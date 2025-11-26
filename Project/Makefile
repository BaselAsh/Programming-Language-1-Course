CC = g++
CFLAGS = -Wall -Wextra -std=c++17

BUILD_DIR = build
SRC_DIR = src
INCLUDE_DIR = include

INCLUDES =-I$(INCLUDE_DIR)

SOURCES = main.cpp student.cpp course.cpp utils.cpp

OBJECTS = $(addprefix $(BUILD_DIR)/, $(SOURCES:.cpp=.o))

EXECUTABLE = student_app

.PHONY: all
all: $(BUILD_DIR) $(EXECUTABLE)

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

$(EXECUTABLE): $(OBJECTS)
	$(CC) %(CFLAGS) $(OBJECTS) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

.PHONY: clean
clear:
	@echo "Removing build directory and executable..."
	rm -rf $(BUILD_DIR) $(EXECUTABLE)
