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
    if(root == nullptr){
        return true;
    }
    queue<Node*> q;
    Node* p;
    q.push(root);
    while(!q.empty()){
        p = q.front();
        q.pop();
        if(p != nullptr){
            q.push(p->left);
            q.push(p->right);
        } else {
            while(!q.empty()){
                if(q.front() != nullptr)    return false;
                q.pop();
            }
        }
    }
    return true;
}

/*
 * 8.计算一个给定二叉树的所有双分支结点的个数；
 */ 
int twoNodeSum(Node* root){
    if(root == nullptr) return 0;
    else if(root->left != nullptr && root->right != nullptr)   return 1 + twoNodeSum(root->right) + twoNodeSum(root->left);
    else    return twoNodeSum(root->left) + twoNodeSum(root->right);
}

/*
 * 9. 编写一个把树 B 中的所有结点的左、右子树进行行交换的函数；
 */
void swapLeftAndRight(Node* root){
    if(root == nullptr) return;
    else {
        swapLeftAndRight(root->left);
        swapLeftAndRight(root->right);
        Node* p = root->left;
        root->left = root->right;
        root->right = p;
        
    }
}

/*
 * 10. 求先序遍历序列中第 k 个结点的值；
 */
int cnt = 0;
void preOrderOfKth(Node* root, int k){
    if(root){
        cnt++;
        if(k == cnt){
            cout << root->data << endl;
            return;
        }    
        preOrderOfKth(root->left, k);
        preOrderOfKth(root->right, k);
    }
}

// 先序建立二叉树：10 6 4 0 0 8 0 0 14 12 0 0 0；
void createBiTree(Node* &T)  
{  
    int data;
    cin >> data;
    if(data == 0){
        T = nullptr;
    } else {
        T = new Node();
        T->data = data;
        T->left = T->right = nullptr;
        createBiTree(T->left);
        createBiTree(T->right);
    }    
}

/*
 * 11. 对于树中每个值为 x 的结点， 删除以它为根的子树，并且释放空间；
 */
// 删除以 root 为根结点的子树；
void delNode(Node* root){
    if(root){
        delNode(root->left);
        delNode(root->right);
        delete root;
    }
}
// 找结点值为 x 的结点；
void search(Node* root, int x){
    queue<Node*> q;
    if(root){
        if(root->data == x){
            delNode(root);
            return;
        }
        q.push(root);
        Node* p;
        while(!q.empty()){
            p = q.front();
            q.pop();
            if(p->left){
                if(p->left->data == x){
                    delNode(p->left);
                    p->left = nullptr;
                } else {
                    q.push(p->left);
                }
            } 
            if(p->right){
                if(p->right->data == x){
                    delNode(p->right);
                    p->right = nullptr;
                } else {
                    q.push(p->right);
                }
            } 
        }
    }
}

/*
 * 12. 打印值为 x 的结点的所有祖先；(后序遍历)
 */ 
void findAnceOfX(Node* root, int x){
    Node* pre = nullptr;
    Node* p = root;
    stack<Node*> s;
    while(p || !s.empty()){
        if(p){
            s.push(p);
            p = p->left;
        } else {
            p = s.top();
            if(p->right && p->right != pre){
                p = p->right;
            } else {
                s.pop();
                if(p->data == x){
                    while(!s.empty()){
                        cout << s.top()->data<< endl;
                        s.pop();
                    }
                    return;
                }
                pre = p;
                p = nullptr;
            }
        }
    }
}

/*
 * 13. 找 p 和 q 的最近公共祖先结点 r；
 *  或者利用后序遍历的特点，栈中元素都是当前元素的祖先。
 */
Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    if(root == NULL) return root; //树空返回root
    if(root == p || root == q) return root; //找到p和q返回root
    Node* lNode = lowestCommonAncestor(root->left,p,q);
    Node* rNode = lowestCommonAncestor(root->right,p,q);
    if(lNode != NULL && rNode != NULL) return root; //p，q分别在左右子树
    else if(lNode == NULL) return rNode; //左边没有
    else return lNode; //右边没有
}

/*
 * 14. 求二叉树 B 的宽度；
 */ 
int widthOfTree(Node* root){
    if(!root)   return 0;
    queue<Node*> q;
    q.push(root);
    Node* p;
    int cnt = 0;
    int size = 1;
    int width = INT_MIN;
    while(!q.empty()){
        width = max(size, width);
        p = q.front();
        q.pop();
        if(p->left) q.push(p->left);
        if(p->right)    q.push(p->right);
        cnt++;
        if(cnt == size){
            cnt = 0;
            size = q.size();
        }
    }
    return width;
}

/*
 * 15. 根据满二叉树的先序序列求其后序序列；
 */
void preToPost(int pre[], int h1, int r1, int post[], int h2, int r2){
    int half;
    if(h1 <= r1){
        post[r2] = pre[h1];
        half = (r1 - h1) / 2;
        preToPost(pre, h1 + 1, h1 + half, post, h2, h2 + half - 1);
        preToPost(pre, h1 + half + 1, r1, post, h2 + half, r2 - 1);
    }
}

