#!/bin/bash
export LD_LIBRARY_PATH=./criterion-2.4.2/lib:$LD_LIBRARY_PATH
cc -I ./criterion-2.4.2/include \
	main_test.c \
	../src/map_content_utils.c \
        ../src/map_utils.c \
        ../src/validate_map.c \
	../libft/libft.a -L ./criterion-2.4.2/lib -lcriterion \
	-o test && ./test " " --verbose

