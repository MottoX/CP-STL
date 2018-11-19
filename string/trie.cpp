const int CHARSET = 10, BASE = '0', MAX_NODE = 100000;

struct Trie {
    int tot, root, child[MAX_NODE][CHARSET];
    int flag[MAX_NODE];

    Trie() {
        init();
    }

    void init() {
        root = newNode();
    }

    int newNode() {
        ++tot;
        memset(child[tot], 0, sizeof(child[tot]));
        flag[tot] = 0;
        return tot;
    }

    void insert(const char *str, int id) {
        int *cur = &root;
        for (const char *p = str; *p; ++p) {
            cur = &child[*cur][*p - BASE];
            if (*cur == 0) {
                *cur = newNode();
            }
        }
        flag[*cur]++;
    }

    bool remove(const char *str) {
        int *cur = &root;
        const char *p;
        for (p = str; *p && (*cur); ++p) {
            cur = &child[*cur][*p - BASE];
        }
        if ((*p) != 0 || !flag[*cur])
            return false;
        flag[*cur] = false;
        return true;
    }

    bool exist(const char *str) {
        int *cur = &root;
        for (const char *p = str; *p && (*cur); ++p) {
            cur = &child[*cur][*p - BASE];
        }
        return (*cur && flag[*cur]);
    }

    bool query(const char *str) {
        /
        int *cur = &root;
        for (const char *p = str; *p && (*cur); ++p) {
            cur = &child[*cur][*p - BASE];
            if (*cur && flag[*cur])
                return true;
        }
        return (*cur);
    }
};

