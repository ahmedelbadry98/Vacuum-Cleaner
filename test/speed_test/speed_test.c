/**
*@brief function definitions
*@author Ahmed Mohamed Elbadry
*/


#include <stdio.h>
#include <string.h>
/* Include tested module header file */
#define EXPOSE_LED_INTERNALS
#include "../../source/speed/speed.h"

/*Include FakeSwitch */
#include "../fake_switch/fake_sw.h"

/* Include Unity */
#include "../unity/unity_fixture.h"


SWITCH_PRESSURE_TME_t pressure_time;
PB_TYPE_t  pb_type;


TEST_GROUP(VacuumState);


/* Helper function to reuse tests */
static void SPEED_TEST_getTestData(SWITCH_STATE_t* initial_switch_state,Vacuum_Speed_State_t* initial_Vacuum_state,Vacuum_Speed_State_t* expected_Vacuum_state, unsigned char test_num);

/* Helper function to reuse tests */
static void SPEE_TEST_arrange(SWITCH_STATE_t switch_state, Vacuum_Speed_State_t led_state);


TEST_SETUP(VacuumState)
{
    /* Point to the fake getter */
    UT_PTR_SET(SWITCH_getSwState, FAKE_SW_getSwState);
}


TEST_TEAR_DOWN(VacuumState)
{

}

/** Doxygen Test Case Description **/
TEST(VacuumState, Vacuum_Speed_Is_Medium_After_Init)
{
    /*!
		  * @par Given : Vacuum is in unknown state
		  * @par When  : Vacuum_init() is called
		  * @par Then  : Vacuum speed is in Medium state
	*/


    /* Expected Vacuum state */
	Vacuum_Speed_State_t expected_Vacuum_state = Medium;

    /* Act */
    Vacuum_init();


    /* Assert */
    LONGS_EQUAL(expected_Vacuum_state, Vacuum_getState());
}

/** Doxygen Test Case Description **/
TEST(VacuumState, speed_Increase_When_pluse_VE_PrePressed)
{
    /*!
		  * @par Given : Vacuum is in Medium state
		  * @par When  : "+ve"Switch is pressed
		  * @par Then  : Vacuum is in Maximum state
	*/

	/* Test data */
    SWITCH_STATE_t switch_state;
    Vacuum_Speed_State_t  Speed_State;
    Vacuum_Speed_State_t expected_Vacuum_state;
    Vac_TEST_getTestData(&switch_state, &Speed_State,&expected_Vacuum_state , 0);


	/* Arrange */
    Vacuum_TEST_arrange(switch_state, Speed_State);

    FAKE_SW_setSwState(switch_state);

	/* Act */
    Vacuum_update();

    /* Assert */
    LONGS_EQUAL(expected_Vacuum_state, Vacuum_getState());
}



/** Doxygen Test Case Description **/
TEST(VacuumState, speed_Decrease_When_Minus_VE_PrePressed)
{
    /*!
		  * @par Given : Vacuum is in Maximum state
		  * @par When  : "-ve"Switch is pressed
		  * @par Then  : Vacuum is in Medium state
	*/

	/* Test data */
/* Test data */
    SWITCH_STATE_t switch_state;
    Vacuum_Speed_State_t  Speed_State;
    Vacuum_Speed_State_t expected_Vacuum_state;
    Vac_TEST_getTestData(&switch_state, &Speed_State,&expected_Vacuum_state , 1);


	/* Arrange */
    Vacuum_TEST_arrange(switch_state, Speed_State);

    FAKE_SW_setSwState(switch_state);
	/* Act */
    Vacuum_update();

    /* Assert */
    LONGS_EQUAL(expected_Vacuum_state, Vacuum_getState());
}

/** Doxygen Test Case Description **/
TEST(VacuumState, speed_Decrease_When_P_pressed_for_30_ms)
{
       /*!
		  * @par Given : Vacuum is in Maximum state
		  * @par When  : "P" Switch is pressed for 30 ms
		  * @par Then  : Vacuum is in Minimum state
	*/

	/* Test data */
/* Test data */
    SWITCH_STATE_t switch_state;
    Vacuum_Speed_State_t  Speed_State;
    Vacuum_Speed_State_t expected_Vacuum_state;
    Vac_TEST_getTestData(&switch_state, &Speed_State,&expected_Vacuum_state , 2);


	/* Arrange */
    Vacuum_TEST_arrange(switch_state, Speed_State);

    FAKE_SW_setSwState(switch_state);
	/* Act */
    Vacuum_update();

    /* Assert */
    LONGS_EQUAL(expected_Vacuum_state, Vacuum_getState());
}


