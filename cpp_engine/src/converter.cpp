#include "stack.h"
#include "evaluator.h"
#include <stdexcept>
using namespace std;

// precedence logic
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '/' || op == '*')
        return 2;
    return 0;
}

// INFIX TO POSTFIX
string infixToPostfix(string exp)
{
    if (exp.empty())
    {
        throw invalid_argument("Invalid Expression");
         
    }

    Stack<char> s;
    int len = exp.length();
    string ans;

    for (int i = 0; i < len; i++)
    {
        char ch = exp[i];
        if (ch == ' ')
            continue;

        // operand
        if (isdigit(ch))
        {
            while (i < len && isdigit(exp[i]))
            {
                ans += exp[i];
                i++;
            }
            ans += ' ';
            i--;
        }
        else if (isalpha(ch))
        {
            throw invalid_argument("Invalid Expression");
             
        }

        // operator
        else
        {
            if (ch == '(')
                s.push(ch);

            else if (ch == ')')
            {
                while (!s.isEmpty() && s.peek() != '(')
                {
                    ans += s.peek();
                    ans += ' ';
                    s.pop();
                }
                // if empty it means that balanced parenthesis is not there in the exp....
                if (s.isEmpty())
                {
                    throw invalid_argument("Balanced Parenthesis!!");
                     
                }
                s.pop(); // remove ( at last when the top is (
            }

            else
            {
                while (!s.isEmpty() && s.peek() != '(' && precedence(s.peek()) >= precedence(ch))
                {
                    ans += s.peek();
                    ans += ' ';
                    s.pop();
                }
                s.push(ch);
            }
        }
    }

    while (!s.isEmpty())
    {
        if (s.peek() == '(')
        {
            throw invalid_argument("Balanced Parenthesis!!");
             
        }
        ans += s.peek();
        ans += ' ';
        s.pop();
    }
    return ans;
}

// POSTFIX TO INFIX
string postfixToInfix(string exp)
{
    Stack<string> s;

    int len = exp.length();
    for (int i = 0; i < len; i++)
    {
        char ch = exp[i];
        if (ch == ' ')
            continue;

        // multidigit number parsing

        if (isdigit(ch))
        {
            string num = "";
            while (i < len && isdigit(exp[i]))
            {
                num += exp[i];
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

            string op2 = s.peek();
            s.pop();
            string op1 = s.peek();
            s.pop();
            string temp = "(" + op1 + ch + op2 + ")";
            s.push(temp);
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
    return s.peek();
}

// POSTFIX TO PREFIX

string postfixToPrefix(string exp)
{
    Stack<string> s;
    int len = exp.length();
    for (int i = 0; i < len; ++i)
    {
        char ch = exp[i];
        if (ch == ' ')
            continue;
        // multidigit parsing
        if (isdigit(ch))
        {
            string temp = "";
            while (i < len && isdigit(exp[i]))
            {
                temp += exp[i];
                i++;
            }
            s.push(temp);
            i--; // i once time increases
        }
        // operators handling
        else if (ch == '+' || ch == '-' || ch == '/' || ch == '*')
        {
            if (s.size() < 2)
            {
                throw invalid_argument("Invalid Expression");
                 
            }
            string op2 = s.peek();
            s.pop();
            string op1 = s.peek();
            s.pop();
            string result = string(1, ch) + " " + op1 + " " + op2;
            s.push(result);
        }
        else
        {
            throw invalid_argument("Invalid Expression");
             
        }
    }

    if (s.size() != 1)
    {
        throw invalid_argument("Invalid Expression");
    }
    return s.peek();
}

// PREFIX TO  POSTFIX

string prefixToPostfix(string exp)
{
    Stack<string> s;
    int n = exp.length();
    for (int i = n - 1; i >= 0; --i)
    {
        char ch = exp[i];
        if (ch == ' ')
            continue;

        // multidigit parsing
        if (isdigit(ch))
        {
            string temp = "";
            while (i >= 0 && isdigit(exp[i]))
            {
                temp = exp[i] + temp;
                i--;
            }
            s.push(temp);
            i++; // i increases once due one more iteration
        }

        // handling operators
        else if (ch == '+' || ch == '-' || ch == '/' || ch == '*')
        {
            if (s.size() < 2)
            {
                throw invalid_argument("Invalid Expression");
            }
            string op1 = s.peek();
            s.pop();
            string op2 = s.peek();
            s.pop();
            string result = op1 + " " + op2 + " " + string(1, ch);
            s.push(result);
        }

        // handling unwanted symbols
        else
        {
            throw invalid_argument("Invalid Symbols!!");     
        }
    }

    if (s.size() != 1)
    {
        throw invalid_argument("Invalid Expression");
    }
    return s.peek();
}
