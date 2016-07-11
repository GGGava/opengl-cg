

all:
	gcc -o test Main.c -lglut -lGL -lGLU
	./test
	@rm test
