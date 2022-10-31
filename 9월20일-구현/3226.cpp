//3226_전화요금
#include <iostream>

using namespace std;

//시간이 위치한 범위 찾기
int findTime(int H){
	if (7 <= H && H < 19){
		return 1; //10원 지불
	}
	return 0; //5원 지불
}

//총 통화 요금을 구해 반환하는 함수
int findFee(int H, int M, int D){
	int endH, endM;
	int fee = 0;

	//통화 종료 시간 찾기
	if (M+D > 59){
		endH = H + 1;
		endM = M + D - 60;
	}
	else{
		endH = H;
		endM = M + D;
	}
	//시작 시간과 종료 시간의 위치(7-19시 사이인지, 그 밖인지) 찾기
	int s = findTime(H); //시작 시간의 위치
	int e = findTime(endH); //종료 시간의 위치
	if (s == 0 && e == 0){
		fee += 5 * D;
	}
	else if (s == 0 && e == 1){
		fee += 5 * (60 - M);
		fee += 10 * (endM);
	}
	else if (s == 1 && e == 1){
		fee += 10 * D;
	}
	else if (s == 1 && e == 0){
		fee += 10 * (60 - M);
		fee += 5 * (endM);
	}
	return fee;
}

int main(){
	int N, D;
	string s;
	int ans=0;

	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> s;
		int H = stoi(s.substr(0, 2));
		int M = stoi(s.substr(3, 5));
		cin >> D;
		ans += findFee(H, M, D);
	}
	cout << ans;
}
