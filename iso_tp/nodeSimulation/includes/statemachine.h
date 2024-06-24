/**
 ********************************************************************************
 * @file    statemachine.h
 * @author  Hugo Quiroz
 * @date    2024-04-04 18:11:57
 * @brief   description
 ********************************************************************************
 */

#ifndef STATEMACHINE_H
#define STATEMACHINE_H

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
typedef eRetVal_t (*stateFunctionPtr)(void);

class StateMachine
{
    public:
    eRetVal_t debugFunctionCallback(debugFunctionPtr_t dbgFuncPtr);
    eRetVal_t testPrint(void);
    virtual eRetVal_t run(void);
    StateMachine(void){};
    
    private:

    debugFunctionPtr_t debugPrint = nullptr;
    stateFunctionPtr * funcArrayPtr  = nullptr;
    
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

#endif //STATEMACHINE_H