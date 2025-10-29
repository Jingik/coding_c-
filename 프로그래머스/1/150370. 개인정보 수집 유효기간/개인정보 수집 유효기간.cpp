#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

vector<int> split_date(string str){
    vector<int> result;
    string strbuf;
    istringstream ss(str);

    while(getline(ss, strbuf, '.')){
        result.push_back(stoi(strbuf));
    }
    return result;
}

vector<string> split(string str){
    vector<string> result;
    string strbuf;
    istringstream ss(str);

    while(getline(ss, strbuf, ' ')){
        result.push_back(strbuf);
    }
    return result;
}


vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    vector<int> to_date = split_date(today);
    int to_day = (to_date[0] * 12 * 28) + (to_date[1] * 28) + to_date[2];

    unordered_map<string, int> to_terms;
    vector<int> to_privacies;
    vector<string> to_privacies_rank; 
    
    for(auto& x : privacies){
        vector<string> cur = split(x);
        to_privacies_rank.push_back(cur[1]);
        vector<int> to_cur = split_date(cur[0]);
        int cur2 = (to_cur[0] * 12 * 28) + (to_cur[1] * 28) + to_cur[2];
        to_privacies.push_back(cur2);
    }

    for(auto& x : terms){
        vector<string> cur = split(x);
        to_terms[cur[0]] = (stoi(cur[1]) * 28);
    }

    for(int i = 0; i < privacies.size(); i++){
        if(to_privacies[i] + to_terms[to_privacies_rank[i]] <= to_day){
            answer.push_back(i);
        }
    }

    for(auto& x : answer) x += 1;
    return answer;
}