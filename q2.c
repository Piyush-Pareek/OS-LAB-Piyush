#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(){
    char message[] = "Hi I am piyush";
    char buffer[100];
    int fd[2];
    if(pipe(fd) == -1){
         return 1;
    }
    pid_t pid = fork();

    if(pid == 0){
        //child 
        close(fd[0]);
        write(fd[1],message,strlen(message)+1);
        close(fd[1]);
        exit(0);
    }else{
        close(fd[1]);
        FILE *file = fopen("temp.txt","w");
        read(fd[0],buffer,sizeof(buffer));
        fprintf(file,"%s",buffer);
        close(fd[0]);
        fclose(file);

        FILE *file1 = fopen("temp.txt","r");
        char buffer1[100];
        while(fgets(buffer1,sizeof(buffer1),file1)!=NULL){
            printf("%s",buffer1);
        }
        fclose(file1);
        wait(0);
    }
    return 0;
}