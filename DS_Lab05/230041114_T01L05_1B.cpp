#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
    Node* head = nullptr;
    Node* tail = nullptr;
    bool isEmpty() {
        return head == nullptr && tail == nullptr;
    }
    Node* CreateNode(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;
        return newNode;
    }
    void insert_front(int key) {
        Node* newNode = CreateNode(key);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }
    void insert_back(int key) {
        Node* newNode = CreateNode(key);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void insert_after_node(int key, int v) {
        Node* temp = head;
        while (temp != nullptr && temp->data != v) {
            temp = temp->next;
        }
        if (temp != nullptr) {
            Node* newNode = CreateNode(key);
            newNode->next = temp->next;
            temp->next = newNode; 
            if (temp == tail) tail = newNode;
        }
        else {
            cout << "Value not found\n";
            return;
        }
    }
    void update_node(int key, int v) {
        Node* temp = head;
        while (temp != nullptr && temp->data != v) {
            temp = temp->next;
        }
        if (temp != nullptr) {
            temp->data = key;
        } else {
            cout << "Value not found\n";
            return;
        }
    }
    void remove_head() {
        if (head == nullptr) {
            cout << "Underflow\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        if (head == nullptr) tail = nullptr;
    }
    void remove_end() {
        if (isEmpty()) {
            cout << "Underflow" << endl;
            return;
        }
        if (head == tail) { 
            delete head; 
            head = tail = nullptr; 
        } else {
            Node* temp = head;
            while(temp->next != tail){
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next=nullptr;
        }
    }
    void remove_element(int key){
        if(isEmpty()){
            cout<<"Value Not Found"<<endl;
            return;
        }
        if(head->data == key){
            remove_head();
        }
        Node* temp = head;
        
        while(temp != nullptr && temp->next != nullptr && temp->next->data != key){
            temp = temp->next;
        }
        if(temp != nullptr && temp->next != nullptr){
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            if(toDelete == tail){
                tail = temp;
            }
            delete toDelete;
        }
        else{
            cout<<"Value Not found"<<endl;
            return ;
        }
    }
    void printlist() {
    if (isEmpty()) {
        cout <<"Head=Null, Tail=Null, Empty"<< endl;
        return;
    }
    cout<<"Head="<<head->data;
    
    if (tail!=nullptr) {
        cout <<", Tail=" << tail->data << ", ";
        Node* temp = head;
        while(temp != nullptr) {
            cout << temp->data<<" ";
            temp = temp->next;
        }
    }
    cout<<endl;
 }
int main(){
    int a;
    while(true){
        cin>>a;
        switch(a){
            case 1:{
                int b;
                cin>>b;
                insert_front(b);
                printlist();
                break;
            }
            case 2:{
                int b;
                cin>>b;
                insert_back(b);
                printlist();
                break;
            }
            case 3:{
                int b,val;
                cin>>b>>val;
                insert_after_node(b,val);
                printlist();
                break;
            }
            case 4:{
                int b,val;
                cin>>b>>val;
                update_node(b,val);
                printlist();
                break;
            }
            case 5:{
                remove_head();
                printlist();
                break;
            }
            case 6:{
                int b;
                cin>>b;
                remove_element(b);
                printlist();
                break;
            }
            case 7:{
                remove_end();
                printlist();
                break;
            }
            case 8:{
                return 0;
            }
            default:{
                cout<<"Invalid input"<<endl;
                break;
            }
        }
    }
}