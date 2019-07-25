
const int CHARSET = 10, BASE = '0', MAX_NODE = 100000;

struct Trie {
    int tot, root, child[MAX_NODE][CHARSET];
    bool flag[MAX_NODE];

    Trie() {
        init();
    }

    void init() {
        memset(child[1], 0, sizeof(child[1]));
        flag[1] = true;
        root = tot = 1;
    }

    void insert(const char *str) {
        int *cur = &root;
        for (const char *p = str; *p; ++p) {
            cur = &child[*cur][*p - BASE];
            if (*cur == 0) {
                *cur = ++tot;
                memset(child[tot], 0, sizeof(child[tot]));
                flag[tot] = false;
            }
        }
        flag[*cur] = true;
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
        int *cur = &root;
        for (const char *p = str; *p && (*cur); ++p) {
            cur = &child[*cur][*p - BASE];
            if (*cur && flag[*cur])
                return true;
        }
        return (*cur);
    }
};

const int CHARSET = 10, BASE = '0';

struct TrieNode {
    TrieNode() {
        flag = false;
        memset(next, 0, sizeof(next));
    }

    TrieNode *next[CHARSET];
    bool flag;
};

struct Trie {
    TrieNode *root;

    Trie() {
        init();
    }

    ~Trie() {
        removeAll(root);
    }

    void init() {
        root = new TrieNode();
    }

    void insert(char *str) {
        int len = strlen(str);
        TrieNode *s = root;
        for (int i = 0; i < len; i++) {
            if (s->next[str[i] - BASE] == 0) {
                s->next[str[i] - BASE] = new TrieNode();
            }
            s = s->next[str[i] - BASE];
        }
        s->flag = true;
    }

    bool exist(char *str) {
        int n = strlen(str);
        TrieNode *t = root;
        for (int i = 0; i < n; i++) {
            if (t->next[str[i] - BASE])
                t = t->next[str[i] - BASE];
            else
                return false;
        }
        return t->flag;
    }

    bool query(char *str) {
        int n = strlen(str);
        TrieNode *t = root;
        for (int i = 0; i < n; i++) {
            if (t->next[str[i] - BASE]) {
                t = t->next[str[i] - BASE];
                if (t->flag == true)
                    return true;
            } else
                return false;
        }
        return true;
    }

    void removeAll(TrieNode *rt) {
        for (int i = 0; i < CHARSET; i++) {
            if (rt->next[i])
                removeAll(rt->next[i]);
        }
        delete rt;
    }
};