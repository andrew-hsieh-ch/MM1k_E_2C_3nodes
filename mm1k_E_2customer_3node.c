#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lcgrand.h"

#define Idle 0
#define Busy 1


void N1_depature(double *Sim_Time, double *N1_next_dept_time, double *Time_since_Last_Event, double* Last_Event_Time, double *Sys_Area_Under_Q, int *Sys_Num_In_Queue, double* E_Area_Under_Q, int* E_Num_In_Queue,
	double *Time_since_Last_N1_Event, double *Last_Event_N1_Time, double *E1_Area_Under_Q, int *E1_Num_In_Queue, int *N1_Num_In_Queue, int* N1_Server_Status, int * N1_Arrival_Type, double* E1_sys_delay, double * E1_Time_Arrival,
	double *N1_sys_delay, double * N1_Time_Arrival, double* N1_total_sys_delay, double* E1_total_sys_delay, double *E_total_sys_delay, float*N2C1_mean_service_time, int*N1_Num_Custs_Delayed, double *N1_Area_Under_Q, double*N1_qDelay, double*E1_qDelay,
	double*N1_Total_qDelay, double *E1_Total_qDelay, double *E_Total_qDelay, int*temp_type, double*temp_time, float*N1C2_mean_service_time,float*N1C1_mean_service_time,
	double* Time_since_Last_N2_Event, double *Last_Event_N2_Time,
	double *N2_Area_Under_Q, int *N2_Num_In_Queue, int *N2_Server_Status, int *N2_Num_Custs_Delayed, double *E2_qDelay, double *E2_Time_Arrival, double *E2_Total_qDelay,
	int* E2_Num_In_Queue, int* N2_Q_limit, double* num_of_Sys_full, double *num_of_N2_full, int * N2_Arrival_Type, double *N2_Time_Arrival, double*N2_next_dept_time,
	double*N2_Sys_Time_Arrival,
	float *N2C2_mean_service_time,double*num_of_N2_arr, double *num_of_Sys_arr);

void N1C1_arrival(double* Sim_Time, double *N1C1_next_arr_time, float *C1_mean_interarrival_time, double *Time_since_Last_Event, double *Last_Event_Time, double *Time_since_Last_N1_Event, double* Last_Event_N1_Time,
	double *Sys_Area_Under_Q, int* Sys_Num_In_Queue, double* N1_Area_Under_Q, int *N1_Num_In_Queue, int *N1_Server_Status, int* N1_Num_Custs_Delayed, double *E1_qDelay, double*E1_Time_Arrival, double *E1_Total_qDelay, double* E_Total_qDelay,
	int* E_Num_In_Queue, int* E1_Num_In_Queue, int *N1_Q_limit, double *num_of_Sys_full, double* num_of_N1_full, float *N1C1_mean_service_time, int * N1_Arrival_Type, double *N1_Time_Arrival, double*N1_next_dept_time);

void N1C2_arrival(double *Sim_Time, double *N1C2_next_arr_time, float *C2_mean_interarrival_time, double* Time_since_Last_Event, double *Last_Event_Time, double *Time_since_Last_N1_Event, double *Last_Event_N1_Time,
	double *Sys_Area_Under_Q, int *Sys_Num_In_Queue, double *N1_Area_Under_Q, int *N1_Num_In_Queue, int* N1_Server_Status, int *N1_Num_Custs_Delayed, double *E1_qDelay, double* E1_Time_Arrival, double *E1_Total_qDelay, double *E_Total_qDelay,
	int *E_Num_In_Queue, int *E1_Num_In_Queue, int *N1_Q_limit, double *num_of_Sys_full, double *num_of_N1_full, float *N1C2_mean_service_time, int * N1_Arrival_Type, double *N1_Time_Arrival, double*N1_next_dept_time);

void E1_arrival(double *Sim_Time, double *E1_next_arr_time, float *E1_mean_interarrival_time, double *Time_since_Last_Event, double *Last_Event_Time,
	double *E_Area_Under_Q, int *E_Num_In_Queue, double *Time_since_Last_N1_Event, double *Last_Event_N1_Time, double *E1_Area_Under_Q, int *E1_Num_In_Queue,
	int *N1_Server_Status, int *N1_Num_In_Queue, int* N1_Arrival_Type, double * N1_next_dept_time, double* N1_Time_Arrival, float * N1C1_mean_service_time, float * N1C2_mean_service_time,
	double *num_of_E_full, double *num_of_E1_full, double *N1_qDelay, double *N1_Total_qDelay, int *E1_Q_limit, int*N1_Num_Custs_Delayed, double*E1_Time_Arrival, int *Sys_Num_In_Queue);



void N2_depature(double *Sim_Time, double *N2_next_dept_time, double *Time_since_Last_Event, double *Last_Event_Time, double* Sys_Area_Under_Q, int* Sys_Num_In_Queue, double *E_Area_Under_Q, int* E_Num_In_Queue,
	double* Time_since_Last_N2_Event, double* Last_Event_N2_Time, double *E2_Area_Under_Q, int *E2_Num_In_Queue, int* N2_Num_In_Queue, int* N2_Server_Status, int *N2_Arrival_Type, double* E2_sys_delay, double * E2_Time_Arrival,
	double* N2_sys_delay, double*N2_Time_Arrival, double* N2_total_sys_delay, double *E2_total_sys_delay, double *E_total_sys_delay, int *temp_type, double *temp_time, float *N2C1_mean_service_time, float *N2C2_mean_service_time,
	double*N2_Area_Under_Q, int*N2_Num_Custs_Delayed, double*N2_qDelay, double*E2_qDelay, double*N2_Total_qDelay, double *E2_Total_qDelay, double *E_Total_qDelay,

	double* Time_since_Last_N3_Event, double *Last_Event_N3_Time,
	double *N3_Area_Under_Q, int *N3_Num_In_Queue, int *N3_Server_Status, int*N3_Num_Custs_Delayed, double *E3_qDelay, double* E3_Time_Arrival, double *E3_Total_qDelay,
	int* E3_Num_In_Queue, int* N3_Q_limit, double* num_of_Sys_full, double *num_of_N3_full, float *N3C1_mean_service_time, int * N3_Arrival_Type, double *N3_Time_Arrival, double*N3_next_dept_time,
	double*N3_Sys_Time_Arrival,

	float *N3C2_mean_service_time, int*Num_Custs_Delayed,double*N2_Sys_Time_Arrival,double*num_of_N3_arr, double *num_of_Sys_arr, double*Sys_qDelay, double *Sys_Total_qDelay);

void N2C1_arrival(double *Sim_Time, double* Time_since_Last_N2_Event, double *Last_Event_N2_Time,
	double *Sys_Area_Under_Q, int *Sys_Num_In_Queue, double *N2_Area_Under_Q, int *N2_Num_In_Queue, int *N2_Server_Status, int *N2_Num_Custs_Delayed, double *E2_qDelay, double *E2_Time_Arrival, double *E2_Total_qDelay, double *E_Total_qDelay,
	int *E_Num_In_Queue, int* E2_Num_In_Queue, int* N2_Q_limit, double* num_of_Sys_full, double *num_of_N2_full, float *N2C1_mean_service_time, int *temp_type, double *temp_time, int * N2_Arrival_Type, double *N2_Time_Arrival, double*N2_next_dept_time,
	double*N2_Sys_Time_Arrival,double*num_of_N2_arr, double *num_of_Sys_arr);

void N2C2_arrival(double *Sim_Time, double* Time_since_Last_N2_Event, double *Last_Event_N2_Time,
	double *Sys_Area_Under_Q, int *Sys_Num_In_Queue, double *N2_Area_Under_Q, int *N2_Num_In_Queue, int *N2_Server_Status, int *N2_Num_Custs_Delayed, double *E2_qDelay, double*E2_Time_Arrival, double *E2_Total_qDelay, double *E_Total_qDelay,
	int *E_Num_In_Queue, int* E2_Num_In_Queue, int* N2_Q_limit, double* num_of_Sys_full, double *num_of_N2_full, float *N2C2_mean_service_time, int *temp_type, double *temp_time, int * N2_Arrival_Type, double *N2_Time_Arrival,
	double*N2_next_dept_time, double*N2_Sys_Time_Arrival,double*num_of_N2_arr, double *num_of_Sys_arr);

void E2_arrival(double *Sim_Time, double *E2_next_arr_time, float *E2_mean_interarrival_time, double *Time_since_Last_Event, double *Last_Event_Time,
	double *E_Area_Under_Q, int *E_Num_In_Queue, double *Time_since_Last_N2_Event, double *Last_Event_N2_Time, double *E2_Area_Under_Q, int *E2_Num_In_Queue,
	int *N2_Server_Status, int *N2_Num_In_Queue, int* N2_Arrival_Type, double * N2_next_dept_time, double *N2_Time_Arrival, float * N2C1_mean_service_time, float * N2C2_mean_service_time,
	double *num_of_E_full, double*num_of_E2_full, double *N2_qDelay, double *N2_Total_qDelay, int *E2_Q_limit, int *N2_Num_Custs_Delayed, double* E2_Time_Arrival,double*N2_Sys_Time_Arrival, int *Sys_Num_In_Queue);


void N3_depature(double *Sim_Time, double *N3_next_dept_time, double *Time_since_Last_Event, double *Last_Event_Time, double* Sys_Area_Under_Q, int *Sys_Num_In_Queue, double *E_Area_Under_Q, int* E_Num_In_Queue,
	double* Time_since_Last_N3_Event, double* Last_Event_N3_Time, double* E3_Area_Under_Q, int *E3_Num_In_Queue, int* N3_Num_In_Queue, int* N3_Server_Status, int *N3_Arrival_Type, double* E3_sys_delay, double*E3_Time_Arrival,
	double *N3_sys_delay, double* N3_Time_Arrival, double *N3_total_sys_delay, double* E3_total_sys_delay, double* E_total_sys_delay, double*N3_Area_Under_Q, double*Sys_sys_delay, double* E3_Sys_Time_Arrival,
	double*Sys_Total_sys_delay, int*N3_Num_Custs_Delayed, int*Num_Custs_Delayed, double*N3_qDelay, double* E3_qDelay, double *N3_Total_qDelay, double *E3_Total_qDelay, double *E_Total_qDelay, double*Sys_qDelay, double*N3_Sys_Time_Arrival,
	double*Sys_Total_qDelay, float*N3C1_mean_service_time, float*N3C2_mean_service_time);

void N3C1_arrival(double *Sim_Time, double* Time_since_Last_N3_Event, double *Last_Event_N3_Time,
	double *Sys_Area_Under_Q, int *Sys_Num_In_Queue, double *N3_Area_Under_Q, int *N3_Num_In_Queue, int *N3_Server_Status, int *N3_Num_Custs_Delayed, double *E3_qDelay, double* E3_Time_Arrival, double *E3_Total_qDelay, double *E_Total_qDelay,
	int *E_Num_In_Queue, int* E3_Num_In_Queue, int* N3_Q_limit, double* num_of_Sys_full, double *num_of_N3_full, float *N3C1_mean_service_time, int *temp_type, double *temp_time, int * N3_Arrival_Type, double *N3_Time_Arrival, double*N3_next_dept_time,
	double*N3_Sys_Time_Arrival, int *Num_Custs_Delayed,double*num_of_N3_arr, double *num_of_Sys_arr, double*Sys_qDelay, double *Sys_Total_qDelay);

void N3C2_arrival(double *Sim_Time, double* Time_since_Last_N3_Event, double *Last_Event_N3_Time,
	double *Sys_Area_Under_Q, int *Sys_Num_In_Queue, double *N3_Area_Under_Q, int *N3_Num_In_Queue, int *N3_Server_Status, int* N3_Num_Custs_Delayed, double *E3_qDelay, double* E3_Time_Arrival, double *E3_Total_qDelay, double *E_Total_qDelay,
	int *E_Num_In_Queue, int* E3_Num_In_Queue, int* N3_Q_limit, double* num_of_Sys_full, double *num_of_N3_full, float *N3C2_mean_service_time, int *temp_type, double *temp_time, int * N3_Arrival_Type, double *N3_Time_Arrival,
	double*N3_next_dept_time, double*N3_Sys_Time_Arrival, int *Num_Custs_Delayed,double*num_of_N3_arr, double *num_of_Sys_arr, double*Sys_qDelay, double *Sys_Total_qDelay);

void E3_arrival(double *Sim_Time, double *E3_next_arr_time, float *E3_mean_interarrival_time, double *Time_since_Last_Event, double *Last_Event_Time,
	double *E_Area_Under_Q, int *E_Num_In_Queue, double *Time_since_Last_N3_Event, double *Last_Event_N3_Time, double *E3_Area_Under_Q, int *E3_Num_In_Queue,
	int *N3_Server_Status, int *N3_Num_In_Queue, int* N3_Arrival_Type, double * N3_next_dept_time, double*N3_Time_Arrival, float * N3C1_mean_service_time, float * N3C2_mean_service_time,
	double *num_of_E_full, double *num_of_E3_full, double *N3_qDelay, double *N3_Total_qDelay, int *E3_Q_limit, int*N3_Num_Custs_Delayed, double *Sys_qDelay, double*N3_Sys_Time_Arrival, double*Sys_Total_qDelay,
	int*Sys_Num_In_Queue, double* E3_Time_Arrival,int*Num_Custs_Delayed);

float expon(float mean);
double minimum(double *N1_next_dept_time, double *N2_next_dept_time, double *N3_next_dept_time, double  *N1C1_next_arr_time, double  *N1C2_next_arr_time, double *E1_next_arr_time, double *E2_next_arr_time, double *E3_next_arr_time);



