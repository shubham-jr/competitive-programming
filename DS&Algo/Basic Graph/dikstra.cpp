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
void printGraph(map<int,vector<pii>>graph)
{
  for(auto i:graph)
  {
    cout<<i.ff<<":";
    for(auto j:i.ss)
    {
      cout<<"{"<<j.ff<<" "<<j.ss<<"}";
    }
    cout<<nline;
  }
}

void dijkstra(map<int,vector<pii>>graph,int source)
{
  map<int,int>distance;
  for(auto i:graph)
  {
    distance[i.ff]=INT_MAX;
  }
  distance[source]=0;
  set<pii>s;
  s.insert({0,source});
  while(!s.empty())
  {
    auto it=*s.begin();
    s.erase(s.begin());
    int node=it.ss;
    int currDist=it.ff;
    for(auto i:graph[node])
    {
      if(currDist+i.ss<distance[i.ff])
      {
        auto f=s.find({distance[i.ff],i.ff});
        if(f!=s.end())
         s.erase(f);
         distance[i.ff]=currDist+i.ss;
         s.insert({distance[i.ff],i.ff});
      }
    }
  }
  for(auto i:distance)
  {
    cout<<i.ff<<" "<<i.ss<<endl;
  }
}
void solve()
{
  int n,e;
  cin>>n>>e;
  map<int,vector<pii>>graph;
  fo(0,e*2)
  {
    int l,m,d;
    cin>>l>>m>>d;
    graph[l].pb({m,d});
  }
  printGraph(graph);
  dijkstra(graph,1);
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