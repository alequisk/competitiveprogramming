#include<bits/stdc++.h>
using namespace std;

typedef int64_t ll;
const char nl = '\n';
#define len(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

int n, k;
double l = 0, r = 1e8;
int arr[10001];

bool good(double x) {
  int s = 0;
  for (int i = 0; i < n; ++i) {
    s += floor(arr[i] / x);
  }
  return s >= k;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  for (int i = 0; i < 100; ++i) {
    double mid = l + (r - l) / 2;
    if (good(mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }

  cout << std::setprecision(20) << l << nl;
  

  return 0;
}