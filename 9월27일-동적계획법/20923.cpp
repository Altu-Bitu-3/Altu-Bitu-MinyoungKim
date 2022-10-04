#include <iostream>	//입출력 헤더
#include <deque>	//덱 헤더

using namespace std;	//std 라이브러리

// src의 합치는 카드 더미를 des의 카드 더미로 합치는 함수
void mergeCards(deque<int>& src, deque<int>& des)
{
    while (!src.empty())	//src가 비어있지 않다면
    {
        des.push_back(src.back()); // 상대방 덱을 뒤집어서(맨 뒤부터) 아래로 합치기
        src.pop_back();	//src에서 카드 삭제
    }
}

//게임 결과를 string으로 반환하는 함수
string playGame(int m, deque<int>& dodo, deque<int>& su)
{
    deque<int> do_gr; //그라운드에 있는 도도의 카드 더미
    deque<int> su_gr; // 그라운드에 있는 수연의 카드 더미
    bool flag = true; // true일 때는 도도의 차례, false 일 때는  수연의 차례
    while (m--)	//게임 진행횟수 m만큼 반복
    {
        if (flag)	//도도의 차례
        {
            do_gr.push_front(dodo.front()); // 덱에 있는 맨 위의 카드를 그라운드에 놓는다
            dodo.pop_front();	//도도의 덱에서 맨 위 카드 삭제한다
            if (dodo.empty()) {	//도도 덱의 카드 수가 0이 되면
                return "su";	//상대방이 즉시 승리
            }
        }
        else		//수연의 차례
        {
            su_gr.push_front(su.front()); /// 덱에 있는 맨 위의 카드를 그라운드에 놓는다
            su.pop_front();		//수연의 덱에서 맨 위 카드 삭제한다.
            if (su.empty()) {	//수연 덱의 카드 수가 0이 되면
                return "do"; 	//상대방이 즉시 승리
            }
        }
        flag = !flag; //순서 바꾸기
        //도도와 수연이가 종을 칠 수 있는지 검사
        //도도가 종을 쳤을 때 : 가장 위에 위치한 카드 숫자 5 존재
        if (!do_gr.empty() && do_gr.front() == 5 || !su_gr.empty() && su_gr.front() == 5) {
            mergeCards(su_gr, dodo);	//수연 그라운드의 카드 도도 덱으로 합치기
            mergeCards(do_gr, dodo);	//도도 그라운드의 카드 도도 덱으로 합치기
        }
        //수현이가 종을 쳤을 때 : 가장 위에 위치한 카드 숫자 합 5
        if (!do_gr.empty() && !su_gr.empty() && do_gr.front() + su_gr.front() == 5) {
            mergeCards(do_gr, su);	//도도 그라운드의 카드 수연 덱으로 합치기
            mergeCards(su_gr, su);	//수연 그라운드의 카드 수연 덱으로 합치기
        }
    }

    if (dodo.size() > su.size()) {	//게임 종료 후 도도 덱의 카드 수가 크면
        return "do";	//도도 승리
    }
    else if (dodo.size() < su.size()) {	//게임 종료 후 수연 덱의 카드 수가 크면
        return "su";	//수연 승리
    }
    return "dosu";	//비기면 dosu 반환
}
/*
 *[숫자 할리갈리 게임] : 구현, 시뮬레이션
 * 도도,수연이의 덱과 그라운드에 있는 도도,수연의 덱 총 4개의 덱을 관리해주면 됩니다
 * deque 라이브러리를 사용하면 카드 덱에서 일어나는 일들을 쉽게 구현할 수 있습니다
 * 문제에서 주어진 게임 진행 순서대로 구현하면 됩니다
 * 게임 순서와 종료 조건을 주의하셔야 합니다
 */
int main()	//메인 함수
{
    int n, m;	//도도, 수연이가 가지는 카드 개수와 게임 진행 횟수
    cin >> n >> m;	//입력
    deque<int> dodo;	//도도 덱 생성
    deque<int> su;		//수연 덱 생성
    for (int i = 0; i < n; i++)	//입력 위한 for문
    {
        int a, b;	//도도와 수연이가 가진 덱의 카드에 적힌 수 (아래~>위)
        cin >> a >> b;	//입력
        dodo.push_front(a);	//도도 덱에 삽입
        su.push_front(b);	//수연 덱에 삽입
    }
    cout << playGame(m, dodo, su);	//게임 결과를 출력
    return 0;	//프로그램 종료
}
