#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string input;
    getline(cin, input);
    stack<char> s;
    vector<int> sum;
    for (auto word : input)
    {
        if(s.empty()) s.push(word);
        else if(s.top()=='(' && word==')')
        {
            if(sum.empty()) sum.push_back(0);
            if(sum.back()==0) sum.back()+=2;
            else          sum.back()*=2;
            if(sum.size()>1)
            {
                sum[0] = sum.front()+sum.back();
                sum.pop_back();
            }
            s.pop();
        }
        else if(s.top()=='[' && word==']')
        {
            if(sum.empty()) sum.push_back(0);
            if(sum.back()==0) sum.back()+=3;
            else          sum.back()*=3;
            if(sum.size()>1)
            {
                sum[0] = sum.front()+sum.back();
                sum.pop_back();
            }
            s.pop();
        }
        else if(s.top()=='(' && word=='[')
        {
            if(!sum.empty()) sum.push_back(0);
            s.push(word);
        }
        else if(s.top()=='[' && word=='(')
        {
            if(!sum.empty()) sum.push_back(0);
            s.push(word);
        }
        else s.push(word);
        if(sum.empty()) cout << "no" << "\n";
        else  cout << sum[0] << "\n";
    }
    if(s.empty())
    {
        cout << sum[0];
    }
    else
    {
        cout << "0";
    }
}