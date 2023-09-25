#
# Joel Miller                   
# CPSC 2310 Spring 23           
# UserName: jmill53             
# Instructor: Dr. Yvon Feaster 
#


CC = gcc
CFLAGS = -o
TARGET = LAB7
SOURCES = lab7.c

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(TARGET) $(SOURCES)

run: $(TARGET)
	./$(TARGET) 

clean:
	rm -f $(TARGET)