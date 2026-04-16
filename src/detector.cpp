#include "detector.h"
#include <vector>
#include <cctype>

using namespace std;

bool isOperator(string s)
{
    return s == "+" || s == "-" || s == "*" || s == "/";
}

vector<string> tokenize(string exp)
{
    vector<string> tokens;
    string temp = "";

    for (char ch : exp)
    {
        if (ch == ' ')
        {
            if (!temp.empty())
            {
                tokens.push_back(temp);
                temp = "";
            }
        }
        else
        {
            temp += ch;
        }
    }

    if (!temp.empty())
        tokens.push_back(temp);

    return tokens;
}

Type detectType(string exp)
{
    if (exp.empty())
        return INVALID;

    vector<string> tokens = tokenize(exp);

    if (tokens.size() == 1)
    {
        return INFIX;
    }

    if (isOperator(tokens[0]))
    {
        return PREFIX;
    }

    if (isOperator(tokens.back()))
    {
        return POSTFIX;
    }

    return INFIX;
}