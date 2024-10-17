cmake_minimum_required(VERSION 3.29)
project(ProjetoCG C)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(ProjetoCG
    cone.c
    cone.h
    cubo.c
    cubo.h
    esfera.c
    esfera.h
    Hierarquia3D-basico.c)
target_link_libraries(ProjetoCG ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} m)