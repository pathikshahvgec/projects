CC = gcc
CFLAGS = -Wall -Werror

TARGET = toDoList
SRCS = toDoListLL.c toDoListLL.h

$(TARGET) : $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)
