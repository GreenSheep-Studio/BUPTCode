#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
  // 声明三个整数变量
  int a, b, c;
  // 输入三个整数
  cin >> a >> b >> c;
  // 将三个整数存储到一个 vector 中
  vector<int> nums = {a, b, c};
  // 对 vector 排序
  sort(nums.begin(), nums.end());
  // 输入三个大写字母，表示所需的顺序
  char order[3];
  cin >> order;
  // 输出三个整数，按照所需的顺序
  for (int i = 0; i < 3; i++) {
    if (order[i] == 'A') cout << nums[0] << " ";
    if (order[i] == 'B') cout << nums[1] << " ";
    if (order[i] == 'C') cout << nums[2] << " ";
  }
  return 0;
}
