#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef enum { NO , YES } BOOL;

	FILE *inputFile;
	FILE *output;
	struct information{
	int brustT;
	int arrivalT;
	int prio;
	};
	int n;
	
	
	
	void readtxt(){
		
		struct information info;
		
		int i=0;
		int j=0;
		
		if (inputFile = fopen("inputmert.txt", "r")){
			while (fscanf(inputFile, "%d: %d: %d",&info.brustT,&info.arrivalT,&info.prio ) != EOF)
    	{
      		i=i+3;
      		j++;
    	}
    }
    	fclose(inputFile);
		
	n=j;
		return info;
	  
	}
	void swap(int *a,int *b){
		
		int temp=*a;
		*a=*b;
		*b=temp;
	}
  
  typedef struct data{
		int id;
		int burstT;
		int arrivalT;
		int prio;
		int turnaroT;
		int waitT;
		struct data *next;
	} fcfs_D_t , *fcfs_D_p_t;
	double awt , atat;
	fcfs_D_p_t *datas;
  
	
	// first come first serve functions
	
	
	
	void inputData_fcfs (){
		
		
		int i;
		if(inputFile = fopen("inputmert.txt", "r")){
				
		datas = (fcfs_D_p_t *) calloc(n, sizeof(fcfs_D_p_t));
			for (i = 0; i < n; ++i) {
				*(datas + i) = (fcfs_D_p_t)malloc(sizeof(fcfs_D_t));
				fcfs_D_p_t data = *(datas + i);
				data->id = i;
				
			
		fscanf(inputFile, "%d: %d: %d",&data->burstT,&data->arrivalT,&data->prio ) ;
    	
    		
    		printf("%d",data->burstT);
    		printf("%d",data->arrivalT);
    		printf("%d\n",data->prio);
    }

    	
		fclose(inputFile);
			}	
}
	
	void calculate_fcfs () {
		int i;
		awt = 0;
		(*datas)->waitT = 0;
		atat = (*datas)->turnaroT = (*datas)->burstT;
		int btt = (*datas)->burstT;
			for (i = 1; i < n; ++i) {
				fcfs_D_p_t data = *(datas + i);
				data->waitT = btt - data->arrivalT;
				btt += data->burstT;
				awt += data->waitT;
				data->turnaroT = data->waitT + data->burstT;
				atat += data->turnaroT;
			}
		atat /= n;
		awt /= n;
		
	}

	void display_fcfs () {
		int i;
		output = fopen("output.txt","w+");
		fprintf(output,"-----First come First serve-----");
		fprintf(output, "\n ID\t| arrivalT\t| burstT\t| waitT\t\t| turnaroT\n");
			for (i = 0; i < n; ++i) {
				fcfs_D_p_t data = *(datas + i);
				fprintf(output, "P: %d\t| %d\t\t| %d\t\t| %d\t\t| %d\n", data->id+1, data->arrivalT, data->burstT, data->waitT, data->turnaroT);
			}
		fprintf(output,"----------------------------------------\n");
		fprintf(output,"Average wait time = %.2lf\n", awt);
		fprintf(output,"Average turnaround time = %.2lf\n\n", atat);
		fprintf(output,"----------------------------------------\n");
		fprintf(output,"\n\n Mert Mustafa Torer 21704824\n");
		fclose(output);
	}

	// end of the first come first serve 
	
	// priorty
	typedef struct dataPri {
	int id;
	int burstT;
	int arrivalT;
	int turnaroT;
	int waitT;		
	int prior;		
	}Prio_D_t, *Prio_D_p_t;
	
	Prio_D_p_t *dataPris;
	
	void inputData_Pri () {
	
	int i;
	
	if(inputFile = fopen("inputmert.txt", "r")){
	dataPris = (Prio_D_p_t *)calloc(n, sizeof(Prio_D_p_t));
	for (i = 0; i < n; ++i) {
		*(dataPris + i) = (Prio_D_p_t)malloc(sizeof(Prio_D_t));
		Prio_D_p_t dataPri = *(dataPris + i);
		dataPri->id = i;
		
		fscanf(inputFile, "%d: %d: %d",&dataPri->burstT,&dataPri->arrivalT,&dataPri->prior ) ;
    	
    		
    		printf("%d",dataPri->burstT);
    		printf("%d",dataPri->arrivalT);
    		printf("%d\n",dataPri->prior);
    		
    		dataPri->waitT = 0;
			dataPri->turnaroT = 0;
    }

    	
		fclose(inputFile);
			}	
	
	
		
	}
	
	void sort_Pri () {
		int i;
		
		for (i = 1; i < n; ++i) {
			int j = i - 1;
			Prio_D_p_t temp = dataPris[i];
			while (j >= 0 && dataPris[j]->prior > temp->prior ) {
				dataPris[j+1] = dataPris[j];
				j--;
			}
			dataPris[j+1] = temp;
			
			
		}
		
		
	}

	void calculate_Pri () {
		
		int i;
		awt = 0;
		Prio_D_p_t dataPri ;
		sort_Pri();
		
		atat = (*dataPris)->turnaroT = (*dataPris)->burstT;
		
		
		int btt = (*dataPris)->burstT;
			
			for (i = 1; i < n; i++) {
				 dataPri = *(dataPris + i);
				
				
				dataPri->waitT = btt - dataPri->arrivalT;
				btt += dataPri->burstT;
				awt = dataPri->waitT + awt;
								
				dataPri->turnaroT = dataPri->waitT + dataPri->burstT;
				atat += dataPri->turnaroT;
			
			}
			
		atat /= n;
		awt /= n;
	}
	
	
	
	
	
	
	void display_Pri () {
		int i;
		output = fopen("output.txt","w+");
		fprintf(output,"-----Priority-----");
		fprintf(output,"\n ID\t| PR\t| AT\t| BT\t| WT\t| TAT\n");
		for (i = 0; i < n; ++i) {
			Prio_D_p_t dataPri = *(dataPris + i);
			fprintf(output,"P: %d\t| %d\t| %d\t| %d\t| %d\t| %d\n", dataPri->id+1, dataPri->prior, dataPri->arrivalT, dataPri->burstT, dataPri->waitT, dataPri->turnaroT);
		}
		fprintf(output,"----------------------------------------\n");
		fprintf(output,"Average wait time = %.2lf\n", awt);
		fprintf(output,"Average turnaround time = %.2lf\n\n", atat);
		fprintf(output,"----------------------------------------\n");
		fprintf(output,"\n\n Mert Mustafa Torer 21704824\n");
		fclose(output);
	}
	// end of priorty
	//short job first
	
	typedef struct dataSjf {
		int id;		
		int burstT;
		int arrivalT;
		int turnaroT;
		int waitT;	
		int prio;
	} shortes_D_t, *shortes_D_p_t;
	
		shortes_D_p_t *dataSjfs;

	void inputData_Sjf () {
			
		
		int i;
		if(inputFile = fopen("inputmert.txt", "r")){
		
		dataSjfs = (shortes_D_p_t *)calloc(n, sizeof(shortes_D_p_t));
		for (i = 0; i < n; ++i) {
			*(dataSjfs + i) = (shortes_D_p_t)malloc(sizeof(shortes_D_t));
			shortes_D_p_t dataSjf = *(dataSjfs + i);
			dataSjf->id = i;
			//printf("Process [%d] Enter arrival time: ", i+1);
			//scanf(" %d", &dataSjf->arrivalT);
			//printf("Process [%d]   Enter burst time: ", i+1);
			//scanf(" %d", &dataSjf->burstT);
			fscanf(inputFile, "%d: %d: %d",&dataSjf->burstT,&dataSjf->arrivalT,&dataSjf->prio);
			printf("%d%d%d\n",dataSjf->burstT,dataSjf->arrivalT,dataSjf->prio);
			dataSjf->waitT = 0;
			dataSjf->turnaroT = 0;
	}
	fclose(inputFile);
}}
		

		void sort_Sjf () {
			int i;
			for (i = 1; i < n; i++) {
				int j = i - 1;
				shortes_D_p_t temp = dataSjfs[i];
				while (j >= 0 && dataSjfs[j]->burstT < temp->burstT ) {
				dataSjfs[j+1] = dataSjfs[j];
				
				j--;
				
			}
			dataSjfs[j+1] = temp;
		}
	}

		void calculate_Sjf () {
			int i;
			awt=0;
			(*dataSjfs)->waitT = 0;
			
			atat = (*dataSjfs)->turnaroT = (*dataSjfs)->burstT;
			int btt = (*dataSjfs)->burstT;
				for (i = 1; i < n; ++i) {
					sort_Sjf();
					shortes_D_p_t dataSjf = *(dataSjfs + i);
					dataSjf->waitT = btt - dataSjf->arrivalT;
					btt += dataSjf->burstT;
					awt += dataSjf->waitT;
					dataSjf->turnaroT = dataSjf->waitT + dataSjf->burstT;
					atat += dataSjf->turnaroT;
					
				}
				sort_Sjf();
				
			atat /= n;
			awt /= n;
	}
	
		void display_Sjf () {
			int i;
			output = fopen("output.txt","w+");
			fprintf(output,"-----Short Job First-----");
			fprintf(output,"\n ID\t| AT\t| BT\t| WT\t| TAT\n");
			for (i = 0; i < n; ++i) {
				shortes_D_p_t dataSjf = *(dataSjfs + i);
				fprintf(output,"P:%d\t| %d\t| %d\t| %d\t| %d\n", dataSjf->id + 1, dataSjf->arrivalT, dataSjf->burstT, dataSjf->waitT, dataSjf->turnaroT);
		}
			fprintf(output,"----------------------------------------\n");
			fprintf(output,"Average wait time = %.2lf\n", awt);
			fprintf(output,"Average turnaround time = %.2lf\n", atat);
			fprintf(output,"----------------------------------------\n");
			fprintf(output,"\n\n Mert Mustafa Torer 21704824\n");
			fclose(output);
	}
	void delay(int number_of_seconds)
{
    
    int milli_seconds = 1000 * number_of_seconds;
  
    
    clock_t start_time = clock();
  
    
    while (clock() < start_time + milli_seconds)
        ;
}
// finsh short job first
// main part 



