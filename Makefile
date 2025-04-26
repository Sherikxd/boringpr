# Nombre del ejecutable
TARGET = IBM_Simulator

# Compilador
CC = gcc

# Flags
CFLAGS = -Wall -Wextra -lm -lws2_32

# Carpetas
SRC_DIR = .
EXP_LIBS_DIR = ./exp_libs
BUILD_DIR = ./build

# Archivos fuente
SRCS = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(EXP_LIBS_DIR)/*.c)

# Archivos objeto (reemplazamos .c por .o en build/)
OBJS = $(patsubst %.c, $(BUILD_DIR)/%.o, $(SRCS))

# Regla principal
all: $(BUILD_DIR) $(TARGET)

# Crear carpeta build
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
	mkdir -p $(BUILD_DIR)/exp_libs

# Cómo construir el ejecutable
$(TARGET): $(OBJS)
	$(CC) -o $(BUILD_DIR)/$@ $^ $(CFLAGS)

# Cómo construir archivos .o a partir de .c
$(BUILD_DIR)/%.o: %.c
	$(CC) -c $< -o $@

# Limpiar archivos generados
clean:
	rm -rf $(BUILD_DIR)

# Limpiar todo
fclean: clean

# Recompilar todo desde cero
re: fclean all
