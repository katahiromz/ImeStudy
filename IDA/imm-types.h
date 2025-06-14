// Type information for IDA Freeware
// <imm.h>
// <immdev.h>
// <imm32_undoc.h>
// <ntuser.h>

typedef HANDLE HIMC;
typedef HANDLE HIMCC;

typedef HKL *LPHKL;
typedef UINT *LPUINT;

typedef struct tagREGISTERWORDA {
    LPSTR lpReading;
    LPSTR lpWord;
} REGISTERWORDA, *PREGISTERWORDA, *NPREGISTERWORDA, *LPREGISTERWORDA;

typedef struct tagREGISTERWORDW {
    LPWSTR lpReading;
    LPWSTR lpWord;
} REGISTERWORDW, *PREGISTERWORDW, *NPREGISTERWORDW, *LPREGISTERWORDW;

typedef INT (__stdcall *REGISTERWORDENUMPROCA)(
    LPCSTR lpszReading,
    DWORD dwStyle,
    LPCSTR lpszRegister,
    LPVOID lpData);

typedef INT (__stdcall *REGISTERWORDENUMPROCW)(
    LPCWSTR lpszReading,
    DWORD dwStyle,
    LPCWSTR lpszRegister,
    LPVOID lpData);

typedef struct tagCANDIDATEFORM {
    DWORD dwIndex;
    DWORD dwStyle;
    POINT ptCurrentPos;
    RECT  rcArea;
} CANDIDATEFORM, *PCANDIDATEFORM, *NPCANDIDATEFORM, *LPCANDIDATEFORM;

typedef struct tagCANDIDATELIST {
    DWORD dwSize;
    DWORD dwStyle;
    DWORD dwCount;
    DWORD dwSelection;
    DWORD dwPageStart;
    DWORD dwPageSize;
    DWORD dwOffset[1];
} CANDIDATELIST, *PCANDIDATELIST, *NPCANDIDATELIST, *LPCANDIDATELIST;

typedef struct tagSTYLEBUFA {
    DWORD dwStyle;
    CHAR  szDescription[32];
} STYLEBUFA, *PSTYLEBUFA, *NPSTYLEBUFA, *LPSTYLEBUFA;

typedef struct tagSTYLEBUFW {
    DWORD dwStyle;
    WCHAR  szDescription[32];
} STYLEBUFW, *PSTYLEBUFW, *NPSTYLEBUFW, *LPSTYLEBUFW;

typedef struct tagRECONVERTSTRING {
    DWORD dwSize;
    DWORD dwVersion;
    DWORD dwStrLen;
    DWORD dwStrOffset;
    DWORD dwCompStrLen;
    DWORD dwCompStrOffset;
    DWORD dwTargetStrLen;
    DWORD dwTargetStrOffset;
} RECONVERTSTRING, *PRECONVERTSTRING, *NPRECONVERTSTRING, *LPRECONVERTSTRING;

typedef struct tagIMEMENUITEMINFOA {
    UINT        cbSize;
    UINT        fType;
    UINT        fState;
    UINT        wID;
    HBITMAP     hbmpChecked;
    HBITMAP     hbmpUnchecked;
    DWORD       dwItemData;
    CHAR        szString[80];
    HBITMAP     hbmpItem;
} IMEMENUITEMINFOA, *PIMEMENUITEMINFOA, *NPIMEMENUITEMINFOA, *LPIMEMENUITEMINFOA;

typedef struct tagIMEMENUITEMINFOW {
    UINT        cbSize;
    UINT        fType;
    UINT        fState;
    UINT        wID;
    HBITMAP     hbmpChecked;
    HBITMAP     hbmpUnchecked;
    DWORD       dwItemData;
    WCHAR       szString[80];
    HBITMAP     hbmpItem;
} IMEMENUITEMINFOW, *PIMEMENUITEMINFOW, *NPIMEMENUITEMINFOW, *LPIMEMENUITEMINFOW;

typedef struct tagIMECHARPOSITION {
    DWORD       dwSize;
    DWORD       dwCharPos;
    POINT       pt;
    UINT        cLineHeight;
    RECT        rcDocument;
} IMECHARPOSITION, *PIMECHARPOSITION, *NPIMECHARPOSITION, *LPIMECHARPOSITION;

typedef struct _tagCOMPOSITIONFORM {
    DWORD   dwStyle;
    POINT ptCurrentPos;
    RECT  rcArea;
} COMPOSITIONFORM, *PCOMPOSITIONFORM, *NPCOMPOSITIONFORM, *LPCOMPOSITIONFORM;

