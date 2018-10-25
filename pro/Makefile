system:bank_server.c bank_count.c bank_get_number.c
	gcc bank_server.c head/comon.c -o server -lpthread
	gcc bank_count.c head/comon.c -o bank_count
	gcc bank_get_number.c head/comon.c -o bank_get_number

server:server.c bank_head.h
	gcc server.c head/comon.c -o server -lpthread

bank_count:bank_count.c
	gcc bank_count.c head/comon.c -o bank_count

bank_get_number:bank_get_number.c
	gcc bank_get_number.c head/comon.c -o bank_get_number

debug:bank_server.c bank_count.c bank_get_number.c
	gcc bank_server.c head/comon.c -g -o server -lpthread
	gcc bank_count.c head/comon.c -g -o bank_count
	gcc bank_get_number.c head/comon.c -g -o bank_get_number
