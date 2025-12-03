#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#define ll long long 
using namespace std;

void max_heapify(int i,vector<int> &arr,int s){
    int l=2*i+1;
    int r=2*i+2;
    int largest=i;
    if(l<s && arr[l]>arr[largest]){
        largest=l;
    }
    
    if(r<s && arr[r]>arr[largest]){
        largest=r;
    }
    
    if(largest!=i){
        swap(arr[largest],arr[i]);
        max_heapify(largest,arr,s);
    }
}
void build_maxheap(vector<int> &arr,int s){
    for(int i=(s/2)-1;i>=0;i--){
        max_heapify(i,arr,s);
    }
}
void heapsort(vector<int> &arr,int s){
    build_maxheap(arr,s);
    for(int i=s-1;i>0;i--){
        swap(arr[0],arr[i]);
        
        max_heapify(0,arr,i);
    }
    reverse(arr.begin(),arr.end());
}
void Print(vector <int> &arr,int s){
    for(int i=0;i<s;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int x;
    vector<int> a;
    while(1){
        cin>>x;
        if(x==-1) break;
        a.push_back(x);
    }
    int s=a.size();
    build_maxheap(a,s);
    cout<<"Max heap :";
    Print(a,s);
    heapsort(a,s);
    cout<<"Sorted :";
    Print(a,s);
}
    