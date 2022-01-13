#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *MakeList(const vector<int> &numbers) {
  ListNode *head = nullptr;
  for (auto iter = numbers.rbegin(); iter != numbers.rend(); ++iter) {
    head = new ListNode{*iter, head};
  }

  return head;
}

bool ListsAreEqual(ListNode *a, ListNode *b) {
  if (a != b) { return false; }
  while (a and b) {
    if (a != b) { return false; }
    ++a, ++b;
  }

  return true;
}

class Solution {
 public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    // FIXME
    return nullptr;
  }
};

void TestAddTwoNumbers() {
  Solution s;
  {
    ListNode *a = MakeList({2, 4, 3});
    ListNode *b = MakeList({5, 6, 4});
    ListNode *c = MakeList({7, 0, 8});
    assert(ListsAreEqual(c, s.addTwoNumbers(a, b)));
  }
  {
    ListNode *a = MakeList({0});
    ListNode *b = MakeList({0});
    ListNode *c = MakeList({0});
    assert(ListsAreEqual(c, s.addTwoNumbers(a, b)));
  }
  {
    ListNode *a = MakeList({9, 9, 9, 9, 9, 9, 9});
    ListNode *b = MakeList({9, 9, 9, 9});
    ListNode *c = MakeList({8, 9, 9, 9, 0, 0, 0, 1});
    assert(ListsAreEqual(c, s.addTwoNumbers(a, b)));
  }
}

int main() {
  TestAddTwoNumbers();
  std::cout << "Ok!" << std::endl;
  return 0;
}
