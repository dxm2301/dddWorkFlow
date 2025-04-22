#include <iostream>
#include <vector>

using namespace std;

// 链表节点定义
struct ListNode {
  int val;
  ListNode* next;
  
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// 打印链表
void printList(ListNode* head) {
  while (head) {
    cout << head->val;
    if (head->next) cout << " -> ";
    head = head->next;
  }
  cout << endl;
}

// 反转链表
ListNode* reverseList(ListNode* head) {
  ListNode* prev = nullptr;
  ListNode* curr = head;
  
  while (curr) {
    ListNode* nextTemp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nextTemp;
  }
  
  return prev;
}

// 查找链表中间节点
ListNode* middleList(ListNode* head) {
  if (!head) return nullptr;
  ListNode* slow = head;
  ListNode* fast = head;

  while (fast->next && fast->next->next) {
    fast = fast->next->next;
    slow = slow->next;
  }

  return slow;
}

// 合并两个链表（交替合并）
void mergeList(ListNode* l1, ListNode* l2) {
  while (l1 && l2) {
    ListNode* l1next = l1->next;
    ListNode* l2next = l2->next;

    l1->next = l2;
    l2->next = l1next;

    l1 = l1next;
    l2 = l2next;
  }
}

// 检测链表是否有环
bool hasCycle(ListNode* head) {
  if (!head || !head->next) return false;

  ListNode* slow = head;
  ListNode* fast = head;

  while (fast->next && fast->next->next) {
    fast = fast->next->next;
    slow = slow->next;

    if (fast == slow) return true;
  }

  return false;
}

// 合并两个有序链表
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
  ListNode* dummy = new ListNode(0);
  ListNode* cur = dummy;

  while (l1 && l2) {
    if (l1->val <= l2->val) {
      cur->next = l1;
      l1 = l1->next;
    } else {
      cur->next = l2;
      l2 = l2->next;
    }
    cur = cur->next;
  }

  cur->next = l1 ? l1 : l2;
  return dummy->next;
}

// 查找两个链表的交点
ListNode* findInstersect(ListNode* l1, ListNode* l2) {
  if (!l1 || !l2) return nullptr;

  while (l1 != l2) {
    l1 = l1 ? l1->next : l2;
    l2 = l2 ? l2->next : l1;
  }

  return l1;
}

// 重排链表
ListNode* reorderList(ListNode* head) {
  if (!head || !head->next) return head;
  ListNode* middle = middleList(head);
  ListNode* l2 = middle->next;
  middle->next = nullptr;
  l2 = reverseList(l2);
  ListNode* l1 = head;
  mergeTwoLists(l1, l2);

  return l1;
}

// 查找链表倒数第k个节点
ListNode* findKthFromEnd(ListNode* head, int k) {
  ListNode* fast = head;
  for (int i = 0; i < k; ++i) {
    if (!fast) return nullptr;
    fast = fast->next;
  }

  ListNode* slow = head;
  while (fast) {
    fast = fast->next;
    slow = slow->next;
  }

  return slow;
}

ListNode* sortList(ListNode* head) {
  if (!head || !head->next) return head;

  ListNode* mid = middleList(head);
  ListNode* l2 = mid->next;
  mid->next = nullptr;
  ListNode* l1 = head;

  l1 = sortList(l1);
  l2 = sortList(l2);

  return mergeTwoLists(l1, l2);
}

ListNode* rotateList(ListNode* head, int k) {
  if (!head || !head->next) return head;

  int n = 1;
  ListNode* tail = head;
  while (tail->next) {
    n++;
    tail = tail->next;
  }

  k = k % n;
  if (k == 0) return head;
  ListNode* newTail = head;
  for (int i = 0; i < n - k - 1; ++i) {
    newTail = newTail->next;
  }
  ListNode* newHead = newTail->next;
  newTail->next = nullptr;
  tail->next = head;

  return newHead;
}

// 从数组创建链表
ListNode* createListFromArray(const vector<int>& arr) {
  if (arr.empty()) return nullptr;
  
  ListNode* head = new ListNode(arr[0]);
  ListNode* current = head;
  
  for (size_t i = 1; i < arr.size(); i++) {
    current->next = new ListNode(arr[i]);
    current = current->next;
  }
  
  return head;
}

// 创建有环链表
ListNode* createCyclicList(const vector<int>& arr, int pos) {
  if (arr.empty() || pos >= arr.size()) return nullptr;
  
  ListNode* head = createListFromArray(arr);
  if (pos == -1) return head; // 无环
  
  // 找到环的入口点
  ListNode* cycleStart = head;
  for (int i = 0; i < pos; i++) {
    cycleStart = cycleStart->next;
  }
  
  // 找到链表尾部
  ListNode* tail = head;
  while (tail->next) {
    tail = tail->next;
  }
  
  // 创建环
  tail->next = cycleStart;
  
  return head;
}

