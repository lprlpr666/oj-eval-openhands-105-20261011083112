#include <iostream>
#include <vector>
#include <iomanip>
#include <cstring>

using namespace std;

double dp[25][25]; // dp[k][t] = expected days to eat exactly t apples starting from k apples

double solve(int k, int t) {
    if (dp[k][t] >= -0.5) return dp[k][t];
    
    if (t == 0) {
        dp[k][t] = 0;
        return 0;
    }
    
    if (k == 0) {
        dp[k][t] = 1e9; // impossible
        return 1e9;
    }
    
    double expected = 1.0; // current day
    double sum = 0.0;
    int valid_options = 0;
    
    for (int i = 1; i <= k; i++) {
        if (t - i >= 0) {
            sum += solve(k - i, t - i);
            valid_options++;
        }
    }
    
    if (valid_options > 0) {
        expected += sum / k;
    } else {
        expected = 1e9; // impossible
    }
    
    dp[k][t] = expected;
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