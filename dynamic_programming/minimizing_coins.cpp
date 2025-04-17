#include <vector>
#include <iostream>
#define mod 1000000007

using namespace std;

int main()
{
    int n, t;
    cin >> n;
    cin >> t;

    vector<int> coins(n);

    for (int i = 0; i < n; i++)
        cin >> coins[i];

    vector<int> minc(t + 1, -1);

    minc[0] = 0;

    for (auto c : coins)
    {
        for (int i = 0; i + c <= t; i++)
        {
            if (minc[i] == -1)
                continue;

            if (minc[i + c] == -1)
                minc[i + c] = minc[i] + 1;
            else
                minc[i + c] = min(minc[i + c], minc[i] + 1);
        }
    }

    cout << minc[t] << endl;

    return 0;
}