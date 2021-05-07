#include<bits/stdc++.h>
using namespace std;

typedef int64_t ll;
const char nl = '\n';
#define len(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

bool hasAns = false;

int f(ll x) {
  int ret = 0;
  while (x) {
    x /= 10; ++ret;
  }
  return ret;
}

ll a, b;

vector<int> order;

void dfs(ll x) {
  
  order.push_back(x);
  if (x < a)
    return;
  
  if (x == a) {
    hasAns = 1;
    return;
  }
  if (x % 10 == 1) {
    dfs(x / 10);
  } else if (x % 2 == 0) {
    dfs(x / 2);
  } else {
    return;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  
  cin >> a >> b;
  dfs(b);
  cout << (hasAns ? "YES" : "NO") << nl;
  if (hasAns) {
    reverse(all(order));
    cout << len(order) << nl;
    for (int x: order) {
      cout << x << " ";
    } cout << nl;
  }
  
  return 0;
}