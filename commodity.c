#include "../include/commodity.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdbool.h>
//常量定义
#define SIZE 20

enum judge
{
	ERROR = -1,
	OK,
};


//类型定义
struct goods
{
	char name [SIZE];//货物名
	int count;//货物数量
	//float price;//货物价格
};

typedef struct goods dataType;

//定义一个结构体
typedef struct list
{
	dataType data;
	struct list *pNext;
}LIST;

LIST lis;

/*
函数名：creation
函数功能：创建一个空结点
函数参数：无
函数返回值：创建成功返回结点的地址，失败返回NULL
*/

LIST * creation ( )
{
	//定义指针变量
	LIST *pList = NULL;
	//申请空间
	pList = ( LIST * ) malloc ( sizeof ( LIST ) );
	//判断，初始化
	if ( NULL == pList )
	{
		return NULL;
	}
	memset ( pList, 0, sizeof ( LIST ) );

	return pList;
}
/**
 * 增加商品
 * @param name 商品名
 * @param count 数量
 * @param p 节点
 * @return 成功则返回true
 */
bool add_goods(char name[],int count,LIST *p){
	if ( NULL == p )
	{
		return false;
	}
	//赋值
	strcpy(p->data.name,name);
	p->data.count = count;
	return true;
}
/*
函数名：insert
函数功能：添加商品信息
函数参数：
		LIST *pList 链表的首地址
函数返回值：添加成功返回0，失败返回-1
*/
int insert ( LIST * pList )
{
	//判断链表是否存在
	if ( NULL == pList )
	{
		return ERROR;
	}
	LIST *p =  creation ( );
	char name[20];
	int count=0;
	printf("请输入商品名：\n");
	scanf("%s",&name);
	printf("请输入商品数量：\n");
	scanf("%d",&count);
	if(add_goods(name,count,p)){
		//头插法插入节点
		p->pNext = pList->pNext;
		pList->pNext = p;
		printf ( "商品 %s 已经添加成功\r\n", p->data.name );
		return OK;
	}
}



/*
函数名：delDate
函数功能：删除商品信息
函数参数：LIST *pList 链表的首地址
函数返回值：删除成功返回0，失败返回-1
*/
int delete_from_list ( LIST * pList )
{
	//判断链表是否存在,是否为空
	if ( NULL == pList
	||   NULL == pList->pNext )
	{
		printf ( "数据库数据为空，请先添加商品信息\r\n" );
		return ERROR;
	}
	//定义一个数组
	char str[SIZE] = {0};
	printf( "请输入需要删除的商品名称\r\n" );
	scanf ( "%s", str );

	//定义指针变量
	LIST *p = pList->pNext;
	LIST *q = pList;

	while ( NULL != p )
	{
		//查找商品，显示商品信息
		if ( 0 == strcmp ( p->data.name, str ) )
		{
			q->pNext = p->pNext;
			free ( p );
			p = NULL;
			printf ( "商品 %s 信息已被删除！！\r\n", str );
			return OK;
		}
		p = p->pNext;
		q = q->pNext;

	}
	printf ( "您输入的商品名称没有找到！！\r\n" );
	return ERROR;
}


/*
函数名：findData
函数功能：查找商品的信息
函数参数：
		LIST *pList 链表的首地址
函数返回值：查找成功返回 OK,失败返回ERROR
*/
int find_goods ( LIST *pList )
{
	//判断链表是否存在,是否为空
	if ( NULL == pList
	||   NULL == pList->pNext )
	{
		printf ( "数据库数据为空，请先添加商品信息\r\n" );
		return ERROR;
	}
	//定义一个数组
	char str[SIZE] = {0};
	printf( "请输入需要查找的商品名称\r\n" );
	scanf ( "%s", str );

	//定义指针变量
	LIST *p = pList->pNext;
	while ( NULL != p )
	{
		//查找商品，显示商品信息
		if ( 0 == strcmp ( p->data.name, str ) )
		{
			printf ( "商品的名称：%s\r\n", p->data.name );
			printf ( "商品的数量：%d\r\n", p->data.count );
			return OK;
		}
		//更新结点
		p = p->pNext;
	}
	printf ( "输入的商品信息无效！！！\r\n" );
	return ERROR;
}


