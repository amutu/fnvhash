# contrib/zh_parser/Makefile

longlong := $(shell make -f Makefile.fnv longlong.h)
libfnv := $(shell make -f Makefile.fnv libfnv.a)

EXTRA_CLEAN = longlong.h hash_32a.o hash_32.o hash_64a.o hash_64.o libfnv.a test_fnv.o

MODULE_big = fnvhash
OBJS = fnvhash.o

EXTENSION = fnvhash
DATA = fnvhash--1.0.sql fnvhash--unpackaged--1.0.sql

REGRESS = fnvhash

#PG_CPPFLAGS = -I$(SCWS_HOME)/include/scws 
SHLIB_LINK = -lfnv -L.

PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)
