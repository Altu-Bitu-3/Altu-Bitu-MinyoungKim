//10845_ť : Queue �����ϱ�
#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 1e4 + 1; //1�� �ε������� ���� ��

vector<int> queue_vec(SIZE);
int front_ptr = 0, rear_ptr = 0;

//ť�� full���� �˻��ϴ� �Լ�
bool full() {
	return ((rear_ptr + 1) % SIZE == front_ptr);
}

//push: ����
void push(int x) {
	rear_ptr = (rear_ptr + 1) % SIZE;
	queue_vec[rear_ptr] = x;
}

//pop: front �� ����
void pop() {
	front_ptr = (front_ptr + 1) % SIZE;
}

//size: ť ������
int size() {
	int tmp = rear_ptr - front_ptr;
	if (tmp < 0) //rear < front �̸�
		tmp += SIZE;
	return tmp;
}

//empty: ����ִ��� Ȯ��
bool empty() {
	return (rear_ptr == front_ptr);
}

//front: front ���� ��ȯ
int front() {
	return (queue_vec[(front_ptr + 1) % SIZE]);
}

//back: rear ���� ��ȯ
int back() {
	return (queue_vec[rear_ptr]);
}

int main() {
	int n, x;
	string cmd;

	//�Է�
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
