add_executable(Server main.c)

target_link_libraries(Server PRIVATE SDL3::SDL3)

# copy SDL3.dll next to executable
add_custom_command(TARGET Server POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_RUNTIME_DLLS:Server> $<TARGET_FILE_DIR:Server>
    COMMAND_EXPAND_LISTS
)