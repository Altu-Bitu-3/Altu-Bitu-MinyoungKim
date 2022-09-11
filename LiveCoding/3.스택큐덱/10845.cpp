//10845_큐 : Queue 구현하기
#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 1e4 + 1; //1번 인덱스부터 값이 들어감

vector<int> queue_vec(SIZE);
int front_ptr = 0, rear_ptr = 0;

//큐가 full인지 검사하는 함수
bool full() {
	return ((rear_ptr + 1) % SIZE == front_ptr);
}

//push: 삽입
void push(int x) {
	rear_ptr = (rear_ptr + 1) % SIZE;
	queue_vec[rear_ptr] = x;
}

//pop: front 값 삭제
void pop() {
	front_ptr = (front_ptr + 1) % SIZE;
}

//size: 큐 사이즈
int size() {
	int tmp = rear_ptr - front_ptr;
	if (tmp < 0) //rear < front 이면
		tmp += SIZE;
	return tmp;
}

//empty: 비어있는지 확인
bool empty() {
	return (rear_ptr == front_ptr);
}

//front: front 원소 반환
int front() {
	return (queue_vec[(front_ptr + 1) % SIZE]);
}

//back: rear 원소 반환
int back() {
	return (queue_vec[rear_ptr]);
}

int main() {
	int n, x;
	string cmd;

	//입력
	cin >> n;
	while (n--){
		cin >> cmd;
		if (cmd == "push"){
			cin >> x;
			if (!full())
				push(x);
			continue;
		}
		if (cmd == "pop"){
			if (empty())
				cout << "-1\n";
			else{
				cout << front() << '\n';
				pop();
			}
			continue;
		}
		if (cmd == "size"){
			cout << size() << '\n';
			continue;
		}
		if (cmd == "empty"){
			cout << empty() << '\n';
			continue;
		}
		if (cmd == "front"){
			if (empty())
				cout << "-1\n";
			else
				cout << front() << '\n';
			continue;
		}
		if (cmd == "back"){
			if (empty())
				cout << "-1\n";
			else
				cout << back() << '\n';
		}
	}
	return 0;
}
