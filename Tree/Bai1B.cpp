#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fi first
#define se second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fast_io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int MAXN = 2e5 + 5;
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;

int n, q, t, pos, x, l, r;
vector<ll> sumOnNode(4*MAXN, 0);

void update(int id, int l , int r, int pos, int val){
    if(pos < l || pos > r) return;
    if(l == r){
        sumOnNode[id] = val;
        return;
    }

    int mid = (l+r)/2;
    update(id*2, l, mid, pos, val);
    update(id*2+1, mid+1, r, pos, val);

    sumOnNode[id] = sumOnNode[id*2] + sumOnNode[id*2+1];
}

ll get(int id, int l, int r, int u, int v){
    if(v < l || r < u) return 0;
    if(u <= l && r <= v) return sumOnNode[id];

    int mid = (l+r)/2;
    ll leftSum = get(id*2, l, mid, u, v);
    ll rightSum = get(id*2+1, mid+1, r, u, v);

    return leftSum + rightSum;
}

int main() {
    fast_io;
    
    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> x;
        update(1, 1, n, i, x);
    }

    while(q--){
        cin >> t;
        if(t == 1){
            cin >> pos >> x;
            update(1, 1, n, pos, x);
        }
        else if(t == 2){
            cin >> l >> r;
            cout << get(1, 1, n, l, r) << endl;
        }
    }

    return 0;
}