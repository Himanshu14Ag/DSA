#include<iostream>
using namespace std;

int pallindrome(int n){
	int temp = n ,rem = 0;
	
	while(temp>0){
		int tp = temp%10;
		rem = rem*10 + tp;
		temp = temp/10;
	}
	if(n = rem)
	 	cout<<"number is pallindrome.";
	else{
		cout<<"number is not a pallindrome.";
	}	
}

int main(){
	int n;
	cin>>n;
	cout<<pallindrome(n);	

}
