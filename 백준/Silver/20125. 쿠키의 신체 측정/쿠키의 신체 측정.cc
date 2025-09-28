#include <iostream>
#include <vector>
#include <string>
using namespace std;

int dx[] = { -1,1,0,0,0 };
int dy[] = { 0,0,1,1,1 };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, num;
    int tx, ty;
    cin >> n;
    vector<string> map(n + 1);

    for (int i = 0; i < n; i++) {
        cin >> map[i];
    }

    bool check = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == '*') {
                tx = j;
                ty = i + 1;
                check = true;
                break;
            }
        }
        if (check) break;
    }

    cout << (ty + 1) << " " << (tx + 1) << '\n';
    
    int cx, cy;
    for (int i = 0; i < 5; i++) {
        num = 0;
        if (i < 3) {
            cx = tx;
            cy = ty;
        }
        else if (i == 3) {
            tx = cx;
            ty = cy;
            cx = tx - 1;
            cy = ty;
            num++;
        }
        else {
            cx = tx + 1;
            cy = ty;
            num++;
        }
        while (true) {
            cx += dx[i];
            cy += dy[i];
            if (cx > n - 1 || cx < 0 || cy < 0 || cy > n - 1) break;
            if (map[cy][cx] == '*') num++;
            else {
                break;
            }
        }
        cout << num << " ";
    }

    return 0;
}
