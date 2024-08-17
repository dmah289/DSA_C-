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

const int MAXN = 1e5 + 5;
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;

vector<ll> arr(MAXN);

int main() {
    fast_io;
    
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) cout << arr[i] << endl;

    return 0;
}