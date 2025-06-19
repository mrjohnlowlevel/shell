# === VARIABLES ===
SRC := shell/main.c getuser/getuser.c prompts/userprompt.c inp/input.c parser/parser.c
OBJ := $(patsubst %.c,objects/%.o,$(SRC))
BIN := bin/main

# === DEFAULT TARGET ===
all: $(BIN)

# === LINKING STEP ===
$(BIN): $(OBJ)
	mkdir -p $(dir $@)
	clang $^ -o $@

# === COMPILATION STEP (pattern rule) ===
objects/%.o: %.c
	mkdir -p $(dir $@)
	clang -c $< -o $@ -Igetuser -Iprompts -Iinp -Iparser

# === CLEANUP ===
.PHONY: clean
clean:
	rm -rf bin/* objects/*

# === RUN ===
.PHONY: run
run:
	./$(BIN)