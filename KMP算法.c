#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//KMP�㷨�Ĵ���ʵ��

void get_next(char* son,int* next);//��ȡ�ַ�����next����ֵ; 
void get_nextval(char* son,int* nextval);//��ȡ�ַ�����nextval�����ֵ;
void KMP_next(char* str,char* son,int* next,int pos);//Ѱ����ĸ����i���ַ�֮��������Ӵ�ƥ���λ��; 
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
		printf("������ӵڼ�λ��ʼ��λ��ͬ���Ӵ���");
		int pos;
		scanf("%d",&pos); 
		getchar();
		printf("��Ҫ�����ַ�������λ������A��next���鷨������B��nextval���鷨����");
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
			j++;//j�൱��next[i-1],��j++�����ڵ�p[j]==p[k]ʱnext[j+1]=next[j]+1; 
			next[i]=j;
		}
		else
			j=next[j];//���Ӵ���ĸ����ƥ��ʱ�Ӵ����±��ƶ�; 
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
		printf("�ڵ�%dλ�Ӵ���ĸ����ƥ�䣡\n",i+1-j);
	else
		printf("δ�ҵ���֮ƥ����Ӵ���\n");
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
		printf("�ڵ�%dλ�Ӵ���ĸ����ƥ�䣡\n",i-j+1);
	else
		printf("δ�ҵ���֮ƥ����Ӵ���\n");
 } 
