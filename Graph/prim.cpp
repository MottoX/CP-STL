const int N = 111;
const int INF = 0x3f3f3f3f;
bool vis[N];
int dis[N];
int g[N][N];

int prim(int s, int n) {
    memset(vis, 0, sizeof(vis));
    vis[s] = true;
    for (int i = 1; i <= n; i++)
        dis[i] = g[s][i];
    dis[s] = 0;
    int ans = 0;
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
        ans += dis[k];
        vis[k] = true;
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && dis[j] > g[k][j])
                dis[j] = g[k][j];
        }
    }
    return ans;
}


typedef pair<int, int> pii;
const int M = 40010;
const int N = 200;
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

int prim(int s, int n) {
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++)
        dis[i] = INF;
    dis[s] = 0;
    int ans = 0;
    priority_queue <pii, vector<pii>, greater<pii>> heap;
    heap.push(make_pair(dis[s], s));
    for (int i = 1; i <= n; i++) {
        while (!heap.empty() && vis[heap.top().second])
            heap.pop();
        if (heap.empty()) break;
        pii
                j = heap.top();
        vis[j.second] = true;
        heap.pop();
        ans += j.first;
        for (int k = head[j.second]; k; k = edge[k].next) {
            int v = edge[k].to;
            if (!vis[v] && dis[v] > edge[k].len) {
                dis[v] = edge[k].len;;
                heap.push(make_pair(edge[k].len, v));
            }
        }
    }
    return ans;
}