#include<iostream>
using namespace std;

// naive---------
bool isPrime(int a){
	if(a == 1) return false;
	
	for(int i=2; i<a; i++){
		if(a%i==0) return false;
	}
	return true;
}

//Optimal------------
bool isprime(int a){
	if(a == 1) return false;
	
	for(int i=2; i*i<=a; i++){
		if(a%i==0) return false;
	}
	return true;
}

// more optimal -----------------
bool IsPrime(int a){
	if(a == 1) return false;
	if(a == 2 || a==3) return true;
	
	if(a%2==0 || a%3==0) return false;
		
	for(int i=5; i*i<=a; i+=6){
		if(a%i==0 || a%(i+2)==0) return false;
	}
	return true;
}



int main(){
	int a;
	cin>>a;
	
	if(isPrime(a)==0){
		cout<<"Number not prime";
	}
	else
		cout<<"Number prime";
		
		
	//optimal
	if(isprime(a)==0){
		cout<<"\nNumber not prime";
	}
	else
		cout<<"\nNumber prime";
		
		
	//More optimal
	if(IsPrime(a)==0){
		cout<<"\nNumber not prime";
	}
	else
		cout<<"\nNumber prime";
}
