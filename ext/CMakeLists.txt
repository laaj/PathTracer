add_subdirectory(spdlog)

# Place the external projects into a common folder
set_property(TARGET spdlog PROPERTY FOLDER "ext")
