#include <cassert>
#include <iostream>
#include <tuple>
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

void AssertEq(ListNode *lhs, ListNode *rhs) {
  while (lhs) {
    assert(rhs);
    assert(lhs->val == rhs->val);
    lhs = lhs->next;
    rhs = rhs->next;
  }
}

class Solution {
 public:
  ListNode *addTwoNumbers(ListNode *a, ListNode *b) {
    bool carry = false;
    int value = 0;
    ListNode result{-1};
    ListNode *last = nullptr;
    while (a and b) {
      tie(carry, value) = add(a->val, b->val, carry);
      ListNode* l = new ListNode{value};
      if (last) {
        last->next = l;
      }
      last = l;
      if (not result.next) { result.next = l; }
      a = a->next;
      b = b->next;
    }
    while (a) {
      tie(carry, value) = add(a->val, 0, carry);
      ListNode* l = new ListNode{value};
      if (last) {
        last->next = l;
      }
      last = l;
      if (not result.next) { result.next = l; }
      a = a->next;
    }
    while (b) {
      tie(carry, value) = add(0, b->val, carry);
      ListNode* l = new ListNode{value};
      if (last) {
        last->next = l;
      }
      last = l;
      if (not result.next) { result.next = l; }
      b = b->next;
    }
    if (carry) {
      ListNode* l = new ListNode{1};
      if (last) {
        last->next = l;
      }
      last = l;
      if (not result.next) { result.next = l; }
    }

    return result.next;
  }
 private:
  pair<bool, int> add(int a, int b, int carry) {
    int result = a + b + carry;
    if (9 < result) {
      return {true, result % 10};
    }

    return {false, result};
  }
};

void TestAddTwoNumbers() {
  Solution s;
  {
    ListNode *a = MakeList({2, 4, 3});
    ListNode *b = MakeList({5, 6, 4});
    ListNode *c = MakeList({7, 0, 8});
    AssertEq(c, s.addTwoNumbers(a, b));
  }
  {
    ListNode *a = MakeList({0});
    ListNode *b = MakeList({0});
    ListNode *c = MakeList({0});
    AssertEq(c, s.addTwoNumbers(a, b));
  }
  {
    ListNode *a = MakeList({9, 9, 9, 9, 9, 9, 9});
    ListNode *b = MakeList({9, 9, 9, 9});
    ListNode *c = MakeList({8, 9, 9, 9, 0, 0, 0, 1});
    AssertEq(c, s.addTwoNumbers(a, b));
  }
}

int main() {
  TestAddTwoNumbers();
  std::cout << "Ok!" << std::endl;
  return 0;
}
