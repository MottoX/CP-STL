typedef unsigned long long ll;
const int N = 1000010;
const ll P = 99997;
char a[N], b[N];
ll ha[N], hb[N];

void initHash(char *s, ll *h, int n = 0) {
    h[0] = 0;
    n = (n == 0) ? strlen(s) : n;
    for (int i = 1; i <= n; i++)
        h[i] = h[i - 1] * P + s[i - 1];
}

ll Pow[N];

inline ll hash(ll *h, int l, int r) {
    r++;
    return h[r] - h[l] * Pow[r - l];
}

void calcPow(int n) {
    Pow[0] = 1;
    for (int i = 1; i < n; i++)
        Pow[i] = Pow[i - 1] * P;
}
