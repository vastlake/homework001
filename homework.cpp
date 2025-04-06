/*
A.
LastRemainningCell
ĳ�������ڵ�����ֻ�иø�������ĳֵ

B.
PossibleNumber
�ų�ͬ�����ѳ��ֵ�ֵ��ĳ���ӻ������ֵ 

*/ 
#include<cstdio>
#include<cstdlib>
using namespace std;

int*** lastRemainingCellInference(int** matrix)
{
	int ***a;	//��ѡֵ���� 
	a=(int***) malloc(10*sizeof(int**));
	for(int i=0;i<=9;i++)
	{
		a[i]=(int**) malloc(10*sizeof(int*));
		for(int j=0;j<=9;j++)
		{
			a[i][j]=(int*) malloc(10*sizeof(int));
		}
	} 
	bool row[10][10],col[10][10],squ[10][10];	//�С��С����ֵ����״��
	for(int i=1;i<=9;i++)
	{
		for(int j=1;j<=9;j++)
		{
			row[i][j]=false;
			col[i][j]=false;
			squ[i][j]=false;
			a[i][j][0]=0;
		}
	}
	for(int i=1;i<=9;i++)
	{
		for(int j=1;j<=9;j++)
		{
			if (matrix[i][j])
			{
				row[i][matrix[i][j]]=true;
				col[j][matrix[i][j]]=true;
				squ[(i-1)/3*3+(j-1)/3+1][matrix[i][j]]=true;
			}
		}
	} 
	for(int i=1;i<=9;i++)
	{
		for(int j=1;j<=9;j++)
		{
			if (matrix[i][j]) continue;
			for(int k=1;k<=9;k++)	//���ܵĺ�ѡֵ 
			{
				if ((!row[i][k])&&(!col[j][k])&&(!squ[(i-1)/3*3+(j-1)/3+1][k]))
				{
					bool bz=true;
					for(int yy=1;yy<=9;yy++)	//ͬ�� 
					{
						if ((!matrix[i][yy])&&(yy!=j)&&(!col[yy][k])&&(!squ[(i-1)/3*3+(yy-1)/3+1][k]))
						{
							bz=false;
						}
					}
					if (bz)
					{
						a[i][j][0]++;
						a[i][j][a[i][j][0]]=k;
						continue;
					}
					bz=true;
					for(int xx=1;xx<=9;xx++)	//ͬ�� 
					{
						if ((!matrix[xx][j])&&(xx!=i)&&(!row[xx][k])&&(!squ[(xx-1)/3*3+(j-1)/3+1][k]))
						{
							bz=false;
						}
					}
					if (bz)
					{
						a[i][j][0]++;
						a[i][j][a[i][j][0]]=k;
						continue;
					}
					bz=true;
					for(int xx=(i-1)/3*3+1;xx<=(i-1)/3*3+3;xx++)	//ͬ���� 
					{
						for(int yy=(j-1)/3*3+1;yy<=(j-1)/3*3+3;yy++)
						{
							if ((!matrix[xx][yy])&&((xx!=i)||(yy!=j))&&(!row[xx][k])&&(!col[yy][k]))
							{
								bz=false;
							}
						}
					}
					if (bz)
					{
						a[i][j][0]++;
						a[i][j][a[i][j][0]]=k;
					}
				}
			}
		}
	}
	return a;
}
int*** possibleNumberInference(int** matrix)
{
	int ***a;	//��ѡֵ���� 
	a=(int***) malloc(10*sizeof(int**));
	for(int i=0;i<=9;i++)
	{
		a[i]=(int**) malloc(10*sizeof(int*));
		for(int j=0;j<=9;j++)
		{
			a[i][j]=(int*) malloc(10*sizeof(int));
		}
	} 
	bool row[10][10],col[10][10],squ[10][10];	//�С��С����ֵ����״��
	for(int i=1;i<=9;i++)
	{
		for(int j=1;j<=9;j++)
		{
			row[i][j]=false;
			col[i][j]=false;
			squ[i][j]=false;
			a[i][j][0]=0;
		}
	}
	for(int i=1;i<=9;i++)
	{
		for(int j=1;j<=9;j++)
		{
			if (matrix[i][j])
			{
				row[i][matrix[i][j]]=true;
				col[j][matrix[i][j]]=true;
				squ[(i-1)/3*3+(j-1)/3+1][matrix[i][j]]=true;
			}
		}
	} 
	for(int i=1;i<=9;i++)
	{
		for(int j=1;j<=9;j++)
		{
			if (matrix[i][j]) continue;
			for(int k=1;k<=9;k++)
			{
				if ((!row[i][k])&&(!col[j][k])&&(!squ[(i-1)/3*3+(j-1)/3+1][k]))
				{
					a[i][j][0]++;
					a[i][j][a[i][j][0]]=k;
				}
			}
		}
	}
	return a;
}
int main()
{
	int matrix[10][10];
	for(int i=1;i<=9;i++)
	{
		for(int j=1;j<=9;j++)
		{
			scanf("%d",&matrix[i][j]);
		}
	}
	int ***ans;
	ans=lastRemainingCellInference(matrix);
//	ans=possibleNumberInference(matrix);
	for(int i=1;i<=9;i++)
	{
		for(int j=1;j<=9;j++)
		{
			printf("%d %d:",i,j);
			if (!ans[i][j][0]) printf("No number");
			else
			{
				for(int k=1;k<=ans[i][j][0];k++)
				{
					printf(" %d",ans[i][j][0]);
				}
				printf("\n");
			}
		}
	}
}
