# Experiment14

## Purpose

Inspect IME messages without input.

## Platform

Windows XP Japanese.

## Tools

- [tests/MsgDump](tests/MsgDump)

## Window Handles

- HWND 000D01A4, window class name "MZC4 MMainWnd Class"
- HWND 00070210, window class name "Edit"
- HWND 001501D2, window class name "IME"

## Work

- Build [tests/MsgDump](tests/MsgDump).
- Execute "MyProject.exe > MsgDump-winxpjp.txt" from Command Prompt.

## The log

- MMainWnd:P: WM_CREATE(hwnd:000D01A4, lpCreateStruct:0022F7F4)
- main:000d01a4
- m_edt1:00070210
- m_ime:001501d2
- MMainWnd:R: WM_CREATE: hwnd:000D01A4, lResult:00000000
- MMainWnd:P: WM_SHOWWINDOW(hwnd:000D01A4, fShow:1, status:0)
- MMainWnd:R: WM_SHOWWINDOW: hwnd:000D01A4, lResult:00000000
- IME:P: WM_WINDOWPOSCHANGING(hwnd:001501D2, lpwpos:0022FE24)
- IME:R: WM_WINDOWPOSCHANGING: hwnd:001501D2, lResult:00000000
- MMainWnd:P: WM_WINDOWPOSCHANGING(hwnd:000D01A4, lpwpos:0022FE24)
- MMainWnd:R: WM_WINDOWPOSCHANGING: hwnd:000D01A4, lResult:00000000
- IME:P: WM_WINDOWPOSCHANGING(hwnd:001501D2, lpwpos:0022FE24)
- IME:R: WM_WINDOWPOSCHANGING: hwnd:001501D2, lResult:00000000
- MMainWnd:P: WM_WINDOWPOSCHANGING(hwnd:000D01A4, lpwpos:0022FE24)
- MMainWnd:R: WM_WINDOWPOSCHANGING: hwnd:000D01A4, lResult:00000000
- IME:P: WM_ACTIVATEAPP(hwnd:001501D2, fActivate:1, dwThreadId:0x00000704)
- IME:R: WM_ACTIVATEAPP: hwnd:001501D2, lResult:00000000
- MMainWnd:P: WM_ACTIVATEAPP(hwnd:000D01A4, fActivate:1, dwThreadId:0x00000704)
- MMainWnd:R: WM_ACTIVATEAPP: hwnd:000D01A4, lResult:00000000
- MMainWnd:P: WM_NCACTIVATE(hwnd:000D01A4, fActive:1, hwndActDeact:00000000, fMinimized:0)
- MMainWnd:P: WM_GETICON(hwnd:000D01A4, nType:2, dpi:00000000)
- MMainWnd:R: WM_GETICON: hwnd:000D01A4, lResult:00000000
- MMainWnd:P: WM_GETICON(hwnd:000D01A4, nType:0, dpi:00000000)
- MMainWnd:R: WM_GETICON: hwnd:000D01A4, lResult:00000000
- MMainWnd:P: WM_GETICON(hwnd:000D01A4, nType:1, dpi:00000000)
- MMainWnd:R: WM_GETICON: hwnd:000D01A4, lResult:00000000
- MMainWnd:R: WM_NCACTIVATE: hwnd:000D01A4, lResult:00000001
- MMainWnd:P: WM_ACTIVATE(hwnd:000D01A4, state:1, hwndActDeact:00000000, fMinimized:0)
- IME:P: WM_647(hwnd:001501D2, wParam:00000017, lParam:000D01A4)
- MMainWnd:P: WM_IME_SETCONTEXT(hwnd:000D01A4, fActive:1, dwShow:0xC000000F)
- IME:P: WM_IME_SETCONTEXT(hwnd:001501D2, fActive:1, dwShow:0xC000000F)
- MMainWnd:P: WM_IME_NOTIFY(hwnd:000D01A4, wSubMessage:00000002, lParam:00000000)
- IME:P: WM_IME_NOTIFY(hwnd:001501D2, wSubMessage:00000002, lParam:00000000)
- IME:R: WM_IME_NOTIFY: hwnd:001501D2, lResult:00000000
- MMainWnd:R: WM_IME_NOTIFY: hwnd:000D01A4, lResult:00000000
- IME:R: WM_IME_SETCONTEXT: hwnd:001501D2, lResult:00000000
- MMainWnd:R: WM_IME_SETCONTEXT: hwnd:000D01A4, lResult:00000000
- IME:R: WM_647(hwnd:001501D2, lResult:00000000)
- MMainWnd:P: WM_SETFOCUS(hwnd:000D01A4, hwndOldFocus:00000000)
- MMainWnd:R: WM_SETFOCUS: hwnd:000D01A4, lResult:00000000
- MMainWnd:R: WM_ACTIVATE: hwnd:000D01A4, lResult:00000000
- MMainWnd:P: WM_NCPAINT(hwnd:000D01A4, hrgn:00000001)
- MMainWnd:R: WM_NCPAINT: hwnd:000D01A4, lResult:00000000
- MMainWnd:P: WM_ERASEBKGND(hwnd:000D01A4, hdc:01010056)
- MMainWnd:R: WM_ERASEBKGND: hwnd:000D01A4, lResult:00000001
- IME:P: WM_WINDOWPOSCHANGED(hwnd:001501D2, lpwpos:0022FE24)
- IME:R: WM_WINDOWPOSCHANGED: hwnd:001501D2, lResult:00000000
- MMainWnd:P: WM_WINDOWPOSCHANGED(hwnd:000D01A4, lpwpos:0022FE24)
- MMainWnd:R: WM_WINDOWPOSCHANGED: hwnd:000D01A4, lResult:00000000
- MMainWnd:P: WM_NCCALCSIZE(hwnd:000D01A4, fCalcValidRects:1, lpcsp:0022FA54)
- MMainWnd:R: WM_NCCALCSIZE: hwnd:000D01A4, lResult:00000000
- MMainWnd:P: WM_NCPAINT(hwnd:000D01A4, hrgn:00000001)
- MMainWnd:R: WM_NCPAINT: hwnd:000D01A4, lResult:00000000
- MMainWnd:P: WM_ERASEBKGND(hwnd:000D01A4, hdc:01010059)
- MMainWnd:R: WM_ERASEBKGND: hwnd:000D01A4, lResult:00000001
- MMainWnd:P: WM_SIZE(hwnd:000D01A4, state:0, cx:595, cy:354)
- MMainWnd:R: WM_SIZE: hwnd:000D01A4, lResult:00000000
- MMainWnd:P: WM_MOVE(hwnd:000D01A4, x:48, y:88)
- MMainWnd:R: WM_MOVE: hwnd:000D01A4, lResult:00000000
- MMainWnd:P: WM_PAINT(hwnd:000D01A4)
- MMainWnd:R: WM_PAINT: hwnd:000D01A4, lResult:00000000
- EDIT:P: WM_PAINT(hwnd:00070210)
- EDIT:P: WM_NCPAINT(hwnd:00070210, hrgn:00000001)
- EDIT:R: WM_NCPAINT: hwnd:00070210, lResult:00000000
- EDIT:P: WM_ERASEBKGND(hwnd:00070210, hdc:01010059)
- MMainWnd:P: WM_CTLCOLOR(hwnd:000D01A4, hdc:01010059, hwndChild:00070210, type:1)
- MMainWnd:R: WM_CTLCOLOREDIT: hwnd:000D01A4, lResult:01100063
- EDIT:R: WM_ERASEBKGND: hwnd:00070210, lResult:00000001
- MMainWnd:P: WM_CTLCOLOR(hwnd:000D01A4, hdc:01010059, hwndChild:00070210, type:1)
- MMainWnd:R: WM_CTLCOLOREDIT: hwnd:000D01A4, lResult:01100063
- EDIT:R: WM_PAINT: hwnd:00070210, lResult:00000001
- MMainWnd:S: WM_GETICON(hwnd:000D01A4, nType:2, dpi:00000000)
- MMainWnd:R: WM_GETICON: hwnd:000D01A4, lResult:00000000
- MMainWnd:S: WM_GETICON(hwnd:000D01A4, nType:0, dpi:00000000)
- MMainWnd:R: WM_GETICON: hwnd:000D01A4, lResult:00000000
- MMainWnd:S: WM_GETICON(hwnd:000D01A4, nType:1, dpi:00000000)
- MMainWnd:R: WM_GETICON: hwnd:000D01A4, lResult:00000000
- MMainWnd:P: WM_49276(hwnd:000D01A4, wParam:0100098A, lParam:00000000)
- MMainWnd:R: WM_49276(hwnd:000D01A4, lResult:00000000)
- MMainWnd:P: WM_KEYUP(hwnd:000D01A4, vk:13, cRepeat:1, flags:49180)
- MMainWnd:R: WM_KEYUP: hwnd:000D01A4, lResult:00000000
- MMainWnd:P: WM_TIMER(hwnd:000D01A4, id:999)
- MMainWnd:R: WM_TIMER: hwnd:000D01A4, lResult:00000000
- MMainWnd:P: WM_COMMAND(hwnd:000D01A4, id:1, hwndCtl:00000000, codeNotify:0)
- MMainWnd:P: WM_WINDOWPOSCHANGING(hwnd:000D01A4, lpwpos:0022FB5C)
- MMainWnd:R: WM_WINDOWPOSCHANGING: hwnd:000D01A4, lResult:00000000
- MMainWnd:P: WM_WINDOWPOSCHANGED(hwnd:000D01A4, lpwpos:0022FB5C)
- MMainWnd:R: WM_WINDOWPOSCHANGED: hwnd:000D01A4, lResult:00000000
- MMainWnd:P: WM_NCACTIVATE(hwnd:000D01A4, fActive:0, hwndActDeact:00000000, fMinimized:0)
- MMainWnd:R: WM_NCACTIVATE: hwnd:000D01A4, lResult:00000001
- MMainWnd:P: WM_ACTIVATE(hwnd:000D01A4, state:0, hwndActDeact:00000000, fMinimized:0)
- MMainWnd:R: WM_ACTIVATE: hwnd:000D01A4, lResult:00000000
- IME:P: WM_ACTIVATEAPP(hwnd:001501D2, fActivate:0, dwThreadId:0x00000704)
- IME:R: WM_ACTIVATEAPP: hwnd:001501D2, lResult:00000000
- MMainWnd:P: WM_ACTIVATEAPP(hwnd:000D01A4, fActivate:0, dwThreadId:0x00000704)
- MMainWnd:R: WM_ACTIVATEAPP: hwnd:000D01A4, lResult:00000000
- MMainWnd:P: WM_KILLFOCUS(hwnd:000D01A4, hwndNewFocus:00000000)
- MMainWnd:R: WM_KILLFOCUS: hwnd:000D01A4, lResult:00000000
- IME:P: WM_647(hwnd:001501D2, wParam:00000018, lParam:000D01A4)
- MMainWnd:P: WM_IME_SETCONTEXT(hwnd:000D01A4, fActive:0, dwShow:0xC000000F)
- IME:P: WM_IME_SETCONTEXT(hwnd:001501D2, fActive:0, dwShow:0xC000000F)
- MMainWnd:P: WM_IME_NOTIFY(hwnd:000D01A4, wSubMessage:00000001, lParam:00000000)
- IME:P: WM_IME_NOTIFY(hwnd:001501D2, wSubMessage:00000001, lParam:00000000)
- IME:R: WM_IME_NOTIFY: hwnd:001501D2, lResult:00000000
- MMainWnd:R: WM_IME_NOTIFY: hwnd:000D01A4, lResult:00000000
- IME:R: WM_IME_SETCONTEXT: hwnd:001501D2, lResult:00000000
- MMainWnd:R: WM_IME_SETCONTEXT: hwnd:000D01A4, lResult:00000000
- IME:R: WM_647(hwnd:001501D2, lResult:00000000)
- MMainWnd:P: WM_DESTROY(hwnd:000D01A4)
- MMainWnd:R: WM_DESTROY: hwnd:000D01A4, lResult:00000000
- EDIT:P: WM_DESTROY(hwnd:00070210)
- EDIT:R: WM_DESTROY: hwnd:00070210, lResult:00000000
- IME:P: WM_DESTROY(hwnd:001501D2)
- IME:R: WM_DESTROY: hwnd:001501D2, lResult:00000000
- IME:P: WM_NCDESTROY(hwnd:001501D2)
- IME:R: WM_NCDESTROY: hwnd:001501D2, lResult:00000000
- EDIT:P: WM_NCDESTROY(hwnd:00070210)
- EDIT:R: WM_NCDESTROY: hwnd:00070210, lResult:00000000
- MMainWnd:P: WM_NCDESTROY(hwnd:000D01A4)
- MMainWnd:R: WM_NCDESTROY: hwnd:000D01A4, lResult:00000000
- MMainWnd:R: WM_COMMAND: hwnd:000D01A4, lResult:00000000