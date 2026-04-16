#include <iostream>
#include <fstream>
#include <map>
#include <cctype>
using namespace std;

int main()
{
    ifstream in("../input/input.txt");
    if (!in)
    {
        cout << "File not opened\n";
        return 0;
    }

    string line;

    map<string, int> count_words;
    count_words["for"] = 0;
    count_words["while"] = 0;
    count_words["if"] = 0;

    while (getline(in, line))
    {
        string word = "";
        for (auto s : line)
        {

            if (isalpha(s))
            {
                word += s;
            }
            else
            {
                if (word == "for" || word == "while" || word == "if")
                    count_words[word]++;
                word = "";
            }
        }

        // last word check
        if (word == "for" || word == "while" || word == "if")
            count_words[word]++;
    }

    cout << "for: " << count_words["for"] << "\n";
    cout << "for: " << count_words["if"] << "\n";
    cout << "for: " << count_words["while"] << "\n";

    return 0;
}