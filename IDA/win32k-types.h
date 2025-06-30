// Type information for IDA Freeware

typedef struct _THRDESKHEAD
{
  struct
  {
    struct
    {
      HANDLE h;
      DWORD cLockObj;
    };
    struct _THREADINFO *pti;
  };
  struct _DESKTOP *rpdesk;
  PVOID pSelf;
} THRDESKHEAD, *PTHRDESKHEAD;

typedef struct _LARGE_UNICODE_STRING
{
  ULONG Length;
  ULONG MaximumLength : 31;
  ULONG bAnsi : 1;
  PWSTR Buffer;
} LARGE_UNICODE_STRING, *PLARGE_UNICODE_STRING;

typedef struct _UNICODE_STRING
{
  WORD Length;
  WORD MaximumLength;
  WCHAR *Buffer;
} UNICODE_STRING, *PUNICODE_STRING;

typedef LRESULT (__stdcall *WNDPROC)(HWND, UINT, WPARAM, LPARAM);

typedef struct _CLS
{
  struct _CLS *pclsNext;
  RTL_ATOM atomClassName;
  ATOM atomNVClassName;
  DWORD fnid;
  struct _DESKTOP *rpdeskParent;
  PVOID pdce;
  DWORD CSF_flags;
  PSTR lpszClientAnsiMenuName;
  PWSTR lpszClientUnicodeMenuName;
  PVOID spcpdFirst;
  struct _CLS *pclsBase;
  struct _CLS *pclsClone;
  ULONG cWndReferenceCount;
  UINT style;
  WNDPROC lpfnWndProc;
  INT cbclsExtra;
  INT cbwndExtra;
} CLS, *PCLS;

typedef HANDLE HIMC;

typedef struct _WND
{
  THRDESKHEAD head;
  DWORD state;
  DWORD state2;
  DWORD ExStyle;
  DWORD style;
  HINSTANCE hModule;
  DWORD fnid;
  struct _WND *spwndNext;
  struct _WND *spwndPrev;
  struct _WND *spwndParent;
  struct _WND *spwndChild;
  struct _WND *spwndOwner;
  RECT rcWindow;
  RECT rcClient;
  WNDPROC lpfnWndProc;
  PCLS pcls;
  HRGN hrgnUpdate;
  PVOID ppropList;
  PVOID pSBInfo;
  PVOID spmenuSys;
  PVOID spmenu;
  HRGN hrgnClip;
  LARGE_UNICODE_STRING strName;
  ULONG ULONG;
  struct _WND *spwndLastActive;
  HIMC hImc;
  LONG_PTR dwUserData;
  PVOID pActCtx;
} WND, *PWND;

typedef struct _TL
{
  struct _TL *next;
  PVOID pobj;
  PVOID pfnFree;
} TL, *PTL;

typedef struct _HEAD
{
  HANDLE h;
  DWORD cLockObj;
} HEAD, *PHEAD;

typedef struct _PROCDESKHEAD
{
  HEAD head;
  DWORD_PTR hTaskWow;
  PVOID *rpdesk;
  PVOID pSelf;
} PROCDESKHEAD, *PPROCDESKHEAD;

typedef struct tagMENU
{
  PROCDESKHEAD head;
  ULONG fFlags;
  INT iItem;
  UINT cAlloced;
  UINT cItems;
  ULONG cxMenu;
  ULONG cyMenu;
  ULONG cxTextAlign;
  WND *spwndNotify;
  PVOID rgItems;
  PVOID pParentMenus;
  DWORD dwContextHelpId;
  ULONG cyMax;
  DWORD_PTR dwMenuData;
  HBRUSH hbrBack;
  INT iTop;
  INT iMaxTop;
  ULONG dwArrowsOn : 2;
  BOOL TimeToHide;
} MENU, *PMENU;

typedef struct tagPOPUPMENU
{
  UINT flags;
  struct _WND *spwndNotify;
  struct _WND *spwndPopupMenu;
  struct _WND *spwndNextPopup;
  struct _WND *spwndPrevPopup;
  PMENU spmenu;
  PMENU spmenuAlternate;
  struct _WND *spwndActivePopup;
  struct tagPOPUPMENU *ppopupmenuRoot;
  struct tagPOPUPMENU *ppmDelayedFree;
  UINT posSelectedItem;
  UINT posDropped;
} POPUPMENU, *PPOPUPMENU;

