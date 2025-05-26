#ifndef WINDEF_H_
#define WINDEF_H_
#include <cstdint>

#define CONST const

typedef void *LPVOID;
typedef unsigned short UINT16;

typedef uint8_t BYTE;
typedef unsigned short WORD;
typedef unsigned long DWORD;
typedef int64_t INT64; //Required for Windows 11
typedef uint64_t UINT64; //Required for Windows 11
typedef DWORD COLORREF;
typedef void *PVOID;
typedef PVOID HANDLE;
typedef HANDLE HICON;
typedef HANDLE HBRUSH;
typedef HANDLE HCURSOR;


typedef char CHAR;
typedef CHAR* PSTR;

typedef wchar_t WCHAR;
typedef CONST WCHAR *LPCWSTR;
typedef const char* LPCSTR;

typedef LPCWSTR LPCTSTR;

typedef wchar_t WCHAR;
typedef long* LONG_PTR;
typedef LONG_PTR LPARAM;

typedef HANDLE HINSTANCE;
typedef HANDLE HWND;
typedef uint32_t UINT; //default 32 bit type
typedef UINT* WPARAM;
typedef long LONG;
typedef long* LONG_PTR;
typedef LONG_PTR LRESULT;

#endif
