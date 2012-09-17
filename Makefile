CC=gcc
PHPPATH=/home/tony/php310

CFLAGS = -I$(PHPPATH)/include/php \
		 -I$(PHPPATH)/include/php/Zend \
		 -I$(PHPPATH)/include/php/TSRM \
		 -I$(PHPPATH)/include/php/main \
		 -I$(PHPPATH)/include/php/sapi \
		 -I$(PHPPATH)/include/php/sapi/embed \
		 -Wall -g

LDFLAGS = -L$(PHPPATH)/lib -lphp5

ALL:
	$(CC) opcode_handlers.c opcodes_dumper.c -o opd $(CFLAGS) $(LDFLAGS)
