#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int N;
    cin >> N;
    vector<int> A;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        A.push_back(a);
    }
    int ma = *max_element(A.begin(), A.end());
    vector<int> dp(ma + 1, 0);
    for (auto it = A.begin(); it != A.end(); it++)
    {
        int n = *it;
        while (n <= ma)
        {
            dp[n] += 1;
            n = n + *it;
        }
    }
    int res = 0;
    for (auto it = A.begin(); it != A.end(); it++)
    {
        if (dp[*it] == 1)
        {
            res += 1;
        }
    }

    cout << res << endl;
}