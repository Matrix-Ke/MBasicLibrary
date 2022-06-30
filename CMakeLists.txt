cmake_minimum_required(VERSION 3.11)


# 防止直接在源文件下生成项目
if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
    message(
        FATAL_ERROR
        "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there."
    )
endif()

# =====================================全局设置=======================================
set(PROJECT_VERSION 1.0.0)
set(PROJECT_NAME "MBasicTool")
Project(${PROJECT_NAME} LANGUAGES CXX VERSION ${PROJECT_VERSION})
message(STATUS "Version: ${PROJECT_VERSION}")
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake)# 设置Include路径
# Cmake划分目录
set(ROOT_FOLDER_NAME "BasicTool")
set(SECOND_FOLDER_NAME "")
set(PROJECT_SOURCE_DIR ${CMAKE_SOURCE_DIR})
set(BASICTOOL_INCLUDE_DIRS  ${CMAKE_CURRENT_SOURCE_DIR})



#===================================引入CMake配置文件========================
if(NOT CMakeInit_FOUND)
    message(STATUS ${PROJECT_NAME}.CMakeInit_FOUND = "Found ${CMakeInit_FOUND}"  )
    include(CMakeFunction)
endif(NOT CMakeInit_FOUND)
if(NOT SetupProject_FOUND)
    message(STATUS ${PROJECT_NAME}.SetupProject_FOUND= "Found ${SetupProject_FOUND}" )
    include(SetupProject)
endif(NOT SetupProject_FOUND)


# =======================================添加子目录====================================
Add_all_subdirectory()

