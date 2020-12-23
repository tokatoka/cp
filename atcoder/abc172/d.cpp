#include <bits/stdc++.h>
using namespace std;
#define int long long

int factorize(vector<int> &spf, int n)
{
    map<int, int> mp;
    while (n != 1)
    {
        mp[spf[n]]++;
        n = n / spf[n];
    }
    int res = 1;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        res = res * (it->second + 1);
    }
    return res;
}

signed main()
{
    int N;
    cin >> N;
    vector<int> spf(N + 1, 0);
    for (int i = 0; i < N + 1; i++)
    {
        spf[i] = i;
    }
    int i = 2;
    while (i * i <= N)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j < N + 1; j += i)
            {
                if (spf[j] == j)
                {
                    spf[j] = i;
                }
            }
        }
        i++;
    }
    int ans = 0;
    for (int i = 1; i < N + 1; i++)
    {
        ans = ans + i * factorize(spf, i);
    }
    cout << ans << endl;
}