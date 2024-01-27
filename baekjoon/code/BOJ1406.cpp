#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string text;
    getline(cin, text);
    list<char> L;
    for(auto c : text)
        L.push_back(c);
    list<char>::iterator cursor = L.end();
    int number;
    cin >> number;
    for(int i = 0; i < number; i++){
        char command;
        cin >> command;
        switch (command)
        {
            case 'L':
                if(cursor != L.begin())
                    cursor--;
                break;
            case 'D':
                if(cursor != L.end())
                    cursor++;
                break;
            case 'B':
                if( cursor != L.begin())
                    cursor = L.erase(--cursor);
                break;
            case 'P':
                char c;
                cin >> c;
                L.insert(cursor, c);
                break;
        }
        // cout << "cursor : " << *cursor << '\n';
        // for(auto c : L)
        //     cout << c;
        // cout << '\n';
    }
    for(auto c : L)
        cout << c;
    cout << '\n';
    return 0;
}