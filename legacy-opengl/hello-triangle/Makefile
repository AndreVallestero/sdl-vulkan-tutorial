#awesome example here: https://codereview.stackexchange.com/questions/78855/makefile-for-c-opengl-with-glfw-and-glad
#and here: https://stackoverflow.com/questions/5178125/how-to-place-object-files-in-separate-subdirectory

CC = g++

dep_path = ../../dependencies
INCLUDES = -I$(dep_path)/include
LIBRARIES = -L$(dep_path)/lib

CPPFLAGS = -Wall -ggdb3 -Og $(INCLUDES)
LDFLAGS = -static-libgcc -static-libstdc++ -lglfw3 $(LIBRARIES)

# Windows
ifdef OS
	LDFLAGS += -lopengl32 -lgdi32
# Linux
else
	LDFLAGS += -lGL -lXrandr -lX11 -pthread -ldl -lXxf86vm -lXinerama -lXcursor
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