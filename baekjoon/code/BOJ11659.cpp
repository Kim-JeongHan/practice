#include <bits/stdc++.h>

using namespace std;

int function1(const vector<int> & array, int first, int last)
{
    return array[last] -array[first-1];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int data_number, q_num;
    cin >> data_number >> q_num;
    int temp_array;
    vector<int> sum_ar;
    sum_ar.push_back(0);
    for(int i=0; i<data_number; i++)
    {
        cin >> temp_array;
        sum_ar.emplace_back(sum_ar.back()+temp_array);
        // ar.push_back(temp_array);
    }
    int arr_size_first, arr_size_last;
    int answer;
    for(int j=0; j<q_num; j++)
    {
        cin >> arr_size_first >> arr_size_last;
        answer =function1(sum_ar, arr_size_first, arr_size_last);
        cout << answer << "\n";
    }
}