int main(int argc, char const *argv[]) {

	
	int chosen;
	menu:1;
	printf("Mert Mustafa Torer 21704824\n\n");
	printf("\tCPU Scheduler Similator\t");
	printf("\n 1> Scheduling Method (None)");
	printf("\n 2> Preemptive Mode (Off)");
	printf("\n 3> Show Result");
	printf("\n 4> End Program");
	printf("\n Option>");
	scanf(" %d",&chosen);
	system("cls");
	
	if (chosen==1){
		int ch;
		schMenu:1;
		printf("\n 1> First Come First Serve");
		printf("\n 2> Priority");
		printf("\n 3> Short Job First");
		printf("\n 4> None: None of scheduling method chosen\n");
		scanf(" %d",&ch);
		system("cls");
		if (ch == 1){
			readtxt();
			inputData_fcfs();
			calculate_fcfs();
			display_fcfs();
			printf("\nDONE!!!\nGoing back!!!");
			delay(2);
			system("cls");
			goto menu;
		}
		if (ch==2){
			readtxt();
			inputData_Pri();
			calculate_Pri();
			display_Pri();
			printf("\nDONE!!!\nGoing back!!!");
			delay(2);
			system("cls");
			goto menu;
			
		}
		if (ch==3){
			readtxt();
			inputData_Sjf();
			sort_Sjf();
			calculate_Sjf();
			display_Sjf();
			printf("\nDONE!!!\nGoing back!!!");
			delay(2);
			system("cls");
			goto menu;
		}
		if (ch==4){
			printf("Going Back!!!\n");
			delay(2);
			system("cls");
			goto menu;
		}
		else{
			printf("Please Choose on the Menu!!!");
			printf("\nGoing back!!!");
			delay(2);
			system("cls");
			goto schMenu;
		}
	}
	if(chosen== 2){
		
		printf("Not Complite!!!\n");
		printf("Going back!!!");
		delay(2);
		system("cls");
		goto menu;
	}
	if(chosen == 3){
		int display;
		FILE* read;
		
		if(read = fopen("output.txt","r")){
		
			while (1) {
	        	display = fgetc(read);
	 
	        	if (feof(read))
	            	break;
	 
	        	printf("%c", display);
	    }
 
	    fclose(read);
		}else{
	    	printf("Don't have any result!!!!");
	    	printf("\nGoing back!!!");
	    	delay(2);
	    	system("cls");
	    	goto menu;
		}
		printf("\nPress Any Key To Go Back.");
		getch();
		system("cls");
		goto menu;
	}
	if (chosen == 4 ){
		int display;
		FILE* read;
		
		if(read = fopen("output.txt","r")){
		
			while (1) {
	        	display = fgetc(read);
	 
	        	if (feof(read))
	            	break;
	 
	        	printf("%c", display);
	    }
 
	    fclose(read);
		}else{
	    	printf("Don't have any result!!!!\n");
	    	
		}
		printf("\nPress Any Key To exit.");
		getch();
		exit(0);
	}else{
		printf("Please Choose on the Menu!!!");
		printf("\nGoing back!!!");
			delay(2);
			system("cls");
			goto menu;
	}
	 
	
	return 0;
}
