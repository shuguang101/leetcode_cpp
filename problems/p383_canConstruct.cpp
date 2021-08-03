#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    int charTable[26];
    memset(charTable, 0, sizeof(charTable));

    int len1 = ransomNote.size();
    int len2 = magazine.size();
    for (int i = 0; i < len2; i++) charTable[magazine[i] - 'a'] += 1;
    for (int i = 0; i < len1; i++) charTable[ransomNote[i] - 'a'] -= 1;

    for (int i = 0; i < 26; i++) {
      if (charTable[i] < 0) return false;
    }

    return true;
  }
};

int main(int, char**) {}