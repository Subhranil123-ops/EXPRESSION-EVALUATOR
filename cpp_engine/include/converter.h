#ifndef CONVERTER_H
#define CONVERTER_H

#include <string>
using namespace std;

string infixToPostfix(string exp);
string postfixToInfix(string exp);
string postfixToPrefix(string exp);
string prefixToPostfix(string exp);

#endif