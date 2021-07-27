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

class node
{
  public:
  int u,v,w;
  node(int u,int v,int w)
  {
    this->u=u;
    this->v=v;
    this->w=w;
  }  
};

bool cmp(node a,node b)
{return a.w<b.w;}

int find(int x,vector<int>&parent)
{
  if(parent[x]==x)
    return x;
  return parent[x]=find(parent[x],parent);
}

void Union(int x,int y,vector<int>&parent,vector<int>&rank)
{
  x=find(x,parent);
  y=find(y,parent);
  if(rank[y]>rank[x])
    parent[x]=y;
  else if(rank[y]<rank[x])
    parent[y]=x;
  else
  {
    parent[y]=x;
    rank[x]++;
  }
}

void solve()
{
  int n,e;
  cin>>n>>e;
  vector<node>graph;
  fo(0,e)
  {
    int u,v,w;
    cin>>u>>v>>w;
    graph.pb(node(u,v,w));
  }
  sort(all(graph),cmp);
  vector<int>parent(n);
  vector<int>rank(n,0);
  fo(0,n)
  parent[i]=i;
  int cost=0;
  vector<pii>mst;
  for(auto i:graph)
  {
    if(find(i.v,parent)!=find(i.u,parent))
    {
      cost+=i.w;
      mst.pb({i.u,i.v});
      Union(i.u,i.v,parent,rank);
    }
  }
  cout<<"cost "<<cost<<endl;
  debug(mst);
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