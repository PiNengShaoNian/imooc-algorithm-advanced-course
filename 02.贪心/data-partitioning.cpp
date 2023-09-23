#include <bits/stdc++.h>
using namespace std;

const int MAX_RAND_TIME = 1000000;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;
  int a[n];
  double avg = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    avg += a[i];
  }

  avg /= m;

  double res = INT_MAX;
  for (int times = 0; times < MAX_RAND_TIME; times++) {
    random_shuffle(a, a + n);
    int sum[m];
    memset(sum, 0, sizeof(sum));

    // 贪心，对于n个数，每次选择m个分组中当前总和（sum）最小的一个将其放入
    // 这样得到的分组会比较平均
    for (int i = 0; i < n; i++) {
      int min_j = 0;
      for (int j = 1; j < m; j++) {
        if (sum[j] < sum[min_j]) {
          min_j = j;
        }
      }
      sum[min_j] += a[i];

      // 计算均方差并更新最优解
      double s = 0;
      for (int i = 0; i < m; i++) {
        s += (avg - sum[i]) * (avg - sum[i]);
      }
      s = sqrt(s / m);
      res = min(res, s);
    }
  }

  // 输出结果
  cout << fixed << setprecision(2) << res << endl;
  return 0;
}