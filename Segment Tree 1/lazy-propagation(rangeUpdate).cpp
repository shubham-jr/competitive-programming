#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define INF 1e18
#define nline "\n"
#define pb push_back
#define popb pop_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define fo(x,y) for(int i=x;i<y;i++)
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
vector<int>segment;
vector<int>lazy(15);
void built(vector<int>&v,int i,int low,int high)
{
  if(low==high)
  {
    segment[i]=v[low];
    return;
  }
  int mid=high+low>>1;
  built(v,2*i+1,low,mid);
  built(v,2*i+2,mid+1,high);
  segment[i]=segment[2*i+1]+segment[2*i+2];
}

int query(int i,int low,int high,int l,int h)
{
  if(lazy[i]!=0)
  {
    segment[i]+=(high-low+1)*lazy[i];
    if(low=!high)
    {
      lazy[2*i+1]+=lazy[i];
      lazy[2*i+2]+=lazy[i];
    }
    lazy[i]=0;
  }
  if(l<=low&&high<=h)
    return segment[i];
  if(low>h||high<l)
    return 0;
  int mid=high+low>>1;
  return query(2*i+1,low,mid,l,h)+query(2*i+2,mid+1,high,l,h);
}

void rangeUpdate(int i,int low,int high,int l,int h,int val)
{
  if(lazy[i]!=0)
  {
    segment[i]+=lazy[i]*(high-low+1);
    if(low!=high)
    lazy[2*i+1]+=lazy[i],lazy[2*i+2]+=lazy[i];
    lazy[i]=0;
  }
  if(low>=l&&high<=h)
  {
    segment[i]+=val*(high-low+1);
    if(low!=high)
    lazy[2*i+1]+=val,lazy[2*i+2]+=val;
    return;
  }
  if(low>h||high<l)
    return;
  int mid=high+low>>1;
  rangeUpdate(2*i+1,low,mid,l,h,val);
  rangeUpdate(2*i+2,mid+1,high,l,h,val);
  segment[i]=segment[2*i+1]+segment[2*i+2];
}

void solve()
{
  int n;cin>>n;
  vector<int>v(n);
  segment.resize(4*n);
  fo(0,n)
  cin>>v[i];
  built(v,0,0,n-1);
  debug(segment);
  int q,update_l,update_r,l,r,val;
  cin>>q>>update_l>>update_r>>val;
  rangeUpdate(0,0,n-1,update_l,update_r,val);
  debug(segment);
  debug(lazy);
  while(q--)
  {
    cin>>l>>r;
    cout<<query(0,0,n-1,l,r)<<nline;
  }
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