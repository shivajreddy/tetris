#####################################
# Project: TETRIS 
# Author: smpl
# OS: Linux, macOS, Windows
#####################################

# Detect OS
ifeq ($(OS),Windows_NT)
    DETECTED_OS := Windows
else
    DETECTED_OS := $(shell uname -s)
endif

# Compiler
CXX := g++
CXXFLAGS := -std=c++23 -Wall -Wextra -O2
DEBUGFLAGS := -g -DDEBUG

# Directories
BUILD_DIR := build
SRC_DIR := src
LIB_DIR := lib

# Source files (automatically find all .cpp files)
SOURCES := $(wildcard $(SRC_DIR)/*.cpp)

# OS-specific settings
# Windows
ifeq ($(DETECTED_OS),Windows)
    TARGET := $(BUILD_DIR)/tetris.exe
    RAYLIB_PATH := $(LIB_DIR)/raylib/windows
    INCLUDES := -I$(RAYLIB_PATH)/include
    LIBS := -L$(RAYLIB_PATH)/lib -lraylib -lopengl32 -lgdi32 -lwinmm
    MKDIR := @if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)
    RM := @if exist $(BUILD_DIR) rmdir /s /q $(BUILD_DIR)
    RUN := $(TARGET)
# MacOS
# MacOS
else ifeq ($(DETECTED_OS),Darwin)
    TARGET := $(BUILD_DIR)/tetris
    RAYLIB_PATH := $(LIB_DIR)/raylib/macos
    INCLUDES := -I$(RAYLIB_PATH)/include
    LIBS := -L$(RAYLIB_PATH)/lib -Wl,-rpath,$(RAYLIB_PATH)/lib -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
    MKDIR := @mkdir -p $(BUILD_DIR)
    RM := @rm -rf $(BUILD_DIR)
    RUN := ./$(TARGET)
# Linux
else
    TARGET := $(BUILD_DIR)/tetris
    RAYLIB_PATH := $(LIB_DIR)/raylib/linux
    INCLUDES := -I$(RAYLIB_PATH)/include
    LIBS := -L$(RAYLIB_PATH)/lib -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
    MKDIR := @mkdir -p $(BUILD_DIR)
    RM := @rm -rf $(BUILD_DIR)
    RUN := ./$(TARGET)
endif

# Build targets
all: $(TARGET)

$(TARGET): $(SOURCES)
	$(MKDIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SOURCES) -o $(TARGET) $(LIBS)
	@echo Build complete for $(DETECTED_OS)!

# Debug build
debug: CXXFLAGS += $(DEBUGFLAGS)
debug: clean $(TARGET)
	@echo Debug build complete for $(DETECTED_OS)!

run: $(TARGET)
	$(RUN)

clean:
	$(RM)
	@echo Clean complete!

rebuild: clean all

# Show detected configuration
info:
	@echo Detected OS: $(DETECTED_OS)
	@echo Target: $(TARGET)
	@echo Compiler: $(CXX)
	@echo Flags: $(CXXFLAGS)
	@echo Raylib Path: $(RAYLIB_PATH)
	@echo Sources: $(SOURCES)

# Help menu
help:
	@echo "Available targets:"
	@echo "  make          - Build the project (optimized)"
	@echo "  make debug    - Build with debug symbols"
	@echo "  make run      - Build and run the game"
	@echo "  make clean    - Remove build artifacts"
	@echo "  make rebuild  - Clean and build"
	@echo "  make info     - Show build configuration"
	@echo "  make help     - Show this help menu"

.PHONY: all debug run clean rebuild info help