int main()
{
	// Initialize
	//total

	double Sim_Time = 0;
	double Time_since_Last_Event = 0;
	double Last_Event_Time = 0;

	float C1_mean_interarrival_time = 0;
	float C2_mean_interarrival_time = 0;


	int C1_priority = 0;
	int C2_priority = 0;


	double E_Area_Under_Q = 0;
	double Sys_Area_Under_Q = 0;


	double min_time = 0;


	int E_Num_In_Queue = 0;
	int Sys_Num_In_Queue = 0;

	double E_avg_num_in_queue = 0;
	double Sys_avg_num_in_queue = 0;

	double E_avg_sys_delay = 0;
	double Sys_avg_qdelay = 0;
	int Num_Delays_Required = 0;
	int Num_Custs_Delayed = 0;

	double num_of_C_full = 0;
	double num_of_E_full = 0;
	double num_of_Sys_full = 0;

	float Sys_Pk = 0;
	float E_Pk = 0;

//	int C_Q_limit = 0;
	int E_Q_limit = 0;

	double E_Total_qDelay = 0;
	double E_total_sys_delay = 0;

	double E_avg_qdelay = 0;
	double Sys_Total_sys_delay = 0;
	double Sys_Total_qDelay = 0;
	double Sys_qDelay = 0;
	double Sys_sys_delay = 0;

	double Sys_avg_sys_delay = 0;
	float Thoughtput = 0;

	// node1 variable
	//total
	int N1_Server_Status = Idle;
	int E1_Num_In_Queue = 0;
	int N1_Num_Custs_Delayed = 0;
	int N1_Num_In_Queue = 0;//C
	double E1_Area_Under_Q = 0;
	int N1_K = 0;
	int E1_K = 0;
	double N1_Area_Under_Q = 0;
	//N1C1_arrival
	double N1C1_next_arr_time = 0;
	float N1C1_mean_service_time = 0;


	//N1C2_arrival
	double N1C2_next_arr_time = 0;
	float N1C2_mean_service_time = 0;


	//E1_arrival
	float E1_mean_interarrival_time = 0;
	double E1_next_arr_time = 0;


	int N1_Q_limit = 0;
	int E1_Q_limit = 0;


	double N1_avg_qdelay = 0;
	double E1_avg_qdelay = 0;

	float N1_avg_num_in_queue = 0;
	float E1_avg_num_in_queue = 0;

	double N1_next_dept_time = pow(10, 30);


	double N1_Total_qDelay = 0;
	double E1_Total_qDelay = 0;

	double N1_qDelay = 0;
	double E1_qDelay = 0;

	double Last_Event_N1_Time = 0;
	double Time_since_Last_N1_Event = 0;


	double num_of_N1_full = 0;
	double num_of_E1_full = 0;

	float N1_Thoughtput = 0;
	float N1_Pk = 0;
	float E1_Pk = 0;

	double N1_sys_delay = 0;
	double E1_sys_delay = 0;

	double N1_total_sys_delay = 0;
	double E1_total_sys_delay = 0;

	float N1_avg_sys_delay = 0;
	float E1_avg_sys_delay = 0;


	double num_of_N1_arr = 0;



	//node2
	int N2_Server_Status = Idle;
	int E2_Num_In_Queue = 0;
	int N2_Num_Custs_Delayed = 0;
	int N2_Num_In_Queue = 0;//C
	double E2_Area_Under_Q = 0;
	int N2_K = 0;
	int E2_K = 0;
	double N2_Area_Under_Q = 0;
	//N2C1_arrival

	float N2C1_mean_service_time = 0;


	//N1C2_arrival

	float N2C2_mean_service_time = 0;


	//E1_arrival
	float E2_mean_interarrival_time = 0;
	double E2_next_arr_time = 0;





	int N2_Q_limit = 0;
	int E2_Q_limit = 0;


	double N2_avg_qdelay = 0;
	double E2_avg_qdelay = 0;

	float N2_avg_num_in_queue = 0;
	float E2_avg_num_in_queue = 0;

	double N2_next_dept_time = pow(10, 30);


	double N2_Total_qDelay = 0;
	double E2_Total_qDelay = 0;

	double N2_qDelay = 0;
	double E2_qDelay = 0;

	double Last_Event_N2_Time = 0;
	double Time_since_Last_N2_Event = 0;


	double num_of_N2_full = 0;
	double num_of_E2_full = 0;

	float N2_Thoughtput = 0;
	float N2_Pk = 0;
	float E2_Pk = 0;

	double N2_sys_delay = 0;
	double E2_sys_delay = 0;

	double N2_total_sys_delay = 0;
	double E2_total_sys_delay = 0;

	float N2_avg_sys_delay = 0;
	float E2_avg_sys_delay = 0;
	double num_of_N2_arr = 0;

	//node3
	int N3_Server_Status = Idle;
	int E3_Num_In_Queue = 0;
	int N3_Num_Custs_Delayed = 0;
	int N3_Num_In_Queue = 0;//C
	double E3_Area_Under_Q = 0;
	int N3_K = 0;
	int E3_K = 0;
	double N3_Area_Under_Q = 0;

	//N3C1_arrival

	float N3C1_mean_service_time = 0;


	//N3C2_arrival

	float N3C2_mean_service_time = 0;


	//E1_arrival
	float E3_mean_interarrival_time = 0;
	double E3_next_arr_time = 0;





	int N3_Q_limit = 0;
	int E3_Q_limit = 0;


	double N3_avg_qdelay = 0;
	double E3_avg_qdelay = 0;

	float N3_avg_num_in_queue = 0;
	float E3_avg_num_in_queue = 0;

	double N3_next_dept_time = pow(10, 30);


	double N3_Total_qDelay = 0;
	double E3_Total_qDelay = 0;

	double N3_qDelay = 0;
	double E3_qDelay = 0;

	double Last_Event_N3_Time = 0;
	double Time_since_Last_N3_Event = 0;


	double num_of_N3_full = 0;
	double num_of_E3_full = 0;

	float N3_Thoughtput = 0;
	float N3_Pk = 0;
	float E3_Pk = 0;

	double N3_sys_delay = 0;
	double E3_sys_delay = 0;

	double N3_total_sys_delay = 0;
	double E3_total_sys_delay = 0;

	float N3_avg_sys_delay = 0;
	float E3_avg_sys_delay = 0;

	double num_of_N3_arr = 0;


	//other

	double num_of_Sys_arr = 0;
	double num_of_E_arr = 0;
	double num_of_E1_arr = 0;
	double num_of_E2_arr = 0;
	double num_of_E3_arr = 0;


	double num_of_D_arr = 0;
	double num_of_D1_arr = 0;
	double num_of_D2_arr = 0;
	double num_of_D3_arr = 0;
	int temp_priority = 0;
	int temp_type = 0;
	double temp_time = 0;



	printf("Enter customer1 mean_interarrival_time\n");
	scanf("%f", &C1_mean_interarrival_time);
	N1C1_next_arr_time = expon(C1_mean_interarrival_time);

	printf("Enter customer2 mean_interarrival_time\n");
	scanf("%f", &C2_mean_interarrival_time);
	N1C2_next_arr_time = expon(C2_mean_interarrival_time);

	printf("Enter energy1 mean_interarrival_time\n");
	scanf("%f", &E1_mean_interarrival_time);
	E1_next_arr_time = expon(E1_mean_interarrival_time);



	printf("Enter energy2 mean_interarrival_time\n");
	scanf("%f", &E2_mean_interarrival_time);
	E2_next_arr_time = expon(E2_mean_interarrival_time);

	printf("Enter energy3 mean_interarrival_time\n");
	scanf("%f", &E3_mean_interarrival_time);
	E3_next_arr_time = expon(E3_mean_interarrival_time);


	printf("Enter N1C1_mean_service_time\n");
	scanf("%f", &N1C1_mean_service_time);

	printf("Enter N1C2_mean_service_time\n");
	scanf("%f", &N1C2_mean_service_time);

	printf("Enter N2C1_mean_service_time\n");
	scanf("%f", &N2C1_mean_service_time);

	printf("Enter N2C2_mean_service_time\n");
	scanf("%f", &N2C2_mean_service_time);

	printf("Enter N3C1_mean_service_time\n");
	scanf("%f", &N3C1_mean_service_time);

	printf("Enter N3C2_mean_service_time\n");
	scanf("%f", &N3C2_mean_service_time);






	printf("Enter num_delays_required\n");
	scanf("%d", &Num_Delays_Required);

	printf("Enter N1_K\n");
	scanf("%d", &N1_K);

	printf("Enter N2_K\n");
	scanf("%d", &N2_K);
	printf("Enter N3_K\n");
	scanf("%d", &N3_K);

	N1_Q_limit = N1_K - 1;
	N2_Q_limit = N2_K - 1;
	N3_Q_limit = N3_K - 1;

	double N1_Time_Arrival[N1_Q_limit + 1];
	double N2_Time_Arrival[N2_Q_limit + 1];
	double N3_Time_Arrival[N3_Q_limit + 1];
	double N2_Sys_Time_Arrival[N2_Q_limit + 1];
	double N3_Sys_Time_Arrival[N3_Q_limit + 1];

	for (int i = 0; i < N1_Q_limit + 1; i++) {
		N1_Time_Arrival[i] = 0;
	}
	for (int i = 0; i < N2_Q_limit + 1; i++) {

		N2_Time_Arrival[i] = 0;
		N2_Sys_Time_Arrival[i] = 0;

	}
	for (int i = 0; i < N3_Q_limit + 1; i++) {

		N3_Time_Arrival[i] = 0;
		N3_Sys_Time_Arrival[i] = 0;
	}


	int N1_Arrival_Type[N1_Q_limit + 1];
	int N2_Arrival_Type[N2_Q_limit + 1];
	int N3_Arrival_Type[N3_Q_limit + 1];

	for (int i = 0; i < N1_Q_limit + 1; i++) {

		N1_Arrival_Type[i] = 0;

	}
	for (int i = 0; i < N2_Q_limit + 1; i++) {

		N2_Arrival_Type[i] = 0;

	}
	for (int i = 0; i < N3_Q_limit + 1; i++) {

		N3_Arrival_Type[i] = 0;
	}

	printf("Enter Energy1_K\n");
	scanf("%d", &E1_K);


	printf("Enter Energy2_K\n");
	scanf("%d", &E2_K);

	printf("Enter Energy3_K\n");
	scanf("%d", &E3_K);
	E1_Q_limit = E1_K - 1;
	E2_Q_limit = E2_K - 1;
	E3_Q_limit = E3_K - 1;


	double E1_Time_Arrival[E1_Q_limit + 1];
	double E2_Time_Arrival[E2_Q_limit + 1];
	double E3_Time_Arrival[E3_Q_limit + 1];
	double E3_Sys_Time_Arrival[E3_Q_limit + 1];
	for (int i = 0; i < E1_Q_limit + 1; i++) {
		E1_Time_Arrival[i] = 0;
	}

	for (int i = 0; i < E2_Q_limit + 1; i++) {

		E2_Time_Arrival[i] = 0;

	}

	for (int i = 0; i < E3_Q_limit + 1; i++) {
		E3_Time_Arrival[i] = 0;
		E3_Sys_Time_Arrival[i] = 0;
	}



	//Initialize end

	while (Num_Custs_Delayed < Num_Delays_Required)
	{
		min_time = minimum(&N1_next_dept_time, &N2_next_dept_time, &N3_next_dept_time, &N1C1_next_arr_time, &N1C2_next_arr_time, &E1_next_arr_time, &E2_next_arr_time, &E3_next_arr_time);


		if (min_time == N1_next_dept_time) {



			N1_depature(&Sim_Time, &N1_next_dept_time, &Time_since_Last_Event, &Last_Event_Time, &Sys_Area_Under_Q, &Sys_Num_In_Queue, &E_Area_Under_Q, &E_Num_In_Queue,
				&Time_since_Last_N1_Event, &Last_Event_N1_Time, &E1_Area_Under_Q, &E1_Num_In_Queue, &N1_Num_In_Queue, &N1_Server_Status, N1_Arrival_Type, &E1_sys_delay, E1_Time_Arrival,
				&N1_sys_delay, N1_Time_Arrival, &N1_total_sys_delay, &E1_total_sys_delay, &E_total_sys_delay, &N2C1_mean_service_time, &N1_Num_Custs_Delayed, &N1_Area_Under_Q, &N1_qDelay, &E1_qDelay,
				&N1_Total_qDelay, &E1_Total_qDelay, &E_Total_qDelay, &temp_type, &temp_time, &N1C2_mean_service_time,&N1C1_mean_service_time,
				&Time_since_Last_N2_Event, &Last_Event_N2_Time,
				&N2_Area_Under_Q, &N2_Num_In_Queue, &N2_Server_Status, &N2_Num_Custs_Delayed, &E2_qDelay, E2_Time_Arrival, &E2_Total_qDelay,
				&E2_Num_In_Queue, &N2_Q_limit, &num_of_Sys_full, &num_of_N2_full, N2_Arrival_Type, N2_Time_Arrival, &N2_next_dept_time,
				N2_Sys_Time_Arrival,
				&N2C2_mean_service_time,&num_of_N2_arr, &num_of_Sys_arr);
			num_of_D1_arr++;
			num_of_D_arr++;
			//printf("D1\n  ");


		}
		else if (min_time == N2_next_dept_time) {



			N2_depature(&Sim_Time, &N2_next_dept_time, &Time_since_Last_Event, &Last_Event_Time, &Sys_Area_Under_Q, &Sys_Num_In_Queue, &E_Area_Under_Q, &E_Num_In_Queue,
				&Time_since_Last_N2_Event, &Last_Event_N2_Time, &E2_Area_Under_Q, &E2_Num_In_Queue, &N2_Num_In_Queue, &N2_Server_Status, N2_Arrival_Type, &E2_sys_delay, E2_Time_Arrival,
				&N2_sys_delay, N2_Time_Arrival, &N2_total_sys_delay, &E2_total_sys_delay, &E_total_sys_delay, &temp_type, &temp_time, &N2C1_mean_service_time, &N2C2_mean_service_time,
				&N2_Area_Under_Q, &N2_Num_Custs_Delayed, &N2_qDelay, &E2_qDelay, &N2_Total_qDelay, &E2_Total_qDelay, &E_Total_qDelay,

				&Time_since_Last_N3_Event, &Last_Event_N3_Time,
				&N3_Area_Under_Q, &N3_Num_In_Queue, &N3_Server_Status, &N3_Num_Custs_Delayed, &E3_qDelay, E3_Time_Arrival, &E3_Total_qDelay,
				&E3_Num_In_Queue, &N3_Q_limit, &num_of_Sys_full, &num_of_N3_full, &N3C1_mean_service_time, N3_Arrival_Type, N3_Time_Arrival, &N3_next_dept_time,
				N3_Sys_Time_Arrival,

				&N3C2_mean_service_time, &Num_Custs_Delayed,N2_Sys_Time_Arrival,&num_of_N3_arr, &num_of_Sys_arr, &Sys_qDelay, &Sys_Total_qDelay);
				num_of_D2_arr++;
				num_of_D_arr++;
				//printf("D2\n  ");


		}
		else if (min_time == N3_next_dept_time) {



			N3_depature(&Sim_Time, &N3_next_dept_time, &Time_since_Last_Event, &Last_Event_Time, &Sys_Area_Under_Q, &Sys_Num_In_Queue, &E_Area_Under_Q, &E_Num_In_Queue,
				&Time_since_Last_N3_Event, &Last_Event_N3_Time, &E3_Area_Under_Q, &E3_Num_In_Queue, &N3_Num_In_Queue, &N3_Server_Status, N3_Arrival_Type, &E3_sys_delay, E3_Time_Arrival,
				&N3_sys_delay, N3_Time_Arrival, &N3_total_sys_delay, &E3_total_sys_delay, &E_total_sys_delay, &N3_Area_Under_Q, &Sys_sys_delay, E3_Sys_Time_Arrival,
				&Sys_Total_sys_delay, &N3_Num_Custs_Delayed, &Num_Custs_Delayed, &N3_qDelay, &E3_qDelay, &N3_Total_qDelay, &E3_Total_qDelay, &E_Total_qDelay, &Sys_qDelay, N3_Sys_Time_Arrival,
				&Sys_Total_qDelay, &N3C1_mean_service_time, &N3C2_mean_service_time);
			num_of_D3_arr++;
			num_of_D_arr++;
			//printf("D3\n  ");


		}
		else if (min_time == N1C1_next_arr_time) {



			N1C1_arrival(&Sim_Time, &N1C1_next_arr_time, &C1_mean_interarrival_time, &Time_since_Last_Event, &Last_Event_Time, &Time_since_Last_N1_Event, &Last_Event_N1_Time,
				&Sys_Area_Under_Q, &Sys_Num_In_Queue, &N1_Area_Under_Q, &N1_Num_In_Queue, &N1_Server_Status, &N1_Num_Custs_Delayed, &E1_qDelay, E1_Time_Arrival, &E1_Total_qDelay, &E_Total_qDelay,
				&E_Num_In_Queue, &E1_Num_In_Queue, &N1_Q_limit, &num_of_Sys_full, &num_of_N1_full, &N1C1_mean_service_time, N1_Arrival_Type, N1_Time_Arrival, &N1_next_dept_time);

			num_of_N1_arr++;
			num_of_Sys_arr++;
			//printf("N1C1\n  ");



		}

		else if (min_time == N1C2_next_arr_time) {



			N1C2_arrival(&Sim_Time, &N1C2_next_arr_time, &C2_mean_interarrival_time, &Time_since_Last_Event, &Last_Event_Time, &Time_since_Last_N1_Event, &Last_Event_N1_Time,
				&Sys_Area_Under_Q, &Sys_Num_In_Queue, &N1_Area_Under_Q, &N1_Num_In_Queue, &N1_Server_Status, &N1_Num_Custs_Delayed, &E1_qDelay, E1_Time_Arrival, &E1_Total_qDelay, &E_Total_qDelay,
				&E_Num_In_Queue, &E1_Num_In_Queue, &N1_Q_limit, &num_of_Sys_full, &num_of_N1_full, &N1C2_mean_service_time, N1_Arrival_Type, N1_Time_Arrival, &N1_next_dept_time);

			num_of_N1_arr++;
			num_of_Sys_arr++;
			//printf("N1C2\n  ");



		}

		else if (min_time == E1_next_arr_time)
		{



			E1_arrival(&Sim_Time, &E1_next_arr_time, &E1_mean_interarrival_time, &Time_since_Last_Event, &Last_Event_Time,
				&E_Area_Under_Q, &E_Num_In_Queue, &Time_since_Last_N1_Event, &Last_Event_N1_Time, &E1_Area_Under_Q, &E1_Num_In_Queue,
				&N1_Server_Status, &N1_Num_In_Queue, N1_Arrival_Type, &N1_next_dept_time, N1_Time_Arrival, &N1C1_mean_service_time, &N1C2_mean_service_time,
				&num_of_E_full, &num_of_E1_full, &N1_qDelay, &N1_Total_qDelay, &E1_Q_limit, &N1_Num_Custs_Delayed, E1_Time_Arrival, &Sys_Num_In_Queue);

			num_of_E1_arr++;
			num_of_E_arr++;
			//printf("E1\n  ");


		}
		else if (min_time == E2_next_arr_time)
		{


			E2_arrival(&Sim_Time, &E2_next_arr_time, &E2_mean_interarrival_time, &Time_since_Last_Event, &Last_Event_Time,
				&E_Area_Under_Q, &E_Num_In_Queue, &Time_since_Last_N2_Event, &Last_Event_N2_Time, &E2_Area_Under_Q, &E2_Num_In_Queue,
				&N2_Server_Status, &N2_Num_In_Queue, N2_Arrival_Type, &N2_next_dept_time, N2_Time_Arrival, &N2C1_mean_service_time, &N2C2_mean_service_time,
				&num_of_E_full, &num_of_E2_full, &N2_qDelay, &N2_Total_qDelay, &E2_Q_limit, &N2_Num_Custs_Delayed, E2_Time_Arrival,&*N2_Sys_Time_Arrival, &Sys_Num_In_Queue);

			num_of_E2_arr++;
			num_of_E_arr++;
			//printf("E2\n  ");


		}
		else
		{

			E3_arrival(&Sim_Time, &E3_next_arr_time, &E3_mean_interarrival_time, &Time_since_Last_Event, &Last_Event_Time,
				&E_Area_Under_Q, &E_Num_In_Queue, &Time_since_Last_N3_Event, &Last_Event_N3_Time, &E3_Area_Under_Q, &E3_Num_In_Queue,
				&N3_Server_Status, &N3_Num_In_Queue, N3_Arrival_Type, &N3_next_dept_time, N3_Time_Arrival, &N3C1_mean_service_time, &N3C2_mean_service_time,
				&num_of_E_full, &num_of_E3_full, &N3_qDelay, &N3_Total_qDelay, &E3_Q_limit, &N3_Num_Custs_Delayed, &Sys_qDelay, N3_Sys_Time_Arrival, &Sys_Total_qDelay,
				&Sys_Num_In_Queue, E3_Time_Arrival,&Num_Custs_Delayed);

			num_of_E3_arr++;
			num_of_E_arr++;
			//printf("E3\n  ");


		}


	//check

	}

    if (N3_Server_Status == Busy){ // Last check

        Sim_Time = N3_next_dept_time;
        Time_since_Last_Event = Sim_Time - Last_Event_Time;
        Last_Event_Time = Sim_Time;
        printf("EIQ = %d \n", E_Num_In_Queue);

        Sys_Area_Under_Q += Sys_Num_In_Queue * Time_since_Last_Event;
        E_Area_Under_Q += E_Num_In_Queue * Time_since_Last_Event;

        Time_since_Last_N3_Event = Sim_Time - Last_Event_N3_Time;
        Last_Event_N3_Time = Sim_Time;
        E3_Area_Under_Q += E3_Num_In_Queue * Time_since_Last_N3_Event;
        N3_Area_Under_Q += N3_Num_In_Queue * Time_since_Last_N3_Event;

        N3_Server_Status = Idle;
        N3_next_dept_time = pow(10,30);

            E3_sys_delay = Sim_Time - E3_Time_Arrival[0];
            N3_sys_delay = Sim_Time - N3_Time_Arrival[0];

            N3_total_sys_delay += N3_sys_delay;
            E3_total_sys_delay += E3_sys_delay;


            Sys_sys_delay = Sim_Time - N3_Sys_Time_Arrival[0];
            Sys_Total_sys_delay += Sys_sys_delay;
            E_total_sys_delay += E3_total_sys_delay;



    }
	//output
	printf("\n");
	printf("sim_time= %.8f \n", Sim_Time);
	printf("num_custs_delayed= %d \n", Num_Custs_Delayed);


	Sys_avg_qdelay = Sys_Total_qDelay / Num_Custs_Delayed;
        printf("Sys_avg_q_delay= %.8f \n", Sys_avg_qdelay);

	N1_avg_qdelay = N1_Total_qDelay / N1_Num_Custs_Delayed;
        printf("N1_avg_q_delay= %.8f \n", N1_avg_qdelay);

	N2_avg_qdelay = N2_Total_qDelay / N2_Num_Custs_Delayed;
        printf("N2_avg_q_delay= %.8f \n", N2_avg_qdelay);

	N3_avg_qdelay = N3_Total_qDelay / N3_Num_Custs_Delayed;
        printf("N3_avg_q_delay= %.8f \n", N3_avg_qdelay);


	Sys_avg_num_in_queue = Sys_Area_Under_Q / Sim_Time;
		printf("Sys_avg_num_in_queue= %.8f \n", Sys_avg_num_in_queue);

	N1_avg_num_in_queue = N1_Area_Under_Q / Sim_Time;
		printf("N1_avg_num_in_queue= %.8f \n", N1_avg_num_in_queue);

	N2_avg_num_in_queue = N2_Area_Under_Q / Sim_Time;
		printf("N2_avg_num_in_queue= %.8f \n", N2_avg_num_in_queue);

	N3_avg_num_in_queue = N3_Area_Under_Q / Sim_Time;
		printf("N3_avg_num_in_queue= %.8f \n", N3_avg_num_in_queue);


		Sys_avg_sys_delay = Sys_Total_sys_delay / Num_Custs_Delayed;
		printf("Sys_avg_system_delay= %.8f \n", Sys_avg_sys_delay);

		N1_avg_sys_delay = N1_total_sys_delay / N1_Num_Custs_Delayed;
		printf("N1_avg_system_delay= %.8f \n", N1_avg_sys_delay);

		N2_avg_sys_delay = N2_total_sys_delay / N2_Num_Custs_Delayed;
		printf("N2_avg_system_delay= %.8f \n", N2_avg_sys_delay);

		N3_avg_sys_delay = N3_total_sys_delay / N3_Num_Custs_Delayed;
		printf("N3_avg_system_delay= %.8f \n", N3_avg_sys_delay);

		E_avg_qdelay = E_Total_qDelay / Num_Custs_Delayed;
		printf("E_avg_q_delay= %.8f \n", E_avg_qdelay);

		E1_avg_qdelay = E1_Total_qDelay / N1_Num_Custs_Delayed;
		printf("E1_avg_q_delay= %.8f \n", E1_avg_qdelay);

		E2_avg_qdelay = E2_Total_qDelay / N2_Num_Custs_Delayed;
		printf("E2_avg_q_delay= %.8f \n", E2_avg_qdelay);

		E3_avg_qdelay = E3_Total_qDelay / N3_Num_Custs_Delayed;
		printf("E3_avg_q_delay= %.8f \n", E3_avg_qdelay);

		E_avg_num_in_queue = E_Area_Under_Q / Sim_Time;
		printf("E_avg_num_in_queue= %.8f \n", E_avg_num_in_queue);

		E1_avg_num_in_queue = E1_Area_Under_Q / Sim_Time;
		printf("E1_avg_num_in_queue= %.8f \n", E1_avg_num_in_queue);

		E2_avg_num_in_queue = E2_Area_Under_Q / Sim_Time;
		printf("E2_avg_num_in_queue= %.8f \n", E2_avg_num_in_queue);

		E3_avg_num_in_queue = E3_Area_Under_Q / Sim_Time;
		printf("E3_avg_num_in_queue= %.8f \n", E3_avg_num_in_queue);

		E_avg_sys_delay = E_total_sys_delay / Num_Custs_Delayed;
		printf("E_avg_system_delay= %.8f \n", E_avg_sys_delay);

		E1_avg_sys_delay = E1_total_sys_delay / N1_Num_Custs_Delayed;
		printf("E1_avg_system_delay= %.8f \n", E1_avg_sys_delay);

		E2_avg_sys_delay = E2_total_sys_delay / N2_Num_Custs_Delayed;
		printf("E2_avg_system_delay= %.8f \n", E2_avg_sys_delay);

		E3_avg_sys_delay = E3_total_sys_delay / N3_Num_Custs_Delayed;
		printf("E3_avg_system_delay= %.8f \n", E3_avg_sys_delay);

		Sys_Pk = num_of_Sys_full / num_of_Sys_arr;
		printf("Sys_Pk = %f \n", Sys_Pk);

		N1_Pk = num_of_N1_full / num_of_N1_arr;
		printf("N1_Pk = %f \n", N1_Pk);

		N2_Pk = num_of_N2_full / num_of_N2_arr;
		printf("N2_Pk = %f \n", N2_Pk);

		N3_Pk = num_of_N3_full / num_of_N3_arr;
		printf("N3_Pk = %f \n", N3_Pk);

		E_Pk = num_of_E_full / num_of_E_arr;
		printf("E_Pk = %f \n", E_Pk);

		E1_Pk = num_of_E1_full / num_of_E1_arr;
		printf("E1_Pk = %f \n", E1_Pk);

		E2_Pk = num_of_E2_full / num_of_E2_arr;
		printf("E2_Pk = %f \n", E2_Pk);

		E3_Pk = num_of_E3_full / num_of_E3_arr;
		printf("E3_Pk = %f \n", E3_Pk);

		Thoughtput = num_of_D_arr/Sim_Time;
		printf("Thoughtput = %f \n", Thoughtput);
		
		N1_Thoughtput = num_of_D1_arr/Sim_Time;
		printf("N1_Thoughtput = %f \n", N1_Thoughtput);


		N2_Thoughtput = num_of_D2_arr/Sim_Time;
		printf("N2_Thoughtput = %f \n", N2_Thoughtput);

		N3_Thoughtput = num_of_D3_arr/Sim_Time;
		printf("N3_Thoughtput = %f \n", N3_Thoughtput);



	return 0;



}




