set(DemoName "")
GetCurrentDirectoryName(DemoName)

FILE(GLOB SourceFiles ./*.cpp)
FILE(GLOB ResourceFile ./*.txt)
source_group("Source Files" FILES ${SourceFiles})
source_group("Resource File" FILES ${ResourceFile})
add_executable(${DemoName} ${SourceFiles} ${ResourceFile})
set_target_properties(${DemoName} PROPERTIES FOLDER ${SampleName}/${DemoName})

add_dependencies(${DemoName} BasicTool::Platform)
add_dependencies(${DemoName} BasicTool::Container)

target_link_libraries(${DemoName} BasicTool::Platform)
target_link_libraries(${DemoName} BasicTool::Container)

target_include_directories(${DemoName} PRIVATE ${BASICTOOL_INCLUDE_DIRS})

if(USE_UNICODE)
    target_compile_definitions(${DemoName} PRIVATE "UNICODE;_UNICODE")
endif()