#include <iostream>
#include "vector.h"
#include "detector.h"
#include "converter.h"
#include "evaluator.h"
#include "analyzer.h"
#include "mode.h"

using namespace std;

string timeComplexity(int &depth)
{
    if (depth == 0)
        return "1";
    else if (depth == 1)
        return "O(n)";
    else if (depth == 2)
        return "O(n^2)";
    else if (depth == 3)
        return "O(n^3)";

    return "O(n^k)";
}
int main()
{
    string exp, input = "";
    cout << "Enter input(type END on new line to finish): ";

    // mulitline input
    while (true)
    {
        getline(cin, exp);
        if (exp == "END")
            break;
        input += exp;
    }

    if (isCodeInput(input))
    {
        vector<int> result = analyzeCode(input);

        cout << "\n--- CODE ANALYSIS ---\n";
        cout << "For: " << result[0] << endl;
        cout << "If: " << result[1] << endl;
        cout << "Else: " << result[2] << endl;
        cout << "While: " << result[3] << endl;
        cout << "Max Depth: " << result[4] << endl;

        cout << "Estimated Complexity: " << timeComplexity(result[4]) << endl;
    }
    else
    {
        Type t = detectType(input);

        if (t == INVALID)
        {
            cout << "Invalid Expression\n";
            return 0;
        }

        string postfix;

        if (t == INFIX)
        {
            postfix = infixToPostfix(input);
        }
        else if (t == PREFIX)
        {
            postfix = prefixToPostfix(input);
        }
        else
        {
            postfix = exp;
        }

        if (postfix == "")
        {
            cout << "Conversion failed\n";
            return 0;
        }

        cout << "\n--- OUTPUT ---\n";
        cout << "Postfix: " << postfix << endl;

        cout << "Infix: " << postfixToInfix(postfix) << endl;

        cout << "Prefix: " << postfixToPrefix(postfix) << endl;

        cout << "Result: ";
        postfixEvaluation(postfix);
    }

    return 0;
}