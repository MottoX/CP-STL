const int N = 1010;
const int M = 10010;
const int INF = 0x3f3f3f3f;

struct Edge {
    int to, next, len;

    Edge() {}

    Edge(int _to, int _next, int _len) : to(_to), next(_next), len(_len) {}
} edge[M];

int idx = 1, head[N];

inline void addEdge(int u, int v, int len) {
    edge[++idx] = Edge(v, head[u], len);
    head[u] = idx;
}

int dis[N];

bool BellmanFord(int s, int e, int n) {
    //start from one;
    fill(dis, dis + N, INF);
    dis[s] = 0;
    for (int it = 1; it < n; it++) {
        for (int i = 1; i <= n; i++) {
            if (dis[i] == INF) continue;
            for (int k = head[i]; k; k = edge[k].next) {
                if (edge[k].len != INF && dis[edge[k].to] > dis[i] + edge[k].len)
                    dis[edge[k].to] = dis[i] + edge[k].len;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dis[i] == INF) continue;
        for (int k = head[i]; k; k = edge[k].next) {
            if (edge[k].len != INF && dis[edge[k].to] > dis[i] + edge[k].len)
                return false;
        }
    }
    return true;
}