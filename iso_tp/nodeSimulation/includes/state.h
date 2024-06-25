/**
 ********************************************************************************
 * @file    state.h
 * @author  Hugo Quiroz
 * @date    2024-04-04 18:11:57
 * @brief   description
 ********************************************************************************
 */

#ifndef STATE_H
#define STATE_H

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

class State
{
    public:
    void run(void);
    State(StateMachine &obj) : smObj(obj) {}

    private:

    virtual void enterFunction(void);
    virtual void runFunction(void);
    virtual void gateFunction(void);
    virtual void exitFunction(void);

    const  StateMachine& smObj;

    
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

#endif //STATE_H