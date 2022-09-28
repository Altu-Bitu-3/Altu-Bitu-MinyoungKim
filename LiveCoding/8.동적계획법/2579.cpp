//LiveCoding
//2579_계단오르기
#include <iostream>
#define MAX(a, b) (a > b ? a : b)

using namespace std;

int n, st[302], dp[302];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> st[i];

    dp[1] = st[1];
    dp[2] = MAX(st[1] + st[2], st[2]);
    dp[3] = MAX(st[1] + st[3], st[2] + st[3]);

    for (int i = 4; i <= n; i++)
        dp[i] = MAX(dp[i - 3] + st[i - 1] + st[i], dp[i - 2] + st[i]);

    cout << dp[n];
}
