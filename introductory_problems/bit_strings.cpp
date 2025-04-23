#include <vector>
#include <iostream>
#define mod 1000000007

using namespace std;

int main()
{

    int n;
    cin >> n;

    long long res = 1;
    long long a = 2;

    while (n > 0)
    {
        if (n & 1)
            res = res * a % mod;

        a = a * a % mod;
        n >>= 1;
    }

    cout << res << endl;

    return 0;
}
