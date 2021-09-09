#include "filemanager.hpp"

void FileManager::setScore()
{

	std::map<std::string, int> lastScores = readLastScore();

	writeNewScore(lastScores);
}


// build a map object with values stored in score.txt
std::map<std::string, int> FileManager::readLastScore()
{
	std::map<std::string, int> res;
	std::ifstream lastScores {"score.txt"};
	std::string line;

	while (getline(lastScores, line))
	{
        std::size_t pos = line.find("=");
		std::string param = line.substr(0, pos);
		int lastValue = std::stoi(line.substr(pos + 1));

        res[param] = lastValue;
	}
    return res;
}

// write new score 
void FileManager::writeNewScore(std::map<std::string, int> lastScores, std::map<std::string, int> newScores)
{
 	std::ofstream newScores {"score.txt"};
    
    std::map<std::string, int>::iterator it = lastScores.begin();
    
    std::map<std::string, int> newScores;

    for(it; it != lastScores.end(); it++) {

    }

}

