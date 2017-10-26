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
		while(ch!=EOF) //判断刚读取的字符是否是文件结束符
    	{
        	putchar(ch); //若不是结束符，将它输出到屏幕上显示
        	ch=fgetc(fp); //继续从fp所指文件中读取下一个字符
    	} //完成将fp所指文件的内容输出到屏幕上显示
    fclose(fp); //关闭fp所指文件
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
	printf("                           图书管理系统\n\n			1、列出当前库存\n			2、从本地数据库中删除一本书\n			3、增添一本书到本地数据库\n			4、取出一本书\n			5、搜索\n\n");
	printf("*****************************************************************\n");
}

int main()
{
	mBook * head ;
	/*
	head = (mBook*)malloc(sizeof(mBook));
	strcpy(head->bookName,"高数");
	strcpy(head->authorName,"王");
	strcpy(head->kind,"math");
	head->price = 19.2 ;
	head->pageNumber = 300 ;
	*/
	//showTitle();
	head = readDataByTxt();
	return 0;
 } 
