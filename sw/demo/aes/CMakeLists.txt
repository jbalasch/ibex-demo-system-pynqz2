string(APPEND CMAKE_C_FLAGS " -O2")

add_prog(aes "main.c;aes-ip-top.c;aes-ip.c;masking.c;gf_256.c;utils.c")
