

/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Mon Sep 06 16:12:45 2010
 */
/* Compiler settings for c:\Program Files\MATLAB\R2010a\extern\include\mwcomtypes.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#if !defined(_M_IA64) && !defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/
#pragma warning( disable: 4152 )  /* function/data pointer conversion in expression */
#pragma warning( disable: 4100 ) /* unreferenced arguments in x86 call */

#pragma optimize("", off ) 

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

#define TYPE_FORMAT_STRING_SIZE   1317                              
#define PROC_FORMAT_STRING_SIZE   3469                              
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

#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT50_OR_LATER)
#error You need a Windows 2000 or later to run this stub because it uses these features:
#error   /robust command line switch.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will fail with the RPC_X_WRONG_STUB_VERSION error.
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
/*  8 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 10 */	NdrFcShort( 0x8 ),	/* 8 */
/* 12 */	NdrFcShort( 0x22 ),	/* 34 */
/* 14 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 16 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter n */

/* 24 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 26 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 28 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pbIsRange */

/* 30 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 32 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 34 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 36 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 38 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 40 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetIsObject */

/* 42 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 44 */	NdrFcLong( 0x0 ),	/* 0 */
/* 48 */	NdrFcShort( 0x4 ),	/* 4 */
/* 50 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 52 */	NdrFcShort( 0x8 ),	/* 8 */
/* 54 */	NdrFcShort( 0x22 ),	/* 34 */
/* 56 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 58 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 60 */	NdrFcShort( 0x0 ),	/* 0 */
/* 62 */	NdrFcShort( 0x0 ),	/* 0 */
/* 64 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter n */

/* 66 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 68 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 70 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pbIsObject */

/* 72 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 74 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 76 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 78 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 80 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 82 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_CoerceNumericToType */


	/* Procedure get_InputArrayFormat */

/* 84 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 86 */	NdrFcLong( 0x0 ),	/* 0 */
/* 90 */	NdrFcShort( 0x7 ),	/* 7 */
/* 92 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 94 */	NdrFcShort( 0x0 ),	/* 0 */
/* 96 */	NdrFcShort( 0x22 ),	/* 34 */
/* 98 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 100 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 102 */	NdrFcShort( 0x0 ),	/* 0 */
/* 104 */	NdrFcShort( 0x0 ),	/* 0 */
/* 106 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pType */


	/* Parameter pInputFmt */

/* 108 */	NdrFcShort( 0x2010 ),	/* Flags:  out, srv alloc size=8 */
/* 110 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 112 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Return value */


	/* Return value */

/* 114 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 116 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 118 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_CoerceNumericToType */


	/* Procedure put_InputArrayFormat */

/* 120 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 122 */	NdrFcLong( 0x0 ),	/* 0 */
/* 126 */	NdrFcShort( 0x8 ),	/* 8 */
/* 128 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 130 */	NdrFcShort( 0x6 ),	/* 6 */
/* 132 */	NdrFcShort( 0x8 ),	/* 8 */
/* 134 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 136 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 138 */	NdrFcShort( 0x0 ),	/* 0 */
/* 140 */	NdrFcShort( 0x0 ),	/* 0 */
/* 142 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Type */


	/* Parameter InputFmt */

/* 144 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 146 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 148 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 150 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 152 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 154 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_NumRows */


	/* Procedure get_NumberOfFields */


	/* Procedure get_InputArrayIndFlag */

/* 156 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 158 */	NdrFcLong( 0x0 ),	/* 0 */
/* 162 */	NdrFcShort( 0x9 ),	/* 9 */
/* 164 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 166 */	NdrFcShort( 0x0 ),	/* 0 */
/* 168 */	NdrFcShort( 0x24 ),	/* 36 */
/* 170 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 172 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 174 */	NdrFcShort( 0x0 ),	/* 0 */
/* 176 */	NdrFcShort( 0x0 ),	/* 0 */
/* 178 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pnRows */


	/* Parameter pnFields */


	/* Parameter pnInputInd */

/* 180 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 182 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 184 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 186 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 188 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 190 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_NumRows */


	/* Procedure put_InputArrayIndFlag */

/* 192 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 194 */	NdrFcLong( 0x0 ),	/* 0 */
/* 198 */	NdrFcShort( 0xa ),	/* 10 */
/* 200 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 202 */	NdrFcShort( 0x8 ),	/* 8 */
/* 204 */	NdrFcShort( 0x8 ),	/* 8 */
/* 206 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 208 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 210 */	NdrFcShort( 0x0 ),	/* 0 */
/* 212 */	NdrFcShort( 0x0 ),	/* 0 */
/* 214 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter nRows */


	/* Parameter nInputInd */

/* 216 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 218 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 220 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 222 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 224 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 226 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_OutputArrayFormat */

/* 228 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 230 */	NdrFcLong( 0x0 ),	/* 0 */
/* 234 */	NdrFcShort( 0xb ),	/* 11 */
/* 236 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 238 */	NdrFcShort( 0x0 ),	/* 0 */
/* 240 */	NdrFcShort( 0x22 ),	/* 34 */
/* 242 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 244 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 246 */	NdrFcShort( 0x0 ),	/* 0 */
/* 248 */	NdrFcShort( 0x0 ),	/* 0 */
/* 250 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pOutputFmt */

/* 252 */	NdrFcShort( 0x2010 ),	/* Flags:  out, srv alloc size=8 */
/* 254 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 256 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Return value */

/* 258 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 260 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 262 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_OutputArrayFormat */

/* 264 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 266 */	NdrFcLong( 0x0 ),	/* 0 */
/* 270 */	NdrFcShort( 0xc ),	/* 12 */
/* 272 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 274 */	NdrFcShort( 0x6 ),	/* 6 */
/* 276 */	NdrFcShort( 0x8 ),	/* 8 */
/* 278 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 280 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 282 */	NdrFcShort( 0x0 ),	/* 0 */
/* 284 */	NdrFcShort( 0x0 ),	/* 0 */
/* 286 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter OutputFmt */

/* 288 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 290 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 292 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Return value */

/* 294 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 296 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 298 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Indirection */


	/* Procedure get_DateBias */


	/* Procedure get_OutputArrayIndFlag */

/* 300 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 302 */	NdrFcLong( 0x0 ),	/* 0 */
/* 306 */	NdrFcShort( 0xd ),	/* 13 */
/* 308 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 310 */	NdrFcShort( 0x0 ),	/* 0 */
/* 312 */	NdrFcShort( 0x24 ),	/* 36 */
/* 314 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 316 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 318 */	NdrFcShort( 0x0 ),	/* 0 */
/* 320 */	NdrFcShort( 0x0 ),	/* 0 */
/* 322 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pnInd */


	/* Parameter pnBias */


	/* Parameter pnOutputInd */

/* 324 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 326 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 328 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 330 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 332 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 334 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Skip */


	/* Procedure put_DateBias */


	/* Procedure put_OutputArrayIndFlag */

/* 336 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 338 */	NdrFcLong( 0x0 ),	/* 0 */
/* 342 */	NdrFcShort( 0xe ),	/* 14 */
/* 344 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 346 */	NdrFcShort( 0x8 ),	/* 8 */
/* 348 */	NdrFcShort( 0x8 ),	/* 8 */
/* 350 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 352 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 354 */	NdrFcShort( 0x0 ),	/* 0 */
/* 356 */	NdrFcShort( 0x0 ),	/* 0 */
/* 358 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter nSkipElms */


	/* Parameter nBias */


	/* Parameter nOutputInd */

/* 360 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 362 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 364 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 366 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 368 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 370 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_IsVararg */


	/* Procedure get_AutoResizeOutput */

/* 372 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 374 */	NdrFcLong( 0x0 ),	/* 0 */
/* 378 */	NdrFcShort( 0xf ),	/* 15 */
/* 380 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 382 */	NdrFcShort( 0x0 ),	/* 0 */
/* 384 */	NdrFcShort( 0x22 ),	/* 34 */
/* 386 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 388 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 390 */	NdrFcShort( 0x0 ),	/* 0 */
/* 392 */	NdrFcShort( 0x0 ),	/* 0 */
/* 394 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbVararg */


	/* Parameter pbResize */

/* 396 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 398 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 400 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 402 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 404 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 406 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_AutoResizeOutput */

/* 408 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 410 */	NdrFcLong( 0x0 ),	/* 0 */
/* 414 */	NdrFcShort( 0x10 ),	/* 16 */
/* 416 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 418 */	NdrFcShort( 0x6 ),	/* 6 */
/* 420 */	NdrFcShort( 0x8 ),	/* 8 */
/* 422 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 424 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 426 */	NdrFcShort( 0x0 ),	/* 0 */
/* 428 */	NdrFcShort( 0x0 ),	/* 0 */
/* 430 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bResize */

/* 432 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 434 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 436 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 438 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 440 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 442 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_TransposeOutput */

/* 444 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 446 */	NdrFcLong( 0x0 ),	/* 0 */
/* 450 */	NdrFcShort( 0x11 ),	/* 17 */
/* 452 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 454 */	NdrFcShort( 0x0 ),	/* 0 */
/* 456 */	NdrFcShort( 0x22 ),	/* 34 */
/* 458 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 460 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 462 */	NdrFcShort( 0x0 ),	/* 0 */
/* 464 */	NdrFcShort( 0x0 ),	/* 0 */
/* 466 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbTranspose */

/* 468 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 470 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 472 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 474 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 476 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 478 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_TransposeOutput */

/* 480 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 482 */	NdrFcLong( 0x0 ),	/* 0 */
/* 486 */	NdrFcShort( 0x12 ),	/* 18 */
/* 488 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 490 */	NdrFcShort( 0x6 ),	/* 6 */
/* 492 */	NdrFcShort( 0x8 ),	/* 8 */
/* 494 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 496 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 498 */	NdrFcShort( 0x0 ),	/* 0 */
/* 500 */	NdrFcShort( 0x0 ),	/* 0 */
/* 502 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bTranspose */

/* 504 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 506 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 508 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 510 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 512 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 514 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_InputDateFormat */

/* 516 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 518 */	NdrFcLong( 0x0 ),	/* 0 */
/* 522 */	NdrFcShort( 0x9 ),	/* 9 */
/* 524 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 526 */	NdrFcShort( 0x0 ),	/* 0 */
/* 528 */	NdrFcShort( 0x22 ),	/* 34 */
/* 530 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 532 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 534 */	NdrFcShort( 0x0 ),	/* 0 */
/* 536 */	NdrFcShort( 0x0 ),	/* 0 */
/* 538 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDateFmt */

/* 540 */	NdrFcShort( 0x2010 ),	/* Flags:  out, srv alloc size=8 */
/* 542 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 544 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Return value */

/* 546 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 548 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 550 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_InputDateFormat */

/* 552 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 554 */	NdrFcLong( 0x0 ),	/* 0 */
/* 558 */	NdrFcShort( 0xa ),	/* 10 */
/* 560 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 562 */	NdrFcShort( 0x6 ),	/* 6 */
/* 564 */	NdrFcShort( 0x8 ),	/* 8 */
/* 566 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 568 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 570 */	NdrFcShort( 0x0 ),	/* 0 */
/* 572 */	NdrFcShort( 0x0 ),	/* 0 */
/* 574 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter DateFmt */

/* 576 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 578 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 580 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Return value */

/* 582 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 584 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 586 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Type */


	/* Procedure get_OutputAsDate */

/* 588 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 590 */	NdrFcLong( 0x0 ),	/* 0 */
/* 594 */	NdrFcShort( 0xb ),	/* 11 */
/* 596 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 598 */	NdrFcShort( 0x0 ),	/* 0 */
/* 600 */	NdrFcShort( 0x22 ),	/* 34 */
/* 602 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 604 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 606 */	NdrFcShort( 0x0 ),	/* 0 */
/* 608 */	NdrFcShort( 0x0 ),	/* 0 */
/* 610 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pnType */


	/* Parameter pbDate */

/* 612 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 614 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 616 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 618 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 620 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 622 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_OutputAsDate */

/* 624 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 626 */	NdrFcLong( 0x0 ),	/* 0 */
/* 630 */	NdrFcShort( 0xc ),	/* 12 */
/* 632 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 634 */	NdrFcShort( 0x6 ),	/* 6 */
/* 636 */	NdrFcShort( 0x8 ),	/* 8 */
/* 638 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 640 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 642 */	NdrFcShort( 0x0 ),	/* 0 */
/* 644 */	NdrFcShort( 0x0 ),	/* 0 */
/* 646 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bDate */

/* 648 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 650 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 652 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 654 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 656 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 658 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ArrayFormatFlags */

/* 660 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 662 */	NdrFcLong( 0x0 ),	/* 0 */
/* 666 */	NdrFcShort( 0x7 ),	/* 7 */
/* 668 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 670 */	NdrFcShort( 0x0 ),	/* 0 */
/* 672 */	NdrFcShort( 0x8 ),	/* 8 */
/* 674 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 676 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 678 */	NdrFcShort( 0x0 ),	/* 0 */
/* 680 */	NdrFcShort( 0x0 ),	/* 0 */
/* 682 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppFlags */

/* 684 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 686 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 688 */	NdrFcShort( 0xe ),	/* Type Offset=14 */

	/* Return value */

/* 690 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 692 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 694 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ArrayFormatFlags */

/* 696 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 698 */	NdrFcLong( 0x0 ),	/* 0 */
/* 702 */	NdrFcShort( 0x8 ),	/* 8 */
/* 704 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 706 */	NdrFcShort( 0x0 ),	/* 0 */
/* 708 */	NdrFcShort( 0x8 ),	/* 8 */
/* 710 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 712 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 714 */	NdrFcShort( 0x0 ),	/* 0 */
/* 716 */	NdrFcShort( 0x0 ),	/* 0 */
/* 718 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFlags */

/* 720 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 722 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 724 */	NdrFcShort( 0x12 ),	/* Type Offset=18 */

	/* Return value */

/* 726 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 728 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 730 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_DataConversionFlags */

/* 732 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 734 */	NdrFcLong( 0x0 ),	/* 0 */
/* 738 */	NdrFcShort( 0x9 ),	/* 9 */
/* 740 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 742 */	NdrFcShort( 0x0 ),	/* 0 */
/* 744 */	NdrFcShort( 0x8 ),	/* 8 */
/* 746 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 748 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 750 */	NdrFcShort( 0x0 ),	/* 0 */
/* 752 */	NdrFcShort( 0x0 ),	/* 0 */
/* 754 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppFlags */

/* 756 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 758 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 760 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Return value */

/* 762 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 764 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 766 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_DataConversionFlags */

/* 768 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 770 */	NdrFcLong( 0x0 ),	/* 0 */
/* 774 */	NdrFcShort( 0xa ),	/* 10 */
/* 776 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 778 */	NdrFcShort( 0x0 ),	/* 0 */
/* 780 */	NdrFcShort( 0x8 ),	/* 8 */
/* 782 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 784 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 786 */	NdrFcShort( 0x0 ),	/* 0 */
/* 788 */	NdrFcShort( 0x0 ),	/* 0 */
/* 790 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFlags */

/* 792 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 794 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 796 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Return value */

/* 798 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 800 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 802 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Clone */

/* 804 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 806 */	NdrFcLong( 0x0 ),	/* 0 */
/* 810 */	NdrFcShort( 0xb ),	/* 11 */
/* 812 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 814 */	NdrFcShort( 0x0 ),	/* 0 */
/* 816 */	NdrFcShort( 0x8 ),	/* 8 */
/* 818 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 820 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 822 */	NdrFcShort( 0x0 ),	/* 0 */
/* 824 */	NdrFcShort( 0x0 ),	/* 0 */
/* 826 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppFlags */

/* 828 */	NdrFcShort( 0x200b ),	/* Flags:  must size, must free, in, srv alloc size=8 */
/* 830 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 832 */	NdrFcShort( 0x3a ),	/* Type Offset=58 */

	/* Return value */

/* 834 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 836 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 838 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Value */

/* 840 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 842 */	NdrFcLong( 0x0 ),	/* 0 */
/* 846 */	NdrFcShort( 0x7 ),	/* 7 */
/* 848 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 850 */	NdrFcShort( 0x0 ),	/* 0 */
/* 852 */	NdrFcShort( 0x8 ),	/* 8 */
/* 854 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 856 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 858 */	NdrFcShort( 0x9f ),	/* 159 */
/* 860 */	NdrFcShort( 0x0 ),	/* 0 */
/* 862 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pvarValue */

/* 864 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 866 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 868 */	NdrFcShort( 0x452 ),	/* Type Offset=1106 */

	/* Return value */

/* 870 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 872 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 874 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Value */

/* 876 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 878 */	NdrFcLong( 0x0 ),	/* 0 */
/* 882 */	NdrFcShort( 0x8 ),	/* 8 */
/* 884 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 886 */	NdrFcShort( 0x0 ),	/* 0 */
/* 888 */	NdrFcShort( 0x8 ),	/* 8 */
/* 890 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 892 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 894 */	NdrFcShort( 0x0 ),	/* 0 */
/* 896 */	NdrFcShort( 0xb4 ),	/* 180 */
/* 898 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter varValue */

/* 900 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 902 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 904 */	NdrFcShort( 0x460 ),	/* Type Offset=1120 */

	/* Return value */

/* 906 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 908 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 910 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Name */


	/* Procedure get_Name */

/* 912 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 914 */	NdrFcLong( 0x0 ),	/* 0 */
/* 918 */	NdrFcShort( 0x9 ),	/* 9 */
/* 920 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 922 */	NdrFcShort( 0x0 ),	/* 0 */
/* 924 */	NdrFcShort( 0x8 ),	/* 8 */
/* 926 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 928 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 930 */	NdrFcShort( 0x1 ),	/* 1 */
/* 932 */	NdrFcShort( 0x0 ),	/* 0 */
/* 934 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbstrName */


	/* Parameter pbstrName */

/* 936 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 938 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 940 */	NdrFcShort( 0x46e ),	/* Type Offset=1134 */

	/* Return value */


	/* Return value */

/* 942 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 944 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 946 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_MWFlags */

/* 948 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 950 */	NdrFcLong( 0x0 ),	/* 0 */
/* 954 */	NdrFcShort( 0xa ),	/* 10 */
/* 956 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 958 */	NdrFcShort( 0x0 ),	/* 0 */
/* 960 */	NdrFcShort( 0x8 ),	/* 8 */
/* 962 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 964 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 966 */	NdrFcShort( 0x0 ),	/* 0 */
/* 968 */	NdrFcShort( 0x0 ),	/* 0 */
/* 970 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppFlags */

/* 972 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 974 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 976 */	NdrFcShort( 0x478 ),	/* Type Offset=1144 */

	/* Return value */

/* 978 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 980 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 982 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_MWFlags */

/* 984 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 986 */	NdrFcLong( 0x0 ),	/* 0 */
/* 990 */	NdrFcShort( 0xb ),	/* 11 */
/* 992 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 994 */	NdrFcShort( 0x0 ),	/* 0 */
/* 996 */	NdrFcShort( 0x8 ),	/* 8 */
/* 998 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1000 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1002 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1004 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1006 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFlags */

/* 1008 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1010 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1012 */	NdrFcShort( 0x3e ),	/* Type Offset=62 */

	/* Return value */

/* 1014 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1016 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1018 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Clone */

/* 1020 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1022 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1026 */	NdrFcShort( 0xc ),	/* 12 */
/* 1028 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1030 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1032 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1034 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1036 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1038 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1040 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1042 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppField */

/* 1044 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1046 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1048 */	NdrFcShort( 0x47c ),	/* Type Offset=1148 */

	/* Return value */

/* 1050 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1052 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1054 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Item */

/* 1056 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1058 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1062 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1064 */	NdrFcShort( 0x20c ),	/* x86 Stack size/offset = 524 */
/* 1066 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1068 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1070 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x22,		/* 34 */
/* 1072 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1074 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1076 */	NdrFcShort( 0x4360 ),	/* 17248 */
/* 1078 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter i0 */

/* 1080 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1082 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1084 */	NdrFcShort( 0x460 ),	/* Type Offset=1120 */

	/* Parameter i1 */

/* 1086 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1088 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1090 */	NdrFcShort( 0x460 ),	/* Type Offset=1120 */

	/* Parameter i2 */

/* 1092 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1094 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 1096 */	NdrFcShort( 0x460 ),	/* Type Offset=1120 */

	/* Parameter i3 */

/* 1098 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1100 */	NdrFcShort( 0x34 ),	/* x86 Stack size/offset = 52 */
/* 1102 */	NdrFcShort( 0x460 ),	/* Type Offset=1120 */

	/* Parameter i4 */

/* 1104 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1106 */	NdrFcShort( 0x44 ),	/* x86 Stack size/offset = 68 */
/* 1108 */	NdrFcShort( 0x460 ),	/* Type Offset=1120 */

	/* Parameter i5 */

/* 1110 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1112 */	NdrFcShort( 0x54 ),	/* x86 Stack size/offset = 84 */
/* 1114 */	NdrFcShort( 0x460 ),	/* Type Offset=1120 */

	/* Parameter i6 */

/* 1116 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1118 */	NdrFcShort( 0x64 ),	/* x86 Stack size/offset = 100 */
/* 1120 */	NdrFcShort( 0x460 ),	/* Type Offset=1120 */

	/* Parameter i7 */

/* 1122 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1124 */	NdrFcShort( 0x74 ),	/* x86 Stack size/offset = 116 */
/* 1126 */	NdrFcShort( 0x460 ),	/* Type Offset=1120 */

	/* Parameter i8 */

/* 1128 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1130 */	NdrFcShort( 0x84 ),	/* x86 Stack size/offset = 132 */
/* 1132 */	NdrFcShort( 0x460 ),	/* Type Offset=1120 */

	/* Parameter i9 */

/* 1134 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1136 */	NdrFcShort( 0x94 ),	/* x86 Stack size/offset = 148 */
/* 1138 */	NdrFcShort( 0x460 ),	/* Type Offset=1120 */

	/* Parameter i10 */

/* 1140 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1142 */	NdrFcShort( 0xa4 ),	/* x86 Stack size/offset = 164 */
/* 1144 */	NdrFcShort( 0x460 ),	/* Type Offset=1120 */

	/* Parameter i11 */

/* 1146 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1148 */	NdrFcShort( 0xb4 ),	/* x86 Stack size/offset = 180 */
/* 1150 */	NdrFcShort( 0x460 ),	/* Type Offset=1120 */

	/* Parameter i12 */

/* 1152 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1154 */	NdrFcShort( 0xc4 ),	/* x86 Stack size/offset = 196 */
/* 1156 */	NdrFcShort( 0x460 ),	/* Type Offset=1120 */

	/* Parameter i13 */

/* 1158 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1160 */	NdrFcShort( 0xd4 ),	/* x86 Stack size/offset = 212 */
/* 1162 */	NdrFcShort( 0x460 ),	/* Type Offset=1120 */

	/* Parameter i14 */

/* 1164 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1166 */	NdrFcShort( 0xe4 ),	/* x86 Stack size/offset = 228 */
/* 1168 */	NdrFcShort( 0x460 ),	/* Type Offset=1120 */

	/* Parameter i15 */

/* 1170 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1172 */	NdrFcShort( 0xf4 ),	/* x86 Stack size/offset = 244 */
/* 1174 */	NdrFcShort( 0x460 ),	/* Type Offset=1120 */

	/* Parameter i16 */

/* 1176 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1178 */	NdrFcShort( 0x104 ),	/* x86 Stack size/offset = 260 */
/* 1180 */	NdrFcShort( 0x460 ),	/* Type Offset=1120 */

	/* Parameter i17 */

/* 1182 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1184 */	NdrFcShort( 0x114 ),	/* x86 Stack size/offset = 276 */
/* 1186 */	NdrFcShort( 0x460 ),	/* Type Offset=1120 */

	/* Parameter i18 */

/* 1188 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1190 */	NdrFcShort( 0x124 ),	/* x86 Stack size/offset = 292 */
/* 1192 */	NdrFcShort( 0x460 ),	/* Type Offset=1120 */

	/* Parameter i19 */

/* 1194 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1196 */	NdrFcShort( 0x134 ),	/* x86 Stack size/offset = 308 */
/* 1198 */	NdrFcShort( 0x460 ),	/* Type Offset=1120 */

	/* Parameter i20 */

/* 1200 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1202 */	NdrFcShort( 0x144 ),	/* x86 Stack size/offset = 324 */
/* 1204 */	NdrFcShort( 0x460 ),	/* Type Offset=1120 */

	/* Parameter i21 */

/* 1206 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1208 */	NdrFcShort( 0x154 ),	/* x86 Stack size/offset = 340 */
/* 1210 */	NdrFcShort( 0x460 ),	/* Type Offset=1120 */

	/* Parameter i22 */

/* 1212 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1214 */	NdrFcShort( 0x164 ),	/* x86 Stack size/offset = 356 */
/* 1216 */	NdrFcShort( 0x460 ),	/* Type Offset=1120 */

	/* Parameter i23 */

/* 1218 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1220 */	NdrFcShort( 0x174 ),	/* x86 Stack size/offset = 372 */
/* 1222 */	NdrFcShort( 0x460 ),	/* Type Offset=1120 */

	/* Parameter i24 */

/* 1224 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1226 */	NdrFcShort( 0x184 ),	/* x86 Stack size/offset = 388 */
/* 1228 */	NdrFcShort( 0x460 ),	/* Type Offset=1120 */

	/* Parameter i25 */

/* 1230 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1232 */	NdrFcShort( 0x194 ),	/* x86 Stack size/offset = 404 */
/* 1234 */	NdrFcShort( 0x460 ),	/* Type Offset=1120 */

	/* Parameter i26 */

/* 1236 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1238 */	NdrFcShort( 0x1a4 ),	/* x86 Stack size/offset = 420 */
/* 1240 */	NdrFcShort( 0x460 ),	/* Type Offset=1120 */

	/* Parameter i27 */

/* 1242 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1244 */	NdrFcShort( 0x1b4 ),	/* x86 Stack size/offset = 436 */
/* 1246 */	NdrFcShort( 0x460 ),	/* Type Offset=1120 */

	/* Parameter i28 */

/* 1248 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1250 */	NdrFcShort( 0x1c4 ),	/* x86 Stack size/offset = 452 */
/* 1252 */	NdrFcShort( 0x460 ),	/* Type Offset=1120 */

	/* Parameter i29 */

/* 1254 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1256 */	NdrFcShort( 0x1d4 ),	/* x86 Stack size/offset = 468 */
/* 1258 */	NdrFcShort( 0x460 ),	/* Type Offset=1120 */

	/* Parameter i30 */

/* 1260 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1262 */	NdrFcShort( 0x1e4 ),	/* x86 Stack size/offset = 484 */
/* 1264 */	NdrFcShort( 0x460 ),	/* Type Offset=1120 */

	/* Parameter i31 */

/* 1266 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1268 */	NdrFcShort( 0x1f4 ),	/* x86 Stack size/offset = 500 */
/* 1270 */	NdrFcShort( 0x460 ),	/* Type Offset=1120 */

	/* Parameter ppField */

/* 1272 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1274 */	NdrFcShort( 0x204 ),	/* x86 Stack size/offset = 516 */
/* 1276 */	NdrFcShort( 0x47c ),	/* Type Offset=1148 */

	/* Return value */

/* 1278 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1280 */	NdrFcShort( 0x208 ),	/* x86 Stack size/offset = 520 */
/* 1282 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Initialize */

/* 1284 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1286 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1290 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1292 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 1294 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1296 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1298 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1300 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1302 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1304 */	NdrFcShort( 0x436 ),	/* 1078 */
/* 1306 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter varDims */

