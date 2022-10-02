//11053_가장 긴 증가하는 부분 수열
#include <iostream>

using namespace std;

int main()
{
    int N, maxLen;
    int A[1000], len[1000] = {0};

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++)
    {
        len[i] = 1;
        for (int j = 0; j < i; j++)
            if (A[j] < A[i] && len[i] < len[j] + 1)
                len[i] = len[j] + 1;
    }
    maxLen = len[0];
    for (int i = 0; i < N; i++)
        if (maxLen < len[i])
            maxLen = len[i];
    cout << maxLen;
}
