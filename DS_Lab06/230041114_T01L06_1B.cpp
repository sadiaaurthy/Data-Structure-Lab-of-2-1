#include<iostream>
#include<queue>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node* par;
    int height;
};
Node* root = nullptr;
Node* CreateNode(int x){
    Node* newNode = new Node();
    newNode->data = x;
    newNode->left = newNode->right = newNode->par = nullptr;
    newNode->height = 0;
    return newNode;
}
void insert(int x) {
    Node* newNode = CreateNode(x);
    if (root == nullptr) {
        root = newNode;
        return;
    }
    Node* temp = root;
    Node* tar = nullptr;
    while (temp != nullptr) {
        tar = temp;
        if (newNode->data < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    newNode->par = tar;
    if (newNode->data < tar->data)
        tar->left = newNode;
    else
        tar->right = newNode;
}

void inorder(Node* root){
    if (root == nullptr){
        return ;
    }
    else{
        inorder(root->left);
        cout << root->data << "(";
        if(root->par == nullptr){
            cout << "null) ";
        }
        else{
            cout <<root->par->data << ") ";
        }
        inorder(root->right);
    }
}
void preorder(Node* root){
    if(root == nullptr){
        return ;
    }
    cout << root->data << "(";
    if(root->par == nullptr){
        cout << "null) ";
    }
    else{
        cout << root->par->data << ") ";
    }
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root){
    if(root == nullptr){
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << "(";
    if(root->par == nullptr){
        cout << "null) ";
    }
    else{
        cout << root->par->data << ") ";
    }
}
void levelorder(Node* root){
    if(root == nullptr) return ;
    queue<Node*> q;
    q.push(root);
    int level = 1;
    while(!q.empty()){
        int nodes = q.size();
        cout << "Level "<< level << ": ";
        while(nodes > 0){
            Node* curr = q.front();
            q.pop();
            if(curr->par == nullptr) {
                cout <<curr->data << "(null) "; 
            } else {
                cout << curr->data << "(" << curr->par->data << ") ";
            }
            if(curr->left != nullptr) q.push(curr->left);
            if(curr->right != nullptr) q.push(curr->right);
            nodes--;
        }
        cout << endl;
        level++;
    }
}
int main(){
    int n;
    cin >> n;
    int cnt = 0;
    int val;
    while(cnt < n){
        cin >> val;
        insert(val);
        cnt++;
    }
    int b;
    while(1){
        cin >> b;
        switch(b){
            case 1:{
                inorder(root);
                cout << endl;
                break;
            }
            case 2:{
                preorder(root);
                cout << endl;
                break;
            }
            case 3:{
                postorder(root);
                cout << endl;
                break;
            }
            case 4:{
                levelorder(root);
                break;
            }
            case 5: return 0;
        }
    }

}
