const int INF = 10000000;
const int N = 10000;
const int M = 1000000;

struct Edge {
    int to, next, len;

    Edge() {}

    Edge(int _to, int _next, int _len) : to(_to), next(_next), len(_len) {}
} edge[M];

int idx = 1, head[N];

inline void addEdge(int u, int v, int l) {
    edge[++idx] = Edge(v, head[u], l);
    head[u] = idx;
}

int dis[N], in[N];
bool vis[N];

bool spfa(int s, int n) {
    fill(dis, dis + N, INF);
    memset(vis, false, sizeof(vis));
    memset(in, 0, sizeof(in));
    dis[s] = 0;
    vis[s] = true;
    queue<int> que;
    que.push(s);
    in[s] = 1;
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        vis[u] = false;
        for (int k = head[u]; k; k = edge[k].next) {
            int v = edge[k].to;
            if (dis[v] > dis[u] + edge[k].len) {
                dis[v] = dis[u] + edge[k].len;
                if (!vis[v]) {
                    vis[v] = true;
                    in[v]++;
                    if (in[v] > n) return false;
                    que.push(v);
                }
            }
        }
    }
    return true;
}