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
    //N=4, K=2, idx=2~(N-1)���� �˻�����
    //�߰��Ǵ� ���빰�� ����, ���ŵǴ� ���빰�� ����.
    // 3�� 2�� ���µ� 1���� ���� 
    // 3 3 3 3
    //     | |(right)
    // len[3]=3-1 => 2
    // len[3]+1 => 2��
    //right�� ���� �����ϸ� right++�� ���߰�,
    //left�� right�� ������ ������ �ϸ�����ʳ�?
    for (int right = K; right < N; right++)
    {
        len[names[right - K]]--; //0
        len[names[right]]++; //2
        sum += len[names[right - K]];
        //���� -> �Ǹ� ��ģ��. 
    }

    for (int left = (N - K); left < N-1 ; left++)
    {
        len[names[left]]--; //0
        sum += len[names[left]];
    }
    cout << sum << '\n';
}