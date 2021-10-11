cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(Corsac LANGUAGES C VERSION 0.1.0)

# set(SDL2_DIR ${PROJECT_SOURCE_DIR}/modules/SDL2)
# set(SDL2_LIB_DIR ${SDL2_DIR}/lib)

include_directories(
    include
    #${SDL2_DIR}/include
)

file(GLOB SOURCES "cmd/main.c" "src/*.c" "src/**/*.c")

add_executable(Corsac ${SOURCES})
# target_link_libraries(${PROJECT_NAME}
#     ${SDL2_LIB_DIR}/libSDL2.dll.a
#     ${SDL2_LIB_DIR}/libSDL2main.a
#     ${SDL2_LIB_DIR}/libSDL2_image.dll.a
#     -mwindows
# )
add_definitions(-DSDL_MAIN_HANDLED)
set_target_properties(
    Corsac PROPERTIES
    C_STANDARD 17
    C_STANDARD_REQUIRED ON
)