//Restore DPKG list
//by Pedro Adelino
//Nara Logic 2020
//www.bypedro.eu

//Version
#define VERSION_MAJOR 0
#define VERSION_MINOR 1
#define VERSION 0.1
#define VERSION_REVISION 1
//#define VERSION STRINGIZE(VERSION_MAJOR) "." STRINGIZE(VERSION_MINOR)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>      // needed to use pid_t, etc.
#include <sys/wait.h>       // needed to use wait()
//#include "naralogic.h"
//double app_version = VERSION;
//const char *app_version = "0.1";
//int println;

//int errorsc; not working
int restoredpkg_errors = 0;

int restoredpkg()
{
    //int ret;
    colorprint("Restore DKPG list.", "blue");
    //colorprint(app_version, "blue");
    colorprint("\n", "blue");
	//colorprint("Apt App List Backup v" + app_version, "blue");
    //colorprint("By Pedro Adelino.", "blue");
    //colorprint("www.bypedro.eu", "blue");
    //The following example searches for the location of the command
    //among the directories specified by the PATH environment variable.
    //ret = execlp("ls", "ls", "-l", (char *)NULL);
    int commandnr;
    
    FILE *file;
    for(commandnr=1;commandnr<=1;commandnr++){
    pid_t pid;
    pid = fork();
    if (pid < 0)
    {
        colorprint("A fork error has occurred. Please try again!", "red");
        exit(-1);
    }
    else 
    if (pid == 0) /* We are in the child. */
    {
        if (commandnr == 1){
            //Command1
            //printf("Command1\n");
            //printf("I am the child, about to call ls using execlp.\n");
            //char *command = ;
            if((file = fopen("dpkglist.txt","r"))==NULL)
            {
                // file doesn't exist
                fclose(file);
                //execlp("cp", "cp", "cydiareposbypedro.txt", "/etc/apt/sources.list.d/cydiareposbypedro.list" , "-v", "-i" , NULL);
                colorprint("List not found!\n", "red");
            }
            else
            {
                colorprint("Preparing script...\n", "yellow");
                // Create DPKG script
                file = fopen("dpkgrestore.sh","w");
                fprintf(file, "#!/bin/bash\n");
                fprintf(file, "echo %cDPKG list restore v0.2%c\n", 34, 34);
                fprintf(file, "echo %cBy Pedro Adelino - www.bypedro.eu%c\n", 34, 34);
                fprintf(file, "echo %cRestoring packages with DPKG from dpkglist.txt%c\n", 34, 34);
                fprintf(file, "dpkg --set-selections < dpkglist.txt\n");
                //fprintf(file, "#dpkg-query -l > dpkg.txt\n");
                //fprintf(file, "echo %cAll done. Have fun!%c\n", 34, 34);
                fclose(file); //Save data to file

                colorprint("Running script...\n", "yellow");
                //execlp("bash", "bash", "/var/mobile/Containers/Data/Application/3B494759-94BF-429D-B7C4-FBB75144A3C6/Documents/files/cydratools/iplcreatorbypedro.sh", NULL);
                execlp("bash", "bash", "dpkgrestore.sh", NULL);
                //execlp("dpkg" , "dpkg", "--get-selections", "|", "tee", "dpkglist.txt", NULL);
                //execle("dpkg" , "dpkg", "--get-selections", ">", "dpkglist.txt", NULL);
                //execv("dpkg" , "dpkg --get-selections |& tee dpkglist.txt");
                //execve("bash" , "bash /var/mobile/Containers/Data/Application/GoCoEdit/Documents/files/cydratools/iplcreatorbypedro.sh", NULL);
                //execvp("dpkg" , "dpkg --get-selections > /var/root/dpkglist.txt");
                //execve("dpkg" , "dpkg --get-selections > /var/root/dpkglist.txt", NULL);
                //execvpe("dpkg" , "dpkg --get-selections > /var/root/dpkglist.txt");
                colorprint("Error running script!\n", "red");
                //++errorsc;
                ++restoredpkg_errors;
                //errorsc=errorsc + 1;
                //colorprinti(errorsc, "yellow"); //debug
                exit(127);
                //colorprinti(errorsc, "yellow"); //debug
            }
            /*  If execlp() is successful, we should not reach this next line. */
            //printf("The call to execlp() was not successful.\n");
            //printf("\033[1;31m"); // Red color
            //printf("Failed executing command 1.\n");
            //printf("\033[0m"); // Reset color
            //errors++;   
        }
    }
    else  /* We are in the parent. */
    {
    //Command executed
    //pid = 0;
    //colorprinti(errorsc, "yellow"); //debug
    wait(0);               /* Wait for the child to terminate. */
    //Go to the next command or exit
    }
    //colorprinti(errorsc, "yellow");//debug
    } //Loop
    if (restoredpkg_errors == 0) {
        //colorprinti(errorsc, "yellow"); //debug
        colorprint("All done. Have fun!\n", "green");
    }
    else {
        colorprint("Failed generating list! Please try again!\n", "red");
        //exit(127);
    }
    //printf("I am the parent.  The child just ended.  I will now exit.\n");
    //exit(0);
    return(0); 
}
