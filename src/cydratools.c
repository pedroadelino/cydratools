//Cydrotools
//Cydia Tools
//by Pedro Adelino
//Nara Logic 2020
//www.bypedro.eu

#include <stdio.h>
#include <string.h>
#include "naralogic.h"
#include "chmod777fix.h"
#include "cydiafix.h"
#include "cydiarepos.h"
#include "createdpkg.h"
#include "restoredpkg.h"
//#include <curses.h>
//#include <conio.h>

// Global var
char *app_version = "0.5";

int main(){
int menuoption = 10;
//savelog("Clear screen...");
while(menuoption > 0)//& (menuoption < 6)
{
//clearscreen();
colorprint("=================================================\n", "blue");
colorprint("          ***  *   *  **    ****  ****\n", "yellow");
colorprint("          *     * *   * *   *  *  *  *\n", "yellow");
colorprint("          *      *    *  *  **    ****\n", "yellow");
colorprint("          *      *    * *   * *   *  *\n", "yellow");
colorprint("          ***    *    **    *  *  *  *\n", "yellow");
colorprint("                   tools v", "yellow");
colorprint(app_version, "yellow");
colorprint("\n", "yellow");
colorprint("        By Pedro Adelino - www.bypedro.eu\n", "red");
colorprint("=================================================\n", "blue");
colorprint("Please choose an option :\n", "green");
colorprint("[1] - Add repositories to Cydia.\n", "green");
colorprint("[2] - Fix iOS filesystem permissions.\n", "green");
colorprint("[3] - Fix Cydia white screen problem.\n", "green");
colorprint("[4] - Create package lists with APT/DPKG.\n", "green");
colorprint("[5] - Restore packages with DPKG.\n", "green");
colorprint("[0] - Exit this app.\n", "green");
colorprint(">", "yellow");

scanf("%d",&menuoption);
//gets(menuoption);
//menuoption = getchar();

switch(menuoption)
{
        case 1: //referente a opcao 1
        //printf("Eu escolhi a opcao 1 \n");
        cydiarepos();
        savelog("Option 1");
        //clearscreen();
        break;

        case 2: //referente a opcao 2
        //printf("Eu escolhi a opcao 2 \n");
        chmod777fix();
        savelog("Option 2");
        //clearscreen();
        break;

        case 3: //referente a opcao 3
        //printf("Eu escolhi a opcao 3 \n");
        cydiafix();
        savelog("Option 3");
        //clearscreen();
        break;

        case 4: //referente a opcao 4
        //printf("Eu escolhi a opcao 4 \n");
        createdpkg();
        savelog("Option 4");
        //clearscreen();
        break;

        case 5: //referente a opcao 5
        //printf("Eu escolhi a opcao 5 \n");
        restoredpkg();
        savelog("Option 5");
        //clearscreen();
        break;

        case 0: //referente exit
        //printf("Eu escolhi a opcao exit \n");
        savelog("Option Exit");
        //clearscreen();
        break;
       
        //else: //any other option
        //savelog("Wrong Option");
        //colorprint("Wrong option!\n", "red");
        //break;
}

} // while loop
savelog("App exit.");
return (0);
}
