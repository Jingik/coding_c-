#include <string>
#include <vector>
using namespace std;

int solution(int n, int w, int num) {
    int layer = (num - 1) / w;
    int col;
    if (layer % 2 == 0) col = (num - 1) % w;
    else col = w - 1 - ((num - 1) % w);

    int count = 1;
    for (int upper = layer + 1; ; upper++) {
        int start = upper * w + 1;
        if (start > n) break;

        int upperNum;
        if (upper % 2 == 0) upperNum = upper * w + col + 1;
        else upperNum = (upper + 1) * w - col;

        if (upperNum <= n) count++;
        else break;
    }

    return count;
}
