//LiveCoding
//2609_최대공약수와 최소공배수
#include <iostream>

using namespace std;

//유클리드 호제법
//a>b일 때, a와 b의 최대공약수 리턴하는 함수
int gcdRecursion(int a, int b){
	if (b == 0)
		return a;					//종료조건
	return gcdRecursion(b, a%b);	//mod + swap
}

int main(){
	int a, b;
	cin >> a >> b;

	//최대공약수
	int g = gcdRecursion(max(a, b), min(a, b));

	//최소공배수
	int l = a * b / g;

	cout << g << '\n' << l;
}
