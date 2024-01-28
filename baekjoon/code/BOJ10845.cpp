#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int number;
    cin >> number;
    queue<int> Q;

    for(int i=0; i<number; i++)
    {
        string input;
        cin >> input;
        if(input == "push")
        {
            int data;
            cin >> data;
            Q.push(data);
        }
        else if(input == "pop")
        {
            if(Q.empty())
            {
                cout << "-1" << "\n";
            }
            else
            {
                cout << Q.front() << "\n";
                Q.pop();
            }
        }
        else if(input == "size")
        {
            cout << Q.size() << "\n";
        }
        else if(input == "empty")
        {
            cout << Q.empty() << "\n";
        }
        else if(input == "front")
        {
            if(Q.empty())
            {
                cout << "-1" << "\n";
            }
            else
                cout << Q.front() << "\n";
        }
        else if(input == "back")
        {
            if(Q.empty())
            {
                cout << "-1" << "\n";
            }
            else
                cout << Q.back() << "\n";
        }
    }
}