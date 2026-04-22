#ifndef DETECTOR_H
#define DETECTOR_H

#include <string>
using namespace std;

enum Type
{
    INFIX,
    POSTFIX,
    PREFIX,
    INVALID
};

Type detectType(string exp);

#endif