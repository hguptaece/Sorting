#include<bits/stdc++.h>
using namespace std;

void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" , ";
    }
    cout<<"\n";
}

int getMax(int arr[],int n){
    int maxi=INT_MIN;

    for(int i=0;i<n;i++){
        maxi=max(maxi,arr[i]);
    }

    return maxi;
}

void countingSort(int arr[],int n){
    int maxi=getMax(arr,n);

    //made my frequency array..
    vector<int> freq(maxi+1,0);

    //fill the freq array..
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }

    //convert the freq array to cumulative frequency array
    for(int i=1;i<=maxi;i++){
        freq[i]=freq[i]+freq[i-1];
    }

    //filling the value in temp array
    int temp[n];
    for(int i=n-1;i>=0;i--){
        temp[freq[arr[i]]-1]=arr[i];
        freq[arr[i]]--;
    }

    //copying the value to original array
    for(int i=0;i<n;i++){
        arr[i]=temp[i];
    }
}

int main(){
    int arr[]={1,2,2,1,5,6,5,2,1,7,2,3};
    int n=12;

    display(arr,n);
    countingSort(arr,n);
    display(arr,n);

    return 0;
}