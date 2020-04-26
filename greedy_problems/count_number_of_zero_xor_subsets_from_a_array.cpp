#include<bits/stdc++.h>
using namespace std;
#define ll long long int
// Returns count of subsets of arr[] with XOR value equals
// to k.
ll subsetXOR(ll arr[], ll n, ll k)
{
    // Find maximum element in arr[]
    ll max_ele = arr[0];
    for (ll i=1; i<n; i++)
       if (arr[i] > max_ele)
           max_ele = arr[i];
 
    // Maximum possible XOR value
    ll m = (1 << (ll)(log2(max_ele) + 1) ) - 1;
 
    // The value of dp[i][j] is the number of subsets having
    // XOR of their elements as j from the set arr[0...i-1]
    ll dp[n+1][m+1];
 
    // Initializing all the values of dp[i][j] as 0
    for (ll i=0; i<=n; i++)
        for (ll j=0; j<=m; j++)
            dp[i][j] = 0;
 
    // The xor of empty subset is 0
    dp[0][0] = 1;
 
    // Fill the dp table
    for (ll i=1; i<=n; i++)
        for (ll j=0; j<=m; j++)
            dp[i][j] = dp[i-1][j] + dp[i-1][j^arr[i-1]];
 
    //  The answer is the number of subset from set
    //  arr[0..n-1] having XOR of elements as k
    return dp[n][k];
}
 
// Driver program to test above function
int main()
{
    ll n; cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++) cin>>arr[i];
    cout <<subsetXOR(arr, n, 0)-1<<endl;
    return 0;
}
