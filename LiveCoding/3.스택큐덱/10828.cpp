//10828_���� : stack �����ϱ�
#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 1e4;			//���� ������ (10�� 4��)

vector<int> stack_vec(SIZE);	//vector�� ���� ����
int top_pointer = -1;			//������ ���� ��ġ ����Ű�� ������

//stack�� full���� Ȯ���ϴ� �Լ� (stl ��� �� �ʿ� ����)
bool full() {
	return (top_pointer == SIZE - 1);
}
//push: top�� ���� ����
void push(int x) {
	stack_vec[++top_pointer] = x;
}

//pop: top�� ���� ����
void pop() {
	top_pointer--;
}

//size: ���� ������ ��ȯ
int size() {
	return (top_pointer + 1);
}

//empty: ��� ������ 1, �ƴϸ� 0
bool empty() {
	return (top_pointer == -1); //true or false ��ȯ
}

//top: top�� �ִ� ���� ��ȯ
int top() {
	return (stack_vec[top_pointer]);
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
			cout << empty() << "\n"; //true�� 1�� , false�� 0���� �ڵ� ���
			continue;
		}
		if (cmd == "top"){
			cout << top() << "\n";
		}
	}
}
