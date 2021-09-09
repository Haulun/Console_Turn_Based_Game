#ifndef DEF_FILEMANAGER
#define DEF_FILEMANAGER

#include <map>
#include <fstream>

class FileManager {
public:

	~FileManager() = default;
    
    void setScore(std::map<std::string, int> currentScore);

private:
    std::map<std::string, int> readLastScore();
	void writeNewScore(std::map<std::string, int> lastScore , std::map<std::string, int> currentScore );
	

};
#endif