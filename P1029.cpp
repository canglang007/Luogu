#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){//���Լ�� 
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
	int spc=0;//��¼P=Q����� 
	//���������飬���Ǳ���ͷ������������������Ҳһ���ǳɶԳ��ֵ�
	//����PQ=xy
	for(P=x;P<=ds/P;P+=x) 
	{
		
		
	   // if(gcd(P,Q)==x&&lcm(P,Q)==y)�˴���ʵ��֤���Լ��ƥ��Ϳ�����
	   //��Ϊ����Q��������������� 
	   if(ds%P==0)
	   {
	   
	   Q=ds/P; //����ñ�֤��������� 
	   if(gcd(P,Q)==x)
	    {
	    	
		    ans++;
			if(P==Q)
			   spc++;			   	
		}
	}
		    
	}
	//����ֱ�Ӷ�ans�˶�����Ҫ���һ�������� 
	cout<<ans*2-spc<<endl;
	   
	return 0;
   
}
