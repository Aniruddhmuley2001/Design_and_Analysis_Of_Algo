// Sieve of Erathrosthanesis

#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<bool> is_prime(N+1, true);   //N+1 size to access is_prime[N]
	
	for(int i = 2; i*i <= N; i++){
	    if(is_prime[i]){
	        for(int j = i+i; j <= N; j+= i)
	            is_prime[j] = false;
	    }
	}
	
	for(int i = 2; i <= N; i++){
	    if(is_prime[i])
	        cout << i << " ";
	}
	
	return 0;
}
