


#include <stack>
#include <assert.h>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool isBalanced(string expression)
{
    char * parenthesis = new char[expression.length()];

    int index = 0;
    for (char ch:expression){

        if (ch == '(' || ch == '{' || ch == '['){
            parenthesis[index++] = ch;
        }else if (ch == ')' || ch == '}' || ch == ']'){

            if (ch == ')' && parenthesis[index - 1] == '('){
            }else if (ch == '}' && parenthesis[index - 1] == '{'){
            }else if (ch == ']' && parenthesis[index - 1] == '['){
            }else{
                return false;
            }
            --index;
        }
    }
    parenthesis[index] = '\0';
    delete []parenthesis;
    return strlen(parenthesis) == 0;
}


int main(void)
{
    string expression;
    expression = "()";
    assert(isBalanced(expression) == true);

    expression = "(a+b)+c - (c*d)";
    assert( isBalanced(expression) == true);
    expression = "()(())";
    assert( isBalanced(expression) == true);
    expression = "()(()";
    assert( isBalanced(expression) == false);
    expression = "[{()}]";
    assert( isBalanced(expression) == true);
    expression = "{()}[]";
    assert( isBalanced(expression) == true);
  
    return 0;
}
