


#include<iostream>
using namespace std;

// Optimal-------------------Euclidian Algorithm (first algorithm ever created)
int gcd(int a, int b){
	if(b == 0)
		return a;
		
	else
		return gcd(b , a%b);
}

//Naive ------------------
int GCD(int a , int b){
	int res = min(a,b);
	
	while(res>0){
		if(a%res==0 && b%res==0){
			break;
		}
		res--;
	} 
	return res;
}


int main(){
	int a,b;
	cin>>a>>b;
	
	cout<<"num : "<<GCD(a,b);
	cout<<"\nOptimal : "<<gcd(a,b);
}






