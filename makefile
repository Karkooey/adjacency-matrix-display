appName="mySDLapp"
executableExtension=".o"
exec=$(appName)$(executableExtension)

build:
	gcc -std=c99 ./src/*.c -lSDL2 -o $(exec)

run:
	./$(exec)

clean:
	rm ./$(exec)

