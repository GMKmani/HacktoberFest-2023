#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int>& wt, vector<int>& val, int n, int W) {
     vector<int> prev(W + 1, 0);

     for (int i = wt[0]; i <= W; i++) {
        prev[i] = val[0];
    }

    // Fill in the DP table using a bottom-up approach
    for (int ind = 1; ind < n; ind++) {
        for (int cap = W; cap >= 0; cap--) {
            
            int notTaken = prev[cap];
            int taken = INT_MIN;

            
            if (wt[ind] <= cap) {
                taken = val[ind] + prev[cap - wt[ind]];
            }

            
            prev[cap] = max(notTaken, taken);
        }
    }

    return prev[W];
}

int main() {
    vector<int> wt = {1, 2, 4, 5};
    vector<int> val = {5, 4, 8, 6};
    int W = 5;
    int n = wt.size();

    cout << "The Maximum value of items the thief can steal is " << knapsack(wt, val, n, W);

    return 0;
}
