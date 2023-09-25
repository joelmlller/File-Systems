
#
# Joel Miller                   
# CPSC 2310 Spring 23           
# UserName: jmill53             
# Instructor: Dr. Yvon Feaster 
#


CC = gcc
CFLAGS = -o
TARGET = LAB4
SOURCES = functions.c driver.c

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(TARGET) $(SOURCES)

run: $(TARGET)
	./$(TARGET) input.txt

clean:
	rm -f $(TARGET)