/* 1308 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1310 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1312 */	NdrFcShort( 0x460 ),	/* Type Offset=1120 */

	/* Parameter varFieldNames */

/* 1314 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1316 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1318 */	NdrFcShort( 0x460 ),	/* Type Offset=1120 */

	/* Return value */

/* 1320 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1322 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 1324 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_NumberOfDims */

/* 1326 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1328 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1332 */	NdrFcShort( 0xa ),	/* 10 */
/* 1334 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1336 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1338 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1340 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1342 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1344 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1346 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1348 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pnDims */

/* 1350 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1352 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1354 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1356 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1358 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1360 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Dims */

/* 1362 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1364 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1368 */	NdrFcShort( 0xb ),	/* 11 */
/* 1370 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1372 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1374 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1376 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1378 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1380 */	NdrFcShort( 0xcd ),	/* 205 */
/* 1382 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1384 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pvarDims */

/* 1386 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 1388 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1390 */	NdrFcShort( 0x452 ),	/* Type Offset=1106 */

	/* Return value */

/* 1392 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1394 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1396 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_FieldNames */

/* 1398 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1400 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1404 */	NdrFcShort( 0xc ),	/* 12 */
/* 1406 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1408 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1410 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1412 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1414 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1416 */	NdrFcShort( 0x2e8 ),	/* 744 */
/* 1418 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1420 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pvarFieldNames */

/* 1422 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 1424 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1426 */	NdrFcShort( 0x452 ),	/* Type Offset=1106 */

	/* Return value */

/* 1428 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1430 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1432 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Clone */

/* 1434 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1436 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1440 */	NdrFcShort( 0xd ),	/* 13 */
/* 1442 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1444 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1446 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1448 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1450 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1452 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1454 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1456 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppStruct */

/* 1458 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1460 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1462 */	NdrFcShort( 0x492 ),	/* Type Offset=1170 */

	/* Return value */

/* 1464 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1466 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1468 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Real */

/* 1470 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1472 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1476 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1478 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1480 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1482 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1484 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1486 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1488 */	NdrFcShort( 0x2e8 ),	/* 744 */
/* 1490 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1492 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pvarValue */

/* 1494 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 1496 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1498 */	NdrFcShort( 0x452 ),	/* Type Offset=1106 */

	/* Return value */

/* 1500 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1502 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1504 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Real */

/* 1506 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1508 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1512 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1514 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1516 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1518 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1520 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1522 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1524 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1526 */	NdrFcShort( 0xe5 ),	/* 229 */
/* 1528 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter varValue */

/* 1530 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1532 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1534 */	NdrFcShort( 0x460 ),	/* Type Offset=1120 */

	/* Return value */

/* 1536 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1538 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1540 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Imag */

/* 1542 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1544 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1548 */	NdrFcShort( 0x9 ),	/* 9 */
/* 1550 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1552 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1554 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1556 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1558 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1560 */	NdrFcShort( 0xfe ),	/* 254 */
/* 1562 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1564 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pvarValue */

/* 1566 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 1568 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1570 */	NdrFcShort( 0x452 ),	/* Type Offset=1106 */

	/* Return value */

/* 1572 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1574 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1576 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Imag */

/* 1578 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1580 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1584 */	NdrFcShort( 0xa ),	/* 10 */
/* 1586 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1588 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1590 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1592 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1594 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1596 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1598 */	NdrFcShort( 0x118 ),	/* 280 */
/* 1600 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter varValue */

/* 1602 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1604 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1606 */	NdrFcShort( 0x460 ),	/* Type Offset=1120 */

	/* Return value */

/* 1608 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1610 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1612 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_MWFlags */

/* 1614 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1616 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1620 */	NdrFcShort( 0xb ),	/* 11 */
/* 1622 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1624 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1626 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1628 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1630 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1632 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1634 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1636 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppFlags */

/* 1638 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1640 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1642 */	NdrFcShort( 0x478 ),	/* Type Offset=1144 */

	/* Return value */

/* 1644 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1646 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1648 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_MWFlags */

/* 1650 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1652 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1656 */	NdrFcShort( 0xc ),	/* 12 */
/* 1658 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1660 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1662 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1664 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1666 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1668 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1670 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1672 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFlags */

/* 1674 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1676 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1678 */	NdrFcShort( 0x3e ),	/* Type Offset=62 */

	/* Return value */

/* 1680 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1682 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1684 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Clone */

/* 1686 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1688 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1692 */	NdrFcShort( 0xd ),	/* 13 */
/* 1694 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1696 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1698 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1700 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1702 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1704 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1706 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1708 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppComplex */

/* 1710 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1712 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1714 */	NdrFcShort( 0x4a8 ),	/* Type Offset=1192 */

	/* Return value */

/* 1716 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1718 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1720 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Array */

/* 1722 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1724 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1728 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1730 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1732 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1734 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1736 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1738 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1740 */	NdrFcShort( 0x133 ),	/* 307 */
/* 1742 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1744 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pvarArray */

/* 1746 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 1748 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1750 */	NdrFcShort( 0x452 ),	/* Type Offset=1106 */

	/* Return value */

/* 1752 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1754 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1756 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Array */

/* 1758 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1760 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1764 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1766 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1768 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1770 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1772 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1774 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1776 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1778 */	NdrFcShort( 0x14f ),	/* 335 */
/* 1780 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter varArray */

/* 1782 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1784 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1786 */	NdrFcShort( 0x460 ),	/* Type Offset=1120 */

	/* Return value */

/* 1788 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1790 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1792 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_NumColumns */

/* 1794 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1796 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1800 */	NdrFcShort( 0xb ),	/* 11 */
/* 1802 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1804 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1806 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1808 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1810 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1812 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1814 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1816 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pnColumns */

/* 1818 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1820 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1822 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1824 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1826 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1828 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_NumColumns */

/* 1830 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1832 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1836 */	NdrFcShort( 0xc ),	/* 12 */
/* 1838 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1840 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1842 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1844 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1846 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1848 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1850 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1852 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter nColumns */

/* 1854 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1856 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1858 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1860 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1862 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1864 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_RowIndex */

/* 1866 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1868 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1872 */	NdrFcShort( 0xd ),	/* 13 */
/* 1874 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1876 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1878 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1880 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1882 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1884 */	NdrFcShort( 0x16c ),	/* 364 */
/* 1886 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1888 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pIndex */

/* 1890 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 1892 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1894 */	NdrFcShort( 0x452 ),	/* Type Offset=1106 */

	/* Return value */

/* 1896 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1898 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1900 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_RowIndex */

/* 1902 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1904 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1908 */	NdrFcShort( 0xe ),	/* 14 */
/* 1910 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1912 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1914 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1916 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1918 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1920 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1922 */	NdrFcShort( 0x18a ),	/* 394 */
/* 1924 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Index */

/* 1926 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1928 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1930 */	NdrFcShort( 0x460 ),	/* Type Offset=1120 */

	/* Return value */

/* 1932 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1934 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1936 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ColumnIndex */

/* 1938 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1940 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1944 */	NdrFcShort( 0xf ),	/* 15 */
/* 1946 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1948 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1950 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1952 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1954 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1956 */	NdrFcShort( 0x1a9 ),	/* 425 */
/* 1958 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1960 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pIndex */

/* 1962 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 1964 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1966 */	NdrFcShort( 0x452 ),	/* Type Offset=1106 */

	/* Return value */

/* 1968 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1970 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1972 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ColumnIndex */

/* 1974 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1976 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1980 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1982 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1984 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1986 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1988 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1990 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1992 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1994 */	NdrFcShort( 0x1c9 ),	/* 457 */
/* 1996 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Index */

/* 1998 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2000 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2002 */	NdrFcShort( 0x460 ),	/* Type Offset=1120 */

	/* Return value */

/* 2004 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2006 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2008 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_MWFlags */

/* 2010 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2012 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2016 */	NdrFcShort( 0x11 ),	/* 17 */
/* 2018 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2020 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2022 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2024 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2026 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2028 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2030 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2032 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppFlags */

/* 2034 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2036 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2038 */	NdrFcShort( 0x478 ),	/* Type Offset=1144 */

	/* Return value */

/* 2040 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2042 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2044 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_MWFlags */

/* 2046 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2048 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2052 */	NdrFcShort( 0x12 ),	/* 18 */
/* 2054 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2056 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2058 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2060 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2062 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2064 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2066 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2068 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFlags */

/* 2070 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2072 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2074 */	NdrFcShort( 0x3e ),	/* Type Offset=62 */

	/* Return value */

/* 2076 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2078 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2080 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Clone */

/* 2082 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2084 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2088 */	NdrFcShort( 0x13 ),	/* 19 */
/* 2090 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2092 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2094 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2096 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2098 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2100 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2102 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2104 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppSparse */

/* 2106 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2108 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2110 */	NdrFcShort( 0x4be ),	/* Type Offset=1214 */

	/* Return value */

/* 2112 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2114 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2116 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Value */

/* 2118 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2120 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2124 */	NdrFcShort( 0x7 ),	/* 7 */
/* 2126 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2130 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2132 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2134 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2136 */	NdrFcShort( 0x1ea ),	/* 490 */
/* 2138 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2140 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pvarValue */

/* 2142 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 2144 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2146 */	NdrFcShort( 0x452 ),	/* Type Offset=1106 */

	/* Return value */

/* 2148 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2150 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2152 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Value */

