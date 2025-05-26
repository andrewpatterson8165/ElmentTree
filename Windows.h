#ifndef WINDOWS_H_
#define WINDOWS_H_

#include "WinDef.h"

int WinMain(HINSTANCE hInstance, 
            HINSTANCE hPrevInstance,
            PSTR lpCmdLine, 
            int nCmdShow);
  
  
struct POINT
{
  LONG x;
  LONG y;
};
                    
struct MSG
{
  HWND   hwnd;
  UINT   message;
  WPARAM wParam;
  LPARAM lParam;
  DWORD  time;
  POINT  pt;
  DWORD  lPrivate;
};
  
typedef void* WNDPROC;

typedef struct tagWNDCLASSEXA 
{
  UINT      cbSize;
  UINT      style;
  WNDPROC   lpfnWndProc;
  int       cbClsExtra;
  int       cbWndExtra;
  HINSTANCE hInstance;
  HICON     hIcon;
  HCURSOR   hCursor;
  HBRUSH    hbrBackground;
  LPCSTR    lpszMenuName;
  LPCSTR    lpszClassName;
  HICON     hIconSm;
} WNDCLASSEXA, *PWNDCLASSEXA, *NPWNDCLASSEXA, *LPWNDCLASSEXA;


typedef struct tagSIZE 
{
  LONG cx;
  LONG cy;
} SIZE, *PSIZE, *LPSIZE;

typedef struct tagCREATESTRUCTA {
  LPVOID    lpCreateParams;
  HINSTANCE hInstance;
  HMENU     hMenu;
  HWND      hwndParent;
  int       cy;
  int       cx;
  int       y;
  int       x;
  LONG      style;
  LPCSTR    lpszName;
  LPCSTR    lpszClass;
  DWORD     dwExStyle;
} CREATESTRUCTA, *LPCREATESTRUCTA;

typedef struct tagNMHDR { //winuser.h
  HWND     hwndFrom;
  UINT_PTR idFrom;
  UINT     code;
} NMHDR;

typedef struct tagMEASUREITEMSTRUCT {
  UINT      CtlType;
  UINT      CtlID;
  UINT      itemID;
  UINT      itemWidth;
  UINT      itemHeight;
  ULONG_PTR itemData;
} MEASUREITEMSTRUCT, *PMEASUREITEMSTRUCT, *LPMEASUREITEMSTRUCT;

#endif

