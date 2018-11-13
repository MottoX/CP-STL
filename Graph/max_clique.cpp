const int N = 100;
bool g[N][N];
int stk[N][N], dp[N], mc;
int choice[N], vertex[N];

void dfs(int n, int sz, int dep) {
    if (sz == 0) {
        if (dep > mc) {
            mc = dep;
            for (int i = 0; i < mc; i++)
                vertex[i] = choice[i];
        }
        return;
    }
    for (int i = 0; i < sz; i++) {
        int u = stk[dep][i];
        if (dep + dp[u] <= mc) return;
        if (dep + sz - i <= mc) return;
        choice[dep] = u;
        int cnt = 0;
        for (int j = i + 1; j < sz; j++) {
            int v = stk[dep][j];
            if (g[u][v])
                stk[dep + 1][cnt++] = v;
        }
        dfs(n, cnt, dep + 1);
    }
}

int maxClique(int n) {
    mc = 1;
    dp[n] = 1;
    for (int i = n - 1; i >= 1; i--) {
        int sz = 0;
        for (int j = i + 1; j <= n; j++)
            if (g[i][j])
                stk[1][sz++] = j;
        choice[0] = i;
        dfs(n, sz, 1);
        dp[i] = mc;
    }
    return mc;
}

