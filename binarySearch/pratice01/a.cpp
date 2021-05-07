#include<bits/stdc++.h>
using namespace std;

typedef int64_t ll;
const char nl = '\n';
#define len(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

int main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  
  for (int &x: arr) cin >> x;
  
  while (k --> 0) {
    int x; cin >> x;
    int ok = false;
    int l = 0, r = n - 1;
    while (r >= l) {
      int mid = l + (r - l) / 2;
      if (arr[mid] == x) {
        ok = true; break;
      } else if (arr[mid] < x) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    cout << (ok ? "YES" : "NO") << nl;
  }

  return 0;
}