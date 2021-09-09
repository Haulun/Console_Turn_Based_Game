#include "filemanager.hpp"

void FileManager::setScore(std::map<std::string, int> currentScores)
{

	std::map<std::string, int> lastScores = readLastScore();

	writeNewScore(lastScores, currentScores);
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
void FileManager::writeNewScore(std::map<std::string, int> lastScores, std::map<std::string, int> currentScores)
{
 	std::ofstream fileNewScores {"score.txt"};

    std::string stringNewScore;
    
    std::map<std::string, int>::iterator it = lastScores.begin();
    
    for(it; it != lastScores.end(); it++) {

        std::string param = it->first;
        
        if(lastScores[param] >= currentScores[param])
        {
            stringNewScore += param + "=" + std::to_string(lastScores[param]) +"\n";
        } 
        else {
            stringNewScore += param + "=" + std::to_string(currentScores[param]) + "\n";
        }
    }

    fileNewScores << stringNewScore;

}
