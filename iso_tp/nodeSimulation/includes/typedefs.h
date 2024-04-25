/**
 ********************************************************************************
 * @file    typedefs.h
 * @author  Hugo Quiroz
 * @date    2024-04-04 18:43:30
 * @brief   description
 ********************************************************************************
 */

#ifndef TYPEDEFS_H
#define TYPEDEFS_H

/************************************
 * INCLUDES
 ************************************/
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

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
    ERET_SUCCESS,
    ERET_NULLPTR,
    ERET_ERROR,

}eRetVal_t;

typedef uint32_t (*debugFunctionPtr_t)(char *format, ...);

/************************************
 * EXPORTED VARIABLES
 ************************************/

/************************************
 * GLOBAL FUNCTION PROTOTYPES
 ************************************/


#ifdef __cplusplus
}
#endif

#endif //TYPEDEFS_H