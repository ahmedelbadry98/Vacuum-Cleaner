/**
*@brief function definitions
*@author Ahmed Mohamed Elbadry
*/

#include "speed.h"
#include "../switch/switch.h"
#include "../../test/fake_switch/fake_sw.h"


static Vacuum_Speed_State_t vacuum_state;

void            Vacuum_init(void)
{
    vacuum_state = Medium;
}




Vacuum_Speed_State_t     Vacuum_getState(void)
{
    return vacuum_state;
}


void            Vacuum_update(void)
{
    Start_Motor();

extern PB_TYPE_t  pb_type;
SWITCH_STATE_t switch_state = SWITCH_getSwState();



//#####################################################################

    if(switch_state == PB_PRESSED && vacuum_state != Minimum && pb_type == PB_PRESSURE )
    {

extern SWITCH_PRESSURE_TME_t pressure_time;

   if(pressure_time == SW_P_TIME_30_ms){
        if(vacuum_state == Medium){vacuum_state = Minimum;}
        else if(vacuum_state == Maximum){vacuum_state = Medium;}
        Motor_update_degree(vacuum_state);
       }
   else if(pressure_time == SW_P_TIME_0_ms){ Motor_update_degree(vacuum_state);}

    }

//#####################################################################


    else if(switch_state == PB_PRE_PRESSED   && vacuum_state != Minimum && pb_type == PB_MINUS)
    {
        if(vacuum_state == Medium){vacuum_state = Minimum;}
        else if(vacuum_state == Maximum){vacuum_state = Medium;}
        Motor_update_degree(vacuum_state);
    }


    else if(switch_state ==   PB_PRE_PRESSED   && vacuum_state != Maximum && pb_type == PB_PLUS )
    {
         if(vacuum_state == Medium){vacuum_state = Maximum;}
        else if(vacuum_state == Minimum){vacuum_state = Medium;}
        Motor_update_degree(vacuum_state);
    }
    else
    {

    }
}

