#include <vector>
#include <iostream>
#define mod 1000000007

using namespace std;

int dx[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

int n, m;
vector<vector<bool>> v;

void dfs(int r, int c)
{
    int dr, dc;
    for(auto d: dx)
    {
        dr = r + d[0];
        dc = c + d[1];
        if(dr < n && dc < m && dr >= 0 && dc >= 0 && !v[dr][dc])
        {
            v[dr][dc] = 1;
            dfs(dr, dc);
        }
    }
}

int main()
{

    cin >> n;
    cin >> m;

    vector<vector<char>> g(n, vector<char>(m));
    v = vector<vector<bool>>(n, vector<bool>(m, false));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> g[i][j];
            if(g[i][j] == '#') v[i][j] = true;
        }
    }

    int ans = 0;

    for(int r = 0; r < n; r++)
    {
        for(int c = 0; c < m; c++)
        {
            if(v[r][c]) continue;
            v[r][c] = 1;
            dfs(r, c);
            ans += 1;
        }
    }

    cout << ans << endl;


    return 0;
}   


