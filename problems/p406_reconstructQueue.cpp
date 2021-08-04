#include <bits/stdc++.h>

#include <pprint/pprint.hpp>

using namespace std;

class Solution {
 public:
  // 140ms
  vector<vector<int>> reconstructQueue_v1(vector<vector<int>>& people) {
    // 按照身高排序之后，优先按身高高的people的k来插入，后序插入节点也不会影响前面已经插入的节点
    // 降序排列, cmp(a,b)返回true时将a放在前面
    sort(people.begin(), people.end(), [](vector<int>& hk1, vector<int>& hk2) {
      if (hk1[0] == hk2[0]) return hk1[1] < hk2[1];
      return hk1[0] > hk2[0];
    });

    vector<vector<int>> ans;
    int len = people.size();
    for (int i = 0; i < len; i++) {
      ans.insert(ans.begin() + people[i][1], people[i]);
    }

    return ans;
  }

  // 28ms
  vector<vector<int>> reconstructQueue_v2(vector<vector<int>>& people) {
    // 按照身高排序之后，优先按身高高的people的k来插入，后序插入节点也不会影响前面已经插入的节点
    // 降序排列, cmp(a,b)返回true时将a放在前面
    sort(people.begin(), people.end(), [](vector<int>& hk1, vector<int>& hk2) {
      if (hk1[0] == hk2[0]) return hk1[1] < hk2[1];
      return hk1[0] > hk2[0];
    });

    // 链表插入效率高
    list<vector<int>> ans;
    int len = people.size();
    for (int i = 0; i < len; i++) {
      auto iter = begin(ans);
      advance(iter, people[i][1]);
      ans.insert(iter, people[i]);
    }

    return vector<vector<int>>(ans.begin(), ans.end());
  }
};

int main(int, char**) {
  Solution s;

  // [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
  vector<vector<int>> people{{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};

  //   auto ans = s.reconstructQueue_v1(people);
  auto ans = s.reconstructQueue_v2(people);

  pprint::PrettyPrinter printer;
  printer.compact(true);
  printer.print(ans);
}