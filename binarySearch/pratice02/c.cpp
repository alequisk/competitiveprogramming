#include<bits/stdc++.h>
using namespace std;

typedef int64_t ll;
const char nl = '\n';
#define len(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

ll n, x, y;

bool good(ll time) {
  if (time - x < 0) return 0;
  time -= x;
  return floor(time / x) + floor(time / y) >= n - 1;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  
  cin >> n >> x >> y;
  if (x > y) swap(x, y);
  
  ll l = 0, h = 2e9;
  
  while (h > l + 1) {
    ll mid = l + (h - l) / 2;
    if (good(mid)) {
      h = mid;
    } else {
      l = mid;
    }
  }

  cout << h << nl;
  

  return 0;
}