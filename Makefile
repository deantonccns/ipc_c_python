CC = g++
CFLAGS  = -g -Wall -o3

# the build target executable:
TARGET = touch_algo

all: $(TARGET)

$(TARGET): algo.cpp
	@$(CC) $(CFLAGS) -o $(TARGET) algo.cpp
	@echo done

clean:
	$(RM) $(TARGET)