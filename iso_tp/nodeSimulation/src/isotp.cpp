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
eRetVal_t Isotp::sm_gateFunction(void)
{
    switch(currState)
    {
        case ISOTPSM_IDLE_STATE:
        {
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
}

eRetVal_t Isotp::sm_runFunction(void)
{
    switch(currState)
    {
        case ISOTPSM_IDLE_STATE:
        {
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

    sm_gateFunction();

    

    sm_runFunction();

    return eRetVal;
}


