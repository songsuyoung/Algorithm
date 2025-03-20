#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int extent = (brown+yellow); //실제 넓이
    
    for(int i=3; i<=extent/2; i++)
    {
        //공식 x*y = (brown+yellow); 를 이루는 값
        if((extent%i) == 0)
        {
            //0으로 떨어질 경우 실제 가능성 있는 답.
            int width = extent/i; //큰 값을 가진다 왜냐하면, 현재 i는 작은 값을 가지기 때문에 height <= width 라는 조건에 의해 나눗셈 연산을 한다.
            int height = i;
            
            //brown 값과 비교를 하기 위해 나온 식
            //실제로, (width-2)*2 + (height-2)*2 + 4 == brown 개수와 같다면 정답이다.
            int brownCnt = (width-2)*2 + (height-2)*2 + 4;
            
            if(brown == brownCnt)
            {
                answer.push_back(width);
                answer.push_back(height);
                break;
            }
        }
    }
    return answer;
}

/*
네오가 카펫을 사러감.. 중앙에 노란색으로 칠해져 있고, 테두리 1줄은 갈색으로 칠해져 있는 격자 모양 카펫을 봄.
근데, 네오가 기억을 못했다. => 그런데 개수는 기억한다. (직사각형)

예) 브라운 10, 엘로우 2
12 를 만들 수 잇는 수 (가로가 2이면 옐로우가 들어갈 수 없음. 근데 옐로우가 1개 이상이기 때문에, 3부터 가능)
3*4

총 12개 사각형을 만들려면 x*y => 3*4 크기의 사각형임을 알 수 있음.
가로 3, 세로 4인 크기의 사각형을 브라운으로 덮어보
브브브브
브    브
브브브브
=> 브라운 10개 나옴
가운데 2개는 엘로우다.
2+4+4 => 12개

예) 브라운 8 옐로우 1
x*y = (브+옐)
x*y = 9로 이루어질려면...
3*3 

(width-2)*2 + (heigth-2)*2 + 4 
2+2+4 => 8
브브브
브  브
브브브

예) 브라운 24 옐로우 24
x*y =(브+옐)
x*y = 24+24 즉, 48

x= 3부터 시작..

width x height
3x16
브라운이 24개밖에 없는데.. 16을 만들 수 있나? 보통.. 겹치는 4개를 제외한 (width-2)*2 + (height-2)*2 + 4(겹치는 수) => 브라운 수와 같으면 정답!
브브브브브브브브브브브브브브브
브
브
4x12
6x8

가로 길이는 세로 길이와 같거나(정사각형)
세로 길이보다 길다. (즉 width가 더 크다)
*/