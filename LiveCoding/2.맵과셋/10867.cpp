//LiveCoding
#include <iostream>
#include <set>

using namespace std;

int main(){
	int n, input;
	set<int> s;

	//�Է�
	cin >> n;
	while (n--){
		cin>>input;
		s.insert(input); //�¿� ����
	}
	//set<int>::iterator iter;
	//auto: �ʱ�ȭ ���� ���� ������ Ÿ�� �ڵ����� ������
	for (auto iter = s.begin(); iter != s.end(); iter++){
		cout << *iter << ' ';
	}
	return 0;
}
