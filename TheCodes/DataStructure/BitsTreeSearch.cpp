#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int date;
    TreeNode * l_ch;
    TreeNode * r_ch;
};

TreeNode * CreatNode (int n){
    TreeNode *p = new TreeNode;
    p ->date = n;
    p ->l_ch = NULL;
    p ->r_ch = NULL;
    return p;
}

TreeNode * InsDate (TreeNode * root, int n) {
    if (root == NULL) {
        root = CreatNode(n);
        return root;
    }
    if (n < root ->date) {
        root ->l_ch = InsDate(root ->l_ch, n);
    }   
    else if (n > root ->date) {
        root ->r_ch = InsDate(root ->r_ch, n);
    }
    return root;
}

void MidShow(TreeNode * Tree) {
    if(Tree == NULL) return;
    MidShow(Tree ->l_ch);
    cout << Tree ->date << " ";
    MidShow(Tree ->r_ch);
}

void PreShow(TreeNode * Tree) {
    if(Tree == NULL) return;    
    cout << Tree ->date << " ";
    PreShow(Tree ->l_ch);
    PreShow(Tree ->r_ch);
}

int Search(TreeNode * Tree, int key) {
    
}

int main ()
{
    TreeNode * BitsTree = new TreeNode;
    int arr[5] = {1, 8, 6, 5, 3};
    BitsTree = NULL;
    for (int i = 0; i < 5; i++){
        BitsTree = InsDate(BitsTree, arr[i]);
    }
    cout << "PreShow" << endl;
    PreShow (BitsTree);
    cout << endl;
    cout << "MidShow" << endl;
    MidShow (BitsTree);
    cout << endl;
    cout << Search (BitsTree, 6, 1) << endl;
    system("PAUSE");
    return 0;
}