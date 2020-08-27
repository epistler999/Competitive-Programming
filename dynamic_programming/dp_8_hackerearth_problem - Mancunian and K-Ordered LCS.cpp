// hackerEarth problem - Mancunian and K-Ordered LCS

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

ll dp[100][100][8];

ll Solve(ll *arr1,ll *arr2,ll n,ll m,ll i,ll j,ll k)
{
    // if any of he string is finished, ans is 0
    if(i==n||j==m)
        return 0;
    
    // if already computed
    if(dp[i][j][k]!=-1)
        return dp[i][j][k];
    
    if(arr1[i]==arr2[j])
        dp[i][j][k]=(1+Solve(arr1,arr2,n,m,i+1,j+1,k));
    else
    {
        if(k>0)
        {
            // converted jth character in arr2 to ith character in arr1
            dp[i][j][k]=(1+Solve(arr1,arr2,n,m,i+1,j+1,k-1));
        }
        dp[i][j][k]=max(dp[i][j][k],(Solve(arr1,arr2,n,m,i,j+1,k)));
        dp[i][j][k]=max(dp[i][j][k],(Solve(arr1,arr2,n,m,i+1,j,k)));
    }
    return dp[i][j][k];
}



int main()
{
    initial(dp,-1);
    ll n,m,k;
    cin>>n>>m>>k;
    
    ll arr1[n],arr2[m];
    
    lp0(i,0,n)
        cin>>arr1[i];
    lp0(i,0,n)
        cin>>arr2[i];    
    

    cout<<Solve(arr1,arr2,n,m,0,0,k)<<"\n";
    
    return 0;
}