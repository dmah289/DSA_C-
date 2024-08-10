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

int n;
vector<ll> arr(MAXN, 0);

int LomutoPartition(int l, int r)
{
    ll pivot = arr[r];
    int i = l-1;
    for(int j = l ; j < r ; j++)
    {
        if(arr[j] <=  pivot)
        swap(arr[++i], arr[j]);
    }
    swap(arr[++i], arr[r]);
    return i;
}

void QuickSortLomuto(int l, int r)
{
    if(l >= r) return;

    int pivot = LomutoPartition(l, r);

    QuickSortLomuto(l, pivot-1);
    QuickSortLomuto(pivot+1, r);
}

int HoarePartition(int l, int r){
    ll pivot = arr[l];
    int i = l-1, j = r+1;
    while(true)
    {
        do{i++;} while(arr[i] < pivot);
        do{j--;} while(arr[j] > pivot);
        if(i < j) swap(arr[i], arr[j]);
        else return j;
    }
}

void QuickSortHoare(int l, int r)
{
    if(l >= r) return;

    int pivot = HoarePartition(l, r);
    QuickSortHoare(l, pivot);
    QuickSortHoare(pivot+1, r);
}

int main() {
    fast_io;
    
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    QuickSortHoare(0, n-1);

    for(int i = 0 ; i < n ; i++) cout << arr[i] << " ";

    return 0;
}