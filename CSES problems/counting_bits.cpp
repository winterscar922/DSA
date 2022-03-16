/* WINTERSCAR  */
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
 
#define pb push_back
#define pf push_front
#define vll vector<long long>
#define vb vector<bool>
#define pii pair<long long, long long>
#define maxheap priority_queue<int>
#define minheap priority_queue<int, vector<int>, greater<int> >
#define int long long
 
#define FOR(i,a,b) for (long long i = (a); i < (b); ++i)
#define REV(i,a) for (long long i = (a); i >= 0; --i)
 
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define all(c) (c).begin(), (c).end()
#define nline "\n"
#define INF 2e18
#define ffo find1_first_of
#define ff first
#define ss second
#define mp make_pair
 
typedef long double lld;
const int mod = 1e9 + 7;
 
/*-------------------------------------------------------------------------*/
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif
 
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
 
/*-------------------------------------------------------------------------*/
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(unordered_set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/*-------------------------------------------------------------------------*/
 
int __gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = __gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
 
int lcm(int a, int b) {
    return (a * b) / __gcd(a, b);
}
 
int binary_ex(int a, int b, int m) {
    int ans = 1;
    while (b > 0) {
        if (b & 1) {
            ans = (ans * 1LL * a) % m ;
        }
        a = (a * 1LL * a) % m ;
        b >>= 1;
    }
    return ans;
}
 
template<typename T>
istream& operator >>(istream& istream, vector<T>& v) {
    for (auto& element : v) {
        cin >> element;
    }
    return istream;
}
 
template<typename T>
ostream& operator <<(ostream& ostream, vector<T>& v) {
    for (auto& element : v) {
        cout << element << " ";
    }
    return ostream;
}
 
template<typename T>
istream &operator >>(istream &istream, vector<vector<T>> &v) {
    for (auto &row : v) {
        for (auto &cell : row) {
            cin >> cell;
        }
    }
    return istream;
}
 
template<typename T>
ostream& operator <<(ostream& ostream, vector<vector<T>>& v) {
    for (auto& row : v) {
        for (auto& cell : row) {
            cout << cell << " ";
        }
        cout << "\n";
    }
    return ostream;
}
int toint(const string &s) {stringstream ss; ss << s; int x; ss >> x; return x;}
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/*-----------------------------------------------------------------------*/
 
 
void PleaseAC() {
    int n;
    cin >> n;
    int mafs = 0;
    FOR(i, 0, 63) {
        int pow = (1LL << i);
        int value = (n / pow);
        int tot = ((value / 2) * pow);
        int nearest = (value * pow);
        if (nearest <= n && (nearest >> i) & 1) {
            tot += (n - nearest + 1);
        }
        mafs += tot;
    }
    debug(mafs)
    cout << mafs << nline;
}
 
 
signed main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
 
    flash;
 
    int t = 1;
 
    // cin >> t;
 
    while (t--) {
        PleaseAC();
    }
 
    return 0;
}
