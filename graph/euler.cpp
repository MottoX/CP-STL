const int N = 200010;
typedef long long ll;

struct Edge {
    int to, next;

    Edge() {}

    Edge(int _t, int _n) : to(_t), next(_n) {}
} edge[N << 1];

int idx, head[N];

void addEdge(int u, int v) {
    edge[++idx] = Edge(v, head[u]);
    head[u] = idx;
}

vector<int> path;
bool vis[N << 1];

void dfs(int u) {
    for (int k = head[u]; k; k = edge[k].next) {
        if (!vis[k]) {
            vis[k] = true;
            vis[k ^ 1] = true;
            dfs(edge[k].to);
            path.push_back(k);
        }
    }
}