#include <bits/stdc++.h>
using namespace std;
#define ll long long

signed main()
{
    ll N, Q;
    cin >> N >> Q;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i] >> B[i];
        B[i]--;
    }
    const ll M = 200000;
    vector<multiset<ll>> kindergartens(M);
    multiset<ll> maxes;
    for (int i = 0; i < N; i++)
    {
        kindergartens[B[i]].insert(A[i]);
    }
    for (int i = 0; i < M; i++)
    {
        if (kindergartens[i].size())
        {
            maxes.insert(*kindergartens[i].rbegin());
        }
    }
    auto del_max = [&](int i) {
        if (kindergartens[i].size())
            maxes.erase(maxes.find(*kindergartens[i].rbegin()));
    };
    auto add_max = [&](int i) {
        if (kindergartens[i].size())
            maxes.insert(*kindergartens[i].rbegin());
    };
    auto del = [&](int i, int a) {
        del_max(i);
        kindergartens[i].erase(kindergartens[i].find(a));
        add_max(i);
    };
    auto add = [&](int i, int a) {
        del_max(i);
        kindergartens[i].insert(a);
        add_max(i);
    };

    while (Q--)
    {
        int i, aft;

        cin >> i >> aft;
        i--;
        aft--;
        int bef = B[i];
        B[i] = aft;

        del(bef, A[i]);
        add(aft, A[i]);
        int ans = *maxes.begin();
        cout << ans << endl;
    }
}