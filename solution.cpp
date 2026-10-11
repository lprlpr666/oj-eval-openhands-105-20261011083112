#include <iostream>
#include <vector>
#include <iomanip>
#include <cstring>

using namespace std;

double dp[25][25]; // dp[k][eaten] = expected remaining days when we have k apples left and have eaten 'eaten' apples so far

double solve(int k, int eaten, int m) {
    if (eaten >= m) return 0.0;
    if (k == 0) return 0.0; // shouldn't happen for valid inputs
    
    if (dp[k][eaten] >= -0.5) return dp[k][eaten];
    
    double expected = 1.0;
    for (int i = 1; i <= k; i++) {
        expected += solve(k - i, eaten + i, m) / k;
    }
    
    dp[k][eaten] = expected;
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
    
    double result = solve(n, 0, m);
    
    cout << fixed << setprecision(2) << result << endl;
    
    return 0;
}