/*
函数名：increase_count
函数功能：修改商品信息
函数参数： LIST *pList 链表的首地址
函数返回值：修改成功返回 0,失败返回 -1
*/
int increase_count ( LIST *pList )
{
	//判断链表是否存在,是否为空
	if ( NULL == pList
	||   NULL == pList->pNext )
	{
		printf ( "数据库数据为空，请先添加商品信息\r\n" );
		return ERROR;
	}
	//定义一个数组
	char str[SIZE] = {0};
	printf( "请输入需修改的商品名称\r\n" );
	scanf ( "%s", str );

	//定义指针变量
	LIST *p = pList->pNext;
	while ( NULL != p )
	{
		//查找商品，修改商品信息
		if ( 0 == strcmp ( p->data.name, str ) )
		{

			printf ( "原商品的数量：%d\r\n", p->data.count );
			printf ( "请输入修改的商品数量\r\n" );
			int xiugai;
			scanf ( "%d", &xiugai );
			p->data.count+=xiugai;
			printf ( "商品数量修改成功 *_* \r\n" );
			return OK;
		}
		p = p->pNext;
	}
	printf ( "您输入的商品名称没有找到！！\r\n");
	return ERROR;
}

/*
函数名：menu
函数功能：菜单的显示，所选选项
函数参数： 无
函数返回值：返回所输入的选项
*/
int menu ( )
{
	//菜单
	printf ( "	==欢迎来到商品管理系统===\r\n" );
	printf ( "*******************************************\r\n");
	printf ( "  1-------------------进货\r\n" );
	printf ( "  2-------------------出货\r\n" );
	printf ( "  3-------------------查询\r\n" );
	printf ( "  4-------------------刷新商品\r\n" );
	printf ( "  5-------------------退出并保存\r\n" );
	printf ( "*******************************************\r\n");
	//输入选项
	printf ( "请输入想要操作的选项*-*\r\n" );
	int choice = 0;

	scanf ( "%d", &choice );

	return choice;
}

int menu1 ( )
{
	//菜单
	printf ( "	==欢迎来到商品管理系统===\r\n" );
	printf ( "*******************************************\r\n");
	printf ( "  1-------------------新增商品和数量\r\n" );
	printf ( "  2-------------------修改商品数量\r\n" );
	printf ( "*******************************************\r\n");
	//输入选项
	printf ( "请输入想要操作的选项*-*\r\n" );
	int choice = 0;

	scanf ( "%d", &choice );
	return choice;
}
int menu2 ( )
{
	//菜单
	printf ( "	==欢迎来到商品管理系统===\r\n" );
	printf ( "*******************************************\r\n");
	printf ( "  1-------------------减少库存\r\n" );
	printf ( "  2-------------------删除商品\r\n" );
	printf ( "*******************************************\r\n");
	//输入选项
	printf ( "请输入想要操作的选项*-*\r\n" );
	int choice = 0;
	scanf ( "%d", &choice );
	return choice;
}
int menu3( )
{
	//菜单
	printf ( "	==欢迎来到商品管理系统===\r\n" );
	printf ( "*******************************************\r\n");
	printf ( "  1-------------------查询当前库存列表\r\n" );
	printf ( "  2-------------------查看仓库中name商品\r\n" );
	printf ( "*******************************************\r\n");
	//输入选项
	printf ( "请输入想要操作的选项*-*\r\n" );
	int choice = 0;
	scanf ( "%d", &choice );
	return choice;
}
/*
函数名：flash
函数功能：刷新商品信息
函数参数： LIST *pList 链表的首地址
函数返回值：无
*/
void flash ( LIST *pList )
{
	if ( NULL == pList
	||   NULL == pList->pNext )
	{
		free ( pList );
		pList = NULL;
		printf ( "您的商品数据库没有商品，无需更新！\r\n" );
		return ;
	}
	//刷新
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
	printf ( "您的商品信息已经全部更新，数量为0的已经删除\r\n" );
	return;
}

