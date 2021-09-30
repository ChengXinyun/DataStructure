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

/*
 * 4. 试给出二叉树的自下而上，自右而左的层次遍历算法。
 */
void levelOrderReverse(Node* root){
    queue<Node*> q;
    stack<int> s;
    Node* p;
    q.push(root);
    while(!q.empty()){
        p = q.front();
        s.push(p->data);
        q.pop();
        if(p->left) q.push(p->left);
        if(p->right)    q.push(p->right);
    }
    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }
}

/*
 * 5. 非递归算法求二叉树的高度
 */
int treeHigh(Node* root){
    if(root == nullptr) return 0;
    queue<Node*> q;
    Node* p;
    int count = 0;
    int size = 1;
    int high = 0;
    q.push(root);
    while(!q.empty()){
        p = q.front();
        q.pop();
        count++;
        if(p->left) q.push(p->left);
        if(p->right)    q.push(p->right);
        if(count == size){
            high++;
            count = 0; 
            size = q.size();
        }
        
    }
    return high;
}

/*
 * 递归算法求解二叉树的高度。
 */
int treeHigh_1(Node* root){
    if(root == nullptr) return 0;
    // 这两句可以不加，但是加了会更快；
    // if(root->left == nullptr)   return 1 + treeHigh_1(root->right);
    // if(root->right == nullptr)   return 1 + treeHigh_1(root->left);
    return 1 + max(treeHigh_1(root->left), treeHigh_1(root->right));
}

/*
 * 求某一层的结点个数
 */
int nodeNumOfKth(Node* root, int k){
    if(root == nullptr || k < 0) return -1;
    if(k == 0)  return 1;
    queue<Node*> q;
    Node* p;
    int cnt = 1; // 记录当前层数；
    int count = 0;  // 记录每一层的遍历个数
    int size = 1;
    q.push(root);
    while(!q.empty()){
        if(cnt == k){
            return q.size();
        }
        p = q.front();
        q.pop();
        count++;
        if(p->left) q.push(p->left);
        if(p->right)    q.push(p->right);
        if(count == size){
            cnt++;
            count = 0;
            size = q.size();
        }   
    }
    return -1;
}

/*
 * 6. 设一个二叉树的值各不相同，其先序序列和中序序列存储在两个数组中，编写算法建立该二叉树的二叉链表。
 */
Node* preInCreateTree(int num1[], int h1, int r1, int num2[], int h2, int r2){
    Node* root = new Node();
    root->data = num1[h1];
    int i = 0;
    for(i = h2; num2[i] != num1[h1]; i++){}
    int len1 = i - h2;
    int len2 = r2 - i;
    if(len1 != 0)   root->left = preInCreateTree(num1, h1 + 1, h1 + i, num2, h2, h2 + len1 - 1);
    else    root->left = nullptr;
    if(len2 != 0)   root->right = preInCreateTree(num1, r1 - len2 + 1 , r1, num2, r2 - len2 + 1, r2);
    else    root->right = nullptr;
    return root;
}

/*
 * 7. 判断一个二叉树是否为完全二叉树
 */ 
bool ifFullTree(Node* root){
    
}