//https://open.kattis.com/problems/balanceddiet
//Running Time: 0.43s
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

const ld  pi   = 4.0*atanl(1.0);
const int iinf = 1e9 + 10;
const ll  inf  = 1e18 + 10;
const int mod  = 1000000007;

#define enld endl
#define endl '\n'
#define pb push_back
#define debug(x) cout<<#x<<" -> "<<x<<'\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); ++i)
#define umap unordered_map
#define uset unordered_set

template<class TIn>
using indexed_set = tree<
        TIn, null_type, less<TIn>,
        rb_tree_tag, tree_order_statistics_node_update>;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

void file() {
    auto a = freopen("a.in",  "r", stdin);
    auto b = freopen("a.out", "w", stdout);
    if(!a || !b) cout << "uh oh" << endl;
}

ll readint(){
    char r;
    bool start=false,neg=false;
    ll ret=0;
    while(true){
        r=getchar();
        if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
            continue;
        }
        if((r-'0'<0 || r-'0'>9) && r!='-' && start){
            break;
        }
        if(start)ret*=10;
        start=true;
        if(r=='-')neg=true;
        else ret+=r-'0';
    }
    if(!neg) return ret;
    else return -ret;
}

ll sum = 0;
ll bestdiff = inf;
ll a=0, b=0;

void search(vector<ll>& v, ll pos, ll curr) {
    if(pos == v.size()) {
        ll rest = sum - curr;
        ll diff = abs(rest-curr);
        if(diff < bestdiff) {
            bestdiff = diff;
            a = curr;
            b = rest;
        }
    }
    else {
        ll target = sum / 2;
        if((curr - target) > bestdiff) {
            return;
        }
        search(v, pos+1, curr);
        search(v, pos+1, curr+v[pos]);
    }
}

int main() {
    ll n;
    while(cin >> n && n != 0) {
        sum = 0;
        bestdiff = inf;
        a = b = 0;
        vector<ll> v(n);
        for(auto& i : v) {
            cin >> i;
            sum += i;
        }
        sort(rall(v));
        search(v, 0, 0);
        cout << max(a,b) << " " << min(a,b) << endl;
    }
}
