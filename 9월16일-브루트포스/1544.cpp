//추가 제출
#include <iostream>		//c++ 입출력 헤더
#include <set>			//set 사용 위한 헤더

using namespace std;	//std 라이브러리 사용

bool isCycle(set<string> &s, string str){	//같은 단어가 있는지 확인하는 함수
	int cnt = str.length();	//str의 길이를 저장

	while (cnt--){	//str의 길이만큼 반복
		/*
		set의 멤버 함수 find(k)
		원소 k가 존재하지 않으면 s.end() 반환
		*/
		if (s.find(str) != s.end()){	//셋에 str이 존재하면
			return true;				//true 반환
		}
		str = str + str[0];	//첫번째 글자를 뒤에 붙이고
		str.erase(0,1);		//첫번째 글자를 지움
	}
	return false;
}

int main(){
	int n;				//입력받을 단어의 개수 n
	string str;
	set<string> words;	//단어 입력받을 셋

	//입력
	cin >> n;	//입력받을 단어 개수 입력받기
	while (n--){	//n개의 단어 입력받아 확인할 반복문
		cin >> str;	//단어 입력

		if (!isCycle(words, str)){	//같은 단어 없을 때만
			words.insert(str);		//셋에 str 추가
		}
	}

	//출력
	cout << words.size();	//words 셋에 있는 단어들은 모두 서로 다른 단어
}
