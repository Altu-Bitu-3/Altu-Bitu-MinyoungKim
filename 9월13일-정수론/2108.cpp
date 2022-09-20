//추가제출
#include<iostream>	//c++입출력 헤더
#include<vector>	//vector 헤더
#include<algorithm>	//sort함수를 사용하기 위한 algorithm 헤더
#include<cmath>		//올림(ceil), 반올림(round), 내림(floor) 연산을 이용하기 위한 헤더

/*
* 1. 산술 평균: 입력된 숫자들의 합을 숫자 개수로 나누기
* 2. 중앙값: 입력값 벡터 정렬 후 (n/2)번째 숫자 구하기. n이 홀수이므로 중앙값은 항상 (n/2)번째 인덱스
* 3. 최빈값: 각 숫자별로 빈도를 저장, 최대 빈도 구하기. 이후 findMode()함수 이용하여 최빈값 구하기
* 4. 범위: 입력받은 벡터 정렬 후 최댓값 - 최솟값
*/

using namespace std;	//std 라이브러리 사용

const int SCOPE = 4000; //입력되는 정수의 최대값

int findMode(int max_cnt, vector<int>& frequency) {
	//정렬된 벡터에서 최빈값을 찾아 반환하는 함수
	//최빈값이 여러 개라면 두번째로 작은 값을 반환
	int cnt = 0; //최빈값에 해당하는 수의 개수 저장하는 변수
	int mode; //최빈값 저장
	for (int i = 0; i < 2 * SCOPE + 1; i++) { //v[i]+SCOPE를 인덱스를 사용했으므로 i=2*SCOPE+1까지 반복
		if (max_cnt == frequency[i]) { //최빈값에 해당하는 수를 찾으면
			mode = i; //최빈값 갱신
			cnt++; //최빈값에 해당하는 수의 개수 카운트
			if (cnt == 2) { //세번째 최빈값부터는
				break; //mode 값을 갱신하지 않기 위해 반복문 종료
			}
		}
	}
	return mode - SCOPE; //인덱스는 입력된 숫자 + 4000 이므로 4000을 빼준 값을 반환
}

int main() {	//메인함수
	int n;		//입력받을 수의 개수 n
	double sum = 0.0; //입력된 숫자의 합
	int max_freq = 0; //최빈값의 빈도수

	cin >> n; //수의 개수 n 입력
	vector<int> v(n); //입력된 숫자를 저장할 벡터
	vector<int> frequency(2 * SCOPE + 1, 0); //각 숫자들(-4000~4000)의 빈도를 저장할 벡터

	for (int i = 0; i < n; i++) { //n개의 수를 입력받기 위한 for문
		cin >> v[i]; //n개의 수를 벡터에 저장
		sum += v[i]; //입력된 수들의 합 구하기

		int cur_freq = ++frequency[v[i] + SCOPE]; //-4000~4000까지의 각 수의 현 빈도수 저장할 변수
		//인덱스 값이 음수가 되지 않도록 하기 위해 각 수에 SCOPE를 더한 값을 인덱스로 사용
		max_freq = max(max_freq, cur_freq); //최대 빈도수 갱신
	} //for문이 끝나면 입력된 수들의 합, 입력된 수들 중 최대 빈도수를 갖는 수를 알 수 있음
	sort(v.begin(), v.end()); //입력된 수들을 오름차순으로 정렬

	//출력
	cout << (int)round(sum / n) << '\n';			//산술평균: -0 안나오게 유의
	cout << v[n / 2] << '\n';						//중앙값 : 오름차순 정렬했으므로 중앙 인덱스의 값
	cout << findMode(max_freq, frequency) << '\n';	//최빈값 : 최빈값을 찾아 반환하는 findMode 함수 이용
	cout << v[n - 1] - v[0] << '\n';				//범위 : 오름차순 정렬했으므로 마지막 수와 처음 수의 차이

	return 0; //종료
}
