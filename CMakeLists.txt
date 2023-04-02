cmake_minimum_required(VERSION 3.0)
project (c_gpio_linux)

add_library(c_gpio_linux STATIC)

target_sources(c_gpio_linux PRIVATE
    gpio.h
    gpio.c
)
