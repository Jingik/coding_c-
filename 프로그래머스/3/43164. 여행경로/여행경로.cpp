#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

vector<string> answer;
map<string, vector<pair<string, bool>>> graph;
int ticketCount;

bool dfs(string cur, vector<string>& route, int count){
    route.push_back(cur);

    if(count == ticketCount){
        answer = route;
        return true;
    }

    for(auto& [value, visit] : graph[cur]){
        if(!visit){
            visit = true;
            if(dfs(value, route, count + 1)) return true;
            visit = false;
        }
    }

    route.pop_back();
    return false;
}


vector<string> solution(vector<vector<string>> tickets) {
    for(auto& val : tickets){
        graph[val[0]].emplace_back(val[1], false);
    }
    
    for(auto& [key,vec] : graph){
        sort(vec.begin(), vec.end());
    }
    
    ticketCount = tickets.size();
    dfs("ICN", answer, 0);
    return answer;
}
