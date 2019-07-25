struct BinaryIndexedTree {
    int v[N];
    int maxn;

    BinaryIndexedTree() {}

    BinaryIndexedTree(int _maxn) {
        maxn = _maxn;
        clear();
    }

    void clear() { memset(v, 0, sizeof(v)); }

    void setMaxn(int _maxn) { maxn = _maxn; }

    int lowbit(int x) {
        return x & (-x);
    }

    void update(int x, int add) {
        for (; x <= maxn; x += lowbit(x))
            v[x] += add;
    }

    void update(int x, int y, int add) {
        update(x, add);
        update(y + 1, -add);
    }

    int query(int x) {
        int sum = 0;
        for (; x; x -= lowbit(x))
            sum += v[x];
        return sum;
    }

    int query(int x, int y) {
        return query(y) - query(x - 1);
    }

    int getKmin(int k) {
        int ret = 0, cnt = 0;
        for (int i = 20; i >= 0; i--) {
            ret += 1 << i;
            if (ret >= maxn || v[ret] + cnt >= k)
                ret -= 1 << i;
            else cnt += v[ret];
        }
        return ret + 1;
    }
}


        Œ¥

∑‚◊∞∞Ê£∫

int v[N];
int maxn;

int lowbit(int x) {
    return x & (-x);
}

void update(int x, int add) {
    for (; x <= maxn; x += lowbit(x))
        v[x] += add;
}

void update(int x, int y, int add) {
    update(x, add);
    update(y + 1, -add);
}

int query(int x) {
    int sum = 0;
    for (; x; x -= lowbit(x))
        sum += v[x];
    return sum;
}

int query(int x, int y) {
    return query(y) - query(x - 1);
}

int getKmin(int k) {
    int ret = 0, cnt = 0;
    for (int i = 20; i >= 0; i--) {
        ret += 1 << i;
        if (ret >= maxn || v[ret] + cnt >= k)
            ret -= 1 << i;
        else cnt += v[ret];
    }
    return ret + 1;
}
