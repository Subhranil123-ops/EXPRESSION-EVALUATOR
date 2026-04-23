#include "Stack.h"
#include <iostream>
#include <cctype>
using namespace std;

int postfixEvaluation(string exp)
{
    Stack<int> s;
    int len = exp.length();
    for (int i = 0; i < len; i++)
    {
        char ch = exp[i];
        if (ch == ' ')
            continue;

        // multidigit number parsing

        if (isdigit(ch))
        {
            int num = 0;
            while (i < len && isdigit(exp[i]))
            {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            s.push(num);
            i--; // because loop has iterated once extra times
        }

        else if (ch == '+' || ch == '-' || ch == '/' || ch == '*')
        {
            // if in stack there are less than two operands then invalid
            if (s.size() < 2)
            {
                cout << "Invalid Expression\n";
                return;
            }
            int result;
            int op2 = s.peek();
            s.pop();
            int op1 = s.peek();
            s.pop();
            if (ch == '+')
                result = op1 + op2;
            else if (ch == '-')
                result = op1 - op2;
            else if (ch == '*')
                result = op1 * op2;
            else if (ch == '/')
            {
                if (op2 == 0)
                {
                    cout << "Invalid Expression\n";
                    return;
                }
                result = op1 / op2;
            }
            s.push(result);
        }

        // invlaid characters like $ % & #
        else
        {
            cout << "Invalid Expression\n";
            return;
        }
    }

    // at last the size of the stack should be 1 (the result)
    if (s.size() != 1)
    {
        cout << "Invalid Expression\n";
        return;
    }
    return s.peek(); // output
}
