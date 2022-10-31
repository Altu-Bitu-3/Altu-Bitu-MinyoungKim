#include <iostream>
#include <queue>

using namespace std;

int main(){
	queue<int> q;
	int n, k;

	//입력 후 큐에 모든 숫자 넣기
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		q.push(i);
	//연산과 출력
	cout << "<";
	while (q.size() > 1){
		//제거하지 않는 숫자는 큐의 뒤에 넣고
		for (int i = 0; i < k-1; i++){
			q.push(q.front());
			q.pop();
		}
		//k번째 숫자 출력 후 제거
		cout << q.front() << ", ";
		q.pop();
	}
	cout << q.front() << ">";
}
