#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> all;
void recursive(int M, vector<int>& arr, vector<int>& tmp)
{
    if (M == tmp.size())
    {
        all.push_back(tmp);
        return;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        tmp.push_back(arr[i]);
        recursive(M, arr, tmp);
        tmp.pop_back();
    }
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    vector<int> tmp;
    recursive(M, arr, tmp);

    sort(all.begin(), all.end());

    all.erase(unique(all.begin(), all.end()), all.end());

    for (int i = 0; i < all.size(); i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << all[i][j] << ' ';
        }
        cout << '\n';
    }
}