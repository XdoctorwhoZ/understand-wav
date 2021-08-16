cmake_minimum_required(VERSION 3.13)
project(wav_write_test)  

add_executable(wav_write_test 
    main.c
    wav_mini.c
    wav_generator.c
)
target_link_libraries(wav_write_test PRIVATE m)


add_executable(wav_header_parser 
    main_parser.c
    wav_mini.c
)
target_link_libraries(wav_header_parser PRIVATE m)


