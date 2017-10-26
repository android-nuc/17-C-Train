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
	char kind[10] ;
	
	struct book * next ;
	
}Book;


/*
Book * initSystem()
{
	Book * head ;
	
	head = (Book*)malloc(sizeof(Book));

	return head ;
}
*/


Book * readDataByTxt()
{
	char allChar[100];
	char bookName[20] ;
	char authorName[20] ;
	float price ;
	int pageNumber;
	
	char kind[10]; 
	Book *head = NULL , *prev = NULL , *bookP = NULL ;
	FILE *fp ;
	//char ch ，prev ;
	int temp = 0 , i , flag ; 
	if((fp = fopen("D:\\mynotes\\17_c_class\\17-C-Train\\data.txt","r"))==NULL)
	{
		printf("**********************从本地文档加载数据失败****************************\n"); 
	} 
	else
	{
		//ch=fgetc(fp);
		do
		{
			fscanf(fp,"%s%s%s%f%d",bookName,authorName,kind,&price,&pageNumber);
			//printf("成功读取：%s %s %s %.1f %d\n",bookName,authorName,kind,price,pageNumber);
			bookP = (Book*)malloc(sizeof(Book));
			if(prev!=NULL)
			{
				prev->next = bookP;
			}
			if(head==NULL)
			{
				head = bookP;
			}
			strcpy(bookP->bookName,bookName);
			strcpy(bookP->kind,kind);
			strcpy(bookP->authorName,authorName) ;
			bookP->price = price ;
			bookP->pageNumber=pageNumber ;
			bookP->next = NULL ;
			prev = bookP ;
			//showSelf(*bookP);	
		}while(fgetc(fp)!=EOF);
	}
	//showList(head);
	printf("**********************已成功从本地文档加载数据*******************\n\n");
	fclose(fp);
	return head ;
}

void showList(Book *Book)
{
	  do
    {
        printf("%10s   %10s   %10s    %.1f    %4d\n",Book->bookName,Book->authorName,Book->kind,Book->price,Book->pageNumber);
    }while(Book = Book->next);
}

void showSelf(Book Book)
{
	printf("%s   %s   %s   %.1f   %d\n",Book.bookName,Book.authorName,Book.kind,Book.price,Book.pageNumber);
}

void showTitle()
{
	printf("*****************************************************************\n\n");
	printf("                           图书管理系统\n\n			1、列出当前库存\n			2、删除一本书\n			3、增添一本书\n			4、取出一本书\n			5、搜索\n			6、查看菜单\n\n");
	printf("*****************************************************************\n\n\n");
}

int main()
{
	Book * head ;
	int functionCode , temp  ;
	/*
	1、列出当前库存		
	2、删除一本书			
	3、增添一本书		
	4、取出一本书		
	5、搜索
	head = (Book*)malloc(sizeof(Book));
	strcpy(head->bookName,"高数");
	strcpy(head->authorName,"王");
	strcpy(head->kind,"math");
	head->price = 19.2 ;
	head->pageNumber = 300 ;
	*/
	showTitle();
	for(temp = 0 ; temp < 100 ; temp ++)
	{
		if(temp == 0 )
		{
			head = readDataByTxt();
		}
		printf("请输入您所需要的操作:");
		scanf("%d",&functionCode);
		//printf("%d",functionCode);
		switch(functionCode)
		{
			case 1 :
				printf("\n以下为当前图书列表:\n\n%8s    %10s   %10s     %s     %s\n\n","书名","作者","种类","价钱","页数");
				showList(head);
				printf("\n\n");
				break;
			case 2 :
				printf("\n\n");

				break;
			case 3 :
				printf("\n\n");
				break;
			case 4 :
				printf("\n\n");
				
				break;
			case 5 :
				printf("\n\n");
				
				break;
			case 6 :
				showTitle();
				
				break;
			default:
				printf("请输入1~5的数字\n");
				
				break; 
		}
	}
	
	//showList(head);

	return 0;
 } 
