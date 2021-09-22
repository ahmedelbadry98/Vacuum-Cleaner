#include <stdio.h>
#include <stdlib.h>

/* Include Modules */
#include "switch/switch.h"
#include "speed/speed.h"


/* Include Unity */
#include "../test/unity/unity_fixture.h"
#define MAKE_UNITY_VERBOSE	argc = 2; argv[1] = "-v"


/* Test Groups Runner */
 void RunAllTests(void)
{
    RUN_TEST_GROUP(Fake_PB);
    RUN_TEST_GROUP(VacuumState);
}


int main(int argc, char * argv[])
{

    /* Manipulate argc & argv to make unity verbose*/
    /* You can use CodeBlocks Command Line inputs to do the same */
    MAKE_UNITY_VERBOSE;

    /* Call Unity Main */
    UnityMain(argc, argv, RunAllTests);


    printf("App is running..");
    Vacuum_init();  // led_state = LED_OFF;
    SWITCH_init(); //real_switch_state = SW_RELEASED; SWITCH_getSwState = real_switch_state ;

    while(1)
    {



    }

    return 0;
}

