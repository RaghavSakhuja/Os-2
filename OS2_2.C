#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <pthread.h>

#define ll long long
#define p(a) printf("%s\n",a)
#define pd(a) printf("%f\n",a)
#define fr(i,n) for(int i=0;i<n;i++)


struct timespec start2;
struct timespec end2;
struct timespec start3;
struct timespec end3;
struct sched_param parameter1;
struct sched_param parameter2;
struct sched_param parameter3;

int main(){
    double tother=0,trr=0,tfifo=0;
    int n=6;
    int pow=16;
    
    fr(i,n)
    {

        int rc=fork();
        if(rc<0){
            
        }
        else if(rc==0){
                struct timespec start1;
                struct timespec end1;

                clock_gettime(CLOCK_REALTIME,&start1);
                // ll maxx=((long long)1)<<pow;
                ll maxx=2<<pow;
                ll i=0;
                for(i=0;i<maxx;i++){
                    //do nothing;
                }
                // pd(i);
                clock_gettime(CLOCK_REALTIME,&end1);
                freopen("fork1.txt","a",stdout);

                double time1=(end1.tv_sec - start1.tv_sec) + (end1.tv_nsec - start1.tv_nsec) / 1000000000.0;
                pd(time1);

                exit(1);

        }
        else{
            int rc2=fork();
            if(rc2<0){

            }
            else if(rc2==0){
                struct timespec start2;
                struct timespec end2;

                clock_gettime(CLOCK_REALTIME,&start2);
                // ll maxx=((ll)1)<<pow;
                ll maxx=2<<pow;
                ll i=0;
                for(i=0;i<maxx;i++){
                    //do nothing;
                }
                // pd(i);
                clock_gettime(CLOCK_REALTIME,&end2);
                freopen("fork2.txt","a",stdout);

                double time2=(end2.tv_sec - start2.tv_sec) + (end2.tv_nsec - start2.tv_nsec) / 1000000000.0;
                pd(time2);

                exit(1);

            }
            else{
                int rc3=fork();
                if(rc3<0){

                }
                else if(rc3==0){
                    struct timespec start3;
                    struct timespec end3;

                    clock_gettime(CLOCK_REALTIME,&start3);
                    // ll maxx=((ll)1)<<pow;
                    ll maxx=2<<pow;
                    ll i=0;
                    for(i=0;i<maxx;i++){
                        //do nothing;
                    }
                    // pd(i);
                    clock_gettime(CLOCK_REALTIME,&end3);
                    freopen("fork3.txt","a",stdout);

                    double time3=(end3.tv_sec - start3.tv_sec) + (end3.tv_nsec - start3.tv_nsec) / 1000000000.0;
                    pd(time3);
                    exit(1);


                }
                else{
                }
            }
            
            waitpid(rc,)
        }
    }

    
    // p("finals");
    // pd(tother/n);
    // pd(trr/n);
    // pd(tfifo/n);


    return 0;
}