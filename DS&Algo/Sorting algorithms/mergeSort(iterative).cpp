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

void merging(vector<int>&v,vector<int>&tmp,int l,int mid,int h)
{
  int i=l;
  int j=mid+1;
  int k=l;
  while(i<=mid&&j<=h) 
  {
    if(v[i]<v[j]) 
    {
      tmp[k]=v[i];
      i++;k++;
    }
    else{
       tmp[k]=v[j];
       j++;k++;
    }
  }
  for(;i<=mid;i++)
  {
    tmp[k]=v[i];
    k++;
  }
  for(;j<=h;j++)
  {
    tmp[k]=v[j];
    k++;
  }
  fo(l,h+1)
  {
    v[i]=tmp[i];
  }
  fo(l,h+1)
  v[i]=tmp[i];
}

void mergeSort(vector<int>&v,int n)
{
  vector<int>tmp(n);
  int p,l,h,mid;
  for(p=2;p<=n;p*=2)
  {
    for(int i=0;i+p-1<n;i+=p)
    { 
      l=i;
      h=i+p-1;
      mid=l+h>>1;
      merging(v,tmp,l,mid,h); 
    }
    if(h<n-1)
    merging(v,tmp,l,h,n-1);
  }
}

void solve()
{
  int n;
  cin>>n;
  vector<int>v(n);
  fo(0,n)
  cin>>v[i];
  mergeSort(v,n);
  fo(0,n)
  cout<<v[i]<<" ";
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