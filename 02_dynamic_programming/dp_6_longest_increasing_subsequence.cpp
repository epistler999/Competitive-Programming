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


// solution function
ll longestIncreasingSubsequence(ll *arr,ll n)
{
    ll dp[100]={0};
    lp0(i,0,n)
        dp[i]=1;
    for(ll i=1;i<n;i++)
    {
        for(ll j=0;j<i;j++)
        {
            if(arr[i]>=arr[j])
            {
                ll curr=dp[j]+1;
                dp[i]=max(curr,dp[i]);
            }
        }
    }
    return *max_element(dp,dp+n);
    
}


// driver function
int main()
{
    ll n;
    cin>>n;
    ll arr[n];
    lp0(i,0,n)
        cin>>arr[i];
        
    cout<<longestIncreasingSubsequence(arr,n)<<"\n";
    
    return 0;
}
