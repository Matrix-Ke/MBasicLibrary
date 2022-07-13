set(SharedLibName "Platform")

find_package(TBB REQUIRED FATAL_ERROR)
if(TBB_FOUND)
    message(STATUS TBB_FOUND = ${TBB_FOUND})
    message(STATUS TBB_VERSION = ${TBB_VERSION})
endif()
# ===============================文件分组==============================
FILE(GLOB_RECURSE HeaderFiles ./*.h ./*.inl) # GLOB 获取./include/目录下的*.h 储存在变量HEAD_RIGEL_EDITOR中
FILE(GLOB_RECURSE SourceFiles ./*.cpp) # GLOB 递归获取./include/目录和子目录下的*.cpp 储存在变量HEAD_RIGEL_EDITOR中

# source_group("Header Files" FILES ${HeaderFiles})
# source_group("Source Files" FILES ${SourceFiles})
source_group("Header Files" FILES ${HeaderFiles})
source_group("Source Files" FILES ${SourceFiles})
add_library(${SharedLibName} SHARED ${HeaderFiles} ${SourceFiles})
add_library(BasicTool::${SharedLibName} ALIAS ${SharedLibName})


# ==============================设置target属性=============================
set_target_properties(${SharedLibName} PROPERTIES FOLDER ${ROOT_FOLDER_NAME}/${SECOND_FOLDER_NAME})
#add libraries
target_link_libraries(${SharedLibName} PRIVATE $<$<CONFIG:Release>:TBB::tbb> )
target_link_libraries(${SharedLibName} PRIVATE $<$<CONFIG:Release>:TBB::tbbmalloc> )
target_link_libraries(${SharedLibName} PRIVATE "dbghelp;Winmm")
#include_dir
target_include_directories(${SharedLibName} PRIVATE ${BASICTOOL_INCLUDE_DIRS})
# add definition
target_compile_definitions(${SharedLibName} PRIVATE $<$<CONFIG:Debug>: _TEST_MACRO_>)
if(USE_UNICODE)
    target_compile_definitions(${SharedLibName} PRIVATE "UNICODE; _UNICODE")
endif()
target_compile_definitions(${SharedLibName} PRIVATE "USE_MATRIX_NEW;USE_STL_TYPE_TRAIT")



if(MSVC)
    target_link_options(${SharedLibName} PRIVATE
        $<$<CONFIG:Debug>:/INCREMENTAL> # default is incremental
        $<$<CONFIG:Release>:/INCREMENTAL:NO>
    )
endif()

# #==========================================生成器表达式 Debug=====================================
# file(GENERATE OUTPUT "${CMAKE_CURRENT_SOURCE_DIR}/../generator_test.txt" CONTENT "$<$<BOOL:release>:dbghelp>\n")