/*
函数名：goodsKinds
函数功能：查看商品的种类
函数参数： LIST *pList 链表的首地址
函数返回值：成功时返回商品种类数，失败返回-1
*/

int show_goods ( LIST *pList )
{
	//判断
	if ( NULL == pList
	||   NULL == pList->pNext )
	{
		printf ( "您的数据库内没有商品！\r\n" );
		return ERROR;
	}

	int count = 0;
	//定义一个指针变量
	LIST *p = pList->pNext;
	while ( NULL != p )
	{
		count++;
		printf ( "商品的名称：%s\r\n", p->data.name );
		printf ( "商品的数量：%d\r\n", p->data.count );
		//printf ( "商品的价格：%f\r\n", p->data.price );
		printf ( "\r\n" );
		p = p->pNext;
	}
	printf ( "商品的种类为 %d \r\n", count );
	return count;
}


/*
函数名：saveData
函数功能：保存数据，销毁结点
函数参数： LIST *pList 链表的首地址
函数返回值：无
*/

void saveData ( LIST *pList )
{
	//判断
	if ( NULL == pList
	||   NULL == pList->pNext )
	{
		printf ( "您没有商品信息不用保存\r\n" );
		return ;
	}

	//定义一个文件指针
	FILE *fp =NULL;
	fp = fopen ( "save.txt", "w+" );
	if ( NULL == fp )
	{
		printf( "文件打开失败\r\n" );
		return ;
	}
	//定义一个指针变量
	LIST *p = NULL;
	int count = 0;
	//保存完后销毁结点
	while ( NULL != pList->pNext )
	{
		p = pList->pNext;
		pList->pNext = p->pNext;

		//保存数据
		fwrite(&p->data,sizeof(p->data),1,fp);
		//释放p
		free (p);
		p = NULL;
		count++;
	}
	//销毁头结点
	free ( pList );
	pList = NULL;

	fclose ( fp );
	printf ( "已经保存 %d 种商品信息\r\n" , count );

	return;
}


/*
函数名：readData
函数功能：读取数据
函数参数： LIST *pList 链表的首地址
函数返回值：无
*/

void readData ( LIST *pList )
{
	//判断
	if ( NULL == pList )
	{
		printf ( "读取数据失败！\r\n" );
		return ;
	}
	//定义一个文件指针
	FILE *fp = fopen ( "save.txt", "rb" );
	if ( NULL == fp )
	{
		printf( "注意：您的数据库内没有商品信息\r\n" );
		return ;
	}

	int count = 0;
	//定义指针变量
	int tmp = 1;
	LIST *p =  NULL;

	p = creation ( );
	fread(&p->data,sizeof(p->data),1,fp);

	while ( !feof(fp) )
	{
			//头插法插入节点
			p->pNext = pList->pNext;
			pList->pNext = p;
			count++;

			//创建一个结点
			p = creation ( );
			//赋值
			fread(&p->data,sizeof(p->data),1,fp);
	}
	printf ( "数据库中有 %d 种商品信息\r\n", count );
	fclose ( fp );

	return;
}
int main ( )
{
	//定义指针变量
	LIST *pList = NULL;
	pList = creation ( );

	//读数据
	readData ( pList );

	while ( 1 )
	{
		int choice = menu ( );
		int c1;
		//从缓存区读取一个字节
		getchar();

		switch ( choice )
		{
			case 1:
				//增加商品信息
				c1= menu1();
				if(c1==1) insert ( pList );
				else increase_count(pList);
					break;
			case 2:
					//删除商品信息
				c1= menu2();
				if(c1==1) increase_count ( pList );
				else delete_from_list ( pList );
					break;
			case 3:
					//查找商品信息
				c1= menu3();
				if(c1==1) show_goods(pList);
				else find_goods ( pList );
					break;
			case 4:
                flash(pList);
                break;
			case 5:
					//退出系统,保存数据
					saveData ( pList );
					return 0;
			default:
					//提示
					printf ("输入的信息有误,请重新输入！！！\r\n");
					break;
		}
	}
	return 0;
}
