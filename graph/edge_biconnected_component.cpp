const int N = 1111;
const int M = 1000;

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

int dfn[N], low[N], bcc[N], bccCnt, stk[N], stkTop;
bool vis[M];
vector<int> node[N];

void dfs(int u, int fa, int dep) {
    vis[u] = true;
    dfn[u] = low[u] = dep;
    stk[++stkTop] = u;
    int son = 0;
    for (int k = head[u]; k; k = edge[k].next) {
        int v = edge[k].to;
        if ((k ^ 1) == fa) continue;
        if (vis[v])low[u] = min(low[u], dfn[v]);
        else {
            dfs(v, k, ++dep);
            if (low[v] > dfn[u]) {
                ++bccCnt;
                do {
                    bcc[stk[stkTop]] = bccCnt;
                    node[bccCnt].push_back(stk[stkTop]);
                } while (stk[stkTop--] != v);
            }
            low[u] = min(low[u], low[v]);
        }
    }
}

int tarjan(int n) {
    bccCnt = 0;
    stkTop = 0;
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) node[i].clear();
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            dfs(i, -1, 1);
            ++bccCnt;
            do {
                bcc[stk[stkTop]] = bccCnt;
                node[bccCnt].push_back(stk[stkTop]);
            } while (stk[stkTop--] != i);
        }
    }
    return bccCnt;
}