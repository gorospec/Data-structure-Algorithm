#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
int s, p, n;
vector<int> prime; 
void sieve(){
	bool pr[200];
	memset(pr, true, sizeof(pr));
	for(int i = 2; i*i <= s; i++){
		if(pr[i] == true){
			for(int j = i*i; j <= s; j+=i){
				pr[j] = false;
			}
		}
	}
	for(int i = p; i <= s; i++){
		if(pr[i])
			prime.push_back(i);
	}
}

int main(){
	int t;cin>>t;
	while(t--){
		cin>>n>>p>>s;
		sieve();
		for(int i=0; i<prime.size(); i++)
			cout<<prime[i]<<" ";
		prime.clear();
	}
}
