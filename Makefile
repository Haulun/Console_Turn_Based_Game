build: 
	g++ -Wall -Wextra main.cpp Entities/entity.cpp Entities/Heroes/knight.cpp Entities/Heroes/mage.cpp Entities/Enemies/troll.cpp Entities/Enemies/goblin.cpp Entities/Enemies/enemy.cpp Entities/Heroes/hero.cpp -o bin/main

run:
	./bin/main

clean:
	rm ./bin/main