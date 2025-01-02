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

vector<int> arr1(MAXN);
vector<int> arr2(MAXN);

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        ListNode* dummyHead = new ListNode(0);
        ListNode* tail = dummyHead;
        int carry = 0;

        while(l1 != nullptr || l2 != nullptr || carry != 0){
            int digit1 = l1 != nullptr ? l1->val : 0;
            int digit2 = l2 != nullptr ? l2->val : 0;

            int sum = digit1 + digit2 + carry;
            int digit = sum % 10;
            carry = sum / 10;

            ListNode* newNode = new ListNode(digit);
            tail->next = newNode;
            tail = tail->next;

            l1 = (l1 != nullptr) ? l1->next : nullptr; 
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }

        ListNode* res = dummyHead->next;
        delete dummyHead;
        return res;
    }
};

int main() {
    fast_io;

    Solution sol = Solution();

    int t; cin >> t;
    while(t--){
        arr1.clear();
        arr2.clear();

        int n1, n2; cin >> n1 >> n2;
        
        ListNode *l1 = new ListNode();
        ListNode *current1 = new ListNode();

        for(int i = 0 ; i < n1 ; i++){
            int x; cin >> x;
            ListNode *newNode = new ListNode(x);
            if(i != 0) current1->next = newNode;
            current1 = newNode;
            if(i == 0) l1 = current1;
        }

        ListNode *l2 = new ListNode();
        ListNode *current2 = new ListNode();

        for(int i = 0 ; i < n2 ; i++){
            int x; cin >> x;
            ListNode *newNode = new ListNode(x);
            if(i != 0) current2->next = newNode;
            current2 = newNode;
            if(i == 0) l2 = current2;
        }

        ListNode *res = sol.addTwoNumbers(l1, l2);

        while(res != nullptr){
            cout << res-> val << " ";
            res = res->next;
        }
        cout << endl;
    }

    return 0;
}