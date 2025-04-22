#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include <iostream>
#include <vector>

// 链表节点定义
struct ListNode {
    int val;
    ListNode *next;
    
    // 构造函数
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    
    // 辅助函数：从数组创建链表
    static ListNode* createFromArray(const std::vector<int>& arr) {
        if (arr.empty()) return nullptr;
        
        ListNode* head = new ListNode(arr[0]);
        ListNode* current = head;
        
        for (size_t i = 1; i < arr.size(); ++i) {
            current->next = new ListNode(arr[i]);
            current = current->next;
        }
        
        return head;
    }
    
    // 辅助函数：打印链表
    static void printList(ListNode* head) {
        while (head) {
            std::cout << head->val;
            if (head->next) std::cout << " -> ";
            head = head->next;
        }
        std::cout << std::endl;
    }
    
    // 辅助函数：释放链表内存
    static void deleteList(ListNode* head) {
        while (head) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// 二叉树节点定义
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    
    // 构造函数
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    
    // 辅助函数：从层序遍历数组创建二叉树（支持空节点，用-1表示）
    static TreeNode* createFromArray(const std::vector<int>& arr) {
        if (arr.empty() || arr[0] == -1) return nullptr;
        
        TreeNode* root = new TreeNode(arr[0]);
        std::vector<TreeNode*> nodes = {root};
        size_t index = 0;
        
        for (size_t i = 1; i < arr.size(); ++i) {
            if (i % 2 == 1) { // 左子节点
                if (arr[i] != -1) {
                    nodes[index]->left = new TreeNode(arr[i]);
                    nodes.push_back(nodes[index]->left);
                }
            } else { // 右子节点
                if (arr[i] != -1) {
                    nodes[index]->right = new TreeNode(arr[i]);
                    nodes.push_back(nodes[index]->right);
                }
                index++;
            }
        }
        
        return root;
    }
    
    // 辅助函数：中序遍历打印二叉树
    static void inorderPrint(TreeNode* root) {
        if (!root) return;
        
        inorderPrint(root->left);
        std::cout << root->val << " ";
        inorderPrint(root->right);
    }
    
    // 辅助函数：释放二叉树内存
    static void deleteTree(TreeNode* root) {
        if (!root) return;
        
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
};

#endif // DATA_STRUCTURES_H