int sa[N];
int t1[N], t2[N], c[N];
int rk[N], height[N];

inline int cmp(int *r, int a, int b, int l) {
    return r[a] == r[b] && r[a + l] == r[b + l];
}

char s[N];

void calcSA(char *s, int n, int m) {
    int i, j, p, *x = t1, *y = t2;
    for (i = 0; i < m; i++)c[i] = 0;
    for (i = 0; i < n; i++)c[x[i] = s[i]]++;
    for (i = 1; i < m; i++)c[i] += c[i - 1];
    for (i = n - 1; i >= 0; i--)sa[--c[x[i]]] = i;
    for (j = 1; j <= n; j <<= 1) {
        p = 0;
        for (i = n - j; i < n; i++)y[p++] = i;
        for (i = 0; i < n; i++)if (sa[i] >= j)y[p++] = sa[i] - j;
        for (i = 0; i < m; i++)c[i] = 0;
        for (i = 0; i < n; i++)c[x[y[i]]]++;
        for (i = 1; i < m; i++)c[i] += c[i - 1];
        for (i = n - 1; i >= 0; i--)sa[--c[x[y[i]]]] = y[i];
        swap(x, y);
        p = 1;
        x[sa[0]] = 0;
        for (i = 1; i < n; i++)
            x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
        if (p >= n)break;
        m = p;
    }
}

void calcHeight(char *s, int n) {
    int i, j, k = 0;
    for (i = 0; i <= n; i++)rk[sa[i]] = i;
    for (i = 0; i < n; i++) {
        if (k)k--; // h[i]>=h[i-1]-1
        j = sa[rk[i] - 1];
        while (s[i + k] == s[j + k])k++;
        height[rk[i]] = k;
    }
}
