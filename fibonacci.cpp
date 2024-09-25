#include<iostream>
using namespace std;

int fibonacci(int n){
	    if(n <= 1)
	       return n;
	    int fib[n+1];
	    fib[0] = 0;
	    fib[1] = 1;
	    for(int i = 2; i <= n; i++){
		fib[i] = fib[i -1] + fib[i-2];
	    }
	    return fib[n];
}    
    

int main(){
	int number;

	cout<<"Enter the number you want to find of the fibonacci sequence: "<<endl;
	cin>>number;
	cout<<"The nth number of the fibonacci is "<<fibonacci(number)<<endl;

	return 0;

}
