gcc -c -Wall -Werror -fpic lib.c
gcc -shared -o liblib.so lib.o
gcc -Wall main.c -o main -llib -L./
