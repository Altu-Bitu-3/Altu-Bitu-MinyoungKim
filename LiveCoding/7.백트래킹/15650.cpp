#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 8;

int n, m;
vector<int> num(SIZE);
vector<int> check(SIZE);

void backtracking(int cnt, int start){ //start:탐색 시작하는 원소 값
if (cnt == m){ //길이 m인 수열 만들었다면 (기저조건)
		for (int i = 0; i < cnt; i++){
			cout << num[i] << ' ';
		}
		cout << '\n';
		return ;
	}
	for (int i = start; i <= n; i++){ //start부터 탐색하므로 check배열 필요없음
		num[cnt] = i; //사용
		backtracking(cnt+1, i+1); //다음 인덱스 수 호출
	}
}

int main(){
	//입력
	cin >> n >> m;

	//연산
	backtracking(0, 1);
	return 0;
}
