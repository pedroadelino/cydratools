#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>      /* needed to use pid_t, etc. */
#include <sys/wait.h>       /* needed to use wait() */  

int getdefinedos(){
int os;
#if defined(__linux__)
        //printf("linux\n");
        os = 1;//"linux"
    #endif

    #if defined(__unix__)
        //printf("unix\n");
        os = 2;//"unix";
    #endif

    #if defined(__APPLE__)
        //printf("apple\n");
        os = 3;//"apple";
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        //printf("win\n");
        os = 4;//"win";
    #endif
return os;
}



int savelog(char *message){
   FILE *file;
   char *os;
   if((file = fopen("log.txt","r"))!=NULL)
            {
                // file exists
                fclose(file);
            }
            else     
            { 
               file = fopen("log.txt","w");
               //if (getdefinedos()) == 3){}
               fprintf(file, "Running ");
               fprintf(file, "%s",__FILE__);
               switch(getdefinedos())
               {              
                  case 1:
                  fprintf(file, " on : Linux");
                  break;
                  case 2:
                  fprintf(file, " on : Unix");
                  break;
                  case 3:
                  fprintf(file, " on : Apple");
                  break;
                  case 4:
                  fprintf(file, " on : Windows");
                  break;
               }
               fprintf(file, "\n");
               fclose(file);
            }
   //Save log
   file = fopen("log.txt","a");
      fprintf(file, "%s", message);
      fprintf(file, "\n");
   fclose(file);
return 0;
}

int colorprint(char *message, char *color){
   if (strcmp(color, "red") == 0)
   {
      printf("\033[1;31m"); // Red color
   } else
   if (strcmp(color, "yellow") == 0)
   {
      printf("\033[1;33m"); // Yellow color
   } else
   if (strcmp(color, "green") == 0)
   {
      printf("\033[1;32m"); // Green color
   } else
   if (strcmp(color, "blue") == 0)
   {
      printf("\033[1;34m"); // Blue color
   }   
   printf("%s", message);
   printf("\033[0m"); // Reset color
   return 0;
}

int colorprinti(int message, char *color){
   if (strcmp(color, "red") == 0)
   {
      printf("\033[1;31m"); // Red color
   } else
   if (strcmp(color, "yellow") == 0)
   {
      printf("\033[1;33m"); // Yellow color
   } else
   if (strcmp(color, "green") == 0)
   {
      printf("\033[1;32m"); // Green color
   } else
   if (strcmp(color, "blue") == 0)
   {
      printf("\033[1;34m"); // Blue color
   }   
   printf("%d", message);
   printf("\033[0m"); // Reset color
   return 0;
}

int clearscreenapple(){
   int commandnr;
   int errors=0;
   for(commandnr=1;commandnr<=1;commandnr++){
   pid_t pid;
   pid = fork();
   if (pid < 0)
   {
      colorprint("A fork error has occurred. Please try again!\n", "red");
      exit(-1);
   }
   else 
   if (pid == 0) /* We are in the child. */
   {
      if (commandnr == 1){
            //Command1
            //printf("Command1\n");
            //printf("I am the child, about to call clear using execlp.\n");
            //char *command = ;
            execlp("clear", "clear", NULL);
            /*  If execlp() is successful, we should not reach this next line. */
            //printf("The call to execlp() was not successful.\n");
            //printf("\033[1;31m"); // Red color
            //printf("Failed executing command 1.\n");
            //printf("\033[0m"); // Reset color
            colorprint("Error clearing screen!\n", "red");
            ++errors;
            exit(127);
        }
        //else
        //if (commandnr == 2){
            //Command2
            //printf("Command2\n");
            //char *command = ;
            //execlp("ls" , "ls" , "/etc/apt/sources.list.d/cydiareposbypedro.list", NULL);
            /*  If execlp() is successful, we should not reach this next line. */
            //printf("The call to execlp() was not successful.\n");
            //colorprint("Failed executing command 2.\n", "red");
            //errors++;
            //exit(127);
        //}
    }
    else  /* We are in the parent. */
    {
    //Command executed
    //pid = 0;
    wait(0);               /* Wait for the child to terminate. */
    //Go to the next command or exit
    }
    
    } //Loop
   return 0;
}

int clearscreen(){
    if (getdefinedos() == 1){
       //system("clear"); 
    } else
    if (getdefinedos() == 2){
       //system("cls");
    } else
    if (getdefinedos() == 3){
        clearscreenapple();
    } else
    if (getdefinedos() == 4){
        //system("cls");
    }
return 0;
}