typedef BOOL (__stdcall *IMCENUMPROC)(HIMC hIMC, LPARAM lParam);

typedef struct _tagIMEINFO {
    DWORD dwPrivateDataSize;
    DWORD fdwProperty;
    DWORD fdwConversionCaps;
    DWORD fdwSentenceCaps;
    DWORD fdwUICaps;
    DWORD fdwSCSCaps;
    DWORD fdwSelectCaps;
} IMEINFO, *PIMEINFO, *NPIMEINFO, *LPIMEINFO;

typedef struct tagCANDIDATEINFO {
    DWORD dwSize;
    DWORD dwCount;
    DWORD dwOffset[32];
    DWORD dwPrivateSize;
    DWORD dwPrivateOffset;
} CANDIDATEINFO, *PCANDIDATEINFO, *NPCANDIDATEINFO, *LPCANDIDATEINFO;

typedef struct tagSOFTKBDDATA {
    UINT uCount;
    WORD wCode[1][256];
} SOFTKBDDATA, *PSOFTKBDDATA, *NPSOFTKBDDATA, *LPSOFTKBDDATA;

typedef struct tagCOMPOSITIONSTRING {
    DWORD dwSize;
    DWORD dwCompReadAttrLen;
    DWORD dwCompReadAttrOffset;
    DWORD dwCompReadClauseLen;
    DWORD dwCompReadClauseOffset;
    DWORD dwCompReadStrLen;
    DWORD dwCompReadStrOffset;
    DWORD dwCompAttrLen;
    DWORD dwCompAttrOffset;
    DWORD dwCompClauseLen;
    DWORD dwCompClauseOffset;
    DWORD dwCompStrLen;
    DWORD dwCompStrOffset;
    DWORD dwCursorPos;
    DWORD dwDeltaStart;
    DWORD dwResultReadClauseLen;
    DWORD dwResultReadClauseOffset;
    DWORD dwResultReadStrLen;
    DWORD dwResultReadStrOffset;
    DWORD dwResultClauseLen;
    DWORD dwResultClauseOffset;
    DWORD dwResultStrLen;
    DWORD dwResultStrOffset;
    DWORD dwPrivateSize;
    DWORD dwPrivateOffset;
} COMPOSITIONSTRING, *PCOMPOSITIONSTRING, *NPCOMPOSITIONSTRING, *LPCOMPOSITIONSTRING;

typedef struct tagGUIDELINE {
    DWORD dwSize;
    DWORD dwLevel;
    DWORD dwIndex;
    DWORD dwStrLen;
    DWORD dwStrOffset;
    DWORD dwPrivateSize;
    DWORD dwPrivateOffset;
} GUIDELINE, *PGUIDELINE, *NPGUIDELINE, *LPGUIDELINE;

typedef struct _tagINPUTCONTEXT {
    HWND                hWnd;
    BOOL                fOpen;
    POINT               ptStatusWndPos;
    POINT               ptSoftKbdPos;
    DWORD               fdwConversion;
    DWORD               fdwSentence;
    union {
        LOGFONTA        A;
        LOGFONTW        W;
    } lfFont;
    COMPOSITIONFORM     cfCompForm;
    CANDIDATEFORM       cfCandForm[4];
    HIMCC               hCompStr;
    HIMCC               hCandInfo;
    HIMCC               hGuideLine;
    HIMCC               hPrivate;
    DWORD               dwNumMsgBuf;
    HIMCC               hMsgBuf;
    DWORD               fdwInit;
    DWORD               dwReserve[3];
} INPUTCONTEXT, *PINPUTCONTEXT, *NPINPUTCONTEXT, *LPINPUTCONTEXT;

typedef struct _tagTRANSMSG {
    UINT message;
    WPARAM wParam;
    LPARAM lParam;
} TRANSMSG, *PTRANSMSG, *NPTRANSMSG, *LPTRANSMSG;

typedef struct _tagTRANSMSGLIST {
    UINT     uMsgCount;
    TRANSMSG TransMsg[ANYSIZE_ARRAY];
} TRANSMSGLIST, *PTRANSMSGLIST, *NPTRANSMSGLIST, *LPTRANSMSGLIST;

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
        INT fSysWow64Only:1;
        INT fCUASLayer:1;
    };
} IMEINFOEX, *PIMEINFOEX, *NPIMEINFOEX, *LPIMEINFOEX;

