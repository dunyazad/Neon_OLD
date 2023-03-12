cmake_minimum_required(VERSION 3.1)

project(Neon)

set(CMAKE_CXX_STANDARD 17)

if(CMAKE_SYSTEM_NAME MATCHES "Windows")
    set(PLATFORM "Windows")
    set(ARCHITECTURE "x64")
elseif(CMAKE_SYSTEM_NAME MATCHES "Darwin")
    set(PLATFORM "MacOS")
    if(CMAKE_SYSTEM_PROCESSOR MATCHES "arm64")
        set(ARCHITECTURE "arm64")
    elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64")
        set(ARCHITECTURE "x86_64")
    elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "universal")
        set(ARCHITECTURE "universal")
    else()
        set(ARCHITECTURE "Unknown")
    endif()
endif()

if(CMAKE_CONFIGURATION_TYPES MATCHES "Debug")
    set(BUILD_TYPE "Debug")
elseif(CMAKE_CONFIGURATION_TYPES MATCHES "Release")
    set(BUILD_TYPE "Release")
endif()

message(${CMAKE_GENERATOR})


include_directories(${CMAKE_SOURCE_DIR}/inc)
include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/src/Neon)

# glad
set(GLAD_INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/inc/glad)
include_directories(${GLAD_INCLUDE_DIRS})

# glfw
set(GLFW_INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/inc/glfw)
set(GLFW_LIB_DIR_ROOT ${CMAKE_SOURCE_DIR}/lib/GLFW)
set(GLFW_LIB_DIR ${GLFW_LIB_DIR_ROOT}/${PLATFORM}/${ARCHITECTURE})
if(CMAKE_SYSTEM_NAME MATCHES "Windows")
set(GLFW_LIBRARIES ${GLFW_LIB_DIR}/glfw3.lib)
elseif(CMAKE_SYSTEM_NAME MATCHES "Darwin")
set(GLFW_LIBRARIES ${GLFW_LIB_DIR}/libglfw.3.dylib)
endif()

set(SOURCE_LIST
${CMAKE_SOURCE_DIR}/src/main.cpp
${CMAKE_SOURCE_DIR}/src/glad.c
${CMAKE_SOURCE_DIR}/src/Neon/Neon.h
${CMAKE_SOURCE_DIR}/src/Neon/NeonCommon.h
${CMAKE_SOURCE_DIR}/src/Neon/NeonApp.h
${CMAKE_SOURCE_DIR}/src/Neon/NeonApp.cpp
${CMAKE_SOURCE_DIR}/src/Neon/NeonWindow.h
${CMAKE_SOURCE_DIR}/src/Neon/NeonWindow.cpp

${CMAKE_SOURCE_DIR}/src/Neon/GraphicsAPI/Shader/NeonShader.h
${CMAKE_SOURCE_DIR}/src/Neon/GraphicsAPI/Shader/NeonShader.cpp

# ${CMAKE_SOURCE_DIR}/src/Neon/Math/SBM_Vector2.cpp
)

add_executable(NeonApp ${SOURCE_LIST})

source_group(TREE ${CMAKE_SOURCE_DIR} FILES ${SOURCE_LIST})

target_link_libraries(NeonApp ${GLFW_LIBRARIES})
set_target_properties(NeonApp
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)
