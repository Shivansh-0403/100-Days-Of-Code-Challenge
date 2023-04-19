#include<iostream>
#include<cmath>
using namespace std;

int count(int n){
    int digit = 0;
    while(n>0){
        digit++;
        n = n/10;
    }
    cout<<digit<<endl;
    return digit;
}

int main()
{


    int n;
    cin>>n;

    int digit = count(n);

    int sum = 0, rem = 0;
    int num = n;

    // cout<<num<<endl;
    while(n!=0){
        rem = n%10;
        sum += round(pow(rem,digit));
        n = n/10;
    }
    // cout<<sum<<endl;
    if (sum==num){
        cout<<"Armstrong"<<endl;
    }
    else{
        cout<<"Not Armstrong"<<endl;
    }
    return 0;
}

    // int n;
    // cout<<"Enter a Number : ";
    // cin>>n;

    // int number=n;
    // int cube=0;
    // while(n>=1){
    //     int rem = n%10;
    //     cube = cube + (rem*rem*rem);
    //     n=n/10;
    // }
    // cout<<"Sum of Cubes = "<<cube<<endl;
    // if(cube==number){
    //     cout<<"Armstrong Number"<<endl;
    // }
    // else{
    //     cout<<"Not an Armstrong NUmber"<<endl;
    // }