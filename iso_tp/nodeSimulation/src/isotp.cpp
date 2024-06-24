/**
 ********************************************************************************
 * @file    isotp.cpp
 * @author  Hugo Quiroz
 * @date    2024-04-04 18:11:35
 * @brief   description
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include "isotp.h"

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

void Isotp::update_stateVars(void)
{
    prevState = currState;
    if(ISOTPSM_NO_STATE != nextState)
    {
        currState = nextState;
        nextState = ISOTPSM_NO_STATE;
    }
}

void Isotp::request_nextState(isotpSMStates_t reqState)
{
    nextState = reqState;
}

void Isotp::run_idleState(void)
{
    /* implement run function */
}

bool Isotp::transition_idleToProcessMsg(void)
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

bool Isotp::transition_idleToProcessData(void)
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

bool Isotp::transition_processDataToSendSF(void)
{
    /* check conditions for transitioning    */
}

bool Isotp::transition_processDataToSendFF(void)
{
    /* check conditions for transitioning    */
}

bool Isotp::transition_sendFFToWaitFC(void)
{
    /* check conditions for transitioning    */
}

bool Isotp::transition_waitFCToSendCF(void)
{
    /* check conditions for transitioning    */
}

bool Isotp::transition_sendCFToDelayCF(void)
{
    /* check conditions for transitioning    */
}

/************************************
 * GLOBAL FUNCTIONS
 ************************************/
eRetVal_t Isotp::debugFunctionCallback(debugFunctionPtr_t dbgFuncPtr)
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

eRetVal_t Isotp::testPrint(void)
{
    eRetVal_t eRetVal = ERET_SUCCESS;

    if(NULL != debugPrint)
    {
        debugPrint((char *)"Testing...%i", 123U);
    }
    return eRetVal;
}

eRetVal_t Isotp::stateMachineRun(void)
{
    eRetVal_t eRetVal = ERET_SUCCESS;

    
    switch(currState)
    {
        case ISOTPSM_IDLE_STATE:
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
                request_nextState(ISOTPSM_PROCESS_DATA_STATE);
            }
            else if(transition_idleToProcessData())
            {
                request_nextState(ISOTPSM_PROCESS_DATA_STATE);
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
        case ISOTPSM_PROCESS_DATA_STATE:
        {
            break;
        }
        case ISOTPSM_SEND_SF_STATE:
        {
            break;
        }
        case ISOTPSM_SEND_FF_STATE:
        {
            break;
        }
        case ISOTPSM_WAIT_FOR_FC_STATE:
        {
            break;
        }
        case ISOTPSM_SEND_CF_STATE:
        {
            break;
        }
        case ISOTPSM_DELAY_CF_STATE:
        {
            break;
        }
        case ISOTPSM_PROCESS_MSG_STATE:
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


