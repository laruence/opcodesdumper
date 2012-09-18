/*
  +----------------------------------------------------------------------+
  | PHP Opcodes Dumper                                                   |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: Laruence  <laruence@gmail.com>                               |
  +----------------------------------------------------------------------+
   $Id$
 */

#include <stdio.h>
#include "sapi/embed/php_embed.h"
#include "main/php_version.h"
#define BUFFER_LEN 11

char *opname(zend_uchar opcode){
	switch(opcode) {
		case ZEND_NOP: return "ZEND_NOP"; break;
		case ZEND_ADD: return "ZEND_ADD"; break;
		case ZEND_SUB: return "ZEND_SUB"; break;
		case ZEND_MUL: return "ZEND_MUL"; break;
		case ZEND_DIV: return "ZEND_DIV"; break;
		case ZEND_MOD: return "ZEND_MOD"; break;
		case ZEND_SL: return "ZEND_SL"; break;
		case ZEND_SR: return "ZEND_SR"; break;
		case ZEND_CONCAT: return "ZEND_CONCAT"; break;
		case ZEND_BW_OR: return "ZEND_BW_OR"; break;
		case ZEND_BW_AND: return "ZEND_BW_AND"; break;
		case ZEND_BW_XOR: return "ZEND_BW_XOR"; break;
		case ZEND_BW_NOT: return "ZEND_BW_NOT"; break;
		case ZEND_BOOL_NOT: return "ZEND_BOOL_NOT"; break;
		case ZEND_BOOL_XOR: return "ZEND_BOOL_XOR"; break;
		case ZEND_IS_IDENTICAL: return "ZEND_IS_IDENTICAL"; break;
		case ZEND_IS_NOT_IDENTICAL: return "ZEND_IS_NOT_IDENTICAL"; break;
		case ZEND_IS_EQUAL: return "ZEND_IS_EQUAL"; break;
		case ZEND_IS_NOT_EQUAL: return "ZEND_IS_NOT_EQUAL"; break;
		case ZEND_IS_SMALLER: return "ZEND_IS_SMALLER"; break;
		case ZEND_IS_SMALLER_OR_EQUAL: return "ZEND_IS_SMALLER_OR_EQUAL"; break;
		case ZEND_CAST: return "ZEND_CAST"; break;
		case ZEND_QM_ASSIGN: return "ZEND_QM_ASSIGN"; break;
		case ZEND_ASSIGN_ADD: return "ZEND_ASSIGN_ADD"; break;
		case ZEND_ASSIGN_SUB: return "ZEND_ASSIGN_SUB"; break;
		case ZEND_ASSIGN_MUL: return "ZEND_ASSIGN_MUL"; break;
		case ZEND_ASSIGN_DIV: return "ZEND_ASSIGN_DIV"; break;
		case ZEND_ASSIGN_MOD: return "ZEND_ASSIGN_MOD"; break;
		case ZEND_ASSIGN_SL: return "ZEND_ASSIGN_SL"; break;
		case ZEND_ASSIGN_SR: return "ZEND_ASSIGN_SR"; break;
		case ZEND_ASSIGN_CONCAT: return "ZEND_ASSIGN_CONCAT"; break;
		case ZEND_ASSIGN_BW_OR: return "ZEND_ASSIGN_BW_OR"; break;
		case ZEND_ASSIGN_BW_AND: return "ZEND_ASSIGN_BW_AND"; break;
		case ZEND_ASSIGN_BW_XOR: return "ZEND_ASSIGN_BW_XOR"; break;
		case ZEND_PRE_INC: return "ZEND_PRE_INC"; break;
		case ZEND_PRE_DEC: return "ZEND_PRE_DEC"; break;
		case ZEND_POST_INC: return "ZEND_POST_INC"; break;
		case ZEND_POST_DEC: return "ZEND_POST_DEC"; break;
		case ZEND_ASSIGN: return "ZEND_ASSIGN"; break;
		case ZEND_ASSIGN_REF: return "ZEND_ASSIGN_REF"; break;
		case ZEND_ECHO: return "ZEND_ECHO"; break;
		case ZEND_PRINT: return "ZEND_PRINT"; break;
		case ZEND_JMP: return "ZEND_JMP"; break;
		case ZEND_JMPZ: return "ZEND_JMPZ"; break;
		case ZEND_JMPNZ: return "ZEND_JMPNZ"; break;
		case ZEND_JMPZNZ: return "ZEND_JMPZNZ"; break;
		case ZEND_JMPZ_EX: return "ZEND_JMPZ_EX"; break;
		case ZEND_JMPNZ_EX: return "ZEND_JMPNZ_EX"; break;
		case ZEND_CASE: return "ZEND_CASE"; break;
		case ZEND_SWITCH_FREE: return "ZEND_SWITCH_FREE"; break;
		case ZEND_BRK: return "ZEND_BRK"; break;
		case ZEND_CONT: return "ZEND_CONT"; break;
		case ZEND_BOOL: return "ZEND_BOOL"; break;
		case ZEND_INIT_STRING: return "ZEND_INIT_STRING"; break;
		case ZEND_ADD_CHAR: return "ZEND_ADD_CHAR"; break;
		case ZEND_ADD_STRING: return "ZEND_ADD_STRING"; break;
		case ZEND_ADD_VAR: return "ZEND_ADD_VAR"; break;
		case ZEND_BEGIN_SILENCE: return "ZEND_BEGIN_SILENCE"; break;
		case ZEND_END_SILENCE: return "ZEND_END_SILENCE"; break;
		case ZEND_INIT_FCALL_BY_NAME: return "ZEND_INIT_FCALL_BY_NAME"; break;
		case ZEND_DO_FCALL: return "ZEND_DO_FCALL"; break;
		case ZEND_DO_FCALL_BY_NAME: return "ZEND_DO_FCALL_BY_NAME"; break;
		case ZEND_RETURN: return "ZEND_RETURN"; break;
		case ZEND_RECV: return "ZEND_RECV"; break;
		case ZEND_RECV_INIT: return "ZEND_RECV_INIT"; break;
		case ZEND_SEND_VAL: return "ZEND_SEND_VAL"; break;
		case ZEND_SEND_VAR: return "ZEND_SEND_VAR"; break;
		case ZEND_SEND_REF: return "ZEND_SEND_REF"; break;
		case ZEND_NEW: return "ZEND_NEW"; break;
		case ZEND_FREE: return "ZEND_FREE"; break;
		case ZEND_INIT_ARRAY: return "ZEND_INIT_ARRAY"; break;
		case ZEND_ADD_ARRAY_ELEMENT: return "ZEND_ADD_ARRAY_ELEMENT"; break;
		case ZEND_INCLUDE_OR_EVAL: return "ZEND_INCLUDE_OR_EVAL"; break;
		case ZEND_UNSET_VAR: return "ZEND_UNSET_VAR"; break;
		case ZEND_UNSET_DIM: return "ZEND_UNSET_DIM"; break;
		case ZEND_UNSET_OBJ: return "ZEND_UNSET_OBJ"; break;
		case ZEND_FE_RESET: return "ZEND_FE_RESET"; break;
		case ZEND_FE_FETCH: return "ZEND_FE_FETCH"; break;
		case ZEND_EXIT: return "ZEND_EXIT"; break;
		case ZEND_FETCH_R: return "ZEND_FETCH_R"; break;
		case ZEND_FETCH_DIM_R: return "ZEND_FETCH_DIM_R"; break;
		case ZEND_FETCH_OBJ_R: return "ZEND_FETCH_OBJ_R"; break;
		case ZEND_FETCH_W: return "ZEND_FETCH_W"; break;
		case ZEND_FETCH_DIM_W: return "ZEND_FETCH_DIM_W"; break;
		case ZEND_FETCH_OBJ_W: return "ZEND_FETCH_OBJ_W"; break;
		case ZEND_FETCH_RW: return "ZEND_FETCH_RW"; break;
		case ZEND_FETCH_DIM_RW: return "ZEND_FETCH_DIM_RW"; break;
		case ZEND_FETCH_OBJ_RW: return "ZEND_FETCH_OBJ_RW"; break;
		case ZEND_FETCH_IS: return "ZEND_FETCH_IS"; break;
		case ZEND_FETCH_DIM_IS: return "ZEND_FETCH_DIM_IS"; break;
		case ZEND_FETCH_OBJ_IS: return "ZEND_FETCH_OBJ_IS"; break;
		case ZEND_FETCH_FUNC_ARG: return "ZEND_FETCH_FUNC_ARG"; break;
		case ZEND_FETCH_DIM_FUNC_ARG: return "ZEND_FETCH_DIM_FUNC_ARG"; break;
		case ZEND_FETCH_OBJ_FUNC_ARG: return "ZEND_FETCH_OBJ_FUNC_ARG"; break;
		case ZEND_FETCH_UNSET: return "ZEND_FETCH_UNSET"; break;
		case ZEND_FETCH_DIM_UNSET: return "ZEND_FETCH_DIM_UNSET"; break;
		case ZEND_FETCH_OBJ_UNSET: return "ZEND_FETCH_OBJ_UNSET"; break;
		case ZEND_FETCH_DIM_TMP_VAR: return "ZEND_FETCH_DIM_TMP_VAR"; break;
		case ZEND_FETCH_CONSTANT: return "ZEND_FETCH_CONSTANT"; break;
		case ZEND_EXT_STMT: return "ZEND_EXT_STMT"; break;
		case ZEND_EXT_FCALL_BEGIN: return "ZEND_EXT_FCALL_BEGIN"; break;
		case ZEND_EXT_FCALL_END: return "ZEND_EXT_FCALL_END"; break;
		case ZEND_EXT_NOP: return "ZEND_EXT_NOP"; break;
		case ZEND_TICKS: return "ZEND_TICKS"; break;
		case ZEND_SEND_VAR_NO_REF: return "ZEND_SEND_VAR_NO_REF"; break;
		case ZEND_CATCH: return "ZEND_CATCH"; break;
		case ZEND_THROW: return "ZEND_THROW"; break;
		case ZEND_FETCH_CLASS: return "ZEND_FETCH_CLASS"; break;
		case ZEND_CLONE: return "ZEND_CLONE"; break;
		case ZEND_INIT_METHOD_CALL: return "ZEND_INIT_METHOD_CALL"; break;
		case ZEND_INIT_STATIC_METHOD_CALL: return "ZEND_INIT_STATIC_METHOD_CALL"; break;
		case ZEND_ISSET_ISEMPTY_VAR: return "ZEND_ISSET_ISEMPTY_VAR"; break;
		case ZEND_ISSET_ISEMPTY_DIM_OBJ: return "ZEND_ISSET_ISEMPTY_DIM_OBJ"; break;
		case ZEND_PRE_INC_OBJ: return "ZEND_PRE_INC_OBJ"; break;
		case ZEND_PRE_DEC_OBJ: return "ZEND_PRE_DEC_OBJ"; break;
		case ZEND_POST_INC_OBJ: return "ZEND_POST_INC_OBJ"; break;
		case ZEND_POST_DEC_OBJ: return "ZEND_POST_DEC_OBJ"; break;
		case ZEND_ASSIGN_OBJ: return "ZEND_ASSIGN_OBJ"; break;
		case ZEND_INSTANCEOF: return "ZEND_INSTANCEOF"; break;
		case ZEND_DECLARE_CLASS: return "ZEND_DECLARE_CLASS"; break;
		case ZEND_DECLARE_INHERITED_CLASS: return "ZEND_DECLARE_INHERITED_CLASS"; break;
		case ZEND_DECLARE_FUNCTION: return "ZEND_DECLARE_FUNCTION"; break;
		case ZEND_RAISE_ABSTRACT_ERROR: return "ZEND_RAISE_ABSTRACT_ERROR"; break;
		case ZEND_ADD_INTERFACE: return "ZEND_ADD_INTERFACE"; break;
		case ZEND_VERIFY_ABSTRACT_CLASS: return "ZEND_VERIFY_ABSTRACT_CLASS"; break;
		case ZEND_ASSIGN_DIM: return "ZEND_ASSIGN_DIM"; break;
		case ZEND_ISSET_ISEMPTY_PROP_OBJ: return "ZEND_ISSET_ISEMPTY_PROP_OBJ"; break;
		case ZEND_HANDLE_EXCEPTION: return "ZEND_HANDLE_EXCEPTION"; break;
		case ZEND_USER_OPCODE: return "ZEND_USER_OPCODE"; break;
		default: return "UNKNOWN"; break;
	}
}

