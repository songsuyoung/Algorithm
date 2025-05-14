#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = -1;

    sort(mats.begin(), mats.end(), greater<>());

    for (int i = 0; i < mats.size(); i++) {
        int size = mats[i];

        if (park.size() < size) continue;

        // 모든 행이 최소한 size 길이의 열을 갖는지 확인
        bool isValidCol = true;
        for (int row = 0; row < park.size(); row++) {
            if (park[row].size() < size) {
                isValidCol = false;
                break;
            }
        }
        if (!isValidCol) continue;

        for (int r = 0; r <= park.size() - size; r++) {
            for (int c = 0; c <= park[r].size() - size; c++) {
                bool bIsSuccess = true;
                for (int cr = r; cr < r + size; cr++) {
                    for (int cc = c; cc < c + size; cc++) {
                        if (cc >= park[cr].size() || park[cr][cc] != "-1") {
                            bIsSuccess = false;
                            break;
                        }
                    }
                    if (!bIsSuccess) break;
                }
                if (bIsSuccess) return size;
            }
        }
    }

    return answer;
}

/*
지민이는 다양한 크기의 정사각형 모양의 돗자리를 가지고 있음.

여가를 즐기는 사람들이 많아서 깔 수 있는 가장 큰 돗자리를 확인 => 그래프 문제 - 연결된 그래프만 확인 -> BFS(or DFS) -> ㄴㄴ 지민이가 깔수있는지를 확인
예)
지민이가 가지고 있는 한 변의 길이가 5,3,2 

빈자리가 있다면 가장 큰 변부터 놓아본다 => 최대 크기이기 때문에.
놓고,
리셋처리 
=> 5중 for문으로 해결가능
*/