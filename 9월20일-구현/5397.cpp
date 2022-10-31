//5397_키로거
#include <iostream>
#include <stack>
#include <ctype.h>
#include <algorithm>

using namespace std;

stack<char> input; //입력된 비밀번호
stack<char> buffer; //현재 커서 뒷부분에 있는 문자 임시 저장

//비밀번호를 출력하는 함수
void printPW(string s){
	//input, buffer 초기화
	while(!input.empty())
        input.pop();
	while(!buffer.empty())
        buffer.pop();
	//비밀번호 찾기
	for (int i = 0; i < s.length(); i++){
		char c = s[i];
		if (isalnum(c))
			input.push(c);
		if (c == '<' && !input.empty()){
			buffer.push(input.top());
			input.pop();
		}
		if (c == '>' && !buffer.empty()){
			input.push(buffer.top());
			buffer.pop();
		}
		if (c == '-' && !input.empty()){
			input.pop();
		}
	}
	//buffer에 문자 남아있으면 모두 input으로
	while (!buffer.empty()){
		input.push(buffer.top());
		buffer.pop();
	}
	//스택 출력
	string print = "";
	while (!input.empty()) {
		print += input.top();
		input.pop();
	}
	reverse(print.begin(), print.end());
	cout << print << '\n';
}

int main(){
	int n;
	string s;

	//입력 및 출력
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> s;
		printPW(s);
	}

	return 0;
}
