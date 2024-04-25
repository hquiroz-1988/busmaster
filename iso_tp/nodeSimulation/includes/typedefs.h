/**
 ********************************************************************************
 * @file    file_name.h
 * @author  Hugo Quiroz
 * @date    2024-04-04 18:43:30
 * @brief   description
 ********************************************************************************
 */

#ifndef FILE_NAME_H
#define FILE_NAME_H

/************************************
 * INCLUDES
 ************************************/
#include <stdint.h>
#include <stdbool.h>

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
    SUCCESS,
    NULLPOINTER_ARG,
    ERROR,

}eRetVal_t;

typedef uint32_t (*debugFunctionPtr_t)(const char *format, ...);

/************************************
 * EXPORTED VARIABLES
 ************************************/

/************************************
 * GLOBAL FUNCTION PROTOTYPES
 ************************************/


#ifdef __cplusplus
}
#endif

#endif //FILE_NAME_H