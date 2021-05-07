#include<bits/stdc++.h>
using namespace std;

typedef int64_t ll;
const char nl = '\n';
#define len(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

const double eps = 1e-6;
double c;

bool good(double x) {
  double xx = x * x + sqrt(x);
  return xx - c <= eps;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> c;
  
  double l = 0, r = 1e5 + 1;
  for (int i = 0; i < 100; ++i) {
    double mid = l + (r - l) / 2.0;
    if (good(mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }

  cout << std::setprecision(20) << l << nl;

  return 0;
}