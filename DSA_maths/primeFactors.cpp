#include<iostream>
using namespace std;

bool isPrime(int a){
	if(a == 1) return false;
	if(a == 2 || a==3) return true;
	
	if(a%2==0 || a%3==0) return false;
		
	for(int i=5; i*i<=a; i+=6){
		if(a%i==0 || a%(i+2)==0) return false;
	}
	return true;
}



//Naive solution

int primeFactor(int n){
	for(int i=2; i<=n; i++){
		if(isPrime(i)){
			int x=i;
		
			while(n%x==0){
				cout<<i<<" ";
				x=x*i;
			}
		}
	}
}


//Optimal Solution

int primeFactor1(int n){
	while(n%2==0){
		cout<<2<<" ";
		n = n/2;
	}
	while(n%3==0){
		cout<<3<<" ";
		n = n/3; 
	}
	for(int i=5;i*i<=n;i+=6){
		while(n%i==0){
			cout<<i<<" ";
			n = n/i;
		}
		while(n%(i+2)==0){
			cout<<(i+2)<<" ";
			n = n/(i+2);
		}
	}
	
	if(n>3)
		cout<<n<<" ";
	
}






int main(){
	int n;
	cin>>n;
	
	cout<<"Prime factors : ";
	primeFactor(n);
	
	cout<<"\n";
	
	cout<<"Optimal solution : ";
	primeFactor1(n);
}











