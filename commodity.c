#include "../include/commodity.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdbool.h>
//��������
#define SIZE 20

enum judge
{
	ERROR = -1,
	OK,
};


//���Ͷ���
struct goods
{
	char name [SIZE];//������
	int count;//��������
	//float price;//����۸�
};

typedef struct goods dataType;

//����һ���ṹ��
typedef struct list
{
	dataType data;
	struct list *pNext;
}LIST;

LIST lis;

/*
��������creation
�������ܣ�����һ���ս��
������������
��������ֵ�������ɹ����ؽ��ĵ�ַ��ʧ�ܷ���NULL
*/

LIST * creation ( )
{
	//����ָ�����
	LIST *pList = NULL;
	//����ռ�
	pList = ( LIST * ) malloc ( sizeof ( LIST ) );
	//�жϣ���ʼ��
	if ( NULL == pList )
	{
		return NULL;
	}
	memset ( pList, 0, sizeof ( LIST ) );

	return pList;
}
/**
 * ������Ʒ
 * @param name ��Ʒ��
 * @param count ����
 * @param p �ڵ�
 * @return �ɹ��򷵻�true
 */
bool add_goods(char name[],int count,LIST *p){
	if ( NULL == p )
	{
		return false;
	}
	//��ֵ
	strcpy(p->data.name,name);
	p->data.count = count;
	return true;
}
/*
��������insert
�������ܣ������Ʒ��Ϣ
����������
		LIST *pList ������׵�ַ
��������ֵ����ӳɹ�����0��ʧ�ܷ���-1
*/
int insert ( LIST * pList )
{
	//�ж������Ƿ����
	if ( NULL == pList )
	{
		return ERROR;
	}
	LIST *p =  creation ( );
	char name[20];
	int count=0;
	printf("��������Ʒ����\n");
	scanf("%s",&name);
	printf("��������Ʒ������\n");
	scanf("%d",&count);
	if(add_goods(name,count,p)){
		//ͷ�巨����ڵ�
		p->pNext = pList->pNext;
		pList->pNext = p;
		printf ( "��Ʒ %s �Ѿ���ӳɹ�\r\n", p->data.name );
		return OK;
	}
}



/*
��������delDate
�������ܣ�ɾ����Ʒ��Ϣ
����������LIST *pList ������׵�ַ
��������ֵ��ɾ���ɹ�����0��ʧ�ܷ���-1
*/
int delete_from_list ( LIST * pList )
{
	//�ж������Ƿ����,�Ƿ�Ϊ��
	if ( NULL == pList
	||   NULL == pList->pNext )
	{
		printf ( "���ݿ�����Ϊ�գ����������Ʒ��Ϣ\r\n" );
		return ERROR;
	}
	//����һ������
	char str[SIZE] = {0};
	printf( "��������Ҫɾ������Ʒ����\r\n" );
	scanf ( "%s", str );

	//����ָ�����
	LIST *p = pList->pNext;
	LIST *q = pList;

	while ( NULL != p )
	{
		//������Ʒ����ʾ��Ʒ��Ϣ
		if ( 0 == strcmp ( p->data.name, str ) )
		{
			q->pNext = p->pNext;
			free ( p );
			p = NULL;
			printf ( "��Ʒ %s ��Ϣ�ѱ�ɾ������\r\n", str );
			return OK;
		}
		p = p->pNext;
		q = q->pNext;

	}
	printf ( "���������Ʒ����û���ҵ�����\r\n" );
	return ERROR;
}


/*
��������findData
�������ܣ�������Ʒ����Ϣ
����������
		LIST *pList ������׵�ַ
��������ֵ�����ҳɹ����� OK,ʧ�ܷ���ERROR
*/
int find_goods ( LIST *pList )
{
	//�ж������Ƿ����,�Ƿ�Ϊ��
	if ( NULL == pList
	||   NULL == pList->pNext )
	{
		printf ( "���ݿ�����Ϊ�գ����������Ʒ��Ϣ\r\n" );
		return ERROR;
	}
	//����һ������
	char str[SIZE] = {0};
	printf( "��������Ҫ���ҵ���Ʒ����\r\n" );
	scanf ( "%s", str );

	//����ָ�����
	LIST *p = pList->pNext;
	while ( NULL != p )
	{
		//������Ʒ����ʾ��Ʒ��Ϣ
		if ( 0 == strcmp ( p->data.name, str ) )
		{
			printf ( "��Ʒ�����ƣ�%s\r\n", p->data.name );
			printf ( "��Ʒ��������%d\r\n", p->data.count );
			return OK;
		}
		//���½��
		p = p->pNext;
	}
	printf ( "�������Ʒ��Ϣ��Ч������\r\n" );
	return ERROR;
}


