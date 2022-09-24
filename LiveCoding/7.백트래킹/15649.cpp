#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 8;

int n, m;
vector<int> num(SIZE);
vector<bool> check(SIZE);

void backtracking(int cnt){ //cnt : 수열의 인덱스
	if (cnt == m){ //길이 m인 수열 만들었다면 (기저조건)
		for (int i = 0; i < cnt; i++){
			cout << num[i] << ' ';
		}
		cout << '\n';
		return ;
	}
	for (int i = 1; i <= n; i++){
		if (!check[i]){ //현재 수열에 해당 수가 없을 때만
			num[cnt] = i; //사용
			check[i] = true;
			backtracking(cnt+1); //다음 인덱스 수 호출
			//다음 노드 탐색 시 check 배열의 해당 수 값 초기화
			check[i] = false;
		}
	}
}
int main(){
	//입력
	cin >> n >> m;

	//연산
	backtracking(0);
	return 0;
}
