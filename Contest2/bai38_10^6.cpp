#include<iostream>
using namespace std;
const int MAX = 1e6+7;
int factor[MAX] = {0};
void sieve(){
	factor[1] = 1;
	for (int i = 2; i < MAX; i++)
		factor[i] = i;
	for (int i = 4; i < MAX; i += 2)
		factor[i] = 2;
	for (int i = 3; i*i < MAX; i++){
		if (factor[i] == i){
			for (int j = i*i; j < MAX; j += i){
				if (factor[j] == j) factor[j] = i;
			}
		}
	}
}
int numberOfFactor(int n){
	if (n == 1) return 1;
	int ans = 1, temp = factor[n], count = 1, j = n / factor[n];
	while (j != 1){
		if (factor[j] == temp) count++;
		else{
			temp = factor[j];
			ans = ans * (count + 1);
			count = 1;
		}
		j = j / factor[j];
	}
	ans = ans * (count + 1);
	return ans;
}
int solve(int n){
	for (int i = 1;; i++)
		if (numberOfFactor(i) >= n)
			return i;
}
int main(){
	sieve();
	cout<<solve(4);
}
