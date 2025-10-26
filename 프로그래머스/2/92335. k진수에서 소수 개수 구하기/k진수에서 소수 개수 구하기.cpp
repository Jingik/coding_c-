#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(long long num) {
    if (num <= 1) return false;
    for (long long i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

string toBaseK(int n, int k) {
    string result = "";
    while (n > 0) {
        result = to_string(n % k) + result;
        n /= k;
    }
    return result.empty() ? "0" : result;
}

int solution(int n, int k) {
    int answer = 0;
    string k_base = toBaseK(n, k);
    string current = "";
    for (char c : k_base) {
        if (c == '0') {
            if (!current.empty()) {
                long long num = stoll(current);
                if (isPrime(num)) answer++;
                current = "";
            }
        } else {
            current += c;
        }
    }
    if (!current.empty()) {
        long long num = stoll(current);
        if (isPrime(num)) answer++;
    }
    return answer;
}