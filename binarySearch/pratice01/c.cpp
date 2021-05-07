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
  
  // closest element of x from right
  
  while (k --> 0) {
    int x; cin >> x;
    int l = -1; // arr[l] < x
    int r = n; // arr[r] >= x
    while (r > l + 1) {
      int mid = l + (r - l) / 2;
      if (arr[mid] < x) {
        l = mid;
      } else {
        r = mid;
      }
    }

    cout << r + 1 << nl;
  }

  return 0;
}