#ifndef FAKESW_H_INCLUDED
#define FAKESW_H_INCLUDED


#include "../../source/switch/switch.h"

///@brief this function used to initialize the push button state to released
void       FAKE_SW_init(void);

///@brief this function used to finalize the push button state to released
void       FAKE_SW_destroy(void);


SWITCH_STATE_t  FAKE_SW_getSwState(void);


///@brief this function used to set the push state
void       FAKE_SW_setSwState(SWITCH_STATE_t state);



#endif // FAKESW_H_INCLUDED
