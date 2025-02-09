PROJ_NAME = opvet

CC = gcc

C_FLAGS = -Wall -Wextra -Wpedantic -O3 -g

C_SOURCE = $(wildcard ./source/*.c)

H_SOURCE=$(wildcard ./source/*.h)

OBJ = $(subst .c,.o,$(subst source,objects,$(C_SOURCE)))

all: objFolder $(PROJ_NAME)

$(PROJ_NAME): $(OBJ)
	$(CC) $(C_FLAGS) $^ -o $@ -lm

./objects/%.o: ./source/%.c
	$(CC) $(C_FLAGS) -c $< -o $@

./objects/main.o: ./source/main.c $(H_SOURCE)
	$(CC) $(C_FLAGS) -c $< -o $@

objFolder:
	@mkdir -p objects

clean:
	@rm -rf ./objects/*.o $(PROJ_NAME) *~
	@rmdir objects

.PHONY: all clean objFolder