#include <iostream>
#include <vector>
using namespace std;

int main() {
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500};

    int n;
    cout << "Enter the change amount: ";
    cin >> n;

    vector<int> dp(n + 1);
    vector<int> selectedCoin(n + 1);

    dp[0] = 0;

    for (int k = 1; k <= n; k++) {
        dp[k] = 1000;

        for (int i = 0; i < 9; i++) {
            if (coins[i] <= k) {

                if (dp[k - coins[i]] + 1 < dp[k]) {
                    dp[k] = dp[k - coins[i]] + 1;
                    selectedCoin[k] = coins[i];
                }

            }
        }
    }

    cout << "Minimum number of coins: " << dp[n] << endl;

    cout << "Coins used: ";

    int k = n;

    while (k > 0) {
        cout << selectedCoin[k] << " ";

        k = k - selectedCoin[k];
    }

    cout << endl;

    return 0;
}

