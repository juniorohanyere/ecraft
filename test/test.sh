gcc -shared -fPIC -o libecraft.so ../*.c
gcc test.c -L. -lecraft -lncurses -ltermbox -o test

export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH

./test
