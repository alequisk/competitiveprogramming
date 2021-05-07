#include<bits/stdc++.h>
using namespace std;

typedef int64_t ll;
const char nl = '\n';
#define len(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

ll h, w, n;

bool good(ll v) {
  return (v / h) * (v / w) >= n;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> h >> w >> n;
  if (h > w) swap(h, w);
  ll l = 0, r = 1;
  while (!good(r)) r <<= 1;
  //cout << "l=" << l << " r=" << r << nl;
  while (r > l + 1) {
    ll mid = l + (r - l) / 2;
    if (good(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }

  cout << r << nl;

  return 0;
}