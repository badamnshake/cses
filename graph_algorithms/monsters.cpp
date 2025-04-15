#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <climits>
#define mod 1000000007

using namespace std;

int dx[4][2] = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
char cx[4] = {'L', 'U', 'D', 'R'};

int main()
{
    int n, m;
    cin >> n;
    cin >> m;
    vector<vector<char>> g(n, vector<char>(m));

    queue<pair<int, int>> qm;
    queue<pair<int, int>> qa;

    vector<vector<int>> path(n, vector<int>(m, INT_MAX));

    vector<pair<int, int>> escapes;

    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < m; c++)
        {
            cin >> g[r][c];

            if (g[r][c] == '.')
                if (r == n - 1 || c == m - 1 || r == 0 || c == 0)
                {
                    escapes.push_back({r, c});
                }

            if (g[r][c] == '#')
                path[r][c] = -1;

            if (g[r][c] == 'A')
            {
                if (r == n - 1 || c == m - 1 || r == 0 || c == 0)
                {

                    std::cout << "YES\n0\n";
                    return 0;
                }

                qa.push({r, c});
                path[r][c] = 1;
            }

            if (g[r][c] == 'M')
            {
                path[r][c] = -1;
                qm.push({r, c});
            }
        }
    }

    int qsz, cnt = 2, tr, tc, dr, dc;

    while (!qa.empty())
    {
        qsz = qa.size();
        for (int i = 0; i < qsz; i++)
        {
            tr = qa.front().first;
            tc = qa.front().second;
            qa.pop();

            for (int i = 0; i < 4; i++)
            {
                dr = tr + dx[i][0];
                dc = tc + dx[i][1];

                if (dr >= 0 && dc >= 0 && dr < n && dc < m && path[dr][dc] == INT_MAX)
                {
                    qa.push({dr, dc});
                    g[dr][dc] = cx[i];
                    path[dr][dc] = cnt;
                }
            }
        }

        cnt += 1;
    }

    cnt = 2;

    while (!qm.empty())
    {

        qsz = qm.size();
        for (int i = 0; i < qsz; i++)
        {
            tr = qm.front().first;
            tc = qm.front().second;
            qm.pop();

            for (int i = 0; i < 4; i++)
            {

                dr = tr + dx[i][0];
                dc = tc + dx[i][1];

                if (dr >= 0 && dc >= 0 && dr < n && dc < m && cnt <= path[dr][dc])
                {
                    qm.push({dr, dc});
                    path[dr][dc] = -1;
                }
            }
        }
        cnt += 1;
    }

    for (auto e : escapes)
    {
        tr = e.first;
        tc = e.second;

        string ans = "";

        if (path[tr][tc] == -1 || path[tr][tc] == INT_MAX)
            continue;

        std::cout << "YES\n";


        while (g[tr][tc] != 'A')
        {
            ans.push_back(g[tr][tc]);

            if (g[tr][tc] == 'L')
                tc += 1;
            else if (g[tr][tc] == 'U')
                tr += 1;
            else if (g[tr][tc] == 'R')
                tc -= 1;
            else
                tr -= 1;
        }

        reverse(ans.begin(), ans.end());
        cout << ans.size() << "\n"
             << ans << "\n";
        return 0;
    }

    cout << "NO\n";

    return 0;
}