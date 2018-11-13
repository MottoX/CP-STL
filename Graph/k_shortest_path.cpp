const int N = 30010;
const int INF = 0x3f3f3f3f;
bool vis[N][2];
int dis[N][2];

struct Edge {
    int to, next, len;

    Edge() {}

    Edge(int _to, int _next, int _len) : to(_to), next(_next), len(_len) {}
} edge[M];

int idx = 1, head[N];

void addEdge(int u, int v, int l) {
    edge[++idx] = Edge(v, head[u], l);
    head[u] = idx;
}

void dijkstra(int s, int n) {
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) {
        dis[i][0] = INF;
        dis[i][1] = INF;
    }
    dis[s][0] = 0;
    for (int i = 1; i <= 2 * n; i++) {
        int k = 0;
        int val = INF;
        int flag;
        for (int j = 1; j <= n; j++) {
            if (!vis[j][0] && dis[j][0] < val) {
                k = j;
                flag = 0;
                val = dis[j][0];
            }
            if (!vis[j][1] && dis[j][1] < val) {
                k = j;
                flag = 1;
                val = dis[j][1];
            }
        }
        if (k == 0) break;
        vis[k][flag] = true;
        for (int o = head[k]; o; o = edge[o].next) {
            int j = edge[o].to;
            int w = edge[o].len;
            if (dis[j][0] > val + w) {
                dis[j][1] = dis[j][0];
                dis[j][0] = val + w;
            } else if (dis[j][1] > val + w)
                dis[j][1] = val + w;
        }
    }
}