#include<bits/stdc++.h>
using namespace std;

typedef int64_t ll;
const char nl = '\n';
#define len(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

int st[200002][19];
vector<int> arr;

int solve(int a, int b) {
  int pos = a;
  for (int k = 18; k >= 0; --k) {
    if ((1 << k) <= b) {
      pos = st[pos][k];
      b -= (1 << k);

      if (pos == -1)
        return -1;
    }
  }
  return pos + 1;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, k;
  cin >> n >> k;
  arr.assign(n, 0);
  memset(st, -1, sizeof(st));


  for (int i = 1; i < n; ++i) {
    cin >> arr[i], --arr[i];
    st[i][0] = arr[i];
  }

  for (int j = 1; j < 19; ++j) {
    for (int i = 0; i < n; ++i) {
      if (st[i][j - 1] != -1)
        st[i][j] = st[ st[i][j - 1] ][j - 1];
    }
  }

  int x, kk;
  while (k --> 0) {
    cin >> x >> kk, --x;
    cout << solve(x, kk) << nl; 
  }

  
  return 0;
}