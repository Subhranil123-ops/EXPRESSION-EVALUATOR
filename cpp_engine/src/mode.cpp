#include <iostream>
using namespace std;

bool isCodeInput(string &input)
{
    int n = input.length();
    string word = "";
    for (int i = 0; i < n; ++i)
    {
        char ch = input[i];

        if (ch == '{' || ch == '}')
            return true;
        else if (ch >= 'a' && ch <= 'z' || ch >= 'A' || ch <= 'Z')
        {
            word += ch;
        }
        else
        {
            if (word == "for" || word == "while" || word == "if" || word == "else")
                return true;
            word = "";
        }

        if (word == "for" || word == "while" || word == "if" || word == "else")
            return true;
    }
    return false;
}