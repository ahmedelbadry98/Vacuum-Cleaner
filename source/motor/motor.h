/**
*@brief function prototypes
*@author Ahmed Mohamed Elbadry
*/

#ifndef MOTOR_H_INCLUDED
#define MOTOR_H_INCLUDED

typedef enum{Max=10,Min=140,Med=90} motor_t;

///@brief this function empty the text function before using it in the program
void          Start_Motor(void);


///@brief this function prints motor degree in a text file called Motor
void          Motor_update_degree(void);



#endif // MOTOR_H_INCLUDED
