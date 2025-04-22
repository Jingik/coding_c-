#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    vector<int> st;
    for (int i = 0; i < arr.size(); i++) {
        if (!st.empty()) {
            if (st.back() != arr[i]) {
                st.push_back(arr[i]);
            }
        }
        else {
            st.push_back(arr[i]);
        }
    }

    return st;
}