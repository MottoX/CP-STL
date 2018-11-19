// Hungarian
const int N = 600;
bool g[N][N], vis[N];
int nx, ny, cx[N], cy[N];

bool dfs(int u) {
    for (int i = 1; i <= ny; i++) {
        if (g[u][i] && !vis[i]) {
            vis[i] = true;
            if (cy[i] == -1 || dfs(cy[i])) {
                cy[i] = u;
                cx[u] = i;
                return true;
            }
        }
    }
    return false;
}

int maxMatch() {
    int ret = 0;
    memset(cx, -1, sizeof(cx));
    memset(cy, -1, sizeof(cy));
    for (int i = 1; i <= nx; i++) {
        if (cx[i] == -1) {
            memset(vis, 0, sizeof(vis));
            ret += dfs(i);
        }
    }
    return ret;
}


// Hopcroft-Karp
bool g[N][N], vis[N];
int nx, ny, dis, cx[N], cy[N], dx[N], dy[N];

bool bfs() {
    queue<int> que;
    dis = INF;
    memset(dx, -1, sizeof(dx));
    memset(dy, -1, sizeof(dy));
    for (int i = 1; i <= nx; i++) {
        if (cx[i] == -1) {
            que.push(i);
            dx[i] = 0;
        }
    }
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        if (dx[u] > dis) break;
        for (int v = 1; v <= ny; v++) {
            if (g[u][v] && dy[v] == -1) {
                dy[v] = dx[u] + 1;
                if (cy[v] == -1)
                    dis = dy[v];
                else {
                    dx[cy[v]] = dy[v] + 1;
                    que.push(cy[v]);
                }
            }
        }
    }
    return dis != INF;
}

bool dfs(int u) {
    for (int v = 1; v <= ny; v++) {
        if (!vis[v] && g[u][v] && dy[v] == dx[u] + 1) {
            vis[v] = true;
            if (cy[v] != -1 && dy[v] == dis)
                continue;
            if (cy[v] == -1 || dfs(cy[v])) {
                cy[v] = u;
                cx[u] = v;
                return true;
            }
        }
    }
    return false;
}

int maxMatch() {
    int ret = 0;
    memset(cx, -1, sizeof(cx));
    memset(cy, -1, sizeof(cy));
    while (bfs()) {
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= nx; i++)
            if (cx[i] == -1)
                ret += dfs(i);
    }
    return ret;
}
