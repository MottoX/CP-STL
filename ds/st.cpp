const int N = 200010;

int MIN(int a, int b) { return a < b ? a : b; }

int MAX(int a, int b) { return a > b ? a : b; }

int val[N];

struct RMQ {
    int dp[N][25];//�ڶ�άҪ��֤����log(N<<1)
    int (*cmp)(int, int);

    void setMin() { cmp = MIN; }

    void setMax() { cmp = MAX; }

    void init(int n, int *val) {
        for (int i = 1; i <= n; i++)
            dp[i][0] = val[i];
        for (int j = 1; (1 << j) <= n; j++) {
            int k = 1 << (j - 1);
            for (int i = 1; i + k <= n; i++)
                dp[i][j] = cmp(dp[i][j - 1], dp[i + k][j - 1]);
        }
    }

    int query(int a, int b) {
        if (a > b) swap(a, b);
        int dis = b - a + 1;
        int k = log((double) dis) / log(2.0);
        return cmp(dp[a][k], dp[b - (1 << k) + 1][k]);
    }
}