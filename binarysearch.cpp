#include<iostream>
using namespace std;

// For Binary Search, the array should be sorted.

int binarySearch(int arr[], int n, int key){
    int s=0;
    int e=n-1;
    while(s<=e){
        int mid=(s+e)/2;

        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]>key){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return -1;
}

int main(){
    int n;
    cout<<"Enter Size of Array : ";
    cin>>n;

    int array[n];

    cout<<"Enter Values of Array : ";
    for(int i=0;i<n;i++){
        cin>>array[i];
    }

    int key;
    cout<<"Enter Value to be Searched : ";
    cin>>key;

    cout<<binarySearch(array,n,key)<<endl;
    return 0;
}