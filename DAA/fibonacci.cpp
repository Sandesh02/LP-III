#include<iostream>
#include<ctime>
using namespace std;

int fib(int n){

   
   if(n==1||n==2)
     {
        return 1;
     }
    else{
        return fib(n-1)+fib(n-2);
     }
}


int fib_non_rec(int n){

    int fib1;
    int fib2;
    int sum;
    for (int i = 3; i <= n; i++){
        sum=fib1+fib2;
        fib1=fib2;
        fib2=sum;
    }
    return fib2;
}

int main(){
    int n;
    cout<<" Enter number: "<<endl;
    cin>>n;
    cout<<"Executing recursive approch"<<endl;
    clock_t start = clock();

    int result;
    result=fib(n);
    cout<<"Fibonacci number:  "<< result<<endl;   

    clock_t end = clock();

    cout<<"time taken by program to execute is: "<<(end-start/CLOCKS_PER_SEC)/1000<<" seconds"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Executing non recursive approch"<<endl;
    clock_t start1 = clock();

    int result1;
    result1=fib_non_rec(n);
    cout<<"Fibonacci number:  "<< result1<<endl;   

    clock_t end1 = clock();

    cout<<"time taken by program to execute is: "<<(end1-start1/CLOCKS_PER_SEC)/1000<<" seconds";
 
   return 0;
}