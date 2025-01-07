# Nome do executável que será gerado.
PROJ_NAME = triangulos

# Compilador utilizado.
CC = gcc

# Flags de compilação para maior segurança e boas práticas.
CFLAGS = -Wall -Wextra -Wpedantic -O2 -g

# Referências para todos os arquivos .c localizados na pasta source.
C_SOURCE = $(wildcard ./source/*.c)

# Substitui a pasta "source" pela pasta "objects" nos arquivos .o.
OBJ = $(subst .c,.o,$(subst source,objects,$(C_SOURCE)))

# Alvo padrão que será executado ao rodar "make".
all: objFolder $(PROJ_NAME)

# Compila e gera o executável a partir dos arquivos objeto.
$(PROJ_NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

# Regra geral para compilar arquivos .c em arquivos .o, com saída na pasta ./objects.
./objects/%.o: ./source/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regra específica para o main.c, garantindo que depende de todos os headers.
./objects/main.o: ./source/main.c
	$(CC) $(CFLAGS) -c $< -o $@

# Cria a pasta ./objects caso ela não exista.
objFolder:
	@mkdir -p objects

# Remove os arquivos objeto, o executável e outros arquivos temporários.
clean:
	@rm -rf ./objects/*.o $(PROJ_NAME) *~
	@rmdir objects

# Declara os alvos "all", "clean" e "objFolder" como phony (não relacionados a arquivos reais).
.PHONY: all clean objFolder