// 释放链表内存（无环）
void deleteList(ListNode* head) {
  while (head) {
    ListNode* temp = head;
    head = head->next;
    delete temp;
  }
}

// 释放有环链表内存
void deleteCyclicList(ListNode* head) {
  if (!head) return;
  
  // 先断开环
  if (hasCycle(head)) {
    ListNode* slow = head;
    ListNode* fast = head;
    
    // 找到相遇点
    do {
      slow = slow->next;
      fast = fast->next->next;
    } while (slow != fast);
    
    // 找到环的入口
    slow = head;
    while (slow->next != fast->next) {
      slow = slow->next;
      fast = fast->next;
    }
    
    // 断开环
    fast->next = nullptr;
  }
  
  // 释放内存
  deleteList(head);
}

// 测试链表功能
void testLinkedList() {
  cout << "\n===== 测试案例1: 链表反转 =====" << endl;
  ListNode* list1 = createListFromArray({1, 2, 3, 4, 5});
  
  cout << "原始链表: ";
  printList(list1);
  
  ListNode* reversed = reverseList(list1);
  cout << "反转后链表: ";
  printList(reversed);
  
  deleteList(reversed);
  
  cout << "\n===== 测试案例2: 查找中间节点 =====" << endl;
  ListNode* list2 = createListFromArray({1, 2, 3, 4, 5});
  
  cout << "链表: ";
  printList(list2);
  
  ListNode* middle = middleList(list2);
  cout << "中间节点值: " << middle->val << endl;
  
  deleteList(list2);
  
  cout << "\n===== 测试案例3: 合并有序链表 =====" << endl;
  ListNode* list3a = createListFromArray({1, 3, 5, 7, 9});
  ListNode* list3b = createListFromArray({2, 4, 6, 8, 10});
  
  cout << "链表1: ";
  printList(list3a);
  cout << "链表2: ";
  printList(list3b);
  
  ListNode* merged = mergeTwoLists(list3a, list3b);
  cout << "合并后: ";
  printList(merged);
  
  deleteList(merged);
  
  cout << "\n===== 测试案例4: 检测环 =====" << endl;
  ListNode* list4a = createListFromArray({1, 2, 3, 4, 5});
  ListNode* list4b = createCyclicList({1, 2, 3, 4, 5}, 2); // 环在位置2
  
  cout << "无环链表: ";
  printList(list4a);
  cout << "是否有环: " << (hasCycle(list4a) ? "是" : "否") << endl;
  
  cout << "有环链表 (不打印以避免无限循环)" << endl;
  cout << "是否有环: " << (hasCycle(list4b) ? "是" : "否") << endl;
  
  deleteList(list4a);
  deleteCyclicList(list4b);
  
  cout << "\n===== 测试案例5: 重排链表 =====" << endl;
  ListNode* list5 = createListFromArray({1, 2, 3, 4, 5, 6});
  
  cout << "原始链表: ";
  printList(list5);
  
  ListNode* reordered = reorderList(list5);
  cout << "重排后链表: ";
  printList(reordered);
  
  deleteList(reordered);
  
  cout << "\n===== 测试案例6: 查找倒数第K个节点 =====" << endl;
  ListNode* list6 = createListFromArray({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
  
  cout << "链表: ";
  printList(list6);
  
  int k = 3;
  ListNode* kthFromEnd = findKthFromEnd(list6, k);
  cout << "倒数第" << k << "个节点值: " << kthFromEnd->val << endl;

  deleteList(list6);

  cout << "\n===== 测试案例7: 链表排序 =====" << endl;
  ListNode* list7 = createListFromArray({4, 2, 1, 3, 5, 6, 0});
  
  cout << "原始链表: ";
  printList(list7);
  
  ListNode* sorted = sortList(list7);
  cout << "排序后链表: ";
  printList(sorted);
  
  deleteList(sorted);

  cout << "\n===== 测试案例8: 旋转链表 =====" << endl;
  ListNode* list8 = createListFromArray({1, 2, 3, 4, 5});
  
  cout << "原始链表: ";
  printList(list8);
  
  int rotateK = 2;
  ListNode* rotated = rotateList(list8, rotateK);
  cout << "向右旋转" << rotateK << "个位置后: ";
  printList(rotated);
  
  deleteList(rotated);
}

int main() {
  testLinkedList();
  return 0;
}