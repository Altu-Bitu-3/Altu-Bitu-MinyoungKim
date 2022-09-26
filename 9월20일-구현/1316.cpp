//1316_그룹단어체커
#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> alpha(123); //'z'의 아스키코드가 122. 알파벳을 그대로 인덱스로 쓰기 위해 123개 벡터 할당
	int n;
	int ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++){
		int flag = 1;
		fill(alpha.begin(), alpha.end(), 0); //0으로 초기화
		string word;
		cin >> word;
		for (int j = 0; j < word.length(); j++){
			while (j+1 < word.length() && word[j] = word[j+1])
				j++;
			if (alpha[word[j]]!= 0){ //그룹 단어 아님
				flag = 0;
				break;
			}
			else
				alpha[word[j]]++;
		}
		if (flag)
			ans++;
	}
}
