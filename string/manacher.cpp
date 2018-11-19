char s[N];
char t[N];
int p[N];

int manacher(char *s, char *t) {
    int n = strlen(s);
    t[0] = '#';
    for (int i = 0, j = 1; i < n; i++, j += 2) {
        t[j] = s[i];
        t[j + 1] = '#';
    }
    int id = 0, mx = 0, ret = 1;
    int m = 2 * n + 1;
    for (int i = 0; i < m; i++) {
        if (mx > i) {
            p[i] = min(p[2 * id - i], mx - i);
        } else {
            p[i] = 1;
        }
        while (i - p[i] >= 0 && i + p[i] < m && t[i - p[i]] == t[i + p[i]]) p[i]++;
        if (i + p[i] > mx) {
            mx = i + p[i];
            id = i;
            ret = max(ret, p[i]);
        }
    }
    return ret - 1;
}