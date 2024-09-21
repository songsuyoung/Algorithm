#include <iostream>
#include <vector>
using namespace std;

void recursive(int N, int M, vector<int> &arr, int idx)
{
    if (arr.size() == M)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = idx; i <= N; i++)
    {
        arr.push_back(i);
        recursive(N, M, arr,i+1);
        arr.pop_back();
    }
}
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    
    vector<int> arr;
    vector<int> isVisited(N, 0);

    recursive(N, M, arr, 1);
     
}