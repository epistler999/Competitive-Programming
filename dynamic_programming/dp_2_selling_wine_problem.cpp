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


ll memo[10000][10000];

// brute force approach
// ll maxProfit(ll *arr,ll s,ll e, ll year)
// {
//     if(s>e)
//         return 0;

//     ll q1=(arr[s]*year+maxProfit(arr,s+1,e,year+1));
//     ll q2=(arr[e]*year+maxProfit(arr,s,e-1,year+1));
//     return max(q1,q2);
// }




// memoziation technique top-down approach
// ll maxProfit(ll* arr,ll s,ll e, ll year)
// {
//     if(s>e)
//         return 0;
        
//     if(memo[s][e] != -1)
//         return memo[s][e];
        
//     ll q1=(arr[s]*year+maxProfit(arr,s+1,e,year+1));
//     ll q2=(arr[e]*year+maxProfit(arr,s,e-1,year+1));
//     memo[s][e]=max(q1,q2);
//     return memo[s][e];
// }

// dynamic programming bottom-up approach
ll maxProfit(ll* arr,ll n)
{
    ll dp[1000][1000] ={0};
    
    ll year=n;
    for(ll i=0;i<n;i++)
    {
        dp[i][i]=arr[i]*year;
    }
    year--;
    for(ll len=2;len<=n;len++)
    {
        ll col=len-1;
        ll row=0;
        while(col<n)
        {
            ll f1=dp[row][col-1] + (arr[col] *year);
            ll f2=dp[row+1][col] + (arr[row]*year);
            dp[row][col]=max(f1,f2);
            row++;
            col++;
        }
        year--;
    }
    return dp[0][n-1];
}
int main() 
{
    ll n;
    cin>>n;
    
    ll arr[n]={0};
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    
    ll s=0;
    ll e=n-1;
    ll year=0;
    memset(memo,-1,sizeof(memo));
    
    // brute force
    // cout<<maxProfit(arr,0,n-1,1);
    // cout<<"\n";
    
    // memoiazation
    // year=1;
    // cout<<maxProfit(arr,s,e,year)<<"\n";
    
    // dp -botton up approach
    cout<<maxProfit(arr,n)<<"\n";
    
    return 0;
}
