#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <unordered_map>
using namespace std;

vector<string> split(const string& str) {
    vector<string> result;
    istringstream ss(str);
    string str_buf;
    while (getline(ss, str_buf, ' ')) {
        result.push_back(str_buf);
    }
    return result;
}

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    unordered_map<string, int> gift_index;
    unordered_map<string, unordered_map<string, int>> gift_count;
    unordered_map<string, int> next_month;

    for (const auto& friend_name : friends) {
        next_month[friend_name] = 0;
        gift_index[friend_name] = 0;
    }

    for (const auto& gift : gifts) {
        vector<string> names = split(gift);
        string giver = names[0], receiver = names[1];
        gift_count[giver][receiver]++;
        gift_index[giver]++;
        gift_index[receiver]--;
    }

    for (int i = 0; i < friends.size(); i++) {
        for (int j = i + 1; j < friends.size(); j++) {
            string a = friends[i], b = friends[j];
            int a_to_b = gift_count[a][b];
            int b_to_a = gift_count[b][a]; 

            if (a_to_b > b_to_a) {
                next_month[a]++;
            } else if (a_to_b < b_to_a) {
                next_month[b]++;
            } else {
                if (gift_index[a] > gift_index[b]) {
                    next_month[a]++;
                } else if (gift_index[a] < gift_index[b]) {
                    next_month[b]++;
                }
            }
        }
    }

    for (const auto& value : next_month) {
        answer = max(answer, value.second);
    }

    return answer;
}