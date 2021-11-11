CXX = g++
CXXFLAGS = `sdl2-config --cflags` -Wall -g -std=c++17
LDFLAGS = `sdl2-config --libs` -lSDL2_image -lm
# This slightly modified INCLUDE lets you use #include<SDL.h> instead of #include<SDL/SDL.h>, etc.
INCLUDE = -I ./include -I `sdl2-config --prefix`/include

# This function fills the role of **, the globstar in GNUMake, which is not inherently supported.
# Credit to user larskholte on https://stackoverflow.com/questions/2483182/recursive-wildcards-in-gnu-make
GLOB = $(foreach d, $(wildcard $(1:=/*)), $(call rwildcard, $d, $2) $(filter $(subst *,%,$2),$d))

# This is the list that will give you all of the .cpp files in src/
# If you prefer the old one, uncomment the next line, and comment out the new SRCS!
# SRCS = $(wildcard src/*.cpp)

# This modified version will not only get all the .cpp files, but get the .cpp files
# out of any directories in src/ as well
SRCS = $(call GLOB, src, *.cpp) 
OBJS = $(patsubst %.cpp, bin/%.o, $(SRCS))

EXEC = my_game

bin/%.o: %.cpp 
	@mkdir -p $(dir $@) #I didn't mention it, but putting @ in front of a command prevents it from displaying to terminal
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(OBJS) -o $@ $(LDFLAGS)

# Feel free to modify this to add any command line arguments! Or don't. Your choice.
run: $(EXEC)
	./$(EXEC) 

clean:
	rm -rf bin
	rm -rf my_game
