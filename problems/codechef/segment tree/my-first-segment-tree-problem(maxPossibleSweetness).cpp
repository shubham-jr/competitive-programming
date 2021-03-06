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
vector<ll>segment;

void built(vector<pii>&v,ll i,ll low,ll high)
{
  if(low==high)
  {
    segment[i]=v[low].ss;
    return;
  }
  ll mid=low+high>>1;
  built(v,2*i+1,low,mid);
  built(v,2*i+2,mid+1,high);
  segment[i]=max(segment[2*i+1],segment[2*i+2]);
}

ll query(ll i,ll low,ll high,ll l,ll h)
{
  if(l<0||h<0) 
    return 0;
  if(l<=low&&high<=h)
    return segment[i];
  if(low>h||high<l)
    return -1e18;
  ll mid=low+high>>1;
  ll left=query(2*i+1,low,mid,l,h);
  ll right=query(2*i+2,mid+1,high,l,h);
  return max(left,right);
}

void solve()
{
  ll n,d;
  cin>>n>>d;
  vector<pii>v(n);
  segment.resize(4*n);
  fo(0,n)
  { 
    ll p;
    cin>>p;
    v[i].ff=p;
  }
  fo(0,n)
  { 
    ll s;
    cin>>s;
    v[i].ss=s;
  }
  sort(all(v));
  debug(v);
  built(v,0,0,n-1);

  ll maxi=0;ll remain=0,beauty=0;
  fo(0,n)
  {
    if(d<v[i].ff)
      continue;
    ll till=-1;
    remain=d-v[i].ff;
    beauty=v[i].ss; 
    ll l=0,h=n-1;
    while(l<=h)
    {
      ll mid=l+h>>1;
      if(v[mid].ff<=remain)
      {
        till=mid;
        l=mid+1;
      }
      else 
        h=mid-1;
    }
    if(till==-1){

    }else 
    if(till>=i)
      {
        beauty+=max(query(0,0,n-1,0,i-1),query(0,0,n-1,i+1,till));
      }
    else
      beauty+=query(0,0,n-1,0,till);
      maxi=max(maxi,beauty);
  }
cout<<maxi<<endl;
}

int main() 
{
  #ifndef ONLINE_JUDGE
  freopen("error.txt","w",stderr);
  #endif
  fastio();  
  tc solve();
  return 0;
}

// problem link https://www.codechef.com/problems/MAXSWT