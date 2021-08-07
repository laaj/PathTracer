# spdlog
add_subdirectory(spdlog)

# GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
add_subdirectory(glfw)

# glad
add_library(glad glad/src/glad.c)
target_include_directories(glad PUBLIC glad/include)

# ImGui
add_library(imgui 
	imgui/imgui.cpp
	imgui/imgui_demo.cpp
	imgui/imgui_draw.cpp
	imgui/imgui_tables.cpp
	imgui/imgui_widgets.cpp
	imgui/backends/imgui_impl_glfw.cpp
	imgui/backends/imgui_impl_opengl3.cpp
)
target_include_directories(imgui PUBLIC 
	imgui
	imgui/backends
)
target_link_libraries(imgui PRIVATE glfw glad)
target_compile_definitions(imgui PRIVATE IMGUI_IMPL_OPENGL_LOADER_GLAD)

set(LIBRARIES
	spdlog
	glfw
	glad
	imgui
PARENT_SCOPE)

# Place the external projects into a common folder
set_property(TARGET 
	spdlog 
	glfw 
	glad 
	imgui 
PROPERTY FOLDER "ext")
