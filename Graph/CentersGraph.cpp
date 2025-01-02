#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fast_io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int MAXN = 1e5 + 5;

int n,m;
vector<vector<int>> adj(MAXN);
vector<int> degrees(MAXN);

// Center: Đỉnh tại trung tâm đường đi dài nhất trên đồ thị
vector<int> FindCentersNode(){
    vector<int> leavesIdx;
    for(int i = 0 ; i < n ; i++){
        if(degrees[i] <= 1){
            leavesIdx.push_back(i);
            degrees[i]--;
        }
    }
    int cntPruned = leavesIdx.size();

    // Đảm bảo duyệt qua tất cả các node
    while(cntPruned < n){
        vector<int> newLeavesIdx;
        // Duyệt qua các lá lớp hiện thời
        for(int leafIdx : leavesIdx){
            // Duyệt qua hàng xóm của lá để giảm bậc tương đương bỏ node lá đang xét
            // Có thể gặp các node lá đã có bậc = 0. Không ảnh hưởng do chỉ xet node có bậc = 1
            for(int neighborIdx : adj[leafIdx]){
                degrees[neighborIdx]--;
                // Nếu bậc của hàng xóm lá hiện tại = 1 -> lá mới
                if(degrees[neighborIdx] == 1)
                    newLeavesIdx.push_back(neighborIdx);
            }
            // Giảm bậc node lá đang xét
            degrees[leafIdx]--;
        }
        cntPruned += newLeavesIdx.size();
        // Cập nhật các node lá mới
        leavesIdx = newLeavesIdx;
    }
    return leavesIdx;
}

int main() {
    fast_io;
    
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degrees[u]++;
        degrees[v]++;
    }

    vector<int> centers = FindCentersNode();
    for(int idx : centers)
        cout << idx << " ";

    return 0;
}