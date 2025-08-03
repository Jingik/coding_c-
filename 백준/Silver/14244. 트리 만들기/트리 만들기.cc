#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for(int i=0; i<N-M; i++)
    {
        cout << i<< " " << i+1 << "\n";
    }

    for(int i=N-M; i<N-1; i++)
    {
        cout << N-M << " " <<i+1 <<"\n";
    }

    return 0;
}