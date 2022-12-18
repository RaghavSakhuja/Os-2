#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <sched.h>


#define ll long long
#define p(a) printf("%s----------\n",a)
#define pd(a) printf("%f------------\n",a)
#define fr(i,n) for(int i=0;i<n;i++)

struct timespec start3;
struct timespec end3;
struct timespec start2;
struct timespec end2;
struct timespec start1;
struct timespec end1;
struct sched_param parameter1;
struct sched_param parameter2;
struct sched_param parameter3;
int n=1;
int prio_oth[]={0,20,2,3,4,5};
int prio_rr[]={1,99,70,50,30,10};
int prio_fifo[]={1,20,30,40,60,80};


void run1(){
            execvp("./ex1.sh",NULL);
}

void run2(){
            execvp("./ex2.sh",NULL);
}

void run3(){
            execvp("./ex3.sh",NULL);
}
void run(){
            execvp("./check",NULL);

}
int main(int argc, char* argv[]){
    int i=atoi(argv[1]);
    printf("\n\n%d\n\n",i);
        int rc1,rc2,rc3;
        rc1=fork();
        clock_gettime(CLOCK_REALTIME,&start1);
        if(rc1==0){
            parameter1.sched_priority=0;
            sched_setscheduler(0,SCHED_OTHER,&parameter1);
            perror("other: ");
            int ret=nice(prio_oth[i]);
            perror("nice: ");
            run1();
        }
        else if(rc1<0){

        }
        else{
            rc2=fork();
            clock_gettime(CLOCK_REALTIME,&start2);
            if(rc2==0){
                parameter2.sched_priority=prio_rr[i];
                sched_setscheduler(0,SCHED_RR,&parameter2);
                perror("rr: ");

                run2();
            }
            else{
                rc3=fork();
                clock_gettime(CLOCK_REALTIME,&start3);
                if(rc3==0){
                    parameter3.sched_priority=prio_fifo[i];
                    sched_setscheduler(0,SCHED_FIFO,&parameter3);
                    perror("fifo: ");

                    run3();
                }
                else{
                }
                
            }
        }
        pid_t a=waitpid(-1,NULL,0);
        if(a==rc1){
            p("ended1");
            clock_gettime(CLOCK_REALTIME,&end1);
        }
        else if(a==rc2){
            p("ended2");
            clock_gettime(CLOCK_REALTIME,&end2);
        }
        else if(a==rc3){
            p("ended3");
            clock_gettime(CLOCK_REALTIME,&end3);
        }
        pid_t b=waitpid(-1,NULL,0);
        if(b==rc1){
            p("ended1");
            clock_gettime(CLOCK_REALTIME,&end1);
        }
        else if(b==rc2){
            p("ended2");
            clock_gettime(CLOCK_REALTIME,&end2);
        }
        else if(b==rc3){
            p("ended3");
            clock_gettime(CLOCK_REALTIME,&end3);
        }
        pid_t c=waitpid(-1,NULL,0);
        if(c==rc1){
            p("ended1");
            clock_gettime(CLOCK_REALTIME,&end1);
        }
        else if(c==rc2){
            p("ended2");
            clock_gettime(CLOCK_REALTIME,&end2);
        }
        else if(c==rc3){
            p("ended3");
            clock_gettime(CLOCK_REALTIME,&end3);
        }

        FILE* demo;

        demo = fopen("fork1.txt", "a");
        double time1=(end1.tv_sec - start1.tv_sec) + (end1.tv_nsec - start1.tv_nsec) / 1000000000.0;
        fprintf(demo,"%d %f\n",prio_oth[i],time1);
        fclose(demo);
        pd(time1);

        demo = fopen("fork2.txt", "a");
        double time2=(end2.tv_sec - start2.tv_sec) + (end2.tv_nsec - start2.tv_nsec) / 1000000000.0;
        fprintf(demo,"%d %f\n",prio_rr[i],time2);
        fclose(demo);
        pd(time2);

        demo = fopen("fork3.txt", "a");
        double time3=(end3.tv_sec - start3.tv_sec) + (end3.tv_nsec - start3.tv_nsec) / 1000000000.0;
        fprintf(demo,"%d %f\n",prio_fifo[i],time3);
        fclose(demo);
        pd(time3);
        pd(i);
        
}