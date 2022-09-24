#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 15;

int n, ans;
//각 행에 대해 아래 열, 좌햐향 대각선, 우하향 대각선에
//퀸 배치되었는지 여부를 저장하는 배열
//[ex] check_col[i]==true -> i열에 퀸 배치 완료
//세 개의 배열의 값이 false이면 배치 가능
vector<bool> check_col(SIZE); //열
vector<bool> check_left(SIZE * 2); //좌하향 대각선
vector<bool> check_right(SIZE * 2); //우하향 대각선

//행을 기준으로 퀸 배치
void backtracking(int row){
	if (row == n){
		ans++;
		return ;
	}
	for (int i = 0; i < n; i++){ //i : 열
		//아래 열, 좌하향 대각선, 우하향 대각선에 퀸이 없는 경우
		if (!check_col[i] && !check_left[row+i] && !check_right[row-i+n]){
			check_col[i] = true;
			check_left[row+i] = true;
			check_right[row-i+n] = true;
			backtracking(row+1); //다음 행 호출
			check_col[i] = false;
			check_left[row+i] = false;
			check_right[row-i+n] = false;
		}
	}
}

int main(){
	//입력
	cin >> n;
	//연산
	backtracking(0);
	//출력
	cout << ans;

	return 0;
}
