PROJ_NAME = alturas

CC = gcc

C_FLAGS = -Wall -Wextra -Wpedantic -O2 -g

C_SOURCE = $(wildcard ./source/*.c)

OBJ = $(subst .c,.o,$(subst source,objects,$(C_SOURCE)))

all: objFolder $(PROJ_NAME)

$(PROJ_NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

./objects/%.o: ./source/%.c
	$(CC) $(C_FLAGS) -c $< -o $@

./objects/main.o: ./source/main.c
	$(CC) $(CFLAGS) -c $< -o $@

objFolder:
	@mkdir -p objects

clean:
	@rm -rf ./objects/*.o $(PROJ_NAME) *~
	@rmdir objects

.PHONY: all clean objFolder