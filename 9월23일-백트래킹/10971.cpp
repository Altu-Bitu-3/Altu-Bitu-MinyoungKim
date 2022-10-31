//추가제출
//10971_외판원순회2
#include <iostream>	//c++ 입출력 헤더
#include <vector>	//vector 사용 위한 헤더

using namespace std;	//std 라이브러리 사용
const int INF = 1e8;	//비용 최댓값 상수로 지정

vector<bool> visited; //방문 여부 저장하는 배열
vector<vector<int>> matrix; //비용 저장하는 2차원 배열
int n, ans = INF; //최소 비용 저장 위해 미리 최댓값으로 초기화

//최소 비용 찾는 백트래킹 함수
//cnt:방문 도시 수, cur_city:현재도시위치, cost:현재까지 비용
void backtracking(int cnt, int cur_city, int cost) {
    if (cost >= ans) {	//현재 비용이 최소 비용이 아니라면 종료
        return;
    }
    if (cnt == n) { //종료 조건 : n개의 도시를 순회했음
        //출발 도시(0)로 다시 돌아올 수 있는지 확인
        if (matrix[cur_city][0] != 0) {	//출발 도시로 돌아갈 수 있다면
            ans = min(ans, cost + matrix[cur_city][0]);	//최소비용과, 현재까지 cost + n에서 0으로 이동 비용 중 더 작은 것을 ans로 갱신
        }
        return;
    }
    for (int i = 0; i < n; i++) { //cur_city에서 도시 i로 이동
        if (matrix[cur_city][i] && !visited[i]) { //길이 있고, 아직 방문하지 않은 도시라면
            visited[i] = true;	//방문 여부 true 바꾸고
            backtracking(cnt + 1, i, cost + matrix[cur_city][i]);	//다음 도시로 진행
            visited[i] = false;	//다음 연산 진행 시에는 다시 false로 초기화
        }
    }
}

/**
 * 백트래킹 풀이 (4ms)
 * 한 사이클을 만들면, 어느 도시에서 시작하든 값은 같으므로 0번 도시부터 시작하는 경우만 검사하면 된다.
 */

int main() {

    //입력
    cin >> n;	//도시 개수 n 입력 받기
    visited.assign(n, false);	//visited n만큼 false로 초기화
    matrix.assign(n, vector<int>(n, 0));	//matrix nxn 만큼 0으로 초기화
    for (int i = 0; i < n; i++) {	//각 도시간 이동 비용 입력받는
        for (int j = 0; j < n; j++) {	//이중 for문
            cin >> matrix[i][j];	//각 도시 간 이동 비용 입력
        }
    }

    //연산
    visited[0] = true;	//1번 도시 방문 여부 true로 만들고
    backtracking(1, 0, 0);	//백트래킹 함수 호출하여 연산 시작

    //출력
    cout << ans;	//backtracking에서 구한 최소 비용 출력
    return 0;	//프로그램 종료
}
