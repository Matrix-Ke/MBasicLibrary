cmake_minimum_required(VERSION 3.11)

#===================================引入CMake配置文件========================
include(CMake/CMakeInit.cmake)
include(Cmake/SetupProject.cmake)

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

# Cmake划分目录
set(ENGINE_ROOT_DIR "MBasicTool")
set(SECOND_LEVEL_DIR "")
set(ENGINE_SOURCE_RUNTIME_DIR ${CMAKE_SOURCE_DIR})

# ==================================引入外部包====================================
# include(CMake/SetUpConfigurations.cmake)

# =======================================添加子目录====================================
Add_all_subdirectory()
