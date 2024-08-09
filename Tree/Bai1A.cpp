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
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);

const int MAXN = 2e5 + 5;
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;

int n, q, t, x, v;
vector<ll> arr(MAXN);
vector<ll> sumOnNode(4*MAXN);

void build(int id, int l, int r){
    if(l == r){
        sumOnNode[id] = arr[l];
        return;
    }

    int mid = (l + r) / 2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);

    sumOnNode[id] = sumOnNode[id*2] + sumOnNode[id*2+1];
}

ll get(int id, int l, int r, int u, int v){
    if(v < l || u > r) return 0;
    if(u <= l && v >= r) return sumOnNode[id];

    int mid = (l + r) / 2;
    ll leftSum = get(id*2, l, mid, u, v);
    ll rightSum = get(id*2+1, mid+1, r, u, v);

    return leftSum + rightSum;
}

void update(int id, int l, int r, int pos, int val){
    if(pos < l || pos > r) return;
    if(l == r){
        arr[pos] = val;
        sumOnNode[id] = val;
        return;
    }

    int mid = (l + r)/2;
    update(id*2, l, mid, pos, val);
    update(id*2 + 1, mid+1, r, pos, val);
    
    sumOnNode[id] = sumOnNode[id*2] + sumOnNode[id*2+1];
}

int main() {
    fast_io;

    cin >> n >> q;
    for(int i = 1 ; i <= n ; i++) cin >> arr[i];

    build(1, 1, n);

    while(q--){
        cin >> t;
        if(t == 1){
            cin >> x >> v;
            update(1, 1, n, x, v);
        }
        else if(t == 2){
            cin >> x;
            cout << get(1, 1, n, 1, x) << endl;
        }
    }

    return 0;
}