#include "fileutils.h"

std::string readFromFile(std::string path)
{

    std::string result;

    std::ifstream file;
    file.open(path.c_str());

    if(!file.good())
    {

        return nullptr;

    }

    std::string line = "";

    while(!file.eof())
    {

        std::getline(file, line);
        result += line + "\n";

    }

    file.close();

    return result;

}

void writeToFile(std::string path, std::string text)
{

    std::ofstream file;
    file.open(path.c_str());

    file << text.c_str();

    file.close();

}
