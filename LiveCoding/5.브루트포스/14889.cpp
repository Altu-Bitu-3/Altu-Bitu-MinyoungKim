//LiveCoding
//14889_��ŸƮ�͸�ũ

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_DIFF = 1000;

int calcDiff(int n, vector<bool> &is_teamA){
	//���޹��� �ӽ� �迭�� �̿��� ���� ������, ����ġ�� ����� ���� ����

	vector<int> teamA; //A���� ���� ����� �ε���
	vector<int> teamB; //B���� ���� ����� �ε���

	for (int i = 0; i < n; i++){
		if (is_teamA[i])
			teamA.push_back(i);
		else
			teamB.push_back(i);
	}
	return 0;
}

int findMinDiff(int n){
	//1.�� ������
	//2.�� ������ �ɷ�ġ �� ���ϱ�
	//3.�ɷ�ġ ������ �ּ� ����ϱ�

	//������ ���ϱ� ���� �ӽ� �迭 �����
	vector<bool> is_teamA(n, true);
	for (int i = 0; i < n/2; i++)
		is_teamA[i] = false;

	int answer = MAX_DIFF;

	do{
		//���� ������ ��Ȳ
		//�� ���� �ɷ�ġ ���̸� ���ϰ�, �ּڰ��� ���
		answer = min(answer, calcDiff(n, is_teamA));
	} while (next_permutation(is_teamA.begin(), is_teamA.end()));

	return answer;
}

int main(){
	int n;

	//�Է�
	cin >> n;
	vector<vector<int>> power(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> power[i][j];
		}
	}

	cout << findMinDiff(n);
	return 0;
}
