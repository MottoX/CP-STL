string minimal_rotation(string s) {
    int i, j, k, l;
    int n = s.length();
    s += s;
    for (i = 0, j = 1; j < n;) {
        for (k = 0; k < n && s[i + k] == s[j + k]; k++);

        if (k >= n) break;
        if (s[i + k] < s[j + k])
            j += k + 1;
        else {
            l = i + k;
            i = j;
            j = max(l, j) + 1;
        }
    }
    return s.substr(i, n);
}


string maximal_rotation(string s) {
    int i, j, k, l;
    int n = s.length();
    s += s;
    for (i = 0, j = 1; j < n;) {
        for (k = 0; k < n && s[i + k] == s[j + k]; k++);
        if (k >= n) break;
        if (s[i + k] > s[j + k])
            j += k + 1;
        else {
            l = i + k;
            i = j;
            j = max(l, j) + 1;
        }
    }
    return s.substr(i, n);
}
