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
void StateMachine::update_stateVars(void)
{
    prevState = currState;
    if(noState != reqState)
    {
        currState = reqState;
        reqState = noState;
    }
}

void StateMachine::request_reqState(uint8_t state)
{
    reqState = state;
}


/************************************
 * GLOBAL FUNCTIONS
 ************************************/

StateMachine::StateMachine(void)
{
    
}

eRetVal_t StateMachine::run(void)
{
    eRetVal_t eRetVal = ERET_SUCCESS;

    /* update sm state   */
    update_stateVars();

    if(nullptr != funcArrayPtr)
    {
        if(nullptr != (*funcArrayPtr)[currState])
        {
            (*funcArrayPtr)[currState]();
        }
    }

    return eRetVal;
}


