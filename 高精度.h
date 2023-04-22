
/**
 * 将字符串s转化为了int型的数组 
 * @param s
 * @param n
 */
void transfer(string s, int n[]){
    int len = s.size();
 
    n[0] = len;//第0为储存操作数的长度；
    for (int i = 0; i < len ; ++i) {
        n[i+1] = s[len - 1 - i] - '0';//将数字逆序存放，便于逐位计算 
    }
}


//输出结果的函数 
void printResult(int c[]){
    for(int i=c[0];i>=1;i--){
        cout<<c[i];  //c[0]是位数，逆着输出，因为是逆着输入的 
    }
}

/**
*
* @param a 加法
* @param b 加数
* @param c 和
* @param len 数组c的长度
*/
void add(int a[],int b[],int c[],int len){
    int d[len]={0};
    int m=max(a[0],b[0]);//最长的位数为a,b中最长的 
    for(int i=1;i<=m;i++){
        d[i]+=a[i]+b[i];
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

//比较两个数的大小，使用大数减去小数
bool compare(int a[],int b[]){
    if(a[0]!=b[0]){
        return a[0]>b[0];
    }
    else{
        for(int i=a[0];i>=1;i--){
            if(a[i]!=b[i]){
                return a[i]>b[i];
            }
        }
        return 1;
    }
}

/**
*
* @param a
* @param b a,b为参与计算的两个数
* @param c 差
* @param len 数组c的长度
*/
void sub(int a[], int b[], int c[], int len) {
    int d[len] = {0};
    for (int i = 1; i <= a[0]; i++) {
        if (a[i] < b[i]) {
            a[i] += 10;
            a[i + 1]--;      //向前一位借了1 
        }
        d[i] = a[i] - b[i];
    }
 
    int l = a[0];           //l为数字的长度 
    while (d[l] == 0 && l > 1) {   //处理高位的0 
        l--;
    }
    d[0] = l;              //记录目前数字的长度 
    memcpy(c, d, len * sizeof(int));//将计算得到的结果复制到数组c 
}

/**
*
* @param a 被乘数
* @param k 乘数
* @param c 积
* @param len 数组c的长度
*/
//一个大数乘一个小数 
void multipy(int a[],int k,int c[],int len){
    int d[len]={0};
    for(int i=1;i<=a[0];i++)
    {
        d[i]+=d[i]+a[i]*k;
        d[i+1]=d[i]/10;
        d[i]=d[i]%10;
    }
    int l=a[0]+1;   //防止出现大于10的位 
    int t=d[l];
    while(t!=0){    //有可能会进上去很多 
        d[l]=t%10;
        t/=10;
        l++;
    }
//去除前导0
    while(d[l]==0&&l>1){
        l--;
    }
    d[0]=l;
    memcpy(c,d,len* sizeof(int));
}

/**
*
* @param a 被乘数
* @param b 乘数
* @param c 乘积
* @param len 数组c的长度
*/
//两个大数相乘,模拟竖式乘法 
void multiply_1(int a[],int b[],int c[],int len){
    int d[len]={0};
    for(int i=1;i<=a[0];i++) {
        for (int j = 1; j <= b[0]; j++)
        {
            d[i + j - 1] = a[i] * b[j] + d[i + j - 1];
            d[i+j]+= d[i + j - 1] / 10;//进位
            d[i + j - 1] = d[i + j - 1] % 10;
        }
    }
    int l=a[0]+b[0];//最大的位数是两个位数相加 
    while(d[l]==0&&l>1){//去除高位的0 
        l--;
    }
    d[0]=l;
//数组d拷贝导数组c
    memcpy(c,d,len* sizeof(int));
}

/**
*
* @param a 被除数
* @param k 除数
* @param c 商
* @param l
*/
//大数除以小数字 
void divide(int a[],int k,int c[],int len){
    int d[len]={0};
    int x=0; //从高位开始除
    for(int i=a[0];i>=1;i--){
        d[i]=(x*10+a[i])/k;  //x是上一位除法留下来的余数 
        x=(x*10+a[i])%k;     //计算余数 
    }
//计算k的位数
    int f=k;
    int size=0;
    while(f!=0){
        size++;
        f/=10;
    }
//size是除数k的位数
    int l=max(a[0]-size+1,1);//l是商的最高位数，多加了1还是为了保证不溢出 
//去除前导0
    while(d[l]==0&&l>1){
        l--;
    }
    d[0]=l;
//把数组d的数据拷贝给c
    memcpy(c,d,len* sizeof(int));
}


/**
* 被除数与除数比较大小
* @param a 被除数
* @param b 除数
* @param current 从最高位数到当前位置
* @return
*/
bool compareab(int a[],int b[],int current){
    if(a[0]-current+1>b[0]){
        return true; //被除数大于除数 
    }else if(a[0]-current+1<b[0]){
        return false;//被除数小于除数 
    }else{
        for(int i=a[0],j=b[0];i>=current;i--,j--){//位数相同的话，逐位比大小 
            if(a[i]==b[j]){
                continue;
            }else{
                return a[i]>b[j];
            }
        }
        return 1;
    }
}

/**
* 减法，因为除法其实就是多个减法 
* @param a 被除数
* @param b 除数
* @param current 从最高位数到当前位置
* @return
*/
void deduce(int a[],int b[],int current){
    for(int i=current,j=1;i<=a[0];i++,j++){
        if(a[i]<b[j]){
            a[i]+=10;
            a[i+1]--;    //向前面借一位 
        }
        a[i]=a[i]-b[j];
    }
    int len=a[0]; //减完以后把最高位的0去掉
    while(a[len]==0){
        len--;
    }
    a[0]=len; //
}

/**
*
* @param a
* @param b
* @param c
* @param len 数组a和数组c的长度，通常情况下我们把a,b,c三个数组的长度都设置成相同
*/
void divide_1(int a[],int b[],int c[],int len){
    int d[len]={0};
    int a1[len];
//使用a1进行计算，因为在计算过程中，被除数会被改变，因此拷贝一个数组
    memcpy(a1,a,len* sizeof(int));
    d[0]=1;//防止输入的被除数小于除数，无输出结果。
    for(int i=a[0]-b[0]+1;i>=1;i--){
        int t=0;
        while(compareab(a1,b,i)){   //只要被除数比除数大的话就进行除法 
            deduce(a1,b,i);
            t++;//每减一次，就说明商多了一 
        }
        d[i]=t;
    }
    int l=max(a[0]-b[0]+1,1);
//去除前导0
    while(d[l]==0&&l>1){
        l--;
    }
    d[0]=len;
//把数组d的数据拷贝给c
    memcpy(c,d,len* sizeof(int));
}
