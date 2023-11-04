#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<pair<int, int>> lines;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int start, end;
        cin >> start >> end;
        lines.push_back(make_pair(start, end));
    }

    sort(lines.begin(), lines.end());

    long dis = abs(lines[0].first-lines[0].second);

    int lastVal = lines[0].second;
    for (int i = 1; i < N; i++) {
 
        if (lastVal > lines[i].first&&lines[i].second<=lastVal) {
            //작으면 다음으로 넘어간다.
            continue;
        }
        else if (lastVal > lines[i].first && lines[i].second > lastVal) {
            dis += abs(lastVal - lines[i].second);
        }
        else {
            dis += abs(lines[i].first - lines[i].second);
        }
        //같거나 크면 dis계산
        lastVal = lines[i].second;
    }

    cout << dis << '\n';

    return 0;
}