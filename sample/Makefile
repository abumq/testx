CC=g++

all:
	$(CC) -Wall -Wextra -Werror -o test_data.bin test_data.cc -std=c++11
	strip test_data.bin
	$(CC) -Wall -Wextra -Werror -o test_data_with_get.bin test_data_with_get.cc -std=c++11
	strip test_data_with_get.bin
