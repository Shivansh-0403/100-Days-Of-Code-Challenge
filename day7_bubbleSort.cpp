#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n){
    for (int i=0; i<n; i++){
        for (int j=0; j<=n-i; j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
  
    return;
}

int main(){
    int n;
    cout<<"Enter Size of Array : ";
    cin>>n;

    int arr[n];
    cout<<"Enter Elements of Array : ";

    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    bubbleSort(arr, n);
    
    cout<<"Sorted Array :- ";
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}
