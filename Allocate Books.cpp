// codingninjas Allocate Books
#include <bits/stdc++.h> 
long long ayushGivesNinjatest(int n, int m, vector<int> time) {	
    long long totalTime = 0;
    long long start = -1;
    for (int i = 0; i < m; i++) {
      totalTime += time[i];
      start = max(start, (long long) time[i]);
    }
    long long end = totalTime;
    long long out = LONG_MAX;
    while(start <= end) {
        long long mid = (start + end) / 2;
        long long counter = 1;
        long long temp = 0;
        for(int i = 0; i < m; i++) {
            if(temp + time[i] > mid) counter++, temp = time[i];
            else temp += time[i];
        }
        if(counter > n) start = mid + 1;
        else end = mid - 1, out = mid;
    }
    return out;
}