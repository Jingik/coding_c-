#include <string>
#include <vector>
#include <map>
#include <unordered_set>
#include <sstream>

using namespace std;

vector<string> split(const string& str) {
    vector<string> result;
    istringstream ss(str);
    string buf;
    
    while (getline(ss, buf, ' ')) {
        result.push_back(buf);
    }
    
    return result;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    map<string, unordered_set<string>> reporters;
    map<string, int> report_count;
    
    for (const auto& id : id_list) {
        reporters[id] = unordered_set<string>();
        report_count[id] = 0;
    }
    
    for (const auto& r : report) {
        vector<string> cur = split(r);
        string reporter = cur[0];
        string reported = cur[1];
        reporters[reporter].insert(reported);
    }
    
    for (const auto& reporter : reporters) {
        for (const auto& reported : reporter.second) {
            report_count[reported]++;
        }
    }
    
    vector<string> banned;
    for (const auto& rc : report_count) {
        if (rc.second >= k) {
            banned.push_back(rc.first);
        }
    }
    
    for (int i = 0; i < id_list.size(); i++) {
        string user = id_list[i];
        for (const auto& banned_user : banned) {
            if (reporters[user].find(banned_user) != reporters[user].end()) {
                answer[i]++;
            }
        }
    }
    
    return answer;
}