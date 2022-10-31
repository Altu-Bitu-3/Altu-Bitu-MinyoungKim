#include <iostream>	//기본 입출력 헤더
#define MAX(x, y) ((x) > (y) ? (x) : (y));	//x,y 중 더 큰 값 반환하는 매크로 함수

using namespace std;	//std 라이브러리

int maze[1000][1000];	//각 방에 놓인 사탕 저장할 maze 배열
int candy[2000][2000];	//각 방까지 가면서 가져갈 수 있는 최대 사탕 개수 저장하는 dp 배열

int main()	//메인 함수
{
	int N, M;	//미로의 크기 저장할 변수

	cin >> N >> M;	//입력
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> maze[i][j];	//2차원 배열로 각 방의 사탕 입력 받기
		}
	}

	candy[0][0] = maze[0][0];	//초기값 저장
	for (int i = 0; i < N; i++){	//이중 for문 돌면서
		for (int j = 0; j < M; j++){
			int cur = candy[i][j];	//현재 위치까지의 사탕 개수 저장하는 cur 변수
			candy[i+1][j] = MAX(candy[i+1][j], cur + maze[i+1][j]);	//오른쪽으로 이동할 때
			candy[i][j+1] = MAX(candy[i][j+1], cur + maze[i][j+1]);	//아래쪽으로 이동할 때
			candy[i+1][j+1] = MAX(candy[i+1][j+1], cur + maze[i+1][j+1]);	//오른쪽 대각선으로 이동할 때
			//각 위치까지 가져올 수 있는 사탕 개수의 최댓값 저장
		}
	}

	cout << candy[N-1][M-1];	//(N,M)으로 이동할 때, 가져올 수 있는 사탕 개수 최댓값 출력
}
