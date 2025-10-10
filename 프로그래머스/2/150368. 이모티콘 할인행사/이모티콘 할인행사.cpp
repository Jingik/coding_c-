#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int discount[] = {10, 20, 30, 40};

void dfs(int idx, int m, vector<int>& disc, vector<vector<int>>& users, vector<int>& emoticons, vector<int>& answer){
    if(idx == m){
        int cur_us = 0, cur_price = 0;
        for(auto us : users){
            int total = 0;
            for(int i = 0; i < emoticons.size(); i++){
                if(disc[i] >= us[0]){
                    total += (emoticons[i] * (100 - disc[i]) / 100);
                }
            }
            if(total >= us[1]) cur_us++;
            else cur_price += total;
        }

        if(cur_us > answer[0] || (cur_us == answer[0] && cur_price > answer[1])){
            answer = {cur_us, cur_price};
        }
        return;
    }
    for(auto x : discount){
        disc[idx] = x;
        dfs(idx + 1, m, disc, users, emoticons, answer);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer = {0, 0};
    vector<int> disc(emoticons.size(), 0);
    dfs(0, emoticons.size(), disc, users, emoticons, answer);
    return answer;
}