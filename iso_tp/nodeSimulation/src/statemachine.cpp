/**
 ********************************************************************************
 * @file    statemachine.cpp
 * @author  Hugo Quiroz
 * @date    2024-04-04 18:11:35
 * @brief   description
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include "statemachine.h"

/************************************
 * EXTERN VARIABLES
 ************************************/

/************************************
 * PRIVATE MACROS AND DEFINES
 ************************************/
#define ENTERING_STATE()    (currState != prevState)
#define EXITING_STATE()      (currState != nextState)

/************************************
 * PRIVATE TYPEDEFS
 ************************************/

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



/************************************
 * GLOBAL FUNCTIONS
 ************************************/

StateMachine::StateMachine(void)
{
    
}
eRetVal_t StateMachine::debugFunctionCallback(debugFunctionPtr_t dbgFuncPtr)
{
    eRetVal_t eRetVal = ERET_ERROR;

    if(NULL != dbgFuncPtr)
    {
        debugPrint = dbgFuncPtr;
    }
    else
    {
        eRetVal = ERET_NULLPTR;
    }

    return eRetVal;
}

eRetVal_t StateMachine::testPrint(void)
{
    eRetVal_t eRetVal = ERET_SUCCESS;

    if(NULL != debugPrint)
    {
        debugPrint((char *)"Testing...%i", 123U);
    }
    return eRetVal;
}

eRetVal_t StateMachine::run(void)
{
    eRetVal_t eRetVal = ERET_SUCCESS;


    return eRetVal;
}


