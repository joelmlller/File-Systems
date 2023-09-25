# compiler to use a c program in makefile
CC=gcc
CFLAGS=-Wall -g
LFLAGS=-lm
TARGET=out


# source files: C files in current directory, src directory and all sub directories
C_SRCS := \
$(wildcard *.c) \
$(wildcard src/*.c) \
$(wildcard src/**/*.c)


# header files: all header files in current directory, src directory and all sub directories
HDRS := \
$(wildcard *.h) \
$(wildcard src/*.h) \
$(wildcard src/**/*.h)


# object files: compiled versions of all src files stored in the bin directory
OBJS := $(patsubst %.c, bin/%.o, $(wildcard *.c))
OBJS += $(filter %.o, $(patsubst src/%.c, bin/%.o, $(C_SRCS)))


# builds the program
all: build
	@echo "All Done"


# compiles all the object files and links into the executable
build: $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LFLAGS)


# compiles the .c files in the src directory into .o files in the bin directory
bin/%.o: %.c $(HDRS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@


# compiles the .c files in the src directory into .o files in the bin directory
bin/%.o: src/%.c $(HDRS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@


# removes executable and bin directories
clean:
	rm -f $(TARGET)
	rm -rf bin


# build and run the program with two input and output files
run: build
	./$(TARGET) input.txt output.txt



# shows the found src files, header files and object files
which:
	@echo "FOUND SOURCES: ${C_SRCS}"
	@echo "FOUND HEADERS: ${HDRS}"
	@echo "TARGET OBJS: ${OBJS}"