char *format_zval(zval *z)
{
	static char buffer[BUFFER_LEN];

	switch(z->type) {
		case IS_NULL:
			return "NULL";
		case IS_LONG:
		case IS_BOOL:
			snprintf(buffer, BUFFER_LEN, "%5d", z->value.lval);
			return buffer;
		case IS_DOUBLE:
			snprintf(buffer, BUFFER_LEN, "%5f", z->value.dval);
			return buffer;
		case IS_STRING:
		case IS_CONSTANT:
			snprintf(buffer, BUFFER_LEN, "\"%5s\"", z->value.str.val);
			return buffer;
		case IS_ARRAY:
		case IS_CONSTANT_ARRAY:
			return "Array";
		case IS_OBJECT:
            return "Object";
		case IS_RESOURCE:
            return "Resource";
		default:
			return "unknown";
	}
}

char * format_znode(znode *n){
	static char buffer[BUFFER_LEN];

	switch (n->op_type) {
		case IS_CONST:
			return format_zval(&n->u.constant);
			break;
		case IS_VAR:
			snprintf(buffer, BUFFER_LEN, "$%d",  n->u.var/sizeof(temp_variable));
			return buffer;
			break;
		case IS_TMP_VAR:
			snprintf(buffer, BUFFER_LEN, "~%d",  n->u.var/sizeof(temp_variable));
			return buffer;
			break;
		default:
			return "";
			break;
	}
}

