const int N = 5111;
const int M = 1000010;

struct Edge {
    int to, next;

    Edge() {}

    Edge(int _to, int _nxt) : to(_to), next(_nxt) {}
} edge[M];

int idx = 1, head[N];

void addEdge(int u, int v) {
    edge[++idx] = Edge(v, head[u]);
    head[u] = idx;
    edge[++idx] = Edge(u, head[v]);
    head[v] = idx;
}

int dfn[N], low[N];
bool vis[N], isCut[N];
int subCnt[N];

void dfs(int u, int fa, int dep) {
    vis[u] = true;
    dfn[u] = low[u] = dep;
    int son = 0;
    for (int k = head[u]; k; k = edge[k].next) {
        int v = edge[k].to;
        if (v == fa) continue;
        if (vis[v])
            low[u] = min(low[u], dfn[v]);
        else {
            dfs(v, u, ++dep);
            son++;
            low[u] = min(low[u], low[v]);
            if ((fa == -1 && son > 1) || (fa != -1 && low[v] >= dfn[u])) {
                isCut[u] = true;
                subCnt[u]++;
            }
        }
    }
    if (fa == -1) subCnt[u] = son - 1;
}

int getCut(int n) {
    memset(vis, false, sizeof(vis));
    memset(isCut, false, sizeof(isCut));
    memset(subCnt, 0, sizeof(subCnt));
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        dfs(i, -1, 1);
        cnt++;
    }
    for (int i = 1; i <= n; i++) subCnt[i] += cnt;
    int ret = 0;
    for (int i = 1; i <= n; i++) ret += isCut[i];
    return ret;
}