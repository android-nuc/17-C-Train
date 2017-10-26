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
	//char ch ��prev ;
	int temp = 0 , i , flag ; 
	if((fp = fopen("D:\\mynotes\\17_c_class\\17-C-Train\\data.txt","r"))==NULL)
	{
		printf("**********************�ӱ����ĵ���������ʧ��****************************\n"); 
	} 
	else
	{
		//ch=fgetc(fp);
		do
		{
			fscanf(fp,"%s%s%s%f%d",bookName,authorName,kind,&price,&pageNumber);
			//printf("�ɹ���ȡ��%s %s %s %.1f %d\n",bookName,authorName,kind,price,pageNumber);
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
	printf("**********************�ѳɹ��ӱ����ĵ���������*******************\n\n");
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
	printf("                           ͼ�����ϵͳ\n\n			1���г���ǰ���\n			2��ɾ��һ����\n			3������һ����\n			4��ȡ��һ����\n			5������\n			6���鿴�˵�\n\n");
	printf("*****************************************************************\n\n\n");
}

int main()
{
	Book * head ;
	int functionCode , temp  ;
	/*
	1���г���ǰ���		
	2��ɾ��һ����			
	3������һ����		
	4��ȡ��һ����		
	5������
	head = (Book*)malloc(sizeof(Book));
	strcpy(head->bookName,"����");
	strcpy(head->authorName,"��");
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
		printf("������������Ҫ�Ĳ���:");
		scanf("%d",&functionCode);
		//printf("%d",functionCode);
		switch(functionCode)
		{
			case 1 :
				printf("\n����Ϊ��ǰͼ���б�:\n\n%8s    %10s   %10s     %s     %s\n\n","����","����","����","��Ǯ","ҳ��");
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
				printf("������1~5������\n");
				
				break; 
		}
	}
	
	//showList(head);

	return 0;
 } 
