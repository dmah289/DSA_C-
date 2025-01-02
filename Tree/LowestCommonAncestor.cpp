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

struct TreeNode{
    int id;
    int val;
    TreeNode* parent;
    vector<TreeNode*> children;
    TreeNode(int id, int val, TreeNode* parent, vector<TreeNode*> children) : id(id), val(val), parent(parent), children(children) {}
};

vector<ll> arr(MAXN);

TreeNode* StartEulerianTour(TreeNode* root){
    // Start Eulerian tour at the root node
    // Traverse all nodes as undirectional graph
    // Store the depth of all nodes and pointer to each node based index in Eulerian tour

    return root;
}

// LCA: The deepest node that has both 2 nodes as descendants
// Note: A node can be a descendant of itself
// Using Eulerian tour + Range Minimum Querry (SpareTable - O(nlogn))
int main() {
    fast_io;
    
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    

    return 0;
}