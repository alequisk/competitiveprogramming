#include<bits/stdc++.h>
using namespace std;

typedef int64_t ll;
const char nl = '\n';
#define len(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

vector<vector<int>> gr;
vector<int> dist, pr;
vector<char> vis;

void print(int p)  {
  if (p == 0) {
    cout << 1 << " ";
    return;
  }
  print(pr[p]);
  cout << p + 1 << " ";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  // resize
  gr.assign(n, vector<int>());
  pr.assign(n, 0);
  vis.assign(n, 0);
  dist.assign(n, 0x3f3f3f3f);

  for (int i = 0; i < n; ++i) pr[i] = i;

  for (int i = 0; i < m; ++i) {
    int u, v; cin >> u >> v, --u, --v;
    gr[u].push_back(v);
    gr[v].push_back(u);
  }

  queue<pair<int, int>> q;
  q.push({0, 0});
  dist[0] = 0;

  while (!q.empty()) {
    pair<int, int> t = q.front();
    q.pop();

    for (int to: gr[t.first]) {
      if (dist[to] > t.second + 1) {
        q.push({ to, t.second + 1 });
        dist[to] = t.second + 1;
        pr[to] = t.first;
      }
    }
  }


  if (dist[n - 1] == 0x3f3f3f3f) {
    cout << "IMPOSSIBLE" << nl;
    return 0;
  }

  cout << dist[n - 1] + 1 << nl;
  print(n - 1); cout << nl;


  return 0;
}