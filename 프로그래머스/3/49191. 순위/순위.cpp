#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    vector<vector<bool>> graph(n + 1, vector<bool>(n + 1, false));

    // 1. 경기 결과 기록
    for (auto& r : results) {
        int win = r[0];
        int lose = r[1];
        graph[win][lose] = true; // win이 lose를 이김
    }

    // 2. 플로이드-워셜 알고리즘으로 이김 관계 전파
    for (int k = 1; k <= n; ++k) {         // 경유 노드
        for (int i = 1; i <= n; ++i) {     // 출발 노드
            for (int j = 1; j <= n; ++j) { // 도착 노드
                if (graph[i][k] && graph[k][j]) {
                    graph[i][j] = true;
                }
            }
        }
    }

    // 3. 정확한 순위를 알 수 있는 선수 수 세기
    int answer = 0;
    for (int i = 1; i <= n; ++i) {
        int count = 0;
        for (int j = 1; j <= n; ++j) {
            if (i == j) continue;
            if (graph[i][j] || graph[j][i]) count++; // i가 j를 이기거나 j가 i를 이긴 경우
        }
        if (count == n - 1) answer++; // 모든 선수와의 승패가 명확하면 순위 알 수 있음
    }

    return answer;
}
