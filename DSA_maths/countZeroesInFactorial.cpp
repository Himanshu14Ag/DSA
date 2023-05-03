#include<iostream>
using namespace std;

int countZeroes(int n){
	int count=0;
	for(int i=5;i<=n;i=i*5)
		count = count + n/i;
	
	return count;
		
}

int main(){
	int n;
	cout<<"Enter number: ";
	cin>>n;
	cout<<"number of zeroes : "<<countZeroes(n);
	
}