/*
 * 16. 将二叉树中的叶子结点从左向右连成一个单链表；
 */
Node *head, *pre = nullptr;
Node* InOrder(Node* root){
    if(root){
        InOrder(root->left);
        if(root->left == nullptr && root->right == nullptr){
            if(pre == nullptr){
                head = root;
                pre = root;
            } else {
                pre->right = root;
                pre = root;
            }
        }
        InOrder(root->right);
        pre->right = nullptr;
    }
    return head;
}

/*
 * 17. 判断两个二叉树是否相似；
 */
bool isSimilar(Node* root1, Node* root2){
    if(root1 == nullptr && root2 == nullptr)    return true;
    else if(root1 == nullptr || root2 == nullptr)   return false;
    else    return isSimilar(root1->left, root2->left) && isSimilar(root1->right, root2->right);
}

/*
 * 18. 查找中序线索二叉树里面指定结点在后序中的前驱结点；
 */
// Node* InPostPre(Node* root, Node* p){
//     Node* q;
//     if(p->rtag == 0){
//         q = p->right;
//     } else if(p->ltag == 0{
//         q = p->left;
//     } else if(p->left == nullptr){
//         q = nullptr;
//     } else {
//         while(p->ltag == 1 && p->left != nullptr){
//             p = p->left;
//         }
//         if(p->ltag == 0){
//             q = p->left;
//         } else {
//             q = nullptr;
//         }
//     }
//     return q;
// }

/*
 * 19.（2014）求二叉树的带权路径长度；
 */
// 基于先序遍历；
int wpl_helper(Node* root, int deep){
    static int wpl = 0;
    if(root->left == nullptr && root->right == nullptr){
        wpl += deep * root->data;
    } 
    if(root->left != nullptr)   wpl_helper(root->left, deep + 1);
    if(root->right != nullptr)  wpl_helper(root->right, deep + 1);
    return wpl;
}
int WPL(Node* root){
    return wpl_helper(root, 0);
}

/*
 * 20.（2017）转化为中缀表达式；
 */
void Tree_helper(Node* root, int deep){
    if(root == nullptr) return;
    else if(root->left == nullptr && root->right == nullptr){
        cout << root->data;
    } else {
        if(deep > 1)    cout << "(";
        Tree_helper(root->left, deep + 1);
        cout << root->data;
        Tree_helper(root->right, deep + 1);
        if(deep > 1)    cout << ")";
    }
}
void TreeToExpre(Node* root){
    Tree_helper(root, 1);
}

// 二叉排序树 BST 的插入；
int BST_Insert(Node* &root, int key){
    if(root == nullptr){
        root = new Node();
        root->data = key;
        root->left = nullptr;
        root->right = nullptr;
        return 1;
    } else if(root->data == key){
        return 0;
    } else if(root->data > key){
        return BST_Insert(root->left, key);
    } else {
        return BST_Insert(root->right, key);
    }
} 

// 判断一个二叉树是否是二叉排序树
bool isBST(Node* root){
    if(root == nullptr) return true;
    else {
        if(root->left == nullptr && root->right == nullptr){
            return true;
        } else if(root->left != nullptr && root->right != nullptr){
            if(root->left->data < root->data && root->right->data > root->data)
                return true && isBST(root->left) && isBST(root->right);
            else 
                return false;
        } else if(root->left != nullptr && root->right == nullptr){
            if(root->left->data < root->data)
                return true && isBST(root->left);
            else 
                return false;
        } else {
            if(root->right->data > root->data)
                return true && isBST(root->right);
            else 
                return false;
        }
    }
}

int p = INT_MIN;
bool isBST_1(Node* root){
    bool bl, br;
    if(root == nullptr) return true;
    else {
        bl = isBST_1(root->left);
        if(bl == false || root->data < p)
            return false;
        p = root->data;
        br = isBST_1(root->right);
        return br;
    }
}

// 判断一棵二叉树是否为平衡二叉树
int depth(Node* root){
    if(root == nullptr) return 0;
    return max(1 + depth(root->left), 1 + depth(root->right));
}

bool isAVL(Node* root){
    if(root == nullptr) return true;
    int dis = abs(depth(root->left) - depth(root->right));
    if(dis < 2) return isAVL(root->left) && isAVL(root->right);
    else    return false;
}

// 输出目标和的所有路径
void dfs(Node* root, int target, stack<int> path){
    if(root == nullptr) return;
    target -= root->data;
    path.push(root->data);
    if(root->left == nullptr && root->right == nullptr && target == 0){
        while(!path.empty()){
            cout << path.top() << endl;
            path.pop();
        }
        return;
    }
    dfs(root->left, target, path);
    dfs(root->right, target, path);
}


int main(){
    Node* root;
    createBiTree(root);
    // cout << isBST(root);
    // cout << isBST_1(root);
    // cout << isAVL(root);
    stack<int> path;
    dfs(root, 35, path);
    // TreeToExpre(root);
    // cout << WPL(root) << endl;
    // cout << widthOfTree(root);
    // findAnceOfX(root, 8);
    // preOrder(root);
    // preOrderOfKth(root, 20);
    return 0;
}