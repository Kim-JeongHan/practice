#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while (1)
    {
        string input;
        getline(cin, input);
        if(input == ".")
            break;
        stack<char> s;
        for (auto word : input)
        {
            if(word == '(' || word == '[')
                s.push(word);
            else if(s.empty() && (word == ')' || word == ']'))
            {
                s.push(word);
                break;
            }
            else if(word == ')' && s.top() == '(')
                s.pop();
            else if(word == ')' && s.top() == '[')
                break;
            else if(word == ']' && s.top() == '[')
                s.pop();
            else if(word == ']' && s.top() == '(')
                break;
            else if(word == '.')
                break;
        }
        if(s.empty())
            cout << "yes" << "\n";
        else
            cout << "no" << "\n";
    }
    
}