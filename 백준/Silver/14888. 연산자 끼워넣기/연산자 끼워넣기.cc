#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> 

using namespace std;

int N;
vector<int> numbers; 
int operators[4];     
long long max_num = LLONG_MIN; 
long long min_num = LLONG_MAX; 


void backtrack(int idx, long long current) {
    if (idx == N) {
        max_num = max(max_num, current);
        min_num = min(min_num, current);
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (operators[i] > 0) {
            operators[i]--;

            if (i == 0) 
                backtrack(idx + 1, current + numbers[idx]);
            else if (i == 1)
                backtrack(idx + 1, current - numbers[idx]);
            else if (i == 2)
                backtrack(idx + 1, current * numbers[idx]);
            else if (i == 3) { 
                if (current < 0) {
                    backtrack(idx + 1, -((-current) / numbers[idx]));
                }
                else {
                    backtrack(idx + 1, current / numbers[idx]);
                }
            }

            operators[i]++;
        }
    }
}

int main() {
    cin >> N;
    numbers.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    for (int i = 0; i < 4; i++) {
        cin >> operators[i];
    }

    backtrack(1, numbers[0]);

    cout << max_num << endl;
    cout << min_num << endl;

    return 0;
}
