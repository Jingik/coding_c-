#include <iostream>
using namespace std;

int N, M;
int path[10];
bool visited[10]; // 방문 체크 배열

void func(int now) {
    if (now == M) {
        for (int i = 0; i < M; i++) {
            cout << path[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (visited[i]) continue; // 이미 방문한 경우 건너뛰기

        visited[i] = true;    // 방문 체크
        path[now] = i;        // 경로에 현재 숫자 저장
        func(now + 1);        // 다음 단계 진행
        visited[i] = false;   // 백트래킹
    }
}

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 향상
    cin.tie(NULL);               // 입출력 동기화 해제

    cin >> N >> M;
    func(0);
    return 0;
}
