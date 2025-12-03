#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

void min_heapify(int i,vector<int> &arr,int size){
    int l=2*i;
    int r=2*i+1;
    int smallest=i;
    if(l<size && arr[l]<arr[smallest]){
        smallest=l;
    }
    
    if(r<size && arr[r]<arr[smallest]){
        smallest=r;
    }
    
    if(smallest!=i){
        swap(arr[smallest],arr[i]);
        min_heapify(smallest,arr,size);
    }
}
void build_minheap(vector<int> &arr,int size){
    for(int i=(size/2);i>=1;i--){
        min_heapify(i,arr,size);
    }
}
int heap_minimum(vector<int> &arr){
    return arr[1];
}
int extract_heap_min(vector<int> &arr,int &size){
    if(size<1){
        cout<<"Underflow"<<endl;
    }
    int m=arr[1];
    arr[1]=arr[size];
    size--;
    min_heapify(1, arr, size);
    return m;
}
void min_heap_insert(vector<int> &arr,int &size,int k){
    size++;
    arr[size]=k;
    int id=size;
    int parent=(id)/2;
    while(id>1 && arr[parent]>arr[id]){
        swap(arr[parent],arr[id]);
        id=parent;
        parent=id/2;
    }
}
void decrease_key(int i,int k,vector<int> &arr,int &size){
    arr[i]-=k;
    min_heapify(i,arr,size);
}
void increase_key(int i,int k,vector<int> &arr,int &size){
    arr[i]+=k;
    int id=size;
    int parent=(id)/2;
    
    while(id>1 && arr[parent]>arr[id]){
        swap(arr[parent],arr[id]);
        id=parent;
        parent=id/2;
    }
}
void Print(vector <int> &arr,int size){
    for(int i=1;i<=size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int x;
    vector<int> a(1000);
    int size=0;
    while(1){
        cin>>x;
        if(x==-1) break;
        a[++size]=x;
    }
    

    build_minheap(a,size);
    cout<<"Min Heap :";
    Print(a,size);
    int b;
    while(1){
        cin>>b;
        if(b==1){
            cout<<heap_minimum(a)<<endl;
            Print(a,size);
        }
        else if(b==2){
            cout<<extract_heap_min(a,size)<<endl;
            Print(a,size);
        }
        else if(b==3){
            int key;
            cin>>key;
            min_heap_insert(a,size,key);
            Print(a,size);
        }
        else if(b==4){
            int id,key;
            cin>>id>>key;
            decrease_key(id,key,a,size);
            Print(a,size);
        }
        else if(b==5){
            int id,key;
            cin>>id>>key;
            increase_key(id,key,a,size);
            Print(a,size);
        }
        else return 0;
    }
}