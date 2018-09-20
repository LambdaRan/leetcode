

#include "stdio.h"


int main(void){
	int A,B,C,t;
	int flag[102];
	int x,i,n;
	scanf("%d",&t);

	while(t--){
		scanf("%d%d%d",&A,&B,&C);
		for(i=0;i<101;i++)
			flag[i]=0;

		n=x=A%B;
		while(1){
			x=x%B;
			if(x==C)
			{
				flag[101]=1;
				break;
			}
			else if(flag[x]==0)
			{
				flag[x]=1;
			}
			else{
				flag[101]=0;
				break;
			}
			x+=n;
		}
		if(flag[101])
			printf("YES\n");
		else
			printf("NO\n");
	}
	
	return 0;
}
