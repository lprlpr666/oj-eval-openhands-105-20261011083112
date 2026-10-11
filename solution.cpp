#include <iostream>
#include <vector>
#include <iomanip>
#include <cstring>

using namespace std;

double dp[25][25]; // dp[k][eaten] = expected remaining days when we have k apples left and have eaten 'eaten' apples so far

int main() {
    int n, m;
    cin >> n >> m;
    
    // Initialize DP table
    for (int i = 0; i <= 20; i++) {
        for (int j = 0; j <= 20; j++) {
            dp[i][j] = 0.0;
        }
    }
    
    // Base case: if we've already eaten m or more apples, expected remaining days is 0
    for (int k = 0; k <= n; k++) {
        for (int eaten = m; eaten <= n; eaten++) {
            dp[k][eaten] = 0.0;
        }
    }
    
    // Fill DP table bottom-up
    for (int eaten = m - 1; eaten >= 0; eaten--) {
        for (int k = 1; k <= n; k++) {
            double sum = 0.0;
            for (int i = 1; i <= k; i++) {
                int new_eaten = min(eaten + i, n);
                int new_k = k - i;
                sum += dp[new_k][new_eaten];
            }
            dp[k][eaten] = 1.0 + sum / k;
        }
    }
    
    double result = dp[n][0];
    
    cout << fixed << setprecision(2) << result << endl;
    
    return 0;
}