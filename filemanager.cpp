#include "filemanager.hpp"

void FileManager::setScore(std::map<std::string, int> stats)
{

	std::map<std::string, int> lastScores = readLastScore();

	writeNewScore(lastScores, stats);
}


// build a map object with values stored in score.txt
std::map<std::string, int> FileManager::readLastScore()
{
	std::map<std::string, int> res;
	std::ifstream lastScores {"scores.txt"};
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
void FileManager::writeNewScore(std::map<std::string, int> lastScores, std::map<std::string, int> stats)
{
 	std::ofstream fileNewScores {"scores.txt"};

    std::string stringNewScore;
    
    std::map<std::string, int>::iterator it = stats.begin();
    
    for(it; it != stats.end(); it++) {

        std::string param = it->first;
        
        if (lastScores.contains(param)) {
            if (lastScores[param] <= stats[param]) {
                stringNewScore += param + "=" + std::to_string(stats[param]);
            }
            else {
                stringNewScore += param + "=" + std::to_string(lastScores[param]);
            }
        }
        else
        {
            throw std::runtime_error("Un paramètre manque dans le fichier scores.txt");
        }


       
    }

    fileNewScores << stringNewScore;

}
