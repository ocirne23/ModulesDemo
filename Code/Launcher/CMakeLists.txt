project(Launcher)

file(GLOB_RECURSE PROJECT_PRIVATE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/*.ixx" "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_executable(${PROJECT_NAME} ${PROJECT_PRIVATE_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE Common Graphics Input)

set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER _Launcher)

apply_compile_settings(${PROJECT_NAME})