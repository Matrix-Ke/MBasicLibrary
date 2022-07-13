set(SharedLibName "Primitive")

# ===============================文件分组==============================
FILE(GLOB_RECURSE HeaderFiles ./*.h ./*.inl) # GLOB 获取./include/目录下的*.h 储存在变量HEAD_RIGEL_EDITOR中
FILE(GLOB_RECURSE SourceFiles ./*.cpp) # GLOB 递归获取./include/目录和子目录下的*.cpp 储存在变量HEAD_RIGEL_EDITOR中
source_group("Header Files" FILES ${HeaderFiles})
source_group("Source Files" FILES ${SourceFiles})
add_library(${SharedLibName} SHARED ${HeaderFiles} ${SourceFiles})
add_library(BasicTool::${SharedLibName} ALIAS ${SharedLibName})
# source_group(TREE  ${CMAKE_CURRENT_SOURCE_DIR} FILES ${HeaderFiles} ${SourceFiles})
set_target_properties(${SharedLibName} PROPERTIES FOLDER ${ROOT_FOLDER_NAME}/${SECOND_FOLDER_NAME})

# ==============================设置target属性=============================
# public 和 private 尽量多注意
# target_link_libraries(${SharedLibName} PRIVATE BasicTool::Platform) 
target_link_libraries(${SharedLibName} PRIVATE BasicTool::Container) 
target_link_libraries(${SharedLibName} PRIVATE BasicTool::Math)
add_dependencies(${SharedLibName} BasicTool::Platform)
add_dependencies(${SharedLibName} BasicTool::Math)
add_dependencies(${SharedLibName} BasicTool::Container)

#add include
target_include_directories(${SharedLibName} PRIVATE ${BASICTOOL_INCLUDE_DIRS})
# add definition
target_compile_definitions(${SharedLibName} PRIVATE $<$<CONFIG:Debug>: _TEST_MACRO_>)
if(USE_UNICODE)
    target_compile_definitions(${SharedLibName} PRIVATE "UNICODE; _UNICODE")
endif()
target_include_directories(${SharedLibName} PRIVATE "${PROJECT_SOURCE_DIR}")
# target_compile_definitions(${SharedLibName} PRIVATE "USE_STL_TYPE_TRAIT")
# target_compile_definitions(${SharedLibName} PRIVATE "USE_MATRIX_NEW")



if(MSVC)
    target_link_options(${SharedLibName} PRIVATE
        $<$<CONFIG:Debug>:/INCREMENTAL> # default is incremental
        $<$<CONFIG:Release>:/INCREMENTAL:NO> # 是否开启增量编译
    )
endif()

# #==========================================生成器表达式 Debug=====================================
# file(GENERATE OUTPUT "${CMAKE_CURRENT_SOURCE_DIR}/../generator_test.txt" CONTENT "$<$<BOOL:release>:dbghelp>\n")