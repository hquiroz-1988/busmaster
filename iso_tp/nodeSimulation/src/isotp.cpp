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
Isotp::Isotp()
{

}

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

eRetVal_t Isotp::run(void)
{
    eRetVal_t eRetVal = ERET_SUCCESS;

    update_stateVars();

    return eRetVal;
}


