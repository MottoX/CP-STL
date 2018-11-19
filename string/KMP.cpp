const int N = 1000010;
const int M = 100010;
char txt[N], pat[M];
int next[M];

int KMP(char *word, char *text) {
    vector<int> pos;
    int n = strlen(word);
    int m = strlen(text);
    memset(next, 0, sizeof(next));
    int i, j;
    for (i = 1; i < n; i++) {
        j = i;
        while (j) {
            j = next[j];
            if (word[i] == word[j]) {
                next[i + 1] = j + 1;
                break;
            }
        }
    }
    for (i = 0, j = 0; i < m; i++) {
        if (j < n && text[i] == word[j]) j++;
        else {
            while (j) {
                j = next[j];
                if (text[i] == word[j]) {
                    j++;
                    break;
                }
            }
        }
        if (j == n) pos.push_back(i - n + 1);
    }
    return pos.size();
}
