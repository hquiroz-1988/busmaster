/**
 ********************************************************************************
 * @file    state.cpp
 * @author  Hugo Quiroz
 * @date    2024-04-04 18:11:35
 * @brief   description
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include "state.h"

/************************************
 * EXTERN VARIABLES
 ************************************/

/************************************
 * PRIVATE MACROS AND DEFINES
 ************************************/


/************************************
 * PRIVATE TYPEDEFS
 ************************************/

#define ENTERING_STATE()    (smObj.currState != smObj.prevState)
#define EXITING_STATE()      (smObj.currState != smObj.reqState)

/************************************
 * STATIC VARIABLES
 ************************************/

/************************************
 * GLOBAL VARIABLES
 ************************************/

/************************************
 * STATIC FUNCTION PROTOTYPES
 ************************************/

/************************************
 * STATIC FUNCTIONS
 ************************************/

void State::enterFunction(void)
{
    /* do nothing    */
}
void State::runFunction(void)
{
    /* do nothing    */
}
void State::gateFunction(void)
{
    /* do nothing    */
}
void State::exitFunction()
{
    /* do nothing    */
}

/************************************
 * GLOBAL FUNCTIONS
 ************************************/


void State::run(void)
{

    /* function for first time init */
    if(ENTERING_STATE())
    {
        enterFunction();
    }
    
    runFunction();

    gateFunction();
    
    if(EXITING_STATE())
    {
        exitFunction();
    }
}