//node1
void N1_depature(double *Sim_Time, double *N1_next_dept_time, double *Time_since_Last_Event, double* Last_Event_Time, double *Sys_Area_Under_Q, int *Sys_Num_In_Queue, double* E_Area_Under_Q, int* E_Num_In_Queue,
	double *Time_since_Last_N1_Event, double *Last_Event_N1_Time, double *E1_Area_Under_Q, int *E1_Num_In_Queue, int *N1_Num_In_Queue, int* N1_Server_Status, int * N1_Arrival_Type, double* E1_sys_delay, double * E1_Time_Arrival,
	double *N1_sys_delay, double * N1_Time_Arrival, double* N1_total_sys_delay, double* E1_total_sys_delay, double *E_total_sys_delay, float*N2C1_mean_service_time, int*N1_Num_Custs_Delayed, double *N1_Area_Under_Q, double*N1_qDelay, double*E1_qDelay,
	double*N1_Total_qDelay, double *E1_Total_qDelay, double *E_Total_qDelay, int*temp_type, double*temp_time, float*N1C2_mean_service_time,float*N1C1_mean_service_time,
	double* Time_since_Last_N2_Event, double *Last_Event_N2_Time,
	double *N2_Area_Under_Q, int *N2_Num_In_Queue, int *N2_Server_Status, int *N2_Num_Custs_Delayed, double *E2_qDelay, double *E2_Time_Arrival, double *E2_Total_qDelay,
	int* E2_Num_In_Queue, int* N2_Q_limit, double* num_of_Sys_full, double *num_of_N2_full, int * N2_Arrival_Type, double *N2_Time_Arrival, double*N2_next_dept_time,
	double*N2_Sys_Time_Arrival,
	float *N2C2_mean_service_time,double*num_of_N2_arr, double *num_of_Sys_arr)
{
	*Sim_Time = *N1_next_dept_time;

	*Time_since_Last_Event = *Sim_Time - *Last_Event_Time;
	*Last_Event_Time = *Sim_Time;
	*Sys_Area_Under_Q += (*Sys_Num_In_Queue) * (*Time_since_Last_Event);
	*E_Area_Under_Q += (*E_Num_In_Queue) * (*Time_since_Last_Event);

	*Time_since_Last_N1_Event = *Sim_Time - *Last_Event_N1_Time;
	*Last_Event_N1_Time = *Sim_Time;
	*E1_Area_Under_Q += (*E1_Num_In_Queue) * (*Time_since_Last_N1_Event);

	*N1_Area_Under_Q += (*N1_Num_In_Queue) * (*Time_since_Last_N1_Event);

	if (*N1_Num_In_Queue == 0) {
		*N1_Server_Status = Idle;
		*N1_next_dept_time = pow(10, 30);

        *temp_type = N1_Arrival_Type[0];
        *temp_time = N1_Time_Arrival[0];


		if (N1_Arrival_Type[0] == 1)
		{

			*E1_sys_delay = *Sim_Time - E1_Time_Arrival[0];
			*N1_sys_delay = *Sim_Time - N1_Time_Arrival[0];

			*N1_total_sys_delay += *N1_sys_delay;
			*E1_total_sys_delay += *E1_sys_delay;
			*E_total_sys_delay += *E1_sys_delay;

			(*N2_Num_In_Queue)++;
			(*Sys_Num_In_Queue)++;

			N2C1_arrival(Sim_Time, Time_since_Last_N2_Event, Last_Event_N2_Time,
				Sys_Area_Under_Q, Sys_Num_In_Queue, N2_Area_Under_Q, N2_Num_In_Queue, N2_Server_Status, N2_Num_Custs_Delayed, E2_qDelay, E2_Time_Arrival, E2_Total_qDelay, E_Total_qDelay,
				E_Num_In_Queue, E2_Num_In_Queue, N2_Q_limit, num_of_Sys_full, num_of_N2_full, N2C1_mean_service_time, temp_type, temp_time, N2_Arrival_Type, N2_Time_Arrival, N2_next_dept_time,
				N2_Sys_Time_Arrival,num_of_N2_arr,num_of_Sys_arr);

		}

		else if (N1_Arrival_Type[0] == 2)
		{

			*E1_sys_delay = *Sim_Time - E1_Time_Arrival[0];
			*N1_sys_delay = *Sim_Time - N1_Time_Arrival[0];

			*N1_total_sys_delay += *N1_sys_delay;
			*E1_total_sys_delay += *E1_sys_delay;
			*E_total_sys_delay += *E1_sys_delay;

			(*N2_Num_In_Queue)++;
			(*Sys_Num_In_Queue)++;
			N2C2_arrival(Sim_Time, Time_since_Last_N2_Event, Last_Event_N2_Time,
				Sys_Area_Under_Q, Sys_Num_In_Queue, N2_Area_Under_Q, N2_Num_In_Queue, N2_Server_Status, N2_Num_Custs_Delayed, E2_qDelay, E2_Time_Arrival, E2_Total_qDelay, E_Total_qDelay,
				E_Num_In_Queue, E2_Num_In_Queue, N2_Q_limit, num_of_Sys_full, num_of_N2_full, N2C2_mean_service_time, temp_type, temp_time, N2_Arrival_Type, N2_Time_Arrival, N2_next_dept_time,
				N2_Sys_Time_Arrival,num_of_N2_arr, num_of_Sys_arr);

		}
	}
	else if (N1_Arrival_Type[1] == 1)
	{

		if (*E1_Num_In_Queue >= 1)
		{
			(*N1_Num_Custs_Delayed)++;



			*N1_qDelay = *Sim_Time - N1_Time_Arrival[1];
			*N1_sys_delay = *Sim_Time - N1_Time_Arrival[0];

			*E1_qDelay = *Sim_Time - E1_Time_Arrival[1];
			*E1_sys_delay = *Sim_Time - E1_Time_Arrival[0];



			*N1_Total_qDelay += *N1_qDelay;
			*N1_total_sys_delay += *N1_sys_delay;
			*E1_Total_qDelay += *E1_qDelay;
			*E1_total_sys_delay += *E1_sys_delay;

			*E_Total_qDelay += *E1_qDelay;
			*E_total_sys_delay += *E1_sys_delay;

			*temp_type = N1_Arrival_Type[0];
			*temp_time = N1_Time_Arrival[0];






			for (int i = 0; i <= *N1_Num_In_Queue; i++)
			{
				if(i==*N1_Num_In_Queue)
				{
					N1_Time_Arrival[i] = 0;
					N1_Arrival_Type[i] = 0;
				}
				else
				{
				N1_Time_Arrival[i] = N1_Time_Arrival[i + 1];
				N1_Arrival_Type[i] = N1_Arrival_Type[i + 1];
				}
			}

			for (int i = 0; i <= *E1_Num_In_Queue; i++)
			{
				if(i==*E1_Num_In_Queue)
				{
					E1_Time_Arrival[i] = 0;
				}
				else
				{
					E1_Time_Arrival[i] = E1_Time_Arrival[i + 1];
				}

			}


			(*N1_Num_In_Queue)--;
			(*E1_Num_In_Queue)--;
			(*E_Num_In_Queue)--;
			(*Sys_Num_In_Queue)--; // customer in queue1

			*N1_next_dept_time = *Sim_Time + expon(*N1C1_mean_service_time);

			(*N2_Num_In_Queue)++; // customers for queue2
			(*Sys_Num_In_Queue)++;

			if (N1_Arrival_Type[0] == 1)
			{

				N2C1_arrival(Sim_Time, Time_since_Last_N2_Event, Last_Event_N2_Time,
					Sys_Area_Under_Q, Sys_Num_In_Queue, N2_Area_Under_Q, N2_Num_In_Queue, N2_Server_Status, N2_Num_Custs_Delayed, E2_qDelay, E2_Time_Arrival, E2_Total_qDelay, E_Total_qDelay,
					E_Num_In_Queue, E2_Num_In_Queue, N2_Q_limit, num_of_Sys_full, num_of_N2_full, N2C1_mean_service_time, temp_type, temp_time, N2_Arrival_Type, N2_Time_Arrival, N2_next_dept_time,
					N2_Sys_Time_Arrival,num_of_N2_arr, num_of_Sys_arr);

			}

			else if (N1_Arrival_Type[0] == 2)
			{

				N2C2_arrival(Sim_Time, Time_since_Last_N2_Event, Last_Event_N2_Time,
					Sys_Area_Under_Q, Sys_Num_In_Queue, N2_Area_Under_Q, N2_Num_In_Queue, N2_Server_Status, N2_Num_Custs_Delayed, E2_qDelay, E2_Time_Arrival, E2_Total_qDelay, E_Total_qDelay,
					E_Num_In_Queue, E2_Num_In_Queue, N2_Q_limit, num_of_Sys_full, num_of_N2_full, N2C2_mean_service_time, temp_type, temp_time, N2_Arrival_Type, N2_Time_Arrival, N2_next_dept_time,
					N2_Sys_Time_Arrival,num_of_N2_arr, num_of_Sys_arr);

			}
		}
		else
		{
			*N1_Server_Status = Idle;
			*N1_next_dept_time = pow(10, 30);
			*temp_type = N1_Arrival_Type[0];
			*temp_time = N1_Time_Arrival[0];

			if (N1_Arrival_Type[0] == 1)
			{

				*E1_sys_delay = *Sim_Time - E1_Time_Arrival[0];
				*N1_sys_delay = *Sim_Time - N1_Time_Arrival[0];

				*N1_total_sys_delay += *N1_sys_delay;
				*E1_total_sys_delay += *E1_sys_delay;
				*E_total_sys_delay += *E1_sys_delay;

                (*N2_Num_In_Queue)++;
                (*Sys_Num_In_Queue)++;
				N2C1_arrival(Sim_Time, Time_since_Last_N2_Event, Last_Event_N2_Time,
					Sys_Area_Under_Q, Sys_Num_In_Queue, N2_Area_Under_Q, N2_Num_In_Queue, N2_Server_Status, N2_Num_Custs_Delayed, E2_qDelay, E2_Time_Arrival, E2_Total_qDelay, E_Total_qDelay,
					E_Num_In_Queue, E2_Num_In_Queue, N2_Q_limit, num_of_Sys_full, num_of_N2_full, N2C1_mean_service_time, temp_type, temp_time, N2_Arrival_Type, N2_Time_Arrival, N2_next_dept_time,
					N2_Sys_Time_Arrival,num_of_N2_arr, num_of_Sys_arr);

			}

			else if (N1_Arrival_Type[0] == 2)
			{

				*E1_sys_delay = *Sim_Time - E1_Time_Arrival[0];
				*N1_sys_delay = *Sim_Time - N1_Time_Arrival[0];

				*N1_total_sys_delay += *N1_sys_delay;
				*E1_total_sys_delay += *E1_sys_delay;
				*E_total_sys_delay += *E1_sys_delay;

				(*N2_Num_In_Queue)++;
                (*Sys_Num_In_Queue)++;

				N2C2_arrival(Sim_Time, Time_since_Last_N2_Event, Last_Event_N2_Time,
					Sys_Area_Under_Q, Sys_Num_In_Queue, N2_Area_Under_Q, N2_Num_In_Queue, N2_Server_Status, N2_Num_Custs_Delayed, E2_qDelay, E2_Time_Arrival, E2_Total_qDelay, E_Total_qDelay,
					E_Num_In_Queue, E2_Num_In_Queue, N2_Q_limit, num_of_Sys_full, num_of_N2_full, N2C2_mean_service_time, temp_type, temp_time, N2_Arrival_Type, N2_Time_Arrival, N2_next_dept_time,
					N2_Sys_Time_Arrival,num_of_N2_arr, num_of_Sys_arr);

			}
		}

	}
	else if (N1_Arrival_Type[1] == 2)
	{
		if (*E1_Num_In_Queue >= 2)
		{
			(*N1_Num_Custs_Delayed)++;



			*N1_qDelay = *Sim_Time - N1_Time_Arrival[1];
			*N1_sys_delay = *Sim_Time - N1_Time_Arrival[0];
			*E1_qDelay = *Sim_Time - E1_Time_Arrival[1];
			*E1_sys_delay = *Sim_Time - E1_Time_Arrival[0];


			*N1_Total_qDelay += *N1_qDelay;
			*N1_total_sys_delay += *N1_sys_delay;
			*E1_Total_qDelay += *E1_qDelay;
			*E1_total_sys_delay += *E1_sys_delay;

			*E_Total_qDelay += *E1_qDelay;
			*E_total_sys_delay += *E1_sys_delay;

			*temp_type = N1_Arrival_Type[0];
			*temp_time = N1_Time_Arrival[0];


			for (int i = 0; i <= *N1_Num_In_Queue; i++)
			{
				if(i==*N1_Num_In_Queue)
				{
					N1_Time_Arrival[i] = 0;
					N1_Arrival_Type[i] = 0;
				}
				else
				{
				N1_Time_Arrival[i] = N1_Time_Arrival[i + 1];
				N1_Arrival_Type[i] = N1_Arrival_Type[i + 1];
				}
			}

			for (int i = 0; i <= *E1_Num_In_Queue; i++)
			{
				if(i==*E1_Num_In_Queue-1||i ==*E1_Num_In_Queue )
				{
					E1_Time_Arrival[i] = 0;
				}
				else
				{
					E1_Time_Arrival[i] = E1_Time_Arrival[i + 2];
				}

			}
			(*N1_Num_In_Queue)--;
			(*E_Num_In_Queue)--;
			(*E_Num_In_Queue)--;
			(*E1_Num_In_Queue)--;
			(*E1_Num_In_Queue)--;
			(*Sys_Num_In_Queue)--;
			*N1_next_dept_time = *Sim_Time + expon(*N1C2_mean_service_time);

            (*N2_Num_In_Queue)++;
			(*Sys_Num_In_Queue)++;

			if (N1_Arrival_Type[0] == 1)
			{

				N2C1_arrival(Sim_Time, Time_since_Last_N2_Event, Last_Event_N2_Time,
					Sys_Area_Under_Q, Sys_Num_In_Queue, N2_Area_Under_Q, N2_Num_In_Queue, N2_Server_Status, N2_Num_Custs_Delayed, E2_qDelay, E2_Time_Arrival, E2_Total_qDelay, E_Total_qDelay,
					E_Num_In_Queue, E2_Num_In_Queue, N2_Q_limit, num_of_Sys_full, num_of_N2_full, N2C1_mean_service_time, temp_type, temp_time, N2_Arrival_Type, N2_Time_Arrival, N2_next_dept_time,
					N2_Sys_Time_Arrival,num_of_N2_arr, num_of_Sys_arr);

			}

			else if (N1_Arrival_Type[0] == 2)
			{

				N2C2_arrival(Sim_Time, Time_since_Last_N2_Event, Last_Event_N2_Time,
					Sys_Area_Under_Q, Sys_Num_In_Queue, N2_Area_Under_Q, N2_Num_In_Queue, N2_Server_Status, N2_Num_Custs_Delayed, E2_qDelay, E2_Time_Arrival, E2_Total_qDelay, E_Total_qDelay,
					E_Num_In_Queue, E2_Num_In_Queue, N2_Q_limit, num_of_Sys_full, num_of_N2_full, N2C2_mean_service_time, temp_type, temp_time, N2_Arrival_Type, N2_Time_Arrival, N2_next_dept_time,
					N2_Sys_Time_Arrival,num_of_N2_arr, num_of_Sys_arr);

			}
		}
		else
		{
			*N1_Server_Status = Idle;
			*N1_next_dept_time = pow(10, 30);
			*temp_type = N1_Arrival_Type[0];
			*temp_time = N1_Time_Arrival[0];


			if (N1_Arrival_Type[0] == 1)
			{

				*E1_sys_delay = *Sim_Time - E1_Time_Arrival[0];
				*N1_sys_delay = *Sim_Time - N1_Time_Arrival[0];

				*N1_total_sys_delay += *N1_sys_delay;
				*E1_total_sys_delay += *E1_sys_delay;
				*E_total_sys_delay += *E1_sys_delay;

				(*N2_Num_In_Queue)++;
                (*Sys_Num_In_Queue)++;

				N2C1_arrival(Sim_Time, Time_since_Last_N2_Event, Last_Event_N2_Time,
					Sys_Area_Under_Q, Sys_Num_In_Queue, N2_Area_Under_Q, N2_Num_In_Queue, N2_Server_Status, N2_Num_Custs_Delayed, E2_qDelay, E2_Time_Arrival, E2_Total_qDelay, E_Total_qDelay,
					E_Num_In_Queue, E2_Num_In_Queue, N2_Q_limit, num_of_Sys_full, num_of_N2_full, N2C1_mean_service_time, temp_type, temp_time, N2_Arrival_Type, N2_Time_Arrival, N2_next_dept_time,
					N2_Sys_Time_Arrival,num_of_N2_arr, num_of_Sys_arr);

			}

			else if (N1_Arrival_Type[0] == 2)
			{

				*E1_sys_delay = *Sim_Time - E1_Time_Arrival[0];
				*N1_sys_delay = *Sim_Time - N1_Time_Arrival[0];

				*N1_total_sys_delay += *N1_sys_delay;
				*E1_total_sys_delay += *E1_sys_delay;
				*E_total_sys_delay += *E1_sys_delay;

				(*N2_Num_In_Queue)++;
                (*Sys_Num_In_Queue)++;

				N2C2_arrival(Sim_Time, Time_since_Last_N2_Event, Last_Event_N2_Time,
					Sys_Area_Under_Q, Sys_Num_In_Queue, N2_Area_Under_Q, N2_Num_In_Queue, N2_Server_Status, N2_Num_Custs_Delayed, E2_qDelay, E2_Time_Arrival, E2_Total_qDelay, E_Total_qDelay,
					E_Num_In_Queue, E2_Num_In_Queue, N2_Q_limit, num_of_Sys_full, num_of_N2_full, N2C2_mean_service_time, temp_type, temp_time, N2_Arrival_Type, N2_Time_Arrival, N2_next_dept_time,
					N2_Sys_Time_Arrival,num_of_N2_arr,num_of_Sys_arr);

			}
		}
	}

}

