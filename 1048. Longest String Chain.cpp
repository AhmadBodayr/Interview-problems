// leetcode
class Solution {
public:
    vector<vector<int>> graph;
    vector<int> memo;
    int solve(int index) {
        int& out = memo[index];
        if(out) return out;
        out = 1;
        for(auto curr: graph[index]) {
            out = max(out, 1 + solve(curr));
        }
        return out;
    }
    
    int longestStrChain(vector<string>& words) {
        int n = (int) words.size();
        graph.clear(), graph.resize(n);
        memo.clear(), memo.resize(n, 0);
        map<string, int> index;
        for(int i = 0; i < n; i++) index[words[i]] = i;
        for(int j = 0; j < n; j++) {
            string s = words[j];
            int m = (int) s.size();
            for(int i = 0; i < m; i++) {
                string temp = s.substr(0, i) + s.substr(i + 1);
                if(index.find(temp) != index.end()) {
                    graph[j].push_back(index[temp]);
                }
            }
        }
        int out = 0;
        for(int i = 0; i < n; i++) {
            out = max(out, solve(i));
        }
        return out;
    }
};