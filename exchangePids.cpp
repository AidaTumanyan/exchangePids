#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char** argv){

	int fd_1[2];
 	int fd_2[2];
	
	if(pipe(fd_1) == -1 || pipe(fd_2) == -1){
	    
           return 1;

        }
        
 	pid_t child_1, child_2;
	child_1 = fork();
	int buff = 4;

	if(child_1 == 0){
 	  
          close(fd_1[0]);
	  int child_1_pid = getpid();
	  std::cout<<child_1_pid<<" ";
	  write(fd_1[1], &child_1_pid, buff);
	  close(fd_1[1]);
	
	  close(fd_2[1]);
          int child_2_pid = getpid();
	  read(fd_2[0], &child_2_pid, buff);
	  std::cout<<child_2_pid<<" ";
	  close(fd_2[0]);
    
         }
         
        if(child_1 > 0){
	
	child_2 = fork(); 	

	}

	if(child_2 > 0){

	if(wait(NULL) == -1){
		
	 return 1;

	}
 	if(wait(NULL) == -1){

	return 1;

       }


	}
        else if(child_2 == 0){

          close(fd_2[0]);
          int child_2_pid = getpid();
          write(fd_2[1], &child_2_pid, buff);
	  std::cout<<child_2_pid<<" ";
          close(fd_2[1]);

          close(fd_1[1]);
          int child_1_pid = getpid();
          read(fd_1[0], &child_1_pid, buff);
	  std::cout<<child_1_pid<<" ";
          close(fd_1[0]);

         }

 }    
