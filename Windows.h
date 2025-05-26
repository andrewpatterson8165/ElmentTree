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


#endif
