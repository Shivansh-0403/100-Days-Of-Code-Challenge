#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n;
    cout<<"Enter a Number : ";
    cin>>n;

    bool flag = true;
    for(int i=2; i<sqrt(n); i++){
        if( n%i == 0 ){
            cout<<n<<" is a non-prime number."<<endl;
            flag = false;   
            break;
        }
    }
    if(flag){
        cout<<n<<" is a prime number."<<endl;
    }

    return 0;
}
