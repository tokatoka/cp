#include <bits/stdc++.h>
using namespace std;
#define ll long long

static const int MOD = 998244353;

template <int MOD>
struct Fp
{
    long long val;
    constexpr Fp(long long v = 0) noexcept : val(v % MOD)
    {
        if (val < 0)
            val += MOD;
    }
    constexpr int getmod() const { return MOD; }
    constexpr Fp operator-() const noexcept
    {
        return val ? MOD - val : 0;
    }
    constexpr Fp operator+(const Fp &r) const noexcept { return Fp(*this) += r; }
    constexpr Fp operator-(const Fp &r) const noexcept { return Fp(*this) -= r; }
    constexpr Fp operator*(const Fp &r) const noexcept { return Fp(*this) *= r; }
    constexpr Fp operator/(const Fp &r) const noexcept { return Fp(*this) /= r; }
    constexpr Fp &operator+=(const Fp &r) noexcept
    {
        val += r.val;
        if (val >= MOD)
            val -= MOD;
        return *this;
    }
    constexpr Fp &operator-=(const Fp &r) noexcept
    {
        val -= r.val;
        if (val < 0)
            val += MOD;
        return *this;
    }
    constexpr Fp &operator*=(const Fp &r) noexcept
    {
        val = val * r.val % MOD;
        return *this;
    }
    constexpr Fp &operator/=(const Fp &r) noexcept
    {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b)
        {
            long long t = a / b;
            a -= t * b, swap(a, b);
            u -= t * v, swap(u, v);
        }
        val = val * u % MOD;
        if (val < 0)
            val += MOD;
        return *this;
    }
    constexpr bool operator==(const Fp &r) const noexcept
    {
        return this->val == r.val;
    }
    constexpr bool operator!=(const Fp &r) const noexcept
    {
        return this->val != r.val;
    }
    friend constexpr istream &operator>>(istream &is, Fp<MOD> &x) noexcept
    {
        is >> x.val;
        x.val %= MOD;
        if (x.val < 0)
            x.val += MOD;
        return is;
    }
    friend constexpr ostream &operator<<(ostream &os, const Fp<MOD> &x) noexcept
    {
        return os << x.val;
    }
    friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept
    {
        if (n == 0)
            return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1)
            t = t * a;
        return t;
    }
};

using mint = Fp<MOD>;

signed main()
{
    ll N, S;
    cin >> N >> S;
    vector<ll> A;
    for(int i = 0; i < N; i++){
        ll a;
        cin >> a;
        A.push_back(a);
    }
    vector<vector<mint>> dp(3000 + 20, vector<mint>(3000 + 20, 0));
    dp[0][0] = mint(1);
    for(int k = 0; k < N; k++){
        for(int i = 0; i <= S; i++){
            dp[k + 1][i] += dp[k][i] * 2;
            if(i + A[k] <= S)dp[k + 1][i + A[k]] += dp[k][i];
        }
    }
    cout << dp[N][S] << endl;
}