#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int h, w;
    cin >> h >> w;
    map<int, int> s;
    multiset<int> vals;

    for (auto i = 0; i < w; i++)
    {
        s[i] = i;
    }
    for (auto i = 0; i < w; i++)
    {
        vals.insert(0);
    }
    for (auto i = 0; i < h; i++)
    {
        int l, r;
        cin >> l >> r;
        l--;
        auto it = s.lower_bound(l);
        int mr = -1;
        while (it != s.end() && it->first <= r)
        {
            mr = max(mr, it->second);
            vals.erase(vals.find(it->first - it->second));
            s.erase(it++);
        }
        if (mr != -1 && r < w)
        {
            vals.insert(r - mr);
            s[r] = mr;
        }
        int ans = -1;
        if (vals.size() > 0)
        {
            ans = *vals.begin() + (i + 1);
        }
        cout << ans << endl;
    }

    return 0;
}