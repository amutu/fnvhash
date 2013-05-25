#include "postgres.h"
#include <string.h>
#include "fmgr.h"
#include "utils/geo_decls.h"

#include "fnv.h"

#ifdef PG_MODULE_MAGIC
PG_MODULE_MAGIC;
#endif

PG_FUNCTION_INFO_V1(fnv032);
	Datum
fnv032(PG_FUNCTION_ARGS)
{
	bytea     *t = PG_GETARG_BYTEA_P(0);
	void     *d =VARDATA(t);
	int64 hashval = fnv_32_buf(d, VARSIZE(t) - VARHDRSZ , FNV0_32_INIT); 
	PG_RETURN_INT64(hashval);
}

PG_FUNCTION_INFO_V1(fnv132);
	Datum
fnv132(PG_FUNCTION_ARGS)
{
	bytea     *t = PG_GETARG_BYTEA_P(0);
	void     *d =VARDATA(t);
	int64 hashval = fnv_32_buf(d, VARSIZE(t) - VARHDRSZ , FNV1_32_INIT); 
	PG_RETURN_INT64(hashval);
}

PG_FUNCTION_INFO_V1(fnv1a32);
	Datum
fnv1a32(PG_FUNCTION_ARGS)
{
	bytea     *t = PG_GETARG_BYTEA_P(0);
	void     *d =VARDATA(t);
	int64 hashval = fnv_32a_buf(d, VARSIZE(t) - VARHDRSZ , FNV1_32A_INIT); 
	PG_RETURN_INT64(hashval);
}

PG_FUNCTION_INFO_V1(fnv064);
	Datum
fnv064(PG_FUNCTION_ARGS)
{
	char hex[32];
	bytea     *t = PG_GETARG_BYTEA_P(0);
	void     *d =VARDATA(t);
	int len = sizeof(uint64) * 2 + 2;// "\x" + 64bit hex
	uint64 hashval = fnv_64_buf(d, VARSIZE(t) - VARHDRSZ, FNV0_64_INIT); 
	text *new_b = NULL;
	snprintf(hex,len + 1,"\\x%lx",hashval);   

	//ereport(INFO,(errcode(0),errmsg("hex : \"%s\"",hex)));	

	new_b = (text *) palloc(VARHDRSZ + len);
	SET_VARSIZE(new_b, VARHDRSZ + len);
	memcpy((void *) VARDATA(new_b), /* destination */
			(void *) hex,     /* source */
			len);  /* how many bytes */
	PG_RETURN_TEXT_P(new_b);

}
PG_FUNCTION_INFO_V1(fnv164);
	Datum
fnv164(PG_FUNCTION_ARGS)
{
	char hex[32];
	bytea     *t = PG_GETARG_BYTEA_P(0);
	void     *d =VARDATA(t);
	int len = sizeof(uint64) * 2 + 2;// "\x" + 64bit hex
	uint64 hashval = fnv_64_buf(d, VARSIZE(t) - VARHDRSZ, FNV1_64_INIT); 
        text *new_b = NULL;
	snprintf(hex,len + 1,"\\x%lx",hashval);   

	//ereport(INFO,(errcode(0),errmsg("hex : \"%s\"",hex)));	

	new_b = (text *) palloc(VARHDRSZ + len);
	SET_VARSIZE(new_b, VARHDRSZ + len);
	memcpy((void *) VARDATA(new_b), /* destination */
			(void *) hex,     /* source */
			len);  /* how many bytes */
	PG_RETURN_TEXT_P(new_b);

}
PG_FUNCTION_INFO_V1(fnv1a64);
	Datum
fnv1a64(PG_FUNCTION_ARGS)
{
	char hex[32];
	bytea     *t = PG_GETARG_BYTEA_P(0);
	void     *d =VARDATA(t);
	int len = sizeof(uint64) * 2 + 2;// "\x" + 64bit hex
	uint64 hashval = fnv_64a_buf(d, VARSIZE(t) - VARHDRSZ, FNV1A_64_INIT); 
	text *new_b = NULL;
	snprintf(hex,len + 1,"\\x%lx",hashval);   

	//ereport(INFO,(errcode(0),errmsg("hex : \"%s\"",hex)));	

	new_b = (text *) palloc(VARHDRSZ + len);
	SET_VARSIZE(new_b, VARHDRSZ + len);
	memcpy((void *) VARDATA(new_b), /* destination */
			(void *) hex,     /* source */
			len);  /* how many bytes */
	PG_RETURN_TEXT_P(new_b);

}
