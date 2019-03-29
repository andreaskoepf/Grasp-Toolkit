

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IObjectInfo,0x92EA75F7,0x994E,0x4925,0x8C,0x88,0x2F,0x9C,0x56,0xF8,0x77,0x56);


MIDL_DEFINE_GUID(IID, IID_IMWArrayFormatFlags,0x30C8EBCB,0x1A50,0x4dee,0xA5,0xE8,0x0C,0x6F,0x7D,0xD5,0x2D,0x4C);


MIDL_DEFINE_GUID(IID, IID_IMWDataConversionFlags,0x5E0BBECB,0xCE72,0x4461,0xAD,0xB8,0x04,0x46,0xAB,0x32,0xCF,0x51);


MIDL_DEFINE_GUID(IID, IID_IMWFlags,0x0A295776,0x23A1,0x410a,0x94,0xBD,0x0C,0x6C,0x61,0xB8,0x91,0xB7);


MIDL_DEFINE_GUID(IID, IID_IMWField,0x0AEC9FFB,0xAB0D,0x4a09,0xBE,0x9C,0x78,0x85,0x7A,0x1B,0x85,0x80);


MIDL_DEFINE_GUID(IID, IID_IMWStruct,0x6C70BB67,0x3F76,0x4176,0x88,0x09,0xC6,0x63,0x93,0xB1,0xFA,0x23);


MIDL_DEFINE_GUID(IID, IID_IMWComplex,0x8CDD4BBF,0xA84C,0x4C50,0xB6,0x00,0xF5,0xE9,0x00,0x08,0x49,0x1D);


MIDL_DEFINE_GUID(IID, IID_IMWSparse,0x6D4874AD,0x38A1,0x4676,0xA1,0x91,0xBA,0xA7,0x5F,0x01,0xD2,0x16);


MIDL_DEFINE_GUID(IID, IID_IMWArg,0x9C77EA62,0x6498,0x4CF5,0xAF,0x36,0x35,0x88,0x6B,0x2F,0x05,0x70);


MIDL_DEFINE_GUID(IID, IID_IMWEnumVararg,0xD4D229FA,0x87A2,0x4a22,0xB5,0x8D,0xDB,0x58,0x98,0xB4,0xD9,0x2F);


MIDL_DEFINE_GUID(IID, IID_IMWMethodArgInfo,0x6D9F6760,0x7A70,0x4524,0x88,0x2D,0xE8,0xE5,0x6A,0x21,0xE4,0xD5);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



