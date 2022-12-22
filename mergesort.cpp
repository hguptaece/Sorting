#include<bits/stdc++.h>
using namespace std;

void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" , ";
    }
    cout<<"\n";
}

void merge(int arr[],int l,int mid,int h){
    vector<int> arr1,arr2;

    for(int i=l;i<=mid;i++){
        arr1.push_back(arr[i]);
    }

    for(int i=mid+1;i<=h;i++){
        arr2.push_back(arr[i]);
    }
    int n=arr1.size(),m=arr2.size();

    int i=0,j=0,k=l;
    
    while(i<n && j<m){
        if(arr1[i] < arr2[j]){
            arr[k++]=arr1[i++];
        }else{
            arr[k++]=arr2[j++];
        }
    }

    while(i<n){
        arr[k++]=arr1[i++];
    }
    while(j<m){
        arr[k++]=arr2[j++];
    }
}

void mergeSort(int arr[],int l,int h){
    if(l>=h)return;

    int mid=(l+h)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,h);
    merge(arr,l,mid,h);
}

int main(){
    int arr[]={9,110,8,109,123,140,63,102,13,20,10,106};
    int n=12;

    display(arr,n);
    mergeSort(arr,0,n-1);
    display(arr,n);

    return 0;
}