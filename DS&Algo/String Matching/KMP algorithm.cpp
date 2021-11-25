#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize "trapv"    
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

class lps
{
  int i,j,size;
  string str;
  public:
    lps(string str)
    {
      i=1;
      j=0;
      size=str.size();
      this->str=str;
    }
    void find_lps(vector<int>&,string&);
    int KMP(string&,string&,vector<int>&);
};


void lps::find_lps(vector<int>&v,string &str)
{
  int i=1,j=0;
    int size=str.size();
  while(i<size)
  {
    if(str[j]==str[i]) 
    {
      v[i]=j+1;
      i++;j++;
    }else{
      if(j==0)
      {
        i++;
      }
      else
      {
        j=v[j-1]; 
      }
    }
  }
}

int lps::KMP(string &str,string &tmp,vector<int>&v)
{
    int i=0,j=-1,ans=0;
 
  while(i<=str.size())
  {
    debug2(tmp[j+1],str[i]); 
   
    if(tmp[j+1]==str[i]) 
    {
      i++;j++;

      if(j>=(int)tmp.size()-1)
      {ans++;break;}
    }
    else{
      if(j==-1)
      {
        i++;
      }
      else
      {
        j=v[j]-1; 
      }

    }
  }
  return ans;
}


void solve()
{
  string str,tmp; 
  cin>>str;
  cin.ignore();
  cin>>tmp; 

  
  vector<int>v(tmp.size());

  lps obj(tmp);

  obj.find_lps(v,tmp); 
  
  if(obj.KMP(str,tmp,v))
    cout<<"Pattern Found...."<<endl;
    else
    cout<<"Pattern not Found...."<<endl;
  debug(v);
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