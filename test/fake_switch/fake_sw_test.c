/**
*@brief function definitions
*@author Ahmed Mohamed Elbadry
*/

#include "fake_sw.h"
#include "../../source/switch/switch.h"

#include "../unity/unity_fixture.h"

TEST_GROUP(Fake_PB);

TEST_SETUP(Fake_PB)
{
    FAKE_SW_init();
}


TEST_TEAR_DOWN(Fake_PB)
{
    FAKE_SW_destroy();
}

/*------------- Test Cases -------*/


/** Doxygen Test Case Description **/
TEST(Fake_PB, Buttons_Are_Released_After_Init)
{
    /*!
		  * @par Given : PusButton State is unknown
		  * @par When  : Init is called
		  * @par Then  : Switch state is PB_RELEASED
	*/

    /* Note that init is called in TEST_SETUP() */
    LONGS_EQUAL(PB_RELEASED, FAKE_SW_getSwState());
}


/** Doxygen Test Case Description **/
TEST(Fake_PB, set_PB_State)
{
    /*!
		  * @par Given : Switch State is Released
		  * @par When  : Switch State is set to PB_PRE_PRESSED
		  * @par Then  : Switch state is SW_PRE_PRESSED
	*/

    FAKE_SW_setSwState(PB_PRE_PRESSED);
    LONGS_EQUAL(PB_PRE_PRESSED, FAKE_SW_getSwState());
}



TEST_GROUP_RUNNER(Fake_PB)
{
   RUN_TEST_CASE(Fake_PB, Buttons_Are_Released_After_Init);
   RUN_TEST_CASE(Fake_PB, set_PB_State);
}

