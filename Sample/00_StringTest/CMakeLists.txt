set(DemoName "")
GetCurrentDirectoryName(DemoName)

FILE(GLOB SourceFiles ./*.cpp)
FILE(GLOB ResourceFile ./*.json)
source_group("Source Files" FILES ${SourceFiles})
source_group("Resource File" FILES ${ResourceFile})
add_executable(${DemoName} ${SourceFiles} ${ResourceFile})
set_target_properties(${DemoName} PROPERTIES FOLDER ${SampleName}/${DemoName})

add_dependencies(${DemoName} BasicTool::Platform)

target_link_libraries(${DemoName} BasicTool::Platform)

target_include_directories(${DemoName} PRIVATE ${BASICTOOL_INCLUDE_DIRS})

target_compile_definitions(${DemoName} PRIVATE "UNICODE;_UNICODE")