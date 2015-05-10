#include "osutils.h"

OS getOS()
{

    #ifdef _WINDOWS_
    return WINDOWS;
    #elif _MAC_
    return MAC;
    #elif _LINUX_
    return LINUX;
    #else
    return OTHER;
    #endif

}

std::string getInstallPath()
{

    OS os = getOS();

    std::string environment;

    switch(os)
    {

    case WINDOWS:
        environment = std::getenv("APPDATA");
        break;
    case MAC:
        environment = std::getenv("HOME");
        break;
    case LINUX:
        environment = std::getenv("HOME");
        break;
    default:
        environment = ".";

    }

    return environment + "/.cubular/";

}
