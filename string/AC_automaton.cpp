const int CHARSET = 26, BASE = 'a', MAX_NODE = 1000000;

struct acAutomation {
    int tot, root, fail[MAX_NODE], child[MAX_NODE][CHARSET];
    int flag[MAX_NODE];

    acAutomation() {
        init();
    }

    void init() {
        root = tot = 0;
        flag[root] = 0;
        memset(child[root], 0, sizeof(child[root]));
    }

    int newNode() {
        ++tot;
        memset(child[tot], 0, sizeof(child[tot]));
        flag[tot] = false;
        return tot;
    }

    void insert(const char *str) {
        int *cur = &root;
        for (const char *p = str; *p; ++p) {
            cur = &child[*cur][*p - BASE];
            if (*cur == 0)
                *cur = newNode();
        }
        flag[*cur]++;
    }

    void build() {
        queue<int> que;
        for (int i = 0; i < CHARSET; i++) {
            if (child[root][i] == 0) child[root][i] = root;
            else {
                fail[child[root][i]] = root;
                que.push(child[root][i]);
            }
        }
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            for (int i = 0; i < CHARSET; i++) {
                if (child[u][i] == 0) child[u][i] = child[fail[u]][i];
                else {
                    fail[child[u][i]] = child[fail[u]][i];
                    que.push(child[u][i]);
                }
            }
        }
    }

    int query(const char *str) {
        int ret = 0, u = root;
        for (const char *p = str; *p; ++p) {
            u = child[u][*p - BASE];
            int tmp = u;
            while (tmp != root) {
                ret += flag[tmp];
                flag[tmp] = 0;
                tmp = fail[tmp];
            }
        }
        return ret;
    }
}
