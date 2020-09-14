// minimum number of operation to get output string from input string 

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
ll minOperations(string inp,string out)
{
    ll inp1=inp.length();
    ll out1=out.length();
    ll dp[101][101]={0};
    
    dp[0][0]=0;
    
    // base case
    for(ll col=1;col<=out1;col++) dp[0][col]=dp[0][col-1]+1;
    for(ll row=1;row<=inp1;row++) dp[row][0]=dp[row-1][0]+1;
    
    // dp
    for(ll i=1;i<=inp1;i++)
    {
        for(ll j=1;j<=out1;j++)
        {
            //replacement 
            ll q1=dp[i-1][j-1];
            
            // deletion
            ll q2=dp[i-1][j];
            
            // insertion
            ll q3=dp[i][j-1];
            
            dp[i][j] = min(q1,min(q2,q3)) + (inp[i-1]!=out[j-1]);
        }
    }
    return dp[inp1][out1];
    
}


// Driver Function
int main()
{
    string s1,s2;
    cin>>s1;
    cin>>s2;
    cout<<minOperations(s1,s2);
    return 0;
}
