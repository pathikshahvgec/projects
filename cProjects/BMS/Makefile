CC = gcc
CFLAGS = -Wall -Werror

TARGET = bms
SRCS = bms.h bms.c

$(TARGET) : $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)
