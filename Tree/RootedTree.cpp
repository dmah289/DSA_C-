#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fast_io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

struct TreeNode{
    int id;
    int val;
    TreeNode* parent;
    vector<TreeNode*> children;

    TreeNode(int id, int val, TreeNode* parent, vector<TreeNode*> children) : id(id), val(val), parent(parent), children(children) {}
};

bool _isDirected = true;
int n,m;
const string fileName = "input.txt";
TreeNode* root;
int rootIdx = 1;
vector<int> values = {0};
unordered_map<int, vector<int>> adjList;

void BuildRootedTree(TreeNode* currNode, TreeNode* parent){
    for(int childIdx : adjList[currNode->id]){
        if(!_isDirected && parent != nullptr && childIdx == parent->id)
            continue;
        TreeNode* childNode = new TreeNode(childIdx, values[childIdx], currNode, {});
        currNode->children.pb(childNode);
        BuildRootedTree(childNode, currNode);
    }
}

void TraverseTree(TreeNode* currNode){
    cout << currNode->val << " ";
    if(!currNode->children.empty()){
        for(TreeNode* childNode : currNode->children){
            TraverseTree(childNode);
        }
    }
}

int SumOfLeafNodes(TreeNode* currNode){
    if(currNode == nullptr) return 0;

    if(currNode->children.empty()) return currNode->val;

    int sum = 0;
    for(TreeNode* childNode : currNode->children){
        sum += SumOfLeafNodes(childNode);
    }
    return sum;
}

int HeightOfTree(TreeNode* currNode){
    if(currNode == nullptr || currNode->children.empty()) return 0;

    vector<int> heights;
    for(TreeNode* childNode: currNode->children){
        heights.pb(HeightOfTree(childNode));
    }
    
    return *max_element(all(heights)) + 1;
}

int main() {
    fast_io;
    
    ifstream inputFile(fileName);
    inputFile >> n >> m;

    for(int i = 0 ; i < n ; i++){
        int x; inputFile >> x;
        values.pb(x);
    }

    for(int i = 0 ; i < m ; i++){
        int u,v; inputFile >> u >> v;
        adjList[u].pb(v);
        if(!_isDirected) adjList[v].pb(u);
    }
    inputFile.close();

    root = new TreeNode(rootIdx, values[rootIdx], nullptr, {});
    BuildRootedTree(root, nullptr);
    TraverseTree(root);

    cout << endl << SumOfLeafNodes(root) << endl;
    cout << HeightOfTree(root) << endl;

    return 0;
}