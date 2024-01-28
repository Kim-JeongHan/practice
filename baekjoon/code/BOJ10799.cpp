#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string input;
    getline(cin, input);
    stack<char> s;
    int number=0;
    int trash=0;
    for(auto i : input)
    {
        if(s.empty()) 
        {
            s.push(i);
        }
        else if(s.top()=='(' && i==')')
        {
            number += (s.size()-1-trash);
            trash += 2;
            s.push(i);
        }
        else if(s.top()==')' && i ==')')
        {
            number+=1;
            trash +=2;
            s.push(i);
        }
        else
            s.push(i);
    }
    cout << number  << "\n";
}