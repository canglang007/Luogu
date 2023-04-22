#include<bits/stdc++.h>
using namespace std;

int main()
{
	int L,R,num=0;
	string s1;
	cin>>L>>R;
	for(int i=L;i<=R;i++)
	{
		stringstream ss;
        string str;
        ss << i;
        ss >> str;
        int n=str.size();
        for(int j=0;j<=n-1;j++)
            if(str[j]=='2')
                num++;
	}
	cout<<num<<endl;
   return 0;
 } 
