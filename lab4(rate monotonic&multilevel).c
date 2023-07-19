// RATE MONOTONIC

#include <stdio.h>
#include <stdlib.h>

int gcd(int a,int b){
    if(b==0)
    return a;
    else
    gcd(b,a%b);
}

int lcm(int a,int b){
    return((a*b)/gcd(a,b));
}

int hyperperiod(int period[],int n){
    int k=period[0];
    n--;
    while(n>=1){
        k=lcm(k,period[n--]);
    }
    return k;
}

int main(){
    int period[10], cput[10], n, i, temp, hyp;

    printf ("Enter no. of processes:\n");
    scanf ("%d",&n);

    printf ("Enter period and processing time:\n");
    for (i=0;i<n;i++){
        scanf ("%d %d", &period[i], &cput[i]);
    }
    hyp = hyperperiod(period, n);
    printf ("Hyperperiod=%d\n",hyp);
    int util[n];
    float utilization=0;

    for (i=0;i<n;i++){
        util[i]=hyp/period[i];
        util[i]*=cput[i];
        utilization+=util[i];
        printf ("Util %d: %d\n",i+1,util[i]);
    }
    utilization/=hyp;
    printf ("Utilization=%f\n",utilization);
    return 0;
}



//----------------MULTILEVEL--------------//

#include<stdio.h>
int main()
{
	int p[20],bt[20], su[20], wt[20],tat[20],i, k, n, temp;
	float wtavg, tatavg;
	printf("Enter the number of processes:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		p[i] = i;
		printf("Enter the Burst Time of Process%d:",i);
		scanf("%d",&bt[i]);
		printf("System/User Process (0/1) ? ");
		scanf("%d", &su[i]);
	}
	for(i=0;i<n;i++)
		for(k=i+1;k<n;k++)
			if(su[i] > su[k])
			{
			temp=p[i];
			p[i]=p[k];
			p[k]=temp;
			temp=bt[i];
			bt[i]=bt[k];
			bt[k]=temp;
			temp=su[i];
			su[i]=su[k];
			su[k]=temp;
			}
	wtavg = wt[0] = 0;
	tatavg = tat[0] = bt[0];
	for(i=1;i<n;i++)
	{
		wt[i] = wt[i-1] + bt[i-1];
		tat[i] = tat[i-1] + bt[i];
		wtavg = wtavg + wt[i];
		tatavg = tatavg + tat[i];
	}
	printf("\nPROCESS\t\t SYSTEM/USER PROCESS \tBURST TIME\tWAITING TIME\tTURNAROUND TIME");
	for(i=0;i<n;i++)
		printf("\n%d \t\t %d \t\t %d \t\t %d \t\t %d ",p[i],su[i],bt[i],wt[i],tat[i]);
	printf("\nAverage Waiting Time is --- %f",wtavg/n);
	printf("\nAverage Turnaround Time is --- %f",tatavg/n);
	return 0;
}

