#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i*i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int solution(string numbers) {
    set<int> result;
    sort(numbers.begin(), numbers.end());

    do {
        for (int len = 1; len <= numbers.size(); len++) {
            int num = stoi(numbers.substr(0, len));
            result.insert(num);
        }
    } while (next_permutation(numbers.begin(), numbers.end()));

    int answer = 0;
    for (int n : result) {
        if (isPrime(n)) answer++;
    }
    return answer;
}
