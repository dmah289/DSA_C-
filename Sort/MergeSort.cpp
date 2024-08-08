#include<bits/stdc++.h>
using namespace std;

vector<int> Merge(vector<int> left, vector<int> right)
{
    vector<int> res;
    int l = 0, r = 0;
    // Lặp đến khi cả 2 mảng đều hết phần tử
    while(l != left.size() || r != right.size())
    {
        // Cách 1 : Nếu 1 mảng hết phần tử hoặc phần tử mảng này nhỏ hơn mảng kia ( mà mảng kia vẫn còn phần tử ) thì add
        // if((r == right.size() || left[l] < right[r]) && l < left.size())
        //     res.push_back(left[l++]);
        // else if((l == left.size() || right[r] <= left[l]) && r < right.size())
        //     res.push_back(right[r++]);

        // Cách 2: Check 1 trong 2 mảng hết phần tử trước -> Chưa có mảng nào hết phần tử thì mới so sánh phần tử với nhau
        if(l == left.size())
            res.push_back(right[r++]);
        else if(r == right.size())
            res.push_back(left[l++]);
        else if(left[l] <= right[r])
            res.push_back(left[l++]);
        else if(right[r] < left[l])
            res.push_back(right[r++]);
    }
    return res;
}

vector<int> Division(int l, int r, vector<int> v)
{
    // Nếu chỉ số giống nhau thì trả về 1 mảng mới có 1 phần tử -> Bắt đầu Merge
    if(l == r) return vector<int>{v[l]};

    // Chia mảng theo chỉ số và lấy về 2 mảng
    int mid = (l + r) / 2;
    vector<int> left = Division(l, mid, v);
    vector<int> right = Division(mid+1, r, v);
    
    // Merge và sắp xếp 2 mảng lại với nhau
    return Merge(left, right);
}

vector<int> MergeSort(vector<int> v)
{
    if(v.size() == 0) return v;
    return Division(0, v.size()-1, v);
}

int main()
{
    vector<int> tmp = {7, 4, 1, 2, 5, 8, 9, 3, 6};
    vector<int> sorted_array = MergeSort(tmp);
    for(auto it : sorted_array)
        cout << it << " ";
}