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