#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

int toMinutes(const string& time) {
    int h = (time[0] - '0') * 10 + (time[1] - '0');
    int m = (time[3] - '0') * 10 + (time[4] - '0');
    return h * 60 + m;
}

int calcFee(int totalMin, const vector<int>& fees) {
    int baseMin = fees[0], baseFee = fees[1];
    int unitMin = fees[2], unitFee = fees[3];
    if (totalMin <= baseMin) return baseFee;
    int extra = totalMin - baseMin;
    int units = (extra + unitMin - 1) / unitMin;
    return baseFee + units * unitFee;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    const int DAY_END = 23 * 60 + 59;
    map<string, pair<int, int>> carInfo;

    for (const string& rec : records) {
        stringstream ss(rec);
        string time, car, type;
        ss >> time >> car >> type;
        int minutes = toMinutes(time);
        if (type == "IN") {
            carInfo[car].first = minutes;
        } else {
            int inTime = carInfo[car].first;
            carInfo[car].second += minutes - inTime;
            carInfo[car].first = -1;
        }
    }

    for (auto& p : carInfo) {
        if (p.second.first != -1) {
            p.second.second += DAY_END - p.second.first;
        }
    }

    vector<int> answer;
    for (const auto& p : carInfo) {
        answer.push_back(calcFee(p.second.second, fees));
    }
    return answer;
}