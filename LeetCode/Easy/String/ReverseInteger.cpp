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

class Solution {
public:
    int reverse(int x) {
        ostringstream oos;
        oos << x;
        string num = oos.str();
        
        if(num[0] == '-'){
            std::reverse(num.begin()+1, num.end());
        }
        else{
            std::reverse(num.begin(), num.end());
        }
        
        int res;
        stringstream(num) >> res;
        if(res >= INT32_MAX || res <= INT32_MIN) res = 0;

        return res;
    }

    int reverse(int x){
        int res = 0;
        while(x != 0){
            int digit = x % 10;
            if(res > INT32_MAX / 10 || res < INT32_MIN / 10)
                return 0;
            
            res = res * 10 + digit;
            x /= 10;
        }
        return res;
    }
};

int main() {
    fast_io;

    Solution sol = Solution();
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << sol.reverse(n) << endl;
    }

    return 0;
}