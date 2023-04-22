#include<bits/stdc++.h>
using namespace std;
/*对于最大公倍数和最小公约数来说，影响它们的因素在于质因数的次数的不同，那么可以考察
y/x中质因数的值*/
//对于满足条件的P和Q来说，一定是有那个不变的因子的，但是变化的因子 以及其次数是不一定的 
int main()
{
	int x,y;
	cin>>x>>y;
	int quo=y/x;
	int curs=2;
	int count=0;//记录因数的个数 
	if (y % x != 0)
	cout<<0;
	else{
	
	while(quo>1)//等于1代表分解完毕 
	{
		
		if(quo%curs==0)
		{
			count++;
			while (quo % curs == 0)
                    quo /= curs;//若能整除就除到底,看 
		}
		curs++;
		 
		 
	} 
	cout<<(1<<count);//使用位运算产生2的幂次 （这个式子的含义是对1左移count位，也就是2^count次 
}
	return 0;
	}
	
