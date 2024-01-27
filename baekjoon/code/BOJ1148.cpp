#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<string> dic;
    while(1)
    {
        string word;
        getline(cin, word);
        if(word == "-")
            break;
        dic.push_back(word);
    }
    while(1)
    {
        string puzzle;
        getline(cin, puzzle);
        if(puzzle == "#")
            break;
        int puzzle_count[10];
        for(auto word : dic)
        {
            
        }
    }
}