all: helloworld
helloworld: helloworld.c
	gcc -Wall -Werror -o helloworld helloworld.c
bye: helloworld.c
	./helloworld
