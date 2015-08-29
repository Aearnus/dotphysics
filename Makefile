COMPILER = g++
FILES = main.cpp World.cpp ElementTypes.cpp Element.cpp
LIBRARIES = -lsfml-graphics -lsfml-window -lsfml-system
FLAGS = -std=c++1y -o dotphysics -Wall -Wextra -pedantic

all:
	$(COMPILER) $(FILES) $(FLAGS) $(LIBRARIES)
