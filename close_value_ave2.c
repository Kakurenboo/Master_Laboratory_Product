#include<stdio.h>
#include<time.h>
#include<math.h>


#define data 233
#define DEMENTION 70
//#define t 3//予測値の選択数（使う予測値の数）



int main()
{
	double ori_data[data][DEMENTION];
	//double a[data][DEMENTION],SA[DEMENTION-t+1];
	double pnew,sum,min;
	int i,j,k,m,n,p,t;
	//int b[data][DEMENTION];
	char *fname = "sort_after.csv";
	//ここで何個選択するかを入れる。
	scanf("%d",&t);
	FILE *fp; // FILE型構造体
	fp = fopen(fname, "r"); // ファイルを開く。失敗するとNULLを返す。
	//scanf("入力してください：%d\n",&t);
	double a[data][DEMENTION],SA[DEMENTION-t+1];
	int b[data][DEMENTION];
	if(fp == NULL) {
		printf("%s file not open!\n",fname);
		return -1;
	}

	for(i=0;i<data;i++){
		for(j=0;j<DEMENTION;j++){
			fscanf(fp,"%lf,",&a[i][j]);
		}
	}
	for(i=0;i<data;i++){
		for(j=0;j<DEMENTION;j++){
			fscanf(fp,"%d,",&b[i][j]);
		}
	}
	fclose( fp );

	for(i=0;i<data;i++){
//	for(i=0;i<2;i++){
		for(j=0;j<DEMENTION-t+1;j++){
			sum=0;
			for(k=0;k<t-1;k++){
				sum+=(a[i][j+k]-a[i][j+k+1]);
			}
			SA[j]=sum;
//			printf("%f  ",SA[j]);
		}
		min=SA[0];
		m=0;
		for(j=0;j<DEMENTION-t+1;j++){
			if(SA[j]<=min){
				min=SA[j];
				m=j;
			}
		}
//		printf("\n%d  %f ",m,min);
		sum=0;
		for(k=0;k<t;k++){
			sum+=a[i][m+k];
		}
		pnew=sum/t;
//		printf("%f  ",min);
//		printf("\n");
		printf("%f ",pnew);
		for(k=0;k<t;k++){
			printf("%f ",a[i][m+k]);
		}
		for(k=0;k<t;k++){
			printf("%d ",b[i][m+k]);
		}
		printf("\n");
	}
	return 0;
}
	
	