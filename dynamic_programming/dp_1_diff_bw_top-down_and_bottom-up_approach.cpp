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
 
ll gcd(ll a,ll b) {if (a==0) return b;return gcd(b%a,a);}

// top down approach
ll findOperationByMemoization(ll* memo,ll n)
{
    if(memo[n]!=-1)
        return memo[n];
        
    ll q1=INT_MAX;
    ll q2=INT_MAX;
    ll q3=INT_MAX;
    
    if(n%3==0) 
        q1= 1+findOperationByMemoization(memo,n/3);
    if(n%2==0) 
        q2= 1+findOperationByMemoization(memo,n/2);
    q3= 1+findOperationByMemoization(memo,n-1);
    
    memo[n]=min(q1,min(q2,q3));
    return memo[n];
    
}

// bottom-up approach
ll findOperationsByDP(ll* dp,ll n)
{
    dp[0]=0;
    dp[1]=0;
    dp[2]=1;
    dp[3]=1;
    for(ll i=4;i<=n;i++)
    {
        ll q1=INT_MAX;
        ll q2=INT_MAX;
        ll q3=INT_MAX;
        if(i%3==0) q1=(1+dp[i/3]);
        if(i%2==0) q2=(1+dp[i/2]);
        q3=(1+dp[i-1]);
        dp[i]=min(q1,min(q2,q3));
    }
    return dp[n];
}

int main() 
{
    ll n;
    cin>>n;
    
    // top-down approach
    ll memo[n+1];
    fill(memo,memo+n+1,-1);
    memo[0]=0;
    memo[1]=0;
    memo[2]=1;
    memo[3]=1;
    cout<<findOperationByMemoization(memo,n)<<"\n";
    
    //bottom-up approach
    ll dp[n+1];
    fill(dp,dp+n+1,-1);
    cout<<findOperationsByDP(dp,n)<<"\n";
    
    return 0;
}
