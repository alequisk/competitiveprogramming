#include<bits/stdc++.h>
using namespace std;

typedef int64_t ll;
const char nl = '\n';
#define len(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

int sz = 0, gr_len = 0;
map<string, int> mp;
vector<vector<int>> gr;
vector<bool> vis;
vector<int> order, comp;

void topologic_order(int u) {
  vis[u] = true;
  for (int to: gr[u]) {
    if (!vis[to]) {
      topologic_order(to);
    }
  }
  order.push_back(u);
}

void dfs(int u, int c) {
  vis[u] = true;
  comp[c]++;
  for (int to: gr[u]) {
    if (!vis[to]) {
      dfs(to, c);
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  
  string str1, str2;

  while (cin >> str1 >> str2) {
    if (!mp.count(str1))  {
      mp[str1] = sz++;
    }
    if (!mp.count(str2))  {
      mp[str2] = sz++;
    }
    while (gr_len < sz) {
      gr.push_back(vector<int>());
      gr_len++;
    }
    gr[mp[str1]].push_back(mp[str2]);
  }

  vis.assign(sz, false);
  comp.assign(sz, 0);
  
  for (int i = 0; i < sz; ++i) {
    if (!vis[i]) {
      topologic_order(i);
    }
  }

  vis.assign(sz, false);

  int c = 0;
  for (int x: order) {
    if (!vis[x])
      dfs(x, c++);
  }
  int ans = 0;
  for (int i = 0; i < sz; ++i) {
    if (comp[i] > 1) ++ans;
  }
  
  cout << ans << nl;
  
  return 0;
}