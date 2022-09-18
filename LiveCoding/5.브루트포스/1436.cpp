//LiveCoding
//1436_영화감독숌

/*
<<연산 횟수 계산하기>>
666부터 10000번 째 종말의 수가 나올 때까지 666이 들어있는지 체크?
6,660,000~6,669,999 사이에 1만개의 종말의 숫자가 있으므로,
10000번 째 종말의 숫자는 6,669,999(<= 1억)보다는 작다.
->브루트포스 가능
*/

#include <iostream>

using namespace std;

//n번째 종말의 수를 찾는 함수
int getEndNumber(int n){
	int num = 666 - 1;

	while (n > 0){
		string s = to_string(++num);
		//find() 는
		if (s.find("666") != s.npos)
			n--;
	}
	return num;
}

int main(){
	int n;

	//입력
	cin >> n;

	//출력
	cout << getEndNumber(n);
	return 0;
}
