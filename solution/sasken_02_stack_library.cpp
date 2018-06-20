


#include <stack>
#include <assert.h>
#include <iostream>
using namespace std;

bool isBalanced(string expression)
{
    stack<char> st;

    for (char ch: expression){

        if (ch == '(' || ch == '{' || ch == '['){

            st.push(ch);
        }else if (ch == ')' || ch == '}' || ch == ']'){

            if (ch == ')' && st.top() == '('){

            }else if (ch == '}' && st.top() == '{'){

            }else if (ch == ']' && st.top() == '['){

            }else{
                return false;
            }

            st.pop();
        }
    }

    return st.empty();
}

int main(void)
{
    string expression;

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
