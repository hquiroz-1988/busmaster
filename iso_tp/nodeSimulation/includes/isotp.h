/**
 ********************************************************************************
 * @file    isotp.h
 * @author  Hugo Quiroz
 * @date    2024-04-04 18:11:57
 * @brief   description
 ********************************************************************************
 */

#ifndef ISOTP_H
#define ISOTP_H

/************************************
 * INCLUDES
 ************************************/
#include "typedefs.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************
 * MACROS AND DEFINES
 ************************************/

/************************************
 * TYPEDEFS
 ************************************/

class Isotp
{
    public:

    eRetVal_t debugFunctionCallback(debugFunctionPtr_t dbgFuncPtr);

    eRetVal_t testPrint(void);

    eRetVal_t stateMachineRun(void);

    private:

    debugFunctionPtr_t debugPrint;

};

/************************************
 * EXPORTED VARIABLES
 ************************************/

/************************************
 * GLOBAL FUNCTION PROTOTYPES
 ************************************/


#ifdef __cplusplus
}
#endif

#endif //ISOTP_H