#include<stdio.h>
#include<time.h>
#include<math.h>


#define data 233
#define DEMENTION 70



void main(void)
{
	double ori_data[data][DEMENTION];
	double a[data][DEMENTION];
	double temp;
	int i,j,k,m,n,p;
	int b[data][DEMENTION];
	
	for(i=0;i<data;i++){
		for(j=0;j<DEMENTION;j++){
			scanf("%lf,",&ori_data[i][j]);
			//printf("%f ",ori_data[i][j]);
		}
		//printf("\n");
	}

	for(i=0;i<data;i++){
		for(j=0;j<DEMENTION;j++){
			a[i][j]=ori_data[i][j];
			b[i][j]=j;
		}
			for(k=0;k<DEMENTION-1;k++){
				for(m=DEMENTION-1;m>k;m--){
					if(a[i][m-1]<a[i][m]){
						temp=a[i][m-1];
						a[i][m-1]=a[i][m];
						a[i][m]=temp;
						
						p=b[i][m-1];
						b[i][m-1]=b[i][m];
						b[i][m]=p;
					}
				}
			}
		
	}
	
	
	for(i=0;i<data;i++){
//		printf("sort:");
		for(j=0;j<DEMENTION;j++){
			printf("%f  ",a[i][j]);
		}
		printf("\n");
	}
		
	for(i=0;i<data;i++){
		for(j=0;j<DEMENTION;j++){
			printf("%d  ",b[i][j]);
		}
		printf("\n");
	}
}
	
