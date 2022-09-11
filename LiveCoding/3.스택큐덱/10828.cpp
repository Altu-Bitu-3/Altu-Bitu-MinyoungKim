//10828_스택 : stack 구현하기
#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 1e4;			//스택 사이즈 (10의 4승)

vector<int> stack_vec(SIZE);	//vector로 스택 생성
int top_pointer = -1;			//스택의 현재 위치 가리키는 포인터

//stack이 full인지 확인하는 함수 (stl 사용 시 필요 없음)
bool full() {
	return (top_pointer == SIZE - 1);
}
//push: top에 원소 삽입
void push(int x) {
	stack_vec[++top_pointer] = x;
}

//pop: top의 원소 삭제
void pop() {
	top_pointer--;
}

//size: 스택 사이즈 반환
int size() {
	return (top_pointer + 1);
}

//empty: 비어 있으면 1, 아니면 0
bool empty() {
	return (top_pointer == -1); //true or false 반환
}

//top: top에 있는 원소 반환
int top() {
	return (stack_vec[top_pointer]);
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
			if (!empty())
				cout << "-1\n";
			else{
				cout << top() << "\n";
				pop();
			}
			continue;
		}
		if (cmd == "size"){
			cout << size() << "\n";
			continue;
		}
		if (cmd == "empty"){
			cout << empty() << "\n"; //true는 1로 , false는 0으로 자동 출력
			continue;
		}
		if (cmd == "top"){
			cout << top() << "\n";
		}
	}
}
