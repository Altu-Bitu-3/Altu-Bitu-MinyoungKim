//2840_행운의바퀴
#include <iostream>
#include <vector>

using namespace std;

int n;
//다른 자리
int checkDouble(vector<char> &wheel, char c, int cur){
	for (int i = 0; i < n; i++){
		if (i == cur)
			continue;
		if(wheel[i] == c)
			return 0; //중복 존재
	}
	return 1; //중복 없음
}

int main(){
	int k, cur=0;

	//입력과 벡터 초기화
	cin >> n >> k;
	vector<char> wheel(n, '?');
	//k번 입력 받으면서 연산
	for (int i = 0; i < k; i++){
		int mv;
		char c;
		cin >> mv >> c;
		cur = (cur + mv) % n;
		//그 자리에 c와 같은 문자가 있거나 ?가 있고,
		//다른 자리의 문자들과 중복되지 않는 경우에만 진행
		if ((wheel[cur] == '?' || wheel[cur] == c)
			&& checkDouble(wheel, c, cur)){
			wheel[cur] = c;
		}
		else{
			cout << '!';
			return 0;
		}
	}
	//출력
	int cnt = 0;
	for (int i = cur; cnt < n; i = (i+n-1)%n, cnt++){
		cout << wheel[i];
	}
	return 0;
}