void N1C1_arrival(double* Sim_Time, double *N1C1_next_arr_time, float *C1_mean_interarrival_time, double *Time_since_Last_Event, double *Last_Event_Time, double *Time_since_Last_N1_Event, double* Last_Event_N1_Time,
	double *Sys_Area_Under_Q, int* Sys_Num_In_Queue, double* N1_Area_Under_Q, int *N1_Num_In_Queue, int *N1_Server_Status, int* N1_Num_Custs_Delayed, double *E1_qDelay, double*E1_Time_Arrival, double *E1_Total_qDelay, double* E_Total_qDelay,
	int* E_Num_In_Queue, int* E1_Num_In_Queue, int *N1_Q_limit, double *num_of_Sys_full, double* num_of_N1_full, float *N1C1_mean_service_time, int * N1_Arrival_Type, double *N1_Time_Arrival, double*N1_next_dept_time)
{
	*Sim_Time = *N1C1_next_arr_time;
	*N1C1_next_arr_time = *Sim_Time + expon(*C1_mean_interarrival_time);

	*Time_since_Last_Event = *Sim_Time - *Last_Event_Time;
	*Last_Event_Time = *Sim_Time;

	*Time_since_Last_N1_Event = *Sim_Time - *Last_Event_N1_Time;
	*Last_Event_N1_Time = *Sim_Time;

	*Sys_Area_Under_Q += (*Sys_Num_In_Queue) * (*Time_since_Last_Event);
	*N1_Area_Under_Q += (*N1_Num_In_Queue) * (*Time_since_Last_N1_Event);

	(*N1_Num_In_Queue)++;
    (*Sys_Num_In_Queue)++;

	if (*N1_Server_Status == Idle)
	{
		if (*E1_Num_In_Queue >= 1 && *N1_Num_In_Queue == 0)
		{
			(*N1_Num_Custs_Delayed)++;
			*N1_Server_Status = Busy;

			*E1_qDelay = *Sim_Time - E1_Time_Arrival[1];
			*E1_Total_qDelay += *E1_qDelay;
			*E_Total_qDelay += *E1_qDelay;

			*N1_next_dept_time = *Sim_Time + expon(*N1C1_mean_service_time);

			N1_Time_Arrival[0] = *Sim_Time;
			N1_Arrival_Type[0] = 1;

			for (int i = 0; i <= *E1_Num_In_Queue; i++)
			{
				if(i==*E1_Num_In_Queue)
				{
					E1_Time_Arrival[i] = 0;
				}
				else
				{
					E1_Time_Arrival[i] = E1_Time_Arrival[i + 1];
				}

			}
			(*E_Num_In_Queue)--;
			(*E1_Num_In_Queue)--;
			(*N1_Num_In_Queue)--;
            (*Sys_Num_In_Queue)--;
		}
		else
		{

			if (*N1_Num_In_Queue > *N1_Q_limit)
			{
				(*Sys_Num_In_Queue)--;
				(*N1_Num_In_Queue)--;
				(*num_of_Sys_full)++;
				(*num_of_N1_full)++;
			}

			else
			{
				N1_Time_Arrival[*N1_Num_In_Queue] = *Sim_Time;
				N1_Arrival_Type[*N1_Num_In_Queue] = 1;

			}
		}
	}
	else
	{

		if (*N1_Num_In_Queue > *N1_Q_limit)
		{
			(*Sys_Num_In_Queue)--;
			(*N1_Num_In_Queue)--;
			(*num_of_Sys_full)++;
			(*num_of_N1_full)++;
		}

		else
		{
			N1_Time_Arrival[*N1_Num_In_Queue] = *Sim_Time;
			N1_Arrival_Type[*N1_Num_In_Queue] = 1;

		}
	}




}

