#include<bits/stdc++.h>
using namespace std;

typedef int64_t ll;
const char nl = '\n';
#define len(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

const int maxn = 200001;

int n, m, l = -1, r, per[maxn], forbidden[maxn];
string p, t;

bool check(int index = 0) {
  int tIndex = 0;
  while (index < n && tIndex < m) {
    if (!forbidden[index] && p[index] == t[tIndex])
      tIndex++;
    ++index;
  }
  return tIndex == m;
}

bool good(int x) {
  for (int left = l + 1; left <= x; ++left) {
    forbidden[per[left]] = 1;
  }
  bool ok = check();
  if (!ok) {
    for (int i = x; i > l; --i) forbidden[per[i]] = 0;
    return 0;
  }
  return 1;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  
  cin >> p >> t;
  n = len(p);
  m = len(t);

  for (int i = 0; i < n; ++i) {
    cin >> per[i];
    per[i]--;
  }
  
  r = n;

  while (r > l + 1) {
    int mid = l + (r - l) / 2;
    if (good(mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }

  cout << l + 1 << nl;

  return 0;
}