/* 2154 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2156 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2160 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2162 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2164 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2166 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2168 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2170 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2172 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2174 */	NdrFcShort( 0x20c ),	/* 524 */
/* 2176 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter varValue */

/* 2178 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2180 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2182 */	NdrFcShort( 0x460 ),	/* Type Offset=1120 */

	/* Return value */

/* 2184 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2186 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2188 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_MWFlags */

/* 2190 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2192 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2196 */	NdrFcShort( 0x9 ),	/* 9 */
/* 2198 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2200 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2202 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2204 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2206 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2208 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2210 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2212 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppFlags */

/* 2214 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2216 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2218 */	NdrFcShort( 0x478 ),	/* Type Offset=1144 */

	/* Return value */

/* 2220 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2222 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2224 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_MWFlags */

/* 2226 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2228 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2232 */	NdrFcShort( 0xa ),	/* 10 */
/* 2234 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2236 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2238 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2240 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2242 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2244 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2246 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2248 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFlags */

/* 2250 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2252 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2254 */	NdrFcShort( 0x3e ),	/* Type Offset=62 */

	/* Return value */

/* 2256 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2258 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2260 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Clone */

/* 2262 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2264 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2268 */	NdrFcShort( 0xb ),	/* 11 */
/* 2270 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2272 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2274 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2276 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2278 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2280 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2282 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2284 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppArg */

/* 2286 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2288 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2290 */	NdrFcShort( 0x4d4 ),	/* Type Offset=1236 */

	/* Return value */

/* 2292 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2294 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2296 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Item */

/* 2298 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2300 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2304 */	NdrFcShort( 0x7 ),	/* 7 */
/* 2306 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2308 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2310 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2312 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 2314 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2316 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2318 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2320 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter nIndex */

/* 2322 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2324 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2326 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppInfo */

/* 2328 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2330 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2332 */	NdrFcShort( 0x4ea ),	/* Type Offset=1258 */

	/* Return value */

/* 2334 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2336 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2338 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Name */

/* 2340 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2342 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2346 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2348 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2350 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2352 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2354 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2356 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2358 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2360 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2362 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbstrName */

/* 2364 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 2366 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2368 */	NdrFcShort( 0x46e ),	/* Type Offset=1134 */

	/* Return value */

/* 2370 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2372 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2374 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Name */

/* 2376 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2378 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2382 */	NdrFcShort( 0x9 ),	/* 9 */
/* 2384 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2386 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2388 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2390 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2392 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2394 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2396 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2398 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bstrName */

/* 2400 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2402 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2404 */	NdrFcShort( 0x504 ),	/* Type Offset=1284 */

	/* Return value */

/* 2406 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2408 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2410 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Value */

/* 2412 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2414 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2418 */	NdrFcShort( 0xa ),	/* 10 */
/* 2420 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2422 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2424 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2426 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2428 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2430 */	NdrFcShort( 0x235 ),	/* 565 */
/* 2432 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2434 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pvarValue */

/* 2436 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 2438 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2440 */	NdrFcShort( 0x452 ),	/* Type Offset=1106 */

	/* Return value */

/* 2442 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2444 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2446 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Value */

/* 2448 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2450 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2454 */	NdrFcShort( 0xb ),	/* 11 */
/* 2456 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2458 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2460 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2462 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2464 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2466 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2468 */	NdrFcShort( 0x25b ),	/* 603 */
/* 2470 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter varValue */

/* 2472 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2474 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2476 */	NdrFcShort( 0x460 ),	/* Type Offset=1120 */

	/* Return value */

/* 2478 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2480 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2482 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Count */

/* 2484 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2486 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2490 */	NdrFcShort( 0xc ),	/* 12 */
/* 2492 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2494 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2496 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2498 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2500 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2502 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2504 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2506 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pnCount */

/* 2508 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2510 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2512 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2514 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2516 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2518 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Reset */

/* 2520 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2522 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2526 */	NdrFcShort( 0xd ),	/* 13 */
/* 2528 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2530 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2532 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2534 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 2536 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2538 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2540 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2542 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 2544 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2546 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2548 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Next */

/* 2550 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2552 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2556 */	NdrFcShort( 0xf ),	/* 15 */
/* 2558 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2560 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2562 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2564 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 2566 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2568 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2570 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2572 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppInfo */

/* 2574 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2576 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2578 */	NdrFcShort( 0x4ea ),	/* Type Offset=1258 */

	/* Parameter pnRetElms */

/* 2580 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2582 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2584 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2586 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2588 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2590 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Add */

/* 2592 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2594 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2598 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2600 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2602 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2604 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2606 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2608 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2610 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2612 */	NdrFcShort( 0x1753 ),	/* 5971 */
/* 2614 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter varValue */

/* 2616 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2618 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2620 */	NdrFcShort( 0x460 ),	/* Type Offset=1120 */

	/* Return value */

/* 2622 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2624 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2626 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Remove */

/* 2628 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2630 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2634 */	NdrFcShort( 0x11 ),	/* 17 */
/* 2636 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2638 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2640 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2642 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2644 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2646 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2648 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2650 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter nIndex */

/* 2652 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2654 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2656 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2658 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2660 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2662 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Clear */

/* 2664 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2666 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2670 */	NdrFcShort( 0x12 ),	/* 18 */
/* 2672 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2674 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2676 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2678 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 2680 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2682 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2684 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2686 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 2688 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2690 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2692 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetAt */

/* 2694 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2696 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2700 */	NdrFcShort( 0x13 ),	/* 19 */
/* 2702 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 2704 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2706 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2708 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2710 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2712 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2714 */	NdrFcShort( 0x1753 ),	/* 5971 */
/* 2716 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter nIndex */

/* 2718 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2720 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2722 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter varValue */

/* 2724 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2726 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2728 */	NdrFcShort( 0x460 ),	/* Type Offset=1120 */

	/* Return value */

/* 2730 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2732 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2734 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_CopyToRange */

/* 2736 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2738 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2742 */	NdrFcShort( 0x14 ),	/* 20 */
/* 2744 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2746 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2748 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2750 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2752 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2754 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2756 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2758 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bToRange */

/* 2760 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2762 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2764 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2766 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2768 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2770 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_CopyToRange */

/* 2772 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2774 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2778 */	NdrFcShort( 0x15 ),	/* 21 */
/* 2780 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2782 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2784 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2786 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2788 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2790 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2792 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2794 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbToRange */

/* 2796 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2798 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2800 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2802 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2804 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2806 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Clone */

/* 2808 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2810 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2814 */	NdrFcShort( 0x16 ),	/* 22 */
/* 2816 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2818 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2820 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2822 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2824 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2826 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2828 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2830 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppEnum */

/* 2832 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2834 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2836 */	NdrFcShort( 0x50e ),	/* Type Offset=1294 */

	/* Return value */

/* 2838 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2840 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2842 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Value */

/* 2844 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2846 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2850 */	NdrFcShort( 0x7 ),	/* 7 */
/* 2852 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2854 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2856 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2858 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2860 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2862 */	NdrFcShort( 0x282 ),	/* 642 */
/* 2864 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2866 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pvarValue */

/* 2868 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 2870 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2872 */	NdrFcShort( 0x452 ),	/* Type Offset=1106 */

	/* Return value */

/* 2874 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2876 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2878 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Value */

/* 2880 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2882 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2886 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2888 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2890 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2892 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2894 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2896 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2898 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2900 */	NdrFcShort( 0x2aa ),	/* 682 */
/* 2902 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter varValue */

/* 2904 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2906 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2908 */	NdrFcShort( 0x460 ),	/* Type Offset=1120 */

	/* Return value */

/* 2910 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2912 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2914 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Name */

/* 2916 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2918 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2922 */	NdrFcShort( 0xa ),	/* 10 */
/* 2924 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2926 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2928 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2930 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2932 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2934 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2936 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2938 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bstrName */

/* 2940 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2942 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2944 */	NdrFcShort( 0x504 ),	/* Type Offset=1284 */

	/* Return value */

/* 2946 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2948 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2950 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Flags */

/* 2952 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2954 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2958 */	NdrFcShort( 0xc ),	/* 12 */
/* 2960 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2962 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2964 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2966 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2968 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2970 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2972 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2974 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pnFlags */

/* 2976 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2978 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2980 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2982 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2984 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2986 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_IsRange */

/* 2988 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2990 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2994 */	NdrFcShort( 0xe ),	/* 14 */
/* 2996 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2998 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3000 */	NdrFcShort( 0x22 ),	/* 34 */
/* 3002 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3004 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3006 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3008 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3010 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbRange */

/* 3012 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3014 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3016 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 3018 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3020 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3022 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_MWFlags */

/* 3024 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3026 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3030 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3032 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3034 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3036 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3038 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 3040 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3042 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3044 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3046 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppFlags */

/* 3048 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3050 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3052 */	NdrFcShort( 0x478 ),	/* Type Offset=1144 */

	/* Return value */

/* 3054 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3056 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3058 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_MWFlags */

/* 3060 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3062 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3066 */	NdrFcShort( 0x11 ),	/* 17 */
/* 3068 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3070 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3072 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3074 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3076 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3078 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3080 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3082 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFlags */

/* 3084 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3086 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3088 */	NdrFcShort( 0x3e ),	/* Type Offset=62 */

	/* Return value */

/* 3090 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3092 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3094 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Selected */

