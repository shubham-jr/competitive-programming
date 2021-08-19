#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define INF 1e18
#define mod 1000000007
#define nline "\n"
#define pb push_back
#define popb pop_back
#define mp make_pair
#define rz resize
#define all(v) v.begin(), v.end()
#define fo(x,y) for(int i=x;i<y;i++)
#define fo1(x,y) for(int i=x;i<y;i++)
#define fo2(x,y) for(int j=x;j<y;j++)
#define pii pair<int,int>
#define tc int t;cin>>t;while(t--)
#ifndef ONLINE_JUDGE
#define debug(x)cerr<<#x<<" ";vprint(x);cerr<<endl;
#define debug2(x,y)cerr<<#x<<" ";vprint(x);cerr<<" ";cerr<<#y<<" ";vprint(y);cerr<<endl;
#else
#define debug(x);
#define debug2(x,y);
#endif
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
void vprint(int a){cerr<<a;}
void vprint(ll a){cerr<<a;}
void vprint(ull a){cerr<<a;}
void vprint(char a){cerr<<a;}
void vprint(double a){cerr<<a;}
void vprint(bool a){cerr<<a;}
void vprint(string a){cerr<<a;}
void vprint(long double a){cerr<<a;}
template<class T>void vprint(vector<T> v1){cerr<<"[";for(T i:v1){vprint(i);cerr<<" ";}cerr<<"]";}
template<class T>void vprint(set<T>s1){cerr<<"[";for(T i:s1){vprint(i);cerr<<" ";}cerr<<"]";}
template<class T>void vprint(multiset<T>s1){cerr<<"[";for(T i:s1){vprint(i);cerr<<" ";}cerr<<"]";}
template<class T,class P>void vprint(pair<T,P>p1){cerr<<"{";vprint(p1.ff);cerr<<",";vprint(p1.ss);cerr<<"}";}
template<class T,class P>void vprint(map<T,P>m1){cerr<<"[";for(auto i:m1){vprint(i);cerr<<" ";}cerr<<"]";}
template<class T>void vprint(vector<vector<T>>vec){for(int i=0;i<vec.size();i++){vprint(vec[i]);cerr<<endl;}}
template<class T,class P>void vprint(vector<pair<T,P>>v){cerr<<"[";for(auto i:v)vprint(i);cerr<<"]";cerr<<endl;}
template<class T,class P>void vprint(set<pair<T,P>>s){cerr<<"[";for(auto i:s)vprint(i);cerr<<"]";}
template<class T>void vprint(list<T>l){cerr<<"[";for(auto i:l){vprint(i);cerr<<" ";}cerr<<"]";}
template<class T,class P>void vprint(list<pair<T,P>>l){cerr<<"[";for(auto i:l)vprint(i);cerr<<"]";}
template<class T,class P>void vprint(unordered_map<T,P>m){cerr<<"[";for(auto i:m)vprint(i);cerr<<"]";}
template<class T,class P>void vprint(map<T,vector<pair<T,P>>>graph){for(auto i:graph){cerr<<"[";vprint(i.ff);cerr<<":";vprint(i.ss);cerr<<"]";}}
template<class T>void swap(T *a,T *b){T tmp;tmp=*a;*a=*b;*b=tmp;}
 
int ways(vector<int>&v,vector<vector<int>>&dp,int i,int x,int bound)
{
 
 //we take index from 1 to n
  //so at index 0 we return 0
   //also x varies from 1 to m
    //so if x==0 then also we return 0 
   if(i==0||x==0)
   return dp[i][x]=0; 
 
// x varies from [1,m] 
 // so it can't be greater than bound(m)
 
   if(x>bound)
   return dp[i][x]=0; 
 
// if we have only one index 
   if(i==1)
   {
    // if there will be a zero means
    // we can put any number b/w [1,m] on that index
    // also if we have x,on that index 
    // in both case we return 1
     if(v[i]==x||v[i]==0)
     return dp[i][x]=1;
     else //else we return 0 if it is fixed
     return dp[i][x]=0;   
   }
 
// memoization
   if(dp[i][x]!=-1)
   return dp[i][x]; 
 
   int ans=0;
   
   // if we have index greater than 1
   // then we have to check on the last index
   // whether it is 0 or x
   // in both case we call our recursive function
 
// defination of our recursive function
   //ways(i,x) means,no. of ways, if we
    // put x on the ith index
 
   if(v[i]==x||v[i]==0)
   ans=((ways(v,dp,i-1,x-1,bound)%mod+ways(v,dp,i-1,x,bound)%mod)%mod+ways(v,dp,i-1,x+1,bound)%mod)%mod;
   else
   return dp[i][x]=0; //return 0 if it is fixed
 
   return dp[i][x]=ans; //return no. of ways
}
 
void solve() 
{
 
  int n,m;
  cin>>n>>m;
 
  vector<int>v(n+1);
 
  fo(1,n+1)
  cin>>v[i];
 
  vector<vector<int>>dp(n+2,vector<int>(m+2,-1));
 
 
  debug(v);
 
  fo(1,m+1)
  ways(v,dp,n,i,m);
 
  int ans=0;

  fo(1,m+1)
  ans=(ans%mod+dp[n][i]%mod)%mod;

  cout<<ans;

  
}
 
int main() 
{
  #ifndef ONLINE_JUDGE
  freopen("error.txt","w",stderr);
  #endif
  fastio();  
  solve();
  return 0;
}
