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

void countingSort(int arr[],int n, int place){
    int maxi=getMax(arr,n);

    //made my frequency array..
    vector<int> freq(10,0);

    //fill the freq array..
    for(int i=0;i<n;i++){
        freq[(arr[i]/place)%10]++;
    }

    //convert the freq array to cumulative frequency array
    for(int i=1;i<=9;i++){
        freq[i]=freq[i]+freq[i-1];
    }

    //filling the value in temp array
    int temp[n];
    for(int i=n-1;i>=0;i--){
        temp[freq[(arr[i]/place)%10]-1]=arr[i];
        freq[(arr[i]/place)%10]--;
    }

    //copying the value to original array
    for(int i=0;i<n;i++){
        arr[i]=temp[i];
    }
}

void radixSort(int arr[], int n){
    int maxi=getMax(arr, n);
    for(int place=1; place <= maxi; place*=10){
        cout<<"place = "<<place<<": ";
        countingSort(arr,n, place);
        display(arr,n);
    }

}

int main(){
    int arr[]={100,21,27,1,15,106,255,372,11,777,12,33};
    int n=12;

    display(arr,n);
    radixSort(arr,n);
    display(arr,n);

    return 0;
}