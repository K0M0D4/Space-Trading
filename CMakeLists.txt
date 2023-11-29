cmake_minimum_required(VERSION 3.21)
project(SpaceTrading LANGUAGES CXX VERSION 0.1.0)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(GLFW
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG master)
FetchContent_MakeAvailable(GLFW)

FetchContent_Declare(glad
        GIT_REPOSITORY https://github.com/Dav1dde/glad.git)

FetchContent_GetProperties(glad)
if(NOT glad_POPULATED)
    FetchContent_Populate(glad)
    set(GLAD_PROFILE "core" CACHE STRING "OpenGL profile")
    set(GLAD_API "gl=" CACHE STRING "API type/version pairs, like \"gl=3.2,gles=\", no version means latest")
    set(GLAD_GENERATOR "c" CACHE STRING "Language to generate the binding for")
    add_subdirectory(${glad_SOURCE_DIR} ${glad_BINARY_DIR})
endif()


FetchContent_Declare(GLM
    GIT_REPOSITORY https://github.com/g-truc/glm.git
    GIT_TAG master)
FetchContent_MakeAvailable(GLM)

add_executable(${PROJECT_NAME}
    src/engine/Quad.cpp
    src/engine/Shader.cpp
    src/engine/Window.cpp

    src/Game.cpp
)

target_link_libraries(${PROJECT_NAME} glfw glad glm)

file(COPY res/ DESTINATION res/)