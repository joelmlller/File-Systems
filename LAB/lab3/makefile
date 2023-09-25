#
# Joel Miller                   
# CPSC 2310 Spring 23           
# UserName: jmill53             
# Instructor: Dr. Yvon Feaster 
#


CC = gcc
CFLAGS = -o
TARGET = LAB3
SOURCES = driver.c functions.c

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(TARGET) $(SOURCES)

run: $(TARGET)
	./$(TARGET) autograderinput.csv studentout.txt

clean:
	rm -f $(TARGET)