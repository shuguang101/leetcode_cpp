#include <bits/stdc++.h>

int main(int, char**) {
  // 栈上分配内存空间, macos stack size ulimit: 8192 kbytes

  // int32_t: 3M
  int m = 3 * 1024, n = 1024 / 4;

  auto t1 = std::chrono::steady_clock::now();
  int32_t arr1[3 * 1024][1024 / 4]{0};
  auto t2 = std::chrono::steady_clock::now();
  int32_t arr2[m][n];
  memset(arr2, 0, sizeof(arr2));
  auto t3 = std::chrono::steady_clock::now();

  auto d1 = std::chrono::duration<double, std::milli>(t2 - t1).count();
  auto d2 = std::chrono::duration<double, std::milli>(t3 - t2).count();

  std::cout << "inti  : " << d1 << std::endl;
  std::cout << "memset: " << d2 << std::endl;
}