#include<bits/stdc++.h>
using namespace std;

typedef int64_t ll;
const char nl = '\n';
#define len(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

const int maxn = 501;

int n, m, i, a, b, timer, tttt;
int tin[maxn], tout[maxn], age[maxn],
    used[maxn], positions[maxn];
vector<int> gr[maxn];

void reset() {
  for (int j = 0; j < n; ++j) {
    positions[j] = j, used[j] = 0;
    gr[j].clear();
  }
}

void Swap(int _a, int _b) {
  swap(age[positions[_a]], age[positions[_b]]);
  swap(positions[_a], positions[_b]);
}

void dfs(int u, int p = -1) {
  used[u] = 1;
  tin[u] = timer++;
  for (int to: gr[u]) {
    cout << tttt << " | " << u << "->" << to << nl;
    if (used[to] == 0) {
      dfs(to, u);
    }
  }
  tout[u] = timer++;
}

int isAnc(int u, int v) {
  return tin[u] > tin[v] && tout[v] > tout[u];
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  while (cin >> n >> m >> i) {
    reset();
    for (int j = 0; j < n; ++j) {
      cin >> age[j];
    }

    for (int j = 0; j < m; ++j) {
      int u, v;
      cin >> u >> v, --u, --v;
      gr[u].push_back(v);
    }

    for (int j = 0; j < n; ++j) {
      if (!used[j]) {
        dfs(j);
        tttt++;
      }
    }

    char ask;
    for (int j = 0; j < i; ++j) {
      cin >> ask;
      if (ask == 'T') {
        cin >> a >> b, --a, --b;
        Swap(a, b);
      } else {
        cin >> a, --a;
        bool hasAns = false;
        int ans = 101;
        for (int k = 0; k < n; ++k) {
          if (k == a) continue;
          //cout << "u = " << aa << " v = " << kk << nl;
          if (isAnc(a, k)) {
            hasAns = true;
            ans = min(ans, age[positions[k]]);
          }
        }
        cout << (hasAns ? ans : '*') << nl;
      }
    }
  }


  return 0;
}
