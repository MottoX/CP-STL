const int N = 1000;
const int M = 1000010;

struct Edge {
    int to, next;

    Edge() {}

    Edge(int _to, int _nxt) : to(_to), next(_nxt) {}
} edge[N << 1];

int idx = 1, head[N];

void addEdge(int u, int v) {
    edge[++idx] = Edge(v, head[u]);
    head[u] = idx;
    edge[++idx] = Edge(u, head[v]);
    head[v] = idx;
}

int dfn[N], low[N], vis[N], bcc[N], bccCnt, stk[N], stkTop;
vector<int> block[N];

void dfs(int u, int f, int &dep) {
    vis[u] = 1;
    low[u] = dfn[u] = dep;
    stk[++stkTop] = u;
    for (int k = head[u]; k; k = edge[k].next) {
        int v = edge[k].to;
        if (v == f) continue;
        if (vis[v] == 0) {
            dfs(v, u, ++dep);
            if (low[v] >= dfn[u]) {
                ++bccCnt;
                do {
                    bcc[stk[stkTop]] = bccCnt;
                    block[bccCnt].push_back(stk[stkTop]);
                    stkTop--;
                } while (stk[stkTop + 1] != v);
                block[bccCnt].push_back(u);
                bcc[u] = bccCnt;
            }
            low[u] = min(low[u], low[v]);
        } else if (vis[v] == 1)
            low[u] = min(low[u], dfn[v]);
    }
}

int tarjan(int n) {
    bccCnt = 0;
    stkTop = 0;
    int dep = 1;
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) block[i].clear();
    for (int i = 1; i <= n; i++)
        if (vis[i] == 0)
            dfs(i, dep);
    return bccCnt;
}
