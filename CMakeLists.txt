cmake_minimum_required(VERSION 3.29)
project(3_12_24 C)

set(CMAKE_C_STANDARD 11)

add_executable(3_12_24
    main.c
        tree.h
        tree.c
        parcours_largeur.h
        parcours_largeur.c
)
