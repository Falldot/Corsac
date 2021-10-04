cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(Corsac LANGUAGES C VERSION 0.1.0)

include_directories(include)

file(GLOB SOURCES "cmd/main.c" "src/*.c")

add_executable(Corsac ${SOURCES})
set_target_properties(
    Corsac PROPERTIES
    C_STANDARD 17
    C_STANDARD_REQUIRED ON
)