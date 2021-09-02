build: 
	g++ -Wall -Wextra main.cpp game.cpp entity.cpp -o bin/main

run:
	./bin/main

clean:
	rm ./bin/main
