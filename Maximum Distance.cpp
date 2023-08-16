// Coding Ninjas.com problem
#include <bits/stdc++.h>
int maxDiff(vector<int> &a, int n) {
    vector<int> post(n);
    post[n - 1] = a[n -1];
    for(int i = n - 2; i >= 0; i--) post[i] = max(post[i + 1], a[i]);
    int i = 0, j = 0, out = 0;
    while(i < n && j < n) {
        if(a[i] <= post[j]) {
            out = max(out, j - i), j++;
        } else i++;
    }
    return out;
}