/* 3096 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3098 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3102 */	NdrFcShort( 0x12 ),	/* 18 */
/* 3104 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3106 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3108 */	NdrFcShort( 0x22 ),	/* 34 */
/* 3110 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3112 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3114 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3116 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3118 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbSelected */

/* 3120 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3122 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3124 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 3126 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3128 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3130 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Vararg */

/* 3132 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3134 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3138 */	NdrFcShort( 0x13 ),	/* 19 */
/* 3140 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3142 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3144 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3146 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 3148 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3150 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3152 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3154 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppVararg */

/* 3156 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3158 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3160 */	NdrFcShort( 0x50e ),	/* Type Offset=1294 */

	/* Return value */

/* 3162 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3164 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3166 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Vararg */

/* 3168 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3170 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3174 */	NdrFcShort( 0x14 ),	/* 20 */
/* 3176 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3178 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3180 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3182 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3184 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3186 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3188 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3190 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVararg */

/* 3192 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3194 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3196 */	NdrFcShort( 0x512 ),	/* Type Offset=1298 */

	/* Return value */

/* 3198 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3200 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3202 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_CopyToRange */

/* 3204 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3206 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3210 */	NdrFcShort( 0x15 ),	/* 21 */
/* 3212 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3214 */	NdrFcShort( 0x6 ),	/* 6 */
/* 3216 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3218 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3220 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3222 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3224 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3226 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bToRange */

/* 3228 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3230 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3232 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 3234 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3236 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3238 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_CopyToRange */

/* 3240 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3242 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3246 */	NdrFcShort( 0x16 ),	/* 22 */
/* 3248 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3250 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3252 */	NdrFcShort( 0x22 ),	/* 34 */
/* 3254 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3256 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3258 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3260 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3262 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbToRange */

/* 3264 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3266 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3268 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 3270 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3272 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3274 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Select */

/* 3276 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3278 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3282 */	NdrFcShort( 0x17 ),	/* 23 */
/* 3284 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3286 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3288 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3290 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 3292 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3294 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3296 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3298 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 3300 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3302 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3304 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_IsListening */

/* 3306 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3308 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3312 */	NdrFcShort( 0x18 ),	/* 24 */
/* 3314 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3316 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3318 */	NdrFcShort( 0x22 ),	/* 34 */
/* 3320 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3322 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3324 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3326 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3328 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbListen */

/* 3330 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3332 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3334 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 3336 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3338 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3340 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_IsListening */

/* 3342 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3344 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3348 */	NdrFcShort( 0x19 ),	/* 25 */
/* 3350 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3352 */	NdrFcShort( 0x6 ),	/* 6 */
/* 3354 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3356 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3358 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3360 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3362 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3364 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bListen */

/* 3366 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3368 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3370 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 3372 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3374 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3376 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Offset */

/* 3378 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3380 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3384 */	NdrFcShort( 0x1a ),	/* 26 */
/* 3386 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3388 */	NdrFcShort( 0x1c ),	/* 28 */
/* 3390 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3392 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x5,		/* 5 */
/* 3394 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3396 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3398 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3400 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter nRows */

/* 3402 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3404 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3406 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nColumns */

/* 3408 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3410 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3412 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter bCopyContents */

/* 3414 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3416 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3418 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter bDeleteOriginal */

/* 3420 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3422 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3424 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 3426 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3428 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3430 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Clone */

/* 3432 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3434 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3438 */	NdrFcShort( 0x1b ),	/* 27 */
/* 3440 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3442 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3444 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3446 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 3448 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3450 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3452 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3454 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppInfo */

/* 3456 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3458 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3460 */	NdrFcShort( 0x4ea ),	/* Type Offset=1258 */

	/* Return value */

/* 3462 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3464 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3466 */	0x8,		/* FC_LONG */
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
/* 82 */	NdrFcShort( 0x400 ),	/* Offset= 1024 (1106) */
/* 84 */	
			0x13, 0x0,	/* FC_OP */
/* 86 */	NdrFcShort( 0x3e8 ),	/* Offset= 1000 (1086) */
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
/* 190 */	NdrFcShort( 0x336 ),	/* Offset= 822 (1012) */
/* 192 */	NdrFcLong( 0x4024 ),	/* 16420 */
/* 196 */	NdrFcShort( 0x330 ),	/* Offset= 816 (1012) */
/* 198 */	NdrFcLong( 0x4011 ),	/* 16401 */
/* 202 */	NdrFcShort( 0x32e ),	/* Offset= 814 (1016) */
/* 204 */	NdrFcLong( 0x4002 ),	/* 16386 */
/* 208 */	NdrFcShort( 0x32c ),	/* Offset= 812 (1020) */
/* 210 */	NdrFcLong( 0x4003 ),	/* 16387 */
/* 214 */	NdrFcShort( 0x32a ),	/* Offset= 810 (1024) */
/* 216 */	NdrFcLong( 0x4014 ),	/* 16404 */
/* 220 */	NdrFcShort( 0x328 ),	/* Offset= 808 (1028) */
/* 222 */	NdrFcLong( 0x4004 ),	/* 16388 */
/* 226 */	NdrFcShort( 0x326 ),	/* Offset= 806 (1032) */
/* 228 */	NdrFcLong( 0x4005 ),	/* 16389 */
/* 232 */	NdrFcShort( 0x324 ),	/* Offset= 804 (1036) */
/* 234 */	NdrFcLong( 0x400b ),	/* 16395 */
/* 238 */	NdrFcShort( 0x30e ),	/* Offset= 782 (1020) */
/* 240 */	NdrFcLong( 0x400a ),	/* 16394 */
/* 244 */	NdrFcShort( 0x30c ),	/* Offset= 780 (1024) */
/* 246 */	NdrFcLong( 0x4006 ),	/* 16390 */
/* 250 */	NdrFcShort( 0x316 ),	/* Offset= 790 (1040) */
/* 252 */	NdrFcLong( 0x4007 ),	/* 16391 */
/* 256 */	NdrFcShort( 0x30c ),	/* Offset= 780 (1036) */
/* 258 */	NdrFcLong( 0x4008 ),	/* 16392 */
/* 262 */	NdrFcShort( 0x30e ),	/* Offset= 782 (1044) */
/* 264 */	NdrFcLong( 0x400d ),	/* 16397 */
/* 268 */	NdrFcShort( 0x30c ),	/* Offset= 780 (1048) */
/* 270 */	NdrFcLong( 0x4009 ),	/* 16393 */
/* 274 */	NdrFcShort( 0x30a ),	/* Offset= 778 (1052) */
/* 276 */	NdrFcLong( 0x6000 ),	/* 24576 */
/* 280 */	NdrFcShort( 0x308 ),	/* Offset= 776 (1056) */
/* 282 */	NdrFcLong( 0x400c ),	/* 16396 */
/* 286 */	NdrFcShort( 0x306 ),	/* Offset= 774 (1060) */
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
/* 328 */	NdrFcShort( 0x2e4 ),	/* Offset= 740 (1068) */
/* 330 */	NdrFcLong( 0x400e ),	/* 16398 */
/* 334 */	NdrFcShort( 0x2e8 ),	/* Offset= 744 (1078) */
/* 336 */	NdrFcLong( 0x4010 ),	/* 16400 */
/* 340 */	NdrFcShort( 0x2e6 ),	/* Offset= 742 (1082) */
/* 342 */	NdrFcLong( 0x4012 ),	/* 16402 */
/* 346 */	NdrFcShort( 0x2a2 ),	/* Offset= 674 (1020) */
/* 348 */	NdrFcLong( 0x4013 ),	/* 16403 */
/* 352 */	NdrFcShort( 0x2a0 ),	/* Offset= 672 (1024) */
/* 354 */	NdrFcLong( 0x4015 ),	/* 16405 */
/* 358 */	NdrFcShort( 0x29e ),	/* Offset= 670 (1028) */
/* 360 */	NdrFcLong( 0x4016 ),	/* 16406 */
/* 364 */	NdrFcShort( 0x294 ),	/* Offset= 660 (1024) */
/* 366 */	NdrFcLong( 0x4017 ),	/* 16407 */
/* 370 */	NdrFcShort( 0x28e ),	/* Offset= 654 (1024) */
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
/* 460 */	NdrFcShort( 0x216 ),	/* Offset= 534 (994) */
/* 462 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x49,		/* 73 */
/* 464 */	NdrFcShort( 0x18 ),	/* 24 */
/* 466 */	NdrFcShort( 0xa ),	/* 10 */
/* 468 */	NdrFcLong( 0x8 ),	/* 8 */
/* 472 */	NdrFcShort( 0x5a ),	/* Offset= 90 (562) */
/* 474 */	NdrFcLong( 0xd ),	/* 13 */
/* 478 */	NdrFcShort( 0x7e ),	/* Offset= 126 (604) */
/* 480 */	NdrFcLong( 0x9 ),	/* 9 */
/* 484 */	NdrFcShort( 0x9e ),	/* Offset= 158 (642) */
/* 486 */	NdrFcLong( 0xc ),	/* 12 */
/* 490 */	NdrFcShort( 0xc8 ),	/* Offset= 200 (690) */
/* 492 */	NdrFcLong( 0x24 ),	/* 36 */
/* 496 */	NdrFcShort( 0x124 ),	/* Offset= 292 (788) */
/* 498 */	NdrFcLong( 0x800d ),	/* 32781 */
/* 502 */	NdrFcShort( 0x140 ),	/* Offset= 320 (822) */
/* 504 */	NdrFcLong( 0x10 ),	/* 16 */
/* 508 */	NdrFcShort( 0x15a ),	/* Offset= 346 (854) */
/* 510 */	NdrFcLong( 0x2 ),	/* 2 */
/* 514 */	NdrFcShort( 0x174 ),	/* Offset= 372 (886) */
/* 516 */	NdrFcLong( 0x3 ),	/* 3 */
/* 520 */	NdrFcShort( 0x18e ),	/* Offset= 398 (918) */
/* 522 */	NdrFcLong( 0x14 ),	/* 20 */
/* 526 */	NdrFcShort( 0x1a8 ),	/* Offset= 424 (950) */
/* 528 */	NdrFcShort( 0xffff ),	/* Offset= -1 (527) */
/* 530 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 532 */	NdrFcShort( 0x4 ),	/* 4 */
/* 534 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 536 */	NdrFcShort( 0x0 ),	/* 0 */
/* 538 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 540 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 542 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 544 */	NdrFcShort( 0x4 ),	/* 4 */
/* 546 */	NdrFcShort( 0x0 ),	/* 0 */
/* 548 */	NdrFcShort( 0x1 ),	/* 1 */
/* 550 */	NdrFcShort( 0x0 ),	/* 0 */
/* 552 */	NdrFcShort( 0x0 ),	/* 0 */
/* 554 */	0x13, 0x0,	/* FC_OP */
/* 556 */	NdrFcShort( 0xff6c ),	/* Offset= -148 (408) */
/* 558 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 560 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 562 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 564 */	NdrFcShort( 0x8 ),	/* 8 */
/* 566 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 568 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 570 */	NdrFcShort( 0x4 ),	/* 4 */
/* 572 */	NdrFcShort( 0x4 ),	/* 4 */
/* 574 */	0x11, 0x0,	/* FC_RP */
/* 576 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (530) */
/* 578 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 580 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 582 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 584 */	NdrFcShort( 0x0 ),	/* 0 */
/* 586 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 588 */	NdrFcShort( 0x0 ),	/* 0 */
/* 590 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 592 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 596 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 598 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 600 */	NdrFcShort( 0xff4a ),	/* Offset= -182 (418) */
/* 602 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 604 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 606 */	NdrFcShort( 0x8 ),	/* 8 */
/* 608 */	NdrFcShort( 0x0 ),	/* 0 */
/* 610 */	NdrFcShort( 0x6 ),	/* Offset= 6 (616) */
/* 612 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 614 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 616 */	
			0x11, 0x0,	/* FC_RP */
