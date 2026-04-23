#include "Myvector.h"
#include <iostream>
#include <cctype>
using namespace std;

Myvector<int> analyzeCode(string code)
{
    Myvector<int> result;
    int forCount = 0, ifCount = 0, elseCount = 0, whileCount = 0, currDepth = 0, activeLoops = 0, maxDepth = 0;
    int n = code.length();
    bool inString = false;
    string word = "", lastKeyword = "";
    for (int i = 0; i < n; ++i)
    {
        char ch = code[i];

        if (ch == '"' && (i == 0 || code[i - 1] != '\\'))
        {
            inString = !inString;
            continue;
        }

        if (inString)
            continue;

        if (isalpha(ch))
        {
            word += ch;
        }
        else
        {
            if (word == "for")
            {
                forCount++;
                lastKeyword = "for";
                activeLoops++;
            }
            else if (word == "if")
            {
                ifCount++;
            }
            else if (word == "else")
            {
                elseCount++;
            }
            else if (word == "while")
            {
                whileCount++;
                lastKeyword = "while";
            }
            word = "";

            if (ch == '{')
            {
                if (lastKeyword == "for" || lastKeyword == "while")
                {
                    currDepth++;
                    maxDepth = max(maxDepth, currDepth);
                }

                lastKeyword = "";
            }
            else if (ch == '}')
            {
                if (currDepth > 0)
                    currDepth--;
            }
        }
    }

    // counting the last digit

    if (word == "for")
        forCount++;
    else if (word == "if")
        ifCount++;
    else if (word == "else")
        elseCount++;
    else if (word == "while")
        whileCount++;

    result.push_back(forCount);
    result.push_back(ifCount);
    result.push_back(elseCount);
    result.push_back(whileCount);
    result.push_back(maxDepth);

    return result;
}