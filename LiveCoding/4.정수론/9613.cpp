//LiveCoding
//9613_GCD��
#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b){
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

long long gcdSum(int n, vector<int> &v){
	//�ִ� 100���� ���� �Է� ���� -> comb(100, 2)=4,950
	//�ִ� �Է� ���� ���� 1,000,000 -> gcd�� �ִ��� 1,000,000
	//sum <= 4,950,000,000
	long long sum = 0;

	for (int i = 0; i < n; i++)
		for (int j = i+1; j < n; j++)
			sum += gcd(max(v[i], v[j]), min(v[i], v[j]));

	return sum;
}

int main(){
	int t;
	cin >> t;

	while (t--){
		int n;
		cin >> n;
		vector<int> arr(n, 0);
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		cout << gcdSum(n, arr) << '\n';
	}
}
