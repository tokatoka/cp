#include <bits/stdc++.h>
using namespace std;
#define ll long long

static const int MOD = 1000000007;

class NCR
{
private:
    static const int MAX = 510000;
    ll fac[MAX], finv[MAX], inv[MAX];

public:
    void COMinit()
    {
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for (int i = 2; i < MAX; i++)
        {
            fac[i] = fac[i - 1] * i % MOD;
            inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
            finv[i] = finv[i - 1] * inv[i] % MOD;
        }
    }
    ll COM(int n, int k)
    {
        if (n < k)
            return 0;
        if (n < 0 || k < 0)
        {
            return 0;
        }
        return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
    }
    ll Perm(int n, int k)
    {
        return fac[n] * finv[n - k] % MOD;
    }
};

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
    ll N, M;
    cin >> N >> M;
    NCR *ncr = new NCR;
    ncr->COMinit();
    mint ans = ncr->Perm(M, N) * ncr->Perm(M, N);
    mint sub = 0;
    for (ll k = 1; k <= N; k++)
    {
        mint v = ncr->COM(N, k) * ncr->Perm(M - k, N - k);
        if (k & 1)
        {
            sub += v;
        }
        else
        {
            sub -= v;
        }
    }
    sub = sub * ncr->Perm(M, N);
    ans -= sub;
    cout << ans << endl;
}