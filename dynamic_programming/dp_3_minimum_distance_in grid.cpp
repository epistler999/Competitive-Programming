#include<iostream>
#include<math.h>
#include<vector>
#include<stack>
#include<list>
#include<queue>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<string>
#include<iterator>
#include<numeric>
#include<functional>
#include<utility>
#include<memory>
#include <cstdlib>
#include<bits/stdc++.h>
using namespace std;
 
#define     fast()              ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define     ll                  long long int
#define     test()              ll t; cin>>t; while(t--) 
#define     lp0(i,begin,end)    for(ll i=begin;i<end;i++)
#define     lp1(i,begin,end)    for(ll i=begin;i<=end;i++)
#define     rlp(i,begin,end)    for(ll i=end;i>=begin;i--)
#define     prec(n)             fixed<<setprecision(n)
#define     initial(a,i)        memset(a,i,sizeof(a))
#define     pb                  push_back
#define     PI                  3.1415926535897932384626433832795
#define     MOD                 1000000007
#define     F                   first
#define     S                   second
#define     all(a)              (a).begin(),(a).end()
#define     BPC(x)              __builtin_popcountll(x)
#define     gcd(a,b)            __gcd(a,b)

// Solution
ll findMinimumPath(ll arr[][100],ll n,ll m)
{
    ll dp[100][100]={0};
    dp[0][0]=arr[0][0];
 
    for(ll col=1;col<m;col++)
        dp[0][col]=dp[0][col-1]+arr[0][col];
 
    for(ll row=1;row<n;row++)
        dp[row][0]=dp[row-1][0]+arr[row][0];
    
    for(ll i=1;i<n;i++)
    {
        for(ll j=1;j<m;j++)
        {
            dp[i][j]=min(dp[i][j-1],dp[i-1][j])+arr[i][j];
        }
    }
    
    return dp[n-1][m-1];
}

// Driver Function
int main() 
{
    ll n,m;
    cin>>n>>m;
    
    ll arr[100][100]={0};
    for(ll i=0;i<n;i++)
        for(ll j=0;j<m;j++)
            cin>>arr[i][j];
    
    cout<<findMinimumPath(arr,n,m)<<"\n";
    
    return 0;
}