/*
��������increase_count
�������ܣ��޸���Ʒ��Ϣ
���������� LIST *pList ������׵�ַ
��������ֵ���޸ĳɹ����� 0,ʧ�ܷ��� -1
*/
int increase_count ( LIST *pList )
{
	//�ж������Ƿ����,�Ƿ�Ϊ��
	if ( NULL == pList
	||   NULL == pList->pNext )
	{
		printf ( "���ݿ�����Ϊ�գ����������Ʒ��Ϣ\r\n" );
		return ERROR;
	}
	//����һ������
	char str[SIZE] = {0};
	printf( "���������޸ĵ���Ʒ����\r\n" );
	scanf ( "%s", str );

	//����ָ�����
	LIST *p = pList->pNext;
	while ( NULL != p )
	{
		//������Ʒ���޸���Ʒ��Ϣ
		if ( 0 == strcmp ( p->data.name, str ) )
		{

			printf ( "ԭ��Ʒ��������%d\r\n", p->data.count );
			printf ( "�������޸ĵ���Ʒ����\r\n" );
			int xiugai;
			scanf ( "%d", &xiugai );
			p->data.count+=xiugai;
			printf ( "��Ʒ�����޸ĳɹ� *_* \r\n" );
			return OK;
		}
		p = p->pNext;
	}
	printf ( "���������Ʒ����û���ҵ�����\r\n");
	return ERROR;
}

/*
��������menu
�������ܣ��˵�����ʾ����ѡѡ��
���������� ��
��������ֵ�������������ѡ��
*/
int menu ( )
{
	//�˵�
	printf ( "	==��ӭ������Ʒ����ϵͳ===\r\n" );
	printf ( "*******************************************\r\n");
	printf ( "  1-------------------����\r\n" );
	printf ( "  2-------------------����\r\n" );
	printf ( "  3-------------------��ѯ\r\n" );
	printf ( "  4-------------------ˢ����Ʒ\r\n" );
	printf ( "  5-------------------�˳�������\r\n" );
	printf ( "*******************************************\r\n");
	//����ѡ��
	printf ( "��������Ҫ������ѡ��*-*\r\n" );
	int choice = 0;

	scanf ( "%d", &choice );

	return choice;
}

int menu1 ( )
{
	//�˵�
	printf ( "	==��ӭ������Ʒ����ϵͳ===\r\n" );
	printf ( "*******************************************\r\n");
	printf ( "  1-------------------������Ʒ������\r\n" );
	printf ( "  2-------------------�޸���Ʒ����\r\n" );
	printf ( "*******************************************\r\n");
	//����ѡ��
	printf ( "��������Ҫ������ѡ��*-*\r\n" );
	int choice = 0;

	scanf ( "%d", &choice );
	return choice;
}
int menu2 ( )
{
	//�˵�
	printf ( "	==��ӭ������Ʒ����ϵͳ===\r\n" );
	printf ( "*******************************************\r\n");
	printf ( "  1-------------------���ٿ��\r\n" );
	printf ( "  2-------------------ɾ����Ʒ\r\n" );
	printf ( "*******************************************\r\n");
	//����ѡ��
	printf ( "��������Ҫ������ѡ��*-*\r\n" );
	int choice = 0;
	scanf ( "%d", &choice );
	return choice;
}
int menu3( )
{
	//�˵�
	printf ( "	==��ӭ������Ʒ����ϵͳ===\r\n" );
	printf ( "*******************************************\r\n");
	printf ( "  1-------------------��ѯ��ǰ����б�\r\n" );
	printf ( "  2-------------------�鿴�ֿ���name��Ʒ\r\n" );
	printf ( "*******************************************\r\n");
	//����ѡ��
	printf ( "��������Ҫ������ѡ��*-*\r\n" );
	int choice = 0;
	scanf ( "%d", &choice );
	return choice;
}
/*
��������flash
�������ܣ�ˢ����Ʒ��Ϣ
���������� LIST *pList ������׵�ַ
��������ֵ����
*/
void flash ( LIST *pList )
{
	if ( NULL == pList
	||   NULL == pList->pNext )
	{
		free ( pList );
		pList = NULL;
		printf ( "������Ʒ���ݿ�û����Ʒ��������£�\r\n" );
		return ;
	}
	//ˢ��
	LIST *p = NULL;
	p = pList->pNext;
	if(p->data.count==0){
		pList->pNext = p->pNext;
		p=p->pNext;
	}
	while ( NULL != p->pNext)
	{

		if( p->pNext->data.count==0 ){
			if(p->pNext->pNext!=NULL){
				p->pNext = p->pNext->pNext;
			} else{
				p->pNext=NULL;
				return;
			}
		}
		p = p->pNext;
	}
	printf ( "������Ʒ��Ϣ�Ѿ�ȫ�����£�����Ϊ0���Ѿ�ɾ��\r\n" );
	return;
}

