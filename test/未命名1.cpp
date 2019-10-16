#include<iostream>

using namespace std;
typedef unsigned float_bits;

float_bits float_half(float_bits f)
{
	unsigned sign = f >> 31;
  	unsigned noSign = f & 0x7FFFFFFF;
  	unsigned exp = f >> 23 & 0xFF;
  	unsigned frac = f & 0x7FFFFF;
	if (exp == 0xFF)
	{
  		return f;
	}
  	int add = ((frac & 0x3) == 0x3);
	if (exp == 0) 
	{
  		frac >>= 1;
   		frac += add;
	} 
	else if (exp == 1) 
	{
    	noSign >>= 1;
    	noSign += add;
    	exp = noSign >> 23 & 0xFF;
    	frac = noSign & 0x7FFFFF;
	} 
	else 
	{
   		exp -= 1;
  	}
	return sign << 31 | exp << 23 | frac;
}

int main()
{
	float func;
	float rst;
	cin>>func;
	rst=float_half(func);
	cout<<rst;
	system("pause");
}
