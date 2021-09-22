/**
*@brief function definitions
*@author Ahmed Mohamed Elbadry
*/


#include<stdlib.h>
#include <stdio.h>
#include"conio.h"
#include "../speed/speed.h"
#include "motor.h"

int count=0;


void          Start_Motor(void)
{

    count=0;
FILE* f = fopen("Motor.txt","w");
    if(f){


fprintf(f,NULL);

fclose(f);
    }
        else
    {
        printf("Failed To open the file");
    }
return;

}






Motor_update_degree(Vacuum_Speed_State_t vacuum_state)
{

motor_t degree;

FILE* f = fopen("Motor.txt","a");



    if(f){
char temp;
if(vacuum_state == Medium){degree=Med;       fseek(f,count,SEEK_SET); fputs(" 90",f); count+=3;    } //90
else if(vacuum_state == Minimum){degree=Min;      fseek(f,count,SEEK_SET); fputs(" 140",f); count+=3;  } // 140
else if(vacuum_state == Maximum){degree=Max;    fseek(f,count,SEEK_SET); fputs(" 10",f); count+=3; } //10





    }
    else
    {
        printf("Failed To open the file");
    }
return;
}