TEST_GROUP_RUNNER(VacuumState)
{
    RUN_TEST_CASE(VacuumState, Vacuum_Speed_Is_Medium_After_Init);
    RUN_TEST_CASE(VacuumState, speed_Increase_When_pluse_VE_PrePressed);
    RUN_TEST_CASE(VacuumState, speed_Decrease_When_Minus_VE_PrePressed);
    RUN_TEST_CASE(VacuumState, speed_Decrease_When_P_pressed_for_30_ms);

    /* And so on..*/
    /* False transitions & 1-Switch coverage tests should be added */
}



/* Helper function implementation */
volatile void Vacuum_TEST_arrange(SWITCH_STATE_t switch_state, Vacuum_Speed_State_t vacuum_state)
{
    /* Set Fake switch state */
    FAKE_SW_setSwState(switch_state);
}

// #if 0
/* Helper function to reuse tests */
volatile void Vac_TEST_getTestData(SWITCH_STATE_t* initial_switch_state,Vacuum_Speed_State_t* current_speed_State,Vacuum_Speed_State_t* expected_speed_state, unsigned char test_num)
{
    FILE* f = fopen("test_data.txt","r+");
    char str1[20];
    char str2[20];
    char str3[20];
    char str4[20];
    char str5[20];

    if(f)
    {
        unsigned char i = 0 ;

        for(i = 0; i <= test_num; i++)
        {
            if(i == 2){
                  memset(str1,0,20);
                  memset(str2,0,20);
                  memset(str3,0,20);
                  memset(str4,0,20);
                  memset(str5,0,20);

                  fscanf(f, "%s\t%s\t%s\t%s\t%s\n",str1, str2, str3, str4, str5);


           }

            else{
            memset(str1,0,20);
            memset(str2,0,20);
            memset(str3,0,20);
            memset(str4,0,20);
            fscanf(f, "%s\t%s\t%s\t%s\n",str1, str2, str3, str4);  }



        }


        if(strcmp(str1,"PB_PRESSED") == 0)
        {
            *initial_switch_state = PB_PRESSED;
        }
        else if (strcmp(str1,"PB_PRE_PRESSED") == 0)
        {
            *initial_switch_state = PB_PRE_PRESSED;
        }
        else if(strcmp(str1,"PB_PRE_RELEASED") == 0)
        {
            *initial_switch_state = PB_PRE_RELEASED;
        }
         else if(strcmp(str1,"PB_RELEASED") == 0)
        {
            *initial_switch_state = PB_RELEASED;
        }
        else
        {
            printf("Incorrect test data\n");
            return;
        }

        if(strcmp(str2,"Minimum") == 0)
        {
            *current_speed_State = Minimum;
        }
        else if (strcmp(str2,"Medium") == 0)
        {
            *current_speed_State = Medium;
        }
        else if(strcmp(str2,"Maximum") == 0)
        {
            *current_speed_State = Maximum;
        }
        else
        {
            printf("Incorrect test data\n");
        }

//#############################################################################

        if(strcmp(str3,"Minimum") == 0)
        {
            *expected_speed_state = Minimum;
        }
        else if (strcmp(str3,"Medium") == 0)
        {
            *expected_speed_state = Medium;
        }
        else if(strcmp(str3,"Maximum") == 0)
        {
            *expected_speed_state = Maximum;
        }
        else
        {
            printf("Incorrect test data\n");
            return;
        }

//##########################################################################

        if(strcmp(str4,"PB_PLUS") == 0){

            pb_type = PB_PLUS;

           }
        else if(strcmp(str4,"PB_MINUS") == 0){

            pb_type = PB_MINUS;

           }
        else if(strcmp(str4,"PB_PRESSURE") == 0){

            pb_type = PB_PRESSURE;

           }
        else
        {
            printf("Incorrect test data\n");
            return;
        }

//######################################################################

      if(test_num == 2 ){


      if(strcmp(str4,"PB_PLUS") == 0){

            pb_type = PB_PLUS;

           }
        else if(strcmp(str4,"PB_MINUS") == 0){

            pb_type = PB_MINUS;

           }
        else if(strcmp(str4,"PB_PRESSURE") == 0){

            pb_type = PB_PRESSURE;

           }
        else
        {
            printf("Incorrect test data\n");
            return;
        }

        if(strcmp(str5,"SW_P_TIME_30_ms") == 0){

            pressure_time = SW_P_TIME_30_ms;

           }
        else if(strcmp(str5,"SW_P_TIME_0_ms") == 0){

            pressure_time = SW_P_TIME_0_ms;

           }
        else
        {
            printf("Incorrect test data\n");
            return;
        }


      } //test_num == 2

//###################################################################################

        fclose(f);
    }
    else
    {
        printf("Failed To open the file");
    }

}


// #endif