typedef struct _MLIST
{
  LPVOID pqmsgRead;
  LPVOID pqmsgWriteLast;
  DWORD cMsgs;
} MLIST, *PMLIST;

typedef struct tagQ
{
  MLIST mlInput;
  struct _THREADINFO *ptiSysLock;
  ULONG_PTR idSysLock;
  ULONG_PTR idSysPeek;
  struct _THREADINFO *ptiMouse;
  struct _THREADINFO *ptiKeyboard;
  PWND spwndCapture;
  PWND spwndFocus;
  PWND spwndActive;
  PWND spwndActivePrev;
  DWORD codeCapture;
  DWORD msgDblClk;
  DWORD xbtnDblClk;
  DWORD timeDblClk;
  HWND hwndDblClk;
  POINT ptDblClk;
  BYTE afKeyRecentDown[32];
  BYTE afKeyState[64];
} Q, *PQ;

typedef struct tagIMEINFO
{
  DWORD dwPrivateDataSize;
  DWORD fdwProperty;
  DWORD fdwConversionCaps;
  DWORD fdwSentenceCaps;
  DWORD fdwUICaps;
  DWORD fdwSCSCaps;
  DWORD fdwSelectCaps;
} IMEINFO, *PIMEINFO;

typedef struct tagIMEINFOEX
{
  HKL hkl;
  IMEINFO ImeInfo;
  WCHAR wszUIClass[16];
  ULONG fdwInitConvMode;
  INT fInitOpen;
  INT fLoadFlag;
  DWORD dwProdVersion;
  DWORD dwImeWinVersion;
  WCHAR wszImeDescription[50];
  WCHAR wszImeFile[80];
  struct
  {
    __int32 fSysWow64Only : 1;
    __int32 fCUASLayer : 1;
  };
} IMEINFOEX, *PIMEINFOEX;

typedef struct tagKL
{
  HEAD head;
  struct tagKL *pklNext;
  struct tagKL *pklPrev;
  DWORD dwKL_Flags;
  HKL hkl;
  PVOID spkf;
  DWORD dwFontSigs;
  UINT iBaseCharset;
  USHORT CodePage;
  WCHAR wchDiacritic;
  PIMEINFOEX piiex;
} KL, *PKL;

typedef struct _DESKTOPINFO
{
  PVOID pvDesktopBase;
  PVOID pvDesktopLimit;
  struct _WND *spwnd;
  DWORD fsHooks;
  LIST_ENTRY aphkStart[14];
  HWND hTaskManWindow;
  HWND hProgmanWindow;
  HWND hShellWindow;
  struct _WND *spwndShell;
  struct _WND *spwndBkGnd;
  struct _PROCESSINFO *ppiShellProcess;
  union
  {
    UINT Dummy;
    struct
    {
      unsigned __int32 LastInputWasKbd : 1;
    };
  };
  WCHAR szDesktopName[1];
} DESKTOPINFO, *PDESKTOPINFO;

typedef struct _THREADINFO
{
  struct
  {
    void *pEThread;
    unsigned int RefCount;
    PTL ptlW32;
    void *pgdiDcattr;
    void *pgdiBrushAttr;
    void *pUMPDObjs;
    void *pUMPDHeap;
    void *pUMPDObj;
    LIST_ENTRY GdiTmpAllocList;
  };
  PTL ptl;
  PVOID ppi;
  PQ pq;
  PKL spklActive;
  PVOID pcti;
  PVOID rpdesk;
  PDESKTOPINFO pDeskInfo;
  PVOID pClientInfo;
  PVOID Data;
  ULONG TIF_flags;
  PUNICODE_STRING pstrAppName;
  PVOID psmsSent;
  PVOID psmsCurrent;
  PVOID psmsReceiveList;
  LONG timeLast;
  ULONG_PTR idLast;
  union
  {
    INT cQuit;
    INT exitCode;
  };
  HDESK hdesk;
  INT cPaintsReady;
  UINT cTimersReady;
  struct tagMENUSTATE *pMenuState;
  union
  {
    PVOID ptdb;
    PVOID pwinsta;
  };
  PVOID psiiList;
  ULONG dwExpWinVer;
  ULONG dwCompatFlags;
  ULONG dwCompatFlags2;
  PQ pqAttach;
  PVOID ptiSibling;
  PVOID pmsd;
  ULONG fsHooks;
  PVOID sphkCurrent;
  PVOID pSBTrack;
  HANDLE hEventQueueClient;
  PVOID pEventQueueServer;
  LIST_ENTRY PtiLink;
  INT iCursorLevel;
  POINT ptLast;
  PWND spwndDefaultIme;
  PVOID spDefaultImc;
  HKL hklPrev;
  INT cEnterCount;
} THREADINFO, *PTHREADINFO;

