/* Check whether the paranthesis are valid or not. */
#include <iostream>
#include <stack>
#include <string>

bool isValid(std::string str)
{
    std::stack<int> st;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            st.push(str[i]);
        }
        else
        {
            if (st.empty())
            {
                return false;
            }
            if ((str[i] == ')' && st.top() == '(')
            || (str[i] == '}' && st.top() == '{')
            || (str[i] == ']' && st.top() == '['))
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }
    if (st.empty())
    {
        return true;
    }
    return false;
}

int main()
{
    std::string str = "[{()}]()";
    if (isValid(str))
    {
        std::cout << "Valid";
    }
    else
    {
        std::cout << "Invalid";
    }
    return 0;
}