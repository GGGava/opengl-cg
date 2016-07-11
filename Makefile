

all: *.c *.h
	gcc -o test *.c -lglut -lGL -lGLU
	./test
	@rm test
