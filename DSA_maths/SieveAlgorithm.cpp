
// Naive solution

#include<iostream>
#include<vector>
using namespace std;

bool isPrime(int a){
	if(a == 1) return false;
	
	for(int i=2; i*i<=a; i++){
		if(a%i==0) return false;
	}
	return true;
}

int printPrime(int n){
    for(int i = 2; i<n; i++){
        if(isPrime(i))
            cout<<i<<" ";
    }
}



// Sieve Implementation

void sieve(int n){
    vector<bool> isPrime(n+1, true);
    for(int i=2;i*i<=n;i++){
        if(isPrime[i]){
            for(int j=2*i;j<=n;j=j+i)
                isPrime[j] = false;
        }
    }
    for(int i=2;i<n;i++){
        if(isPrime[i])
            cout<<i<<" ";
    }
}


// Optimal Solution

void sieveOptimal(int n){
    vector<bool> isPrime(n+1,true);
    for(int i=2;i<n;i++){
        if(isPrime[i]){
            cout<<i<<" ";
            for(int j=i*i;j<=n;j=j+i)
                isPrime[j]= false;
        }
    }
}




int main(){
    int n;
    cin>>n;

    printPrime(n);
    cout<<"\n\n";
    sieve(n);
    cout<<"\n\n";
    sieveOptimal(n);
}

