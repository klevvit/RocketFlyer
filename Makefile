TARGET = RocketFlyer
PREFIX = out/
ARGS = -std=c++20 -Isfml/include
LINK_ARGS = -Lsfml/lib -lsfml-graphics -lsfml-window -lsfml-system 

.PHONY: all clean

all: $(TARGET)
	
clean:
			rm -rf $(TARGET) $(PREFIX)*.o

$(PREFIX)main.o: main.cpp
			clang++ main.cpp $(ARGS) -c -o $(PREFIX)main.o
$(PREFIX)Asteroid.o: Asteroid.cpp
			clang++ Asteroid.cpp $(ARGS) -c -o $(PREFIX)Asteroid.o
$(PREFIX)Earth.o: Earth.cpp
			clang++ Earth.cpp $(ARGS) -c -o $(PREFIX)Earth.o
$(PREFIX)Object.o: Object.cpp
			clang++ Object.cpp $(ARGS) -c -o $(PREFIX)Object.o
$(PREFIX)Rocket.o: Rocket.cpp
			clang++ Rocket.cpp $(ARGS) -c -o $(PREFIX)Rocket.o
$(PREFIX)Sky.o: Sky.cpp
			clang++ Sky.cpp $(ARGS) -c -o $(PREFIX)Sky.o

$(TARGET): $(PREFIX)main.o $(PREFIX)Asteroid.o $(PREFIX)Earth.o $(PREFIX)Object.o $(PREFIX)Rocket.o $(PREFIX)Sky.o
			clang++ $(LINK_ARGS) -o $(TARGET) $(PREFIX)main.o $(PREFIX)Asteroid.o $(PREFIX)Earth.o $(PREFIX)Object.o $(PREFIX)Rocket.o $(PREFIX)Sky.o
