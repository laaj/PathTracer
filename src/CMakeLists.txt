# Source files
set(SOURCE_FILES
	main.cpp
	mypch.h
	Application.h
	Application.cpp

	Core/Log.h
	Core/Log.cpp
	Core/utils.h
	Core/utils.cpp

	Events/Event.h
	Events/EventDispatcher.h
	Events/KeyEvent.h
	Events/MouseEvent.h
	Events/WindowEvent.h

	UI/Window.h
	UI/Window.cpp
	UI/Editor.h
	UI/Editor.cpp
)

# Preserve the project hierarchy in IDEs
source_group(TREE "${CMAKE_SOURCE_DIR}" FILES ${SOURCE_FILES})

# The executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBRARIES})

# Precompiled headers
target_precompile_headers(${PROJECT_NAME} PRIVATE mypch.h)

# Compiler settings
if(MSVC)
	target_compile_options(${PROJECT_NAME} PRIVATE /W4 /MP)
endif()

target_compile_definitions(${PROJECT_NAME} PRIVATE "$<$<CONFIG:DEBUG>:PT_DEBUG>")

# Visual Studio stuff
set_property(DIRECTORY "${CMAKE_SOURCE_DIR}" PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")