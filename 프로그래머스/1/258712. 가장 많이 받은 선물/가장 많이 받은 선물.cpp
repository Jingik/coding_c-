#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> split(const string& words){
    vector<string> result;
    string buf;
    istringstream ss(words);
    
    while(getline(ss, buf, ' ')){
        result.push_back(buf);
    }
    return result;
}

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    unordered_map<string, int> gift_score;
    unordered_map<string, unordered_map<string, int>> gift_index;
    unordered_map<string, int> next;

    for(const auto& fr : friends){
        gift_score[fr] = 0;
        next[fr] = 0;
    }
    
    vector<string> cur;
    for(const auto& gift : gifts){
        cur = split(gift);
        gift_score[cur[0]]++;
        gift_score[cur[1]]--;
        gift_index[cur[0]][cur[1]]++;
    }
    
    for(int i = 0; i < friends.size(); i++){
        for(int j = i; j < friends.size(); j++){
            int a_b = gift_index[friends[i]][friends[j]];
            int b_a = gift_index[friends[j]][friends[i]];

            if(a_b > b_a){
                next[friends[i]]++;
            }
            else if(a_b < b_a){
                next[friends[j]]++;
            }
            else{
                if(gift_score[friends[i]] > gift_score[friends[j]]){
                    next[friends[i]]++;
                }
                else if(gift_score[friends[i]] < gift_score[friends[j]]){
                    next[friends[j]]++;
                }
                continue;
            }
        }
    }
    
    for(int i = 0; i < friends.size(); i++){
        answer = max(answer, next[friends[i]]);
    }

    return answer;
}