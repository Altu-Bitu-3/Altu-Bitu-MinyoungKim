#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Ȧ�� �� ���ڰ� �� ������ Ȯ���Ͽ� �����ϴ� �Լ� + ��� ���ڵ� ����
int cntOdd(vector<int> alpha, char &mid){
	int cnt = 0; //alpha�� �� �� Ȧ���� �� üũ

	for (char i = 'A'; i <= 'Z'; i++){
		if (alpha[i]%2){
			cnt++;
			mid = i;	//�� �Լ� ���� ���� 1�� ���� mid ���
		}
	}

	return cnt;
}

//�Ӹ���� ����� �Լ�
string makePal(vector<int> alpha, char mid){
	string s;
	string tmp;

	for (char i = 'A'; i <= 'Z'; i++)
		if (alpha[i])
			for (char j = 0; j < alpha[i]/2; j++)
				s += i;
	tmp = s;
	if (mid)
		s += mid;
	reverse(tmp.begin(), tmp.end());
	s += tmp;
	return s;
}

int main(){
	vector<int> alpha(91, 0); //'Z'�� �ƽ�Ű�ڵ� ���� 90�̹Ƿ� 91�� �ʱ�ȭ
	string name;
	string nameToPal="";
	char mid=0;

	//�Է�
	cin >> name;

	//�Է� ���� �̸��� �� ������ �ƽ�Ű�ڵ忡 �ش��ϴ� �ε����� ���� �ø���
	for (int i = 0; i < name.length(); i++)
		alpha[name[i]]++;
	if(cntOdd(alpha, mid) >= 2)
			cout << "I'm Sorry Hansoo";
	else
		cout << makePal(alpha, mid);
}
