#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // 输入部分
  int m, k;
  cin >> m >> k;
  int b[m], tot = 0;
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    // 累加书的总页数
    tot += b[i];
  }

  // 设置二分答案下限为书的总页数 / k（即平均页数），上限为书的总页数
  int l = tot / k, r = tot;

  // resp用来记录抄书的最优划分方案，res记录最短复制时间
  int resp[m + 1], res = r;

  // 二分答案
  while (l < r) {
    // 每次设每个人的抄书时间上限t = l和r的中间值
    int t = (l + r) / 2;

    // seg是当上限为t时最少需要分成几段（即需要几个人）
    // count用来记录当前这个人已经抄的页数
    // period记录分段方案（即分段的断开点）
    int seg = 1, count = 0;
    int period[m + 1];
    // 贪心，如果当前这个人还能继续抄下一本书（即剩余时间还充裕），就把这本书给他抄
    // 否则就认为这个人已经分配了足够多的书，把这本书给下一个人
    for (int i = m - 1; i >= 0; i--) {
      // 特殊情况：如果一本书的页数大于时间上限，那么这本书给谁都无解
      // 所以直接跳出循环，返回无解（即分段数为正无穷）
      if (b[i] > t) {
        seg = INT_MAX;
        break;
      }
      if (count + b[i] <= t)
        count += b[i];
      else {
        count = b[i];
        period[seg++] = i + 1;
      }
    }

    // 如果刚好k个人可以抄完，且时间上限比当前最短复制时间更低，则说明存在更好的方案
    // 更新方案和最短复制时间
    if (seg == k && t < res) {
      res = t;
      memcpy(resp, period, sizeof(resp));
    }

    // 二分，如果分段数小于等于k（如果等于k则此时t >=
    // res），说明上限设高了，尝试左半边 否则尝试右半边
    if (seg <= k)
      r = t;
    else
      l = t + 1;
  }

  // 输出结果
  resp[0] = m;
  resp[k] = 0;
  for (int i = k - 1; i >= 0; i--) {
    cout << resp[i + 1] + 1 << ' ' << resp[i] << endl;
  }
  return 0;
}