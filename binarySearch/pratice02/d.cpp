#include<bits/stdc++.h>
using namespace std;

typedef int64_t ll;
const char nl = '\n';
#define len(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

const int maxn = 1001;

ll n, m;
ll t[maxn], y[maxn], z[maxn];

ll countTime(int index, ll num) {
  ll ret = t[index] * num;
  ll m = num % z[index];
  if (m > 0) {
    ret += (num / z[index]) * y[index];
  } else if (num >= z[index]){
    ret += (num / z[index] - 1) * y[index];
  }
  return ret;
}

// k * (t * z + y)

// T => (t * z + y) + (t * z + y) + ... + (t * z + y)
// z => T / 

ll countBallons(int index, ll time) {
  // closed equation
  // return time / (t[index] * z[index] + y[index]) * z[index] + min((time % (t[index] * z[index] + y[index]) / t[index]), z[index]);

  ll l = 0, r = 15001;
  while (r > l + 1) {
    ll mid = l + (r - l) / 2;
    if (countTime(index, mid) <= time) {
      l = mid;
    } else {
      r = mid;
    }
  }
  return l;
}

bool good(ll time) {
  ll ballons = 0;
  
  for (int i = 0; i < n; ++i) {
    ballons += countBallons(i, time);
  }
  
  return ballons >= m;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> m >> n;
  for (int i = 0; i < n; ++i) {
    cin >> t[i] >> z[i] >> y[i];
  }

  ll l = -1, r = 1e9;
  while (r > l + 1) {
    ll mid = l + (r - l) / 2;
    if (good(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }

  ll time = r;
  cout << time << nl;

  vector<ll> ans(n, 0);

  for (int i = 0; i < n; ++i) {
    ans[i] = countBallons(i, time);
  }

  ll sum = accumulate(all(ans), 0);

  for (int i = 0; i < n; ++i) {
    while (sum > m && ans[i] > 0)
      --ans[i], --sum;
    cout << ans[i] << " ";
  } cout << nl;

  return 0;
}