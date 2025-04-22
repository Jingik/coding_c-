#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Song {
    int index;
    int plays;
};

bool compareSongs(const Song& a, const Song& b) {
    if (a.plays != b.plays) return a.plays > b.plays;
    return a.index < b.index;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    unordered_map<string, vector<Song>> genreMap;
    unordered_map<string, int> totalPlays;

    for (int i = 0; i < genres.size(); ++i) {
        genreMap[genres[i]].push_back({ i, plays[i] });
        totalPlays[genres[i]] += plays[i];
    }

    vector<pair<string, int>> genreOrder(totalPlays.begin(), totalPlays.end());
    sort(genreOrder.begin(), genreOrder.end(),
        [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second > b.second;
    });

    vector<int> answer;

    for (const auto& [genre, _] : genreOrder) {
        auto& songs = genreMap[genre];
        sort(songs.begin(), songs.end(), compareSongs);

        for (int i = 0; i < songs.size() && i < 2; ++i) {
            answer.push_back(songs[i].index);
        }
    }

    return answer;
}
