//추가제출
#include<iostream> //c++ 입출력 헤더

using namespace std; //std 라이브러리 사용


int gcd(int a, int b) { //최대공약수를 구하는 함수(유클리드 호제법)
	if (b == 0) { //재귀 종료 조건
		return a; //b=0일 때 a가 a와 b의 최대공약수
	}
	return gcd(b, a % b); //재귀 호출 부분 : 첫번째 매개변수 > 두번째 매개변수
}

int main() { //메인함수
	int n, m; //직사각형 가로길이, 세로길이
	//입력
	cin >> n >> m; //가로길이와 세로길이 입력
	//출력
	cout << n + m - gcd(n, m); //대각선이 그려져 있는 타일의 개수 출력
	//그림으로 확인했을 때, 최대공약수-1 개의 꼭짓점을 지남
	//최대공약수가 1일 때, n+m-1
	//최대공약수가 2이상일 때, n+m-gcd(n,m)
	//이므로 일반적으로 n+m-gcd(n,m)으로 나타낼 수 있음
}
