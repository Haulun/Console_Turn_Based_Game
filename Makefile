build: 
	g++ -std=c++2a -Wall -Wextra -Wpedantic main.cpp game.cpp entity.cpp interface.cpp entitymaker.cpp filemanager.cpp -o bin/main

run:
	./bin/main

clean:
	rm ./bin/main
