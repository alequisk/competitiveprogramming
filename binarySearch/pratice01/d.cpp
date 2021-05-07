#include<bits/stdc++.h>
using namespace std;

typedef int64_t ll;
const char nl = '\n';
#define len(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

int main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n, k;
  cin >> n;
  vector<int> arr(n);
  for (int &x: arr) cin >> x;
  sort(all(arr));
  cin >> k;
  while (k --> 0) {
    int l, r;
    cin >> l >> r;
    
    int left, right;
    int a = -1, b = n;
    while (b > a + 1) {
      int mid = a + (b - a) / 2;
      if (arr[mid] < l) a = mid;
      else b = mid;
    }
    
    left = b;
    a = - 1, b = n;

    while (b > a + 1) {
      int mid = a + (b - a) / 2;
      if (arr[mid] <= r) a = mid;
      else b = mid;
    }
    
    right = a;
    cout << right - left + 1 << " ";

    // simple answer
    // cout << upper_bound(all(arr), r) - lower_bound(all(arr), l) << " ";
  } cout << nl;

  return 0;
}