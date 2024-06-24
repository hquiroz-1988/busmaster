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
typedef enum
{
    STATEMACHINESM_NO_STATE,
    STATEMACHINESM_IDLE_STATE,

    STATEMACHINESM_PROCESS_DATA_STATE,
    STATEMACHINESM_SEND_SF_STATE,
    STATEMACHINESM_SEND_FF_STATE,
    STATEMACHINESM_WAIT_FC_STATE,
    STATEMACHINESM_SEND_CF_STATE,
    STATEMACHINESM_DELAY_CF_STATE,

    STATEMACHINESM_PROCESS_MSG_STATE,
    STATEMACHINESM_EXTRACT_SF_STATE,
    STATEMACHINESM_EXTRACT_FF_STATE,
    STATEMACHINESM_SEND_FC_STATE,
    STATEMACHINESM_WAIT_MSG_STATE,
    STATEMACHINESM_EXTRACT_CF_STATE,
    STATEMACHINESM_OUTPUT_DATA_STATE,
}statemachineSMStates_t;


class StateMachine
{
    public:
    eRetVal_t debugFunctionCallback(debugFunctionPtr_t dbgFuncPtr);
    eRetVal_t testPrint(void);
    eRetVal_t stateMachineRun(void);

    private:
    debugFunctionPtr_t debugPrint;
    statemachineSMStates_t prevState;
    statemachineSMStates_t currState;
    statemachineSMStates_t nextState;

    void update_stateVars(void);
    void request_nextState(statemachineSMStates_t reqState);

    bool transition_idleToProcessMsg(void);

    bool transition_idleToProcessData(void);
    bool transition_processDataToSendSF(void);
    bool transition_processDataToSendFF(void);
    bool transition_sendFFToWaitFC(void);
    bool transition_waitFCToSendCF(void);
    bool transition_sendCFToDelayCF(void);


    void run_idleState(void);
    

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