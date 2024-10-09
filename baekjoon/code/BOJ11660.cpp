#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int box_size, input_num;
    cin >> box_size >> input_num;
    int temp;
    vector<vector<int>> ar;
    vector<int> temp_vec(box_size+1,0);
    for(int i=0; i<= box_size; i++) ar.push_back(temp_vec);
    for(int j=1; j<=box_size; j++)
    {
        for(int i=0; i<=box_size; i++)
        {
            if(i==0) ar[j][i]=0; 
            else
            {
                cin >> temp;
                ar[j][i] = ar[j][i-1] + ar[j-1][i]+temp-ar[j-1][i-1];
            }
        }
    }

    int x1,y1,x2,y2;
    for(int i=0; i<input_num; i++)
    {
        cin >> y1 >> x1 >> y2 >> x2;
        cout << ar[y2][x2] - ar[y2][x1-1] - ar[y1-1][x2] + ar[y1-1][x1-1] << "\n"; 
    }
}