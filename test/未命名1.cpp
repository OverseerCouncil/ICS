#include<iostream>
#include<limits.h>
using namespace std;
int x;

int main()
{
	cin>>x;
	x=((x<<1)+x);
	((x&INT_MIN)&&(x=x+(1<<2)-1));
	x=x>>2;
	cout<<x;
}