void dump_op(zend_op *op, int num){
	printf("%6d|%6d|%20s|%50s|%10s|%10s|%6s|\n", num, op->lineno,
			opname(op->opcode),
            get_handler(op),
			format_znode(&op->op1),
			format_znode(&op->op2),
			format_znode(&op->result)) ;
}

void dump_op_array(zend_op_array *op_array){
	if(op_array) {
        //TOPO format output ... >_<
		int i;
        char *buf;
        char *top;
		memset(memset((buf=malloc(116))+115, 0, 1)-115, '=', 115);
		memset(memset((top=malloc(116))+115, 0, 1)-115, '-', 115);
		printf("%s\n",top);
		printf("%6s|%6s|%20s|%50s|%10s|%10s|%6s|\n", "opnum", "line", "opcode", "op_handler", "op1", "op2", "result");
		printf("%.6s|%.6s|%.20s|%.50s|%.10s|%.10s|%.6s|\n", buf, buf, buf, buf, buf, buf,buf);
		for(i = 0; i < op_array->last; i++) {
			dump_op(&op_array->opcodes[i], i);
		}
		printf("%s\n",top);
        free(buf);
        free(top);
	}
}

int main(int argc, char **argv){
	zend_op_array *op_array;
	zend_file_handle file_handle;

	if(argc != 2) {
		printf("usage:  op_dumper <script>\n");
		return 1;
	}
	PHP_EMBED_START_BLOCK(argc, argv);
	printf("Script: %s   PHP version: %d.%d\n", argv[1], PHP_MAJOR_VERSION, PHP_MINOR_VERSION);
	file_handle.filename = argv[1];
	file_handle.free_filename = 0;
	file_handle.type = ZEND_HANDLE_FILENAME;
	file_handle.opened_path = NULL;
	op_array =  zend_compile_file(&file_handle, ZEND_INCLUDE TSRMLS_CC);
	if(!op_array) {
		printf("Error parsing script: %s\n", file_handle.filename);
		return 1;
	}
	//printf(" %s\n", EX(opline));
	dump_op_array(op_array);
    destroy_op_array(op_array TSRMLS_CC);
    efree(op_array);
	PHP_EMBED_END_BLOCK();
	return 0;
}
