using namespace std;
#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <algorithm>
typedef long long ll; 					
typedef unsigned long long ull; 
typedef long double ld;
#define inf 1000000000000000005

ll t;

bool possible(int r, int c, int index, string& s,vector<string>& mat) {
    if(mat[r][c] != s[index]) return 0;
    if(index == (int) s.size() - 1) return 1;
    bool out = 0;
    if (r != 0) out |= possible(r - 1, c, index + 1, s, mat);
    if (r != (int) mat.size() - 1) out |= possible(r + 1, c, index + 1, s, mat);
    if (c != 0) out |= possible(r, c - 1, index + 1, s, mat);
    if (c != (int) mat[0].size() - 1) out |= possible(r, c + 1, index + 1, s, mat);
    if(r != 0 && c != 0) out |= possible(r - 1, c - 1, index + 1, s, mat);
    if(r != (int) mat.size() - 1 && c != mat[0].size() - 1) out |= possible(r + 1, c + 1, index + 1, s, mat);
    if(r != (int) mat.size() - 1 && c != 0) out |= possible(r + 1, c - 1, index + 1, s, mat);
    if(r != 0 && c != mat[0].size() - 1) out |= possible(r - 1, c + 1, index + 1, s, mat);
    return out;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL); 	

	#ifndef ONLINE_JUDGDE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);	
	#endif
	///////////////////////////////////////////////////////////////
    cin >> t;
    while(t--) {
        int n , m, q; cin >> n >> m >> q;
        vector<string> mat(n); for(int i = 0; i < n; i++) cin >> mat[i];
        vector<string> queries(q); for(int i = 0; i < q; i++) cin >> queries[i];
        vector<int> out(q, 0);
        vector<vector<pair<int, int>>> v(26);
        for(int i = 0; i < 26; i++) {
            char c = 'A' + i;
            for(int r = 0; r < n; r++) {
                for(int c = 0; c < m; c++) 
                    if(mat[r][c] == c)
                        v[i].push_back({r, c});
            }
        }
        for(int i = 0; i < q; i++) {
            string s = queries[i];
            int start = s[0] - 'A';
            int ans = 0;
            for(int j = 0; j < (int) v[start].size(); j++) {
                ans = possible(v[start][j].first, v[start][j].second, 0, s, mat);
                if(ans) break;
            }        
            out[i] = ans;
            cout << out[i] << endl;
        }
    } // end testcases
} // end main