build: 
	g++ -Wall -Wextra -Wpedantic main.cpp game.cpp entity.cpp -o bin/main

run:
	./bin/main

clean:
	rm ./bin/main