/* 618 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (582) */
/* 620 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 622 */	NdrFcShort( 0x0 ),	/* 0 */
/* 624 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 626 */	NdrFcShort( 0x0 ),	/* 0 */
/* 628 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 630 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 634 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 636 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 638 */	NdrFcShort( 0xff36 ),	/* Offset= -202 (436) */
/* 640 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 642 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 644 */	NdrFcShort( 0x8 ),	/* 8 */
/* 646 */	NdrFcShort( 0x0 ),	/* 0 */
/* 648 */	NdrFcShort( 0x6 ),	/* Offset= 6 (654) */
/* 650 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 652 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 654 */	
			0x11, 0x0,	/* FC_RP */
/* 656 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (620) */
/* 658 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 660 */	NdrFcShort( 0x4 ),	/* 4 */
/* 662 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 664 */	NdrFcShort( 0x0 ),	/* 0 */
/* 666 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 668 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 670 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 672 */	NdrFcShort( 0x4 ),	/* 4 */
/* 674 */	NdrFcShort( 0x0 ),	/* 0 */
/* 676 */	NdrFcShort( 0x1 ),	/* 1 */
/* 678 */	NdrFcShort( 0x0 ),	/* 0 */
/* 680 */	NdrFcShort( 0x0 ),	/* 0 */
/* 682 */	0x13, 0x0,	/* FC_OP */
/* 684 */	NdrFcShort( 0x192 ),	/* Offset= 402 (1086) */
/* 686 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 688 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 690 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 692 */	NdrFcShort( 0x8 ),	/* 8 */
/* 694 */	NdrFcShort( 0x0 ),	/* 0 */
/* 696 */	NdrFcShort( 0x6 ),	/* Offset= 6 (702) */
/* 698 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 700 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 702 */	
			0x11, 0x0,	/* FC_RP */
/* 704 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (658) */
/* 706 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 708 */	NdrFcLong( 0x2f ),	/* 47 */
/* 712 */	NdrFcShort( 0x0 ),	/* 0 */
/* 714 */	NdrFcShort( 0x0 ),	/* 0 */
/* 716 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 718 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 720 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 722 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 724 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 726 */	NdrFcShort( 0x1 ),	/* 1 */
/* 728 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 730 */	NdrFcShort( 0x4 ),	/* 4 */
/* 732 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 734 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 736 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 738 */	NdrFcShort( 0x10 ),	/* 16 */
/* 740 */	NdrFcShort( 0x0 ),	/* 0 */
/* 742 */	NdrFcShort( 0xa ),	/* Offset= 10 (752) */
/* 744 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 746 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 748 */	NdrFcShort( 0xffd6 ),	/* Offset= -42 (706) */
/* 750 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 752 */	
			0x13, 0x0,	/* FC_OP */
/* 754 */	NdrFcShort( 0xffe2 ),	/* Offset= -30 (724) */
/* 756 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 758 */	NdrFcShort( 0x4 ),	/* 4 */
/* 760 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 762 */	NdrFcShort( 0x0 ),	/* 0 */
/* 764 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 766 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 768 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 770 */	NdrFcShort( 0x4 ),	/* 4 */
/* 772 */	NdrFcShort( 0x0 ),	/* 0 */
/* 774 */	NdrFcShort( 0x1 ),	/* 1 */
/* 776 */	NdrFcShort( 0x0 ),	/* 0 */
/* 778 */	NdrFcShort( 0x0 ),	/* 0 */
/* 780 */	0x13, 0x0,	/* FC_OP */
/* 782 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (736) */
/* 784 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 786 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 788 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 790 */	NdrFcShort( 0x8 ),	/* 8 */
/* 792 */	NdrFcShort( 0x0 ),	/* 0 */
/* 794 */	NdrFcShort( 0x6 ),	/* Offset= 6 (800) */
/* 796 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 798 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 800 */	
			0x11, 0x0,	/* FC_RP */
/* 802 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (756) */
/* 804 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 806 */	NdrFcShort( 0x8 ),	/* 8 */
/* 808 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 810 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 812 */	NdrFcShort( 0x10 ),	/* 16 */
/* 814 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 816 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 818 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (804) */
			0x5b,		/* FC_END */
/* 822 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 824 */	NdrFcShort( 0x18 ),	/* 24 */
/* 826 */	NdrFcShort( 0x0 ),	/* 0 */
/* 828 */	NdrFcShort( 0xa ),	/* Offset= 10 (838) */
/* 830 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 832 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 834 */	NdrFcShort( 0xffe8 ),	/* Offset= -24 (810) */
/* 836 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 838 */	
			0x11, 0x0,	/* FC_RP */
/* 840 */	NdrFcShort( 0xfefe ),	/* Offset= -258 (582) */
/* 842 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 844 */	NdrFcShort( 0x1 ),	/* 1 */
/* 846 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 848 */	NdrFcShort( 0x0 ),	/* 0 */
/* 850 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 852 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 854 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 856 */	NdrFcShort( 0x8 ),	/* 8 */
/* 858 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 860 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 862 */	NdrFcShort( 0x4 ),	/* 4 */
/* 864 */	NdrFcShort( 0x4 ),	/* 4 */
/* 866 */	0x13, 0x0,	/* FC_OP */
/* 868 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (842) */
/* 870 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 872 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 874 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 876 */	NdrFcShort( 0x2 ),	/* 2 */
/* 878 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 880 */	NdrFcShort( 0x0 ),	/* 0 */
/* 882 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 884 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 886 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 888 */	NdrFcShort( 0x8 ),	/* 8 */
/* 890 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 892 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 894 */	NdrFcShort( 0x4 ),	/* 4 */
/* 896 */	NdrFcShort( 0x4 ),	/* 4 */
/* 898 */	0x13, 0x0,	/* FC_OP */
/* 900 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (874) */
/* 902 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 904 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 906 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 908 */	NdrFcShort( 0x4 ),	/* 4 */
/* 910 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 912 */	NdrFcShort( 0x0 ),	/* 0 */
/* 914 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 916 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 918 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 920 */	NdrFcShort( 0x8 ),	/* 8 */
/* 922 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 924 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 926 */	NdrFcShort( 0x4 ),	/* 4 */
/* 928 */	NdrFcShort( 0x4 ),	/* 4 */
/* 930 */	0x13, 0x0,	/* FC_OP */
/* 932 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (906) */
/* 934 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 936 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 938 */	
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 940 */	NdrFcShort( 0x8 ),	/* 8 */
/* 942 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 944 */	NdrFcShort( 0x0 ),	/* 0 */
/* 946 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 948 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 950 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 952 */	NdrFcShort( 0x8 ),	/* 8 */
/* 954 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 956 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 958 */	NdrFcShort( 0x4 ),	/* 4 */
/* 960 */	NdrFcShort( 0x4 ),	/* 4 */
/* 962 */	0x13, 0x0,	/* FC_OP */
/* 964 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (938) */
/* 966 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 968 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 970 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 972 */	NdrFcShort( 0x8 ),	/* 8 */
/* 974 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 976 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 978 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 980 */	NdrFcShort( 0x8 ),	/* 8 */
/* 982 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 984 */	NdrFcShort( 0xffd8 ),	/* -40 */
/* 986 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 988 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 990 */	NdrFcShort( 0xffec ),	/* Offset= -20 (970) */
/* 992 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 994 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 996 */	NdrFcShort( 0x28 ),	/* 40 */
/* 998 */	NdrFcShort( 0xffec ),	/* Offset= -20 (978) */
/* 1000 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1000) */
/* 1002 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1004 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1006 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1008 */	NdrFcShort( 0xfdde ),	/* Offset= -546 (462) */
/* 1010 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1012 */	
			0x13, 0x0,	/* FC_OP */
