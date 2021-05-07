#include<bits/stdc++.h>
using namespace std;

typedef int64_t ll;
const char nl = '\n';
#define len(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

vector<vector<int>> gr;
vector<char> vis;
vector<pair<int, int>> ans;

void dfs(int u) {
  vis[u] = true;
  for (int to: gr[u]) {
    if (!vis[to]) dfs(to);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  // resize
  gr.assign(n, vector<int>());
  vis.assign(n, 0);

  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v, --u, --v;
    gr[u].push_back(v);
    gr[v].push_back(u);
  }

  int last = 0, c = 0;
  for (int i = 0; i < n; ++i) {
    if (!vis[i]) {
      dfs(i);
      if (c > 0) ans.push_back({last + 1, i + 1});
      ++c, last = i;
    }
  }

  cout << len(ans) << nl;
  for (auto x: ans) {
    cout << x.first << " " << x.second << nl;
  }

  return 0;
}