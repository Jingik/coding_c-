#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct song {
    int index;
    int ct;
};

bool compare(const song& x, const song& y) {
    if (x.ct != y.ct) {
        return x.ct > y.ct;
    }
    return x.index < y.index;
}
bool compare2(const pair<string, int>& x, const pair<string, int>& y) {
    return x.second > y.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    unordered_map<string, vector<song>> genremap;
    unordered_map<string, int> playnum;

    for (int i = 0; i < genres.size(); i++) {
        playnum[genres[i]] += plays[i];
        genremap[genres[i]].push_back({i, plays[i]});
    }
    vector<pair<string, int>> order_play(playnum.begin(), playnum.end());
    sort(order_play.begin(), order_play.end(), compare2);
    vector<int> answer;

    for (const auto& [genre, _] : order_play) {
        auto& com = genremap[genre];
        sort(com.begin(), com.end(), compare);
        for (int i = 0; i < com.size() && i < 2; ++i) {
            answer.push_back(com[i].index);
        }
    }

    return answer;
}
