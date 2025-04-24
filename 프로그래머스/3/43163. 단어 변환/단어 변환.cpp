#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool check(string& x, string& y){
    int diff = 0;
    for(int i = 0; i < x.size(); i++){
        if(x[i] != y[i]) diff++;
        if(diff > 1) return false;
    }
    return true;
}


int solution(string begin, string target, vector<string> words) {
    if(find(words.begin(), words.end(), target) == words.end()) return 0;
    
    int answer = 0;
    vector<bool> visited(words.size(), false);
    queue<pair<string, int>> que;
    que.push({begin, 0});
    
    while(!que.empty()){
        auto[cur, depth]  = que.front(); que.pop();
        
        if(cur == target) return depth;
        
        for(int i = 0; i < words.size(); i++){
            if(!visited[i] && check(cur, words[i])){
                visited[i] = true;
                que.push({words[i], depth + 1});
            }
        }
    }
    
    
    return answer;
}