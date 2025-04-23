#include <vector>
#include <set>
#include <map>
using namespace std;

int dx[8] = {0,1,1,1,0,-1,-1,-1};
int dy[8] = {1,1,0,-1,-1,-1,0,1};

int solution(vector<int> arrows) {
    set<pair<int, int>> visitedNodes;
    set<pair<pair<int,int>, pair<int,int>>> visitedEdges;
    int x = 0, y = 0;
    int answer = 0;

    visitedNodes.insert({x, y});

    for (int dir : arrows) {

        for (int step = 0; step < 2; ++step) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            pair<int, int> from = {x, y};
            pair<int, int> to = {nx, ny};

            if (visitedNodes.count(to) && !visitedEdges.count({from, to})) {
                answer++;
            }

            visitedEdges.insert({from, to});
            visitedEdges.insert({to, from});
            visitedNodes.insert(to);

            x = nx;
            y = ny;
        }
    }

    return answer;
}