void N1C2_arrival(double *Sim_Time, double *N1C2_next_arr_time, float *C2_mean_interarrival_time, double* Time_since_Last_Event, double *Last_Event_Time, double *Time_since_Last_N1_Event, double *Last_Event_N1_Time,
	double *Sys_Area_Under_Q, int *Sys_Num_In_Queue, double *N1_Area_Under_Q, int *N1_Num_In_Queue, int* N1_Server_Status, int *N1_Num_Custs_Delayed, double *E1_qDelay, double* E1_Time_Arrival, double *E1_Total_qDelay, double *E_Total_qDelay,
	int *E_Num_In_Queue, int *E1_Num_In_Queue, int *N1_Q_limit, double *num_of_Sys_full, double *num_of_N1_full, float *N1C2_mean_service_time, int * N1_Arrival_Type, double *N1_Time_Arrival, double*N1_next_dept_time)
{
	*Sim_Time = *N1C2_next_arr_time;
	*N1C2_next_arr_time = *Sim_Time + expon(*C2_mean_interarrival_time);
	*Time_since_Last_Event = *Sim_Time - *Last_Event_Time;
	*Last_Event_Time = *Sim_Time;
	*Time_since_Last_N1_Event = *Sim_Time - *Last_Event_N1_Time;


	*Last_Event_N1_Time = *Sim_Time;

	*Sys_Area_Under_Q += (*Sys_Num_In_Queue) * (*Time_since_Last_Event);
	*N1_Area_Under_Q += (*N1_Num_In_Queue) * (*Time_since_Last_N1_Event);

	(*N1_Num_In_Queue)++;
    (*Sys_Num_In_Queue)++;

	if (*N1_Server_Status == Idle)
	{
		if (*E1_Num_In_Queue >= 2)
		{
			(*N1_Num_Custs_Delayed)++;
			*N1_Server_Status = Busy;

			*E1_qDelay = *Sim_Time - E1_Time_Arrival[1];
			*E1_Total_qDelay += *E1_qDelay;
			*E_Total_qDelay += *E1_qDelay;

			*N1_next_dept_time = *Sim_Time + expon(*N1C2_mean_service_time);

			N1_Time_Arrival[0] = *Sim_Time;
			N1_Arrival_Type[0] = 2;

			for (int i = 0; i <= *E1_Num_In_Queue; i++)
			{
				if(i==*E1_Num_In_Queue-1||i ==*E1_Num_In_Queue )
				{
					E1_Time_Arrival[i] = 0;
				}
				else
				{
					E1_Time_Arrival[i] = E1_Time_Arrival[i + 2];
				}

			}
			(*E_Num_In_Queue)--;
			(*E_Num_In_Queue)--;
			(*E1_Num_In_Queue)--;
			(*E1_Num_In_Queue)--;
			(*N1_Num_In_Queue)--;
            (*Sys_Num_In_Queue)--;

		}
		else
		{

			if (*N1_Num_In_Queue > *N1_Q_limit)
			{
				(*Sys_Num_In_Queue)--;
				(*N1_Num_In_Queue)--;
				(*num_of_Sys_full)++;
				(*num_of_N1_full)++;
			}

			else
			{
				N1_Time_Arrival[*N1_Num_In_Queue] = *Sim_Time;
				N1_Arrival_Type[*N1_Num_In_Queue] = 2;

			}
		}
	}
	else {

		if (*N1_Num_In_Queue > *N1_Q_limit)
		{
			(*Sys_Num_In_Queue)--;
			(*N1_Num_In_Queue)--;
			(*num_of_Sys_full)++;
			(*num_of_N1_full)++;
		}

		else
		{
			N1_Time_Arrival[*N1_Num_In_Queue] = *Sim_Time;
			N1_Arrival_Type[*N1_Num_In_Queue] = 2;

		}
	}

}

void E1_arrival(double *Sim_Time, double *E1_next_arr_time, float *E1_mean_interarrival_time, double *Time_since_Last_Event, double *Last_Event_Time,
	double *E_Area_Under_Q, int *E_Num_In_Queue, double *Time_since_Last_N1_Event, double *Last_Event_N1_Time, double *E1_Area_Under_Q, int *E1_Num_In_Queue,
	int *N1_Server_Status, int *N1_Num_In_Queue, int* N1_Arrival_Type, double * N1_next_dept_time, double* N1_Time_Arrival, float * N1C1_mean_service_time, float * N1C2_mean_service_time,
	double *num_of_E_full, double *num_of_E1_full, double *N1_qDelay, double *N1_Total_qDelay, int *E1_Q_limit, int*N1_Num_Custs_Delayed, double*E1_Time_Arrival, int *Sys_Num_In_Queue)
{

	*Sim_Time = *E1_next_arr_time;
	*E1_next_arr_time = *Sim_Time + expon(*E1_mean_interarrival_time);

	*Time_since_Last_Event = *Sim_Time - *Last_Event_Time;
	*Last_Event_Time = *Sim_Time;
	*E_Area_Under_Q += (*E_Num_In_Queue) * (*Time_since_Last_Event);

	*Time_since_Last_N1_Event = *Sim_Time - *Last_Event_N1_Time;
	*Last_Event_N1_Time = *Sim_Time;
	*E1_Area_Under_Q += (*E1_Num_In_Queue) * (*Time_since_Last_N1_Event);

	if (*N1_Server_Status == Idle)
	{
		if (*N1_Num_In_Queue != 0)
		{
			if (N1_Arrival_Type[1] == 1)
			{
				if (*E1_Num_In_Queue >= 0)
				{

					(*N1_Num_Custs_Delayed)++;
					*N1_Server_Status = Busy;


					*N1_qDelay = *Sim_Time - N1_Time_Arrival[1];
					*N1_Total_qDelay += *N1_qDelay;

					*N1_next_dept_time = *Sim_Time + expon(*N1C1_mean_service_time);


					E1_Time_Arrival[0] = *Sim_Time;

					for (int i = 0; i <= *N1_Num_In_Queue; i++)
				{
				if(i==*N1_Num_In_Queue)
				{
					N1_Time_Arrival[i] = 0;
					N1_Arrival_Type[i] = 0;
				}
				else
				{
				N1_Time_Arrival[i] = N1_Time_Arrival[i + 1];
				N1_Arrival_Type[i] = N1_Arrival_Type[i + 1];
				}
			}
					(*N1_Num_In_Queue)--;
					(*Sys_Num_In_Queue)--;

				}
				else
				{
					(*E_Num_In_Queue)++;
					(*E1_Num_In_Queue)++;
					if (*E1_Num_In_Queue > *E1_Q_limit)
					{
						(*E_Num_In_Queue)--;
						(*E1_Num_In_Queue)--;
						(*num_of_E_full)++;
						(*num_of_E1_full)++;
					}

					else
					{
						E1_Time_Arrival[*E1_Num_In_Queue] = *Sim_Time;
					}
				}
			}
			else if (N1_Arrival_Type[1] == 2)
			{

				if (*E1_Num_In_Queue >= 1)
				{

					(*N1_Num_Custs_Delayed)++;
					*N1_Server_Status = Busy;


					*N1_qDelay = *Sim_Time - N1_Time_Arrival[1];
					*N1_Total_qDelay += *N1_qDelay;

					*N1_next_dept_time = *Sim_Time + expon(*N1C2_mean_service_time);
     //               printf("Depature Time %f \n", *N1_next_dept_time);

					(*E1_Num_In_Queue)--;
					(*E_Num_In_Queue)--;

					E1_Time_Arrival[0] = *Sim_Time;

					for (int i = 0; i <= *N1_Num_In_Queue; i++)
			{
				if(i==*N1_Num_In_Queue)
				{
					N1_Time_Arrival[i] = 0;
					N1_Arrival_Type[i] = 0;
				}
				else
				{
				N1_Time_Arrival[i] = N1_Time_Arrival[i + 1];
				N1_Arrival_Type[i] = N1_Arrival_Type[i + 1];
				}
			}
					(*N1_Num_In_Queue)--;
					(*Sys_Num_In_Queue)--;

				}
				else
				{
					(*E1_Num_In_Queue)++;
					(*E_Num_In_Queue)++;

					if (*E1_Num_In_Queue > *E1_Q_limit)
					{
						(*E1_Num_In_Queue)--;
						(*E_Num_In_Queue)--;
						(*num_of_E_full)++;
						(*num_of_E1_full)++;
					}
					else
					{
						E1_Time_Arrival[*E1_Num_In_Queue] = *Sim_Time;
					}
				}
			}
		}
		else
		{
			(*E1_Num_In_Queue)++;
			(*E_Num_In_Queue)++;

			if (*E1_Num_In_Queue > *E1_Q_limit)
			{
				(*E1_Num_In_Queue)--;
				(*E_Num_In_Queue)--;
				(*num_of_E_full)++;
				(*num_of_E1_full)++;
			}
			else
			{
				E1_Time_Arrival[*E1_Num_In_Queue] = *Sim_Time;
			}
		}
	}
	else
	{
		(*E1_Num_In_Queue)++;
		(*E_Num_In_Queue)++;

		if (*E1_Num_In_Queue > *E1_Q_limit)
		{
			(*E1_Num_In_Queue)--;
			(*E_Num_In_Queue)--;
			(*num_of_E_full)++;
			(*num_of_E1_full)++;
		}
		else
		{
			E1_Time_Arrival[*E1_Num_In_Queue] = *Sim_Time;
		}
	}
}

//node2
void N2_depature(double *Sim_Time, double *N2_next_dept_time, double *Time_since_Last_Event, double *Last_Event_Time, double* Sys_Area_Under_Q, int* Sys_Num_In_Queue, double *E_Area_Under_Q, int* E_Num_In_Queue,
	double* Time_since_Last_N2_Event, double* Last_Event_N2_Time, double *E2_Area_Under_Q, int *E2_Num_In_Queue, int* N2_Num_In_Queue, int* N2_Server_Status, int *N2_Arrival_Type, double* E2_sys_delay, double * E2_Time_Arrival,
	double* N2_sys_delay, double*N2_Time_Arrival, double* N2_total_sys_delay, double *E2_total_sys_delay, double *E_total_sys_delay, int *temp_type, double *temp_time, float *N2C1_mean_service_time, float *N2C2_mean_service_time,
	double*N2_Area_Under_Q, int*N2_Num_Custs_Delayed, double*N2_qDelay, double*E2_qDelay, double*N2_Total_qDelay, double *E2_Total_qDelay, double *E_Total_qDelay,

	double* Time_since_Last_N3_Event, double *Last_Event_N3_Time,
	double *N3_Area_Under_Q, int *N3_Num_In_Queue, int *N3_Server_Status, int*N3_Num_Custs_Delayed, double *E3_qDelay, double* E3_Time_Arrival, double *E3_Total_qDelay,
	int* E3_Num_In_Queue, int* N3_Q_limit, double* num_of_Sys_full, double *num_of_N3_full, float *N3C1_mean_service_time, int * N3_Arrival_Type, double *N3_Time_Arrival, double*N3_next_dept_time,
	double*N3_Sys_Time_Arrival, float *N3C2_mean_service_time, int *Num_Custs_Delayed,double*N2_Sys_Time_Arrival,double*num_of_N3_arr, double *num_of_Sys_arr, double*Sys_qDelay , double*Sys_Total_qDelay
)

