#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int number;
    cin >> number;
    deque<int> dQ;
    for(int i=0; i<number; i++)
    {
        string input;
        cin >> input;
        if(input=="push_front")
        {
            int data;
            cin >> data;
            dQ.push_front(data);
        }
        else if(input=="push_back")
        {
            int data;
            cin >> data;
            dQ.push_back(data);
        }
        else if(input=="pop_front")
        {
            if(dQ.empty())
            {
                cout << "-1" << "\n";
            }
            else
            {
                cout << dQ.front() << "\n";
                dQ.pop_front();
            }
        }
        else if(input=="pop_back")
        {
            if(dQ.empty())
            {
                cout << "-1" << "\n";
            }
            else
            {
                cout << dQ.back() << "\n";
                dQ.pop_back();
            }
        }
        else if(input=="size")
        {
            cout << dQ.size() << "\n";
        }
        else if(input=="empty")
        {
            cout << dQ.empty() << "\n";
        }
        else if(input=="front")
        {
            if(dQ.empty())
            {
                cout << "-1" << "\n";
            }
            else
                cout << dQ.front() << "\n";
        }
        else if(input=="back")
        {
            if(dQ.empty())
            {
                cout << "-1" << "\n";
            }
            else
                cout << dQ.back() << "\n";
        }
    }
}