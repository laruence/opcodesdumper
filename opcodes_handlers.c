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
  |         Xinchen Hui <laruence@gmail.com>                             |
  +----------------------------------------------------------------------+
   $Id$
 */

#include <stdio.h>
#include "sapi/embed/php_embed.h"
#include "opcodes_handlers.h"

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

    return opcode * 25 + zend_vm_decode[op->op1_type] * 5 + zend_vm_decode[op->op2_type];
}

const char * get_handler(zend_op* op){
    char *name;
    int opcode_handler;
    opcode_handler = get_opcode_handler_index(op->opcode, op);
    if (opcode_handler >= sizeof(php_handlers_name)) {
        return "Unknow";
    }
    return php_handlers_name[opcode_handler];
}

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
