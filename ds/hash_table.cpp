struct HashNode {
    int val, next;
};

struct HashSet {
#define HASHVAL 100007
#define T long long
#define MAXN 1000000+1000
    int head[HASHVAL], size;
    HashNode node[MAXN];

    void init() {
        size = 0;
        memset(head, 0, sizeof(head));
    }

    bool exist(T val) {
        T h = (val % HASHVAL + HASHVAL) % HASHVAL;
        for (int i = head[h]; i; i = node[i].next)
            if (node[i].val == val)
                return true;
        return false;
    }

    bool insert(T val) {
        T h = (val % HASHVAL + HASHVAL) % HASHVAL;
        for (int i = head[h]; i; i = node[i].next)
            if (node[i].val == val)
                return false;
        ++size;
        node[size].val = val;
        node[size].next = head[h];
        head[h] = size;
        return true;
    }

#undef T
}