#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <fstream>
#include <string>

std::string readFromFile(std::string path);
void writeToFile(std::string path, std::string text);

#endif // FILEUTILS_H
