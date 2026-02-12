#include <iostream>

using namespace std;

bool IsPrime(long long num) 
{
    if (num <= 1) 
        return false;

    if (num == 2 || num == 3) 
        return true;

    if (num % 2 == 0 || num % 3 == 0)
        return false;

    for (long long i = 5; i * i <= num; i += 6) 
    {
        if (num % i == 0 || num % (i + 2) == 0) 
            return false;
    }

    return true;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N;

    while (true)
    {
        int count = 0;
        cin >> N;

        if (N == 0)
            break;

        for (int i = N + 1; i <= 2 * N; ++i)
        {
            if (IsPrime(i))
                count++;
        }
        cout << count << '\n';
    }
}