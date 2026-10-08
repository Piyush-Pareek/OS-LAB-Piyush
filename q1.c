#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){

    int arr[] = {10,5,20,8,6};
    pid_t pid = fork();
    if(pid <0){
        perror("Failed");
        return -1;
    }
    if(pid==0){
       int min = 1e9;
        for(int i=0;i<5;i++){
            if(min>arr[i]){
                min = arr[i];
            }
        }
        printf("MiN No. is %d\n",min);
        exit(0);
    }else{
        // parent
        wait(NULL);
        int max = -1e9;
        for(int i=0;i<5;i++){
            if(max<arr[i]){
                max = arr[i];
            }
        }
        printf("MiN No. is %d\n",max);
    }

    return 0;
}