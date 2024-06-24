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
#include "statemachine.h"

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
    ISOTPSM_NO_STATE,
    ISOTPSM_IDLE_STATE,

    ISOTPSM_PROCESS_DATA_STATE,
    ISOTPSM_SEND_SF_STATE,
    ISOTPSM_SEND_FF_STATE,
    ISOTPSM_WAIT_FC_STATE,
    ISOTPSM_SEND_CF_STATE,
    ISOTPSM_DELAY_CF_STATE,

    ISOTPSM_PROCESS_MSG_STATE,
    ISOTPSM_EXTRACT_SF_STATE,
    ISOTPSM_EXTRACT_FF_STATE,
    ISOTPSM_SEND_FC_STATE,
    ISOTPSM_WAIT_MSG_STATE,
    ISOTPSM_EXTRACT_CF_STATE,
    ISOTPSM_OUTPUT_DATA_STATE,
}isotpSMStates_t;


class Isotp : public StateMachine
{
    public:
    eRetVal_t debugFunctionCallback(debugFunctionPtr_t dbgFuncPtr);
    eRetVal_t testPrint(void);
    eRetVal_t stateMachineRun(void);

    private:
    debugFunctionPtr_t debugPrint;
    isotpSMStates_t prevState;
    isotpSMStates_t currState;
    isotpSMStates_t nextState;

    void update_stateVars(void);
    void request_nextState(isotpSMStates_t reqState);

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

#endif //ISOTP_H