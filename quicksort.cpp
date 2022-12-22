#include<bits/stdc++.h>
using namespace std;

void display(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" , ";
    }
    cout<<"\n";
}

int partition(int arr[], int l, int h){
    int pivot = arr[l];
    vector<int> temp;

    for(int i=l; i<=h; i++){
        if(arr[i]<pivot){
            cout<<arr[i]<<", ";
        }
    }
    int partitionedIndex=temp.size()+1;

    for(int i=l; i<=h; i++){
        if(arr[i]==pivot){
            cout<<arr[i]<<", ";
        }
    }
    for(int i=l; i<=h; i++){
        if(arr[i]>pivot){
            cout<<arr[i]<<", ";
        }
    }
    for(int i=l;i<=h;i++){
        arr[i]=temp[i-l];
    }
    return partitionedIndex;

}

void QuickSort(int arr[],int l,int h){
    if(l >= h)return;
    //getting the partitioned  index after the partitioning..
    int pIndex=partition(arr,l,h);
    QuickSort(arr,l,pIndex-l);
    QuickSort(arr,pIndex+l,h);
}

int main(){
    int arr[]={12,5,23,32,7,35,78,9,10,51};
    int n=10;
    display(arr, n);
    QuickSort(arr,0,n-1);
    //partition(arr, 0, n-1);
    display(arr, n);

    return 0;
}