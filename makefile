appName="mySDLapp"
executableExtension=".o"
exec=$(appName)$(executableExtension)

build:
	gcc -std=c99 ./src/*.c 'sdl2-config --cflags --libs'   -I /usr/include/SDL2  -o $(exec)

run:
	./$(exec)

clean:
	rm ./$(exec)

