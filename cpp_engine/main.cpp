#define CROW_USE_ASIO
#include "crow.h"
#include <iostream>
#include "Myvector.h"
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
    crow::SimpleApp app;
    CROW_ROUTE(app, "/analyze").methods("POST"_method)([](const crow::request &req)
                                                       {
    auto body=crow::json::load(req.body);
    if(!body){
        return crow::response(400, "Invalid or empty JSON");
    }
    if(!body.has("code")){
        return crow::response(400,"MISSING CODE FIELD");
    }
    if(body["code"].t()!=crow::json::type::String){
        return crow::response(400,"CODE FIELD MUST BE A STRING");
    }
    auto input = body["code"].s();
    if (isCodeInput(input))
    {
        Myvector<int> result = analyzeCode(input);
        string output = "";
        output += "for : " + to_string(result[0]) + "\n";
        output += "if : " + to_string(result[1]) + "\n";
        output += "else : " + to_string(result[2]) + "\n";
        output += "while : " + to_string(result[3]) + "\n";
        output += "Max Depth : " + to_string(result[4]) + "\n";
        string complexity = timeComplexity(result[4]);
        output += "Estimated Complexity: : " + complexity + "\n";
        return crow::response(200,output);
    }else
    {
        Type t = detectType(input);

        if (t == INVALID)
            return crow::response(400, "Invalid expression type. Please provide a valid infix, prefix, or postfix expression.");
        string postfix;

        if (t == INFIX)
            postfix = infixToPostfix(input);
        else if (t == PREFIX)
            postfix = prefixToPostfix(input);
        else
            postfix = exp;

        if (postfix == "")
            return crow::response(400, "Conversion failed. Please check your expression and try again.");
        string output = "";
        output += "Postfix : " + postfix + "\n";
        output += "Infix: " + postfixToInfix(postfix) + "\n";
        output += "Prefix: " + postfixToPrefix(postfix) + "\n";
        output += "Result : " + to_string(postfixEvaluation(postfix)) + "\n";
        return crow::response(200, output);
    } });

    app.port(5000).multithreaded().run();
    return 0;
}