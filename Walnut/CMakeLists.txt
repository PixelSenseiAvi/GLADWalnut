cmake_minimum_required(VERSION 3.16)
project(libwalnut)

# ========= setup ================
set(CMAKE_CXX_STANDARD 17)

# for cmake modules if u wnat to add some libraries
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/modules")

# flags for gcc or clang
set(GCC_COVERAGE_COMPILE_FLAGS "")

if(NOT MSVC)
	set(CMAKE_CXX_FLAGS	"${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
endif()
# ===============================

# ========= deps ================
# vulkan loader
#find_package(Vulkan REQUIRED)

# glfw
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(vendor/glfw)

# glm
add_subdirectory(vendor/glm)

# imgui
add_subdirectory(vendor/imgui)

#stb-image
add_subdirectory(vendor/stb-image)

#glad
add_subdirectory(vendor/glad)
# ===============================

# ========== walnut =============
# find all source files and headers
file(
	GLOB_RECURSE # recursive
	WALNUT_SRC # variable to store the source files and headers
	CONFIGURE_DEPENDS # make a dependency
	"${PROJECT_SOURCE_DIR}/src/*.h" "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

add_library(walnut STATIC ${WALNUT_SRC})
# =================================

# ========= linking deps ==========
target_link_libraries(walnut PUBLIC glad)
target_link_libraries(walnut PUBLIC glfw)
target_link_libraries(walnut PUBLIC imgui)
target_link_libraries(walnut PUBLIC glm)
target_link_libraries(walnut PUBLIC stbimage)
# =================================

# ========== include dir ==========
target_include_directories(walnut PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_include_directories(walnut PUBLIC "${PROJECT_SOURCE_DIR}/vendor/stb_image")
target_include_directories(walnut PUBLIC "${PROJECT_SOURCE_DIR}/vendor/glad/include")
# =================================