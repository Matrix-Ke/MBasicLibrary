set(SampleName  "")
GetCurrentDirectoryName(SampleName)
project(SampleName)

if(${USE_BASICTOOL_SAMPLE})
    Add_all_subdirectory()
endif()