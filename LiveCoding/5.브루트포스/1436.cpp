//LiveCoding
//1436_��ȭ������

/*
<<���� Ƚ�� ����ϱ�>>
666���� 10000�� ° ������ ���� ���� ������ 666�� ����ִ��� üũ?
6,660,000~6,669,999 ���̿� 1������ ������ ���ڰ� �����Ƿ�,
10000�� ° ������ ���ڴ� 6,669,999(<= 1��)���ٴ� �۴�.
->���Ʈ���� ����
*/

#include <iostream>

using namespace std;

//n��° ������ ���� ã�� �Լ�
int getEndNumber(int n){
	int num = 666 - 1;

	while (n > 0){
		string s = to_string(++num);
		//find() ��
		if (s.find("666") != s.npos)
			n--;
	}
	return num;
}

int main(){
	int n;

	//�Է�
	cin >> n;

	//���
	cout << getEndNumber(n);
	return 0;
}
