#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    vector<string> nums;
    for (auto n : numbers) {
        nums.push_back(to_string(n));
    }

    sort(nums.begin(), nums.end(), compare);

    if (nums[0] == "0") return "0";

    string answer = "";
    for (auto s : nums) {
        answer += s;
    }

    return answer;
}
