#include <vector>
#include <iostream>

#define mod 1000000007

using namespace std;

// how many ways you can tile a board of length 5 with red

int main()
{
    // first denotes the size, second denotes the different colors
    vector<pair<int, int>> tiles = {{1, 2}, {2, 1}, {4, 1}};
    // sort(tiles.begin(), tiles.end());

    int sz = 25;

    vector<long long int> a(sz + 1);
    a[0] = 1;
    long long int ans = 0;

    for (int i = 1; i <= sz; i++)
    {
        ans = 0;

        for (auto p : tiles)
        {
            if (i - p.first < 0)
                break;

            ans += p.second * a[i - p.first];
        }

        a[i] = ans;
    }

    cout << a[sz] << endl;

    return 0;
}