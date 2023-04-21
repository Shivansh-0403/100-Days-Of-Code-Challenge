#include <iostream>
using namespace std;

void linearSearch(int array[], int n, int key){
    bool flag=false;
    for (int i=0;i<n;i++){
        if (array[i]==key){
            cout<<"Element present at index "<<i<<endl;
            flag=true;
        }
    }
    if (!flag){
        cout<<"Element Not Found"<<endl;
    }
    return;
}

int main() {
    int n;
    cin>>n;
    
    int arr[n];
    
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int key;
    cin>>key;
    
    linearSearch(arr, n, key);
    return 0;
}
