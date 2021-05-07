#include<bits/stdc++.h>
using namespace std;

typedef int64_t ll;
const char nl = '\n';
#define len(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

vector<vector<int>> gr;
vector<int> vis, deg;
int ok;

void dfs(int u) {
  vis[u] = true;
  ok &= deg[u] == 2;
  for (int to: gr[u]) {
    if (!vis[to]) {
      dfs(to);
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n, m;
  cin >> n >> m;
  gr.assign(n, vector<int>());
  deg.assign(n, 0);
  vis.assign(n, 0);

  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v, --u, --v;
    gr[u].push_back(v);
    gr[v].push_back(u);
    deg[u]++, deg[v]++;
  }
  int ans = 0;
  
  for (int i = 0; i < n; ++i) {
    if (!vis[i]) {
      ok = 1; dfs(i);
      ans += ok;
    }
  }

  cout << ans << nl;
  
  
  return 0;
}