typedef struct tagMENUSTATE
{
  PPOPUPMENU pGlobalPopupMenu;
  UINT flags;
  POINT ptMouseLast;
  INT mnFocus;
  INT cmdLast;
  PTHREADINFO ptiMenuStateOwner;
  DWORD dwLockCount;
  struct tagMENUSTATE *pmnsPrev;
  POINT ptButtonDown;
  ULONG_PTR uButtonDownHitArea;
  UINT uButtonDownIndex;
  INT vkButtonDown;
  ULONG_PTR uDraggingHitArea;
  UINT uDraggingIndex;
  UINT uDraggingFlags;
  HDC hdcWndAni;
  DWORD dwAniStartTime;
  INT ixAni;
  INT iyAni;
  INT cxAni;
  INT cyAni;
  HBITMAP hbmAni;
  HDC hdcAni;
} MENUSTATE, *PMENUSTATE;

typedef struct _DESKTOP
{
  DWORD dwSessionId;
  PDESKTOPINFO pDeskInfo;
  LIST_ENTRY ListEntry;
  struct _WINSTATION_OBJECT *rpwinstaParent;
  DWORD dwDTFlags;
  DWORD_PTR dwDesktopId;
  PVOID spmenuSys;
  PVOID spmenuDialogSys;
  PVOID spmenuHScroll;
  PVOID spmenuVScroll;
  PWND spwndForeground;
  PWND spwndTray;
  PWND spwndMessage;
  PWND spwndTooltip;
  PVOID hsectionDesktop;
  PVOID pheapDesktop;
  ULONG_PTR ulHeapSize;
  LIST_ENTRY PtiList;
} DESKTOP, *PDESKTOP;

typedef struct _CLIENTTHREADINFO
{
    DWORD CTI_flags;
    WORD fsChangeBits;
    WORD fsWakeBits;
    WORD fsWakeBitsJournal;
    WORD fsWakeMask;
    ULONG timeLastRead;
    DWORD dwcPumpHook;
} CLIENTTHREADINFO, *PCLIENTTHREADINFO;

typedef struct tagHOOK
{
    THRDESKHEAD head;
    struct tagHOOK *phkNext;
    int HookId;
    ULONG_PTR offPfn;
    ULONG flags;
    INT_PTR ihmod;
    struct _THREADINFO *ptiHooked;
    struct _DESKTOP *rpdesk;
} HOOK, *PHOOK;

typedef struct _CALLBACKWND
{
    HWND hWnd;
    struct _WND *pWnd;
    PVOID pActCtx;
} CALLBACKWND, *PCALLBACKWND;

typedef struct tagMSG
{
    HWND hwnd;
    UINT message;
    WPARAM wParam;
    LPARAM lParam;
    DWORD time;
    POINT pt;
} MSG, *PMSG, *LPMSG;

