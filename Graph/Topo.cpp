#include<bits/stdc++.h>
using namespace std;

int main()
{
    int v, e; cin >> v >> e;

    vector<vector<int>> adj(v);     // Danh sách kề
    vector<int> deg_in(v, 0);       // Bậc vào
    queue<int> noIncomingVertice;   // Danh sách đỉnh bậc vào = 0
    vector<int> topo_arr;           // Danh sách topo

    // Nhập vào danh sách cạnh -> Danh sách kề
    for(int i = 0 ; i < e ; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    for(int i = 0 ; i < v ; i++){
        cout << "Dinh " << i << ": ";
        for(int u : adj[i])
            cout << u << " ";
        cout << endl;
    }

    // Tính bậc vào
    for(int i = 0 ; i < v ; i++){
        for(int to : adj[i])
            deg_in[to]++;
    }
    for(int i = 0 ; i < v ; i++)
        cout << deg_in[i] << " ";

    cout << endl;

    // Tìm các đỉnh bậc vào = 0 đầu tiên
    for(int i = 0 ; i < v ; i++){
        if(deg_in[i] == 0)
            noIncomingVertice.push(i);
    }
    // Chừng nào còn đỉnh thì cho vào topo -> deg_in = 0 thì push vào queue
    while(!noIncomingVertice.empty()){
        int top = noIncomingVertice.front(); noIncomingVertice.pop();
        topo_arr.push_back(top);
        for(int to : adj[top]){
            deg_in[to]--;
            if(deg_in[to] == 0)
                noIncomingVertice.push(to);
        }
    }
    // Nếu không đủ đỉnh thì chứa chu trình (Có giai đoạn còn đỉnh nhưng không đỉnh nào deg_in = 0)
    if(topo_arr.size() != v)
        cout << "Cyclic" << endl;
    else{
        for(int it : topo_arr)
            cout << it << " ";
    }

}

/* 
Input:
        14 18
        0 2
        0 3
        0 6
        1 4
        2 6
        3 1
        3 4   (4 3) -> Cyclic
        4 5
        4 8
        6 7
        6 11
        7 4
        7 12
        9 2
        9 10
        10 6
        11 12
        12 8

Output: 
        Dinh 0: 2 3 6 
        Dinh 1: 4 
        Dinh 2: 6 
        Dinh 3: 1 4 
        Dinh 4: 5 8 
        Dinh 5: 
        Dinh 6: 7 11 
        Dinh 7: 4 12 
        Dinh 8: 
        Dinh 9: 2 10 
        Dinh 10: 6 
        Dinh 11: 12 
        Dinh 12: 8 
        Dinh 13: 
        0 1 2 1 3 1 3 1 2 0 1 1 2 0
        0 9 13 3 2 10 1 6 7 11 4 12 5 8 
*/
