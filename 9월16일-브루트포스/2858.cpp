#include <iostream>

using namespace std;

/*
방 사이즈가 l*w일 때,
갈색 타일 r=(l-2)(w-2)
갈색 타일+빨간색 타일 r+b=lw
*/

int main(){
	int red, brown;

	cin >> red >> brown;
	for (int i = 3; ; i++){
		for (int j = i; j >= 3; j--){
			int brownTmp = (i-2)*(j-2);
			int redTmp = i*j-brownTmp;
			if (redTmp == red && brownTmp == brown){
				cout << i << ' ' << j;
				return 0;
			}
		}
	}
	return 0;
}
