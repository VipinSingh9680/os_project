#include<stdio.h> 
#include<conio.h>
void program(int n,int remaining_time[10],int current_time,int arrivaltime[10], int bursttime[10]);
main() 
{
	int  Pnumber,j,n,Curr_Time,Remaining_process,indicator,time_quantum,waiting,turnaround_t,arrivaltime[10],bursttime[10],remaining_time[10],x=1;
	indicator = 0;
	waiting = 0;
	turnaround_t = 0;
	printf("Number of process "); 
	scanf("%d",&n);
	Remaining_process = n;
	
	printf("\nEnter the arrival time and burst time \n");
	for( Pnumber = 0; Pnumber < n; Pnumber++) 
	{
		printf("\nProcess P%d\n", Pnumber+1);
		printf("Arrival time = "); 
		scanf("%d",&arrivaltime[ Pnumber]);
		printf("\tBurst time = "); 
		scanf("%d",&bursttime[ Pnumber]); 
		remaining_time[ Pnumber]=bursttime[ Pnumber]; 
	} 
	//
	time_quantum=3;
	Curr_Time=0;
	for( Pnumber=0;Remaining_process!=0;) 
	{
		if(remaining_time[ Pnumber]<=time_quantum && remaining_time[ Pnumber]>0)
		{ 
			Curr_Time+=remaining_time[ Pnumber]; 
			remaining_time[ Pnumber]=0; 
			indicator=1; 
		} 
		else if(remaining_time[ Pnumber]>0)
		{ 
			remaining_time[ Pnumber]-=time_quantum; 
			Curr_Time+=time_quantum; 
		} 
		if(remaining_time[ Pnumber]==0 && indicator==1)			
		{ printf("%d", Pnumber);
			Remaining_process--;				
			printf("P %d", Pnumber+1); 
			printf("\t\t\t%d",Curr_Time-arrivaltime[ Pnumber]);
			printf("\t\t\t%d\n",Curr_Time-bursttime[ Pnumber]-arrivaltime[ Pnumber]);
			waiting+=Curr_Time-arrivaltime[ Pnumber]-bursttime[ Pnumber]; 
			turnaround_t+=Curr_Time-arrivaltime[ Pnumber]; 
			indicator=0;                    
		} 
		if( Pnumber==n-1){
			x++;
			if(x==2){
			 Pnumber=0;
				time_quantum=6;
				//
			}
			else{
				break;
			}
		}
		else if(Curr_Time >= arrivaltime[ Pnumber+1]){
			 Pnumber++;
		}
		else{
			 Pnumber=0;
		}
	}	
	program(n,remaining_time,Curr_Time,arrivaltime,bursttime);
	return 0;
}
