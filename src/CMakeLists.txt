# Source files
set(SOURCE_FILES
	main.cpp
	mypch.h
)

# Preserve the project hierarchy in IDEs
source_group(TREE "${CMAKE_SOURCE_DIR}" FILES ${SOURCE_FILES})

# The executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE
	spdlog
)

# Precompiled headers
target_precompile_headers(${PROJECT_NAME} PRIVATE mypch.h)

# Compiler settings
if(MSVC)
	target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX /MP)
endif()

# Visual Studio stuff
set_property(DIRECTORY "${CMAKE_SOURCE_DIR}" PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")