CC = gcc
CFLAGS = -Wall -Werror

TARGET = lms
SRCS = lms.h lms.c

$(TARGET) : $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)
