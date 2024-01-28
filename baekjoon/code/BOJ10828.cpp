#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int stack[100000];
    int index=-1;
    int number;
    cin >> number;
    for(int i=0; i<number; i++)
    {
        string input;
        cin >> input;
        if(input=="push")
        {
            int data;
            cin >> data;
            stack[++index] = data;
        }
        else if(input == "pop")
        {
            if(index==-1)
            {
                cout << "-1" << "\n";
            }
            else
            {
                cout << stack[index] << "\n";
                index--;
            }
        }
        else if(input == "top")
        {
            if(index==-1)
            {
                cout << "-1" << "\n";
            }
            else
            {
                cout << stack[index] << "\n";
            }
        }
        else if(input == "size")
        {
            cout << index+1 << "\n";
        }
        else if(input == "empty")
        {
            if(index==-1)
            {
                cout << "1" << "\n";
            }
            else
            {
                cout << "0" << "\n";
            }
        }
        else
        {
            cout << "error";
            break;
        }
    }
    
}
