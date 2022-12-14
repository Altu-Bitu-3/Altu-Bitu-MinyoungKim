//LiveCoding
#include <iostream>
#include <set>

using namespace std;

int main(){
	int n, input;
	set<int> s;

	//입력
	cin >> n;
	while (n--){
		cin>>input;
		s.insert(input); //셋에 삽입
	}
	//set<int>::iterator iter;
	//auto: 초기화 값에 따라 데이터 타입 자동으로 정해줌
	for (auto iter = s.begin(); iter != s.end(); iter++){
		cout << *iter << ' ';
	}
	return 0;
}
