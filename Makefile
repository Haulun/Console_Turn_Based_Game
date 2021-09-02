build: 
	g++ -Wall -Wextra main.cpp game.cpp -o bin/main

run:
	./bin/main

clean:
	rm ./bin/main
