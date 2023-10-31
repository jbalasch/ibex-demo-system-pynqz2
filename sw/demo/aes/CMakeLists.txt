include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../../vendor/aes-ip)

add_library(aes-ip_lib
${CMAKE_CURRENT_SOURCE_DIR}/../../../vendor/aes-ip/aes-ip-top.c
${CMAKE_CURRENT_SOURCE_DIR}/../../../vendor/aes-ip/aes-ip.c
${CMAKE_CURRENT_SOURCE_DIR}/../../../vendor/aes-ip/masking.c
${CMAKE_CURRENT_SOURCE_DIR}/../../../vendor/aes-ip/gf_256.c
${CMAKE_CURRENT_SOURCE_DIR}/../../../vendor/aes-ip/utils.c
)

# add_executable(lcd_st7735 main.c)
add_prog(aes main.c aes-ip-top.h)

# pull in core dependencies and additional i2c hardware support
target_link_libraries(aes aes-ip_lib)

target_include_directories(aes PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../vendor/aes-ip)