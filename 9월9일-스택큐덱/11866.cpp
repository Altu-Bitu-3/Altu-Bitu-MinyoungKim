#include <iostream>
#include <queue>

using namespace std;

int main(){
	queue<int> q;
	int n, k;

	//�Է� �� ť�� ��� ���� �ֱ�
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		q.push(i);
	//����� ���
	cout << "<";
	while (q.size() > 1){
		//�������� �ʴ� ���ڴ� ť�� �ڿ� �ְ�
		for (int i = 0; i < k-1; i++){
			q.push(q.front());
			q.pop();
		}
		//k��° ���� ��� �� ����
		cout << q.front() << ", ";
		q.pop();
	}
	cout << q.front() << ">";
}
