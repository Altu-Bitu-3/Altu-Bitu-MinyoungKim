#include <iostream>
#include <vector>
#include <deque>

using namespace std;

deque<int> dq;

//front가 카드 더미 맨 밑, back이 카드 더미 맨 위
//기술 번호 x에 따라 카드 역순으로 다시 쌓기
void putCards(int x, int n){
	if (x == 1){
		dq.push_back(n);
	}
	if (x == 2){
		int tmp = dq.back();
		dq.pop_back();
		dq.push_back(n);
		dq.push_back(tmp);
	}
	if (x == 3){
		dq.push_front(n);
	}
}

int main(){
	int N, x;
	deque<int> x_arr;

	//입력
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> x;
		//입력 받은 기술을 역순으로 쉽게 사용하기 위해 deque 사용
		x_arr.push_front(x);
	}
	//카드 역순으로 다시 쌓기
	dq.push_back(1);
	for (int i = 2; i <= N; i++)
		putCards(x_arr[i-1], i);
	//출력
	while (dq.size()){
		cout << dq.back() << " ";
		dq.pop_back();
	}
}
