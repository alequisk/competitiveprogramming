#include<bits/stdc++.h>
using namespace std;

typedef int64_t ll;
const char nl = '\n';
#define len(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

vector<vector<int>> gr;
vector<int> vis, color;
int hasAns = true;


void dfs(int u, int c) {
  vis[u] = 1;
  color[u] = c;
  for (int to: gr[u]) {
    if (!vis[to]) {
      dfs(to, c ^ 1);
    } else if (color[to] == color[u]) {
      hasAns = false;
      return;
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  // resize
  gr.assign(n, vector<int>());
  vis.assign(n, 0);
  color.assign(n, -1);

  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v, --u, --v;
    gr[u].push_back(v);
    gr[v].push_back(u);
  }

  for (int i = 0; i < n; ++i) {
    if (!vis[i]) {
      dfs(i, 0);
    }
  }

  if (!hasAns) {
    cout << "IMPOSSIBLE" << nl;
    return 0;
  }

  for (int x: color) {
    cout << x + 1 << " ";
  } cout << nl;


  return 0;
}