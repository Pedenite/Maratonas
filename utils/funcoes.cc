#define ll long long

ll gcd(ll a, ll b) {
    return !b ? a : gcd(b, a%b);
}
