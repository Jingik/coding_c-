#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

vector<string> answer;
map<string, vector<pair<string, bool>>> graph;
int ticketCount;

bool dfs(string curr, vector<string>& route, int used) {
    route.push_back(curr);

    if (used == ticketCount) {
        answer = route;
        return true;
    }

    for (auto& [next, usedFlag] : graph[curr]) {
        if (!usedFlag) {
            usedFlag = true;
            if (dfs(next, route, used + 1)) return true;
            usedFlag = false;
        }
    }

    route.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    for (auto& ticket : tickets) {
        graph[ticket[0]].emplace_back(ticket[1], false);
    }

    for (auto& [key, vec] : graph) {
        sort(vec.begin(), vec.end());
    }

    vector<string> route;
    ticketCount = tickets.size();
    dfs("ICN", route, 0);
    return answer;
}
