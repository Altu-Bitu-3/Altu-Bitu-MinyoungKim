//LiveCoding
//10870_피보나치수
#include <iostream>
#include <vector>

using namespace std;

vector<int> dp(21);

int f(int n){
	if (n <= 1)
		return n;
	if (dp[n])
		return dp[n];
	return dp[n] = f(n-1) + f(n-2);
}
int main(){
	int n;

	cin >> n;
	cout << f(n);
}
