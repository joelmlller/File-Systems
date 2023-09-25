#
# Joel Miller                   
# CPSC 2310 Spring 23           
# UserName: jmill53             
# Instructor: Dr. Yvon Feaster 
#


CC = gcc
CFLAGS = -o
TARGET = LAB5
SOURCES = driver.c functions.c

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(TARGET) $(SOURCES)

run: $(TARGET)
	./$(TARGET) classdata.csv studentout.txt 1

test: $(TARGET)
	./$(TARGET) classdata.csv studentout.txt 2

clean:
	rm -f $(TARGET)