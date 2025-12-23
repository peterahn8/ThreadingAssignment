CXX      ?= c++
CXXFLAGS ?= -std=c++20 -Wall -Wextra -Wpedantic -O2 -pthread
LDFLAGS  ?= -pthread

TARGET    := ThreadingAssignment
BUILD_DIR := build

SRCS := main.cpp Thread.cpp CountingThread.cpp
OBJS := $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

.PHONY: all run clean

all: $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR)/$(TARGET): $(OBJS) | $(BUILD_DIR)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

run: $(BUILD_DIR)/$(TARGET)
	./$(BUILD_DIR)/$(TARGET)

clean:
	rm -rf $(BUILD_DIR)