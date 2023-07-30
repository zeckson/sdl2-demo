SRC_DIR = src
BUILD_DIR = build
CC = g++
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_NAME = SDL_App
SDL_LIBRARY_INCLUDE = $(shell sdl2-config --cflags)
SDL_LIBRARY = $(shell pkg-config SDL2 SDL2_image --libs)
COMPILER_FLAGS = -std=c++17 -Wall -O0 -g

.PHONY: compile clean run all

compile: clean
	mkdir $(BUILD_DIR)
	echo $(SDL_LIBRARY)
	$(CC) $(COMPILER_FLAGS) $(SDL_LIBRARY) $(SDL_LIBRARY_INCLUDE) $(SRC_FILES) -o $(BUILD_DIR)/$(OBJ_NAME)

clean:
	rm -rf $(BUILD_DIR)

run: compile
	$(BUILD_DIR)/${OBJ_NAME}

all: compile
