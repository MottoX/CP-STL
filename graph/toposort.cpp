const int N = 10010;
const int M = 100010;

struct Edge {
    int to, next;

    Edge() {}

    Edge(int _to, int _nxt) : to(_to), next(_nxt) {}
} edge[M];

int idx = 1, head[N];

void addEdge(int u, int v) {
    edge[++idx] = Edge(v, head[u]);
    head[u] = idx;
}

int in[N], que[N];

bool toposort(int n) {
    memset(in, 0, sizeof(in));
    for (int i = 1; i <= n; i++)
        for (int k = head[i]; k; k = edge[k].next) {
            int v = edge[k].to;
            in[v]++;
        }
    int tail = 0;
    for (int i = 1; i <= n; i++)
        if (in[i] == 0)
            que[tail++] = i;
    for (int i = 0; i < tail; i++) {
        for (int k = head[que[i]]; k; k = edge[k].next) {
            int v = edge[k].to;
            in[v]--;
            if (in[v] == 0)
                que[tail++] = v;
        }
    }
    return tail == n;
}

