#include <vector>
#include <iostream>
#define mod 1000000007

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n, 0));
    char x;



    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> x;

            if(x == '.')
            {
                if(i == 0 && j == 0)
                {
                    v[i][j] = 1;
                    continue;
                }
                
                if(j > 0)
                {
                    v[i][j] += v[i][j - 1];
                    v[i][j] %= mod;
                }

                if(i > 0)
                {
                    v[i][j] += v[i - 1][j];
                    v[i][j] %= mod;
                }

            }
            else
                v[i][j] = 0;
        }
    }

    cout << v[n - 1][n - 1] << "\n";
    

    return 0;
}