typedef enum IMEINFOEXCLASS
{
    ImeInfoExKeyboardLayout,
    ImeInfoExKeyboardLayoutTFS,
    ImeInfoExImeWindow,
    ImeInfoExImeFileName
} IMEINFOEXCLASS;

typedef struct IMEDPI
{
    struct IMEDPI *pNext;
    HINSTANCE      hInst;
    HKL            hKL;
    IMEINFO        ImeInfo;
    UINT           uCodePage;
    WCHAR          szUIClass[16];
    DWORD          cLockObj;
    DWORD          dwFlags;
    LPVOID ImeInquire;
    LPVOID ImeConversionList;
    LPVOID ImeRegisterWord;
    LPVOID ImeUnregisterWord;
    LPVOID ImeGetRegisterWordStyle;
    LPVOID ImeEnumRegisterWord;
    LPVOID ImeConfigure;
    LPVOID ImeDestroy;
    LPVOID ImeEscape;
    LPVOID ImeProcessKey;
    LPVOID ImeSelect;
    LPVOID ImeSetActiveContext;
    LPVOID ImeToAsciiEx;
    LPVOID NotifyIME;
    LPVOID ImeSetCompositionString;
    LPVOID ImeGetImeMenuItems;
    LPVOID CtfImeInquireExW;
    LPVOID CtfImeSelectEx;
    LPVOID CtfImeEscapeEx;
    LPVOID CtfImeGetGuidAtom;
    LPVOID CtfImeIsGuidMapEnable;
} IMEDPI, *PIMEDPI, *NPIMEDPI, *LPIMEDPI;

typedef struct tagCLIENTIMC
{
    HANDLE hInputContext;
    LONG cLockObj;
    DWORD dwFlags;
    DWORD dwCompatFlags;
    RTL_CRITICAL_SECTION cs;
    UINT uCodePage;
    HKL hKL;
    BOOL bCtfIme;
} CLIENTIMC, *PCLIENTIMC, *NPCLIENTIMC, *LPCLIENTIMC;

typedef struct INPUTCONTEXTDX : INPUTCONTEXT
{
    UINT nVKey;
    BOOL bNeedsTrans;
    DWORD dwUnknown1;
    DWORD dwUIFlags;
    DWORD dwUnknown2;
    struct IME_STATE *pState;
    DWORD dwChange;
    HIMCC hCtfImeContext;
} INPUTCONTEXTDX, *PINPUTCONTEXTDX, *NPINPUTCONTEXTDX, *LPINPUTCONTEXTDX;

typedef struct IME_SUBSTATE
{
    struct IME_SUBSTATE *pNext;
    HKL hKL;
    DWORD dwValue;
} IME_SUBSTATE, *PIME_SUBSTATE, *NPIME_SUBSTATE, *PIME_SUBSTATE;

typedef struct IME_STATE
{
    struct IME_STATE *pNext;
    WORD wLang;
    WORD fOpen;
    DWORD dwConversion;
    DWORD dwSentence;
    DWORD dwInit;
    PIME_SUBSTATE pSubState;
} IME_STATE, *PIME_STATE, *NPIME_STATE, *LPIME_STATE;

typedef struct tagUNDETERMINESTRUCT
{
    DWORD dwSize;
    UINT  uDefIMESize;
    UINT  uDefIMEPos;
    UINT  uUndetTextLen;
    UINT  uUndetTextPos;
    UINT  uUndetAttrPos;
    UINT  uCursorPos;
    UINT  uDeltaStart;
    UINT  uDetermineTextLen;
    UINT  uDetermineTextPos;
    UINT  uDetermineDelimPos;
    UINT  uYomiTextLen;
    UINT  uYomiTextPos;
    UINT  uYomiDelimPos;
} UNDETERMINESTRUCT, *PUNDETERMINESTRUCT, *LPUNDETERMINESTRUCT;

typedef struct tagIMEUI
{
    PWND spwnd;
    HIMC hIMC;
    HWND hwndIMC;
    HKL hKL;
    HWND hwndUI;
    LONG nCntInIMEProc;
    struct {
        UINT fShowStatus:1;
        UINT fActivate:1;
        UINT fDestroy:1;
        UINT fDefault:1;
        UINT fChildThreadDef:1;
        UINT fCtrlShowStatus:1;
        UINT fFreeActiveEvent:1;
    };
    DWORD dwLastStatus;
} IMEUI, *PIMEUI;

typedef struct _IMEWND
{
    WND wnd;
    PIMEUI pimeui;
} IMEWND, *PIMEWND;
