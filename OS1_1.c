#include <stdio.h>
#include <stdlib.h>
// #include <sys/types.h>
// #include <sys/wait.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

#define ll long long
#define p(a) printf("%s\n",a)
#define pd(a) printf("%f\n",a)
#define fr(i,n) for(int i=0;i<n;i++)

struct timespec start1;
struct timespec end1;
struct timespec start2;
struct timespec end2;
struct timespec start3;
struct timespec end3;
struct sched_param parameter1;
struct sched_param parameter2;
struct sched_param parameter3;
pthread_t p;
pthread_t q;
pthread_t r;
int n=10;
int prio_oth[]={-1000,1000,2,3,4,5,6,7,9,10};
int prio_rr[]={99,70,50,30,10,1,10,20,30,50};
int prio_fifo[]={1,20,30,40,60,80,10,20,30,50};
int l=0,m=0,k=0;
void countA(){
    parameter1.sched_priority=0;
    int t=pthread_setschedparam(p,SCHED_OTHER,&parameter1);
    perror("other: ");
    int ret=nice(prio_oth[l]);
    perror("nice: ");
    printf("%d\n",ret);
    clock_gettime(CLOCK_REALTIME,&start1);
    ll maxx=4294967296;
    for(ll i=0;i<maxx;i++){
        //do nothing;
    }
    clock_gettime(CLOCK_REALTIME,&end1);
    l++;

}
void countB(){    
    parameter2.sched_priority=prio_rr[m];
    m++;
    int t=pthread_setschedparam(q,SCHED_RR,&parameter2);
    perror("rr: ");

    // pd(t);
    clock_gettime(CLOCK_REALTIME,&start2);
    ll maxx=4294967296;
    for(ll i=0;i<maxx;i++){
        //do nothing;
    }
    clock_gettime(CLOCK_REALTIME,&end2);
}

void countC(){
    parameter3.sched_priority=prio_fifo[k];
    k++;
    int t=pthread_setschedparam(r,SCHED_FIFO,&parameter3);
    perror("fifo: ");

    // pd(t);
    clock_gettime(CLOCK_REALTIME,&start3);
    ll maxx=4294967296;
    for(ll i=0;i<maxx;i++){
        //do nothing;
    }
    clock_gettime(CLOCK_REALTIME,&end3);
}

int main(){
    double tother=0,trr=0,tfifo=0;
    fr(i,n)
    {    int a=pthread_create(&p,NULL,(void*)countA,NULL);
        if(a!=0){
            p("Unable to create the thread-A");
            return 1;
        }

        int b=pthread_create(&q,NULL,(void*)countB,NULL);
        if(b!=0){
            p("Unable to create the thread-B");
            return 1;
        }

        int c=pthread_create(&r,NULL,(void*)countC,NULL);
        if(c!=0){
            p("Unable to create the thread-C");
            return 1;
        }

        int a1=pthread_join(p,NULL);
        if(a1!=0){
            p("Unable to exit the thread-A");
            exit(1);
        }
        int b1=pthread_join(q,NULL);

        if(b1!=0){
            p("Unable to exit the thread-B");
            exit(1);
        }
        int c1=pthread_join(r,NULL);

        if(c1!=0){
            p("Unable to exit the thread-C");
            exit(1);
        }

        FILE* demo;

        demo = fopen("OTHER.txt", "a");
        double time1=(end1.tv_sec - start1.tv_sec) + (end1.tv_nsec - start1.tv_nsec) / 1000000000.0;
        fprintf(demo,"%d %f\n",prio_oth[l-1],time1);
        fclose(demo);

        demo = fopen("RR.txt", "a");
        double time2=(end2.tv_sec - start2.tv_sec) + (end2.tv_nsec - start2.tv_nsec) / 1000000000.0;
        fprintf(demo,"%d %f\n",prio_rr[m-1],time2);
        fclose(demo);

        demo = fopen("FIFO.txt", "a");
        double time3=(end3.tv_sec - start3.tv_sec) + (end3.tv_nsec - start3.tv_nsec) / 1000000000.0;
        fprintf(demo,"%d %f\n",prio_fifo[k-1],time3);
        fclose(demo);

        pd(time1);
        pd(time2);
        pd(time3);
        p("");

        }
    


    return 0;
}