/*
��������goodsKinds
�������ܣ��鿴��Ʒ������
���������� LIST *pList ������׵�ַ
��������ֵ���ɹ�ʱ������Ʒ��������ʧ�ܷ���-1
*/

int show_goods ( LIST *pList )
{
	//�ж�
	if ( NULL == pList
	||   NULL == pList->pNext )
	{
		printf ( "�������ݿ���û����Ʒ��\r\n" );
		return ERROR;
	}

	int count = 0;
	//����һ��ָ�����
	LIST *p = pList->pNext;
	while ( NULL != p )
	{
		count++;
		printf ( "��Ʒ�����ƣ�%s\r\n", p->data.name );
		printf ( "��Ʒ��������%d\r\n", p->data.count );
		//printf ( "��Ʒ�ļ۸�%f\r\n", p->data.price );
		printf ( "\r\n" );
		p = p->pNext;
	}
	printf ( "��Ʒ������Ϊ %d \r\n", count );
	return count;
}


/*
��������saveData
�������ܣ��������ݣ����ٽ��
���������� LIST *pList ������׵�ַ
��������ֵ����
*/

void saveData ( LIST *pList )
{
	//�ж�
	if ( NULL == pList
	||   NULL == pList->pNext )
	{
		printf ( "��û����Ʒ��Ϣ���ñ���\r\n" );
		return ;
	}

	//����һ���ļ�ָ��
	FILE *fp =NULL;
	fp = fopen ( "save.txt", "w+" );
	if ( NULL == fp )
	{
		printf( "�ļ���ʧ��\r\n" );
		return ;
	}
	//����һ��ָ�����
	LIST *p = NULL;
	int count = 0;
	//����������ٽ��
	while ( NULL != pList->pNext )
	{
		p = pList->pNext;
		pList->pNext = p->pNext;

		//��������
		fwrite(&p->data,sizeof(p->data),1,fp);
		//�ͷ�p
		free (p);
		p = NULL;
		count++;
	}
	//����ͷ���
	free ( pList );
	pList = NULL;

	fclose ( fp );
	printf ( "�Ѿ����� %d ����Ʒ��Ϣ\r\n" , count );

	return;
}


/*
��������readData
�������ܣ���ȡ����
���������� LIST *pList ������׵�ַ
��������ֵ����
*/

void readData ( LIST *pList )
{
	//�ж�
	if ( NULL == pList )
	{
		printf ( "��ȡ����ʧ�ܣ�\r\n" );
		return ;
	}
	//����һ���ļ�ָ��
	FILE *fp = fopen ( "save.txt", "rb" );
	if ( NULL == fp )
	{
		printf( "ע�⣺�������ݿ���û����Ʒ��Ϣ\r\n" );
		return ;
	}

	int count = 0;
	//����ָ�����
	int tmp = 1;
	LIST *p =  NULL;

	p = creation ( );
	fread(&p->data,sizeof(p->data),1,fp);

	while ( !feof(fp) )
	{
			//ͷ�巨����ڵ�
			p->pNext = pList->pNext;
			pList->pNext = p;
			count++;

			//����һ�����
			p = creation ( );
			//��ֵ
			fread(&p->data,sizeof(p->data),1,fp);
	}
	printf ( "���ݿ����� %d ����Ʒ��Ϣ\r\n", count );
	fclose ( fp );

	return;
}
int main ( )
{
	//����ָ�����
	LIST *pList = NULL;
	pList = creation ( );

	//������
	readData ( pList );

	while ( 1 )
	{
		int choice = menu ( );
		int c1;
		//�ӻ�������ȡһ���ֽ�
		getchar();

		switch ( choice )
		{
			case 1:
				//������Ʒ��Ϣ
				c1= menu1();
				if(c1==1) insert ( pList );
				else increase_count(pList);
					break;
			case 2:
					//ɾ����Ʒ��Ϣ
				c1= menu2();
				if(c1==1) increase_count ( pList );
				else delete_from_list ( pList );
					break;
			case 3:
					//������Ʒ��Ϣ
				c1= menu3();
				if(c1==1) show_goods(pList);
				else find_goods ( pList );
					break;
			case 4:
                flash(pList);
                break;
			case 5:
					//�˳�ϵͳ,��������
					saveData ( pList );
					return 0;
			default:
					//��ʾ
					printf ("�������Ϣ����,���������룡����\r\n");
					break;
		}
	}
	return 0;
}
