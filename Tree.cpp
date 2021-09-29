#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct Node{
    Node* left;
    Node* right;
    int data;
};

// 树的非递归遍历

// 前序遍历
void preOrder(Node* root){
    Node* p = root;
    stack<Node*> s;
    while(p != nullptr || !s.empty()){
        if(p != nullptr){
            cout << p->data << endl;
            s.push(p);
            p = p->left;
        } else {
            p = s.top();
            s.pop();
            p = p->right;
        }
    }
}
// 中序遍历
void inOrder(Node* root){
    Node* p = root;
    stack<Node*> s;
    while(p != nullptr || !s.empty()){
        if(p != nullptr){
            s.push(p);
            p = p->left;
        } else {
            p = s.top();
            s.pop();
            cout << p->data << endl;
            p = p->right;
        }
    }
}

// 后序遍历
void postOrder(Node* root){
    Node* p = root;
    Node* pre = nullptr;    // 标记前一个打印的结点；
    stack<Node*> s;
    while(p != nullptr || !s.empty()){
        if(p != nullptr){
            s.push(p);
            p = p->left;
        } else {
            p = s.top();
            if(p->right != nullptr && p->right != pre){
                p = p->right;
            } else {
                s.pop();
                cout << p->data << endl;
                pre = p;
                p = nullptr;
            }
        }
    }
}

// 层序遍历
void levelOrder(Node* root){
    queue<Node*> q;
    Node* p;
    q.push(root);
    while(!q.empty()){
        p = q.front();
        q.pop();
        cout << p->data << endl;
        if(p->left != nullptr)  q.push(p->left);
        if(p->right != nullptr) q.push(p->right);    
    }
}

struct ThreadTreeNode{
    ThreadTreeNode* left;
    ThreadTreeNode* right;
    int ltag;
    int rtag;
};

// 中序遍历建立线索二叉树
void inThread(ThreadTreeNode* &p, ThreadTreeNode* &pre){
    if(p != nullptr){
        inThread(p->left, pre);
        
        if(p->left == nullptr){
            p->left = pre;
            p->ltag = 1;
        }
        if(p->right == nullptr){
            p->right = pre;
            p->rtag = 1;
        }
        pre = p;
        
        inThread(p->right, pre);
    }
}

void createInThread(ThreadTreeNode* &p){
    ThreadTreeNode* pre = nullptr;
    if(p){
        inThread(p, pre);
        pre->right = nullptr;
        pre->rtag = 1;
    }
}