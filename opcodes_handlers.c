/*
  +----------------------------------------------------------------------+
  | PHP Opcodes Hander Dumper                                            |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: Er  <er@zhangabc.com>                                        |
  +----------------------------------------------------------------------+
   $Id$
 */

#include <stdio.h>
#include "sapi/embed/php_embed.h"
#include "opcodes_handlers.h"

char handler_name[100] = "error handler file.";

static zend_uchar zend_user_opcodes[256] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255}; 

static int get_opcode_handler_index(zend_uchar opcode, zend_op* op)
{
    static const int zend_vm_decode[] = {
        _UNUSED_CODE, /* 0              */
        _CONST_CODE,  /* 1 = IS_CONST   */
        _TMP_CODE,    /* 2 = IS_TMP_VAR */
        _UNUSED_CODE, /* 3              */
        _VAR_CODE,    /* 4 = IS_VAR     */
        _UNUSED_CODE, /* 5              */
        _UNUSED_CODE, /* 6              */
        _UNUSED_CODE, /* 7              */
        _UNUSED_CODE, /* 8 = IS_UNUSED  */
        _UNUSED_CODE, /* 9              */
        _UNUSED_CODE, /* 10             */
        _UNUSED_CODE, /* 11             */
        _UNUSED_CODE, /* 12             */                                                                                                                                                                                     
        _UNUSED_CODE, /* 13             */
        _UNUSED_CODE, /* 14             */
        _UNUSED_CODE, /* 15             */
        _CV_CODE      /* 16 = IS_CV     */
    };    
    return opcode * 25 + zend_vm_decode[op->op1.op_type] * 5 + zend_vm_decode[op->op2.op_type];
}

void search_handler_name(int line){
    FILE * hFile;
    int i = 0;

    //char *PHP_HANDLER_FILE[]= "opcodes_handlers_php5_310";
    char php_handlers_file[55] ;
    sprintf(php_handlers_file, "php_%d_%d_opcodes_handlers", PHP_MAJOR_VERSION, PHP_MINOR_VERSION);
    
    hFile = fopen(php_handlers_file, "r");
    if (hFile == NULL) {
        return ;
    }
    for(i = 0; i<=line ; i++){
        fgets(handler_name, 100, hFile);
    }
    fclose(hFile);
    i = strlen(handler_name) - 1;

    handler_name[i] = 0;
}

char * get_handler(zend_op* op){
    int opcode_handler;
    char * name;
    opcode_handler = get_opcode_handler_index(zend_user_opcodes[op->opcode], op);
    search_handler_name(opcode_handler);
    name = handler_name;

    return name;
}