{

	*Sim_Time = *N2_next_dept_time;

	*Time_since_Last_Event = *Sim_Time - *Last_Event_Time;
	*Last_Event_Time = *Sim_Time;
	*Sys_Area_Under_Q += (*Sys_Num_In_Queue) * (*Time_since_Last_Event);
	*E_Area_Under_Q += (*E_Num_In_Queue) * (*Time_since_Last_Event);


	*Time_since_Last_N2_Event = *Sim_Time - *Last_Event_N2_Time;
	*Last_Event_N2_Time = *Sim_Time;
	*E2_Area_Under_Q += (*E2_Num_In_Queue) * (*Time_since_Last_N2_Event);

	*N2_Area_Under_Q += (*N2_Num_In_Queue) * (*Time_since_Last_N2_Event);


	if (*N2_Num_In_Queue == 0) {
		*N2_Server_Status = Idle;
		*N2_next_dept_time = pow(10, 30);



		if (N2_Arrival_Type[0] == 1)
		{

			*E2_sys_delay = *Sim_Time - E2_Time_Arrival[0];
			*N2_sys_delay = *Sim_Time - N2_Time_Arrival[0];

			*N2_total_sys_delay += *N2_sys_delay;
			*E2_total_sys_delay += *E2_sys_delay;
			*E_total_sys_delay += *E2_sys_delay;

			*temp_type = N2_Arrival_Type[0];
			*temp_time = N2_Sys_Time_Arrival[0];

			(*N3_Num_In_Queue)++;
            (*Sys_Num_In_Queue)++;

			N3C1_arrival(Sim_Time, Time_since_Last_N3_Event, Last_Event_N3_Time,
				Sys_Area_Under_Q, Sys_Num_In_Queue, N3_Area_Under_Q, N3_Num_In_Queue, N3_Server_Status, N3_Num_Custs_Delayed, E3_qDelay, E3_Time_Arrival, E3_Total_qDelay, E_Total_qDelay,
				E_Num_In_Queue, E3_Num_In_Queue, N3_Q_limit, num_of_Sys_full, num_of_N3_full, N3C1_mean_service_time, temp_type, temp_time, N3_Arrival_Type, N3_Time_Arrival, N3_next_dept_time,
				N3_Sys_Time_Arrival, Num_Custs_Delayed,num_of_N3_arr, num_of_Sys_arr ,Sys_qDelay ,Sys_Total_qDelay);

		}

		else if (N2_Arrival_Type[0] == 2)
		{

			*E2_sys_delay = *Sim_Time - E2_Time_Arrival[0];
			*N2_sys_delay = *Sim_Time - N2_Time_Arrival[0];

			*N2_total_sys_delay += *N2_sys_delay;
			*E2_total_sys_delay += *E2_sys_delay;
			*E_total_sys_delay += *E2_sys_delay;

			*temp_type = N2_Arrival_Type[0];
			*temp_time = N2_Sys_Time_Arrival[0];

			(*N3_Num_In_Queue)++;
            (*Sys_Num_In_Queue)++;

			N3C2_arrival(Sim_Time, Time_since_Last_N3_Event, Last_Event_N3_Time,
				Sys_Area_Under_Q, Sys_Num_In_Queue, N3_Area_Under_Q, N3_Num_In_Queue, N3_Server_Status, N3_Num_Custs_Delayed, E3_qDelay, E3_Time_Arrival, E3_Total_qDelay, E_Total_qDelay,
				E_Num_In_Queue, E3_Num_In_Queue, N3_Q_limit, num_of_Sys_full, num_of_N3_full, N3C2_mean_service_time, temp_type, temp_time, N3_Arrival_Type, N3_Time_Arrival, N3_next_dept_time,
				N3_Sys_Time_Arrival, Num_Custs_Delayed,num_of_N3_arr, num_of_Sys_arr, Sys_qDelay, Sys_Total_qDelay);

		}
	}
	else if (N2_Arrival_Type[1] == 1)
	{

		if (*E2_Num_In_Queue >= 1)
		{
			(*N2_Num_Custs_Delayed)++;



			*N2_qDelay = *Sim_Time - N2_Time_Arrival[1];
			*N2_sys_delay = *Sim_Time - N2_Time_Arrival[0];

			*E2_qDelay = *Sim_Time - E2_Time_Arrival[1];
			*E2_sys_delay = *Sim_Time - E2_Time_Arrival[0];



			*N2_Total_qDelay += *N2_qDelay;
			*N2_total_sys_delay += *N2_sys_delay;
			*E2_Total_qDelay += *E2_qDelay;
			*E2_total_sys_delay += *E2_sys_delay;

			*E_Total_qDelay += *E2_qDelay;
			*E_total_sys_delay += *E2_sys_delay;

			*temp_type = N2_Arrival_Type[0];
			*temp_time = N2_Sys_Time_Arrival[0];


			for (int i = 0; i <= *N2_Num_In_Queue; i++)
			{
				if(i == *N2_Num_In_Queue)
				{
				N2_Time_Arrival[i] = 0;
				N2_Arrival_Type[i] = 0;
				N2_Sys_Time_Arrival[i] = 0;
				}

				else
				{
				N2_Time_Arrival[i] = N2_Time_Arrival[i + 1];
				N2_Arrival_Type[i] = N2_Arrival_Type[i + 1];
				N2_Sys_Time_Arrival[i] = N2_Sys_Time_Arrival[i+1];
				}


			}

			for (int i = 0; i <= *E2_Num_In_Queue; i++)
			{
				if(i == *E2_Num_In_Queue)
				{
					E2_Time_Arrival[i] = 0;
				}
				else
				{
					E2_Time_Arrival[i] = E2_Time_Arrival[i + 1];
				}

			}
			(*N2_Num_In_Queue)--;
			(*E2_Num_In_Queue)--;
			(*E_Num_In_Queue)--;
            (*Sys_Num_In_Queue)--;

			*N2_next_dept_time = *Sim_Time + expon(*N2C1_mean_service_time);

			(*N3_Num_In_Queue)++;
            (*Sys_Num_In_Queue)++;

			if (N2_Arrival_Type[0] == 1)
			{

				N3C1_arrival(Sim_Time, Time_since_Last_N3_Event, Last_Event_N3_Time,
					Sys_Area_Under_Q, Sys_Num_In_Queue, N3_Area_Under_Q, N3_Num_In_Queue, N3_Server_Status, N3_Num_Custs_Delayed, E3_qDelay, E3_Time_Arrival, E3_Total_qDelay, E_Total_qDelay,
					E_Num_In_Queue, E3_Num_In_Queue, N3_Q_limit, num_of_Sys_full, num_of_N3_full, N3C1_mean_service_time, temp_type, temp_time, N3_Arrival_Type, N3_Time_Arrival, N3_next_dept_time,
					N3_Sys_Time_Arrival, Num_Custs_Delayed,num_of_N3_arr, num_of_Sys_arr, Sys_qDelay, Sys_Total_qDelay);

			}

			else if (N2_Arrival_Type[0] == 2)
			{

				N3C2_arrival(Sim_Time, Time_since_Last_N3_Event, Last_Event_N3_Time,
					Sys_Area_Under_Q, Sys_Num_In_Queue, N3_Area_Under_Q, N3_Num_In_Queue, N3_Server_Status, N3_Num_Custs_Delayed, E3_qDelay, E3_Time_Arrival, E3_Total_qDelay, E_Total_qDelay,
					E_Num_In_Queue, E3_Num_In_Queue, N3_Q_limit, num_of_Sys_full, num_of_N3_full, N3C2_mean_service_time, temp_type, temp_time, N3_Arrival_Type, N3_Time_Arrival, N3_next_dept_time,
					N3_Sys_Time_Arrival, Num_Custs_Delayed,num_of_N3_arr,num_of_Sys_arr, Sys_qDelay ,Sys_Total_qDelay);

			}
		}
		else
		{
			*N2_Server_Status = Idle;
			*N2_next_dept_time = pow(10, 30);

			if (N2_Arrival_Type[0] == 1)
			{

				*E2_sys_delay = *Sim_Time - E2_Time_Arrival[0];
				*N2_sys_delay = *Sim_Time - N2_Time_Arrival[0];

				*N2_total_sys_delay += *N2_sys_delay;
				*E2_total_sys_delay += *E2_sys_delay;
				*E_total_sys_delay += *E2_sys_delay;

				*temp_type = N2_Arrival_Type[0];
                *temp_time = N2_Sys_Time_Arrival[0];

                (*N3_Num_In_Queue)++;
                (*Sys_Num_In_Queue)++;

				N3C1_arrival(Sim_Time, Time_since_Last_N3_Event, Last_Event_N3_Time,
					Sys_Area_Under_Q, Sys_Num_In_Queue, N3_Area_Under_Q, N3_Num_In_Queue, N3_Server_Status, N3_Num_Custs_Delayed, E3_qDelay, E3_Time_Arrival, E3_Total_qDelay, E_Total_qDelay,
					E_Num_In_Queue, E3_Num_In_Queue, N3_Q_limit, num_of_Sys_full, num_of_N3_full, N3C1_mean_service_time, temp_type, temp_time, N3_Arrival_Type, N3_Time_Arrival, N3_next_dept_time,
					N3_Sys_Time_Arrival, Num_Custs_Delayed,num_of_N3_arr, num_of_Sys_arr, Sys_qDelay, Sys_Total_qDelay);

			}

			else if (N2_Arrival_Type[0] == 2)
			{

				*E2_sys_delay = *Sim_Time - E2_Time_Arrival[0];
				*N2_sys_delay = *Sim_Time - N2_Time_Arrival[0];

				*N2_total_sys_delay += *N2_sys_delay;
				*E2_total_sys_delay += *E2_sys_delay;
				*E_total_sys_delay += *E2_sys_delay;

				*temp_type = N2_Arrival_Type[0];
                *temp_time = N2_Sys_Time_Arrival[0];

                (*N3_Num_In_Queue)++;
                (*Sys_Num_In_Queue)++;

				N3C2_arrival(Sim_Time, Time_since_Last_N3_Event, Last_Event_N3_Time,
					Sys_Area_Under_Q, Sys_Num_In_Queue, N3_Area_Under_Q, N3_Num_In_Queue, N3_Server_Status, N3_Num_Custs_Delayed, E3_qDelay, E3_Time_Arrival, E3_Total_qDelay, E_Total_qDelay,
					E_Num_In_Queue, E3_Num_In_Queue, N3_Q_limit, num_of_Sys_full, num_of_N3_full, N3C2_mean_service_time, temp_type, temp_time, N3_Arrival_Type, N3_Time_Arrival, N3_next_dept_time,
					N3_Sys_Time_Arrival, Num_Custs_Delayed,num_of_N3_arr, num_of_Sys_arr, Sys_qDelay, Sys_Total_qDelay);

			}
		}

	}
	else if (N2_Arrival_Type[1] == 2)
	{
		if (*E2_Num_In_Queue >= 2)
		{
			(*N2_Num_Custs_Delayed)++;



			*N2_qDelay = *Sim_Time - N2_Time_Arrival[1];
			*N2_sys_delay = *Sim_Time - N2_Time_Arrival[0];
			*E2_qDelay = *Sim_Time - E2_Time_Arrival[1];
			*E2_sys_delay = *Sim_Time - E2_Time_Arrival[0];


			*N2_Total_qDelay += *N2_qDelay;
			*N2_total_sys_delay += *N2_sys_delay;
			*E2_Total_qDelay += *E2_qDelay;
			*E2_total_sys_delay += *E2_sys_delay;

			*E_Total_qDelay += *E2_qDelay;
			*E_total_sys_delay += *E2_sys_delay;

			*temp_type = N2_Arrival_Type[0];
			*temp_time = N2_Sys_Time_Arrival[0];


			for (int i = 0; i <= *N2_Num_In_Queue; i++)
			{
				if(i == *N2_Num_In_Queue)
				{
				N2_Time_Arrival[i] = 0;
				N2_Arrival_Type[i] = 0;
				N2_Sys_Time_Arrival[i] = 0;
				}

				else
				{
				N2_Time_Arrival[i] = N2_Time_Arrival[i + 1];
				N2_Arrival_Type[i] = N2_Arrival_Type[i + 1];
				N2_Sys_Time_Arrival[i] = N2_Sys_Time_Arrival[i+1];
				}


			}

			for (int i = 0; i <= *E2_Num_In_Queue; i++)
			{
				if(i == *E2_Num_In_Queue-1||i == *E2_Num_In_Queue)
				{
					E2_Time_Arrival[i] = 0;
				}
				else
				{
					E2_Time_Arrival[i] = E2_Time_Arrival[i + 2];
				}

			}
			(*N2_Num_In_Queue)--;
			(*E_Num_In_Queue)--;
			(*E_Num_In_Queue)--;
			(*E2_Num_In_Queue)--;
			(*E2_Num_In_Queue)--;

            (*Sys_Num_In_Queue)--;

			*N2_next_dept_time = *Sim_Time + expon(*N2C2_mean_service_time);

			(*N3_Num_In_Queue)++;
            (*Sys_Num_In_Queue)++;

			if (N2_Arrival_Type[0] == 1)
			{

				N3C1_arrival(Sim_Time, Time_since_Last_N3_Event, Last_Event_N3_Time,
					Sys_Area_Under_Q, Sys_Num_In_Queue, N3_Area_Under_Q, N3_Num_In_Queue, N3_Server_Status, N3_Num_Custs_Delayed, E3_qDelay, E3_Time_Arrival, E3_Total_qDelay, E_Total_qDelay,
					E_Num_In_Queue, E3_Num_In_Queue, N3_Q_limit, num_of_Sys_full, num_of_N3_full, N3C1_mean_service_time, temp_type, temp_time, N3_Arrival_Type, N3_Time_Arrival, N3_next_dept_time,
					N3_Sys_Time_Arrival,Num_Custs_Delayed,num_of_N3_arr, num_of_Sys_arr, Sys_qDelay, Sys_Total_qDelay);

			}

			else if (N2_Arrival_Type[0] == 2)
			{

				N3C2_arrival(Sim_Time, Time_since_Last_N3_Event, Last_Event_N3_Time,
					Sys_Area_Under_Q, Sys_Num_In_Queue, N3_Area_Under_Q, N3_Num_In_Queue, N3_Server_Status, N3_Num_Custs_Delayed, E3_qDelay, E3_Time_Arrival, E3_Total_qDelay, E_Total_qDelay,
					E_Num_In_Queue, E3_Num_In_Queue, N3_Q_limit, num_of_Sys_full, num_of_N3_full, N3C2_mean_service_time, temp_type, temp_time, N3_Arrival_Type, N3_Time_Arrival, N3_next_dept_time,
					N3_Sys_Time_Arrival, Num_Custs_Delayed,num_of_N3_arr, num_of_Sys_arr, Sys_qDelay, Sys_Total_qDelay);

			}
		}
		else
		{
			*N2_Server_Status = Idle;
			*N2_next_dept_time = pow(10, 30);
			if (N2_Arrival_Type[0] == 1)
			{

				*E2_sys_delay = *Sim_Time - E2_Time_Arrival[0];
				*N2_sys_delay = *Sim_Time - N2_Time_Arrival[0];

				*N2_total_sys_delay += *N2_sys_delay;
				*E2_total_sys_delay += *E2_sys_delay;
				*E_total_sys_delay += *E2_sys_delay;

				*temp_type = N2_Arrival_Type[0];
                *temp_time = N2_Sys_Time_Arrival[0];

                (*N3_Num_In_Queue)++;
                (*Sys_Num_In_Queue)++;

				N3C1_arrival(Sim_Time, Time_since_Last_N3_Event, Last_Event_N3_Time,
					Sys_Area_Under_Q, Sys_Num_In_Queue, N3_Area_Under_Q, N3_Num_In_Queue, N3_Server_Status, N3_Num_Custs_Delayed, E3_qDelay, E3_Time_Arrival, E3_Total_qDelay, E_Total_qDelay,
					E_Num_In_Queue, E3_Num_In_Queue, N3_Q_limit, num_of_Sys_full, num_of_N3_full, N3C1_mean_service_time, temp_type, temp_time, N3_Arrival_Type, N3_Time_Arrival, N3_next_dept_time,
					N3_Sys_Time_Arrival, Num_Custs_Delayed,num_of_N3_arr, num_of_Sys_arr, Sys_qDelay, Sys_Total_qDelay);

			}

			else if (N2_Arrival_Type[0] == 2)
			{

				*E2_sys_delay = *Sim_Time - E2_Time_Arrival[0];
				*N2_sys_delay = *Sim_Time - N2_Time_Arrival[0];

				*N2_total_sys_delay += *N2_sys_delay;
				*E2_total_sys_delay += *E2_sys_delay;
				*E_total_sys_delay += *E2_sys_delay;

                *temp_type = N2_Arrival_Type[0];
                *temp_time = N2_Sys_Time_Arrival[0];

                (*N3_Num_In_Queue)++;
                (*Sys_Num_In_Queue)++;

				N3C2_arrival(Sim_Time, Time_since_Last_N3_Event, Last_Event_N3_Time,
					Sys_Area_Under_Q, Sys_Num_In_Queue, N3_Area_Under_Q, N3_Num_In_Queue, N3_Server_Status, N3_Num_Custs_Delayed, E3_qDelay, E3_Time_Arrival, E3_Total_qDelay, E_Total_qDelay,
					E_Num_In_Queue, E3_Num_In_Queue, N3_Q_limit, num_of_Sys_full, num_of_N3_full, N3C2_mean_service_time, temp_type, temp_time, N3_Arrival_Type, N3_Time_Arrival, N3_next_dept_time,
					N3_Sys_Time_Arrival, Num_Custs_Delayed,num_of_N3_arr,num_of_Sys_arr ,Sys_qDelay, Sys_Total_qDelay);

			}
		}
	}

}

void N2C1_arrival(double *Sim_Time, double* Time_since_Last_N2_Event, double *Last_Event_N2_Time,
	double *Sys_Area_Under_Q, int *Sys_Num_In_Queue, double *N2_Area_Under_Q, int *N2_Num_In_Queue, int *N2_Server_Status, int *N2_Num_Custs_Delayed, double *E2_qDelay, double *E2_Time_Arrival, double *E2_Total_qDelay, double *E_Total_qDelay,
	int *E_Num_In_Queue, int* E2_Num_In_Queue, int* N2_Q_limit, double* num_of_Sys_full, double *num_of_N2_full, float *N2C1_mean_service_time, int *temp_type, double *temp_time, int * N2_Arrival_Type, double *N2_Time_Arrival, double*N2_next_dept_time,
	double*N2_Sys_Time_Arrival,double*num_of_N2_arr, double *num_of_Sys_arr)
{
	(*num_of_N2_arr)++;
	*Time_since_Last_N2_Event = *Sim_Time - *Last_Event_N2_Time;
	*Last_Event_N2_Time = *Sim_Time;

	*N2_Area_Under_Q += (*N2_Num_In_Queue) * (*Time_since_Last_N2_Event);

	if (*N2_Server_Status == Idle)
	{
		if (*E2_Num_In_Queue >= 1 && *N2_Num_In_Queue == 0)
		{
			(*N2_Num_Custs_Delayed)++;
			*N2_Server_Status = Busy;

			*E2_qDelay = *Sim_Time - E2_Time_Arrival[1];
			*E2_Total_qDelay += *E2_qDelay;
			*E_Total_qDelay += *E2_qDelay;

			*N2_next_dept_time = *Sim_Time + expon(*N2C1_mean_service_time);



			N2_Sys_Time_Arrival[0] = *temp_time;
			N2_Time_Arrival[0] = *Sim_Time;
			N2_Arrival_Type[0] = *temp_type;





			for (int i = 0; i <= *E2_Num_In_Queue; i++)
			{
				if(i == *E2_Num_In_Queue)
				{
					E2_Time_Arrival[i] = 0;
				}
				else
				{
					E2_Time_Arrival[i] = E2_Time_Arrival[i + 1];
				}

			}
			(*E_Num_In_Queue)--;
			(*E2_Num_In_Queue)--;
			(*N2_Num_In_Queue)--;
            (*Sys_Num_In_Queue)--;
		}
		else
		{


			if (*N2_Num_In_Queue > *N2_Q_limit)
			{
				(*Sys_Num_In_Queue)--;
				(*N2_Num_In_Queue)--;
				(*num_of_Sys_full)++;
				(*num_of_N2_full)++;
			}

			else
			{
				N2_Sys_Time_Arrival[*N2_Num_In_Queue] = *temp_time;
				N2_Time_Arrival[*N2_Num_In_Queue] = *Sim_Time;
				N2_Arrival_Type[*N2_Num_In_Queue] = *temp_type;

			}
		}
	}
	else
	{

		if (*N2_Num_In_Queue > *N2_Q_limit)
		{
			(*Sys_Num_In_Queue)--;
			(*N2_Num_In_Queue)--;
			(*num_of_Sys_full)++;
			(*num_of_N2_full)++;
		}

		else
		{
			N2_Sys_Time_Arrival[*N2_Num_In_Queue] = *temp_time;
			N2_Time_Arrival[*N2_Num_In_Queue] = *Sim_Time;
			N2_Arrival_Type[*N2_Num_In_Queue] = *temp_type;

		}
	}
}

void N2C2_arrival(double *Sim_Time, double* Time_since_Last_N2_Event, double *Last_Event_N2_Time,
	double *Sys_Area_Under_Q, int *Sys_Num_In_Queue, double *N2_Area_Under_Q, int *N2_Num_In_Queue, int *N2_Server_Status, int *N2_Num_Custs_Delayed, double *E2_qDelay, double*E2_Time_Arrival, double *E2_Total_qDelay, double *E_Total_qDelay,
	int *E_Num_In_Queue, int* E2_Num_In_Queue, int* N2_Q_limit, double* num_of_Sys_full, double *num_of_N2_full, float *N2C2_mean_service_time, int *temp_type, double *temp_time, int * N2_Arrival_Type, double *N2_Time_Arrival,
	double*N2_next_dept_time, double*N2_Sys_Time_Arrival,double*num_of_N2_arr, double *num_of_Sys_arr)
{
	(*num_of_N2_arr)++;
	*Time_since_Last_N2_Event = *Sim_Time - *Last_Event_N2_Time;
	*Last_Event_N2_Time = *Sim_Time;

	*N2_Area_Under_Q += (*N2_Num_In_Queue) * (*Time_since_Last_N2_Event);

	if (*N2_Server_Status == Idle)
	{
		if (*E2_Num_In_Queue >= 2)
		{
			(*N2_Num_Custs_Delayed)++;
			*N2_Server_Status = Busy;

			*E2_qDelay = *Sim_Time - E2_Time_Arrival[1];
			*E2_Total_qDelay += *E2_qDelay;
			*E_Total_qDelay += *E2_qDelay;

			*N2_next_dept_time = *Sim_Time + expon(*N2C2_mean_service_time);


			N2_Sys_Time_Arrival[0] = *temp_time;
			N2_Time_Arrival[0] = *Sim_Time;
			N2_Arrival_Type[0] = *temp_type;



			for (int i = 0; i <= *E2_Num_In_Queue; i++)
			{
				if(i == *E2_Num_In_Queue-1||i == *E2_Num_In_Queue)
				{
					E2_Time_Arrival[i] = 0;
				}
				else
				{
					E2_Time_Arrival[i] = E2_Time_Arrival[i + 2];
				}

			}
			(*E_Num_In_Queue)--;
			(*E_Num_In_Queue)--;
			(*E2_Num_In_Queue)--;
			(*E2_Num_In_Queue)--;
			(*N2_Num_In_Queue)--;
            (*Sys_Num_In_Queue)--;
		}
		else
		{

			if (*N2_Num_In_Queue > *N2_Q_limit)
			{
				(*Sys_Num_In_Queue)--;
				(*N2_Num_In_Queue)--;
				(*num_of_Sys_full)++;
				(*num_of_N2_full)++;
			}

			else
			{
				N2_Sys_Time_Arrival[*N2_Num_In_Queue] = *temp_time;
				N2_Time_Arrival[*N2_Num_In_Queue] = *Sim_Time;
				N2_Arrival_Type[*N2_Num_In_Queue] = *temp_type;


			}
		}
	}
	else
	{

		if (*N2_Num_In_Queue > *N2_Q_limit)
		{
			(*Sys_Num_In_Queue)--;
			(*N2_Num_In_Queue)--;
			(*num_of_Sys_full)++;
			(*num_of_N2_full)++;
		}

		else
		{
			N2_Sys_Time_Arrival[*N2_Num_In_Queue] = *temp_time;
			N2_Time_Arrival[*N2_Num_In_Queue] = *Sim_Time;
			N2_Arrival_Type[*N2_Num_In_Queue] = *temp_type;

		}
	}




}

