#include <bits/stdc++.h>

#include <pprint/pprint.hpp>

using namespace std;

class Solution {
 private:
  vector<string> path;
  vector<vector<string>> ans;
  bool isFind;

  void backtracking(vector<vector<string>>& tickets, vector<bool>& used,
                    int lastIndex) {
    // 超时
    int len = tickets.size();
    if (path.size() == len) {
      path.push_back(tickets[lastIndex][1]);
      ans.push_back(path);
      path.pop_back();
      isFind = true;
      return;
    }

    for (int i = 0; i < len; i++) {
      if (isFind) return;
      if (path.size() == 0 && tickets[i][0] == "JFK" && !used[i]) {
        path.push_back(tickets[i][0]);
        used[i] = true;
        backtracking(tickets, used, i);
        used[i] = false;
        path.pop_back();
        continue;
      }
      if (path.size() > 0 && tickets[i][0] == tickets[lastIndex][1] &&
          !used[i]) {
        path.push_back(tickets[i][0]);
        used[i] = true;
        backtracking(tickets, used, i);
        used[i] = false;
        path.pop_back();
      }
    }
  }

 public:
  vector<string> findItinerary_v1(vector<vector<string>>& tickets) {
    // 超时
    path.clear();
    ans.clear();
    isFind = false;

    sort(tickets.begin(), tickets.end());

    vector<bool> used(tickets.size(), false);
    backtracking(tickets, used, 0);

    return ans.front();
  }
};

int main(int, char**) {
  Solution s;

  // ["JFK","MUC","LHR","SFO","SJC"]
  //   vector<vector<string>> tickets{
  //       {"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};

  // ["JFK","ATL","JFK","SFO","ATL","SFO"]
  //   vector<vector<string>> tickets{{"JFK", "SFO"},
  //                                  {"JFK", "ATL"},
  //                                  {"SFO", "ATL"},
  //                                  {"ATL", "JFK"},
  //                                  {"ATL", "SFO"}};

  vector<vector<string>> tickets{
      {"AXA", "EZE"}, {"EZE", "AUA"}, {"ADL", "JFK"}, {"ADL", "TIA"},
      {"AUA", "AXA"}, {"EZE", "TIA"}, {"EZE", "TIA"}, {"AXA", "EZE"},
      {"EZE", "ADL"}, {"ANU", "EZE"}, {"TIA", "EZE"}, {"JFK", "ADL"},
      {"AUA", "JFK"}, {"JFK", "EZE"}, {"EZE", "ANU"}, {"ADL", "AUA"},
      {"ANU", "AXA"}, {"AXA", "ADL"}, {"AUA", "JFK"}, {"EZE", "ADL"},
      {"ANU", "TIA"}, {"AUA", "JFK"}, {"TIA", "JFK"}, {"EZE", "AUA"},
      {"AXA", "EZE"}, {"AUA", "ANU"}, {"ADL", "AXA"}, {"EZE", "ADL"},
      {"AUA", "ANU"}, {"AXA", "EZE"}, {"TIA", "AUA"}, {"AXA", "EZE"},
      {"AUA", "SYD"}, {"ADL", "JFK"}, {"EZE", "AUA"}, {"ADL", "ANU"},
      {"AUA", "TIA"}, {"ADL", "EZE"}, {"TIA", "JFK"}, {"AXA", "ANU"},
      {"JFK", "AXA"}, {"JFK", "ADL"}, {"ADL", "EZE"}, {"AXA", "TIA"},
      {"JFK", "AUA"}, {"ADL", "EZE"}, {"JFK", "ADL"}, {"ADL", "AXA"},
      {"TIA", "AUA"}, {"AXA", "JFK"}, {"ADL", "AUA"}, {"TIA", "JFK"},
      {"JFK", "ADL"}, {"JFK", "ADL"}, {"ANU", "AXA"}, {"TIA", "AXA"},
      {"EZE", "JFK"}, {"EZE", "AXA"}, {"ADL", "TIA"}, {"JFK", "AUA"},
      {"TIA", "EZE"}, {"EZE", "ADL"}, {"JFK", "ANU"}, {"TIA", "AUA"},
      {"EZE", "ADL"}, {"ADL", "JFK"}, {"ANU", "AXA"}, {"AUA", "AXA"},
      {"ANU", "EZE"}, {"ADL", "AXA"}, {"ANU", "AXA"}, {"TIA", "ADL"},
      {"JFK", "ADL"}, {"JFK", "TIA"}, {"AUA", "ADL"}, {"AUA", "TIA"},
      {"TIA", "JFK"}, {"EZE", "JFK"}, {"AUA", "ADL"}, {"ADL", "AUA"},
      {"EZE", "ANU"}, {"ADL", "ANU"}, {"AUA", "AXA"}, {"AXA", "TIA"},
      {"AXA", "TIA"}, {"ADL", "AXA"}, {"EZE", "AXA"}, {"AXA", "JFK"},
      {"JFK", "AUA"}, {"ANU", "ADL"}, {"AXA", "TIA"}, {"ANU", "AUA"},
      {"JFK", "EZE"}, {"AXA", "ADL"}, {"TIA", "EZE"}, {"JFK", "AXA"},
      {"AXA", "ADL"}, {"EZE", "AUA"}, {"AXA", "ANU"}, {"ADL", "EZE"},
      {"AUA", "EZE"}};

  auto ans = s.findItinerary_v1(tickets);

  pprint::PrettyPrinter printer;
  printer.compact(true);
  printer.print(ans);
}