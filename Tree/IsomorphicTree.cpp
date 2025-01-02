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
    TreeNode* parent;
    vector<TreeNode*> children;

    TreeNode(int id, TreeNode* parent, vector<TreeNode*> children) : id(id), parent(parent), children(children) {}
};

int n1, m1, n2, m2; 
vector<vector<int>> adj1(MAXN), adj2(MAXN);
vector<int> degrees1(MAXN), degrees2(MAXN);
TreeNode* root1;
TreeNode* root2;

vector<int> FindCentersOfTree(int n, vector<vector<int>>& adj, vector<int>& degrees){
    vector<int> leavesIdx;
    for(int i = 0 ; i < n ; i++){
        if(degrees[i] <= 1){
            leavesIdx.push_back(i);
            degrees[i]--;
        }
    }
    int cnt = leavesIdx.size();

    while(cnt < n){
        vector<int> newLeaves;
        for(int leaf : leavesIdx){
            for(int neighbor : adj[leaf]){
                degrees[neighbor]--;
                if(degrees[neighbor] == 1) newLeaves.push_back(neighbor);
            }
            degrees[leaf]--;
        }
        leavesIdx = newLeaves;
        cnt += newLeaves.size();
    }
    return leavesIdx;
}

void BuildRootedTree(vector<vector<int>> adj, TreeNode* currNode, TreeNode* parent){
    for(int neighbor : adj[currNode->id]){
        if(parent != nullptr && neighbor == parent->id)
            continue;
        TreeNode* childNode = new TreeNode(neighbor, currNode, {});
        currNode->children.push_back(childNode);
        BuildRootedTree(adj, childNode, currNode);
    }
}

string EncodeRootedTree(TreeNode* currNode){
    if(currNode == nullptr) return "";

    vector<string> labels;
    for(TreeNode* child : currNode->children)
        labels.push_back(EncodeRootedTree(child));

    sort(all(labels));

    string res = "";
    for(string item : labels) res += item;
    return "(" + res + ")";
}

bool CheckIsomorphic(){
    vector<int> tree1_centers = FindCentersOfTree(n1, adj1, degrees1);
    vector<int> tree2_centers = FindCentersOfTree(n2, adj2, degrees2);

    root1 = new TreeNode(tree1_centers[0], nullptr, {});
    BuildRootedTree(adj1, root1, root1->parent);
    string tree_encoded1 = EncodeRootedTree(root1);

    for(int center : tree2_centers){
        root2 = new TreeNode(center, nullptr, {});
        BuildRootedTree(adj2, root2, root2->parent);
        string tree_encoded2 = EncodeRootedTree(root2);
        if(tree_encoded2 == tree_encoded1)
            return true;
    }
    return false;
}

int main() {
    fast_io;
    
    cin >> n1 >> m1;
    for (int i = 0; i < m1; i++){
        int u,v; cin >> u >> v;
        adj1[u].push_back(v);
        adj1[v].push_back(u);
        degrees1[u]++;
        degrees1[v]++;
    }

    cin >> n2 >> m2;
    for(int i = 0 ; i < m2 ; i++){
        int u,v; cin >> u >> v;
        adj2[u].push_back(v);
        adj2[v].push_back(u);
        degrees2[u]++;
        degrees2[v]++;
    }

    if(CheckIsomorphic()) cout << "YES";
    else cout << "NO";

    return 0;
}