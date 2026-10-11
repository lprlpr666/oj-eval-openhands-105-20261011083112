#include <iostream>
#include <vector>
#include <iomanip>
#include <cstring>

using namespace std;

double dp[25][25]; // dp[k][eaten] = expected remaining days when we have k apples left and have eaten 'eaten' apples so far

double solve(int k, int eaten, int m) {
    if (dp[k][eaten] >= -0.5) return dp[k][eaten];
    
    if (eaten >= m) {
        dp[k][eaten] = 0;
        return 0;
    }
    
    if (k == 0) {
        dp[k][eaten] = 1e9; // impossible to eat more if no apples left
        return 1e9;
    }
    
    double expected = 1.0; // current day
    double sum = 0.0;
    
    for (int i = 1; i <= k; i++) {
        sum += solve(k - i, min(eaten + i, m), m);
    }
    
    expected += sum / k;
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