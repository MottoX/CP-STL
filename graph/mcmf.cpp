const int N = 3000;
const int M = 1000000;
const int INF = ~0U >> 1;

struct Edge {
    int to, next, f, c;

    Edge() {}

    Edge(int _to, int _nxt, int _f, int _c) : to(_to), next(_nxt), f(_f), c(_c) {}
} edge[M];

int head[N], idx;
bool vis[N];
int dis[N], pree[N], prev[N];

void addEdge(int u, int v, int flow, int cost) {
    edge[++idx] = Edge(v, head[u], flow, cost);
    head[u] = idx;
    edge[++idx] = Edge(u, head[v], 0, -cost);
    head[v] = idx;
}

bool spfa(int s, int e) {
    memset(vis, 0, sizeof(vis));
    memset(pree, -1, sizeof(pree));
    memset(prev, -1, sizeof(prev));
    fill(dis, dis + N, INF);
    dis[s] = 0;
    vis[s] = true;
    queue<int> que;
    que.push(s);
    while (!que.empty()) {
        int cur = que.front();
        que.pop();
        vis[cur] = false;
        for (int k = head[cur]; k; k = edge[k].next) {
            if (edge[k].f) {
                int n = edge[k].to;
                if (dis[n] > dis[cur] + edge[k].c) {
                    dis[n] = dis[cur] + edge[k].c;
                    prev[n] = cur;
                    pree[n] = k;
                    if (!vis[n]) {
                        vis[n] = true;
                        que.push(n);
                    }
                }
            }
        }
    }
    if (dis[e] == INF) return 0;
    return 1;
}

int minCostMaxFlow(int src, int sink) {
    int cur, min_val;
    int ansf = 0, ansc = 0;
    while (spfa(src, sink)) {
        cur = sink;
        min_val = INF;
        while (prev[cur] != -1) {
            if (min_val > edge[pree[cur]].f)
                min_val = edge[pree[cur]].f;
            cur = prev[cur];
        }
        cur = sink;
        while (prev[cur] != -1) {
            edge[pree[cur]].f -= min_val;
            edge[pree[cur] ^ 1].f += min_val;
            cur = prev[cur];
        }
        ansc += dis[sink] * min_val;
        ansf += min_val;
    }
    return ansc;
}