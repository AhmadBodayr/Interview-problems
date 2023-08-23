// geekforgeeks
#define inf 100000005
class Solution {
    vector<vector<int>> memo;
    
    
    vector<int> combinations(int r, int n) {
    vector<int> subsets;
    combinations(0, 0, r, n, subsets);
    return subsets;
  }


    void combinations(int set, int at, int r, int n, vector<int>& subsets) {

    int elementsLeftToPick = n - at;
    if (elementsLeftToPick < r) return;
    if (r == 0) {
      subsets.push_back(set);
    } else {
      for (int i = at; i < n; i++) {
        // Try including this element
        set ^= (1 << i);

        combinations(set, i + 1, r - 1, n, subsets);
        set ^= (1 << i);
      }
    }
  }
public:
    int total_cost(vector<vector<int>> cost) {
        int n = (int) cost.size();
        const int p = (1 << n);
        if(n == 1) return 0;
        memo.clear(), memo.resize(n, vector<int>(p, inf));
        for(int i = 1; i < n; i++) {
            memo[i][(1 << 0) | (1 << i)] = cost[0][i];
        }
        for(int r = 3; r <= n; r++) {
            for(auto subset: combinations(r, n)) {
                if(!(subset & (1 << 0))) continue;
                for(int next = 1; next < n; next++) {
                    if(!(subset & (1 << next))) continue;
                    int& val = memo[next][subset];
                    int sub = subset & ~(1 << next);
                    for(int e = 1; e < n; e++) {
                        if(sub & (1 << e)) {
                            val = min(val, memo[e][sub] + cost[e][next]);
                        }
                    }
                }
            }
        }
        int out = inf;
        for(int i = 1; i < n; i++) {
            out = min(out, memo[i][p - 1] + cost[i][0]);
        }
        return out;
    }
};