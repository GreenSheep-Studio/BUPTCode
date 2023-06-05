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

TreeNode *  Search(TreeNode * Tree, int key) {
    if (Tree == NULL) return NULL;
    else{
        if (Tree ->date == key) return Tree;
        else if (Tree ->date < key) return Search(Tree ->r_ch, key);
        else if (Tree ->date > key) return Search(Tree ->l_ch, key);
    }
}

bool Delete(TreeNode * p) {
    TreeNode *q, *s;
    if (p ->r_ch == NULL && p ->l_ch == NULL) p = NULL;
    else if (p ->r_ch == NULL && p ->l_ch != NULL) {
        q = p;
        p = p ->l_ch;
        delete q;
    }
    else if (p ->r_ch != NULL && p ->l_ch == NULL) {
        q = p;
        p = p ->r_ch;
        delete q;
    }
    else if (p ->r_ch != NULL && p ->l_ch != NULL) {
        q = p;
        s = p ->r_ch;
        while (s ->r_ch != NULL){
            q = s;
            s = s ->l_ch;
            if(s == NULL) break;
        }
        p = s;
        if (q != p) q ->l_ch = s ->r_ch;
        else q ->r_ch = s ->r_ch;
        delete q;
    }
    return true;
}

bool DeleteNode(TreeNode * Tree, int key){
    if (Tree == NULL) return false;
    else{
        if (Tree ->date == key) 
            return Delete(Tree);
        else if (Tree ->date < key) 
            return DeleteNode(Tree ->r_ch, key);
        else if (Tree ->date > key) 
            return DeleteNode(Tree ->l_ch, key);
    }
}

int main ()
{
    TreeNode * BitsTree;
    int arr[5] = {3, 5, 8, 1,0 6};
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
    cout << (Search (BitsTree, 6)) ->date << endl;
    DeleteNode(BitsTree, 3);
    MidShow(BitsTree);
    //cout << "1 5 6 8" << endl;
    cout << endl;
    system("PAUSE");
    return 0;
}