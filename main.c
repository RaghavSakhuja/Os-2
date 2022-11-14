#include <stdio.h>
#include <stdlib.h>
// #include <sys/types.h>
// #include <sys/wait.h>
#include <time.h>
#include <pthread.h>

#define ll long long
#define p(a) printf("%s\n",a)
#define pd(a) printf("%f\n",a)


void countA(){
    ll maxx=4294967296;
    for(ll i=0;i<maxx;i++){
        //do nothing;
    }
}
void countB(){
    ll maxx=4294967296;
    for(ll i=0;i<maxx;i++){
        //do nothing;
    }
}
void countC(){
    ll maxx=4294967296;
    for(ll i=0;i<maxx;i++){
        //do nothing;
    }
}

int main(){
    struct timespec start1;
    struct timespec end1;
    struct timespec start2;
    struct timespec end2;
    struct timespec start3;
    struct timespec end3;
    pthread_t p;
    clock_gettime(CLOCK_REALTIME,&start1);
    int a=pthread_create(&p,NULL,(void*)countA,NULL);
    if(a!=0){
        p("Unable to create the thread-A");
        return 1;
    }

    pthread_t q;
    clock_gettime(CLOCK_REALTIME,&start2);
    int b=pthread_create(&q,NULL,(void*)countB,NULL);
    if(b!=0){
        p("Unable to create the thread-B");
        return 1;
    }

    pthread_t r;
    clock_gettime(CLOCK_REALTIME,&start3);
    int c=pthread_create(&r,NULL,(void*)countC,NULL);
    if(c!=0){
        p("Unable to create the thread-C");
        return 1;
    }

    int a1=pthread_join(p,NULL);
    clock_gettime(CLOCK_REALTIME,&end1);
    if(a1!=0){
        p("Unable to exit the thread-A");
        exit(1);
    }
    int b1=pthread_join(q,NULL);
    clock_gettime(CLOCK_REALTIME,&end2);

    if(b1!=0){
        p("Unable to exit the thread-B");
        exit(1);
    }
    int c1=pthread_join(r,NULL);
    clock_gettime(CLOCK_REALTIME,&end3);

    if(c1!=0){
        p("Unable to exit the thread-C");
        exit(1);
    }
    p("starts");

    pd(start1.tv_sec+start1.tv_nsec/1000000000.0);
    pd(start2.tv_sec+start2.tv_nsec/1000000000.0);
    pd(start3.tv_sec+start3.tv_nsec/1000000000.0);

    p("ends");

    pd(end1.tv_sec+end1.tv_nsec/1000000000.0);
    pd(end2.tv_sec+end2.tv_nsec/1000000000.0);
    pd(end3.tv_sec+end3.tv_nsec/1000000000.0);

    p("Vals");
    double time1=(end1.tv_sec - start1.tv_sec) + (end1.tv_nsec - start1.tv_nsec) / 1000000000.0;
    double time2=(end2.tv_sec - start2.tv_sec) + (end2.tv_nsec - start2.tv_nsec) / 1000000000.0;
    double time3=(end3.tv_sec - start3.tv_sec) + (end3.tv_nsec - start3.tv_nsec) / 1000000000.0;

    pd(time1);
    pd(time2);
    pd(time3);
    



    return 0;
}
