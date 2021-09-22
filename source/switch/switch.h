/**
*@brief function prototypes
*@author Ahmed Mohamed Elbadry
*/

#ifndef SWITCH_H_INCLUDED
#define SWITCH_H_INCLUDED

typedef enum {PB_PRESSED,PB_RELEASED,PB_PRE_PRESSED,PB_PRE_RELEASED} SWITCH_STATE_t;

typedef enum {PB_PLUS,PB_MINUS,PB_PRESSURE} PB_TYPE_t;

typedef enum {SW_P_TIME_0_ms,SW_P_TIME_30_ms} SWITCH_PRESSURE_TME_t;


///@brief this function used to initialize the push button state to released
void        SWITCH_init(void);

///@brief this function used to get push button state
extern      SWITCH_STATE_t   (*SWITCH_getSwState)(void); /* Turned into pointer so we can make it point to another fake function */


///@brief this function used to update push button state
void        SWITCH_update(void);

#endif
