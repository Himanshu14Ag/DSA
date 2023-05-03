#include<iostream>
using namespace std;

int count(int n){
	int count;
	while(n!=0){
		n = n/10;
		count++;
	}
	return count;
}

int main(){
	int n;
	cin>>n;
	int res = count(n);
	cout<<res;
		
}
