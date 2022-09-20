//LiveCoding
//2231_������

/*
<<���� Ƚ�� ����ϱ�>>
input ���� 1 <= n <= 1,000,000 �̹Ƿ�,
1���� 1,000,000���� �������� ��� ����ϴ���
7 * 1,000,000 ȸ�� ������ ���� �� �����Ƿ� ���Ʈ���� ��� ����
*/

#include <iostream>

using namespace std;

//1���� n���� ������ ���غ��鼭, ���� ���� �����ڸ� ã�� �����ϴ� �Լ�
int findConstructor(int n){
	int sum;

	for (int i = 1; i < n; i++){
		//�ݺ��� ������ i�� �������� �ʱ� ���� �ӽ� ���� ���
		int temp = i;
		sum = i;

		//�� �ڸ� �� ���ϱ�
		while (temp){
			sum += temp % 10;
			temp /= 10;
		}
		//i�� �������� n�� ������ i�� n�� ������
		//1���� �����Ͽ� Ž���ϹǷ� ���� ���� ������ ����
		if (sum == n)
			return i;
	}
	//�����ڰ� ���� ���
	return 0;
}

int main(){
	int n;

	//�Է�
	cin >> n;
	cout << findConstructor(n);
	return 0;
}
