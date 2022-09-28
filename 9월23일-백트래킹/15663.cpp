#include <iostream>
#include <vector>
#include <algorithm>
//잚못된 코드 !!!
using namespace std;
const int SIZE = 8;

int n, m;

vector<int> make(SIZE);
vector<bool> check(SIZE);

void backtracking(int cnt, vector<int> &input){ //cnt : 수열의 인덱스
	if (cnt == m){ //길이 m인 수열 만들었다면 (기저조건)
		for (int i = 0; i < cnt; i++){
			cout << make[i] << ' ';
		}
		cout << '\n';
		return ;
	}
	for (int i = 0; i < n; i++){
		int num = input[i];
		if (!check[num]){ //현재 수열에 해당 수가 없을 때만
			make[cnt] = i; //사용
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
	vector<int> input(n);
	for (int i = 0; i < n; i++){
		cin >> input[i];
	}

	//정렬 및 중복 제거
	sort(input.begin(), input.end());
	input.erase(unique(input.begin(), input.end()), input.end());

	//연산
	backtracking(0, input);
	return 0;
}
