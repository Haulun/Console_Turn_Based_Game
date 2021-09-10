#include "filemanager.hpp"

void FileManager::setScore(std::map<std::string, int>& stats)
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
        if(pos == std::string::npos) continue; // case empty line
		std::string param = line.substr(0, pos);
		int lastValue = std::stoi(line.substr(pos + 1));
        res[param] = lastValue;
	}
    return res;
}

// write new score if new score
void FileManager::writeNewScore(std::map<std::string, int>& lastScores, std::map<std::string, int>& stats)
{
 	std::ofstream fileNewScores {"scores.txt"};

    std::string stringNewScore;
        
    for(auto it = stats.begin(); it != stats.end(); it++) {

        std::string param = it->first;
        
        if (lastScores.contains(param)) {
            if (lastScores[param] <= stats[param]) {
                stringNewScore += param + "=" + std::to_string(stats[param]) + "\n";
            }
            else {
                stringNewScore += param + "=" + std::to_string(lastScores[param]) + "\n";
            }
        }
        else
        {
            stringNewScore += param + "=" + std::to_string(stats[param]) + "\n";
            // throw std::runtime_error("Un param�tre manque dans le fichier scores.txt");
        }


       
    }

    fileNewScores << stringNewScore;

}
