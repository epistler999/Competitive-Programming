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


ll maxProfit(ll* arr, ll length)
{
    if(length==0) return 0;
    ll best=0;
    for(ll i=1;i<=length;i++)
    {
        ll netProfit=arr[i]+maxProfit(arr,length-i);
        best=max(best,netProfit);
    }
    return best;
}

ll maxProfitDp(ll *arr,ll totlength)
{
    ll dp[totlength+1]={0};
    for(ll len=1;len<=totlength;len++)
    {
        ll best=0;
        for(ll cut=1;cut<=len;cut++)
        {
            ll netprofit=arr[cut]+dp[len-cut];
            best=max(netprofit,best);
        }
        dp[len]=best;
    }
    return  dp[totlength];
}


int main()
{
    ll n;
    cin>>n;
    ll arr[n+1];
    for(ll i=1;i<=n;i++)
        cin>>arr[i];
    
    cout<<maxProfit(arr,n)<<"\n";   
    return 0;
}
