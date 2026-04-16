#include <iostream>
#include "detector.h"
#include "converter.h"
#include "evaluator.h"

using namespace std;

int main()
{
    string exp;
    cout << "Enter expression: ";
    getline(cin, exp);

    Type t = detectType(exp);

    if (t == INVALID)
    {
        cout << "Invalid Expression\n";
        return 0;
    }

    string postfix;

    if (t == INFIX)
    {
        postfix = infixToPostfix(exp);
    }
    else if (t == PREFIX)
    {
        postfix = prefixToPostfix(exp);
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

    return 0;
}