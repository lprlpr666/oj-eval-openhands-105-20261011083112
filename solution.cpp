#include <iostream>
#include <vector>
#include <iomanip>
#include <cstring>

using namespace std;

double dp[25][25]; // dp[k][remaining] = expected days to eat exactly 'remaining' more apples when we have k apples left

double solve(int k, int remaining) {
    if (remaining <= 0) return 0.0;
    if (k == 0) return 1e9; // impossible
    if (k < remaining) return 1e9; // not enough apples left
    
    if (dp[k][remaining] >= -0.5) return dp[k][remaining];
    
    double expected = 1.0;
    double valid_sum = 0.0;
    int valid_count = 0;
    
    for (int i = 1; i <= k; i++) {
        if (i <= remaining) {
            valid_sum += solve(k - i, remaining - i);
            valid_count++;
        } else {
            // if we eat more than needed, this path doesn't contribute to the expectation
            // since we're looking for exactly m apples eaten
        }
    }
    
    if (valid_count > 0) {
        expected += valid_sum / k;
    } else {
        expected = 1e9; // impossible
    }
    
    dp[k][remaining] = expected;
    return expected;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    // Initialize DP table
    for (int i = 0; i <= 20; i++) {
        for (int j = 0; j <= 20; j++) {
            dp[i][j] = -1.0;
        }
    }
    
    double result = solve(n, m);
    
    cout << fixed << setprecision(2) << result << endl;
    
    return 0;
}