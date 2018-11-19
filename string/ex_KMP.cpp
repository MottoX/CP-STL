const int N = 1000010;
const int M = 100010;
char txt[N], pat[M];
int next[M];
int ret[N];

void getNext(char *a, int n = 0) {
    n = (n == 0) ? strlen(a) : n;
    int j;
    for (j = 0; 1 + j < n && a[j] == a[1 + j]; j++);
    next[1] = j;
    int k = 1;
    for (int i = 2; i < n; i++) {
        int len = k + next[k], l = next[i - k];
        if (l < len - i) next[i] = l;
        else {
            for (j = max(0, len - i); i + j < n && a[j] == a[i + j]; j++);
            next[i] = j;
            k = i;
        }
    }
}

void exKMP(char *a, char *b, int *ret, int n = 0, int m = 0) {
    n = (n == 0) ? strlen(a) : n;
    m = (m == 0) ? strlen(b) : m;
    int j;
    for (j = 0; j < n && j < m && a[j] == b[j]; j++);
    ret[0] = j;
    int k = 0;
    for (int i = 1; i < m; i++) {
        int len = k + ret[k], l = next[i - k];
        if (l < len - i)
            ret[i] = l;
        else {
            for (j = max(0, len - i); j < n && i + j < m && a[j] == b[i + j]; j++);
            ret[i] = j;
            k = i;
        }
    }
}
