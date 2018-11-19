const int N = 55555;

struct Edge {
    int to, next, f;

    Edge() {}

    Edge(int _to, int _next, int _f) : to(_to), next(_next), f(_f) {}
} edge[N << 2];

int idx = 1, head[N], nhead[N];

inline void addEdge(int u, int v, int flow) {
    edge[++idx] = Edge(v, head[u], flow);
    head[u] = idx;
    edge[++idx] = Edge(u, head[v], 0);
    head[v] = idx;
}

int lev[N], que[N];

inline bool bfs(int s, int e) {
    memset(lev, -1, sizeof(lev));
    int t = 0;
    que[t++] = s;
    lev[s] = 0;
    for (int h = 0; h < t; h++)
        for (int k = head[que[h]]; k; k = edge[k].next)
            if (edge[k].f && !~lev[edge[k].to]) {
                lev[edge[k].to] = lev[que[h]] + 1;
                que[t++] = edge[k].to;
            }
    return ~lev[e];
}

int dfs(int u, int ext, int e) {
    if (u == e)
        return ext;
    for (int &k = nhead[u], flow; k; k = edge[k].next)
        if (edge[k].f && lev[edge[k].to] == lev[u] + 1 && (flow = dfs(edge[k].to, min(edge[k].f, ext), e))) {
            edge[k].f -= flow;
            edge[k ^ 1].f += flow;
            return flow;
        }
    return 0;
}

long long MaxFlow(int s, int e) {
    long long ret = 0;
    while (bfs(s, e)) {
        memcpy(nhead, head, sizeof(head));
        while (int f = dfs(s, ~0U >> 1, e))
            ret += f;
    }
    return ret;
}

