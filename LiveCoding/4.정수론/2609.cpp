//LiveCoding
//2609_�ִ������� �ּҰ����
#include <iostream>

using namespace std;

//��Ŭ���� ȣ����
//a>b�� ��, a�� b�� �ִ����� �����ϴ� �Լ�
int gcdRecursion(int a, int b){
	if (b == 0)
		return a;					//��������
	return gcdRecursion(b, a%b);	//mod + swap
}

int main(){
	int a, b;
	cin >> a >> b;

	//�ִ�����
	int g = gcdRecursion(max(a, b), min(a, b));

	//�ּҰ����
	int l = a * b / g;

	cout << g << '\n' << l;
}