/* 1014 */	NdrFcShort( 0xfeea ),	/* Offset= -278 (736) */
/* 1016 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1018 */	0x1,		/* FC_BYTE */
			0x5c,		/* FC_PAD */
/* 1020 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1022 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 1024 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1026 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 1028 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1030 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 1032 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1034 */	0xa,		/* FC_FLOAT */
			0x5c,		/* FC_PAD */
/* 1036 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1038 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 1040 */	
			0x13, 0x0,	/* FC_OP */
/* 1042 */	NdrFcShort( 0xfd70 ),	/* Offset= -656 (386) */
/* 1044 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1046 */	NdrFcShort( 0xfd72 ),	/* Offset= -654 (392) */
/* 1048 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1050 */	NdrFcShort( 0xfd88 ),	/* Offset= -632 (418) */
/* 1052 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1054 */	NdrFcShort( 0xfd96 ),	/* Offset= -618 (436) */
/* 1056 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1058 */	NdrFcShort( 0xfda4 ),	/* Offset= -604 (454) */
/* 1060 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1062 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1064) */
/* 1064 */	
			0x13, 0x0,	/* FC_OP */
/* 1066 */	NdrFcShort( 0x14 ),	/* Offset= 20 (1086) */
/* 1068 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 1070 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1072 */	0x6,		/* FC_SHORT */
			0x1,		/* FC_BYTE */
/* 1074 */	0x1,		/* FC_BYTE */
			0x8,		/* FC_LONG */
/* 1076 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 1078 */	
			0x13, 0x0,	/* FC_OP */
/* 1080 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (1068) */
/* 1082 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1084 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 1086 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 1088 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1090 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1092 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1092) */
/* 1094 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1096 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1098 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1100 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1102 */	NdrFcShort( 0xfc0a ),	/* Offset= -1014 (88) */
/* 1104 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1106 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1108 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1110 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1112 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1114 */	NdrFcShort( 0xfbfa ),	/* Offset= -1030 (84) */
/* 1116 */	
			0x12, 0x0,	/* FC_UP */
/* 1118 */	NdrFcShort( 0xffe0 ),	/* Offset= -32 (1086) */
/* 1120 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1122 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1124 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1126 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1128 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (1116) */
/* 1130 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1132 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1134) */
/* 1134 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1136 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1138 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1140 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1142 */	NdrFcShort( 0xfd12 ),	/* Offset= -750 (392) */
/* 1144 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1146 */	NdrFcShort( 0xfbc4 ),	/* Offset= -1084 (62) */
/* 1148 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1150 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1152) */
/* 1152 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1154 */	NdrFcLong( 0xaec9ffb ),	/* 183279611 */
/* 1158 */	NdrFcShort( 0xab0d ),	/* -21747 */
/* 1160 */	NdrFcShort( 0x4a09 ),	/* 18953 */
/* 1162 */	0xbe,		/* 190 */
			0x9c,		/* 156 */
/* 1164 */	0x78,		/* 120 */
			0x85,		/* 133 */
/* 1166 */	0x7a,		/* 122 */
			0x1b,		/* 27 */
/* 1168 */	0x85,		/* 133 */
			0x80,		/* 128 */
/* 1170 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1172 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1174) */
/* 1174 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1176 */	NdrFcLong( 0x6c70bb67 ),	/* 1819327335 */
/* 1180 */	NdrFcShort( 0x3f76 ),	/* 16246 */
/* 1182 */	NdrFcShort( 0x4176 ),	/* 16758 */
/* 1184 */	0x88,		/* 136 */
			0x9,		/* 9 */
/* 1186 */	0xc6,		/* 198 */
			0x63,		/* 99 */
/* 1188 */	0x93,		/* 147 */
			0xb1,		/* 177 */
/* 1190 */	0xfa,		/* 250 */
			0x23,		/* 35 */
/* 1192 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1194 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1196) */
/* 1196 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1198 */	NdrFcLong( 0x8cdd4bbf ),	/* -1931654209 */
/* 1202 */	NdrFcShort( 0xa84c ),	/* -22452 */
/* 1204 */	NdrFcShort( 0x4c50 ),	/* 19536 */
/* 1206 */	0xb6,		/* 182 */
			0x0,		/* 0 */
/* 1208 */	0xf5,		/* 245 */
			0xe9,		/* 233 */
/* 1210 */	0x0,		/* 0 */
			0x8,		/* 8 */
/* 1212 */	0x49,		/* 73 */
			0x1d,		/* 29 */
/* 1214 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1216 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1218) */
/* 1218 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1220 */	NdrFcLong( 0x6d4874ad ),	/* 1833465005 */
/* 1224 */	NdrFcShort( 0x38a1 ),	/* 14497 */
/* 1226 */	NdrFcShort( 0x4676 ),	/* 18038 */
/* 1228 */	0xa1,		/* 161 */
			0x91,		/* 145 */
/* 1230 */	0xba,		/* 186 */
			0xa7,		/* 167 */
/* 1232 */	0x5f,		/* 95 */
			0x1,		/* 1 */
/* 1234 */	0xd2,		/* 210 */
			0x16,		/* 22 */
/* 1236 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1238 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1240) */
/* 1240 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1242 */	NdrFcLong( 0x9c77ea62 ),	/* -1669862814 */
/* 1246 */	NdrFcShort( 0x6498 ),	/* 25752 */
/* 1248 */	NdrFcShort( 0x4cf5 ),	/* 19701 */
/* 1250 */	0xaf,		/* 175 */
			0x36,		/* 54 */
/* 1252 */	0x35,		/* 53 */
			0x88,		/* 136 */
/* 1254 */	0x6b,		/* 107 */
			0x2f,		/* 47 */
/* 1256 */	0x5,		/* 5 */
			0x70,		/* 112 */
/* 1258 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1260 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1262) */
/* 1262 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1264 */	NdrFcLong( 0x6d9f6760 ),	/* 1839163232 */
/* 1268 */	NdrFcShort( 0x7a70 ),	/* 31344 */
/* 1270 */	NdrFcShort( 0x4524 ),	/* 17700 */
/* 1272 */	0x88,		/* 136 */
			0x2d,		/* 45 */
/* 1274 */	0xe8,		/* 232 */
			0xe5,		/* 229 */
/* 1276 */	0x6a,		/* 106 */
			0x21,		/* 33 */
/* 1278 */	0xe4,		/* 228 */
			0xd5,		/* 213 */
/* 1280 */	
			0x12, 0x0,	/* FC_UP */
/* 1282 */	NdrFcShort( 0xfc96 ),	/* Offset= -874 (408) */
/* 1284 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1286 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1288 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1290 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1292 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (1280) */
/* 1294 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1296 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1298) */
/* 1298 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1300 */	NdrFcLong( 0xd4d229fa ),	/* -724424198 */
/* 1304 */	NdrFcShort( 0x87a2 ),	/* -30814 */
/* 1306 */	NdrFcShort( 0x4a22 ),	/* 18978 */
/* 1308 */	0xb5,		/* 181 */
			0x8d,		/* 141 */
/* 1310 */	0xdb,		/* 219 */
			0x58,		/* 88 */
/* 1312 */	0x98,		/* 152 */
			0xb4,		/* 180 */
/* 1314 */	0xd9,		/* 217 */
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
    42
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
    84,
    120,
    156,
    192,
    228,
    264,
    300,
    336,
    372,
    408,
    444,
    480
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
    84,
    120,
    516,
    552,
    588,
    624,
    300,
    336
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
    660,
    696,
    732,
    768,
    804
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
    840,
    876,
    912,
    948,
    984,
    1020
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
    1056,
    1284,
    156,
    1326,
    1362,
    1398,
    1434
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
    1470,
    1506,
    1542,
    1578,
    1614,
    1650,
    1686
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
    1722,
    1758,
    156,
    192,
    1794,
    1830,
    1866,
    1902,
    1938,
    1974,
    2010,
    2046,
    2082
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
    2118,
    2154,
    2190,
    2226,
    2262
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
    2298,
    2340,
    2376,
    2412,
    2448,
    2484,
    2520,
    336,
    2550,
    2592,
    2628,
    2664,
    2694,
    2736,
    2772,
    2808
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
    2844,
    2880,
    912,
    2916,
    588,
    2952,
    300,
    2988,
    372,
    3024,
    3060,
    3096,
    3132,
    3168,
    3204,
    3240,
    3276,
    3306,
    3342,
    3378,
    3432
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
#pragma optimize("", on )
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/

