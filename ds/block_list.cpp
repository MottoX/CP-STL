struct BlockList {
#define T char
#define MAXN 2010

    struct Node {
        T data[MAXN];
        int next, siz;

        void init() {
            memset(data, 0, sizeof data);
            next = -1;
            siz = 0;
        }
    } node[N];

    int head, tot;

    void init(T o[], int n) {
        head = 0;
        tot = 0;
        node[tot++].init();
        for (int i = 0, u = head; i < n; u = node[u].next) {
            for (int j = 0; j < MAXN && i < n; j++, i++) {
                node[u].data[j] = o[i];
                node[u].siz++;
            }
            if (i < n) {
                node[tot].init();
                node[u].next = tot++;
            }
        }
        for (int u = head; ~u; u = node[u].next) {
            if (node[u].siz >= MAXN) split(u);
        }
    }

    void split(int u) {
        node[tot].init();
        for (int i = MAXN / 2; i < MAXN; i++) {
            node[tot].data[i - MAXN / 2] = node[u].data[i];
            node[tot].siz++;
            node[u].data[i] = 0;
            node[u].siz--;
        }
        node[tot].next = node[u].next;
        node[u].next = tot++;
    }

    void insert(int pos, T val) {
        int u = head;
        while (pos > node[u].siz && ~node[u].next) {
            pos -= node[u].siz;
            u = node[u].next;
        }
        if (pos >= node[u].siz) node[u].data[node[u].siz] = val;
        else {
            for (int i = node[u].siz; i > pos; i--) node[u].data[i] = node[u].data[i - 1];
            node[u].data[pos] = val;
        }
        node[u].siz++;
        if (node[u].siz == MAXN) split(u);
    }

    T query(int pos) {
        int u = head;
        while (pos > node[u].siz && ~node[u].next) {
            pos -= node[u].siz;
            u = node[u].next;
        }
        return node[u].data[pos - 1];
    }
};
