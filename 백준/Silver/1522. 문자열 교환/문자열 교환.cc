#include <iostream>
#include <string>
#include <climits>  

using namespace std;

int main() {
    string se;
    cin >> se;

    int a_count = 0; 
    for (char x : se) {
        if (x == 'a') {
            a_count++;
        }
    }

    string new_se = se + se; 

    int min_b_count = INT_MAX; 
    int current_b_count = 0;    

    for (int i = 0; i < a_count; i++) {
        if (new_se[i] == 'b') {
            current_b_count++;
        }
    }
    min_b_count = min(min_b_count, current_b_count);

    for (int i = 1; i < se.size(); i++) {
        if (new_se[i - 1] == 'b') current_b_count--;
        if (new_se[i + a_count - 1] == 'b') current_b_count++;
        min_b_count = min(min_b_count, current_b_count);
    }

    cout << min_b_count << endl;
    return 0;
}
