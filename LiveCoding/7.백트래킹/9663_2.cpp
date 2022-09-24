#include <iostream>
#include <vector>
#define ABS(x, y) (x>y ? x-y : y-x)

using namespace std;

int n;
int ans;
//각 행(인덱스)에 대해 퀸 배치한 열(값) 저장
vector<int> queens;

bool ispromising(int row){
	for (int i = 0; i < row; i++){
		//같은 열에 이미 퀸 존재
		if (queens[i] == queens[row])
			return false;
		//같은 대각선 라인에 이미 퀸 존재
		if (ABS(queens[i], queens[row]) == ABS(i, row))
			return false;
		//퀸 배치 가능
	}
	return true;
}

void backtracking(int row){
	if (row == n){
		ans++;
		return ;
	}
	for (int col = 0; col < n; col++){
		queens.push_back(col);
		if (ispromising(row))
			backtracking(row+1);
		queens.pop_back();
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
