#include <stdio.h>
#include <sys/syscall.h>
#include <linux/kernel.h>
#include <unistd.h>
#include <errno.h>

#define KERNEL_2D_MEMCPY_SYSCALL 451
#define ll long long
#define p(a) printf("%s----------\n",a)
#define pd(a) printf("%f------------\n",a)
#define fr(i,n) for(int i=0;i<n;i++)

int main()
{
    float src_arr[5][5] = {{1.0, 2.0, 3.0, 4.0, 5.0},{1.0, 2.0, 3.0, 4.0, 5.0},{1.0, 2.0, 3.0, 4.0, 5.0},{1.0, 2.0, 3.0, 4.0, 5.0},{1.0, 2.0, 3.0, 4.0, 5.0}};
    float dest_arr[5][5]; 

    long sys_call_status;

    sys_call_status = syscall(KERNEL_2D_MEMCPY_SYSCALL, src_arr, dest_arr, 5,5);

    int n=5,m=5;
    if (sys_call_status != EFAULT)
    {
        p("Message : System Call 451 successfuly invoked \n");
        int i=0,j=0;
        fr(i,n){
            fr(j,m){
                if(src_arr[i][j]!=dest_arr[i][j])
                printf("Error : SRC[%d] != DEST[%d]\n", i, i);
                // return;
            }
        }
        printf("Message : Successfully Copied the Data \n");
    }

    return 0;
}
