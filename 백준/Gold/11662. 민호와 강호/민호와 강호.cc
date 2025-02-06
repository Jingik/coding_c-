#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double getDistance(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    double Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;
    cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy >> Dx >> Dy;

    double left = 0.0, right = 1.0;
    double minDistance = 1e18; 

    while (right - left > 1e-9) { 
        double m1 = (2 * left + right) / 3;
        double m2 = (left + 2 * right) / 3;

        // 현재 비율로 두 점의 위치 계산
        double minho_x1 = Ax + m1 * (Bx - Ax);
        double minho_y1 = Ay + m1 * (By - Ay);
        double minho_x2 = Ax + m2 * (Bx - Ax);
        double minho_y2 = Ay + m2 * (By - Ay);

        double kangho_x1 = Cx + m1 * (Dx - Cx);
        double kangho_y1 = Cy + m1 * (Dy - Cy);
        double kangho_x2 = Cx + m2 * (Dx - Cx);
        double kangho_y2 = Cy + m2 * (Dy - Cy);

        double d1 = getDistance(minho_x1, minho_y1, kangho_x1, kangho_y1);
        double d2 = getDistance(minho_x2, minho_y2, kangho_x2, kangho_y2);

        minDistance = min(minDistance, min(d1, d2));

        if (d1 < d2) {
            right = m2;
        }
        else {
            left = m1;
        }
    }

    cout << fixed << setprecision(10) << minDistance << '\n';

    return 0;
}
