file(GLOB_RECURSE SERVER_SRC *.c)

add_executable(server ${SERVER_SRC})

target_include_directories(server PRIVATE
    ${CMAKE_SOURCE_DIR}/include/server
)

target_link_libraries(server PRIVATE SDL3::SDL3)

# copy SDL3.dll next to executable
add_custom_command(TARGET server POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_RUNTIME_DLLS:server> $<TARGET_FILE_DIR:server>
    COMMAND_EXPAND_LISTS
)