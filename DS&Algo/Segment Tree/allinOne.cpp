#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize "trapv"        
#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const int mod=1000000007;
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define INF 1e18
#define nline "\n"
#define pb push_back
#define popb pop_back
#define mp make_pair
#define rz resize
#define typeof(i) decltype(i)::foo= 1;
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
template<class T,class P,class Q>void vprint(map<T,P,greater<Q>>m){cerr<<"[";for(auto i:m){vprint(i);cerr<<" ";}cerr<<"]";}
template<class T>void vprint(vector<vector<T>>vec){for(int i=0;i<vec.size();i++){vprint(vec[i]);cerr<<endl;}}
template<class T,class P>void vprint(vector<pair<T,P>>v){cerr<<"[";for(auto i:v)vprint(i);cerr<<"]";cerr<<endl;}
template<class T,class P>void vprint(set<pair<T,P>>s){cerr<<"[";for(auto i:s)vprint(i);cerr<<"]";}
template<class T>void vprint(list<T>l){cerr<<"[";for(auto i:l){vprint(i);cerr<<" ";}cerr<<"]";}
template<class T,class P>void vprint(list<pair<T,P>>l){cerr<<"[";for(auto i:l)vprint(i);cerr<<"]";}
template<class T,class P>void vprint(unordered_map<T,P>m){cerr<<"[";for(auto i:m)vprint(i);cerr<<"]";}
template<class T,class P>void vprint(map<T,vector<pair<T,P>>>graph){for(auto i:graph){cerr<<"[";vprint(i.ff);cerr<<":";vprint(i.ss);cerr<<"]";}}
template<class T,class P>void vprint(multimap<T,P>m){cerr<<"[";for(auto i:m){vprint(i);cerr<<" ";}cerr<<"]";}
template<class T>void swap(T *a,T *b){T tmp;tmp=*a;*a=*b;*b=tmp;}
template<class T>int gcd(T a,T b){if(a==0)return b;return gcd(b%a,a);}
template<class T>bool checkInt(T b){b=abs(b);/*for negative numbers*/ int a=b;return b-a>0?0:1;}
template<class T>T find_nearest_square_pow(T n,char pos){if(pos=='l'){T k=floor(log2(n));return 1<<k;}else{T k=ceil(log2(n));return 1<<k;}}
template<class T>T binaryExponentiation(T a,T b,T m){T ans=1;a%=m;while(b){if(b&1)ans=(ans*a)%m;a=(a*a)%m;b=b>>1;}return ans;}

void built(vector<int>&v,vector<int>&tree,int index,int low,int high)
{
  if(low==high)
  {
    tree[index]=v[low];
    return;
  }
  int mid=(low+high)>>1;
  built(v,tree,2*index+1,low,mid);
  built(v,tree,2*index+2,mid+1,high);
  tree[index]=max(tree[2*index+1],tree[2*index+2]);
}

int query(vector<int>&v,vector<int>&tree,vector<int>&lazy,int index,int low,int high,int l,int h)
{
  if(lazy[index])
  {
    tree[index]+=lazy[index];
    if(low!=high)
    {
      lazy[2*index+1]+=lazy[index];
      lazy[2*index+2]+=lazy[index];  
    }
    lazy[index]=0;
  }  
  if(low>h||high<l)
  return INT_MIN;
  if(low>=l&&high<=h)
  return tree[index];
  int mid=low+high>>1;  
  int left=query(v,tree,lazy,2*index+1,low,mid,l,h);
  int right=query(v,tree,lazy,2*index+2,mid+1,high,l,h); 
  return max(left,right);
}

void pointUpdate(vector<int>&v,vector<int>&tree,int index,int low,int high,int pos,int val)
{
  if(low==high)
    {
      tree[index]+=val;
      v[low]+=val;
      return;
    }
  int mid=low+high>>1;
  if(mid>=pos)
    pointUpdate(v,tree,2*index+1,low,mid,pos,val);
    else
    pointUpdate(v,tree,2*index+2,mid+1,high,pos,val);
    tree[index]=max(tree[2*index+1],tree[2*index+2]);
}

void range_update(vector<int>&v,vector<int>&tree,vector<int>&lazy,int index,int low,int high,int l,int h,int val)
{
  if(lazy[index])
  {
    tree[index]+=lazy[index];
    if(low!=high)
    {
      lazy[2*index+1]+=lazy[index];
      lazy[2*index+2]+=lazy[index];
    }    
    lazy[index]=0;
  }  
  if(l>high||h<low)
    return;
  if(l<=low&&h>=high)
  {
    tree[index]+=val;
    if(low!=high)
    {
      lazy[2*index+1]+=val;
      lazy[2*index+2]+=val;
    }  
    return;
  }  
  int mid=low+high>>1;
  range_update(v,tree,lazy,2*index+1,low,mid,l,h,val);
  range_update(v,tree,lazy,2*index+2,mid+1,high,l,h,val);
  tree[index]=max(tree[2*index+1],tree[2*index+2]);
}

void solve()
{
   int n,l,h,pos,val;
   cin>>n;
   vector<int>v(n),tree(4*n),lazy(4*n);
   fo(0,n)
   cin>>v[i];
   debug(v);
   built(v,tree,0,0,n-1);
   cin>>l>>h;
   cout<<query(v,tree,lazy,0,0,n-1,l,h)<<endl;
   debug(tree);
   // pointUpdate(v,tree,0,0,n-1,pos,val);
   // cout<<query(v,tree,0,0,n-1,l,h)<<endl;
   cin>>l>>h>>val;
   range_update(v,tree,lazy,0,0,n-1,l,h,val);
   debug(tree);debug(lazy);
   cin>>l>>h;
   cout<<query(v,tree,lazy,0,0,n-1,l,h)<<endl;
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