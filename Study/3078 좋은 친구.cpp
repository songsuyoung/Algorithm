#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> names;

    for (int i = 0; i < N; i++)
    {
        string name;
        cin >> name;
        names.push_back(name.length());
    }

    vector<int> len(300001, 0);
    int cnt = 0;
    int right = 1;

    int sum = 0;

    for (int i = 0; i < K; i++)
    {
        len[names[i]]++;
    }
    //N=4, K=2, idx=2~(N-1)까지 검사진행
    //추가되는 내용물은 없고, 제거되는 내용물만 있음.
    // 3이 2개 였는데 1개로 줄임 
    // 3 3 3 3
    //     | |(right)
    // len[3]=3-1 => 2
    // len[3]+1 => 2쌍
    //right는 끝에 도달하면 right++을 멈추고,
    //left와 right가 같아질 때까지 하면되지않나?
    for (int right = K; right < N; right++)
    {
        len[names[right - K]]--; //0
        len[names[right]]++; //2
        sum += len[names[right - K]];
        //조합 -> 되면 합친다. 
    }

    for (int left = (N - K); left < N-1 ; left++)
    {
        len[names[left]]--; //0
        sum += len[names[left]];
    }
    cout << sum << '\n';
}