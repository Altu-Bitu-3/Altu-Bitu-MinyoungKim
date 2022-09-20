//LiveCoding
//13458_시험감독

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
	int N, a;
	vector<int> A;
	int B, C;

	//입력
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> a;
		A.push_back(a);
	}
	long long cnt = N; //감독관 한 명씩은 필요
	cin >> B >> C;
	//감독관 수 세기
	for (int i = 0; i < N; i++){
		A[i] -= B;
		if (A[i] <= 0)
			continue;
		cnt += (int)ceil((float)A[i] / (float)C);
	}
	//출력
	cout << cnt;
}
