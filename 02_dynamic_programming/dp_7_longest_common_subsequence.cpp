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
ll longestCommonSubsequence(string s1,string s2)
{
    ll l1=s1.length();
    ll l2=s2.length();
    ll dp[100][100]={0};
    for(ll i=1;i<=l1;i++)
    {
        for(ll j=1;j<=l2;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[l1][l2];
    
}


// Driver function
int main()
{
    string s1,s2;
    cin>>s1;
    cin>>s2;
    cout<<longestCommonSubsequence(s1,s2)<<"\n";
    return 0;
}
