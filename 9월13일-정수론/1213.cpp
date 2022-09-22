#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//홀수 개 문자가 몇 개인지 확인하여 리턴하는 함수 + 가운데 문자도 저장
int cntOdd(vector<int> alpha, char &mid){
	int cnt = 0; //alpha의 값 중 홀수인 것 체크

	for (char i = 'A'; i <= 'Z'; i++){
		if (alpha[i]%2){
			cnt++;
			mid = i;	//이 함수 리턴 값이 1일 때만 mid 사용
		}
	}

	return cnt;
}

//팰린드롬 만드는 함수
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
	vector<int> alpha(91, 0); //'Z'의 아스키코드 값이 90이므로 91개 초기화
	string name;
	string nameToPal="";
	char mid=0;

	//입력
	cin >> name;

	//입력 받은 이름의 각 문자의 아스키코드에 해당하는 인덱스의 값을 올리기
	for (int i = 0; i < name.length(); i++)
		alpha[name[i]]++;
	if(cntOdd(alpha, mid) >= 2)
			cout << "I'm Sorry Hansoo";
	else
		cout << makePal(alpha, mid);
}
