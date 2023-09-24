#include <bits/stdc++.h>
using namespace std;

int m, n;
int point[100], length[100];
bool hashOption[100];
int res;

void dfs(int k) {
  if (k == m) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
      count += !hashOption[i];
    }
    res = min(res, count);
    return;
  }

  for (int i = 1; i <= n; i++) {
    if (hashOption[i]) {
      int t = k + 1;
      int r = point[t] + length[i];
      while (t < m && point[t + 1] <= r) {
        t++;
      }
      hashOption[i] = false;
      dfs(t);
      hashOption[i] = true;
    }
  }
}

void dfs_init() {
  memset(hashOption, 1, sizeof(hashOption));
  res = INT_MAX;
  dfs(0);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> m >> n;
  for (int i = 1; i <= m; i++) cin >> point[i];
  for (int i = 1; i <= n; i++) cin >> length[i];

  dfs_init();

  cout << res << endl;
  return 0;
}