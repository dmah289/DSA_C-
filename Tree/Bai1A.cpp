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
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MAXN = 2e5 + 5;
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;

vector<int> arr(MAXN);
vector<int> st(4*MAXN);

void buildTree(){}

ll getSum(){}

void update(){}

int main() {
    fast_io;

    int n,q; cin >> n >> q;

    for(int i = 0 ; i < n ; i++)
    {
        cin >> arr[i];
    }

    buildTree();

    while(q--){
        int t; cin >> t;
        if(t == 1) update();
        else if(t == 2) getSum();
    }



    return 0;
}