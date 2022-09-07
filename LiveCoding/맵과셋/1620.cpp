#include <iostream>
#include <map>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	string input;
	map<string, int> pocket_name; //�̸��� key, ��ȣ�� value
	map<int, string> pocket_num;  //��ȣ�� key, �̸��� value

	//�Է�
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> input;
		pocket_name[input] = i;
		pocket_num[i] = input;
	}
	while (m--){
		cin >> input;
		if (isdigit(input[0])) {
			//stoi : string to int
			cout << pocket_num[stoi(input)] << '\n';
		} else {
			cout << pocket_name[input] << '\n';
		}
	}

	return 0;
}