typedef struct _CLIENTINFO
{
    ULONG_PTR CI_flags;
    ULONG_PTR cSpins;
    DWORD dwExpWinVer;
    DWORD dwCompatFlags;
    DWORD dwCompatFlags2;
    DWORD dwTIFlags;
    PDESKTOPINFO pDeskInfo;
    ULONG_PTR ulClientDelta;
    PHOOK phkCurrent;
    ULONG fsHooks;
    CALLBACKWND CallbackWnd;
    DWORD dwHookCurrent;
    INT cInDDEMLCallback;
    PCLIENTTHREADINFO pClientThreadInfo;
    ULONG_PTR dwHookData;
    DWORD dwKeyCache;
    BYTE afKeyState[8];
    DWORD dwAsyncKeyCache;
    BYTE afAsyncKeyState[8];
    BYTE afAsyncKeyStateRecentDow[8];
    HKL hKL;
    USHORT CodePage;
    UCHAR achDbcsCF[2];
    MSG msgDbcsCB;
    LPDWORD lpdwRegisteredClasses;
    ULONG Win32ClientInfo3[26];
    struct _PROCESSINFO *ppi;
} CLIENTINFO, *PCLIENTINFO;

typedef struct tagITEM
{
    UINT fType;
    UINT fState;
    UINT wID;
    struct tagMENU *spSubMenu;
    HANDLE hbmpChecked;
    HANDLE hbmpUnchecked;
    USHORT *Xlpstr;
    ULONG cch;
    DWORD_PTR dwItemData;
    ULONG xItem;
    ULONG yItem;
    ULONG cxItem;
    ULONG cyItem;
    ULONG dxTab;
    ULONG ulX;
    ULONG ulWidth;
    HBITMAP hbmp;
    INT cxBmp;
    INT cyBmp;
} ITEM, *PITEM;

typedef struct tagMENULIST
{
    struct tagMENULIST *pNext;
    struct tagMENU *pMenu;
} MENULIST, *PMENULIST;

/* dwType for NtUserQueryInputContext */
typedef enum _QUERY_INPUT_CONTEXT
{
    QIC_INPUTPROCESSID = 0,
    QIC_INPUTTHREADID,
    QIC_DEFAULTWINDOWIME,
    QIC_DEFAULTIMC
} QUERY_INPUT_CONTEXT;

/* NtUserSetImeHotKey actions */
typedef enum tagSETIMEHOTKEY_ACTION
{
    SETIMEHOTKEY_DELETE = 1,
    SETIMEHOTKEY_ADD,
    SETIMEHOTKEY_INITIALIZE
} SETIMEHOTKEY_ACTION;

typedef struct tagMBSTRING
{
    WCHAR szName[16];
    UINT uID;
    UINT uStr;
} MBSTRING, *PMBSTRING;

/* extern PSERVERINFO gpsi; */
typedef struct tagSERVERINFO
{
  DWORD dwSRVIFlags;
  ULONG_PTR cHandleEntries;
  LPVOID mpFnidPfn[31];
  WNDPROC aStoCidPfn[7];
  USHORT mpFnid_serverCBWndProc[31];
  LPVOID apfnClientA;
  LPVOID apfnClientW;
  LPVOID apfnClientWorker;
  ULONG cbHandleTable;
  ATOM atomSysClass[24];
  DWORD dwDefaultHeapBase;
  DWORD dwDefaultHeapSize;
  UINT uiShellMsg;
  MBSTRING MBStrings[11];
  ATOM atomIconSmProp;
  ATOM atomIconProp;
  ATOM atomContextHelpIdProp;
  ATOM atomFrostedWindowProp;
  CHAR acOemToAnsi[256];
  CHAR acAnsiToOem[256];
  DWORD dwInstalledEventHooks;
  INT aiSysMet[83];
  ULONG argbSystemUnmatched[31];
  COLORREF argbSystem[31];
  HBRUSH ahbrSystem[31];
  HBRUSH hbrGray;
  POINT ptCursor;
  POINT ptCursorReal;
  DWORD dwLastRITEventTickCount;
  INT nEvents;
  UINT dtScroll;
  UINT dtLBSearch;
  UINT dtCaretBlink;
  UINT ucWheelScrollLines;
  UINT ucWheelScrollChars;
  INT wMaxLeftOverlapChars;
  INT wMaxRightOverlapChars;
  INT cxSysFontChar;
  INT cySysFontChar;
  TEXTMETRICW tmSysFont;
} SERVERINFO, *PSERVERINFO;
