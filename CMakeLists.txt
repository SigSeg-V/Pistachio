cmake_minimum_required(VERSION 3.29 FATAL_ERROR)
project(Pistachio)

set(CMAKE_CXX_STANDARD 26)

find_package(imgui CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(Stb REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(Vulkan) # CMake 3.21+

set(PRIVATE_DIR Source/Private)
set(PUBLIC_DIR Source/Public)

add_library(Pistachio
    ${PRIVATE_DIR}/Pistachio/Application.cpp
    ${PRIVATE_DIR}/Pistachio/Image.cpp
    ${PRIVATE_DIR}/Pistachio/Random.cpp
    ${PRIVATE_DIR}/Pistachio/Input/Input.cpp

    ${PUBLIC_DIR}/Pistachio/Application.h
    ${PUBLIC_DIR}/Pistachio/EntryPoint.h
    ${PUBLIC_DIR}/Pistachio/Image.h
    ${PUBLIC_DIR}/Pistachio/Layer.h
    ${PUBLIC_DIR}/Pistachio/Random.h
    ${PUBLIC_DIR}/Pistachio/Timer.h
    ${PUBLIC_DIR}/Pistachio/Input/Input.h
    ${PUBLIC_DIR}/Pistachio/Input/KeyCodes.h
        Resources/Pistachio/Roboto-Regular.h
)

include_directories(${Stb_INCLUDE_DIR} ${PRIVATE_DIR}/Pistachio ${PUBLIC_DIR}/Pistachio Resources)

target_link_libraries(Pistachio PRIVATE imgui::imgui glm::glm Vulkan::Vulkan)

install(TARGETS Pistachio
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)
