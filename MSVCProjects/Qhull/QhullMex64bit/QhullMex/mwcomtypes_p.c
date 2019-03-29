

/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Sat Oct 09 00:05:12 2010
 */
/* Compiler settings for C:\Program Files\MATLAB\R2010a\extern\include\mwcomtypes.idl:
    Oicf, W1, Zp8, env=Win64 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#if defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/
#pragma warning( disable: 4152 )  /* function/data pointer conversion in expression */

#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 475
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif // __RPCPROXY_H_VERSION__


#include "mwcomtypes_h.h"

#define TYPE_FORMAT_STRING_SIZE   1271                              
#define PROC_FORMAT_STRING_SIZE   3649                              
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   2            

typedef struct _mwcomtypes_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } mwcomtypes_MIDL_TYPE_FORMAT_STRING;

typedef struct _mwcomtypes_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } mwcomtypes_MIDL_PROC_FORMAT_STRING;

typedef struct _mwcomtypes_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } mwcomtypes_MIDL_EXPR_FORMAT_STRING;


static RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const mwcomtypes_MIDL_TYPE_FORMAT_STRING mwcomtypes__MIDL_TypeFormatString;
extern const mwcomtypes_MIDL_PROC_FORMAT_STRING mwcomtypes__MIDL_ProcFormatString;
extern const mwcomtypes_MIDL_EXPR_FORMAT_STRING mwcomtypes__MIDL_ExprFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IObjectInfo_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IObjectInfo_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IMWArrayFormatFlags_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IMWArrayFormatFlags_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IMWDataConversionFlags_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IMWDataConversionFlags_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IMWFlags_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IMWFlags_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IMWField_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IMWField_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IMWStruct_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IMWStruct_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IMWComplex_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IMWComplex_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IMWSparse_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IMWSparse_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IMWArg_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IMWArg_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IMWEnumVararg_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IMWEnumVararg_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IMWMethodArgInfo_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IMWMethodArgInfo_ProxyInfo;


extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ];

#if !defined(__RPC_WIN64__)
#error  Invalid build platform for this stub.
#endif

static const mwcomtypes_MIDL_PROC_FORMAT_STRING mwcomtypes__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure GetIsRange */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x3 ),	/* 3 */
/*  8 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 10 */	NdrFcShort( 0x8 ),	/* 8 */
/* 12 */	NdrFcShort( 0x22 ),	/* 34 */
/* 14 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 16 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */
/* 24 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter n */

/* 26 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 28 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 30 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pbIsRange */

/* 32 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 34 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 36 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 38 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 40 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 42 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetIsObject */

/* 44 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 46 */	NdrFcLong( 0x0 ),	/* 0 */
/* 50 */	NdrFcShort( 0x4 ),	/* 4 */
/* 52 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 54 */	NdrFcShort( 0x8 ),	/* 8 */
/* 56 */	NdrFcShort( 0x22 ),	/* 34 */
/* 58 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 60 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 62 */	NdrFcShort( 0x0 ),	/* 0 */
/* 64 */	NdrFcShort( 0x0 ),	/* 0 */
/* 66 */	NdrFcShort( 0x0 ),	/* 0 */
/* 68 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter n */

/* 70 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 72 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 74 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pbIsObject */

/* 76 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 78 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 80 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 82 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 84 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 86 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_CoerceNumericToType */


	/* Procedure get_InputArrayFormat */

/* 88 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 90 */	NdrFcLong( 0x0 ),	/* 0 */
/* 94 */	NdrFcShort( 0x7 ),	/* 7 */
/* 96 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 98 */	NdrFcShort( 0x0 ),	/* 0 */
/* 100 */	NdrFcShort( 0x22 ),	/* 34 */
/* 102 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 104 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 106 */	NdrFcShort( 0x0 ),	/* 0 */
/* 108 */	NdrFcShort( 0x0 ),	/* 0 */
/* 110 */	NdrFcShort( 0x0 ),	/* 0 */
/* 112 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pType */


	/* Parameter pInputFmt */

/* 114 */	NdrFcShort( 0x2010 ),	/* Flags:  out, srv alloc size=8 */
/* 116 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 118 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Return value */


	/* Return value */

/* 120 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 122 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 124 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_CoerceNumericToType */


	/* Procedure put_InputArrayFormat */

/* 126 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 128 */	NdrFcLong( 0x0 ),	/* 0 */
/* 132 */	NdrFcShort( 0x8 ),	/* 8 */
/* 134 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 136 */	NdrFcShort( 0x6 ),	/* 6 */
/* 138 */	NdrFcShort( 0x8 ),	/* 8 */
/* 140 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 142 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 144 */	NdrFcShort( 0x0 ),	/* 0 */
/* 146 */	NdrFcShort( 0x0 ),	/* 0 */
/* 148 */	NdrFcShort( 0x0 ),	/* 0 */
/* 150 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Type */


	/* Parameter InputFmt */

/* 152 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 154 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 156 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 158 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 160 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 162 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_NumRows */


	/* Procedure get_NumberOfFields */


	/* Procedure get_InputArrayIndFlag */

/* 164 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 166 */	NdrFcLong( 0x0 ),	/* 0 */
/* 170 */	NdrFcShort( 0x9 ),	/* 9 */
/* 172 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 174 */	NdrFcShort( 0x0 ),	/* 0 */
/* 176 */	NdrFcShort( 0x24 ),	/* 36 */
/* 178 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 180 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 182 */	NdrFcShort( 0x0 ),	/* 0 */
/* 184 */	NdrFcShort( 0x0 ),	/* 0 */
/* 186 */	NdrFcShort( 0x0 ),	/* 0 */
/* 188 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pnRows */


	/* Parameter pnFields */


	/* Parameter pnInputInd */

/* 190 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 192 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 194 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 196 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 198 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 200 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_NumRows */


	/* Procedure put_InputArrayIndFlag */

/* 202 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 204 */	NdrFcLong( 0x0 ),	/* 0 */
/* 208 */	NdrFcShort( 0xa ),	/* 10 */
/* 210 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 212 */	NdrFcShort( 0x8 ),	/* 8 */
/* 214 */	NdrFcShort( 0x8 ),	/* 8 */
/* 216 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 218 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 220 */	NdrFcShort( 0x0 ),	/* 0 */
/* 222 */	NdrFcShort( 0x0 ),	/* 0 */
/* 224 */	NdrFcShort( 0x0 ),	/* 0 */
/* 226 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter nRows */


	/* Parameter nInputInd */

/* 228 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 230 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 232 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 234 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 236 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 238 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_OutputArrayFormat */

/* 240 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 242 */	NdrFcLong( 0x0 ),	/* 0 */
/* 246 */	NdrFcShort( 0xb ),	/* 11 */
/* 248 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 250 */	NdrFcShort( 0x0 ),	/* 0 */
/* 252 */	NdrFcShort( 0x22 ),	/* 34 */
/* 254 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 256 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 258 */	NdrFcShort( 0x0 ),	/* 0 */
/* 260 */	NdrFcShort( 0x0 ),	/* 0 */
/* 262 */	NdrFcShort( 0x0 ),	/* 0 */
/* 264 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pOutputFmt */

/* 266 */	NdrFcShort( 0x2010 ),	/* Flags:  out, srv alloc size=8 */
/* 268 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 270 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Return value */

/* 272 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 274 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 276 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_OutputArrayFormat */

/* 278 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 280 */	NdrFcLong( 0x0 ),	/* 0 */
/* 284 */	NdrFcShort( 0xc ),	/* 12 */
/* 286 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 288 */	NdrFcShort( 0x6 ),	/* 6 */
/* 290 */	NdrFcShort( 0x8 ),	/* 8 */
/* 292 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 294 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 296 */	NdrFcShort( 0x0 ),	/* 0 */
/* 298 */	NdrFcShort( 0x0 ),	/* 0 */
/* 300 */	NdrFcShort( 0x0 ),	/* 0 */
/* 302 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter OutputFmt */

/* 304 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 306 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 308 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Return value */

/* 310 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 312 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 314 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Indirection */


	/* Procedure get_DateBias */


	/* Procedure get_OutputArrayIndFlag */

/* 316 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 318 */	NdrFcLong( 0x0 ),	/* 0 */
/* 322 */	NdrFcShort( 0xd ),	/* 13 */
/* 324 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 326 */	NdrFcShort( 0x0 ),	/* 0 */
/* 328 */	NdrFcShort( 0x24 ),	/* 36 */
/* 330 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 332 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 334 */	NdrFcShort( 0x0 ),	/* 0 */
/* 336 */	NdrFcShort( 0x0 ),	/* 0 */
/* 338 */	NdrFcShort( 0x0 ),	/* 0 */
/* 340 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pnInd */


	/* Parameter pnBias */


	/* Parameter pnOutputInd */

/* 342 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 344 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 346 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 348 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 350 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 352 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Skip */


	/* Procedure put_DateBias */


	/* Procedure put_OutputArrayIndFlag */

/* 354 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 356 */	NdrFcLong( 0x0 ),	/* 0 */
/* 360 */	NdrFcShort( 0xe ),	/* 14 */
/* 362 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 364 */	NdrFcShort( 0x8 ),	/* 8 */
/* 366 */	NdrFcShort( 0x8 ),	/* 8 */
/* 368 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 370 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 372 */	NdrFcShort( 0x0 ),	/* 0 */
/* 374 */	NdrFcShort( 0x0 ),	/* 0 */
/* 376 */	NdrFcShort( 0x0 ),	/* 0 */
/* 378 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter nSkipElms */


	/* Parameter nBias */


	/* Parameter nOutputInd */

/* 380 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 382 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 384 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 386 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 388 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 390 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_IsVararg */


	/* Procedure get_AutoResizeOutput */

/* 392 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 394 */	NdrFcLong( 0x0 ),	/* 0 */
/* 398 */	NdrFcShort( 0xf ),	/* 15 */
/* 400 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 402 */	NdrFcShort( 0x0 ),	/* 0 */
/* 404 */	NdrFcShort( 0x22 ),	/* 34 */
/* 406 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 408 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 410 */	NdrFcShort( 0x0 ),	/* 0 */
/* 412 */	NdrFcShort( 0x0 ),	/* 0 */
/* 414 */	NdrFcShort( 0x0 ),	/* 0 */
/* 416 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbVararg */


	/* Parameter pbResize */

/* 418 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 420 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 422 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 424 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 426 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 428 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_AutoResizeOutput */

/* 430 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 432 */	NdrFcLong( 0x0 ),	/* 0 */
/* 436 */	NdrFcShort( 0x10 ),	/* 16 */
/* 438 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 440 */	NdrFcShort( 0x6 ),	/* 6 */
/* 442 */	NdrFcShort( 0x8 ),	/* 8 */
/* 444 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 446 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 448 */	NdrFcShort( 0x0 ),	/* 0 */
/* 450 */	NdrFcShort( 0x0 ),	/* 0 */
/* 452 */	NdrFcShort( 0x0 ),	/* 0 */
/* 454 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bResize */

/* 456 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 458 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 460 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 462 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 464 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 466 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_TransposeOutput */

/* 468 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 470 */	NdrFcLong( 0x0 ),	/* 0 */
/* 474 */	NdrFcShort( 0x11 ),	/* 17 */
/* 476 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 478 */	NdrFcShort( 0x0 ),	/* 0 */
/* 480 */	NdrFcShort( 0x22 ),	/* 34 */
/* 482 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 484 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 486 */	NdrFcShort( 0x0 ),	/* 0 */
/* 488 */	NdrFcShort( 0x0 ),	/* 0 */
/* 490 */	NdrFcShort( 0x0 ),	/* 0 */
/* 492 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbTranspose */

/* 494 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 496 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 498 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 500 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 502 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 504 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_TransposeOutput */

/* 506 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 508 */	NdrFcLong( 0x0 ),	/* 0 */
/* 512 */	NdrFcShort( 0x12 ),	/* 18 */
/* 514 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 516 */	NdrFcShort( 0x6 ),	/* 6 */
/* 518 */	NdrFcShort( 0x8 ),	/* 8 */
/* 520 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 522 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 524 */	NdrFcShort( 0x0 ),	/* 0 */
/* 526 */	NdrFcShort( 0x0 ),	/* 0 */
/* 528 */	NdrFcShort( 0x0 ),	/* 0 */
/* 530 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bTranspose */

/* 532 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 534 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 536 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 538 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 540 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 542 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_InputDateFormat */

/* 544 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 546 */	NdrFcLong( 0x0 ),	/* 0 */
/* 550 */	NdrFcShort( 0x9 ),	/* 9 */
/* 552 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 554 */	NdrFcShort( 0x0 ),	/* 0 */
/* 556 */	NdrFcShort( 0x22 ),	/* 34 */
/* 558 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 560 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 562 */	NdrFcShort( 0x0 ),	/* 0 */
/* 564 */	NdrFcShort( 0x0 ),	/* 0 */
/* 566 */	NdrFcShort( 0x0 ),	/* 0 */
/* 568 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDateFmt */

/* 570 */	NdrFcShort( 0x2010 ),	/* Flags:  out, srv alloc size=8 */
/* 572 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 574 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Return value */

/* 576 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 578 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 580 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_InputDateFormat */

/* 582 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 584 */	NdrFcLong( 0x0 ),	/* 0 */
/* 588 */	NdrFcShort( 0xa ),	/* 10 */
/* 590 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 592 */	NdrFcShort( 0x6 ),	/* 6 */
/* 594 */	NdrFcShort( 0x8 ),	/* 8 */
/* 596 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 598 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 600 */	NdrFcShort( 0x0 ),	/* 0 */
/* 602 */	NdrFcShort( 0x0 ),	/* 0 */
/* 604 */	NdrFcShort( 0x0 ),	/* 0 */
/* 606 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter DateFmt */

