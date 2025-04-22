#include <iostream>
#include <queue>
#include <stack>
#include <functional>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

// 二叉树节点定义
struct Node {
  int val;
  Node* left;
  Node* right;

  Node() : val(0), left(nullptr), right(nullptr) {}
  Node(int x) : val(x), left(nullptr), right(nullptr) {}

  ~Node() {
    delete left;
    delete right;
  }
};

// 层序遍历
vector<int> levelOrder(Node* root) {
  vector<int> result;
  if (!root) return result;

  queue<Node*> q;
  q.push(root);

  while (!q.empty()) {
    Node* tempNode = q.front();
    q.pop();

    result.push_back(tempNode->val);

    if (tempNode->left) q.push(tempNode->left);
    if (tempNode->right)q.push(tempNode->right);
  }

  return result;
}

// 前序遍历（递归）
void frontOrder(Node* root, vector<int>& nums) {
  if (!root) return;
  nums.push_back(root->val);

  frontOrder(root->left, nums);
  frontOrder(root->right, nums);
}

// 前序遍历（迭代）
vector<int> frontOrder(Node* root) {
  vector<int> result;
  if (!root) return result;

  stack<Node*> s;
  s.push(root);

  while (!s.empty()) {
    Node* tempNode = s.top();
    result.push_back(tempNode->val);
    s.pop();

    if (tempNode->right) s.push(tempNode->right);
    if (tempNode->left) s.push(tempNode->left);
  }

  return result;
}

// 后序遍历（递归）
void postOrder(Node* root, vector<int>& nums) {
  if (!root) return;

  postOrder(root->left, nums);
  postOrder(root->right, nums);
  nums.push_back(root->val);
}

// 计算树高
int treeHeight(Node* root) {
  if (!root) return 0;
  
  int leftHeight = treeHeight(root->left);
  int rightHeight = treeHeight(root->right);
  
  return 1 + max(leftHeight, rightHeight);
}

// 垂直打印树
void printTreeVertical(Node* root) {
  if (!root) return;
  
  // 计算树的高度
  std::function<int(Node*)> height = [&](Node* node) -> int {
    if (!node) return 0;
    return 1 + std::max(height(node->left), height(node->right));
  };
  
  int h = height(root);
  
  // 创建一个二维字符数组来存储树的可视化表示
  std::vector<std::vector<std::string>> treeArray(2 * h - 1, std::vector<std::string>(std::pow(2, h) - 1, " "));
  
  // 填充二维数组
  std::function<void(Node*, int, int, int)> fillArray = [&](Node* node, int row, int left, int right) {
    if (!node) return;
    
    int mid = (left + right) / 2;
    treeArray[row][mid] = std::to_string(node->val);
    
    // 添加左斜线
    if (node->left) {
      int nextRow = row + 2;
      int nextMid = (left + mid - 1) / 2;
      treeArray[row + 1][mid - 1] = "/";
      fillArray(node->left, nextRow, left, mid - 1);
    }
    
    // 添加右斜线
    if (node->right) {
      int nextRow = row + 2;
      int nextMid = (mid + 1 + right) / 2;
      treeArray[row + 1][mid + 1] = "\\";
      fillArray(node->right, nextRow, mid + 1, right);
    }
  };
  
  fillArray(root, 0, 0, std::pow(2, h) - 1);
  
  // 打印二维数组
  for (const auto& row : treeArray) {
    for (const auto& cell : row) {
      std::cout << cell;
    }
    std::cout << std::endl;
  }
}

// 后序遍历（迭代）
vector<int> postOrder(Node* root) {
  vector<int> result;
  if (!root) return result;

  stack<Node*> s1, s2;
  s1.push(root);

  while (!s1.empty()) {
    Node* tempNode = s1.top();
    s2.push(tempNode);
    s1.pop();

    if (tempNode->left) s1.push(tempNode->left);
    if (tempNode->right) s1.push(tempNode->right);
  }
 
  while (!s2.empty()) {
    result.push_back(s2.top()->val);
    s2.pop();
  }

  return result;
}

// 中序遍历（迭代）
vector<int> middleOrder(Node* root) {
  vector<int> result;
  if (!root) return result;

  stack<Node*> s;
  Node* current = root;

  while (current || !s.empty()) {
    // 将所有左子节点入栈
    while (current) {
      s.push(current);
      current = current->left;
    }
    
    // 处理栈顶节点
    current = s.top();
    s.pop();
    
    // 访问当前节点
    result.push_back(current->val);
    
    // 处理右子树
    current = current->right;
  }

  return result;
}

// 测试二叉树功能
void testBinaryTree() {
  cout << "\n===== 测试案例1: 手动构建的二叉树 =====" << endl;
  Node* root1 = new Node(1);
  root1->left = new Node(2);
  root1->right = new Node(3);
  root1->left->left = new Node(4);
  root1->left->right = new Node(5);
  root1->right->left = new Node(6);
  root1->left->left->left = new Node(7);
  root1->left->left->right = new Node(8);
  root1->left->left->left->left = new Node(9);

  cout << "二叉树形状:" << endl;
  printTreeVertical(root1);
  cout << endl;

  cout << "层序遍历: ";
  for (auto& val : levelOrder(root1)) {
    cout << val << " ";
  }
  cout << endl;

  cout << "先序遍历: ";
  for (auto& val : frontOrder(root1)) {
    cout << val << " ";
  }
  cout << endl;

  cout << "中序遍历: ";
  for (auto& val : middleOrder(root1)) {
    cout << val << " ";
  }
  cout << endl;

  cout << "后序遍历: ";
  for (auto& val : postOrder(root1)) {
    cout << val << " ";
  }
  cout << endl;
  
  cout << "树高: " << treeHeight(root1) << endl;
  
  // 释放内存
  delete root1;
}

int main() {
  testBinaryTree();
  return 0;
}