#include <stdio.h>
#include <stdlib.h>
// #include <sys/types.h>
// #include <sys/wait.h>
#include <time.h>
#include <pthread.h>

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

    // pthread_param=(&p,SCHED_VALUE,)


void countA(){
    // parameter1.sched_priority=1;
    int t=pthread_setschedparam(p,SCHED_OTHER,NULL);
    // pd(t);
    clock_gettime(CLOCK_REALTIME,&start1);
    ll maxx=4294967296;
    for(ll i=0;i<maxx;i++){
        //do nothing;
    }
    clock_gettime(CLOCK_REALTIME,&end1);

}
void countB(){    
    parameter2.sched_priority=20;
    int t=pthread_setschedparam(q,SCHED_RR,NULL);
    // pd(t);
    clock_gettime(CLOCK_REALTIME,&start2);
    ll maxx=4294967296;
    for(ll i=0;i<maxx;i++){
        //do nothing;
    }
    clock_gettime(CLOCK_REALTIME,&end2);

}
void countC(){
    int t=pthread_setschedparam(r,SCHED_FIFO,NULL);
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
    int n=3;
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
        // p("starts");

        // pd(start1.tv_sec+start1.tv_nsec/1000000000.0);
        // pd(start2.tv_sec+start2.tv_nsec/1000000000.0);
        // pd(start3.tv_sec+start3.tv_nsec/1000000000.0);

        // p("ends");

        // pd(end1.tv_sec+end1.tv_nsec/1000000000.0);
        // pd(end2.tv_sec+end2.tv_nsec/1000000000.0);
        // pd(end3.tv_sec+end3.tv_nsec/1000000000.0);

        p("Vals");
        double time1=(end1.tv_sec - start1.tv_sec) + (end1.tv_nsec - start1.tv_nsec) / 1000000000.0;
        double time2=(end2.tv_sec - start2.tv_sec) + (end2.tv_nsec - start2.tv_nsec) / 1000000000.0;
        double time3=(end3.tv_sec - start3.tv_sec) + (end3.tv_nsec - start3.tv_nsec) / 1000000000.0;
        tother+=time1;
        trr+=time2;
        tfifo+=time3;
        pd(time1);
        pd(time2);
        pd(time3);}
    
    p("finals");
    pd(tother/n);
    pd(trr/n);
    pd(tfifo/n);


    return 0;
}
