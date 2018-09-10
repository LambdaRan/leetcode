
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
 
 
int search_char(char *str,char c);     /*在字符串中寻找字符c*/
char result[MAX]={};                     /*这是存放最终结果的字符数组*/
char tmp[MAX]={};               
int location=0;                          /*这是标志循环节的位置，默认起始位置是0*/
int tag=0;                    
int first=0;

void subRecursion(int a,int b)
{
    int divide=0, remainder=0;
    char ch;
    divide=a/b;
    remainder=a%b;
    ch=divide+'0';
    int length=0;
    int i=0;
    if(b==0)return;
    else if(divide)
    {
        if(search_char(result,ch)==-1)
        {
            itoa(divide,tmp,10);
            strcat(result,tmp);
            if(tag==0)
            {
                strcat(result,".");
                first=1;
                tag=1;
            }
            if(remainder != 0)
                subRecursion(remainder*10,b);
        }
        else
        {
            location = search_char(result,ch);
            length = strlen(result);
            strcat(result,"(");
            for(i=location;i<length;i++)
            {
                itoa(result[i]-'0',tmp,10);
                strcat(result,tmp);
            }
            strcat(result,")");
        }
    }
    else
    {
        if(first==0)
        {
            strcat(result,"0.");
            tag=1;
            first=1;
        }
        else
            strcat(result,"0");
        subRecursion(remainder*10,b);
    }
}
int search_char(char *str,char c)
{
    int i;
    for(i=0;i<strlen(str);i++)
    {
        if(str[i]=='.')break;
    }
    i++;
    for(;i<strlen(str);i++)
    {
        if(str[i]==c)return i;
    }
    return -1;
}

int main()
{
    printf("Please input two integer numbers:\n");
    int a,b;
    scanf("%d%d",&a,&b);
    subRecursion(a,b);
    printf("%s\n",result);
    return 0;
}