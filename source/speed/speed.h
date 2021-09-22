/**
*@brief function prototypes
*@author Ahmed Mohamed Elbadry
*/

#ifndef SPEED_H_INCLUDED
#define SPEED_H_INCLUDED

typedef enum {Minimum, Medium, Maximum} Vacuum_Speed_State_t;

///@brief this function used to initialize vacuum speed state to medium
void                     Vacuum_init(void);

///@brief this function used to get vacuum speed state
Vacuum_Speed_State_t     Vacuum_getState(void);

///@brief this function used to update vacuum speed state
void                     Vacuum_update(void);


#endif
