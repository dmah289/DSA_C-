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

class Solution {
public:
    double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2) {
        int p1 = 0, p2 = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> res;

        while(p1 < n1 || p2 < n2){
            if(p1 == n1) res.push_back(nums2[p2++]);
            else if(p2 == n2) res.push_back(nums1[p1++]);
            else if(nums1[p1] < nums2[p2]) res.push_back(nums1[p1++]);
            else res.push_back(nums2[p2++]);
        }

        cout << fixed << setprecision(5);

        if(res.size() % 2 == 0)
            return (res[res.size()/2] + res[res.size()/2 - 1]) / 2.0;
        else return res[res.size()/2];
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();

        // Mảng 1 luôn ngắn hơn mảng 2 đảm bảo luôn tính toán được điểm phân vùng của mảng 2
        if (n1 > n2) return findMedianSortedArrays(nums2, nums1);

        // Tính toán điểm (điểm != index)
        int low = 0, high = n1;           // Hỗ trợ khởi tạo điểm phân vùng cho mảng 1
        int halfLen = (n1 + n2 + 1) / 2;  // Hỗ trợ khởi tạo điểm phân vùng cho mảng 2

        cout << fixed << setprecision(5);
        // Tìm điểm chia thỏa mãn phần tử bên trái mỗi mảng <= phần tử bên phải mảng còn lại
        while (low <= high) {
            // Điểm phân vùng mảng 1
            int i = (low + high) / 2;
            // Điểm phân vùng mảng 2 thỏa mãn i + j (nửa bên trái mảng đã gộp) = 1/2 tổng phần tử 2 mảng
            int j = halfLen - i;

            // Nếu phần tử bên phải điểm chia mảng 1 vẫn còn nhỏ hơn phần tử bên trái điểm chia mảng 2
            // -> Điểm chia mảng 1 chưa đủ lớn
            if (i < n1 && nums1[i] < nums2[j - 1]) {
                low = i + 1;
            // Nếu phần tử bên trái điểm chia mảng 1 lại lớn hơn phần tử bên phải điểm chia mảng 2
            // -> Điểm chia mảng 1 đã vượt ngưỡng
            } else if (i > 0 && nums1[i - 1] > nums2[j]) {
                high = i - 1;
            } else {
                int maxLeft = 0;
                // Tất cả phần tử bên trái đều đến từ mảng 2
                if (i == 0) maxLeft = nums2[j - 1];
                // Tất cả phần tử bên trái đều đến từ mảng 1
                else if (j == 0) maxLeft = nums1[i - 1];
                else maxLeft = max(nums1[i - 1], nums2[j - 1]);

                if ((n1 + n2) % 2 == 1) return maxLeft;

                int minRight = 0;
                // Tất cả phần tử bên phải đều đến từ mảng 2
                if (i == n1) minRight = nums2[j];
                // Tất cả phần tử bên trái đều đến từ mảng 1
                else if (j == n2) minRight = nums1[i];
                else minRight = min(nums1[i], nums2[j]);

                return (maxLeft + minRight) / 2.0;
                
            }
        }
        return 0.0;
    }
};

int main() {
    fast_io;
    
    int n,m; cin >> n >> m;
    vector<int> nums1(n), nums2(m);
    for(int i = 0 ; i < n ; i++){
        cin >> nums1[i];
    }
    for(int i = 0 ; i < m ; i++){
        cin >> nums2[i];
    }

    Solution sol = Solution();
    cout << sol.findMedianSortedArrays(nums1, nums2);

    return 0;
}