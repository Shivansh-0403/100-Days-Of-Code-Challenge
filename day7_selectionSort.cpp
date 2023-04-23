#include<bits/stdc++.h>
using namespace std;

void selectionSort(int array[], int n){
    for (int i=0; i<n-1; i++){
        for (int j=i+1; j<n; j++){
            if (array[j] < array[i]){
                int temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }

    return;
}


int main(){
  
    int n;
    cout<<"Enter Size of Array : ";
    cin>>n;

    int array[n];
    cout<<"Enter Elements of Array : ";

    for(int i=0;i<n;i++){
        cin>>array[i];
    }

    selectionSort(array, n);

    cout<<"Sorted Form of Array : ";
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}
