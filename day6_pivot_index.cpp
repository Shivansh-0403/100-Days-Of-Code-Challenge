#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }

    int s=0, e=n-1, mid=(s+e)/2;

    while(s<e){
        if (arr[mid] >= arr[0]){
            s = mid+1;
        }
        else{
            e = mid;
        }

        mid = (s+e)/2;
    }
  
    cout<<s<<endl;
    return 0;
}
