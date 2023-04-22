#include<iostream>
#include<string.h>
using namespace std;

int a[2000],b[2000],c[2000];
void transfer(string s, int n[]){
    int len = s.size();
 
    n[0] = len;//第0为储存操作数的长度；
    for (int i = 0; i < len ; ++i) {
        n[i+1] = s[len - 1 - i] - '0';//将数字逆序存放，便于逐位计算 
    }
}
void add(int a[],int b[],int c[],int len){
    int d[len]={0};
    int m=max(a[0],b[0]);//最长的位数为a,b中最长的 
    for(int i=1;i<=m;i++){
        d[i]+=a[i]+b[i];  //千万注意，这是加等 
        d[i+1]=d[i]/10; //进位
        d[i]=d[i]%10; //取进位后余下的数
    }
    int l=m+1;       //让数组长度多一位，因为很可能有进位 
    while(d[l]==0&&l>1){     //处理各位的0 
        l--;
    }
    d[0]=l;//第0位记录数的长度 
    memcpy(c,d,len* sizeof(int));//将d中的值复制到c中 
}
void print(int n[]){
    for (int i = n[0]; i >= 1 ; i--) {
        cout<<n[i];
    }
}
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	transfer(s1,a);
	transfer(s2,b);
	add(a,b,c,2000);
	print(c);
	return 0;
 } 
