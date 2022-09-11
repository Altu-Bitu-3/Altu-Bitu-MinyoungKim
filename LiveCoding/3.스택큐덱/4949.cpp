//LiveCoding
//4949_균형잡힌세상
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
			//여는 괄호인 경우
			case '(': case '[':
				st.push(s[i]); //stack에 넣기
				break;
			//닫는 괄호인 경우
			case ')': case ']':
				if (st.empty() || st.top() != m[s[i]]) //비어있거나 짝이 맞지 않는 경우
					return false;
				st.pop(); //짝이 맞으면 stack에서 빼기
				break;
		}
	}
	return st.empty(); //stack이 비어있으면 balanced
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