void E2_arrival(double *Sim_Time, double *E2_next_arr_time, float *E2_mean_interarrival_time, double *Time_since_Last_Event, double *Last_Event_Time,
	double *E_Area_Under_Q, int *E_Num_In_Queue, double *Time_since_Last_N2_Event, double *Last_Event_N2_Time, double *E2_Area_Under_Q, int *E2_Num_In_Queue,
	int *N2_Server_Status, int *N2_Num_In_Queue, int* N2_Arrival_Type, double * N2_next_dept_time, double *N2_Time_Arrival, float * N2C1_mean_service_time, float * N2C2_mean_service_time,
	double *num_of_E_full, double *num_of_E2_full, double *N2_qDelay, double *N2_Total_qDelay, int *E2_Q_limit, int *N2_Num_Custs_Delayed, double* E2_Time_Arrival,double*N2_Sys_Time_Arrival, int *Sys_Num_In_Queue)

{

	*Sim_Time = *E2_next_arr_time;
	*E2_next_arr_time = *Sim_Time + expon(*E2_mean_interarrival_time);

	*Time_since_Last_Event = *Sim_Time - *Last_Event_Time;
	*Last_Event_Time = *Sim_Time;
	*E_Area_Under_Q += (*E_Num_In_Queue) * (*Time_since_Last_Event);

	*Time_since_Last_N2_Event = *Sim_Time - *Last_Event_N2_Time;
	*Last_Event_N2_Time = *Sim_Time;
	*E2_Area_Under_Q += (*E2_Num_In_Queue) * (*Time_since_Last_N2_Event);

	if (*N2_Server_Status == Idle)
	{
		if (*N2_Num_In_Queue != 0)
		{
			if (N2_Arrival_Type[1] == 1)
			{
				if (*E2_Num_In_Queue >= 0)
				{

					(*N2_Num_Custs_Delayed)++;
					*N2_Server_Status = Busy;


					*N2_qDelay = *Sim_Time - N2_Time_Arrival[1];
					*N2_Total_qDelay += *N2_qDelay;

					*N2_next_dept_time = *Sim_Time + expon(*N2C1_mean_service_time);


					E2_Time_Arrival[0] = *Sim_Time;

					for (int i = 0; i <= *N2_Num_In_Queue; i++)
			{
				if(i == *N2_Num_In_Queue)
				{
				N2_Time_Arrival[i] = 0;
				N2_Arrival_Type[i] = 0;
				N2_Sys_Time_Arrival[i] =0;
				}

				else
				{
				N2_Time_Arrival[i] = N2_Time_Arrival[i + 1];
				N2_Arrival_Type[i] = N2_Arrival_Type[i + 1];
				N2_Sys_Time_Arrival[i] = N2_Sys_Time_Arrival[i+1];
				}


			}
					(*N2_Num_In_Queue)--;
					(*Sys_Num_In_Queue)--;

				}
				else
				{
					(*E_Num_In_Queue)++;
					(*E2_Num_In_Queue)++;
					if (*E2_Num_In_Queue > *E2_Q_limit)
					{
						(*E_Num_In_Queue)--;
						(*E2_Num_In_Queue)--;
						(*num_of_E_full)++;
						(*num_of_E2_full)++;
					}

					else
					{
						E2_Time_Arrival[*E2_Num_In_Queue] = *Sim_Time;
					}
				}
			}
			else if (N2_Arrival_Type[1] == 2)
			{

				if (*E2_Num_In_Queue >= 1)
				{

					(*N2_Num_Custs_Delayed)++;
					*N2_Server_Status = Busy;


					*N2_qDelay = *Sim_Time - N2_Time_Arrival[1];
					*N2_Total_qDelay += *N2_qDelay;

					*N2_next_dept_time = *Sim_Time + expon(*N2C2_mean_service_time);


					(*E2_Num_In_Queue)--;
					(*E_Num_In_Queue)--;

					E2_Time_Arrival[0] = *Sim_Time;

					for (int i = 0; i <= *N2_Num_In_Queue; i++)
			{
				if(i == *N2_Num_In_Queue)
				{
				N2_Time_Arrival[i] = 0;
				N2_Arrival_Type[i] = 0;
				N2_Sys_Time_Arrival[i] =0;
				}

				else
				{
				N2_Time_Arrival[i] = N2_Time_Arrival[i + 1];
				N2_Arrival_Type[i] = N2_Arrival_Type[i + 1];
				N2_Sys_Time_Arrival[i] = N2_Sys_Time_Arrival[i+1];
				}


			}
					(*N2_Num_In_Queue)--;
					(*Sys_Num_In_Queue)--;

				}
				else
				{
					(*E2_Num_In_Queue)++;
					(*E_Num_In_Queue)++;

					if (*E2_Num_In_Queue > *E2_Q_limit)
					{
						(*E2_Num_In_Queue)--;
						(*E_Num_In_Queue)--;
						(*num_of_E_full)++;
						(*num_of_E2_full)++;
					}
					else
					{
						E2_Time_Arrival[*E2_Num_In_Queue] = *Sim_Time;
					}
				}
			}
		}
		else
		{
			(*E2_Num_In_Queue)++;
			(*E_Num_In_Queue)++;

			if (*E2_Num_In_Queue > *E2_Q_limit)
			{
				(*E2_Num_In_Queue)--;
				(*E_Num_In_Queue)--;
				(*num_of_E_full)++;
				(*num_of_E2_full)++;
			}
			else
			{
				E2_Time_Arrival[*E2_Num_In_Queue] = *Sim_Time;
			}
		}
	}
	else
	{
		(*E2_Num_In_Queue)++;
		(*E_Num_In_Queue)++;

		if (*E2_Num_In_Queue > *E2_Q_limit)
		{
			(*E2_Num_In_Queue)--;
			(*E_Num_In_Queue)--;
			(*num_of_E_full)++;
			(*num_of_E2_full)++;
		}
		else
		{
			E2_Time_Arrival[*E2_Num_In_Queue] = *Sim_Time;
		}
	}
}

//node3
void N3_depature(double *Sim_Time, double *N3_next_dept_time, double *Time_since_Last_Event, double *Last_Event_Time, double* Sys_Area_Under_Q, int *Sys_Num_In_Queue, double *E_Area_Under_Q, int* E_Num_In_Queue,
	double* Time_since_Last_N3_Event, double* Last_Event_N3_Time, double* E3_Area_Under_Q, int *E3_Num_In_Queue, int* N3_Num_In_Queue, int* N3_Server_Status, int *N3_Arrival_Type, double* E3_sys_delay, double*E3_Time_Arrival,
	double *N3_sys_delay, double* N3_Time_Arrival, double *N3_total_sys_delay, double* E3_total_sys_delay, double* E_total_sys_delay, double*N3_Area_Under_Q, double*Sys_sys_delay, double* E3_Sys_Time_Arrival,
	double*Sys_Total_sys_delay, int*N3_Num_Custs_Delayed, int*Num_Custs_Delayed, double*N3_qDelay, double* E3_qDelay, double *N3_Total_qDelay, double *E3_Total_qDelay, double *E_Total_qDelay, double*Sys_qDelay, double*N3_Sys_Time_Arrival,
	double*Sys_Total_qDelay, float*N3C1_mean_service_time, float*N3C2_mean_service_time)
{
	*Sim_Time = *N3_next_dept_time;

	*Time_since_Last_Event = *Sim_Time - *Last_Event_Time;
	*Last_Event_Time = *Sim_Time;
	*Sys_Area_Under_Q += (*Sys_Num_In_Queue) * (*Time_since_Last_Event);
	*E_Area_Under_Q += (*E_Num_In_Queue) * (*Time_since_Last_Event);

	*Time_since_Last_N3_Event = *Sim_Time - *Last_Event_N3_Time;
	*Last_Event_N3_Time = *Sim_Time;
	*E3_Area_Under_Q += (*E3_Num_In_Queue) * (*Time_since_Last_N3_Event);

	*N3_Area_Under_Q += (*N3_Num_In_Queue) * (*Time_since_Last_N3_Event);

	if (*N3_Num_In_Queue == 0) {
		*N3_Server_Status = Idle;
		*N3_next_dept_time = pow(10, 30);



		if (N3_Arrival_Type[0] == 1)
		{

			*E3_sys_delay = *Sim_Time - E3_Time_Arrival[0];
			*N3_sys_delay = *Sim_Time - N3_Time_Arrival[0];

			*N3_total_sys_delay += *N3_sys_delay;
			*E3_total_sys_delay += *E3_sys_delay;
			*E_total_sys_delay += *E3_sys_delay;

			*Sys_sys_delay = *Sim_Time - N3_Sys_Time_Arrival[0];
			*Sys_Total_sys_delay += *Sys_sys_delay;

		}

		else if (N3_Arrival_Type[0] == 2)
		{

			*E3_sys_delay = *Sim_Time - E3_Time_Arrival[0];
			*N3_sys_delay = *Sim_Time - N3_Time_Arrival[0];

			*N3_total_sys_delay += *N3_sys_delay;
			*E3_total_sys_delay += *E3_sys_delay;
			*E_total_sys_delay += *E3_sys_delay;


			*Sys_sys_delay = *Sim_Time - N3_Sys_Time_Arrival[0];
			*Sys_Total_sys_delay += *Sys_sys_delay;
		}
	}
	else if (N3_Arrival_Type[1] == 1)
	{

		if (*E3_Num_In_Queue >= 1)
		{
			(*N3_Num_Custs_Delayed)++;
			(*Num_Custs_Delayed)++;


			*N3_qDelay = *Sim_Time - N3_Time_Arrival[1];
			*N3_sys_delay = *Sim_Time - N3_Time_Arrival[0];

			*E3_qDelay = *Sim_Time - E3_Time_Arrival[1];
			*E3_sys_delay = *Sim_Time - E3_Time_Arrival[0];



			*N3_Total_qDelay += *N3_qDelay;
			*N3_total_sys_delay += *N3_sys_delay;
			*E3_Total_qDelay += *E3_qDelay;
			*E3_total_sys_delay += *E3_sys_delay;

			*E_Total_qDelay += *E3_qDelay;
			*E_total_sys_delay += *E3_sys_delay;

			*Sys_qDelay = *Sim_Time - N3_Sys_Time_Arrival[1];
			*Sys_Total_qDelay += *Sys_qDelay;


			*Sys_sys_delay = *Sim_Time - N3_Sys_Time_Arrival[0];
			*Sys_Total_sys_delay += *Sys_sys_delay;



			for (int i = 0; i <= *N3_Num_In_Queue; i++)
			{
				if(i == *N3_Num_In_Queue)
				{
				N3_Time_Arrival[i] = 0;
				N3_Arrival_Type[i] = 0;
					N3_Sys_Time_Arrival[i] =0;
				}
				else
				{
				N3_Time_Arrival[i] = N3_Time_Arrival[i + 1];
				N3_Arrival_Type[i] = N3_Arrival_Type[i + 1];
				N3_Sys_Time_Arrival[i] = N3_Sys_Time_Arrival[i+1];
				}

			}

			for (int i = 0; i <= *E3_Num_In_Queue; i++)
			{
				if(i == *E3_Num_In_Queue)
				{
				E3_Time_Arrival[i] = 0;
				}
				else
				{
				E3_Time_Arrival[i] = E3_Time_Arrival[i + 1];
				}
			}
			(*N3_Num_In_Queue)--;
			(*E3_Num_In_Queue)--;
			(*E_Num_In_Queue)--;
			(*Sys_Num_In_Queue)--;

			*N3_next_dept_time = *Sim_Time + expon(*N3C1_mean_service_time);

		}
		else
		{
			*N3_Server_Status = Idle;
			*N3_next_dept_time = pow(10, 30);



			if (N3_Arrival_Type[0] == 1)
			{

				*E3_sys_delay = *Sim_Time - E3_Time_Arrival[0];
				*N3_sys_delay = *Sim_Time - N3_Time_Arrival[0];

				*N3_total_sys_delay += *N3_sys_delay;
				*E3_total_sys_delay += *E3_sys_delay;
				*E_total_sys_delay += *E3_sys_delay;



				*Sys_sys_delay = *Sim_Time - N3_Sys_Time_Arrival[0];
				*Sys_Total_sys_delay += *Sys_sys_delay;

			}

			else if (N3_Arrival_Type[0] == 2)
			{

				*E3_sys_delay = *Sim_Time - E3_Time_Arrival[0];
				*N3_sys_delay = *Sim_Time - N3_Time_Arrival[0];

				*N3_total_sys_delay += *N3_sys_delay;
				*E3_total_sys_delay += *E3_sys_delay;
				*E_total_sys_delay += *E3_sys_delay;



				*Sys_sys_delay = *Sim_Time - N3_Sys_Time_Arrival[0];
				*Sys_Total_sys_delay += *Sys_sys_delay;
			}
		}

	}
	else if (N3_Arrival_Type[1] == 2)
	{
		if (*E3_Num_In_Queue >= 2)
		{
			(*N3_Num_Custs_Delayed)++;
			(*Num_Custs_Delayed)++;


			*N3_qDelay = *Sim_Time - N3_Time_Arrival[1];
			*N3_sys_delay = *Sim_Time - N3_Time_Arrival[0];
			*E3_qDelay = *Sim_Time - E3_Time_Arrival[1];
			*E3_sys_delay = *Sim_Time - E3_Time_Arrival[0];


			*N3_Total_qDelay += *N3_qDelay;
			*N3_total_sys_delay += *N3_sys_delay;
			*E3_Total_qDelay += *E3_qDelay;
			*E3_total_sys_delay += *E3_sys_delay;

			*E_Total_qDelay += *E3_qDelay;
			*E_total_sys_delay += *E3_sys_delay;

			*Sys_qDelay = *Sim_Time - N3_Sys_Time_Arrival[1];
			*Sys_Total_qDelay += *Sys_qDelay;


			*Sys_sys_delay = *Sim_Time - N3_Sys_Time_Arrival[0];
			*Sys_Total_sys_delay += *Sys_sys_delay;

			for (int i = 0; i <= *N3_Num_In_Queue; i++)
			{
				if(i == *N3_Num_In_Queue)
				{
				N3_Time_Arrival[i] = 0;
				N3_Arrival_Type[i] = 0;
				N3_Sys_Time_Arrival[i] = 0;
				}
				else
				{
				N3_Time_Arrival[i] = N3_Time_Arrival[i + 1];
				N3_Arrival_Type[i] = N3_Arrival_Type[i + 1];
				N3_Sys_Time_Arrival[i] = N3_Sys_Time_Arrival[i+1];
				}

			}

			for (int i = 0; i <= *E3_Num_In_Queue; i++)
			{
				if(i == *E3_Num_In_Queue-1||i == *E3_Num_In_Queue)
				{
				E3_Time_Arrival[i] = 0;
				}
				else
				{
				E3_Time_Arrival[i] = E3_Time_Arrival[i + 2];
				}
			}

			(*N3_Num_In_Queue)--;
			(*E_Num_In_Queue)--;
			(*E_Num_In_Queue)--;
			(*E3_Num_In_Queue)--;
			(*E3_Num_In_Queue)--;
			(*Sys_Num_In_Queue)--;
			*N3_next_dept_time = *Sim_Time + expon(*N3C2_mean_service_time);

		}
		else
		{
			*N3_Server_Status = Idle;
			*N3_next_dept_time = pow(10, 30);



			if (N3_Arrival_Type[0] == 1)
			{

				*E3_sys_delay = *Sim_Time - E3_Time_Arrival[0];
				*N3_sys_delay = *Sim_Time - N3_Time_Arrival[0];

				*N3_total_sys_delay += *N3_sys_delay;
				*E3_total_sys_delay += *E3_sys_delay;
				*E_total_sys_delay += *E3_sys_delay;



				*Sys_sys_delay = *Sim_Time - N3_Sys_Time_Arrival[0];
				*Sys_Total_sys_delay += *Sys_sys_delay;

			}

			else if (N3_Arrival_Type[0] == 2)
			{

				*E3_sys_delay = *Sim_Time - E3_Time_Arrival[0];
				*N3_sys_delay = *Sim_Time - N3_Time_Arrival[0];

				*N3_total_sys_delay += *N3_sys_delay;
				*E3_total_sys_delay += *E3_sys_delay;
				*E_total_sys_delay += *E3_sys_delay;



				*Sys_sys_delay = *Sim_Time - N3_Sys_Time_Arrival[0];
				*Sys_Total_sys_delay += *Sys_sys_delay;
			}
		}
	}

}