/* 608 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 610 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 612 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Return value */

/* 614 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 616 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 618 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Type */


	/* Procedure get_OutputAsDate */

/* 620 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 622 */	NdrFcLong( 0x0 ),	/* 0 */
/* 626 */	NdrFcShort( 0xb ),	/* 11 */
/* 628 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 630 */	NdrFcShort( 0x0 ),	/* 0 */
/* 632 */	NdrFcShort( 0x22 ),	/* 34 */
/* 634 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 636 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 638 */	NdrFcShort( 0x0 ),	/* 0 */
/* 640 */	NdrFcShort( 0x0 ),	/* 0 */
/* 642 */	NdrFcShort( 0x0 ),	/* 0 */
/* 644 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pnType */


	/* Parameter pbDate */

/* 646 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 648 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 650 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 652 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 654 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 656 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_OutputAsDate */

/* 658 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 660 */	NdrFcLong( 0x0 ),	/* 0 */
/* 664 */	NdrFcShort( 0xc ),	/* 12 */
/* 666 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 668 */	NdrFcShort( 0x6 ),	/* 6 */
/* 670 */	NdrFcShort( 0x8 ),	/* 8 */
/* 672 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 674 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 676 */	NdrFcShort( 0x0 ),	/* 0 */
/* 678 */	NdrFcShort( 0x0 ),	/* 0 */
/* 680 */	NdrFcShort( 0x0 ),	/* 0 */
/* 682 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bDate */

/* 684 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 686 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 688 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 690 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 692 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 694 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ArrayFormatFlags */

/* 696 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 698 */	NdrFcLong( 0x0 ),	/* 0 */
/* 702 */	NdrFcShort( 0x7 ),	/* 7 */
/* 704 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 706 */	NdrFcShort( 0x0 ),	/* 0 */
/* 708 */	NdrFcShort( 0x8 ),	/* 8 */
/* 710 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 712 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 714 */	NdrFcShort( 0x0 ),	/* 0 */
/* 716 */	NdrFcShort( 0x0 ),	/* 0 */
/* 718 */	NdrFcShort( 0x0 ),	/* 0 */
/* 720 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppFlags */

/* 722 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 724 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 726 */	NdrFcShort( 0xe ),	/* Type Offset=14 */

	/* Return value */

/* 728 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 730 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 732 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ArrayFormatFlags */

/* 734 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 736 */	NdrFcLong( 0x0 ),	/* 0 */
/* 740 */	NdrFcShort( 0x8 ),	/* 8 */
/* 742 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 744 */	NdrFcShort( 0x0 ),	/* 0 */
/* 746 */	NdrFcShort( 0x8 ),	/* 8 */
/* 748 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 750 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 752 */	NdrFcShort( 0x0 ),	/* 0 */
/* 754 */	NdrFcShort( 0x0 ),	/* 0 */
/* 756 */	NdrFcShort( 0x0 ),	/* 0 */
/* 758 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFlags */

/* 760 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 762 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 764 */	NdrFcShort( 0x12 ),	/* Type Offset=18 */

	/* Return value */

/* 766 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 768 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 770 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_DataConversionFlags */

/* 772 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 774 */	NdrFcLong( 0x0 ),	/* 0 */
/* 778 */	NdrFcShort( 0x9 ),	/* 9 */
/* 780 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 782 */	NdrFcShort( 0x0 ),	/* 0 */
/* 784 */	NdrFcShort( 0x8 ),	/* 8 */
/* 786 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 788 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 790 */	NdrFcShort( 0x0 ),	/* 0 */
/* 792 */	NdrFcShort( 0x0 ),	/* 0 */
/* 794 */	NdrFcShort( 0x0 ),	/* 0 */
/* 796 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppFlags */

/* 798 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 800 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 802 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Return value */

/* 804 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 806 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 808 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_DataConversionFlags */

/* 810 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 812 */	NdrFcLong( 0x0 ),	/* 0 */
/* 816 */	NdrFcShort( 0xa ),	/* 10 */
/* 818 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 820 */	NdrFcShort( 0x0 ),	/* 0 */
/* 822 */	NdrFcShort( 0x8 ),	/* 8 */
/* 824 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 826 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 828 */	NdrFcShort( 0x0 ),	/* 0 */
/* 830 */	NdrFcShort( 0x0 ),	/* 0 */
/* 832 */	NdrFcShort( 0x0 ),	/* 0 */
/* 834 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFlags */

/* 836 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 838 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 840 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Return value */

/* 842 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 844 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 846 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Clone */

/* 848 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 850 */	NdrFcLong( 0x0 ),	/* 0 */
/* 854 */	NdrFcShort( 0xb ),	/* 11 */
/* 856 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 858 */	NdrFcShort( 0x0 ),	/* 0 */
/* 860 */	NdrFcShort( 0x8 ),	/* 8 */
/* 862 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 864 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 866 */	NdrFcShort( 0x0 ),	/* 0 */
/* 868 */	NdrFcShort( 0x0 ),	/* 0 */
/* 870 */	NdrFcShort( 0x0 ),	/* 0 */
/* 872 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppFlags */

/* 874 */	NdrFcShort( 0x200b ),	/* Flags:  must size, must free, in, srv alloc size=8 */
/* 876 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 878 */	NdrFcShort( 0x3a ),	/* Type Offset=58 */

	/* Return value */

/* 880 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 882 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 884 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Value */

/* 886 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 888 */	NdrFcLong( 0x0 ),	/* 0 */
/* 892 */	NdrFcShort( 0x7 ),	/* 7 */
/* 894 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 896 */	NdrFcShort( 0x0 ),	/* 0 */
/* 898 */	NdrFcShort( 0x8 ),	/* 8 */
/* 900 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 902 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 904 */	NdrFcShort( 0x9f ),	/* 159 */
/* 906 */	NdrFcShort( 0x0 ),	/* 0 */
/* 908 */	NdrFcShort( 0x0 ),	/* 0 */
/* 910 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pvarValue */

