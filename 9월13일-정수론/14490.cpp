#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int gcdIter(int a, int b){
	while (b){
		a %= b;
		swap(a, b);
	}
	return a;
}

int main(){
	string input;
	int i=0, n=0, m=0, gcd;

	//입력
	cin >> input;
	//n과 m 입력 받기
	for (i = 0; input[i] != ':'; i++)
		n = n * 10 + input[i] - '0';
	for (++i; i < input.length(); i++)
		m = m * 10 + input[i] - '0';
	//최대공약수 구하기
	gcd = gcdIter(max(n, m), min(n, m));
	//출력
	cout << n/gcd << ':' << m/gcd;
}
