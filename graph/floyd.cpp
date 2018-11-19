int g[N][N];

void floyd(int n) {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                if (g[i][k] == INF || g[k][j] == INF) continue;
                if (g[i][j] > g[i][k] + g[k][j])
                    g[i][j] = g[i][k] + g[k][j];
            }
}


int g[N][N];
int dis[N][N];

void floyd(int n) {
    memcpy(dis, g, sizeof g);
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dis[i][k] == INF || dis[k][j] == INF) continue;
                if (dis[i][j] > dis[i][k] + dis[k][j])
                    dis[i][j] = dis[i][k] + dis[k][j];
            }
        }
    }
}