#include <iostream>
#include <vector>
#include <deque>

using namespace std;

deque<int> dq;

//front�� ī�� ���� �� ��, back�� ī�� ���� �� ��
//��� ��ȣ x�� ���� ī�� �������� �ٽ� �ױ�
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

	//�Է�
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> x;
		//�Է� ���� ����� �������� ���� ����ϱ� ���� deque ���
		x_arr.push_front(x);
	}
	//ī�� �������� �ٽ� �ױ�
	dq.push_back(1);
	for (int i = 2; i <= N; i++)
		putCards(x_arr[i-1], i);
	//���
	while (dq.size()){
		cout << dq.back() << " ";
		dq.pop_back();
	}
}
