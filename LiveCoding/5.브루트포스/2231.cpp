//LiveCoding
//2231_분해합

/*
<<연산 횟수 계산하기>>
input 범위 1 <= n <= 1,000,000 이므로,
1부터 1,000,000까지 분해합을 모두 계산하더라도
7 * 1,000,000 회의 연산을 넘을 수 없으므로 브루트포스 사용 가능
*/

#include <iostream>

using namespace std;

//1부터 n까지 분해합 구해보면서, 가장 작은 생성자를 찾아 리턴하는 함수
int findConstructor(int n){
	int sum;

	for (int i = 1; i < n; i++){
		//반복문 내에서 i를 변경하지 않기 위해 임시 변수 사용
		int temp = i;
		sum = i;

		//각 자리 수 더하기
		while (temp){
			sum += temp % 10;
			temp /= 10;
		}
		//i의 분해합이 n과 같으면 i는 n의 생성자
		//1부터 시작하여 탐색하므로 가장 작은 생성자 리턴
		if (sum == n)
			return i;
	}
	//생성자가 없는 경우
	return 0;
}

int main(){
	int n;

	//입력
	cin >> n;
	cout << findConstructor(n);
	return 0;
}
