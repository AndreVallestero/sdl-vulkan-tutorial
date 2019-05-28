#awesome example here: https://codereview.stackexchange.com/questions/78855/makefile-for-c-opengl-with-glfw-and-glad
#and here: https://stackoverflow.com/questions/5178125/how-to-place-object-files-in-separate-subdirectory

CC = g++

# Windows
ifdef OS
	DEPPATH = ../../dependencies
# Linux
else
	DEPPATH = /usr
endif

INCLUDES = -I$(DEPPATH)/include
LIBRARIES = -L$(DEPPATH)/lib

CXXFLAGS = -Wall -ggdb3 -Og $(INCLUDES)
LDFLAGS =  -lOpengl32 -lglu32 -lSDL2main -lSDL2 -lgdi32 $(LIBRARIES)

# Windows
ifdef OS
	LDFLAGS += -lmingw32 
# Linux
else
	LDFLAGS +=
endif

TARGET = hello-triangle
cpp_files = src/main.cpp
objects = $(patsubst src/%,build/%,$(cpp_files:.cpp=.o))
headers = 

all: $(TARGET)

$(TARGET): $(objects) 
	$(CC) -o bin/$@ $^ $(LDFLAGS) 

$(objects): build/%.o: src/%.cpp $(headers) Makefile
	$(CC) $(CXXFLAGS) -c -o $@ $<

clean:
	$(RM) bin/$(TARGET) $(objects)