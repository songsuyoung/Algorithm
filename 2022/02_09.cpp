#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

void dfs(int** cablist, int x, int y, bool** visited,int M,int N) {

	int dx[] = { -1,0,1,0 }; //행
	int dy[] = { 0,1,0,-1 }; //열
	// 회전 (-1,0)좌 -> (0,1)우 -> (1,0)상 -> (0,-1)하

	visited[x][y] = true;

	for (int k = 0; k < 4; k++) {
		int tx = x + dx[k];//tempx
		int ty = y + dy[k];//tempy

		if (tx>=0&&tx<M&&ty>=0&&ty<N) {
			if(cablist[tx][ty] && !visited[tx][ty])
				dfs(cablist, tx, ty, visited,M,N);
		}
	}
}

int main() {

	int input;
	cin >> input;
	int** cablist;

	while (input) {
		int M, N; //M 가로길이 N 세로길이
		int cabNum = 0;
		bool** visited;
		int earthworm = 0;
		cin >> M >> N >> cabNum;

		cablist = new int* [M];
		visited = new bool* [M];
		for (int i = 0; i < M; i++) {
			cablist[i] = new int[N];
			visited[i] = new bool[N];
			memset(cablist[i], 0, sizeof(int) * N);
			memset(visited[i], false, sizeof(bool) * N);
		}

		for (int i = 0; i < cabNum; i++)
		{
			int TempN, TempM;
			cin >> TempM >> TempN;
			cablist[TempM][TempN] = 1;
		}

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (cablist[i][j]) {
					if (!visited[i][j]) {
						earthworm++;
						cout << i << "," << j << endl;
						dfs(cablist, i, j, visited, M, N);
					}
				}
			}
		}
		cout << earthworm << endl;
		for (int i = 0; i < M; i++) {
			delete(cablist[i]);
			delete(visited[i]);
		}
		delete(cablist);
		delete(visited);

		input--;
	}
}