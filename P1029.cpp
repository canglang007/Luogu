#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){//最大公约数 
	if(a<b) swap(a,b);
	if(a%b==0) return b;
	else return gcd(b,a%b);
}
int main()
{
	int x,y;
	int P,Q;
	int ans=0,ds;
	cin>>x>>y;
	ds=x*y;
	int spc=0;//记录P=Q的情况 
	//至少有两组，它们本身和反过来，并且其余的组也一定是成对出现的
	//满足PQ=xy
	for(P=x;P<=ds/P;P+=x) 
	{
		
		
	   // if(gcd(P,Q)==x&&lcm(P,Q)==y)此处其实保证最大公约数匹配就可以了
	   //因为本来Q就是这样算出来的 
	   if(ds%P==0)
	   {
	   
	   Q=ds/P; //必须得保证这个是整除 
	   if(gcd(P,Q)==x)
	    {
	    	
		    ans++;
			if(P==Q)
			   spc++;			   	
		}
	}
		    
	}
	//不能直接对ans乘二，需要解决一样的问题 
	cout<<ans*2-spc<<endl;
	   
	return 0;
   
}
