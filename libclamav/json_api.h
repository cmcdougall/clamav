/*
 * JSON Object API
 * 
 * Copyright (C) 2014 Cisco Systems, Inc.
 * 
 * Authors: Kevin Lin
 * 
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License version 2 as published by the
 * Free Software Foundation.
 * 
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 * 
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 51
 * Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef __JSON_C_H__
#define __JSON_C_H__

#if HAVE_CONFIG_H
#include "clamav-config.h"
#endif

#if HAVE_JSON
#include "json/json.h"
#endif

#include "cltypes.h"
#include "others.h"

#if HAVE_JSON
int cli_jsonnull(json_object *obj, const char* key);
int cli_jsonstr(json_object *obj, const char* key, const char* s);
int cli_jsonint(json_object *obj, const char* key, int32_t i);
int cli_jsonint64(json_object *obj, const char* key, int64_t i);
int cli_jsonbool(json_object *obj, const char* key, int i);
int cli_jsondouble(json_object *obj, const char* key, double d);
#else
#define nojson_func cli_dbgmsg

/* internal functions */
int cli_json_nojson();

int cli_jsonnull_nojson(const char* key);
int cli_jsonint_nojson(const char* key, int32_t i);
int cli_jsonint64_nojson(const char* key, int64_t i);
int cli_jsonbool_nojson(const char* key, int i);
int cli_jsondouble_nojson(const char* key, double d);

#define cli_jsonnull(o,n)       cli_jsonnull_nojson(n)
#define cli_jsonstr(o,n,s)      cli_jsonstr_nojson(n,s)
#define cli_jsonint(o,n,i)      cli_jsonint_nojson(n,i)
#define cli_jsonint64(o,n,i)    cli_jsonint64_nojson(n,i)
#define cli_jsonbool(o,n,b)     cli_jsonbool_nojson(n,b)
#define cli_jsondouble(o,n,d)   cli_jsondouble_nojson(n,d)
#endif

#endif /*__JSON_C_H__*/
