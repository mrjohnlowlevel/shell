MAIN = shell/main.c
BIN = bin/main
OBJ = objects/main.o

run:
	mkdir -p bin
	clang -c $(MAIN) -o $(OBJ) -Igetuser -Iprompts
	clang -c getuser/getuser.c -o objects/getuser.o
	clang -c prompts/userprompt.c -o objects/userprompt.o
	clang $(OBJ) objects/getuser.o objects/userprompt.o -o $(BIN)


clean:
	rm -rf ./bin/* ./objects/*