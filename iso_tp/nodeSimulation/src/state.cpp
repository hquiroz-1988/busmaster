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

void StateMachine::update_stateVars(void)
{
    prevState = currState;
    if(STATEMACHINESM_NO_STATE != nextState)
    {
        currState = nextState;
        nextState = STATEMACHINESM_NO_STATE;
    }
}

void StateMachine::request_nextState(statemachineSMStates_t reqState)
{
    nextState = reqState;
}

void StateMachine::run_idleState(void)
{
    /* implement run function */
}

bool StateMachine::transition_idleToProcessMsg(void)
{
    /* check conditions for transitioning    */
    bool retVal = false;

    // /* conditions for transitioning are receiving data from CAN module   */
    // if(get_canMessageFlag())
    // {
    //     retVal = true;
    // }

    return retVal;
}

bool StateMachine::transition_idleToProcessData(void)
{
    /* check conditions for transitioning    */
    bool retVal = false;

    // /* conditions for transitioning are receiving data from UDS module   */
    // if(get_udsMessageFlag())
    // {
    //     retVal = true;
    // }

    return retVal;
}

bool StateMachine::transition_processDataToSendSF(void)
{
    /* check conditions for transitioning    */
}

bool StateMachine::transition_processDataToSendFF(void)
{
    /* check conditions for transitioning    */
}

bool StateMachine::transition_sendFFToWaitFC(void)
{
    /* check conditions for transitioning    */
}

bool StateMachine::transition_waitFCToSendCF(void)
{
    /* check conditions for transitioning    */
}

bool StateMachine::transition_sendCFToDelayCF(void)
{
    /* check conditions for transitioning    */
}

/************************************
 * GLOBAL FUNCTIONS
 ************************************/
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

eRetVal_t StateMachine::stateMachineRun(void)
{
    eRetVal_t eRetVal = ERET_SUCCESS;

    
    switch(currState)
    {
        case STATEMACHINESM_IDLE_STATE:
        {
            if(ENTERING_STATE())
            {
                /* first time setup for this state */
            }

            /* run function*/
            run_idleState();
            

            /* check for transitions  */
            if(transition_idleToProcessMsg())
            {
                request_nextState(STATEMACHINESM_PROCESS_DATA_STATE);
            }
            else if(transition_idleToProcessData())
            {
                request_nextState(STATEMACHINESM_PROCESS_DATA_STATE);
            }
            else
            {
                /* do nothing, possibly clear the req state if not one of the above states */
            }


            if(EXITING_STATE())
            {
                /* last minute wrap up with this state   */
            }
            break;
        }
        case STATEMACHINESM_PROCESS_DATA_STATE:
        {
            break;
        }
        case STATEMACHINESM_SEND_SF_STATE:
        {
            break;
        }
        case STATEMACHINESM_SEND_FF_STATE:
        {
            break;
        }
        case STATEMACHINESM_WAIT_FOR_FC_STATE:
        {
            break;
        }
        case STATEMACHINESM_SEND_CF_STATE:
        {
            break;
        }
        case STATEMACHINESM_DELAY_CF_STATE:
        {
            break;
        }
        case STATEMACHINESM_PROCESS_MSG_STATE:
        {
            break;
        }
        default:
        {
            break;
        }
    }

    return eRetVal;
}


