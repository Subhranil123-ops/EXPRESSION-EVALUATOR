#include "Stack.h"
#include <iostream>
#include <cctype>
#include <stdexcept>

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
                throw invalid_argument("Invalid Expression");
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
                    throw runtime_error("Division By Zero");
                }
                result = op1 / op2;
            }
            s.push(result);
        }

        // invlaid characters like $ % & #
        else
        {
            throw invalid_argument("Invalid Expression");
        }
    }

    // at last the size of the stack should be 1 (the result)
    if (s.size() != 1)
    {
        throw invalid_argument("Invalid Expression");
    }
    return s.peek(); // output
}
