#!/bin/bash
export LD_LIBRARY_PATH=./criterion-2.4.2/lib:$LD_LIBRARY_PATH
cc -I ./criterion-2.4.2/include \
	main_test.c \
	../src/alloc_mem_utils.c \
	../src/char_utils.c \
	../src/map_content_utils.c \
	../src/map_iter_utils.c \
	../src/map_utils.c \
	../src/path_utils.c \
	../src/print_utils.c \
	../src/st_map_utils.c \
	../src/valid_char_utils.c \
	../libft/libft.a -L ./criterion-2.4.2/lib -lcriterion \
	-o test && ./test " " --verbose

