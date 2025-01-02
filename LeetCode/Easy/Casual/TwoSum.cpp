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

vector<int> arr(MAXN);

class Solution {
public:
    vector<int> twoSum1(vector<int>& nums, int target) {
        vector<int> res; 
        for(int i = 0 ; i < nums.size()-1 ; i++){
            for(int j = i+1 ; j < nums.size() ; j++){
                if(nums[i] + nums[j] == target){
                    res.push_back(i);
                    res.push_back(j);
                }
            }
        }
        return res;
    }

    vector<int> twoSum(vector<int>& nums, int target){
        int n = nums.size();

        unordered_map<int, int> map;
        for(int i = 0 ; i < n ; i++){
            int comp = target - nums[i];
            if(map.count(comp)) return {map[comp], i};
            map[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    fast_io;

    int t; cin >> t;
    while(t--){
        arr.clear();
        int n; cin >> n;
        for(int i = 0 ; i < n ; i++){
            int x; cin >> x;
            arr.push_back(x);
        }
        int target; cin >> target;

        Solution sol = Solution();
        vector<int> res = sol.twoSum(arr, target);
        for(int element : res){
            cout << element << " ";
        }
        cout << endl;
    }
    return 0;
}