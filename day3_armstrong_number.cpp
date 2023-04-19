#include<iostream>
#include<cmath>
using namespace std;

int count(int n){
    int digit = 0;
    while(n>0){
        digit++;
        n = n/10;
    }
    
    return digit;
}

int main()
{
    int n;
    cin>>n;

    int digit = count(n);

    int sum = 0, rem = 0;
    int num = n;

    while(n!=0){
        rem = n%10;
        sum += round(pow(rem,digit));
        n = n/10;
    }

    if (sum==num){
        cout<<"Armstrong"<<endl;
    }
    else{
        cout<<"Not Armstrong"<<endl;
    }
    
    return 0;
}
