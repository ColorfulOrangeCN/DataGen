cmake_minimum_required(VERSION 3.0.2)

project(DataGen)

#find_package(FLEX)
#find_library(ldev LDEV_DIR)

#FLEX_TARGET(LEXER src/lexer.l src/lexer.lex.c)

#add_library(ldev STATIC)

aux_source_directory(src SRC_DIR)

add_executable(datagen ${SRC_DIR})
