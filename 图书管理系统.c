#include<stdio.h>
#include<string.h>
/*
kind=["math","physics","Chinese","English","computer"]
*/

typedef struct book{
	
	char bookName[20] ;
	char authorName[20] ;
	int pageNumber ;
	float price ;
	char kind[10];
	
	struct book * next ;
	
}mBook;

mBook * readDataByTxt()
{
	char bookName[20] ;
	char authorName[20] ;
	int pageNumber ;
	float price ;
	char kind[10]; 
	FILE *fp ;
	char ch  ;
	
	if((fp = fopen("D:\\mynotes\\17_c_class\\17-C-Train\\data.txt","r"))==NULL)
	{
		printf("open error!\n"); 
	}
	else
	{
		ch=fgetc(fp);
		while(ch!=EOF) //�жϸն�ȡ���ַ��Ƿ����ļ�������
    	{
        	putchar(ch); //�����ǽ������������������Ļ����ʾ
        	ch=fgetc(fp); //������fp��ָ�ļ��ж�ȡ��һ���ַ�
    	} //��ɽ�fp��ָ�ļ��������������Ļ����ʾ
    fclose(fp); //�ر�fp��ָ�ļ�
	}
	return NULL ;
}

void showSelf(mBook mBook)
{
	printf("%s\t%s\t%s\t%.1f\t%d",mBook.bookName,mBook.authorName,mBook.kind,mBook.price,mBook.pageNumber);
}

void showTitle()
{
	printf("*****************************************************************\n\n");
	printf("                           ͼ�����ϵͳ\n\n			1���г���ǰ���\n			2���ӱ������ݿ���ɾ��һ����\n			3������һ���鵽�������ݿ�\n			4��ȡ��һ����\n			5������\n\n");
	printf("*****************************************************************\n");
}

int main()
{
	mBook * head ;
	/*
	head = (mBook*)malloc(sizeof(mBook));
	strcpy(head->bookName,"����");
	strcpy(head->authorName,"��");
	strcpy(head->kind,"math");
	head->price = 19.2 ;
	head->pageNumber = 300 ;
	*/
	//showTitle();
	head = readDataByTxt();
	return 0;
 } 