void N3C1_arrival(double *Sim_Time, double* Time_since_Last_N3_Event, double *Last_Event_N3_Time,
	double *Sys_Area_Under_Q, int *Sys_Num_In_Queue, double *N3_Area_Under_Q, int *N3_Num_In_Queue, int *N3_Server_Status, int *N3_Num_Custs_Delayed, double *E3_qDelay, double* E3_Time_Arrival, double *E3_Total_qDelay, double *E_Total_qDelay,
	int *E_Num_In_Queue, int* E3_Num_In_Queue, int* N3_Q_limit, double* num_of_Sys_full, double *num_of_N3_full, float *N3C1_mean_service_time, int *temp_type, double *temp_time, int * N3_Arrival_Type, double *N3_Time_Arrival, double*N3_next_dept_time,
	double*N3_Sys_Time_Arrival, int*Num_Custs_Delayed,double*num_of_N3_arr, double *num_of_Sys_arr, double *Sys_qDelay, double *Sys_Total_qDelay)
{
	(*num_of_N3_arr)++;
	*Time_since_Last_N3_Event = *Sim_Time - *Last_Event_N3_Time;
	*Last_Event_N3_Time = *Sim_Time;

	*N3_Area_Under_Q += (*N3_Num_In_Queue) * (*Time_since_Last_N3_Event);

	if (*N3_Server_Status == Idle)
	{
		if (*E3_Num_In_Queue >= 1 && *N3_Num_In_Queue == 0)
		{
			(*N3_Num_Custs_Delayed)++;
			(*Num_Custs_Delayed)++;
			*N3_Server_Status = Busy;

			*E3_qDelay = *Sim_Time - E3_Time_Arrival[1];
			*E3_Total_qDelay += *E3_qDelay;
			*E_Total_qDelay += *E3_qDelay;

			*Sys_qDelay = *Sim_Time - *temp_time;
			*Sys_Total_qDelay += *Sys_qDelay;

			*N3_next_dept_time = *Sim_Time + expon(*N3C1_mean_service_time);

			N3_Sys_Time_Arrival[0] = *temp_time;
			N3_Time_Arrival[0] = *Sim_Time;
			N3_Arrival_Type[0] = *temp_type;


		for (int i = 0; i <= *E3_Num_In_Queue; i++)
			{
				if(i == *E3_Num_In_Queue)
				{
				E3_Time_Arrival[i] = 0;
				}
				else
				{
				E3_Time_Arrival[i] = E3_Time_Arrival[i + 1];
				}
			}
			(*E_Num_In_Queue)--;
			(*E3_Num_In_Queue)--;
			(*Sys_Num_In_Queue)--;
			(*N3_Num_In_Queue)--;

		}
		else
		{

			if (*N3_Num_In_Queue > *N3_Q_limit)
			{
				(*Sys_Num_In_Queue)--;
				(*N3_Num_In_Queue)--;
				(*num_of_Sys_full)++;
				(*num_of_N3_full)++;
			}

			else
			{
				N3_Sys_Time_Arrival[*N3_Num_In_Queue] = *temp_time;
				N3_Time_Arrival[*N3_Num_In_Queue] = *Sim_Time;
				N3_Arrival_Type[*N3_Num_In_Queue] = *temp_type;

			}
		}
	}
	else
	{

		if (*N3_Num_In_Queue > *N3_Q_limit)
		{
			(*Sys_Num_In_Queue)--;
			(*N3_Num_In_Queue)--;
			(*num_of_Sys_full)++;
			(*num_of_N3_full)++;
		}

		else
		{
			N3_Sys_Time_Arrival[*N3_Num_In_Queue] = *temp_time;
			N3_Time_Arrival[*N3_Num_In_Queue] = *Sim_Time;
			N3_Arrival_Type[*N3_Num_In_Queue] = *temp_type;

		}
	}




}

void N3C2_arrival(double *Sim_Time, double* Time_since_Last_N3_Event, double *Last_Event_N3_Time,
	double *Sys_Area_Under_Q, int *Sys_Num_In_Queue, double *N3_Area_Under_Q, int *N3_Num_In_Queue, int *N3_Server_Status, int* N3_Num_Custs_Delayed, double *E3_qDelay, double* E3_Time_Arrival, double *E3_Total_qDelay, double *E_Total_qDelay,
	int *E_Num_In_Queue, int* E3_Num_In_Queue, int* N3_Q_limit, double* num_of_Sys_full, double *num_of_N3_full, float *N3C2_mean_service_time, int *temp_type, double *temp_time, int * N3_Arrival_Type, double *N3_Time_Arrival,
	double*N3_next_dept_time, double*N3_Sys_Time_Arrival, int*Num_Custs_Delayed,double*num_of_N3_arr, double *num_of_Sys_arr, double *Sys_qDelay, double *Sys_Total_qDelay )
{
	(*num_of_N3_arr)++;
	*Time_since_Last_N3_Event = *Sim_Time - *Last_Event_N3_Time;
	*Last_Event_N3_Time = *Sim_Time;

	*N3_Area_Under_Q += (*N3_Num_In_Queue) * (*Time_since_Last_N3_Event);


	if (*N3_Server_Status == Idle)
	{
		if (*E3_Num_In_Queue >= 2)
		{
			(*N3_Num_Custs_Delayed)++;
			(*Num_Custs_Delayed)++;
			*N3_Server_Status = Busy;

			*E3_qDelay = *Sim_Time - E3_Time_Arrival[1];
			*E3_Total_qDelay += *E3_qDelay;
			*E_Total_qDelay += *E3_qDelay;

			*Sys_qDelay = *Sim_Time - *temp_time;
			*Sys_Total_qDelay += *Sys_qDelay;


			*N3_next_dept_time = *Sim_Time + expon(*N3C2_mean_service_time);



			N3_Sys_Time_Arrival[0] = *temp_time;
			N3_Time_Arrival[0] = *Sim_Time;
			N3_Arrival_Type[0] = *temp_type;



			for (int i = 0; i <= *E3_Num_In_Queue; i++)
			{
				if(i == *E3_Num_In_Queue-1||i == *E3_Num_In_Queue)
				{
				E3_Time_Arrival[i] = 0;
				}
				else
				{
				E3_Time_Arrival[i] = E3_Time_Arrival[i + 2];
				}
			}
			(*E_Num_In_Queue)--;
			(*E_Num_In_Queue)--;
			(*E3_Num_In_Queue)--;
			(*E3_Num_In_Queue)--;
			(*Sys_Num_In_Queue)--;
			(*N3_Num_In_Queue)--;

		}
		else
		{

			if (*N3_Num_In_Queue > *N3_Q_limit)
			{
				(*Sys_Num_In_Queue)--;
				(*N3_Num_In_Queue)--;
				(*num_of_Sys_full)++;
				(*num_of_N3_full)++;
			}

			else
			{
				N3_Sys_Time_Arrival[*N3_Num_In_Queue] = *temp_time;
				N3_Time_Arrival[*N3_Num_In_Queue] = *Sim_Time;
				N3_Arrival_Type[*N3_Num_In_Queue] = *temp_type;

			}
		}
	}
	else
	{

		if (*N3_Num_In_Queue > *N3_Q_limit)
		{
			(*Sys_Num_In_Queue)--;
			(*N3_Num_In_Queue)--;
			(*num_of_Sys_full)++;
			(*num_of_N3_full)++;
		}

		else
		{
			N3_Sys_Time_Arrival[*N3_Num_In_Queue] = *temp_time;
			N3_Time_Arrival[*N3_Num_In_Queue] = *Sim_Time;
			N3_Arrival_Type[*N3_Num_In_Queue] = *temp_type;

		}
	}




}

void E3_arrival(double *Sim_Time, double *E3_next_arr_time, float *E3_mean_interarrival_time, double *Time_since_Last_Event, double *Last_Event_Time,
	double *E_Area_Under_Q, int *E_Num_In_Queue, double *Time_since_Last_N3_Event, double *Last_Event_N3_Time, double *E3_Area_Under_Q, int *E3_Num_In_Queue,
	int *N3_Server_Status, int *N3_Num_In_Queue, int* N3_Arrival_Type, double * N3_next_dept_time, double*N3_Time_Arrival, float * N3C1_mean_service_time, float * N3C2_mean_service_time,
	double *num_of_E_full, double *num_of_E3_full, double *N3_qDelay, double *N3_Total_qDelay, int *E3_Q_limit, int*N3_Num_Custs_Delayed, double *Sys_qDelay, double*N3_Sys_Time_Arrival, double*Sys_Total_qDelay,
	int*Sys_Num_In_Queue, double* E3_Time_Arrival,int*Num_Custs_Delayed)
{

	*Sim_Time = *E3_next_arr_time;
	*E3_next_arr_time = *Sim_Time + expon(*E3_mean_interarrival_time);

	*Time_since_Last_Event = *Sim_Time - *Last_Event_Time;
	*Last_Event_Time = *Sim_Time;
	*E_Area_Under_Q += (*E_Num_In_Queue) * (*Time_since_Last_Event);

	*Time_since_Last_N3_Event = *Sim_Time - *Last_Event_N3_Time;
	*Last_Event_N3_Time = *Sim_Time;
	*E3_Area_Under_Q += (*E3_Num_In_Queue) * (*Time_since_Last_N3_Event);

	if (*N3_Server_Status == Idle)
	{
		if (*N3_Num_In_Queue != 0)
		{
			if (N3_Arrival_Type[1] == 1)
			{
				if (*E3_Num_In_Queue >= 0)
				{

					(*N3_Num_Custs_Delayed)++;
					(*Num_Custs_Delayed)++;
					*N3_Server_Status = Busy;


					*N3_qDelay = *Sim_Time - N3_Time_Arrival[1];
					*N3_Total_qDelay += *N3_qDelay;
					*Sys_qDelay = *Sim_Time - N3_Sys_Time_Arrival[1];
					*Sys_Total_qDelay += *Sys_qDelay;

					*N3_next_dept_time = *Sim_Time + expon(*N3C1_mean_service_time);


					E3_Time_Arrival[0] = *Sim_Time;

					for (int i = 0; i <= *N3_Num_In_Queue; i++)
			{
				if(i == *N3_Num_In_Queue)
				{
				N3_Time_Arrival[i] = 0;
				N3_Arrival_Type[i] = 0;
				N3_Sys_Time_Arrival[i] =0;
				}
				else
				{
				N3_Time_Arrival[i] = N3_Time_Arrival[i + 1];
				N3_Arrival_Type[i] = N3_Arrival_Type[i + 1];
				N3_Sys_Time_Arrival[i] = N3_Sys_Time_Arrival[i+1];
				}

			}
					(*N3_Num_In_Queue)--;
					(*Sys_Num_In_Queue)--;
				}
				else
				{
					(*E_Num_In_Queue)++;
					(*E3_Num_In_Queue)++;
					if (*E3_Num_In_Queue > *E3_Q_limit)
					{
						(*E_Num_In_Queue)--;
						(*E3_Num_In_Queue)--;
						(*num_of_E_full)++;
						(*num_of_E3_full)++;
					}

					else
					{
						E3_Time_Arrival[*E3_Num_In_Queue] = *Sim_Time;
					}
				}
			}
			else if (N3_Arrival_Type[1] == 2)
			{

				if (*E3_Num_In_Queue >= 1)
				{

					(*N3_Num_Custs_Delayed)++;
					(*Num_Custs_Delayed)++;
					*N3_Server_Status = Busy;


					*N3_qDelay = *Sim_Time - N3_Time_Arrival[1];
					*N3_Total_qDelay += *N3_qDelay;
					*Sys_qDelay = *Sim_Time - N3_Sys_Time_Arrival[1];
					*Sys_Total_qDelay += *Sys_qDelay;

					*N3_next_dept_time = *Sim_Time + expon(*N3C2_mean_service_time);

					(*E3_Num_In_Queue)--;
					(*E_Num_In_Queue)--;

					E3_Time_Arrival[0] = *Sim_Time;

					for (int i = 0; i <= *N3_Num_In_Queue; i++)
			{
				if(i == *N3_Num_In_Queue)
				{
				N3_Time_Arrival[i] = 0;
				N3_Arrival_Type[i] = 0;

				}
				else
				{
				N3_Time_Arrival[i] = N3_Time_Arrival[i + 1];
				N3_Arrival_Type[i] = N3_Arrival_Type[i + 1];
				}

			}
					(*N3_Num_In_Queue)--;
					(*Sys_Num_In_Queue)--;
				}
				else
				{
					(*E_Num_In_Queue)++;
					(*E3_Num_In_Queue)++;
					if (*E3_Num_In_Queue > *E3_Q_limit)
					{
						(*E_Num_In_Queue)--;
						(*E3_Num_In_Queue)--;
						(*num_of_E_full)++;
						(*num_of_E3_full)++;
					}

					else
					{
						E3_Time_Arrival[*E3_Num_In_Queue] = *Sim_Time;
					}
				}
			}
		}
		else
		{
			(*E_Num_In_Queue)++;
			(*E3_Num_In_Queue)++;
			if (*E3_Num_In_Queue > *E3_Q_limit)
			{
				(*E_Num_In_Queue)--;
				(*E3_Num_In_Queue)--;
				(*num_of_E_full)++;
				(*num_of_E3_full)++;
			}

			else
			{
				E3_Time_Arrival[*E3_Num_In_Queue] = *Sim_Time;
			}
		}
	}
	else
	{
		(*E_Num_In_Queue)++;
		(*E3_Num_In_Queue)++;
		if (*E3_Num_In_Queue > *E3_Q_limit)
		{
			(*E_Num_In_Queue)--;
			(*E3_Num_In_Queue)--;
			(*num_of_E_full)++;
			(*num_of_E3_full)++;
		}

		else
		{
			E3_Time_Arrival[*E3_Num_In_Queue] = *Sim_Time;
		}
	}
}






//other

float expon(float mean) {
	return -mean * log(lcgrand(1));
}


double minimum(double *N1_next_dept_time, double *N2_next_dept_time, double *N3_next_dept_time, double  *N1C1_next_arr_time, double  *N1C2_next_arr_time, double *E1_next_arr_time, double *E2_next_arr_time, double *E3_next_arr_time) {
	double min;
	min = *N1_next_dept_time;
	if (min > *N2_next_dept_time)
	{
		min = *N2_next_dept_time;
	}
    if (min > *N3_next_dept_time)
	{
		min = *N3_next_dept_time;
	}
    if (min > *N1C1_next_arr_time)
	{
		min = *N1C1_next_arr_time;
	}
    if (min > *N1C2_next_arr_time)
	{
		min = *N1C2_next_arr_time;
	}
    if (min > *E1_next_arr_time) {
		min = *E1_next_arr_time;
	}
	if (min > *E2_next_arr_time) {
		min = *E2_next_arr_time;
	}
	if (min > *E3_next_arr_time) {
		min = *E3_next_arr_time;
	}





	return min;

}