/* 912 */	NdrFcShort( 0x6113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=24 */
/* 914 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 916 */	NdrFcShort( 0x420 ),	/* Type Offset=1056 */

	/* Return value */

/* 918 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 920 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 922 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Value */

/* 924 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 926 */	NdrFcLong( 0x0 ),	/* 0 */
/* 930 */	NdrFcShort( 0x8 ),	/* 8 */
/* 932 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 934 */	NdrFcShort( 0x0 ),	/* 0 */
/* 936 */	NdrFcShort( 0x8 ),	/* 8 */
/* 938 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 940 */	0xa,		/* 10 */
			0x85,		/* Ext Flags:  new corr desc, srv corr check, has big amd64 byval param */
/* 942 */	NdrFcShort( 0x0 ),	/* 0 */
/* 944 */	NdrFcShort( 0xb4 ),	/* 180 */
/* 946 */	NdrFcShort( 0x0 ),	/* 0 */
/* 948 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter varValue */

/* 950 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 952 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 954 */	NdrFcShort( 0x432 ),	/* Type Offset=1074 */

	/* Return value */

/* 956 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 958 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 960 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Name */


	/* Procedure get_Name */

/* 962 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 964 */	NdrFcLong( 0x0 ),	/* 0 */
/* 968 */	NdrFcShort( 0x9 ),	/* 9 */
/* 970 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 972 */	NdrFcShort( 0x0 ),	/* 0 */
/* 974 */	NdrFcShort( 0x8 ),	/* 8 */
/* 976 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 978 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 980 */	NdrFcShort( 0x1 ),	/* 1 */
/* 982 */	NdrFcShort( 0x0 ),	/* 0 */
/* 984 */	NdrFcShort( 0x0 ),	/* 0 */
/* 986 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbstrName */


	/* Parameter pbstrName */

/* 988 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 990 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 992 */	NdrFcShort( 0x440 ),	/* Type Offset=1088 */

	/* Return value */


	/* Return value */

/* 994 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 996 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 998 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_MWFlags */

/* 1000 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1002 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1006 */	NdrFcShort( 0xa ),	/* 10 */
/* 1008 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 1010 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1012 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1014 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1016 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1018 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1020 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1022 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1024 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppFlags */

/* 1026 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1028 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1030 */	NdrFcShort( 0x44a ),	/* Type Offset=1098 */

	/* Return value */

/* 1032 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1034 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1036 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_MWFlags */

/* 1038 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1040 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1044 */	NdrFcShort( 0xb ),	/* 11 */
/* 1046 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 1048 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1050 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1052 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1054 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1056 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1058 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1060 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1062 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFlags */

/* 1064 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1066 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1068 */	NdrFcShort( 0x3e ),	/* Type Offset=62 */

	/* Return value */

/* 1070 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1072 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1074 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Clone */

/* 1076 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1078 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1082 */	NdrFcShort( 0xc ),	/* 12 */
/* 1084 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 1086 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1088 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1090 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1092 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1094 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1096 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1098 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1100 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppField */

/* 1102 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1104 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1106 */	NdrFcShort( 0x44e ),	/* Type Offset=1102 */

	/* Return value */

/* 1108 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1110 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1112 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Item */

/* 1114 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1116 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1120 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1122 */	NdrFcShort( 0x118 ),	/* X64 Stack size/offset = 280 */
/* 1124 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1126 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1128 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x22,		/* 34 */
/* 1130 */	0xa,		/* 10 */
			0x85,		/* Ext Flags:  new corr desc, srv corr check, has big amd64 byval param */
/* 1132 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1134 */	NdrFcShort( 0x4360 ),	/* 17248 */
/* 1136 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1138 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter i0 */

/* 1140 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1142 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1144 */	NdrFcShort( 0x432 ),	/* Type Offset=1074 */

	/* Parameter i1 */

/* 1146 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1148 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1150 */	NdrFcShort( 0x432 ),	/* Type Offset=1074 */

	/* Parameter i2 */

/* 1152 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1154 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 1156 */	NdrFcShort( 0x432 ),	/* Type Offset=1074 */

	/* Parameter i3 */

/* 1158 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1160 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 1162 */	NdrFcShort( 0x432 ),	/* Type Offset=1074 */

	/* Parameter i4 */

/* 1164 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1166 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 1168 */	NdrFcShort( 0x432 ),	/* Type Offset=1074 */

	/* Parameter i5 */

/* 1170 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1172 */	NdrFcShort( 0x30 ),	/* X64 Stack size/offset = 48 */
/* 1174 */	NdrFcShort( 0x432 ),	/* Type Offset=1074 */

	/* Parameter i6 */

/* 1176 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1178 */	NdrFcShort( 0x38 ),	/* X64 Stack size/offset = 56 */
/* 1180 */	NdrFcShort( 0x432 ),	/* Type Offset=1074 */

	/* Parameter i7 */

/* 1182 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1184 */	NdrFcShort( 0x40 ),	/* X64 Stack size/offset = 64 */
/* 1186 */	NdrFcShort( 0x432 ),	/* Type Offset=1074 */

	/* Parameter i8 */

/* 1188 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1190 */	NdrFcShort( 0x48 ),	/* X64 Stack size/offset = 72 */
/* 1192 */	NdrFcShort( 0x432 ),	/* Type Offset=1074 */

	/* Parameter i9 */

/* 1194 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1196 */	NdrFcShort( 0x50 ),	/* X64 Stack size/offset = 80 */
/* 1198 */	NdrFcShort( 0x432 ),	/* Type Offset=1074 */

	/* Parameter i10 */

/* 1200 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1202 */	NdrFcShort( 0x58 ),	/* X64 Stack size/offset = 88 */
/* 1204 */	NdrFcShort( 0x432 ),	/* Type Offset=1074 */

	/* Parameter i11 */

/* 1206 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1208 */	NdrFcShort( 0x60 ),	/* X64 Stack size/offset = 96 */
/* 1210 */	NdrFcShort( 0x432 ),	/* Type Offset=1074 */

	/* Parameter i12 */

/* 1212 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1214 */	NdrFcShort( 0x68 ),	/* X64 Stack size/offset = 104 */
/* 1216 */	NdrFcShort( 0x432 ),	/* Type Offset=1074 */

	/* Parameter i13 */

/* 1218 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1220 */	NdrFcShort( 0x70 ),	/* X64 Stack size/offset = 112 */
/* 1222 */	NdrFcShort( 0x432 ),	/* Type Offset=1074 */

	/* Parameter i14 */

/* 1224 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1226 */	NdrFcShort( 0x78 ),	/* X64 Stack size/offset = 120 */
/* 1228 */	NdrFcShort( 0x432 ),	/* Type Offset=1074 */

	/* Parameter i15 */

/* 1230 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1232 */	NdrFcShort( 0x80 ),	/* X64 Stack size/offset = 128 */
/* 1234 */	NdrFcShort( 0x432 ),	/* Type Offset=1074 */

	/* Parameter i16 */

/* 1236 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1238 */	NdrFcShort( 0x88 ),	/* X64 Stack size/offset = 136 */
/* 1240 */	NdrFcShort( 0x432 ),	/* Type Offset=1074 */

	/* Parameter i17 */

/* 1242 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1244 */	NdrFcShort( 0x90 ),	/* X64 Stack size/offset = 144 */
/* 1246 */	NdrFcShort( 0x432 ),	/* Type Offset=1074 */

	/* Parameter i18 */

/* 1248 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1250 */	NdrFcShort( 0x98 ),	/* X64 Stack size/offset = 152 */
/* 1252 */	NdrFcShort( 0x432 ),	/* Type Offset=1074 */

	/* Parameter i19 */

/* 1254 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1256 */	NdrFcShort( 0xa0 ),	/* X64 Stack size/offset = 160 */
/* 1258 */	NdrFcShort( 0x432 ),	/* Type Offset=1074 */

	/* Parameter i20 */

/* 1260 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1262 */	NdrFcShort( 0xa8 ),	/* X64 Stack size/offset = 168 */
/* 1264 */	NdrFcShort( 0x432 ),	/* Type Offset=1074 */

	/* Parameter i21 */

/* 1266 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1268 */	NdrFcShort( 0xb0 ),	/* X64 Stack size/offset = 176 */
/* 1270 */	NdrFcShort( 0x432 ),	/* Type Offset=1074 */

	/* Parameter i22 */

/* 1272 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1274 */	NdrFcShort( 0xb8 ),	/* X64 Stack size/offset = 184 */
/* 1276 */	NdrFcShort( 0x432 ),	/* Type Offset=1074 */

	/* Parameter i23 */

/* 1278 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1280 */	NdrFcShort( 0xc0 ),	/* X64 Stack size/offset = 192 */
/* 1282 */	NdrFcShort( 0x432 ),	/* Type Offset=1074 */

	/* Parameter i24 */

/* 1284 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1286 */	NdrFcShort( 0xc8 ),	/* X64 Stack size/offset = 200 */
/* 1288 */	NdrFcShort( 0x432 ),	/* Type Offset=1074 */

	/* Parameter i25 */

/* 1290 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1292 */	NdrFcShort( 0xd0 ),	/* X64 Stack size/offset = 208 */
/* 1294 */	NdrFcShort( 0x432 ),	/* Type Offset=1074 */

	/* Parameter i26 */

/* 1296 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1298 */	NdrFcShort( 0xd8 ),	/* X64 Stack size/offset = 216 */
/* 1300 */	NdrFcShort( 0x432 ),	/* Type Offset=1074 */

	/* Parameter i27 */

/* 1302 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1304 */	NdrFcShort( 0xe0 ),	/* X64 Stack size/offset = 224 */
/* 1306 */	NdrFcShort( 0x432 ),	/* Type Offset=1074 */

	/* Parameter i28 */

/* 1308 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1310 */	NdrFcShort( 0xe8 ),	/* X64 Stack size/offset = 232 */
/* 1312 */	NdrFcShort( 0x432 ),	/* Type Offset=1074 */

	/* Parameter i29 */

/* 1314 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1316 */	NdrFcShort( 0xf0 ),	/* X64 Stack size/offset = 240 */
/* 1318 */	NdrFcShort( 0x432 ),	/* Type Offset=1074 */

	/* Parameter i30 */

/* 1320 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1322 */	NdrFcShort( 0xf8 ),	/* X64 Stack size/offset = 248 */
/* 1324 */	NdrFcShort( 0x432 ),	/* Type Offset=1074 */

	/* Parameter i31 */

/* 1326 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1328 */	NdrFcShort( 0x100 ),	/* X64 Stack size/offset = 256 */
/* 1330 */	NdrFcShort( 0x432 ),	/* Type Offset=1074 */

	/* Parameter ppField */

/* 1332 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1334 */	NdrFcShort( 0x108 ),	/* X64 Stack size/offset = 264 */
/* 1336 */	NdrFcShort( 0x44e ),	/* Type Offset=1102 */

	/* Return value */

/* 1338 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1340 */	NdrFcShort( 0x110 ),	/* X64 Stack size/offset = 272 */
/* 1342 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Initialize */

/* 1344 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1346 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1350 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1352 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 1354 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1356 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1358 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1360 */	0xa,		/* 10 */
			0x85,		/* Ext Flags:  new corr desc, srv corr check, has big amd64 byval param */
/* 1362 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1364 */	NdrFcShort( 0x436 ),	/* 1078 */
/* 1366 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1368 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter varDims */

/* 1370 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1372 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1374 */	NdrFcShort( 0x432 ),	/* Type Offset=1074 */

	/* Parameter varFieldNames */

/* 1376 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1378 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1380 */	NdrFcShort( 0x432 ),	/* Type Offset=1074 */

	/* Return value */

/* 1382 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1384 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 1386 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_NumberOfDims */

/* 1388 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1390 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1394 */	NdrFcShort( 0xa ),	/* 10 */
/* 1396 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 1398 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1400 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1402 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1404 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1406 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1408 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1410 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1412 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pnDims */

/* 1414 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1416 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1418 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1420 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1422 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1424 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Dims */

/* 1426 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1428 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1432 */	NdrFcShort( 0xb ),	/* 11 */
/* 1434 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 1436 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1438 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1440 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1442 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1444 */	NdrFcShort( 0xcd ),	/* 205 */
/* 1446 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1448 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1450 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pvarDims */

/* 1452 */	NdrFcShort( 0x6113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=24 */
/* 1454 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1456 */	NdrFcShort( 0x420 ),	/* Type Offset=1056 */

	/* Return value */

/* 1458 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1460 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1462 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_FieldNames */

/* 1464 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1466 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1470 */	NdrFcShort( 0xc ),	/* 12 */
/* 1472 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 1474 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1476 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1478 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1480 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1482 */	NdrFcShort( 0x2e8 ),	/* 744 */
/* 1484 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1486 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1488 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pvarFieldNames */

/* 1490 */	NdrFcShort( 0x6113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=24 */
/* 1492 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1494 */	NdrFcShort( 0x420 ),	/* Type Offset=1056 */

	/* Return value */

/* 1496 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1498 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1500 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Clone */

/* 1502 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1504 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1508 */	NdrFcShort( 0xd ),	/* 13 */
/* 1510 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 1512 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1514 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1516 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1518 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1520 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1522 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1524 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1526 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppStruct */

/* 1528 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1530 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1532 */	NdrFcShort( 0x464 ),	/* Type Offset=1124 */

	/* Return value */

/* 1534 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1536 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1538 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Real */

/* 1540 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1542 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1546 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1548 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 1550 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1552 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1554 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1556 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1558 */	NdrFcShort( 0x2e8 ),	/* 744 */
/* 1560 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1562 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1564 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pvarValue */

/* 1566 */	NdrFcShort( 0x6113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=24 */
/* 1568 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1570 */	NdrFcShort( 0x420 ),	/* Type Offset=1056 */

	/* Return value */

/* 1572 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1574 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1576 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Real */

/* 1578 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1580 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1584 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1586 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 1588 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1590 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1592 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1594 */	0xa,		/* 10 */
			0x85,		/* Ext Flags:  new corr desc, srv corr check, has big amd64 byval param */
/* 1596 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1598 */	NdrFcShort( 0xe5 ),	/* 229 */
/* 1600 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1602 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter varValue */

/* 1604 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1606 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1608 */	NdrFcShort( 0x432 ),	/* Type Offset=1074 */

	/* Return value */

/* 1610 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1612 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1614 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Imag */

/* 1616 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1618 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1622 */	NdrFcShort( 0x9 ),	/* 9 */
/* 1624 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 1626 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1628 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1630 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1632 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1634 */	NdrFcShort( 0xfe ),	/* 254 */
/* 1636 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1638 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1640 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pvarValue */

/* 1642 */	NdrFcShort( 0x6113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=24 */
/* 1644 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1646 */	NdrFcShort( 0x420 ),	/* Type Offset=1056 */

	/* Return value */

/* 1648 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1650 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1652 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Imag */

/* 1654 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1656 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1660 */	NdrFcShort( 0xa ),	/* 10 */
/* 1662 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 1664 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1666 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1668 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1670 */	0xa,		/* 10 */
			0x85,		/* Ext Flags:  new corr desc, srv corr check, has big amd64 byval param */
/* 1672 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1674 */	NdrFcShort( 0x118 ),	/* 280 */
/* 1676 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1678 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter varValue */

/* 1680 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1682 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1684 */	NdrFcShort( 0x432 ),	/* Type Offset=1074 */

	/* Return value */

/* 1686 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1688 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1690 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_MWFlags */

/* 1692 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1694 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1698 */	NdrFcShort( 0xb ),	/* 11 */
/* 1700 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 1702 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1704 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1706 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1708 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1710 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1712 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1714 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1716 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppFlags */

/* 1718 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1720 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1722 */	NdrFcShort( 0x44a ),	/* Type Offset=1098 */

	/* Return value */

/* 1724 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1726 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1728 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_MWFlags */

/* 1730 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1732 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1736 */	NdrFcShort( 0xc ),	/* 12 */
/* 1738 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 1740 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1742 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1744 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1746 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1748 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1750 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1752 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1754 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFlags */

/* 1756 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1758 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1760 */	NdrFcShort( 0x3e ),	/* Type Offset=62 */

	/* Return value */

/* 1762 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1764 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1766 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Clone */

/* 1768 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1770 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1774 */	NdrFcShort( 0xd ),	/* 13 */
/* 1776 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 1778 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1780 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1782 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1784 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1786 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1788 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1790 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1792 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppComplex */

/* 1794 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1796 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1798 */	NdrFcShort( 0x47a ),	/* Type Offset=1146 */

	/* Return value */

/* 1800 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1802 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1804 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Array */

/* 1806 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1808 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1812 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1814 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 1816 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1818 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1820 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1822 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1824 */	NdrFcShort( 0x133 ),	/* 307 */
/* 1826 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1828 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1830 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pvarArray */

/* 1832 */	NdrFcShort( 0x6113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=24 */
/* 1834 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1836 */	NdrFcShort( 0x420 ),	/* Type Offset=1056 */

	/* Return value */

/* 1838 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1840 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1842 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Array */

/* 1844 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1846 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1850 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1852 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 1854 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1856 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1858 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1860 */	0xa,		/* 10 */
			0x85,		/* Ext Flags:  new corr desc, srv corr check, has big amd64 byval param */
/* 1862 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1864 */	NdrFcShort( 0x14f ),	/* 335 */
/* 1866 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1868 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter varArray */

/* 1870 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1872 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1874 */	NdrFcShort( 0x432 ),	/* Type Offset=1074 */

	/* Return value */

/* 1876 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1878 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1880 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_NumColumns */

/* 1882 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1884 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1888 */	NdrFcShort( 0xb ),	/* 11 */
/* 1890 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 1892 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1894 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1896 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1898 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1900 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1902 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1904 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1906 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pnColumns */

/* 1908 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1910 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1912 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1914 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1916 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1918 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_NumColumns */

/* 1920 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1922 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1926 */	NdrFcShort( 0xc ),	/* 12 */
/* 1928 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 1930 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1932 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1934 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1936 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1938 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1940 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1942 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1944 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter nColumns */

/* 1946 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1948 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1950 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1952 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1954 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1956 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_RowIndex */

/* 1958 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1960 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1964 */	NdrFcShort( 0xd ),	/* 13 */
/* 1966 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 1968 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1970 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1972 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1974 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1976 */	NdrFcShort( 0x16c ),	/* 364 */
/* 1978 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1980 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1982 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pIndex */

/* 1984 */	NdrFcShort( 0x6113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=24 */
/* 1986 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1988 */	NdrFcShort( 0x420 ),	/* Type Offset=1056 */

	/* Return value */

/* 1990 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1992 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1994 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_RowIndex */

/* 1996 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1998 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2002 */	NdrFcShort( 0xe ),	/* 14 */
/* 2004 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 2006 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2008 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2010 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2012 */	0xa,		/* 10 */
			0x85,		/* Ext Flags:  new corr desc, srv corr check, has big amd64 byval param */
/* 2014 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2016 */	NdrFcShort( 0x18a ),	/* 394 */
/* 2018 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2020 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Index */

/* 2022 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2024 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 2026 */	NdrFcShort( 0x432 ),	/* Type Offset=1074 */

	/* Return value */

/* 2028 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2030 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 2032 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ColumnIndex */

/* 2034 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2036 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2040 */	NdrFcShort( 0xf ),	/* 15 */
/* 2042 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 2044 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2046 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2048 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2050 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2052 */	NdrFcShort( 0x1a9 ),	/* 425 */
/* 2054 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2056 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2058 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pIndex */

/* 2060 */	NdrFcShort( 0x6113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=24 */
/* 2062 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 2064 */	NdrFcShort( 0x420 ),	/* Type Offset=1056 */

	/* Return value */

/* 2066 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2068 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 2070 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ColumnIndex */

/* 2072 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2074 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2078 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2080 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 2082 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2084 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2086 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2088 */	0xa,		/* 10 */
			0x85,		/* Ext Flags:  new corr desc, srv corr check, has big amd64 byval param */
/* 2090 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2092 */	NdrFcShort( 0x1c9 ),	/* 457 */
/* 2094 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2096 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Index */

/* 2098 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2100 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 2102 */	NdrFcShort( 0x432 ),	/* Type Offset=1074 */

	/* Return value */

/* 2104 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2106 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 2108 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_MWFlags */

/* 2110 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2112 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2116 */	NdrFcShort( 0x11 ),	/* 17 */
/* 2118 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 2120 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2122 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2124 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2126 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2130 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2132 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2134 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppFlags */

/* 2136 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2138 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 2140 */	NdrFcShort( 0x44a ),	/* Type Offset=1098 */

	/* Return value */

/* 2142 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2144 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 2146 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_MWFlags */

/* 2148 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2150 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2154 */	NdrFcShort( 0x12 ),	/* 18 */
/* 2156 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 2158 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2160 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2162 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2164 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2166 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2168 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2170 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2172 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFlags */

/* 2174 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2176 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 2178 */	NdrFcShort( 0x3e ),	/* Type Offset=62 */

	/* Return value */

/* 2180 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2182 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 2184 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Clone */

/* 2186 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2188 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2192 */	NdrFcShort( 0x13 ),	/* 19 */
/* 2194 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 2196 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2198 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2200 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2202 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2204 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2206 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2208 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2210 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppSparse */

/* 2212 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2214 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 2216 */	NdrFcShort( 0x490 ),	/* Type Offset=1168 */

	/* Return value */

/* 2218 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2220 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 2222 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Value */

/* 2224 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2226 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2230 */	NdrFcShort( 0x7 ),	/* 7 */
/* 2232 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 2234 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2236 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2238 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2240 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2242 */	NdrFcShort( 0x1ea ),	/* 490 */
/* 2244 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2246 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2248 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pvarValue */

/* 2250 */	NdrFcShort( 0x6113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=24 */
/* 2252 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 2254 */	NdrFcShort( 0x420 ),	/* Type Offset=1056 */

	/* Return value */

/* 2256 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2258 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 2260 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Value */

/* 2262 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2264 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2268 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2270 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 2272 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2274 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2276 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2278 */	0xa,		/* 10 */
			0x85,		/* Ext Flags:  new corr desc, srv corr check, has big amd64 byval param */
/* 2280 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2282 */	NdrFcShort( 0x20c ),	/* 524 */
/* 2284 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2286 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter varValue */

/* 2288 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2290 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 2292 */	NdrFcShort( 0x432 ),	/* Type Offset=1074 */

	/* Return value */

/* 2294 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2296 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 2298 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_MWFlags */

/* 2300 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2302 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2306 */	NdrFcShort( 0x9 ),	/* 9 */
/* 2308 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 2310 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2312 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2314 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2316 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2318 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2320 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2322 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2324 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppFlags */

/* 2326 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2328 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 2330 */	NdrFcShort( 0x44a ),	/* Type Offset=1098 */

	/* Return value */

/* 2332 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2334 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 2336 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_MWFlags */

/* 2338 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2340 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2344 */	NdrFcShort( 0xa ),	/* 10 */
/* 2346 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 2348 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2350 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2352 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2354 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2356 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2358 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2360 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2362 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFlags */

/* 2364 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2366 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 2368 */	NdrFcShort( 0x3e ),	/* Type Offset=62 */

	/* Return value */

/* 2370 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2372 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 2374 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Clone */

/* 2376 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2378 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2382 */	NdrFcShort( 0xb ),	/* 11 */
/* 2384 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 2386 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2388 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2390 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2392 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2394 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2396 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2398 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2400 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppArg */

/* 2402 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2404 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 2406 */	NdrFcShort( 0x4a6 ),	/* Type Offset=1190 */

	/* Return value */

/* 2408 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2410 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 2412 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Item */

/* 2414 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2416 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2420 */	NdrFcShort( 0x7 ),	/* 7 */
/* 2422 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 2424 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2426 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2428 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 2430 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2432 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2434 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2436 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2438 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter nIndex */

/* 2440 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2442 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 2444 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppInfo */

/* 2446 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2448 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 2450 */	NdrFcShort( 0x4bc ),	/* Type Offset=1212 */

	/* Return value */

/* 2452 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2454 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 2456 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Name */

/* 2458 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2460 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2464 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2466 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 2468 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2470 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2472 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2474 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2476 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2478 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2480 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2482 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbstrName */

/* 2484 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 2486 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 2488 */	NdrFcShort( 0x440 ),	/* Type Offset=1088 */

	/* Return value */

/* 2490 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2492 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 2494 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Name */

/* 2496 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2498 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2502 */	NdrFcShort( 0x9 ),	/* 9 */
/* 2504 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 2506 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2508 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2510 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2512 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2514 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2516 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2518 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2520 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bstrName */

/* 2522 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2524 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 2526 */	NdrFcShort( 0x4d6 ),	/* Type Offset=1238 */

	/* Return value */

/* 2528 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2530 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 2532 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Value */

/* 2534 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2536 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2540 */	NdrFcShort( 0xa ),	/* 10 */
/* 2542 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 2544 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2546 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2548 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2550 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2552 */	NdrFcShort( 0x235 ),	/* 565 */
/* 2554 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2556 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2558 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pvarValue */

/* 2560 */	NdrFcShort( 0x6113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=24 */
/* 2562 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 2564 */	NdrFcShort( 0x420 ),	/* Type Offset=1056 */

	/* Return value */

/* 2566 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2568 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 2570 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Value */

/* 2572 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2574 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2578 */	NdrFcShort( 0xb ),	/* 11 */
/* 2580 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 2582 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2584 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2586 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2588 */	0xa,		/* 10 */
			0x85,		/* Ext Flags:  new corr desc, srv corr check, has big amd64 byval param */
/* 2590 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2592 */	NdrFcShort( 0x25b ),	/* 603 */
/* 2594 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2596 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter varValue */

/* 2598 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2600 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 2602 */	NdrFcShort( 0x432 ),	/* Type Offset=1074 */

	/* Return value */

/* 2604 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2606 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 2608 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Count */

/* 2610 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2612 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2616 */	NdrFcShort( 0xc ),	/* 12 */
/* 2618 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 2620 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2622 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2624 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2626 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2628 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2630 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2632 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2634 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pnCount */

/* 2636 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2638 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 2640 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2642 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2644 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 2646 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Reset */

/* 2648 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2650 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2654 */	NdrFcShort( 0xd ),	/* 13 */
/* 2656 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 2658 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2660 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2662 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 2664 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2666 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2668 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2670 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2672 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 2674 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2676 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 2678 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Next */

/* 2680 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2682 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2686 */	NdrFcShort( 0xf ),	/* 15 */
/* 2688 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 2690 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2692 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2694 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 2696 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2698 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2700 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2702 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2704 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppInfo */

/* 2706 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2708 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 2710 */	NdrFcShort( 0x4bc ),	/* Type Offset=1212 */

	/* Parameter pnRetElms */

/* 2712 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2714 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 2716 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2718 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2720 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 2722 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Add */

/* 2724 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2726 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2730 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2732 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 2734 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2736 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2738 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2740 */	0xa,		/* 10 */
			0x85,		/* Ext Flags:  new corr desc, srv corr check, has big amd64 byval param */
/* 2742 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2744 */	NdrFcShort( 0x1753 ),	/* 5971 */
/* 2746 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2748 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter varValue */

/* 2750 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2752 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 2754 */	NdrFcShort( 0x432 ),	/* Type Offset=1074 */

	/* Return value */

/* 2756 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2758 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 2760 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Remove */

/* 2762 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2764 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2768 */	NdrFcShort( 0x11 ),	/* 17 */
/* 2770 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 2772 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2774 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2776 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2778 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2780 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2782 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2784 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2786 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter nIndex */

/* 2788 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2790 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 2792 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2794 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2796 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 2798 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Clear */

/* 2800 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2802 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2806 */	NdrFcShort( 0x12 ),	/* 18 */
/* 2808 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 2810 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2812 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2814 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 2816 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2818 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2820 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2822 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2824 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 2826 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2828 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 2830 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetAt */

/* 2832 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2834 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2838 */	NdrFcShort( 0x13 ),	/* 19 */
/* 2840 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 2842 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2844 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2846 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2848 */	0xa,		/* 10 */
			0x85,		/* Ext Flags:  new corr desc, srv corr check, has big amd64 byval param */
/* 2850 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2852 */	NdrFcShort( 0x1753 ),	/* 5971 */
/* 2854 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2856 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter nIndex */

/* 2858 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2860 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 2862 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter varValue */

/* 2864 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2866 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 2868 */	NdrFcShort( 0x432 ),	/* Type Offset=1074 */

	/* Return value */

/* 2870 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2872 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 2874 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_CopyToRange */

/* 2876 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2878 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2882 */	NdrFcShort( 0x14 ),	/* 20 */
/* 2884 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 2886 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2888 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2890 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2892 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2894 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2896 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2898 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2900 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bToRange */

/* 2902 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2904 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 2906 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2908 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2910 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 2912 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_CopyToRange */

/* 2914 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2916 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2920 */	NdrFcShort( 0x15 ),	/* 21 */
/* 2922 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 2924 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2926 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2928 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2930 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2932 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2934 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2936 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2938 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbToRange */

/* 2940 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2942 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 2944 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2946 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2948 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 2950 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Clone */

/* 2952 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2954 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2958 */	NdrFcShort( 0x16 ),	/* 22 */
/* 2960 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 2962 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2964 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2966 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2968 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2970 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2972 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2974 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2976 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppEnum */

/* 2978 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2980 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 2982 */	NdrFcShort( 0x4e0 ),	/* Type Offset=1248 */

	/* Return value */

/* 2984 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2986 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 2988 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Value */

/* 2990 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2992 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2996 */	NdrFcShort( 0x7 ),	/* 7 */
/* 2998 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 3000 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3002 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3004 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 3006 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 3008 */	NdrFcShort( 0x282 ),	/* 642 */
/* 3010 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3012 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3014 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pvarValue */

/* 3016 */	NdrFcShort( 0x6113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=24 */
/* 3018 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 3020 */	NdrFcShort( 0x420 ),	/* Type Offset=1056 */

	/* Return value */

/* 3022 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3024 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 3026 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Value */

/* 3028 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3030 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3034 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3036 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 3038 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3040 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3042 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3044 */	0xa,		/* 10 */
			0x85,		/* Ext Flags:  new corr desc, srv corr check, has big amd64 byval param */
/* 3046 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3048 */	NdrFcShort( 0x2aa ),	/* 682 */
/* 3050 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3052 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter varValue */

/* 3054 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3056 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 3058 */	NdrFcShort( 0x432 ),	/* Type Offset=1074 */

	/* Return value */

/* 3060 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3062 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 3064 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Name */

/* 3066 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3068 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3072 */	NdrFcShort( 0xa ),	/* 10 */
/* 3074 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 3076 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3078 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3080 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3082 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3084 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3086 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3088 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3090 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bstrName */

/* 3092 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3094 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 3096 */	NdrFcShort( 0x4d6 ),	/* Type Offset=1238 */

	/* Return value */

/* 3098 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3100 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 3102 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Flags */

/* 3104 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3106 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3110 */	NdrFcShort( 0xc ),	/* 12 */
/* 3112 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 3114 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3116 */	NdrFcShort( 0x22 ),	/* 34 */
/* 3118 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3120 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3122 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3124 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3126 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3128 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pnFlags */

/* 3130 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3132 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 3134 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 3136 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3138 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 3140 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_IsRange */

/* 3142 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3144 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3148 */	NdrFcShort( 0xe ),	/* 14 */
/* 3150 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 3152 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3154 */	NdrFcShort( 0x22 ),	/* 34 */
/* 3156 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3158 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3160 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3162 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3164 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3166 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbRange */

/* 3168 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3170 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 3172 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 3174 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3176 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 3178 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_MWFlags */

/* 3180 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3182 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3186 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3188 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 3190 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3192 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3194 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 3196 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3198 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3200 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3202 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3204 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppFlags */

/* 3206 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3208 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 3210 */	NdrFcShort( 0x44a ),	/* Type Offset=1098 */

	/* Return value */

/* 3212 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3214 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 3216 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_MWFlags */

/* 3218 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3220 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3224 */	NdrFcShort( 0x11 ),	/* 17 */
/* 3226 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 3228 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3230 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3232 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3234 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3236 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3238 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3240 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3242 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFlags */

/* 3244 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3246 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 3248 */	NdrFcShort( 0x3e ),	/* Type Offset=62 */

	/* Return value */

/* 3250 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3252 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 3254 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Selected */

/* 3256 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3258 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3262 */	NdrFcShort( 0x12 ),	/* 18 */
/* 3264 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 3266 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3268 */	NdrFcShort( 0x22 ),	/* 34 */
/* 3270 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3272 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3274 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3276 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3278 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3280 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbSelected */

/* 3282 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3284 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 3286 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 3288 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3290 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 3292 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Vararg */

/* 3294 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3296 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3300 */	NdrFcShort( 0x13 ),	/* 19 */
/* 3302 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 3304 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3306 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3308 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 3310 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3312 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3314 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3316 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3318 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVararg */

/* 3320 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3322 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 3324 */	NdrFcShort( 0x4e0 ),	/* Type Offset=1248 */

	/* Return value */

/* 3326 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3328 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 3330 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Vararg */

/* 3332 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3334 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3338 */	NdrFcShort( 0x14 ),	/* 20 */
/* 3340 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 3342 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3344 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3346 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3348 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3350 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3352 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3354 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3356 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVararg */

/* 3358 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3360 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 3362 */	NdrFcShort( 0x4e4 ),	/* Type Offset=1252 */

	/* Return value */

/* 3364 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3366 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 3368 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_CopyToRange */

/* 3370 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3372 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3376 */	NdrFcShort( 0x15 ),	/* 21 */
/* 3378 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 3380 */	NdrFcShort( 0x6 ),	/* 6 */
/* 3382 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3384 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3386 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3388 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3390 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3392 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3394 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bToRange */

/* 3396 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3398 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 3400 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 3402 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3404 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 3406 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_CopyToRange */

/* 3408 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3410 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3414 */	NdrFcShort( 0x16 ),	/* 22 */
/* 3416 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 3418 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3420 */	NdrFcShort( 0x22 ),	/* 34 */
/* 3422 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3424 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3426 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3428 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3430 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3432 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbToRange */

/* 3434 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3436 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 3438 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 3440 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3442 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 3444 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Select */

/* 3446 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3448 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3452 */	NdrFcShort( 0x17 ),	/* 23 */
/* 3454 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 3456 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3458 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3460 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 3462 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3464 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3466 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3468 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3470 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 3472 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3474 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 3476 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_IsListening */

/* 3478 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3480 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3484 */	NdrFcShort( 0x18 ),	/* 24 */
/* 3486 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 3488 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3490 */	NdrFcShort( 0x22 ),	/* 34 */
/* 3492 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3494 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3496 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3498 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3500 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3502 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbListen */

/* 3504 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3506 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 3508 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 3510 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3512 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 3514 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_IsListening */

/* 3516 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3518 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3522 */	NdrFcShort( 0x19 ),	/* 25 */
/* 3524 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 3526 */	NdrFcShort( 0x6 ),	/* 6 */
/* 3528 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3530 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3532 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3534 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3536 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3538 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3540 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bListen */

/* 3542 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3544 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 3546 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 3548 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3550 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 3552 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Offset */

/* 3554 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3556 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3560 */	NdrFcShort( 0x1a ),	/* 26 */
/* 3562 */	NdrFcShort( 0x30 ),	/* X64 Stack size/offset = 48 */
/* 3564 */	NdrFcShort( 0x1c ),	/* 28 */
/* 3566 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3568 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x5,		/* 5 */
/* 3570 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3572 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3574 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3576 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3578 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter nRows */

/* 3580 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3582 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 3584 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nColumns */

/* 3586 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3588 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 3590 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter bCopyContents */

/* 3592 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3594 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 3596 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter bDeleteOriginal */

/* 3598 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3600 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 3602 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 3604 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3606 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 3608 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Clone */

/* 3610 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3612 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3616 */	NdrFcShort( 0x1b ),	/* 27 */
/* 3618 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 3620 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3622 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3624 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 3626 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3628 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3630 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3632 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3634 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppInfo */

/* 3636 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3638 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 3640 */	NdrFcShort( 0x4bc ),	/* Type Offset=1212 */

	/* Return value */

/* 3642 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3644 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 3646 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const mwcomtypes_MIDL_TYPE_FORMAT_STRING mwcomtypes__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/*  4 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/*  6 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/*  8 */	0xd,		/* FC_ENUM16 */
			0x5c,		/* FC_PAD */
/* 10 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 12 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 14 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 16 */	NdrFcShort( 0x2 ),	/* Offset= 2 (18) */
/* 18 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 20 */	NdrFcLong( 0x30c8ebcb ),	/* 818473931 */
/* 24 */	NdrFcShort( 0x1a50 ),	/* 6736 */
/* 26 */	NdrFcShort( 0x4dee ),	/* 19950 */
/* 28 */	0xa5,		/* 165 */
			0xe8,		/* 232 */
/* 30 */	0xc,		/* 12 */
			0x6f,		/* 111 */
/* 32 */	0x7d,		/* 125 */
			0xd5,		/* 213 */
/* 34 */	0x2d,		/* 45 */
			0x4c,		/* 76 */
/* 36 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 38 */	NdrFcShort( 0x2 ),	/* Offset= 2 (40) */
/* 40 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 42 */	NdrFcLong( 0x5e0bbecb ),	/* 1577828043 */
/* 46 */	NdrFcShort( 0xce72 ),	/* -12686 */
/* 48 */	NdrFcShort( 0x4461 ),	/* 17505 */
/* 50 */	0xad,		/* 173 */
			0xb8,		/* 184 */
/* 52 */	0x4,		/* 4 */
			0x46,		/* 70 */
/* 54 */	0xab,		/* 171 */
			0x32,		/* 50 */
/* 56 */	0xcf,		/* 207 */
			0x51,		/* 81 */
/* 58 */	0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 60 */	NdrFcShort( 0x2 ),	/* Offset= 2 (62) */
/* 62 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 64 */	NdrFcLong( 0xa295776 ),	/* 170481526 */
/* 68 */	NdrFcShort( 0x23a1 ),	/* 9121 */
/* 70 */	NdrFcShort( 0x410a ),	/* 16650 */
/* 72 */	0x94,		/* 148 */
			0xbd,		/* 189 */
/* 74 */	0xc,		/* 12 */
			0x6c,		/* 108 */
/* 76 */	0x61,		/* 97 */
			0xb8,		/* 184 */
/* 78 */	0x91,		/* 145 */
			0xb7,		/* 183 */
/* 80 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 82 */	NdrFcShort( 0x3ce ),	/* Offset= 974 (1056) */
/* 84 */	
			0x13, 0x0,	/* FC_OP */
/* 86 */	NdrFcShort( 0x3b6 ),	/* Offset= 950 (1036) */
/* 88 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 90 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 92 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 94 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 96 */	NdrFcShort( 0x2 ),	/* Offset= 2 (98) */
/* 98 */	NdrFcShort( 0x10 ),	/* 16 */
/* 100 */	NdrFcShort( 0x2f ),	/* 47 */
/* 102 */	NdrFcLong( 0x14 ),	/* 20 */
/* 106 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 108 */	NdrFcLong( 0x3 ),	/* 3 */
/* 112 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 114 */	NdrFcLong( 0x11 ),	/* 17 */
/* 118 */	NdrFcShort( 0x8001 ),	/* Simple arm type: FC_BYTE */
/* 120 */	NdrFcLong( 0x2 ),	/* 2 */
/* 124 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 126 */	NdrFcLong( 0x4 ),	/* 4 */
/* 130 */	NdrFcShort( 0x800a ),	/* Simple arm type: FC_FLOAT */
/* 132 */	NdrFcLong( 0x5 ),	/* 5 */
/* 136 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 138 */	NdrFcLong( 0xb ),	/* 11 */
/* 142 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 144 */	NdrFcLong( 0xa ),	/* 10 */
/* 148 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 150 */	NdrFcLong( 0x6 ),	/* 6 */
/* 154 */	NdrFcShort( 0xe8 ),	/* Offset= 232 (386) */
/* 156 */	NdrFcLong( 0x7 ),	/* 7 */
/* 160 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 162 */	NdrFcLong( 0x8 ),	/* 8 */
/* 166 */	NdrFcShort( 0xe2 ),	/* Offset= 226 (392) */
/* 168 */	NdrFcLong( 0xd ),	/* 13 */
/* 172 */	NdrFcShort( 0xf6 ),	/* Offset= 246 (418) */
/* 174 */	NdrFcLong( 0x9 ),	/* 9 */
/* 178 */	NdrFcShort( 0x102 ),	/* Offset= 258 (436) */
/* 180 */	NdrFcLong( 0x2000 ),	/* 8192 */
/* 184 */	NdrFcShort( 0x10e ),	/* Offset= 270 (454) */
/* 186 */	NdrFcLong( 0x24 ),	/* 36 */
/* 190 */	NdrFcShort( 0x304 ),	/* Offset= 772 (962) */
/* 192 */	NdrFcLong( 0x4024 ),	/* 16420 */
/* 196 */	NdrFcShort( 0x2fe ),	/* Offset= 766 (962) */
/* 198 */	NdrFcLong( 0x4011 ),	/* 16401 */
/* 202 */	NdrFcShort( 0x2fc ),	/* Offset= 764 (966) */
/* 204 */	NdrFcLong( 0x4002 ),	/* 16386 */
/* 208 */	NdrFcShort( 0x2fa ),	/* Offset= 762 (970) */
/* 210 */	NdrFcLong( 0x4003 ),	/* 16387 */
/* 214 */	NdrFcShort( 0x2f8 ),	/* Offset= 760 (974) */
/* 216 */	NdrFcLong( 0x4014 ),	/* 16404 */
/* 220 */	NdrFcShort( 0x2f6 ),	/* Offset= 758 (978) */
/* 222 */	NdrFcLong( 0x4004 ),	/* 16388 */
/* 226 */	NdrFcShort( 0x2f4 ),	/* Offset= 756 (982) */
/* 228 */	NdrFcLong( 0x4005 ),	/* 16389 */
/* 232 */	NdrFcShort( 0x2f2 ),	/* Offset= 754 (986) */
/* 234 */	NdrFcLong( 0x400b ),	/* 16395 */
/* 238 */	NdrFcShort( 0x2dc ),	/* Offset= 732 (970) */
/* 240 */	NdrFcLong( 0x400a ),	/* 16394 */
/* 244 */	NdrFcShort( 0x2da ),	/* Offset= 730 (974) */
/* 246 */	NdrFcLong( 0x4006 ),	/* 16390 */
/* 250 */	NdrFcShort( 0x2e4 ),	/* Offset= 740 (990) */
/* 252 */	NdrFcLong( 0x4007 ),	/* 16391 */
/* 256 */	NdrFcShort( 0x2da ),	/* Offset= 730 (986) */
/* 258 */	NdrFcLong( 0x4008 ),	/* 16392 */
/* 262 */	NdrFcShort( 0x2dc ),	/* Offset= 732 (994) */
/* 264 */	NdrFcLong( 0x400d ),	/* 16397 */
/* 268 */	NdrFcShort( 0x2da ),	/* Offset= 730 (998) */
/* 270 */	NdrFcLong( 0x4009 ),	/* 16393 */
/* 274 */	NdrFcShort( 0x2d8 ),	/* Offset= 728 (1002) */
/* 276 */	NdrFcLong( 0x6000 ),	/* 24576 */
/* 280 */	NdrFcShort( 0x2d6 ),	/* Offset= 726 (1006) */
/* 282 */	NdrFcLong( 0x400c ),	/* 16396 */
/* 286 */	NdrFcShort( 0x2d4 ),	/* Offset= 724 (1010) */
/* 288 */	NdrFcLong( 0x10 ),	/* 16 */
/* 292 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 294 */	NdrFcLong( 0x12 ),	/* 18 */
/* 298 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 300 */	NdrFcLong( 0x13 ),	/* 19 */
/* 304 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 306 */	NdrFcLong( 0x15 ),	/* 21 */
/* 310 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 312 */	NdrFcLong( 0x16 ),	/* 22 */
/* 316 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 318 */	NdrFcLong( 0x17 ),	/* 23 */
/* 322 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 324 */	NdrFcLong( 0xe ),	/* 14 */
/* 328 */	NdrFcShort( 0x2b2 ),	/* Offset= 690 (1018) */
/* 330 */	NdrFcLong( 0x400e ),	/* 16398 */
/* 334 */	NdrFcShort( 0x2b6 ),	/* Offset= 694 (1028) */
/* 336 */	NdrFcLong( 0x4010 ),	/* 16400 */
/* 340 */	NdrFcShort( 0x2b4 ),	/* Offset= 692 (1032) */
/* 342 */	NdrFcLong( 0x4012 ),	/* 16402 */
/* 346 */	NdrFcShort( 0x270 ),	/* Offset= 624 (970) */
/* 348 */	NdrFcLong( 0x4013 ),	/* 16403 */
/* 352 */	NdrFcShort( 0x26e ),	/* Offset= 622 (974) */
/* 354 */	NdrFcLong( 0x4015 ),	/* 16405 */
/* 358 */	NdrFcShort( 0x26c ),	/* Offset= 620 (978) */
/* 360 */	NdrFcLong( 0x4016 ),	/* 16406 */
/* 364 */	NdrFcShort( 0x262 ),	/* Offset= 610 (974) */
/* 366 */	NdrFcLong( 0x4017 ),	/* 16407 */
/* 370 */	NdrFcShort( 0x25c ),	/* Offset= 604 (974) */
/* 372 */	NdrFcLong( 0x0 ),	/* 0 */
/* 376 */	NdrFcShort( 0x0 ),	/* Offset= 0 (376) */
/* 378 */	NdrFcLong( 0x1 ),	/* 1 */
/* 382 */	NdrFcShort( 0x0 ),	/* Offset= 0 (382) */
/* 384 */	NdrFcShort( 0xffff ),	/* Offset= -1 (383) */
/* 386 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 388 */	NdrFcShort( 0x8 ),	/* 8 */
/* 390 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 392 */	
			0x13, 0x0,	/* FC_OP */
/* 394 */	NdrFcShort( 0xe ),	/* Offset= 14 (408) */
/* 396 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 398 */	NdrFcShort( 0x2 ),	/* 2 */
/* 400 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 402 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 404 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 406 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 408 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 410 */	NdrFcShort( 0x8 ),	/* 8 */
/* 412 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (396) */
/* 414 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 416 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 418 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 420 */	NdrFcLong( 0x0 ),	/* 0 */
/* 424 */	NdrFcShort( 0x0 ),	/* 0 */
/* 426 */	NdrFcShort( 0x0 ),	/* 0 */
/* 428 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 430 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 432 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 434 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 436 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 438 */	NdrFcLong( 0x20400 ),	/* 132096 */
/* 442 */	NdrFcShort( 0x0 ),	/* 0 */
/* 444 */	NdrFcShort( 0x0 ),	/* 0 */
/* 446 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 448 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 450 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 452 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 454 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 456 */	NdrFcShort( 0x2 ),	/* Offset= 2 (458) */
/* 458 */	
			0x13, 0x0,	/* FC_OP */
/* 460 */	NdrFcShort( 0x1e4 ),	/* Offset= 484 (944) */
/* 462 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x89,		/* 137 */
/* 464 */	NdrFcShort( 0x20 ),	/* 32 */
/* 466 */	NdrFcShort( 0xa ),	/* 10 */
/* 468 */	NdrFcLong( 0x8 ),	/* 8 */
/* 472 */	NdrFcShort( 0x50 ),	/* Offset= 80 (552) */
/* 474 */	NdrFcLong( 0xd ),	/* 13 */
/* 478 */	NdrFcShort( 0x70 ),	/* Offset= 112 (590) */
/* 480 */	NdrFcLong( 0x9 ),	/* 9 */
/* 484 */	NdrFcShort( 0x90 ),	/* Offset= 144 (628) */
/* 486 */	NdrFcLong( 0xc ),	/* 12 */
/* 490 */	NdrFcShort( 0xb0 ),	/* Offset= 176 (666) */
/* 492 */	NdrFcLong( 0x24 ),	/* 36 */
/* 496 */	NdrFcShort( 0x102 ),	/* Offset= 258 (754) */
/* 498 */	NdrFcLong( 0x800d ),	/* 32781 */
/* 502 */	NdrFcShort( 0x11e ),	/* Offset= 286 (788) */
/* 504 */	NdrFcLong( 0x10 ),	/* 16 */
/* 508 */	NdrFcShort( 0x138 ),	/* Offset= 312 (820) */
/* 510 */	NdrFcLong( 0x2 ),	/* 2 */
/* 514 */	NdrFcShort( 0x14e ),	/* Offset= 334 (848) */
/* 516 */	NdrFcLong( 0x3 ),	/* 3 */
/* 520 */	NdrFcShort( 0x164 ),	/* Offset= 356 (876) */
/* 522 */	NdrFcLong( 0x14 ),	/* 20 */
/* 526 */	NdrFcShort( 0x17a ),	/* Offset= 378 (904) */
/* 528 */	NdrFcShort( 0xffff ),	/* Offset= -1 (527) */
/* 530 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 532 */	NdrFcShort( 0x0 ),	/* 0 */
/* 534 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 536 */	NdrFcShort( 0x0 ),	/* 0 */
/* 538 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 540 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 544 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 546 */	
			0x13, 0x0,	/* FC_OP */
/* 548 */	NdrFcShort( 0xff74 ),	/* Offset= -140 (408) */
/* 550 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 552 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 554 */	NdrFcShort( 0x10 ),	/* 16 */
/* 556 */	NdrFcShort( 0x0 ),	/* 0 */
/* 558 */	NdrFcShort( 0x6 ),	/* Offset= 6 (564) */
/* 560 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 562 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 564 */	
			0x11, 0x0,	/* FC_RP */
/* 566 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (530) */
/* 568 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 570 */	NdrFcShort( 0x0 ),	/* 0 */
/* 572 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 574 */	NdrFcShort( 0x0 ),	/* 0 */
/* 576 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 578 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 582 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 584 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 586 */	NdrFcShort( 0xff58 ),	/* Offset= -168 (418) */
/* 588 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 590 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 592 */	NdrFcShort( 0x10 ),	/* 16 */
/* 594 */	NdrFcShort( 0x0 ),	/* 0 */
/* 596 */	NdrFcShort( 0x6 ),	/* Offset= 6 (602) */
/* 598 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 600 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 602 */	
			0x11, 0x0,	/* FC_RP */
/* 604 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (568) */
/* 606 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 608 */	NdrFcShort( 0x0 ),	/* 0 */
/* 610 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 612 */	NdrFcShort( 0x0 ),	/* 0 */
/* 614 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 616 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 620 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 622 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 624 */	NdrFcShort( 0xff44 ),	/* Offset= -188 (436) */
/* 626 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 628 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 630 */	NdrFcShort( 0x10 ),	/* 16 */
/* 632 */	NdrFcShort( 0x0 ),	/* 0 */
/* 634 */	NdrFcShort( 0x6 ),	/* Offset= 6 (640) */
/* 636 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 638 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 640 */	
			0x11, 0x0,	/* FC_RP */
/* 642 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (606) */
/* 644 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 646 */	NdrFcShort( 0x0 ),	/* 0 */
/* 648 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 650 */	NdrFcShort( 0x0 ),	/* 0 */
/* 652 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 654 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 658 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 660 */	
			0x13, 0x0,	/* FC_OP */
/* 662 */	NdrFcShort( 0x176 ),	/* Offset= 374 (1036) */
/* 664 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 666 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 668 */	NdrFcShort( 0x10 ),	/* 16 */
/* 670 */	NdrFcShort( 0x0 ),	/* 0 */
/* 672 */	NdrFcShort( 0x6 ),	/* Offset= 6 (678) */
/* 674 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 676 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 678 */	
			0x11, 0x0,	/* FC_RP */
/* 680 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (644) */
/* 682 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 684 */	NdrFcLong( 0x2f ),	/* 47 */
/* 688 */	NdrFcShort( 0x0 ),	/* 0 */
/* 690 */	NdrFcShort( 0x0 ),	/* 0 */
/* 692 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 694 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 696 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 698 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 700 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 702 */	NdrFcShort( 0x1 ),	/* 1 */
/* 704 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 706 */	NdrFcShort( 0x4 ),	/* 4 */
/* 708 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 710 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 712 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 714 */	NdrFcShort( 0x18 ),	/* 24 */
/* 716 */	NdrFcShort( 0x0 ),	/* 0 */
/* 718 */	NdrFcShort( 0xa ),	/* Offset= 10 (728) */
/* 720 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 722 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 724 */	NdrFcShort( 0xffd6 ),	/* Offset= -42 (682) */
/* 726 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 728 */	
			0x13, 0x0,	/* FC_OP */
/* 730 */	NdrFcShort( 0xffe2 ),	/* Offset= -30 (700) */
/* 732 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 734 */	NdrFcShort( 0x0 ),	/* 0 */
/* 736 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 738 */	NdrFcShort( 0x0 ),	/* 0 */
/* 740 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 742 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 746 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 748 */	
			0x13, 0x0,	/* FC_OP */
/* 750 */	NdrFcShort( 0xffda ),	/* Offset= -38 (712) */
/* 752 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 754 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 756 */	NdrFcShort( 0x10 ),	/* 16 */
/* 758 */	NdrFcShort( 0x0 ),	/* 0 */
/* 760 */	NdrFcShort( 0x6 ),	/* Offset= 6 (766) */
/* 762 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 764 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 766 */	
			0x11, 0x0,	/* FC_RP */
/* 768 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (732) */
/* 770 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 772 */	NdrFcShort( 0x8 ),	/* 8 */
/* 774 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 776 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 778 */	NdrFcShort( 0x10 ),	/* 16 */
/* 780 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 782 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 784 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (770) */
			0x5b,		/* FC_END */
/* 788 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 790 */	NdrFcShort( 0x20 ),	/* 32 */
/* 792 */	NdrFcShort( 0x0 ),	/* 0 */
/* 794 */	NdrFcShort( 0xa ),	/* Offset= 10 (804) */
/* 796 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 798 */	0x36,		/* FC_POINTER */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 800 */	0x0,		/* 0 */
			NdrFcShort( 0xffe7 ),	/* Offset= -25 (776) */
			0x5b,		/* FC_END */
/* 804 */	
			0x11, 0x0,	/* FC_RP */
/* 806 */	NdrFcShort( 0xff12 ),	/* Offset= -238 (568) */
/* 808 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 810 */	NdrFcShort( 0x1 ),	/* 1 */
/* 812 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 814 */	NdrFcShort( 0x0 ),	/* 0 */
/* 816 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 818 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 820 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 822 */	NdrFcShort( 0x10 ),	/* 16 */
/* 824 */	NdrFcShort( 0x0 ),	/* 0 */
/* 826 */	NdrFcShort( 0x6 ),	/* Offset= 6 (832) */
/* 828 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 830 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 832 */	
			0x13, 0x0,	/* FC_OP */
/* 834 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (808) */
/* 836 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 838 */	NdrFcShort( 0x2 ),	/* 2 */
/* 840 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 842 */	NdrFcShort( 0x0 ),	/* 0 */
/* 844 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 846 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 848 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 850 */	NdrFcShort( 0x10 ),	/* 16 */
/* 852 */	NdrFcShort( 0x0 ),	/* 0 */
/* 854 */	NdrFcShort( 0x6 ),	/* Offset= 6 (860) */
/* 856 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 858 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 860 */	
			0x13, 0x0,	/* FC_OP */
/* 862 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (836) */
/* 864 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 866 */	NdrFcShort( 0x4 ),	/* 4 */
/* 868 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 870 */	NdrFcShort( 0x0 ),	/* 0 */
/* 872 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 874 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 876 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 878 */	NdrFcShort( 0x10 ),	/* 16 */
/* 880 */	NdrFcShort( 0x0 ),	/* 0 */
/* 882 */	NdrFcShort( 0x6 ),	/* Offset= 6 (888) */
/* 884 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 886 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 888 */	
			0x13, 0x0,	/* FC_OP */
/* 890 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (864) */
/* 892 */	
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 894 */	NdrFcShort( 0x8 ),	/* 8 */
/* 896 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 898 */	NdrFcShort( 0x0 ),	/* 0 */
/* 900 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 902 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 904 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 906 */	NdrFcShort( 0x10 ),	/* 16 */
/* 908 */	NdrFcShort( 0x0 ),	/* 0 */
/* 910 */	NdrFcShort( 0x6 ),	/* Offset= 6 (916) */
/* 912 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 914 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 916 */	
			0x13, 0x0,	/* FC_OP */
/* 918 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (892) */
/* 920 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 922 */	NdrFcShort( 0x8 ),	/* 8 */
/* 924 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 926 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 928 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 930 */	NdrFcShort( 0x8 ),	/* 8 */
/* 932 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 934 */	NdrFcShort( 0xffc8 ),	/* -56 */
/* 936 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 938 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 940 */	NdrFcShort( 0xffec ),	/* Offset= -20 (920) */
/* 942 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 944 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 946 */	NdrFcShort( 0x38 ),	/* 56 */
/* 948 */	NdrFcShort( 0xffec ),	/* Offset= -20 (928) */
/* 950 */	NdrFcShort( 0x0 ),	/* Offset= 0 (950) */
/* 952 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 954 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 956 */	0x40,		/* FC_STRUCTPAD4 */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 958 */	0x0,		/* 0 */
			NdrFcShort( 0xfe0f ),	/* Offset= -497 (462) */
			0x5b,		/* FC_END */
/* 962 */	
			0x13, 0x0,	/* FC_OP */
/* 964 */	NdrFcShort( 0xff04 ),	/* Offset= -252 (712) */
/* 966 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 968 */	0x1,		/* FC_BYTE */
			0x5c,		/* FC_PAD */
/* 970 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 972 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 974 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 976 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 978 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 980 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 982 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 984 */	0xa,		/* FC_FLOAT */
			0x5c,		/* FC_PAD */
/* 986 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 988 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 990 */	
			0x13, 0x0,	/* FC_OP */
/* 992 */	NdrFcShort( 0xfda2 ),	/* Offset= -606 (386) */
/* 994 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 996 */	NdrFcShort( 0xfda4 ),	/* Offset= -604 (392) */
/* 998 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1000 */	NdrFcShort( 0xfdba ),	/* Offset= -582 (418) */
/* 1002 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1004 */	NdrFcShort( 0xfdc8 ),	/* Offset= -568 (436) */
/* 1006 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1008 */	NdrFcShort( 0xfdd6 ),	/* Offset= -554 (454) */
/* 1010 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1012 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1014) */
/* 1014 */	
			0x13, 0x0,	/* FC_OP */
/* 1016 */	NdrFcShort( 0x14 ),	/* Offset= 20 (1036) */
/* 1018 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 1020 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1022 */	0x6,		/* FC_SHORT */
			0x1,		/* FC_BYTE */
/* 1024 */	0x1,		/* FC_BYTE */
			0x8,		/* FC_LONG */
/* 1026 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 1028 */	
			0x13, 0x0,	/* FC_OP */
/* 1030 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (1018) */
/* 1032 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1034 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 1036 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 1038 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1040 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1042 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1042) */
/* 1044 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1046 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1048 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1050 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1052 */	NdrFcShort( 0xfc3c ),	/* Offset= -964 (88) */
/* 1054 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1056 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1058 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1060 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1062 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1064 */	NdrFcShort( 0xfc2c ),	/* Offset= -980 (84) */
/* 1066 */	
			0x11, 0x0,	/* FC_RP */
/* 1068 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1074) */
/* 1070 */	
			0x12, 0x0,	/* FC_UP */
/* 1072 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (1036) */
/* 1074 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1076 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1078 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1080 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1082 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (1070) */
/* 1084 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1086 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1088) */
/* 1088 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1090 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1092 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1094 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1096 */	NdrFcShort( 0xfd40 ),	/* Offset= -704 (392) */
/* 1098 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1100 */	NdrFcShort( 0xfbf2 ),	/* Offset= -1038 (62) */
/* 1102 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1104 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1106) */
/* 1106 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1108 */	NdrFcLong( 0xaec9ffb ),	/* 183279611 */
/* 1112 */	NdrFcShort( 0xab0d ),	/* -21747 */
/* 1114 */	NdrFcShort( 0x4a09 ),	/* 18953 */
/* 1116 */	0xbe,		/* 190 */
			0x9c,		/* 156 */
/* 1118 */	0x78,		/* 120 */
			0x85,		/* 133 */
/* 1120 */	0x7a,		/* 122 */
			0x1b,		/* 27 */
/* 1122 */	0x85,		/* 133 */
			0x80,		/* 128 */
/* 1124 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1126 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1128) */
/* 1128 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1130 */	NdrFcLong( 0x6c70bb67 ),	/* 1819327335 */
/* 1134 */	NdrFcShort( 0x3f76 ),	/* 16246 */
/* 1136 */	NdrFcShort( 0x4176 ),	/* 16758 */
/* 1138 */	0x88,		/* 136 */
			0x9,		/* 9 */
/* 1140 */	0xc6,		/* 198 */
			0x63,		/* 99 */
/* 1142 */	0x93,		/* 147 */
			0xb1,		/* 177 */
/* 1144 */	0xfa,		/* 250 */
			0x23,		/* 35 */
/* 1146 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1148 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1150) */
/* 1150 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1152 */	NdrFcLong( 0x8cdd4bbf ),	/* -1931654209 */
/* 1156 */	NdrFcShort( 0xa84c ),	/* -22452 */
/* 1158 */	NdrFcShort( 0x4c50 ),	/* 19536 */
/* 1160 */	0xb6,		/* 182 */
			0x0,		/* 0 */
/* 1162 */	0xf5,		/* 245 */
			0xe9,		/* 233 */
/* 1164 */	0x0,		/* 0 */
			0x8,		/* 8 */
/* 1166 */	0x49,		/* 73 */
			0x1d,		/* 29 */
/* 1168 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1170 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1172) */
/* 1172 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1174 */	NdrFcLong( 0x6d4874ad ),	/* 1833465005 */
/* 1178 */	NdrFcShort( 0x38a1 ),	/* 14497 */
/* 1180 */	NdrFcShort( 0x4676 ),	/* 18038 */
/* 1182 */	0xa1,		/* 161 */
			0x91,		/* 145 */
/* 1184 */	0xba,		/* 186 */
			0xa7,		/* 167 */
/* 1186 */	0x5f,		/* 95 */
			0x1,		/* 1 */
/* 1188 */	0xd2,		/* 210 */
			0x16,		/* 22 */
/* 1190 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1192 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1194) */
/* 1194 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1196 */	NdrFcLong( 0x9c77ea62 ),	/* -1669862814 */
/* 1200 */	NdrFcShort( 0x6498 ),	/* 25752 */
/* 1202 */	NdrFcShort( 0x4cf5 ),	/* 19701 */
/* 1204 */	0xaf,		/* 175 */
			0x36,		/* 54 */
/* 1206 */	0x35,		/* 53 */
			0x88,		/* 136 */
/* 1208 */	0x6b,		/* 107 */
			0x2f,		/* 47 */
/* 1210 */	0x5,		/* 5 */
			0x70,		/* 112 */
/* 1212 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1214 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1216) */
/* 1216 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1218 */	NdrFcLong( 0x6d9f6760 ),	/* 1839163232 */
/* 1222 */	NdrFcShort( 0x7a70 ),	/* 31344 */
/* 1224 */	NdrFcShort( 0x4524 ),	/* 17700 */
/* 1226 */	0x88,		/* 136 */
			0x2d,		/* 45 */
/* 1228 */	0xe8,		/* 232 */
			0xe5,		/* 229 */
/* 1230 */	0x6a,		/* 106 */
			0x21,		/* 33 */
/* 1232 */	0xe4,		/* 228 */
			0xd5,		/* 213 */
/* 1234 */	
			0x12, 0x0,	/* FC_UP */
/* 1236 */	NdrFcShort( 0xfcc4 ),	/* Offset= -828 (408) */
/* 1238 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1240 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1242 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1244 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1246 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (1234) */
/* 1248 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1250 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1252) */
/* 1252 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1254 */	NdrFcLong( 0xd4d229fa ),	/* -724424198 */
/* 1258 */	NdrFcShort( 0x87a2 ),	/* -30814 */
/* 1260 */	NdrFcShort( 0x4a22 ),	/* 18978 */
/* 1262 */	0xb5,		/* 181 */
			0x8d,		/* 141 */
/* 1264 */	0xdb,		/* 219 */
			0x58,		/* 88 */
/* 1266 */	0x98,		/* 152 */
			0xb4,		/* 180 */
/* 1268 */	0xd9,		/* 217 */
			0x2f,		/* 47 */

			0x0
        }
    };

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ] = 
        {
            
            {
            VARIANT_UserSize
            ,VARIANT_UserMarshal
            ,VARIANT_UserUnmarshal
            ,VARIANT_UserFree
            },
            {
            BSTR_UserSize
            ,BSTR_UserMarshal
            ,BSTR_UserUnmarshal
            ,BSTR_UserFree
            }

        };



/* Standard interface: __MIDL_itf_mwcomtypes_0000_0000, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IObjectInfo, ver. 0.0,
   GUID={0x92EA75F7,0x994E,0x4925,{0x8C,0x88,0x2F,0x9C,0x56,0xF8,0x77,0x56}} */

#pragma code_seg(".orpc")
static const unsigned short IObjectInfo_FormatStringOffsetTable[] =
    {
    0,
    44
    };

static const MIDL_STUBLESS_PROXY_INFO IObjectInfo_ProxyInfo =
    {
    &Object_StubDesc,
    mwcomtypes__MIDL_ProcFormatString.Format,
    &IObjectInfo_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IObjectInfo_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    mwcomtypes__MIDL_ProcFormatString.Format,
    &IObjectInfo_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(5) _IObjectInfoProxyVtbl = 
{
    &IObjectInfo_ProxyInfo,
    &IID_IObjectInfo,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IObjectInfo::GetIsRange */ ,
    (void *) (INT_PTR) -1 /* IObjectInfo::GetIsObject */
};

const CInterfaceStubVtbl _IObjectInfoStubVtbl =
{
    &IID_IObjectInfo,
    &IObjectInfo_ServerInfo,
    5,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IMWArrayFormatFlags, ver. 0.0,
   GUID={0x30C8EBCB,0x1A50,0x4dee,{0xA5,0xE8,0x0C,0x6F,0x7D,0xD5,0x2D,0x4C}} */

#pragma code_seg(".orpc")
static const unsigned short IMWArrayFormatFlags_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    88,
    126,
    164,
    202,
    240,
    278,
    316,
    354,
    392,
    430,
    468,
    506
    };

static const MIDL_STUBLESS_PROXY_INFO IMWArrayFormatFlags_ProxyInfo =
    {
    &Object_StubDesc,
    mwcomtypes__MIDL_ProcFormatString.Format,
    &IMWArrayFormatFlags_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IMWArrayFormatFlags_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    mwcomtypes__MIDL_ProcFormatString.Format,
    &IMWArrayFormatFlags_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(19) _IMWArrayFormatFlagsProxyVtbl = 
{
    &IMWArrayFormatFlags_ProxyInfo,
    &IID_IMWArrayFormatFlags,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IMWArrayFormatFlags::get_InputArrayFormat */ ,
    (void *) (INT_PTR) -1 /* IMWArrayFormatFlags::put_InputArrayFormat */ ,
    (void *) (INT_PTR) -1 /* IMWArrayFormatFlags::get_InputArrayIndFlag */ ,
    (void *) (INT_PTR) -1 /* IMWArrayFormatFlags::put_InputArrayIndFlag */ ,
    (void *) (INT_PTR) -1 /* IMWArrayFormatFlags::get_OutputArrayFormat */ ,
    (void *) (INT_PTR) -1 /* IMWArrayFormatFlags::put_OutputArrayFormat */ ,
    (void *) (INT_PTR) -1 /* IMWArrayFormatFlags::get_OutputArrayIndFlag */ ,
    (void *) (INT_PTR) -1 /* IMWArrayFormatFlags::put_OutputArrayIndFlag */ ,
    (void *) (INT_PTR) -1 /* IMWArrayFormatFlags::get_AutoResizeOutput */ ,
    (void *) (INT_PTR) -1 /* IMWArrayFormatFlags::put_AutoResizeOutput */ ,
    (void *) (INT_PTR) -1 /* IMWArrayFormatFlags::get_TransposeOutput */ ,
    (void *) (INT_PTR) -1 /* IMWArrayFormatFlags::put_TransposeOutput */
};


static const PRPC_STUB_FUNCTION IMWArrayFormatFlags_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IMWArrayFormatFlagsStubVtbl =
{
    &IID_IMWArrayFormatFlags,
    &IMWArrayFormatFlags_ServerInfo,
    19,
    &IMWArrayFormatFlags_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IMWDataConversionFlags, ver. 0.0,
   GUID={0x5E0BBECB,0xCE72,0x4461,{0xAD,0xB8,0x04,0x46,0xAB,0x32,0xCF,0x51}} */

#pragma code_seg(".orpc")
static const unsigned short IMWDataConversionFlags_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    88,
    126,
    544,
    582,
    620,
    658,
    316,
    354
    };

static const MIDL_STUBLESS_PROXY_INFO IMWDataConversionFlags_ProxyInfo =
    {
    &Object_StubDesc,
    mwcomtypes__MIDL_ProcFormatString.Format,
    &IMWDataConversionFlags_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IMWDataConversionFlags_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    mwcomtypes__MIDL_ProcFormatString.Format,
    &IMWDataConversionFlags_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(15) _IMWDataConversionFlagsProxyVtbl = 
{
    &IMWDataConversionFlags_ProxyInfo,
    &IID_IMWDataConversionFlags,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IMWDataConversionFlags::get_CoerceNumericToType */ ,
    (void *) (INT_PTR) -1 /* IMWDataConversionFlags::put_CoerceNumericToType */ ,
    (void *) (INT_PTR) -1 /* IMWDataConversionFlags::get_InputDateFormat */ ,
    (void *) (INT_PTR) -1 /* IMWDataConversionFlags::put_InputDateFormat */ ,
    (void *) (INT_PTR) -1 /* IMWDataConversionFlags::get_OutputAsDate */ ,
    (void *) (INT_PTR) -1 /* IMWDataConversionFlags::put_OutputAsDate */ ,
    (void *) (INT_PTR) -1 /* IMWDataConversionFlags::get_DateBias */ ,
    (void *) (INT_PTR) -1 /* IMWDataConversionFlags::put_DateBias */
};


static const PRPC_STUB_FUNCTION IMWDataConversionFlags_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IMWDataConversionFlagsStubVtbl =
{
    &IID_IMWDataConversionFlags,
    &IMWDataConversionFlags_ServerInfo,
    15,
    &IMWDataConversionFlags_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IMWFlags, ver. 0.0,
   GUID={0x0A295776,0x23A1,0x410a,{0x94,0xBD,0x0C,0x6C,0x61,0xB8,0x91,0xB7}} */

#pragma code_seg(".orpc")
static const unsigned short IMWFlags_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    696,
    734,
    772,
    810,
    848
    };

static const MIDL_STUBLESS_PROXY_INFO IMWFlags_ProxyInfo =
    {
    &Object_StubDesc,
    mwcomtypes__MIDL_ProcFormatString.Format,
    &IMWFlags_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IMWFlags_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    mwcomtypes__MIDL_ProcFormatString.Format,
    &IMWFlags_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(12) _IMWFlagsProxyVtbl = 
{
    &IMWFlags_ProxyInfo,
    &IID_IMWFlags,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IMWFlags::get_ArrayFormatFlags */ ,
    (void *) (INT_PTR) -1 /* IMWFlags::put_ArrayFormatFlags */ ,
    (void *) (INT_PTR) -1 /* IMWFlags::get_DataConversionFlags */ ,
    (void *) (INT_PTR) -1 /* IMWFlags::put_DataConversionFlags */ ,
    (void *) (INT_PTR) -1 /* IMWFlags::Clone */
};


static const PRPC_STUB_FUNCTION IMWFlags_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IMWFlagsStubVtbl =
{
    &IID_IMWFlags,
    &IMWFlags_ServerInfo,
    12,
    &IMWFlags_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IMWField, ver. 0.0,
   GUID={0x0AEC9FFB,0xAB0D,0x4a09,{0xBE,0x9C,0x78,0x85,0x7A,0x1B,0x85,0x80}} */

#pragma code_seg(".orpc")
static const unsigned short IMWField_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    886,
    924,
    962,
    1000,
    1038,
    1076
    };

static const MIDL_STUBLESS_PROXY_INFO IMWField_ProxyInfo =
    {
    &Object_StubDesc,
    mwcomtypes__MIDL_ProcFormatString.Format,
    &IMWField_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IMWField_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    mwcomtypes__MIDL_ProcFormatString.Format,
    &IMWField_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(13) _IMWFieldProxyVtbl = 
{
    &IMWField_ProxyInfo,
    &IID_IMWField,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IMWField::get_Value */ ,
    (void *) (INT_PTR) -1 /* IMWField::put_Value */ ,
    (void *) (INT_PTR) -1 /* IMWField::get_Name */ ,
    (void *) (INT_PTR) -1 /* IMWField::get_MWFlags */ ,
    (void *) (INT_PTR) -1 /* IMWField::put_MWFlags */ ,
    (void *) (INT_PTR) -1 /* IMWField::Clone */
};


static const PRPC_STUB_FUNCTION IMWField_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IMWFieldStubVtbl =
{
    &IID_IMWField,
    &IMWField_ServerInfo,
    13,
    &IMWField_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IMWStruct, ver. 0.0,
   GUID={0x6C70BB67,0x3F76,0x4176,{0x88,0x09,0xC6,0x63,0x93,0xB1,0xFA,0x23}} */

#pragma code_seg(".orpc")
static const unsigned short IMWStruct_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1114,
    1344,
    164,
    1388,
    1426,
    1464,
    1502
    };

static const MIDL_STUBLESS_PROXY_INFO IMWStruct_ProxyInfo =
    {
    &Object_StubDesc,
    mwcomtypes__MIDL_ProcFormatString.Format,
    &IMWStruct_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IMWStruct_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    mwcomtypes__MIDL_ProcFormatString.Format,
    &IMWStruct_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(14) _IMWStructProxyVtbl = 
{
    &IMWStruct_ProxyInfo,
    &IID_IMWStruct,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IMWStruct::get_Item */ ,
    (void *) (INT_PTR) -1 /* IMWStruct::Initialize */ ,
    (void *) (INT_PTR) -1 /* IMWStruct::get_NumberOfFields */ ,
    (void *) (INT_PTR) -1 /* IMWStruct::get_NumberOfDims */ ,
    (void *) (INT_PTR) -1 /* IMWStruct::get_Dims */ ,
    (void *) (INT_PTR) -1 /* IMWStruct::get_FieldNames */ ,
    (void *) (INT_PTR) -1 /* IMWStruct::Clone */
};


static const PRPC_STUB_FUNCTION IMWStruct_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IMWStructStubVtbl =
{
    &IID_IMWStruct,
    &IMWStruct_ServerInfo,
    14,
    &IMWStruct_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IMWComplex, ver. 0.0,
   GUID={0x8CDD4BBF,0xA84C,0x4C50,{0xB6,0x00,0xF5,0xE9,0x00,0x08,0x49,0x1D}} */

#pragma code_seg(".orpc")
static const unsigned short IMWComplex_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1540,
    1578,
    1616,
    1654,
    1692,
    1730,
    1768
    };

static const MIDL_STUBLESS_PROXY_INFO IMWComplex_ProxyInfo =
    {
    &Object_StubDesc,
    mwcomtypes__MIDL_ProcFormatString.Format,
    &IMWComplex_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IMWComplex_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    mwcomtypes__MIDL_ProcFormatString.Format,
    &IMWComplex_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(14) _IMWComplexProxyVtbl = 
{
    &IMWComplex_ProxyInfo,
    &IID_IMWComplex,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IMWComplex::get_Real */ ,
    (void *) (INT_PTR) -1 /* IMWComplex::put_Real */ ,
    (void *) (INT_PTR) -1 /* IMWComplex::get_Imag */ ,
    (void *) (INT_PTR) -1 /* IMWComplex::put_Imag */ ,
    (void *) (INT_PTR) -1 /* IMWComplex::get_MWFlags */ ,
    (void *) (INT_PTR) -1 /* IMWComplex::put_MWFlags */ ,
    (void *) (INT_PTR) -1 /* IMWComplex::Clone */
};


static const PRPC_STUB_FUNCTION IMWComplex_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IMWComplexStubVtbl =
{
    &IID_IMWComplex,
    &IMWComplex_ServerInfo,
    14,
    &IMWComplex_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IMWSparse, ver. 0.0,
   GUID={0x6D4874AD,0x38A1,0x4676,{0xA1,0x91,0xBA,0xA7,0x5F,0x01,0xD2,0x16}} */

#pragma code_seg(".orpc")
static const unsigned short IMWSparse_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1806,
    1844,
    164,
    202,
    1882,
    1920,
    1958,
    1996,
    2034,
    2072,
    2110,
    2148,
    2186
    };

static const MIDL_STUBLESS_PROXY_INFO IMWSparse_ProxyInfo =
    {
    &Object_StubDesc,
    mwcomtypes__MIDL_ProcFormatString.Format,
    &IMWSparse_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IMWSparse_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    mwcomtypes__MIDL_ProcFormatString.Format,
    &IMWSparse_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(20) _IMWSparseProxyVtbl = 
{
    &IMWSparse_ProxyInfo,
    &IID_IMWSparse,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IMWSparse::get_Array */ ,
    (void *) (INT_PTR) -1 /* IMWSparse::put_Array */ ,
    (void *) (INT_PTR) -1 /* IMWSparse::get_NumRows */ ,
    (void *) (INT_PTR) -1 /* IMWSparse::put_NumRows */ ,
    (void *) (INT_PTR) -1 /* IMWSparse::get_NumColumns */ ,
    (void *) (INT_PTR) -1 /* IMWSparse::put_NumColumns */ ,
    (void *) (INT_PTR) -1 /* IMWSparse::get_RowIndex */ ,
    (void *) (INT_PTR) -1 /* IMWSparse::put_RowIndex */ ,
    (void *) (INT_PTR) -1 /* IMWSparse::get_ColumnIndex */ ,
    (void *) (INT_PTR) -1 /* IMWSparse::put_ColumnIndex */ ,
    (void *) (INT_PTR) -1 /* IMWSparse::get_MWFlags */ ,
    (void *) (INT_PTR) -1 /* IMWSparse::put_MWFlags */ ,
    (void *) (INT_PTR) -1 /* IMWSparse::Clone */
};


static const PRPC_STUB_FUNCTION IMWSparse_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IMWSparseStubVtbl =
{
    &IID_IMWSparse,
    &IMWSparse_ServerInfo,
    20,
    &IMWSparse_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IMWArg, ver. 0.0,
   GUID={0x9C77EA62,0x6498,0x4CF5,{0xAF,0x36,0x35,0x88,0x6B,0x2F,0x05,0x70}} */

#pragma code_seg(".orpc")
static const unsigned short IMWArg_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    2224,
    2262,
    2300,
    2338,
    2376
    };

static const MIDL_STUBLESS_PROXY_INFO IMWArg_ProxyInfo =
    {
    &Object_StubDesc,
    mwcomtypes__MIDL_ProcFormatString.Format,
    &IMWArg_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IMWArg_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    mwcomtypes__MIDL_ProcFormatString.Format,
    &IMWArg_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(12) _IMWArgProxyVtbl = 
{
    &IMWArg_ProxyInfo,
    &IID_IMWArg,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IMWArg::get_Value */ ,
    (void *) (INT_PTR) -1 /* IMWArg::put_Value */ ,
    (void *) (INT_PTR) -1 /* IMWArg::get_MWFlags */ ,
    (void *) (INT_PTR) -1 /* IMWArg::put_MWFlags */ ,
    (void *) (INT_PTR) -1 /* IMWArg::Clone */
};


static const PRPC_STUB_FUNCTION IMWArg_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IMWArgStubVtbl =
{
    &IID_IMWArg,
    &IMWArg_ServerInfo,
    12,
    &IMWArg_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Standard interface: __MIDL_itf_mwcomtypes_0000_0009, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IMWEnumVararg, ver. 0.0,
   GUID={0xD4D229FA,0x87A2,0x4a22,{0xB5,0x8D,0xDB,0x58,0x98,0xB4,0xD9,0x2F}} */

#pragma code_seg(".orpc")
static const unsigned short IMWEnumVararg_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    2414,
    2458,
    2496,
    2534,
    2572,
    2610,
    2648,
    354,
    2680,
    2724,
    2762,
    2800,
    2832,
    2876,
    2914,
    2952
    };

static const MIDL_STUBLESS_PROXY_INFO IMWEnumVararg_ProxyInfo =
    {
    &Object_StubDesc,
    mwcomtypes__MIDL_ProcFormatString.Format,
    &IMWEnumVararg_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IMWEnumVararg_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    mwcomtypes__MIDL_ProcFormatString.Format,
    &IMWEnumVararg_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(23) _IMWEnumVarargProxyVtbl = 
{
    &IMWEnumVararg_ProxyInfo,
    &IID_IMWEnumVararg,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IMWEnumVararg::get_Item */ ,
    (void *) (INT_PTR) -1 /* IMWEnumVararg::get_Name */ ,
    (void *) (INT_PTR) -1 /* IMWEnumVararg::put_Name */ ,
    (void *) (INT_PTR) -1 /* IMWEnumVararg::get_Value */ ,
    (void *) (INT_PTR) -1 /* IMWEnumVararg::put_Value */ ,
    (void *) (INT_PTR) -1 /* IMWEnumVararg::get_Count */ ,
    (void *) (INT_PTR) -1 /* IMWEnumVararg::Reset */ ,
    (void *) (INT_PTR) -1 /* IMWEnumVararg::Skip */ ,
    (void *) (INT_PTR) -1 /* IMWEnumVararg::Next */ ,
    (void *) (INT_PTR) -1 /* IMWEnumVararg::Add */ ,
    (void *) (INT_PTR) -1 /* IMWEnumVararg::Remove */ ,
    (void *) (INT_PTR) -1 /* IMWEnumVararg::Clear */ ,
    (void *) (INT_PTR) -1 /* IMWEnumVararg::SetAt */ ,
    (void *) (INT_PTR) -1 /* IMWEnumVararg::put_CopyToRange */ ,
    (void *) (INT_PTR) -1 /* IMWEnumVararg::get_CopyToRange */ ,
    (void *) (INT_PTR) -1 /* IMWEnumVararg::Clone */
};


static const PRPC_STUB_FUNCTION IMWEnumVararg_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IMWEnumVarargStubVtbl =
{
    &IID_IMWEnumVararg,
    &IMWEnumVararg_ServerInfo,
    23,
    &IMWEnumVararg_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IMWMethodArgInfo, ver. 0.0,
   GUID={0x6D9F6760,0x7A70,0x4524,{0x88,0x2D,0xE8,0xE5,0x6A,0x21,0xE4,0xD5}} */

#pragma code_seg(".orpc")
static const unsigned short IMWMethodArgInfo_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    2990,
    3028,
    962,
    3066,
    620,
    3104,
    316,
    3142,
    392,
    3180,
    3218,
    3256,
    3294,
    3332,
    3370,
    3408,
    3446,
    3478,
    3516,
    3554,
    3610
    };

static const MIDL_STUBLESS_PROXY_INFO IMWMethodArgInfo_ProxyInfo =
    {
    &Object_StubDesc,
    mwcomtypes__MIDL_ProcFormatString.Format,
    &IMWMethodArgInfo_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IMWMethodArgInfo_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    mwcomtypes__MIDL_ProcFormatString.Format,
    &IMWMethodArgInfo_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(28) _IMWMethodArgInfoProxyVtbl = 
{
    &IMWMethodArgInfo_ProxyInfo,
    &IID_IMWMethodArgInfo,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IMWMethodArgInfo::get_Value */ ,
    (void *) (INT_PTR) -1 /* IMWMethodArgInfo::put_Value */ ,
    (void *) (INT_PTR) -1 /* IMWMethodArgInfo::get_Name */ ,
    (void *) (INT_PTR) -1 /* IMWMethodArgInfo::put_Name */ ,
    (void *) (INT_PTR) -1 /* IMWMethodArgInfo::get_Type */ ,
    (void *) (INT_PTR) -1 /* IMWMethodArgInfo::get_Flags */ ,
    (void *) (INT_PTR) -1 /* IMWMethodArgInfo::get_Indirection */ ,
    (void *) (INT_PTR) -1 /* IMWMethodArgInfo::get_IsRange */ ,
    (void *) (INT_PTR) -1 /* IMWMethodArgInfo::get_IsVararg */ ,
    (void *) (INT_PTR) -1 /* IMWMethodArgInfo::get_MWFlags */ ,
    (void *) (INT_PTR) -1 /* IMWMethodArgInfo::put_MWFlags */ ,
    (void *) (INT_PTR) -1 /* IMWMethodArgInfo::get_Selected */ ,
    (void *) (INT_PTR) -1 /* IMWMethodArgInfo::get_Vararg */ ,
    (void *) (INT_PTR) -1 /* IMWMethodArgInfo::put_Vararg */ ,
    (void *) (INT_PTR) -1 /* IMWMethodArgInfo::put_CopyToRange */ ,
    (void *) (INT_PTR) -1 /* IMWMethodArgInfo::get_CopyToRange */ ,
    (void *) (INT_PTR) -1 /* IMWMethodArgInfo::Select */ ,
    (void *) (INT_PTR) -1 /* IMWMethodArgInfo::get_IsListening */ ,
    (void *) (INT_PTR) -1 /* IMWMethodArgInfo::put_IsListening */ ,
    (void *) (INT_PTR) -1 /* IMWMethodArgInfo::Offset */ ,
    (void *) (INT_PTR) -1 /* IMWMethodArgInfo::Clone */
};


static const PRPC_STUB_FUNCTION IMWMethodArgInfo_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IMWMethodArgInfoStubVtbl =
{
    &IID_IMWMethodArgInfo,
    &IMWMethodArgInfo_ServerInfo,
    28,
    &IMWMethodArgInfo_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    mwcomtypes__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x70001f4, /* MIDL Version 7.0.500 */
    0,
    UserMarshalRoutines,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };

const CInterfaceProxyVtbl * _mwcomtypes_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IMWMethodArgInfoProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IMWArgProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IMWStructProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IMWFlagsProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IMWSparseProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IMWComplexProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IMWDataConversionFlagsProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IMWArrayFormatFlagsProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IObjectInfoProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IMWEnumVarargProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IMWFieldProxyVtbl,
    0
};

const CInterfaceStubVtbl * _mwcomtypes_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IMWMethodArgInfoStubVtbl,
    ( CInterfaceStubVtbl *) &_IMWArgStubVtbl,
    ( CInterfaceStubVtbl *) &_IMWStructStubVtbl,
    ( CInterfaceStubVtbl *) &_IMWFlagsStubVtbl,
    ( CInterfaceStubVtbl *) &_IMWSparseStubVtbl,
    ( CInterfaceStubVtbl *) &_IMWComplexStubVtbl,
    ( CInterfaceStubVtbl *) &_IMWDataConversionFlagsStubVtbl,
    ( CInterfaceStubVtbl *) &_IMWArrayFormatFlagsStubVtbl,
    ( CInterfaceStubVtbl *) &_IObjectInfoStubVtbl,
    ( CInterfaceStubVtbl *) &_IMWEnumVarargStubVtbl,
    ( CInterfaceStubVtbl *) &_IMWFieldStubVtbl,
    0
};

PCInterfaceName const _mwcomtypes_InterfaceNamesList[] = 
{
    "IMWMethodArgInfo",
    "IMWArg",
    "IMWStruct",
    "IMWFlags",
    "IMWSparse",
    "IMWComplex",
    "IMWDataConversionFlags",
    "IMWArrayFormatFlags",
    "IObjectInfo",
    "IMWEnumVararg",
    "IMWField",
    0
};

const IID *  _mwcomtypes_BaseIIDList[] = 
{
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    0,
    &IID_IDispatch,
    &IID_IDispatch,
    0
};


#define _mwcomtypes_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _mwcomtypes, pIID, n)

int __stdcall _mwcomtypes_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _mwcomtypes, 11, 8 )
    IID_BS_LOOKUP_NEXT_TEST( _mwcomtypes, 4 )
    IID_BS_LOOKUP_NEXT_TEST( _mwcomtypes, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _mwcomtypes, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _mwcomtypes, 11, *pIndex )
    
}

const ExtendedProxyFileInfo mwcomtypes_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _mwcomtypes_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _mwcomtypes_StubVtblList,
    (const PCInterfaceName * ) & _mwcomtypes_InterfaceNamesList,
    (const IID ** ) & _mwcomtypes_BaseIIDList,
    & _mwcomtypes_IID_Lookup, 
    11,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* defined(_M_AMD64)*/

