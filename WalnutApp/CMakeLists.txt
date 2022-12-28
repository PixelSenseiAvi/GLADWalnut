cmake_minimum_required(VERSION 3.16)

project(walnut_app)
set(CMAKE_CXX_STANDARD 17)

add_executable(walnutapp
    src/Renderer.cpp
	src/WalnutApp.cpp
)

target_link_libraries(walnutapp walnut)