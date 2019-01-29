#awesome example here: https://codereview.stackexchange.com/questions/78855/makefile-for-c-opengl-with-glfw-and-glad
#and here: https://stackoverflow.com/questions/5178125/how-to-place-object-files-in-separate-subdirectory

CC = g++

# Windows
ifdef OS
	dep_path = ../../dependencies
# Linux
else
	dep_path = /usr
endif

INCLUDES = -I$(dep_path)/include
LIBRARIES = -L$(dep_path)/lib

CPPFLAGS = -Wall -ggdb3 -Og $(INCLUDES)
LDFLAGS = -lSDL2 $(LIBRARIES)

# Windows
ifdef OS
	LDFLAGS += 
# Linux
else
	LDFLAGS += -lGL
endif

TARGET = hello-triangle
cpp_files = src/main.cpp
objects = $(patsubst src/%,build/%,$(cpp_files:.cpp=.o))
headers = 

all: $(TARGET)

$(TARGET): $(objects) 
	$(CC) -o bin/$@ $^ $(LDFLAGS) 

$(objects): build/%.o: src/%.cpp $(headers) Makefile
	$(CC) $(CPPFLAGS) -c -o $@ $<

clean:
	$(RM) bin/$(TARGET) $(objects)