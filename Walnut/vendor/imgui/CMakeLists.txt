add_library(imgui STATIC 
	imgui.cpp
	imgui_demo.cpp
	imgui_draw.cpp
	imgui_tables.cpp
	imgui_widgets.cpp
	backends/imgui_impl_opengl3.cpp
    backends/imgui_impl_glfw.cpp
)

target_link_libraries(imgui PUBLIC glfw)
target_include_directories(imgui PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
