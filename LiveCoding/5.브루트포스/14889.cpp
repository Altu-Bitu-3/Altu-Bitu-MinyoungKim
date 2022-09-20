//LiveCoding
//14889_스타트와링크

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_DIFF = 1000;

int calcDiff(int n, vector<bool> &is_teamA){
	//전달받은 임시 배열을 이용해 팀을 나누고, 경험치를 계산해 차이 리턴

	vector<int> teamA; //A팀에 속한 사람의 인덱스
	vector<int> teamB; //B팀에 속한 사람의 인덱스

	for (int i = 0; i < n; i++){
		if (is_teamA[i])
			teamA.push_back(i);
		else
			teamB.push_back(i);
	}
	return 0;
}

int findMinDiff(int n){
	//1.팀 나누기
	//2.각 팀마다 능력치 합 구하기
	//3.능력치 차이의 최소 기록하기

	//조합을 구하기 위해 임시 배열 만들기
	vector<bool> is_teamA(n, true);
	for (int i = 0; i < n/2; i++)
		is_teamA[i] = false;

	int answer = MAX_DIFF;

	do{
		//팀이 결정된 상황
		//팀 간의 능력치 차이를 구하고, 최솟값을 기록
		answer = min(answer, calcDiff(n, is_teamA));
	} while (next_permutation(is_teamA.begin(), is_teamA.end()));

	return answer;
}

int main(){
	int n;

	//입력
	cin >> n;
	vector<vector<int>> power(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> power[i][j];
		}
	}

	cout << findMinDiff(n);
	return 0;
}
