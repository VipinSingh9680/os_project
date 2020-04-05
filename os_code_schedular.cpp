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
void program(int n,int remaining_time[10],int current_time,int arrivaltime[10], int bursttime[10]){	
	float average_waiting,average_turnaround;
    int i,j,m=n,temp,btime[20], Pnumber[20],waiting_time[20],turn_around_time[20],total=0,location;
    //
    for(i=0;i<m;i++)
    {
        btime[i]=remaining_time[i];
        waiting_time[i]=current_time-arrivaltime[i]-btime[i];
		Pnumber[i]=i+1;
    }
    for(i=0;i<m;i++)
    {
        location=i;
        for(j=i+1;j<m;j++)
        {
            if(btime[j]<btime[location]){
            	location=j;
            }
        }
        temp=btime[i];
        btime[i]=btime[location];
        btime[location]=temp;
        temp= Pnumber[i];
        Pnumber[i]= Pnumber[location];
        Pnumber[location]=temp;
    }
	
    for(i=1;i<m;i++)
    {
        for(j=0;j<i;j++){
        	waiting_time[i]+=btime[j];
        }
        total+=waiting_time[i];
    }
    average_waiting=(float)total/m;
    total=0;
    printf("\nProcess\t\tBurst time\t\twaiting time\t\tTurnaround Time");
    for(i=0;i<m;i++)
    {
        turn_around_time[i]=btime[i]+waiting_time[i];
        total=total + turn_around_time[i];
        printf("\nP%d\t\t\t%d\t\t\t%d\t\t\t%d", Pnumber[i],btime[i],waiting_time[i],turn_around_time[i]);
    }
    average_turnaround=(float)total/m;
    printf("\nAverage waiting time = %f",average_waiting);
    printf("\nAverage turnaround time = %f\n",average_turnaround);
	
}


