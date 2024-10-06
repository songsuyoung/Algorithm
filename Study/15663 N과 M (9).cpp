#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> all;
void recursive(int M,vector<int>& arr, vector<int>& tmp)
{
    if (M == tmp.size())
    {
        all.push_back(tmp);
        return;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (find(tmp.begin(), tmp.end(), i)!=tmp.end()) continue;

        tmp.push_back(i);
        recursive(M,arr, tmp);
        tmp.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);


    int N, M;
    cin >> N >> M;

    vector<int> arr(N, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    vector<int> tmp;
    recursive(M,arr, tmp);
    vector<vector<int>> sortedAll;

    for (int i = 0; i < all.size(); i++)
    {
        vector<int> tmp;
        for (int j = 0; j < M; j++)
        {
            tmp.push_back(arr[all[i][j]]);
        }
        sortedAll.push_back(tmp);
    }

    sort(sortedAll.begin(), sortedAll.end());

    sortedAll.erase(unique(sortedAll.begin(), sortedAll.end()), sortedAll.end());

    for (int i = 0; i < sortedAll.size(); i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << sortedAll[i][j] << ' ';
        }
        cout << '\n';
    }
}