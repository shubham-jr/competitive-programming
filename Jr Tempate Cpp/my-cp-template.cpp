#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize "trapv"
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const int mod = 1000000007;
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define nline cout<<endl
#define pb push_back
#define popb pop_back
#define mp make_pair
#define rz resize
#define yep cout<<"yes"<<endl
#define nope cout<<"no"<<endl
#define check debug("here")
#define VAR_NAME(x) #x
#define INF (long long)2e+18
#define typeof(i) decltype(i)::foo= 1;
#define all(v) v.begin(), v.end()
#define fo(x,y) for(int i=x;i<y;i++)
#define fo_r(x,y) for(int i=x;i>=y;i--)
#define fo1(x,y) for(int i=x;i<y;i++)
#define fo2(x,y) for(int j=x;j<y;j++)
#define pii pair<int,int>
#define tc int t;cin>>t;while(t--)
#define watch() cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n"
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
void vprint(int a) {cerr << a;}
void vprint(ll a) {cerr << a;}
void vprint(ull a) {cerr << a;}
void vprint(char a) {cerr << a;}
void vprint(double a) {cerr << a;}
void vprint(bool a) {cerr << a;}
void vprint(string a) {cerr << a;}
void vprint(long double a) {cerr << a;}
template<class T>void vprint(vector<T> v1) {cerr << "["; for (T i : v1) {vprint(i); cerr << " ";} cerr << "]";}
template<class T>void vprint(set<T>s1) {cerr << "["; for (T i : s1) {vprint(i); cerr << " ";} cerr << "]";}
template<class T>void vprint(multiset<T>s1) {cerr << "["; for (T i : s1) {vprint(i); cerr << " ";} cerr << "]";}
template<class T, class P>void vprint(pair<T, P>p1) {cerr << "{"; vprint(p1.ff); cerr << ","; vprint(p1.ss); cerr << "}";}
template<class T, class P>void vprint(map<T, P>m1) {cerr << "["; for (auto i : m1) {vprint(i); cerr << " ";} cerr << "]";}
template<class T, class P, class Q>void vprint(map<T, P, greater<Q>>m) {cerr << "["; for (auto i : m) {vprint(i); cerr << " ";} cerr << "]";}
template<class T>void vprint(vector<vector<T>>vec) {for (int i = 0; i < vec.size(); i++) {vprint(vec[i]); cerr << endl;}}
template<class T, class P>void vprint(vector<pair<T, P>>v) {cerr << "["; for (auto i : v)vprint(i); cerr << "]"; cerr << endl;}
template<class T, class P>void vprint(set<pair<T, P>>s) {cerr << "["; for (auto i : s)vprint(i); cerr << "]";}
template<class T>void vprint(list<T>l) {cerr << "["; for (auto i : l) {vprint(i); cerr << " ";} cerr << "]";}
template<class T, class P>void vprint(list<pair<T, P>>l) {cerr << "["; for (auto i : l)vprint(i); cerr << "]";}
template<class T, class P>void vprint(unordered_map<T, P>m) {cerr << "["; for (auto i : m)vprint(i); cerr << "]";}
template<class T, class P>void vprint(map<T, vector<pair<T, P>>>graph) {for (auto i : graph) {cerr << "["; vprint(i.ff); cerr << ":"; vprint(i.ss); cerr << "]";}}
template<class T, class P>void vprint(multimap<T, P>m) {cerr << "["; for (auto i : m) {vprint(i); cerr << " ";} cerr << "]";}
template<class T>void vprint(queue<T>q) {cerr << "["; int q_size = q.size(); for (int i = 0; i < q_size; i++) {vprint(q.front()); q.pop(); cerr << " ";} cerr << "]";}
template<class T, class P>void vprint(queue<pair<T, P>>q) {cerr << "["; int q_size = q.size(); for (int i = 0; i < q_size; i++) {vprint(q.front()); q.pop(); cerr << " ";} cerr << "]";}
template<class T>void swap(T *a, T *b) {T tmp; tmp = *a; *a = *b; *b = tmp;}
template<class T>bool checkInt(T b) {b = abs(b);/*for negative numbers*/ int a = b; return b - a > 0 ? 0 : 1;}
template<class T>T find_nearest_square_pow(T n, char pos) {if (pos == 'l') {T k = floor(log2(n)); return 1 << k;} else {T k = ceil(log2(n)); return 1 << k;}}
template<class T>T binaryExponentiation(T a, T b, T m) {T ans = 1; a %= m; while (b) {if (b & 1)ans = (ans * a) % m; a = (a * a) % m; b = b >> 1;} return ans;}
template<class T>string printBinary(T x) {return bitset<32>(x).to_string();}
template<class T>ostream& operator<<(ostream&os, vector<T>&v) {fo(0, v.size())os << v[i] << " "; nline; return os;}
template<class T>istream& operator>>(istream&is, vector<T>&v) {fo(0, v.size())is >> v[i]; return is;}
template<class T>istream& operator>>(istream&is, vector<vector<T>>&v) {vector<T>tmp(v[0].size()); fo(0, v.size()) {is >> tmp; v[i] = tmp;} return is;}
template<class T>ostream& operator>>(ostream&os, vector<vector<T>>&v) {vector<T>tmp(v[0].size()); fo(0, v.size())os << v[i]; return os;}
template<class T, class P>istream& operator>>(istream&is, vector<pair<T, P>>&v) {fo(0, v.size()) {T x; P y; is >> x >> y; v[i] = {x, y};} return is;}
template<class T, class P>ostream& operator<<(ostream&os, vector<pair<T, P>>&v) {fo(0, v.size())os << v[i].ff << " " << v[i].ss << endl; nline; return os;}
template<typename T>void debugAll(const char* name, T arg) {cerr << name << " "; vprint(arg); cerr << endl;}
template<class T>using ordered_set  = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename... Args>void debugAll(const char* name, T arg, Args... args) {cerr << name << " "; vprint(arg); cerr << endl; debugAll(args...);}

void solve()
{

}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
	fastio();
	solve();
	return 0;
}

// Want to use this template for CP ?
// Check it out "https://github.com/shubham-jr/competitive-programming/blob/master/Jr%20Tempate%20Cpp/my-cp-template.cpp"