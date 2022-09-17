//LiveCoding
//4949_������������
#include <iostream>
#include <stack>
#include <map>

using namespace std;

bool isBalanced(string &s){
	stack<char> st;
	map<char, char> m;
	m[']'] = '[';
	m[')'] = '(';

	for (int i = 0; i < s.length(); i++){
		switch(s[i]){
			//���� ��ȣ�� ���
			case '(': case '[':
				st.push(s[i]); //stack�� �ֱ�
				break;
			//�ݴ� ��ȣ�� ���
			case ')': case ']':
				if (st.empty() || st.top() != m[s[i]]) //����ְų� ¦�� ���� �ʴ� ���
					return false;
				st.pop(); //¦�� ������ stack���� ����
				break;
		}
	}
	return st.empty(); //stack�� ��������� balanced
}

int main(){
	string s;

	while (getline(cin, s)){
		if (s == ".")
			break;
		if (isBalanced(s))
			cout << "yes\n";
		else
			cout << "no\n";
	}
}
