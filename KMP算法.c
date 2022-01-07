#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//KMP算法的代码实现

void get_next(char* son,int* next);//获取字符串的next数组值; 
void get_nextval(char* son,int* nextval);//获取字符串的nextval数组的值;
void KMP_next(char* str,char* son,int* next,int pos);//寻找在母串第i个字符之后可以与子串匹配的位置; 
void KMP_nextval(char* str,char* son,int* nextval,int pos);
int main()
{
	char str[50];
	char son[15];
	int next[15];
	int nextval[15];
	while(gets(str)!=NULL)
	{
		gets(son);
		get_next(son,next);
		get_nextval(son,nextval);
		printf("请输入从第几位开始定位相同的子串：");
		int pos;
		scanf("%d",&pos); 
		getchar();
		printf("你要用哪种方法来定位（方法A：next数组法；方法B：nextval数组法）：");
		char ch;
		scanf("%c",&ch);
		getchar();
		if(ch=='A') 
			KMP_next(str,son,next,pos);
		else if(ch=='B')
			KMP_nextval(str,son,nextval,pos);
	}
	return 0;
}
 
void get_next(char* son,int* next)
{
	int i=0,j=-1;
	next[0]=-1;
	int lenth=strlen(son);
	while(i<lenth)
	{
		if(j==-1||son[i]==son[j])
		{
			i++;
			j++;//j相当于next[i-1],而j++是由于当p[j]==p[k]时next[j+1]=next[j]+1; 
			next[i]=j;
		}
		else
			j=next[j];//当子串与母串不匹配时子串的下标移动; 
	}
}

void KMP_next(char* str,char* son,int *next,int pos)
{
	int lenth1=strlen(str);
	int lenth2=strlen(son);
	int i=pos-1,j=0;
	while(i<lenth1&&j<lenth2)
	{
		if(j==-1||str[i]==son[j])
		{
			i++;
			j++;
		}
		else
			j=next[j];
	}
	if(j>=lenth2)
		printf("在第%d位子串与母串相匹配！\n",i+1-j);
	else
		printf("未找到与之匹配的子串！\n");
}
 
void get_nextval(char* son,int* nextval)
{
	int i=0,j=-1;
	nextval[0]=-1;
	int lenth=strlen(son);
	while(i<lenth)
	{
		if(j==-1||son[i]==son[j])
		{
			i++;
			j++;
			nextval[i]=j;
			if(son[i]==son[j])
				nextval[i]=nextval[j];
		}
		else
			j=nextval[j];
	}
}

void KMP_nextval(char* str,char* son,int* nextval,int pos)
{
	int i=pos-1,j=0;
	int lenth1=strlen(str);
	int lenth2=strlen(son);
	while(i<lenth1&&j<lenth2)
	{
		if(j==-1||str[i]==son[j])
		{
			i++;
			j++;
		}
		else
			j=nextval[j];
	}
	if(j>=lenth2)
		printf("在第%d位子串与母串相匹配！\n",i-j+1);
	else
		printf("未找到与之匹配的子串！\n");
 } 
