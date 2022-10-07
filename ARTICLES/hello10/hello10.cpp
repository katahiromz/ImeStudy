#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>
#define _USE_MATH_DEFINES
#include <math.h>

#define NAME TEXT("hello10")

HINSTANCE g_hInstance = NULL;
HWND g_hMainWnd = NULL;
BOOL g_bButtonDown = FALSE;

#define TIMER_ID 999
#define INTERVAL 100

BOOL OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct)
{
    SetTimer(hwnd, TIMER_ID, INTERVAL, NULL);
    return TRUE;
}

void OnDestroy(HWND hwnd)
{
    KillTimer(hwnd, TIMER_ID);
    PostQuitMessage(0);
}

void OnPaint(HWND hwnd)
{
    RECT rc;
    GetClientRect(hwnd, &rc);

    RECT rcWnd;
    GetWindowRect(hwnd, &rcWnd);
    POINT ptWnd = { (rcWnd.left + rcWnd.right) / 2, (rcWnd.top + rcWnd.bottom) / 2 };

    POINT ptCursor;
    GetCursorPos(&ptCursor);

    PAINTSTRUCT ps;
    if (HDC hdc = BeginPaint(hwnd, &ps))
    {
        INT px = (rc.left + rc.right) / 2;
        RECT rc1, rc2;
        SetRect(&rc1, rc.left, rc.top, px, rc.bottom);
        SetRect(&rc2, px, rc.top, rc.right, rc.bottom);
        {
            HBRUSH hbr1 = GetStockBrush(WHITE_BRUSH);
            HGDIOBJ hbr1Old = SelectObject(hdc, hbr1);
            HPEN hPen1 = CreatePen(PS_SOLID, 15, RGB(0, 0, 0));
            HGDIOBJ hPen1Old = SelectObject(hdc, hPen1);
            {
                Ellipse(hdc, rc1.left, rc1.top, rc1.right, rc1.bottom);
                Ellipse(hdc, rc2.left, rc2.top, rc2.right, rc2.bottom);
            }
            SelectObject(hdc, hPen1Old);
            DeleteObject(hPen1);
            SelectObject(hdc, hbr1Old);
            if (g_bButtonDown)
            {
                HPEN hPen3 = CreatePen(PS_SOLID, 8, RGB(255, 0, 0));
                HGDIOBJ hPen3Old = SelectObject(hdc, hPen3);
                {
                    MoveToEx(hdc, rc1.left, rc1.top, NULL);
                    LineTo(hdc, rc1.right, rc1.bottom);
                    MoveToEx(hdc, rc1.right, rc1.top, NULL);
                    LineTo(hdc, rc1.left, rc1.bottom);

                    MoveToEx(hdc, rc2.left, rc2.top, NULL);
                    LineTo(hdc, rc2.right, rc2.bottom);
                    MoveToEx(hdc, rc2.right, rc2.top, NULL);
                    LineTo(hdc, rc2.left, rc2.bottom);
                }
                SelectObject(hdc, hPen3Old);
                DeleteObject(hPen3);
            }
            else
            {
                HBRUSH hbr2 = CreateSolidBrush(RGB(0, 0, 255));
                HGDIOBJ hbr2Old = SelectObject(hdc, hbr2);
                HGDIOBJ hPen2Old = SelectObject(hdc, GetStockBrush(NULL_PEN));
                {
                    RECT rc3 = rc1, rc4 = rc2;
                    InflateRect(&rc3, -20, -20);
                    InflateRect(&rc4, -20, -20);
                    double radian = atan2(ptCursor.y - ptWnd.y, ptCursor.x - ptWnd.x);
                    OffsetRect(&rc3, INT(20 * cos(radian)), INT(20 * sin(radian)));
                    OffsetRect(&rc4, INT(20 * cos(radian)), INT(20 * sin(radian)));
                    Ellipse(hdc, rc3.left, rc3.top, rc3.right, rc3.bottom);
                    Ellipse(hdc, rc4.left, rc4.top, rc4.right, rc4.bottom);
                }
                SelectObject(hdc, hPen2Old);
                SelectObject(hdc, hbr2Old);
                DeleteObject(hbr2);
            }
        }
        EndPaint(hwnd, &ps);
    }
}

void OnTimer(HWND hwnd, UINT id)
{
    if (id == TIMER_ID)
    {
        InvalidateRect(hwnd, NULL, TRUE);
    }
}

void OnLButtonDown(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT keyFlags)
{
    g_bButtonDown = TRUE;
}

void OnLButtonUp(HWND hwnd, int x, int y, UINT keyFlags)
{
    g_bButtonDown = FALSE;
}

LRESULT CALLBACK
WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        HANDLE_MSG(hwnd, WM_CREATE, OnCreate);
        HANDLE_MSG(hwnd, WM_PAINT, OnPaint);
        HANDLE_MSG(hwnd, WM_TIMER, OnTimer);
        HANDLE_MSG(hwnd, WM_LBUTTONDOWN, OnLButtonDown);
        HANDLE_MSG(hwnd, WM_LBUTTONDBLCLK, OnLButtonDown);
        HANDLE_MSG(hwnd, WM_LBUTTONUP, OnLButtonUp);
        HANDLE_MSG(hwnd, WM_DESTROY, OnDestroy);
    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}

BOOL doInitInst(HINSTANCE hInstance)
{
    InitCommonControls();

    g_hInstance = hInstance;

    WNDCLASSEX wcx = { sizeof(wcx) };
    wcx.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
    wcx.lpfnWndProc = WindowProc;
    wcx.hInstance = hInstance;
    wcx.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wcx.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcx.hbrBackground = (HBRUSH)(COLOR_3DDKSHADOW + 1);
    wcx.lpszClassName = NAME;
    if (!RegisterClassEx(&wcx))
    {
        MessageBoxA(NULL, "RegisterClass failed", NULL, MB_ICONERROR);
        return FALSE;
    }

    return TRUE;
}

BOOL doCreateWnd(HINSTANCE hInstance, INT nCmdShow)
{
    DWORD style = WS_OVERLAPPEDWINDOW;
    DWORD exstyle = 0;
    g_hMainWnd = CreateWindowEx(exstyle, NAME, NAME, style,
                                CW_USEDEFAULT, CW_USEDEFAULT,
                                300, 200, NULL, NULL, hInstance, NULL);
    if (g_hMainWnd == NULL)
    {
        MessageBoxA(NULL, "CreateWindow failed", NULL, MB_ICONERROR);
        return FALSE;
    }

    ShowWindow(g_hMainWnd, nCmdShow);
    UpdateWindow(g_hMainWnd);
    return TRUE;
}

INT WINAPI
WinMain(HINSTANCE   hInstance,
        HINSTANCE   hPrevInstance,
        LPSTR       lpCmdLine,
        INT         nCmdShow)
{
    if (!doInitInst(hInstance))
        return -1;

    if (!doCreateWnd(hInstance, nCmdShow))
        return -2;

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

#if defined(_MSC_VER) && !defined(NDEBUG)
    // for detecting memory leak (MSVC only)
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

    return (INT)msg.wParam;
}
