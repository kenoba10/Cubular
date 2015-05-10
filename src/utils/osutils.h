#ifndef OSUTILS_H
#define OSUTILS_H

#include <string>

enum OS
{

    WINDOWS,
    MAC,
    LINUX,
    OTHER

};

OS getOS();
std::string getInstallPath();

#endif // OSUTILS_H
