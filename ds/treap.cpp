struct Treap {
#define maxNode 200010
    int root, treapCnt, key[maxNode], priority[maxNode],
            child[maxNode][2], cnt[maxNode], size[maxNode];

    Treap() {
        root = 0;
        treapCnt = 0;
        priority[0] = ~0U >> 1;
        size[0] = 0;
    }

    void update(int x) {
        size[x] = size[child[x][0]] + cnt[x] + size[child[x][1]];
    }

    void rotate(int &x, int t) {
        int y = child[x][t];
        child[x][t] = child[y][1 - t];
        child[y][1 - t] = x;
        update(x);
        update(y);
        x = y;
    }

    void __insert(int &x, int k) {
        if (x) {
            if (key[x] == k)
                cnt[x]++;
            else {
                int t = key[x] < k;//СΪ1��Ӧ��������
                __insert(child[x][t], k);
                if (priority[child[x][t]] < priority[x])
                    rotate(x, t);
            }
        } else {
            x = ++treapCnt;
            key[x] = k;
            cnt[x] = 1;
            priority[x] = rand();
            child[x][0] = child[x][1] = 0;
        }
        update(x);
    }

    void __erase(int &x, int k) {
        if (key[x] == k) {
            if (cnt[x] > 1)
                cnt[x]--;
            else {
                if (child[x][0] == 0 && child[x][1] == 0) {
                    x = 0;
                    return;
                }
                int t = priority[child[x][0]] > priority[child[x][1]];
                rotate(x, t);
                __erase(x, k);
            }
        } else
            __erase(child[x][key[x] < k], k);

        update(x);
    }

    int __getKth(int &x, int k, int t) {
        if (k <= size[child[x][t]])
            return __getKth(child[x][t], k, t);
        k -= size[child[x][t]] + cnt[x];
        if (k <= 0) return key[x];
        return __getKth(child[x][1 - t], k, t);
    }

    void insert(int k) {
        __insert(root, k);
    }

    void erase(int k) {
        __erase(root, k);
    }

    int getKth(int k, int t = 0) {
        return __getKth(root, k, t);
    }
}