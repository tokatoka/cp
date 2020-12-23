#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int R, C, K;
    cin >> R >> C >> K;
    map<pair<int, int>, int> mp;
    for (int i = 0; i < K; i++)
    {
        int r, c, v;
        cin >> r >> c >> v;
        r--;
        c--;
        mp[make_pair(r, c)] = v;
    }

    vector<vector<vector<int>>> dp(R, vector<vector<int>>(C, vector<int>(4, -1)));
    dp[0][0][0] = 0;
    for (int r = 0; r < R; r++)
    {
        for (int c = 0; c < C; c++)
        {
            for (int k = 0; k < 4; k++)
            {
                if (dp[r][c][k] < 0)
                {
                    continue;
                }
                if (c + 1 < C)
                {
                    dp[r][c + 1][k] = max(dp[r][c + 1][k], dp[r][c][k]);
                    if (k < 3 and mp.count(make_pair(r, c)))
                    {
                        dp[r][c + 1][k + 1] = max(dp[r][c + 1][k + 1], dp[r][c][k] + mp[make_pair(r, c)]);
                    }
                }
                if (r + 1 < R)
                {
                    dp[r + 1][c][0] = max(dp[r + 1][c][0], dp[r][c][k]);
                    if (k < 3 and mp.count(make_pair(r, c)))
                        dp[r + 1][c][0] = max(dp[r + 1][c][0],
                                              dp[r][c][k] + mp[make_pair(r, c)]);
                }
            }
        }
    }
    if (mp.count(make_pair(R - 1, C - 1)))
    {
        for (int i = 0; i < 3; i++)
        {
            dp[R - 1][C - 1][i] += mp[make_pair(R - 1, C - 1)];
        }
    }
    cout << *max_element(begin(dp[R - 1][C - 1]), end(dp[R - 1][C - 1])) << endl;
}
