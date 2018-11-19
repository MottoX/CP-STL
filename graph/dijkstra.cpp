const int N = 1010;
const int INF = 0x3f3f3f3f;
bool vis[N];
int dis[N];
int g[N][N];

void dijkstra(int s, int n) {
    memset(vis, 0, sizeof(vis));
    vis[s] = true;
    for (int i = 1; i <= n; i++)
        dis[i] = g[s][i];
    dis[s] = 0;
    for (int i = 1; i < n; i++) {
        int k = 0;
        int val = INF;
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && dis[j] < val) {
                k = j;
                val = dis[j];
            }
        }
        if (k == 0) break;
        vis[k] = true;
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && dis[j] > dis[k] + g[k][j])
                dis[j] = dis[k] + g[k][j];
        }
    }
}


// heap optimization
typedef pair<int, int> pii;
const int M = 155555;
const int N = 30010;
const int INF = 0x3f3f3f3f;

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

bool vis[N];
int dis[N];

void dijkstra(int s, int n) {
    memset(vis, 0, sizeof(vis));
    fill(dis, dis + N, INF);
    dis[s] = 0;
    priority_queue <pii, vector<pii>, greater<pii>> heap;
    heap.push(make_pair(dis[s], s));
    for (int i = 1; i <= n; i++) {
        while (!heap.empty() && vis[heap.top().second])
            heap.pop();
        if (heap.empty()) break;
        pii j = heap.top();
        int u = j.second;
        vis[u] = true;
        heap.pop();
        for (int k = head[u]; k; k = edge[k].next) {
            int v = edge[k].to;
            if (!vis[v] && dis[v] > dis[u] + edge[k].len) {
                dis[v] = dis[u] + edge[k].len;;
                heap.push(make_pair(dis[v], v));
            }
        }
    }
}


