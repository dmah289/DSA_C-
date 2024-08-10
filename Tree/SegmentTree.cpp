//               [0, 3]                  --->   Số phần tử n = 2^k: Cây nhị phân đầy đủ
//          /              \                    -> Số node = 2^(k+1)-1 = 2*n-1 node
//     [0, 1]              [2, 3]               Số phần tử n != 2^k
//    /     \              /    \               -> Số node = 4*n-1
// [0,0]    [1,1]      [2,2]      [3,3]

#include<bits/stdc++.h>
using namespace std;

int n = 8;
int arr[8] = {1, 3, 5, 2, 4, 6, 8, 7};
int sumOnNode[100];   // Tổng trên 1 node


// Xây dựng node bởi id mà quản lý [l,r]
void buildNode(int id, int l, int r){

    //Điều kiện dừng: Đoạn con chỉ có 1 phần tử
    if(l == r){
        sumOnNode[id] = arr[l];
        // cout << id << " " << l << " " << r << " " << sumOnNode[id] << endl;
        return;
    }

    // Xây dựng 2 node con trước
    int mid = (l + r) / 2;
    buildNode(id*2, l, mid);
    buildNode(id*2+1, mid+1, r);

    // Sau khi đã xây dựng 2 node con -> Tính tổng của cha
    sumOnNode[id] = sumOnNode[id*2] + sumOnNode[id*2+1];
}

// Tính tổng 1 đoạn con [u,v] theo id node quản lý [l,r]
int getSum(int id, int l, int r, int u, int v){

    // [u,v] không giao [l,r]
    if(r < u || v < l) return 0;

    // [l,r] nằm trong [u,v]
    if(u <= l && r <= v){
        // cout << id << " giao " << l << " " << r << " " << sumOnNode[id] << endl;
        return sumOnNode[id];
    }

    // [l,r] giao với 1 phần hoặc toàn bộ [u,v]
    // --> Tính tổng phần mà [u,v] giao với đoạn bên trái và phải sau khi chia nửa của [l,r]
    int mid = (l + r) / 2;
    int leftSum = getSum(id*2, l, mid, u, v);
    int rightSum = getSum(id*2+1, mid+1, r, u, v);
    // cout << id << " " << l << " " << r << " " << leftSum + rightSum << endl;
    return leftSum + rightSum;
}

void updateValueOnArray(int id, int l, int r, int pos, int val){

    // Trường hợp pos không thuộc [l,r]
    if(pos < l || pos > r) return;

    // Trường hợp [l,r] chính là pos
    if(l == r){
        sumOnNode[id] = val;
        arr[pos] = val;
        return;
    }

    // Trường hợp pos thuộc [l,r].size != 1
    int mid = (l + r) / 2;
    updateValueOnArray(id*2, l, mid, pos, val);
    updateValueOnArray(id*2+1, mid+1, r, pos, val);

    // Sau khi đã update 1 trong 2 node con thì phải cập nhật cả tổng trên nút cha
    sumOnNode[id] = sumOnNode[id*2] + sumOnNode[id*2+1];
}

int main(){
    // update n lần (nlogn) tương đương build(4n)
    buildNode(1, 0, n-1);
    cout << getSum(1, 0, n-1, 1, 4) << endl;
    updateValueOnArray(1, 0, n-1, 3, 10);
    cout << getSum(1, 0, n-1, 1, 4) << endl;
    return 0;
}