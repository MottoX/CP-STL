const int M = 100010;

struct Edge {
    int u, v, w;

    Edge() {}

    Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}

    bool operator<(const Edge &o) const {
        return w < o.w;
    }
} edge[M];

int fa[N];

int Find(int x) {
    if (fa[x] != x)
        fa[x] = Find(fa[x]);
    return fa[x];
}

bool Union(int u, int v) {
    int f1 = Find(u);
    int f2 = Find(v);
    if (f1 != f2) {
        fa[f1] = f2;
        return true;
    }
    return false;
}

int kruskal(int n, int m) {
    sort(edge + 1, edge + 1 + m);
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    int cnt = 0, ans = 0;
    for (int i = 1; i <= m; i++) {
        if (Union(edge[i].u, edge[i].v)) {
            ++cnt;
            ans += edge[i].w;
        }
        if (cnt == n - 1)
            return ans;
    }
    return cnt == n - 1 ? ans : 0;
}
