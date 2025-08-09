#include <string>
#include <vector>
#include <algorithm> // sort 사용
#include <functional>  // greater 사용

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int park_rows = park.size();
    int park_cols = park[0].size();

    vector<vector<int>> prefix_sum(park_rows + 1, vector<int>(park_cols + 1, 0));
    for (int i = 0; i < park_rows; ++i) {
        for (int j = 0; j < park_cols; ++j) {
            int person_exists = (park[i][j] != "-1") ? 1 : 0;
            prefix_sum[i + 1][j + 1] = person_exists + prefix_sum[i][j + 1] + prefix_sum[i + 1][j] - prefix_sum[i][j];
        }
    }

    sort(mats.begin(), mats.end(), greater<int>());

    for (int k : mats) {
        if (k > park_rows || k > park_cols) {
            continue;
        }

        for (int r = 0; r <= park_rows - k; ++r) {
            for (int c = 0; c <= park_cols - k; ++c) {
                int r2 = r + k - 1;
                int c2 = c + k - 1;

                int sum_of_people = prefix_sum[r2 + 1][c2 + 1] - prefix_sum[r][c2 + 1] - prefix_sum[r2 + 1][c] + prefix_sum[r][c];

                if (sum_of_people == 0) {
                    return k;
                }
            }
        }
    }

    return -1;
}