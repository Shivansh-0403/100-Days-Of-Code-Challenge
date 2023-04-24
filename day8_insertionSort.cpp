#include<iostream>
using namespace std;

void insertionSort(int arr[], int n){
    for (int i=1;i<n;i++){
        int temp = arr[i];
        int j = i-1;
        while (j>=0 && arr[j]>temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
    return;
}

int main(){
    int n;
    cin>>n;
  
    int array[n];
    for (int i=0; i<n; i++){
        cin>>array[i];
    }
  
    insertionSort(array, n);
  
    cout<<"Sorted Array:- ";
    for (int i=0; i<n; i++){
        cout<<array[i]<<" ";
    }
  
    return 0;
}
