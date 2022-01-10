#include <bits/stdc++.h>
using namespace std;

int coingChange(int n, vector<int> &dp)
{
    if (n <= 0)
        return 0;

    if (dp[n - 1] == -1)
        dp[n - 1] = coingChange(n - 1, dp);
    if (dp[n - 5] == -1)
        dp[n - 5] = coingChange(n - 5, dp);
    if (dp[n - 7] == -1)
        dp[n - 7] = coingChange(n - 7, dp);

    return min(dp[n - 1], min(dp[n - 5], dp[n - 7])) + 1;
}

int main()
{
    int coins; cin>> coins;
    vector<int> denomination(coins);
    for (auto &i:denomination)cin>>i; 


    int n;
    cin >> n;   
    vector<int> dp(n + 1, -1);
    cout << coingChange(n, dp);
}