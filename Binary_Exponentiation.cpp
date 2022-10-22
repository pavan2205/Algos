#include<bits/stdc++.h>
using namespace std;

/*
Here we have calculated the power function using reccursion.
The time complexity here is O(logN) as we reduce the value of b by 2 in each reccursion.
*/

int Binary_Power(int a,int b){
	if(a==1 || b==0) return 1;
	int c=power(a,b/2);
	int ans=c*c;
	if(b%2==1){
		ans*=a;
	}
	return ans;
}

int main(){
	int number;
	int power;
	cin>>number>>power;

	cout<<Binary_Power(number,power)<<"\n";
}