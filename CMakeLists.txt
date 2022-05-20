cmake_minimum_required(VERSION 3.22)
project(metodos C)

set(CMAKE_C_STANDARD 99)

add_executable(metodos main.c fibonacci.c fibonacci.h lista_enlazada.c lista_enlazada.h labouchere.c labouchere.h labouchere2.c labouchere2.h)
