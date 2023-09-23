#include <bits/stdc++.h>
using namespace std;

int num[105];
int n;
int ave;
int tot;
int ans;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> num[i];
    tot += num[i];
  }
  ave = tot / n;
  for (int i = 1; i <= n; i++) {
    num[i] -= ave;
  }

  for (int i = 1; i < n; i++) {
    if (num[i] == 0) {
      continue;
    }
    num[i + 1] += num[i];
    ans++;
  }

  cout << ans;
  return 0;
}