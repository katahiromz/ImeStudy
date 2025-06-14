// Type information for IDA Freeware
// <msctf.h>
// <ctfutb.h>
// <textstor.h>

struct IUnknownVtbl
{
  HRESULT (__stdcall *QueryInterface)(struct IUnknown *This, const IID *const riid, void **ppvObject);
  ULONG (__stdcall *AddRef)(struct IUnknown *This);
  ULONG (__stdcall *Release)(struct IUnknown *This);
};
struct IUnknown
{
    IUnknownVtbl *lpVtbl;
};

typedef unsigned short VARTYPE;
typedef struct tagVARIANT  {
    VARTYPE vt; 
    unsigned short wReserved1; 
    unsigned short wReserved2; 
    unsigned short wReserved3;
    LPVOID _value;
} VARIANT, *PVARIANT, *LPVARIANT;

typedef DWORD TfEditCookie;
typedef DWORD TfClientId;
typedef DWORD TfGuidAtom;

struct ITfCompartmentVtbl
{
  HRESULT (__stdcall *QueryInterface)(struct ITfCompartment *This, const IID *const riid, void **ppvObject);
  ULONG (__stdcall *AddRef)(struct ITfCompartment *This);
  ULONG (__stdcall *Release)(struct ITfCompartment *This);
  HRESULT (__stdcall *SetValue)(struct ITfCompartment *This, TfClientId tid, const VARIANT *pvarValue);
  HRESULT (__stdcall *GetValue)(struct ITfCompartment *This, VARIANT *pvarValue);
};

typedef struct ITfCompartment
{
    ITfCompartmentVtbl *lpVtbl;
} ITfCompartment;

struct IStorage;
struct IEnumSTATSTG;

typedef LPWSTR LPOLESTR;

  typedef struct tagSTATSTG {
    LPOLESTR pwcsName;
    DWORD type;
    ULARGE_INTEGER cbSize;
    FILETIME mtime;
    FILETIME ctime;
    FILETIME atime;
    DWORD grfMode;
    DWORD grfLocksSupported;
    CLSID clsid;
    DWORD grfStateBits;
    DWORD reserved;
  } STATSTG;

  typedef enum tagSTGTY {
    STGTY_STORAGE   = 1,
    STGTY_STREAM    = 2,
    STGTY_LOCKBYTES = 3,
    STGTY_PROPERTY  = 4
  } STGTY;

  typedef enum tagSTREAM_SEEK {
    STREAM_SEEK_SET = 0,
    STREAM_SEEK_CUR = 1,
    STREAM_SEEK_END = 2
  } STREAM_SEEK;

typedef WCHAR OLECHAR;
typedef OLECHAR **SNB;

struct IStorageVtbl
{
  HRESULT (__stdcall *QueryInterface)(struct IStorage *This, const IID *const riid, void **ppvObject);
  ULONG (__stdcall *AddRef)(struct IStorage *This);
  ULONG (__stdcall *Release)(struct IStorage *This);
  HRESULT (__stdcall *CreateStream)(struct IStorage *This, const OLECHAR *pwcsName, DWORD grfMode, DWORD reserved1, DWORD reserved2, IStream **ppstm);
  HRESULT (__stdcall *OpenStream)(struct IStorage *This, const OLECHAR *pwcsName, void *reserved1, DWORD grfMode, DWORD reserved2, IStream **ppstm);
  HRESULT (__stdcall *CreateStorage)(struct IStorage *This, const OLECHAR *pwcsName, DWORD grfMode, DWORD reserved1, DWORD reserved2, IStorage **ppstg);
  HRESULT (__stdcall *OpenStorage)(struct IStorage *This, const OLECHAR *pwcsName, IStorage *pstgPriority, DWORD grfMode, SNB snbExclude, DWORD reserved, IStorage **ppstg);
  HRESULT (__stdcall *CopyTo)(struct IStorage *This, DWORD ciidExclude, const IID *rgiidExclude, SNB snbExclude, IStorage *pstgDest);
  HRESULT (__stdcall *MoveElementTo)(struct IStorage *This, const OLECHAR *pwcsName, IStorage *pstgDest, const OLECHAR *pwcsNewName, DWORD grfFlags);
  HRESULT (__stdcall *Commit)(struct IStorage *This, DWORD grfCommitFlags);
  HRESULT (__stdcall *Revert)(struct IStorage *This);
  HRESULT (__stdcall *EnumElements)(struct IStorage *This, DWORD reserved1, void *reserved2, DWORD reserved3, IEnumSTATSTG **ppenum);
  HRESULT (__stdcall *DestroyElement)(struct IStorage *This, const OLECHAR *pwcsName);
  HRESULT (__stdcall *RenameElement)(struct IStorage *This, const OLECHAR *pwcsOldName, const OLECHAR *pwcsNewName);
  HRESULT (__stdcall *SetElementTimes)(struct IStorage *This, const OLECHAR *pwcsName, const FILETIME *pctime, const FILETIME *patime, const FILETIME *pmtime);
  HRESULT (__stdcall *SetClass)(struct IStorage *This, const IID *const clsid);
  HRESULT (__stdcall *SetStateBits)(struct IStorage *This, DWORD grfStateBits, DWORD grfMask);
  HRESULT (__stdcall *Stat)(struct IStorage *This, STATSTG *pstatstg, DWORD grfStatFlag);
};

typedef struct IStorage
{
    IStorageVtbl *lpVtbl;
} IStorage;

struct IEnumSTATSTGVtbl
{
  HRESULT (__stdcall *QueryInterface)(struct IEnumSTATSTG *This, const IID *const riid, void **ppvObject);
  ULONG (__stdcall *AddRef)(struct IEnumSTATSTG *This);
  ULONG (__stdcall *Release)(struct IEnumSTATSTG *This);
  HRESULT (__stdcall *Next)(struct IEnumSTATSTG *This, ULONG celt, STATSTG *rgelt, ULONG *pceltFetched);
  HRESULT (__stdcall *Skip)(struct IEnumSTATSTG *This, ULONG celt);
  HRESULT (__stdcall *Reset)(struct IEnumSTATSTG *This);
  HRESULT (__stdcall *Clone)(struct IEnumSTATSTG *This, IEnumSTATSTG **ppenum);
};

struct IEnumSTATSTG
{
    IEnumSTATSTGVtbl *lpVtbl;
};

typedef enum { TS_GR_BACKWARD = 0, TS_GR_FORWARD = 1 } TsGravity;
typedef enum { TS_SD_BACKWARD = 0, TS_SD_FORWARD = 1 } TsShiftDir;

struct IAnchorVtbl
{
  HRESULT (__stdcall *QueryInterface)(struct IAnchor *This, const IID *const riid, void **ppvObject);
  ULONG (__stdcall *AddRef)(struct IAnchor *This);
  ULONG (__stdcall *Release)(struct IAnchor *This);
  HRESULT (__stdcall *SetGravity)(struct IAnchor *This, TsGravity gravity);
  HRESULT (__stdcall *GetGravity)(struct IAnchor *This, TsGravity *pgravity);
  HRESULT (__stdcall *IsEqual)(struct IAnchor *This, struct IAnchor *paWith, BOOL *pfEqual);
  HRESULT (__stdcall *Compare)(struct IAnchor *This, struct IAnchor *paWith, LONG *plResult);
  HRESULT (__stdcall *Shift)(struct IAnchor *This, DWORD dwFlags, LONG cchReq, LONG *pcch, struct IAnchor *paHaltAnchor);
  HRESULT (__stdcall *ShiftTo)(struct IAnchor *This, struct IAnchor *paSite);
  HRESULT (__stdcall *ShiftRegion)(struct IAnchor *This, DWORD dwFlags, TsShiftDir dir, BOOL *pfNoRegion);
  HRESULT (__stdcall *SetChangeHistoryMask)(struct IAnchor *This, DWORD dwMask);
  HRESULT (__stdcall *GetChangeHistory)(struct IAnchor *This, DWORD *pdwHistory);
  HRESULT (__stdcall *ClearChangeHistory)(struct IAnchor *This);
  HRESULT (__stdcall *Clone)(struct IAnchor *This, struct IAnchor **ppaClone);
};

struct IAnchor
{
    IAnchorVtbl *lpVtbl;
};

struct ITfDocumentMgr;
struct ITfFunctionProvider;

struct ITfThreadMgr_PVtbl
{
  HRESULT (__stdcall *QueryInterface)(struct ITfThreadMgr_P *This, struct IID *riid, LPVOID *ppvObj);
  ULONG (__stdcall *AddRef)(struct ITfThreadMgr_P *This);
  ULONG (__stdcall *Release)(struct ITfThreadMgr_P *This);
  HRESULT (__stdcall *Activate)(struct ITfThreadMgr_P *This, TfClientId *ptid);
  HRESULT (__stdcall *Deactivate)(struct ITfThreadMgr_P *This);
  HRESULT (__stdcall *CreateDocumentMgr)(struct ITfThreadMgr_P *This, struct ITfDocumentMgr **ppdim);
  HRESULT (__stdcall *EnumDocumentMgrs)(struct ITfThreadMgr_P *This, struct IEnumTfDocumentMgrs **ppEnum);
  HRESULT (__stdcall *GetFocus)(struct ITfThreadMgr_P *This, struct ITfDocumentMgr **ppdimFocus);
  HRESULT (__stdcall *SetFocus)(struct ITfThreadMgr_P *This, struct ITfDocumentMgr *pdimFocus);
  HRESULT (__stdcall *AssociateFocus)(struct ITfThreadMgr_P *This, HWND hwnd, ITfDocumentMgr *pdimNew, ITfDocumentMgr **ppdimPrev);
  HRESULT (__stdcall *IsThreadFocus)(struct ITfThreadMgr_P *This, BOOL *pfThreadFocus);
  HRESULT (__stdcall *GetFunctionProvider)(struct ITfThreadMgr_P *This, const CLSID *clsid, struct ITfFunctionProvider **ppFuncProv);
  HRESULT (__stdcall *EnumFunctionProviders)(struct ITfThreadMgr_P *This, struct IEnumTfFunctionProviders **ppEnum);
  HRESULT (__stdcall *GetGlobalCompartment)(struct ITfThreadMgr_P *This, struct ITfCompartmentMgr **ppCompMgr);
  HRESULT (__stdcall *GetAssociated)(struct ITfThreadMgr_P *This, HWND, ITfDocumentMgr **);
  HRESULT (__stdcall *SetSysHookSink)(struct ITfThreadMgr_P *This, struct ITfSysHookSink *);
  HRESULT (__stdcall *RequestPostponedLock)(struct ITfThreadMgr_P *This, struct ITfContext *);
  HRESULT (__stdcall *IsKeystrokeFeedEnabled)(struct ITfThreadMgr_P *This, int *);
  HRESULT (__stdcall *CallImm32HotkeyHanlder)(struct ITfThreadMgr_P *This, UINT, LONG, int *);
  HRESULT (__stdcall *ActivateEx)(struct ITfThreadMgr_P *This, LPDWORD, DWORD);
};

typedef struct ITfThreadMgr_P
{
    ITfThreadMgr_PVtbl *lpVtbl;
} ITfThreadMgr_P;

struct IEnumTfDocumentMgrs;
struct IEnumTfFunctionProviders;
struct ITfCompartmentMgr;

struct ITfThreadMgrVtbl
{
  HRESULT (__stdcall *QueryInterface)(struct ITfThreadMgr *This, IID *riid, LPVOID *ppvObj);
  ULONG (__stdcall *AddRef)(struct ITfThreadMgr *This);
  ULONG (__stdcall *Release)(struct ITfThreadMgr *This);
  HRESULT (__stdcall *Activate)(struct ITfThreadMgr *This, TfClientId *ptid);
  HRESULT (__stdcall *Deactivate)(struct ITfThreadMgr *This);
  HRESULT (__stdcall *CreateDocumentMgr)(struct ITfThreadMgr *This, ITfDocumentMgr **ppdim);
  HRESULT (__stdcall *EnumDocumentMgrs)(struct ITfThreadMgr *This, IEnumTfDocumentMgrs **ppEnum);
  HRESULT (__stdcall *GetFocus)(struct ITfThreadMgr *This, ITfDocumentMgr **ppdimFocus);
  HRESULT (__stdcall *SetFocus)(struct ITfThreadMgr *This, ITfDocumentMgr *pdimFocus);
  HRESULT (__stdcall *AssociateFocus)(struct ITfThreadMgr *This, HWND hwnd, ITfDocumentMgr *pdimNew, ITfDocumentMgr **ppdimPrev);
  HRESULT (__stdcall *IsThreadFocus)(struct ITfThreadMgr *This, BOOL *pfThreadFocus);
  HRESULT (__stdcall *GetFunctionProvider)(struct ITfThreadMgr *This, const CLSID *clsid, ITfFunctionProvider **ppFuncProv);
  HRESULT (__stdcall *EnumFunctionProviders)(struct ITfThreadMgr *This, struct IEnumTfFunctionProviders **ppEnum);
  HRESULT (__stdcall *GetGlobalCompartment)(struct ITfThreadMgr *This, struct ITfCompartmentMgr **ppCompMgr);
};

struct ITfThreadMgr
{
    struct ITfThreadMgrVtbl *lpVtbl;
};

struct ITfContext;

typedef struct TF_PERSISTENT_PROPERTY_HEADER_ACP
{
    GUID guidType;
    LONG ichStart;
    LONG cch;
    ULONG cb;
    DWORD dwPrivate;
    CLSID clsidTIP;
} TF_PERSISTENT_PROPERTY_HEADER_ACP;

typedef struct TF_LANGUAGEPROFILE
{
    CLSID clsid;
    LANGID langid;
    GUID catid;
    BOOL fActive;
    GUID guidProfile;
} TF_LANGUAGEPROFILE;

typedef struct TF_PRESERVEDKEY
{
    UINT uVKey;
    UINT uModifiers;
} TF_PRESERVEDKEY;

struct ITfKeyEventSink;
typedef LPWSTR BSTR;

struct ITfKeystrokeMgrVtbl
{
  HRESULT (__stdcall *QueryInterface)(struct ITfKeystrokeMgr *This, const IID *const riid, void **ppvObject);
  ULONG (__stdcall *AddRef)(struct ITfKeystrokeMgr *This);
  ULONG (__stdcall *Release)(struct ITfKeystrokeMgr *This);
  HRESULT (__stdcall *AdviseKeyEventSink)(struct ITfKeystrokeMgr *This, TfClientId tid, struct ITfKeyEventSink *pSink, BOOL fForeground);
  HRESULT (__stdcall *UnadviseKeyEventSink)(struct ITfKeystrokeMgr *This, TfClientId tid);
  HRESULT (__stdcall *GetForeground)(struct ITfKeystrokeMgr *This, CLSID *pclsid);
  HRESULT (__stdcall *TestKeyDown)(struct ITfKeystrokeMgr *This, WPARAM wParam, LPARAM lParam, BOOL *pfEaten);
  HRESULT (__stdcall *TestKeyUp)(struct ITfKeystrokeMgr *This, WPARAM wParam, LPARAM lParam, BOOL *pfEaten);
  HRESULT (__stdcall *KeyDown)(struct ITfKeystrokeMgr *This, WPARAM wParam, LPARAM lParam, BOOL *pfEaten);
  HRESULT (__stdcall *KeyUp)(struct ITfKeystrokeMgr *This, WPARAM wParam, LPARAM lParam, BOOL *pfEaten);
  HRESULT (__stdcall *GetPreservedKey)(struct ITfKeystrokeMgr *This, struct ITfContext *pic, const TF_PRESERVEDKEY *pprekey, GUID *pguid);
  HRESULT (__stdcall *IsPreservedKey)(struct ITfKeystrokeMgr *This, const GUID *const rguid, const TF_PRESERVEDKEY *pprekey, BOOL *pfRegistered);
  HRESULT (__stdcall *PreserveKey)(struct ITfKeystrokeMgr *This, TfClientId tid, const GUID *const rguid, const TF_PRESERVEDKEY *prekey, const WCHAR *pchDesc, ULONG cchDesc);
  HRESULT (__stdcall *UnpreserveKey)(struct ITfKeystrokeMgr *This, const GUID *const rguid, const TF_PRESERVEDKEY *pprekey);
  HRESULT (__stdcall *SetPreservedKeyDescription)(struct ITfKeystrokeMgr *This, const GUID *const rguid, const WCHAR *pchDesc, ULONG cchDesc);
  HRESULT (__stdcall *GetPreservedKeyDescription)(struct ITfKeystrokeMgr *This, const GUID *const rguid, BSTR *pbstrDesc);
  HRESULT (__stdcall *SimulatePreservedKey)(struct ITfKeystrokeMgr *This, struct ITfContext *pic, const GUID *const rguid, BOOL *pfEaten);
};

struct ITfKeystrokeMgr
{
    ITfKeystrokeMgrVtbl *lpVtbl;
};

struct ITfKeyEventSinkVtbl
{
  HRESULT (__stdcall *QueryInterface)(struct ITfKeyEventSink *This, const IID *const riid, void **ppvObject);
  ULONG (__stdcall *AddRef)(struct ITfKeyEventSink *This);
  ULONG (__stdcall *Release)(struct ITfKeyEventSink *This);
  HRESULT (__stdcall *OnSetFocus)(struct ITfKeyEventSink *This, BOOL fForeground);
  HRESULT (__stdcall *OnTestKeyDown)(struct ITfKeyEventSink *This, ITfContext *pic, WPARAM wParam, LPARAM lParam, BOOL *pfEaten);
  HRESULT (__stdcall *OnTestKeyUp)(struct ITfKeyEventSink *This, ITfContext *pic, WPARAM wParam, LPARAM lParam, BOOL *pfEaten);
  HRESULT (__stdcall *OnKeyDown)(struct ITfKeyEventSink *This, ITfContext *pic, WPARAM wParam, LPARAM lParam, BOOL *pfEaten);
  HRESULT (__stdcall *OnKeyUp)(struct ITfKeyEventSink *This, ITfContext *pic, WPARAM wParam, LPARAM lParam, BOOL *pfEaten);
  HRESULT (__stdcall *OnPreservedKey)(struct ITfKeyEventSink *This, ITfContext *pic, const GUID *const rguid, BOOL *pfEaten);
};

struct ITfKeyEventSink
{
    ITfKeyEventSinkVtbl *lpVtbl;
};

struct ITfReadOnlyProperty;
struct IEnumTfProperties;

typedef enum { TS_AE_NONE, TS_AE_START, TS_AE_END } TsActiveSelEnd;
typedef enum { TS_RT_PLAIN, TS_RT_HIDDEN, TS_RT_OPAQUE } TsRunType;
typedef GUID TS_ATTRID;

typedef struct TS_STATUS
{
    DWORD dwDynamicFlags;
    DWORD dwStaticFlags;
} TS_STATUS;

typedef TS_STATUS TF_STATUS;

struct ITfProperty;
struct ITfRange;
struct ITfRangeBackup;
struct ITfContextView;
struct IEnumTfContextViews;

typedef enum { TF_AE_NONE, TF_AE_START, TF_AE_END } TfActiveSelEnd;

typedef struct TF_SELECTIONSTYLE
{
    TfActiveSelEnd ase;
    BOOL fInterimChar;
} TF_SELECTIONSTYLE;

typedef struct TF_SELECTION
{
    struct ITfRange *range;
    TF_SELECTIONSTYLE style;
} TF_SELECTION;

struct ITfEditSession;

struct ITfContextVtbl
{
  HRESULT (__stdcall *QueryInterface)(struct ITfContext *This, const IID *const riid, void **ppvObject);
  ULONG (__stdcall *AddRef)(struct ITfContext *This);
  ULONG (__stdcall *Release)(struct ITfContext *This);
  HRESULT (__stdcall *RequestEditSession)(struct ITfContext *This, TfClientId tid, struct ITfEditSession *pes, DWORD dwFlags, HRESULT *phrSession);
  HRESULT (__stdcall *InWriteSession)(struct ITfContext *This, TfClientId tid, BOOL *pfWriteSession);
  HRESULT (__stdcall *GetSelection)(struct ITfContext *This, TfEditCookie ec, ULONG ulIndex, ULONG ulCount, TF_SELECTION *pSelection, ULONG *pcFetched);
  HRESULT (__stdcall *SetSelection)(struct ITfContext *This, TfEditCookie ec, ULONG ulCount, const TF_SELECTION *pSelection);
  HRESULT (__stdcall *GetStart)(struct ITfContext *This, TfEditCookie ec, struct ITfRange **ppStart);
  HRESULT (__stdcall *GetEnd)(struct ITfContext *This, TfEditCookie ec, struct ITfRange **ppEnd);
  HRESULT (__stdcall *GetActiveView)(struct ITfContext *This, struct ITfContextView **ppView);
  HRESULT (__stdcall *EnumViews)(struct ITfContext *This, struct IEnumTfContextViews **ppEnum);
  HRESULT (__stdcall *GetStatus)(struct ITfContext *This, TF_STATUS *pdcs);
  HRESULT (__stdcall *GetProperty)(struct ITfContext *This, const GUID *const guidProp, struct ITfProperty **ppProp);
  HRESULT (__stdcall *GetAppProperty)(struct ITfContext *This, const GUID *const guidProp, ITfReadOnlyProperty **ppProp);
  HRESULT (__stdcall *TrackProperties)(struct ITfContext *This, const GUID **prgProp, ULONG cProp, const GUID **prgAppProp, ULONG cAppProp, struct ITfReadOnlyProperty **ppProperty);
  HRESULT (__stdcall *EnumProperties)(struct ITfContext *This, struct IEnumTfProperties **ppEnum);
  HRESULT (__stdcall *GetDocumentMgr)(struct ITfContext *This, ITfDocumentMgr **ppDm);
  HRESULT (__stdcall *CreateRangeBackup)(struct ITfContext *This, TfEditCookie ec, struct ITfRange *pRange, struct ITfRangeBackup **ppBackup);
};

struct ITfContext
{
    ITfContextVtbl *lpVtbl;
};

struct ITfEditSessionVtbl
{
  HRESULT (__stdcall *QueryInterface)(struct ITfEditSession *This, const IID *const riid, void **ppvObject);
  ULONG (__stdcall *AddRef)(struct ITfEditSession *This);
  ULONG (__stdcall *Release)(struct ITfEditSession *This);
  HRESULT (__stdcall *DoEditSession)(struct ITfEditSession *This, TfEditCookie ec);
};

struct ITfEditSession
{
    ITfEditSessionVtbl *lpVtbl;
};

typedef struct TF_PERSISTENT_PROPERTY_HEADER_ACP
{
    GUID guidType;
    LONG ichStart;
    LONG cch;
    ULONG cb;
    DWORD dwPrivate;
    CLSID clsidTIP;
} TF_PERSISTENT_PROPERTY_HEADER_ACP;

typedef struct TF_LANGUAGEPROFILE
{
    CLSID clsid;
    LANGID langid;
    GUID catid;
    BOOL fActive;
    GUID guidProfile;
} TF_LANGUAGEPROFILE;

typedef struct TF_PRESERVEDKEY
{
    UINT uVKey;
    UINT uModifiers;
} TF_PRESERVEDKEY;


typedef enum { TF_ANCHOR_START = 0, TF_ANCHOR_END = 1 } TfAnchor;

typedef enum { TF_GRAVITY_BACKWARD = 0, TF_GRAVITY_FORWARD = 1 } TfGravity;

typedef enum { TF_SD_BACKWARD = 0, TF_SD_FORWARD = 1 } TfShiftDir;

typedef struct  TF_HALTCOND
{
    ITfRange *pHaltRange;
    TfAnchor aHaltPos;
    DWORD dwFlags;
} TF_HALTCOND;

struct ITfRangeVtbl
{
  HRESULT (__stdcall *QueryInterface)(struct ITfRange *This, const IID *const riid, void **ppvObject);
  ULONG (__stdcall *AddRef)(struct ITfRange *This);
  ULONG (__stdcall *Release)(struct ITfRange *This);
  HRESULT (__stdcall *GetText)(struct ITfRange *This, TfEditCookie ec, DWORD dwFlags, WCHAR *pchText, ULONG cchMax, ULONG *pcch);
  HRESULT (__stdcall *SetText)(struct ITfRange *This, TfEditCookie ec, DWORD dwFlags, const WCHAR *pchText, LONG cch);
  HRESULT (__stdcall *GetFormattedText)(struct ITfRange *This, TfEditCookie ec, struct IDataObject **ppDataObject);
  HRESULT (__stdcall *GetEmbedded)(struct ITfRange *This, TfEditCookie ec, const GUID *const rguidService, const IID *const riid, struct IUnknown **ppunk);
  HRESULT (__stdcall *InsertEmbedded)(struct ITfRange *This, TfEditCookie ec, DWORD dwFlags, struct IDataObject *pDataObject);
  HRESULT (__stdcall *ShiftStart)(struct ITfRange *This, TfEditCookie ec, LONG cchReq, LONG *pcch, const TF_HALTCOND *pHalt);
  HRESULT (__stdcall *ShiftEnd)(struct ITfRange *This, TfEditCookie ec, LONG cchReq, LONG *pcch, const TF_HALTCOND *pHalt);
  HRESULT (__stdcall *ShiftStartToRange)(struct ITfRange *This, TfEditCookie ec, struct ITfRange *pRange, TfAnchor aPos);
  HRESULT (__stdcall *ShiftEndToRange)(struct ITfRange *This, TfEditCookie ec, struct ITfRange *pRange, TfAnchor aPos);
  HRESULT (__stdcall *ShiftStartRegion)(struct ITfRange *This, TfEditCookie ec, TfShiftDir dir, BOOL *pfNoRegion);
  HRESULT (__stdcall *ShiftEndRegion)(struct ITfRange *This, TfEditCookie ec, TfShiftDir dir, BOOL *pfNoRegion);
  HRESULT (__stdcall *IsEmpty)(struct ITfRange *This, TfEditCookie ec, BOOL *pfEmpty);
  HRESULT (__stdcall *Collapse)(struct ITfRange *This, TfEditCookie ec, TfAnchor aPos);
  HRESULT (__stdcall *IsEqualStart)(struct ITfRange *This, TfEditCookie ec, struct ITfRange *pWith, TfAnchor aPos, BOOL *pfEqual);
  HRESULT (__stdcall *IsEqualEnd)(struct ITfRange *This, TfEditCookie ec, struct ITfRange *pWith, TfAnchor aPos, BOOL *pfEqual);
  HRESULT (__stdcall *CompareStart)(struct ITfRange *This, TfEditCookie ec, struct ITfRange *pWith, TfAnchor aPos, LONG *plResult);
  HRESULT (__stdcall *CompareEnd)(struct ITfRange *This, TfEditCookie ec, struct ITfRange *pWith, TfAnchor aPos, LONG *plResult);
  HRESULT (__stdcall *AdjustForInsert)(struct ITfRange *This, TfEditCookie ec, ULONG cchInsert, BOOL *pfInsertOk);
  HRESULT (__stdcall *GetGravity)(struct ITfRange *This, TfGravity *pgStart, TfGravity *pgEnd);
  HRESULT (__stdcall *SetGravity)(struct ITfRange *This, TfEditCookie ec, TfGravity gStart, TfGravity gEnd);
  HRESULT (__stdcall *Clone)(struct ITfRange *This, ITfRange **ppClone);
  HRESULT (__stdcall *GetContext)(struct ITfRange *This, ITfContext **ppContext);
};

struct ITfRange
{
    ITfRangeVtbl *lpVtbl;
};

typedef WORD CLIPFORMAT;

typedef struct tagFORMATETC 
{
    CLIPFORMAT  cfFormat;
    void *ptd;
    DWORD  dwAspect;
    LONG  lindex;
    DWORD  tymed;
} FORMATETC, *LPFORMATETC;

  typedef struct tagSTGMEDIUM {
    DWORD tymed;
    HANDLE _value;
    IUnknown *pUnkForRelease;
  } STGMEDIUM;

struct IEnumSTATDATA;
struct IAdviseSink;

struct IDataObjectVtbl
{
  HRESULT (__stdcall *QueryInterface)(struct IDataObject *This, const IID *const riid, void **ppvObject);
  ULONG (__stdcall *AddRef)(struct IDataObject *This);
  ULONG (__stdcall *Release)(struct IDataObject *This);
  HRESULT (__stdcall *GetData)(struct IDataObject *This, FORMATETC *pformatetcIn, STGMEDIUM *pmedium);
  HRESULT (__stdcall *GetDataHere)(struct IDataObject *This, FORMATETC *pformatetc, STGMEDIUM *pmedium);
  HRESULT (__stdcall *QueryGetData)(struct IDataObject *This, FORMATETC *pformatetc);
  HRESULT (__stdcall *GetCanonicalFormatEtc)(struct IDataObject *This, FORMATETC *pformatectIn, FORMATETC *pformatetcOut);
  HRESULT (__stdcall *SetData)(struct IDataObject *This, FORMATETC *pformatetc, STGMEDIUM *pmedium, BOOL fRelease);
  HRESULT (__stdcall *EnumFormatEtc)(struct IDataObject *This, DWORD dwDirection, struct IEnumFORMATETC **ppenumFormatEtc);
  HRESULT (__stdcall *DAdvise)(struct IDataObject *This, FORMATETC *pformatetc, DWORD advf, struct IAdviseSink *pAdvSink, DWORD *pdwConnection);
  HRESULT (__stdcall *DUnadvise)(struct IDataObject *This, DWORD dwConnection);
  HRESULT (__stdcall *EnumDAdvise)(struct IDataObject *This, struct IEnumSTATDATA **ppenumAdvise);
};

struct IDataObject
{
    IDataObjectVtbl *lpVtbl;
};

struct IEnumFORMATETCVtbl
{
  HRESULT (__stdcall *QueryInterface)(struct IEnumFORMATETC *This, const IID *const riid, void **ppvObject);
  ULONG (__stdcall *AddRef)(struct IEnumFORMATETC *This);
  ULONG (__stdcall *Release)(struct IEnumFORMATETC *This);
  HRESULT (__stdcall *Next)(struct IEnumFORMATETC *This, ULONG celt, FORMATETC *rgelt, ULONG *pceltFetched);
  HRESULT (__stdcall *Skip)(struct IEnumFORMATETC *This, ULONG celt);
  HRESULT (__stdcall *Reset)(struct IEnumFORMATETC *This);
  HRESULT (__stdcall *Clone)(struct IEnumFORMATETC *This, struct IEnumFORMATETC **ppenum);
};

struct IEnumFORMATETC
{
    IEnumFORMATETCVtbl *lpVtbl;
};

struct IAdviseSinkVtbl
{
  HRESULT (__stdcall *QueryInterface)(struct IAdviseSink *This, const IID *const riid, void **ppvObject);
  ULONG (__stdcall *AddRef)(struct IAdviseSink *This);
  ULONG (__stdcall *Release)(struct IAdviseSink *This);
  void (__stdcall *OnDataChange)(struct IAdviseSink *This, FORMATETC *pFormatetc, STGMEDIUM *pStgmed);
  void (__stdcall *OnViewChange)(struct IAdviseSink *This, DWORD dwAspect, LONG lindex);
  void (__stdcall *OnRename)(struct IAdviseSink *This, struct IMoniker *pmk);
  void (__stdcall *OnSave)(struct IAdviseSink *This);
  void (__stdcall *OnClose)(struct IAdviseSink *This);
};

struct IAdviseSink
{
    IAdviseSinkVtbl *lpVtbl;
};

struct ITfContextViewVtbl
{
  HRESULT (__stdcall *QueryInterface)(struct ITfContextView *This, const IID *const riid, void **ppvObject);
  ULONG (__stdcall *AddRef)(struct ITfContextView *This);
  ULONG (__stdcall *Release)(struct ITfContextView *This);
  HRESULT (__stdcall *GetRangeFromPoint)(struct ITfContextView *This, TfEditCookie ec, const POINT *ppt, DWORD dwFlags, ITfRange **ppRange);
  HRESULT (__stdcall *GetTextExt)(struct ITfContextView *This, TfEditCookie ec, ITfRange *pRange, RECT *prc, BOOL *pfClipped);
  HRESULT (__stdcall *GetScreenExt)(struct ITfContextView *This, RECT *prc);
  HRESULT (__stdcall *GetWnd)(struct ITfContextView *This, HWND *phwnd);
};

struct ITfContextView
{
    ITfContextViewVtbl *lpVtbl;
};

struct IEnumTfContextViewsVtbl
{
  HRESULT (__stdcall *QueryInterface)(struct IEnumTfContextViews *This, const IID *const riid, void **ppvObject);
  ULONG (__stdcall *AddRef)(struct IEnumTfContextViews *This);
  ULONG (__stdcall *Release)(struct IEnumTfContextViews *This);
  HRESULT (__stdcall *Clone)(struct IEnumTfContextViews *This, IEnumTfContextViews **ppEnum);
  HRESULT (__stdcall *Next)(struct IEnumTfContextViews *This, ULONG ulCount, ITfContextView **rgViews, ULONG *pcFetched);
  HRESULT (__stdcall *Reset)(struct IEnumTfContextViews *This);
  HRESULT (__stdcall *Skip)(struct IEnumTfContextViews *This, ULONG ulCount);
};

struct IEnumTfContextViews
{
    IEnumTfContextViewsVtbl *lpVtbl;
};

struct ITfPropertyVtbl
{
  HRESULT (__stdcall *QueryInterface)(struct ITfProperty *This, const IID *const riid, void **ppvObject);
  ULONG (__stdcall *AddRef)(struct ITfProperty *This);
  ULONG (__stdcall *Release)(struct ITfProperty *This);
  HRESULT (__stdcall *GetType)(struct ITfProperty *This, GUID *pguid);
  HRESULT (__stdcall *EnumRanges)(struct ITfProperty *This, TfEditCookie ec, struct IEnumTfRanges **ppEnum, struct ITfRange *pTargetRange);
  HRESULT (__stdcall *GetValue)(struct ITfProperty *This, TfEditCookie ec, struct ITfRange *pRange, VARIANT *pvarValue);
  HRESULT (__stdcall *GetContext)(struct ITfProperty *This, ITfContext **ppContext);
  HRESULT (__stdcall *FindRange)(struct ITfProperty *This, TfEditCookie ec, struct ITfRange *pRange, struct ITfRange **ppRange, TfAnchor aPos);
  HRESULT (__stdcall *SetValueStore)(struct ITfProperty *This, TfEditCookie ec, ITfRange *pRange, struct ITfPropertyStore *pPropStore);
  HRESULT (__stdcall *SetValue)(struct ITfProperty *This, TfEditCookie ec, struct ITfRange *pRange, const VARIANT *pvarValue);
  HRESULT (__stdcall *Clear)(struct ITfProperty *This, TfEditCookie ec, struct ITfRange *pRange);
};

struct ITfProperty
{
    ITfPropertyVtbl *lpVtbl;
};

struct IEnumTfRangesVtbl
{
  HRESULT (__stdcall *QueryInterface)(struct IEnumTfRanges *This, const IID *const riid, void **ppvObject);
  ULONG (__stdcall *AddRef)(struct IEnumTfRanges *This);
  ULONG (__stdcall *Release)(struct IEnumTfRanges *This);
  HRESULT (__stdcall *Clone)(struct IEnumTfRanges *This, struct IEnumTfRanges **ppEnum);
  HRESULT (__stdcall *Next)(struct IEnumTfRanges *This, ULONG ulCount, struct ITfRange **ppRange, ULONG *pcFetched);
  HRESULT (__stdcall *Reset)(struct IEnumTfRanges *This);
  HRESULT (__stdcall *Skip)(struct IEnumTfRanges *This, ULONG ulCount);
};

struct IEnumTfRanges
{
    IEnumTfRangesVtbl *lpVtbl;
};

struct ITfPropertyStoreVtbl
{
  HRESULT (__stdcall *QueryInterface)(struct ITfPropertyStore *This, const IID *const riid, void **ppvObject);
  ULONG (__stdcall *AddRef)(struct ITfPropertyStore *This);
  ULONG (__stdcall *Release)(struct ITfPropertyStore *This);
  HRESULT (__stdcall *GetType)(struct ITfPropertyStore *This, GUID *pguid);
  HRESULT (__stdcall *GetDataType)(struct ITfPropertyStore *This, DWORD *pdwReserved);
  HRESULT (__stdcall *GetData)(struct ITfPropertyStore *This, VARIANT *pvarValue);
  HRESULT (__stdcall *OnTextUpdated)(struct ITfPropertyStore *This, DWORD dwFlags, ITfRange *pRangeNew, BOOL *pfAccept);
  HRESULT (__stdcall *Shrink)(struct ITfPropertyStore *This, ITfRange *pRangeNew, BOOL *pfFree);
  HRESULT (__stdcall *Divide)(struct ITfPropertyStore *This, ITfRange *pRangeThis, ITfRange *pRangeNew, struct ITfPropertyStore **ppPropStore);
  HRESULT (__stdcall *Clone)(struct ITfPropertyStore *This, struct ITfPropertyStore **pPropStore);
  HRESULT (__stdcall *GetPropertyRangeCreator)(struct ITfPropertyStore *This, CLSID *pclsid);
  HRESULT (__stdcall *Serialize)(struct ITfPropertyStore *This, IStream *pStream, ULONG *pcb);
};

struct ITfPropertyStore
{
    ITfPropertyStoreVtbl *lpVtbl;
};

struct ITfReadOnlyPropertyVtbl
{
  HRESULT (__stdcall *QueryInterface)(struct ITfReadOnlyProperty *This, const IID *const riid, void **ppvObject);
  ULONG (__stdcall *AddRef)(struct ITfReadOnlyProperty *This);
  ULONG (__stdcall *Release)(struct ITfReadOnlyProperty *This);
  HRESULT (__stdcall *GetType)(struct ITfReadOnlyProperty *This, GUID *pguid);
  HRESULT (__stdcall *EnumRanges)(struct ITfReadOnlyProperty *This, TfEditCookie ec, IEnumTfRanges **ppEnum, ITfRange *pTargetRange);
  HRESULT (__stdcall *GetValue)(struct ITfReadOnlyProperty *This, TfEditCookie ec, ITfRange *pRange, VARIANT *pvarValue);
  HRESULT (__stdcall *GetContext)(struct ITfReadOnlyProperty *This, ITfContext **ppContext);
};

struct ITfReadOnlyProperty
{
    ITfReadOnlyPropertyVtbl *lpVtbl;
};

struct IEnumTfPropertiesVtbl
{
  HRESULT (__stdcall *QueryInterface)(struct IEnumTfProperties *This, const IID *const riid, void **ppvObject);
  ULONG (__stdcall *AddRef)(struct IEnumTfProperties *This);
  ULONG (__stdcall *Release)(struct IEnumTfProperties *This);
  HRESULT (__stdcall *Clone)(struct IEnumTfProperties *This, IEnumTfProperties **ppEnum);
  HRESULT (__stdcall *Next)(struct IEnumTfProperties *This, ULONG ulCount, ITfProperty **ppProp, ULONG *pcFetched);
  HRESULT (__stdcall *Reset)(struct IEnumTfProperties *This);
  HRESULT (__stdcall *Skip)(struct IEnumTfProperties *This, ULONG ulCount);
};

struct IEnumTfProperties
{
    IEnumTfPropertiesVtbl *lpVtbl;
};

struct ITfDocumentMgrVtbl
{
  HRESULT (__stdcall *QueryInterface)(struct ITfDocumentMgr *This, const IID *const riid, void **ppvObject);
  ULONG (__stdcall *AddRef)(struct ITfDocumentMgr *This);
  ULONG (__stdcall *Release)(struct ITfDocumentMgr *This);
  HRESULT (__stdcall *CreateContext)(struct ITfDocumentMgr *This, TfClientId tidOwner, DWORD dwFlags, IUnknown *punk, struct ITfContext **ppic, TfEditCookie *pecTextStore);
  HRESULT (__stdcall *Push)(struct ITfDocumentMgr *This, struct ITfContext *pic);
  HRESULT (__stdcall *Pop)(struct ITfDocumentMgr *This, DWORD dwFlags);
  HRESULT (__stdcall *GetTop)(struct ITfDocumentMgr *This, struct ITfContext **ppic);
  HRESULT (__stdcall *GetBase)(struct ITfDocumentMgr *This, struct ITfContext **ppic);
  HRESULT (__stdcall *EnumContexts)(struct ITfDocumentMgr *This, struct IEnumTfContexts **ppEnum);
};

struct ITfDocumentMgr
{
    struct ITfDocumentMgrVtbl *lpVtbl;
};


struct IEnumTfContexts;

struct IEnumTfContextsVtbl
{
  HRESULT (__stdcall *QueryInterface)(struct IEnumTfContexts *This, const IID *const riid, void **ppvObject);
  ULONG (__stdcall *AddRef)(struct IEnumTfContexts *This);
  ULONG (__stdcall *Release)(struct IEnumTfContexts *This);
  HRESULT (__stdcall *Clone)(struct IEnumTfContexts *This, struct IEnumTfContexts **ppEnum);
  HRESULT (__stdcall *Next)(struct IEnumTfContexts *This, ULONG ulCount, struct ITfContext **rgContext, ULONG *pcFetched);
  HRESULT (__stdcall *Reset)(struct IEnumTfContexts *This);
  HRESULT (__stdcall *Skip)(struct IEnumTfContexts *This, ULONG ulCount);
};

struct IEnumTfContexts
{
    IEnumTfContextsVtbl *lpVtbl;
};

struct ITfRangeBackupVtbl
{
  HRESULT (__stdcall *QueryInterface)(struct ITfRangeBackup *This, const IID *const riid, void **ppvObject);
  ULONG (__stdcall *AddRef)(struct ITfRangeBackup *This);
  ULONG (__stdcall *Release)(struct ITfRangeBackup *This);
  HRESULT (__stdcall *Restore)(struct ITfRangeBackup *This, TfEditCookie ec, ITfRange *pRange);
};

struct ITfRangeBackup
{
    ITfRangeBackupVtbl *lpVtbl;
};

typedef struct TF_LANGBARITEMINFO
{
    CLSID clsidService;
    GUID guidItem;
    DWORD dwStyle;
    ULONG ulSort;
    WCHAR szDescription[32];
} TF_LANGBARITEMINFO;

struct ITfLangBarItemMgrVtbl
{
  HRESULT (__stdcall *QueryInterface)(struct ITfLangBarItemMgr *This, const IID *const riid, void **ppvObject);
  ULONG (__stdcall *AddRef)(struct ITfLangBarItemMgr *This);
  ULONG (__stdcall *Release)(struct ITfLangBarItemMgr *This);
  HRESULT (__stdcall *EnumItems)(struct ITfLangBarItemMgr *This, struct IEnumTfLangBarItems **ppEnum);
  HRESULT (__stdcall *GetItem)(struct ITfLangBarItemMgr *This, const GUID *const rguid, struct ITfLangBarItem **ppItem);
  HRESULT (__stdcall *AddItem)(struct ITfLangBarItemMgr *This, struct ITfLangBarItem *punk);
  HRESULT (__stdcall *RemoveItem)(struct ITfLangBarItemMgr *This, struct ITfLangBarItem *punk);
  HRESULT (__stdcall *AdviseItemSink)(struct ITfLangBarItemMgr *This, struct ITfLangBarItemSink *punk, DWORD *pdwCookie, const GUID *const rguidItem);
  HRESULT (__stdcall *UnadviseItemSink)(struct ITfLangBarItemMgr *This, DWORD dwCookie);
  HRESULT (__stdcall *GetItemFloatingRect)(struct ITfLangBarItemMgr *This, DWORD dwThreadId, const GUID *const rguid, RECT *prc);
  HRESULT (__stdcall *GetItemsStatus)(struct ITfLangBarItemMgr *This, ULONG ulCount, const GUID *prgguid, DWORD *pdwStatus);
  HRESULT (__stdcall *GetItemNum)(struct ITfLangBarItemMgr *This, ULONG *pulCount);
  HRESULT (__stdcall *GetItems)(struct ITfLangBarItemMgr *This, ULONG ulCount, struct ITfLangBarItem **ppItem, TF_LANGBARITEMINFO *pInfo, DWORD *pdwStatus, ULONG *pcFetched);
  HRESULT (__stdcall *AdviseItemsSink)(struct ITfLangBarItemMgr *This, ULONG ulCount, struct ITfLangBarItemSink **ppunk, const GUID *pguidItem, DWORD *pdwCookie);
  HRESULT (__stdcall *UnadviseItemsSink)(struct ITfLangBarItemMgr *This, ULONG ulCount, DWORD *pdwCookie);
};

struct ITfLangBarItemMgr
{
    ITfLangBarItemMgrVtbl *lpVtbl;
};

struct IEnumTfLangBarItemsVtbl
{
  HRESULT (__stdcall *QueryInterface)(struct IEnumTfLangBarItems *This, const IID *const riid, void **ppvObject);
  ULONG (__stdcall *AddRef)(struct IEnumTfLangBarItems *This);
  ULONG (__stdcall *Release)(struct IEnumTfLangBarItems *This);
  HRESULT (__stdcall *Clone)(struct IEnumTfLangBarItems *This, struct IEnumTfLangBarItems **ppEnum);
  HRESULT (__stdcall *Next)(struct IEnumTfLangBarItems *This, ULONG ulCount, struct ITfLangBarItem **ppItem, ULONG *pcFetched);
  HRESULT (__stdcall *Reset)(struct IEnumTfLangBarItems *This);
  HRESULT (__stdcall *Skip)(struct IEnumTfLangBarItems *This, ULONG ulCount);
};

struct IEnumTfLangBarItems
{
    IEnumTfLangBarItemsVtbl *lpVtbl;
};

struct ITfLangBarItemVtbl
{
  HRESULT (__stdcall *QueryInterface)(struct ITfLangBarItem *This, const IID *const riid, void **ppvObject);
  ULONG (__stdcall *AddRef)(struct ITfLangBarItem *This);
  ULONG (__stdcall *Release)(struct ITfLangBarItem *This);
  HRESULT (__stdcall *GetInfo)(struct ITfLangBarItem *This, TF_LANGBARITEMINFO *pInfo);
  HRESULT (__stdcall *GetStatus)(struct ITfLangBarItem *This, DWORD *pdwStatus);
  HRESULT (__stdcall *Show)(struct ITfLangBarItem *This, BOOL fShow);
  HRESULT (__stdcall *GetTooltipString)(struct ITfLangBarItem *This, BSTR *pbstrToolTip);
};

struct ITfLangBarItem
{
    ITfLangBarItemVtbl *lpVtbl;
};

struct ITfLangBarItemSinkVtbl
{
  HRESULT (__stdcall *QueryInterface)(struct ITfLangBarItemSink *This, const IID *const riid, void **ppvObject);
  ULONG (__stdcall *AddRef)(struct ITfLangBarItemSink *This);
  ULONG (__stdcall *Release)(struct ITfLangBarItemSink *This);
  HRESULT (__stdcall *OnUpdate)(struct ITfLangBarItemSink *This, DWORD dwFlags);
};

struct ITfLangBarItemSink
{
    ITfLangBarItemSinkVtbl *lpVtbl;
};

struct ITfSourceVtbl
{
  HRESULT (__stdcall *QueryInterface)(struct ITfSource *This, const IID *const riid, void **ppvObject);
  ULONG (__stdcall *AddRef)(struct ITfSource *This);
  ULONG (__stdcall *Release)(struct ITfSource *This);
  HRESULT (__stdcall *AdviseSink)(struct ITfSource *This, const IID *const riid, IUnknown *punk, DWORD *pdwCookie);
  HRESULT (__stdcall *UnadviseSink)(struct ITfSource *This, DWORD dwCookie);
};

struct ITfSource
{
    ITfSourceVtbl *lpVtbl;
};

struct ITfSourceSingleVtbl
{
  HRESULT (__stdcall *QueryInterface)(struct ITfSourceSingle *This, const IID *const riid, void **ppvObject);
  ULONG (__stdcall *AddRef)(struct ITfSourceSingle *This);
  ULONG (__stdcall *Release)(struct ITfSourceSingle *This);
  HRESULT (__stdcall *AdviseSingleSink)(struct ITfSourceSingle *This, TfClientId tid, const IID *const riid, IUnknown *punk);
  HRESULT (__stdcall *UnadviseSingleSink)(struct ITfSourceSingle *This, TfClientId tid, const IID *const riid);
};

struct ITfSourceSingle
{
    ITfSourceSingleVtbl *lpVtbl;
};

struct ITfMessagePumpVtbl
{
  HRESULT (__stdcall *QueryInterface)(struct ITfMessagePump *This, const IID *const riid, void **ppvObject);
  ULONG (__stdcall *AddRef)(struct ITfMessagePump *This);
  ULONG (__stdcall *Release)(struct ITfMessagePump *This);
  HRESULT (__stdcall *PeekMessageA)(struct ITfMessagePump *This, LPMSG pMsg, HWND hwnd, UINT wMsgFilterMin, UINT wMsgFilterMax, UINT wRemoveMsg, BOOL *pfResult);
  HRESULT (__stdcall *GetMessageA)(struct ITfMessagePump *This, LPMSG pMsg, HWND hwnd, UINT wMsgFilterMin, UINT wMsgFilterMax, BOOL *pfResult);
  HRESULT (__stdcall *PeekMessageW)(struct ITfMessagePump *This, LPMSG pMsg, HWND hwnd, UINT wMsgFilterMin, UINT wMsgFilterMax, UINT wRemoveMsg, BOOL *pfResult);
  HRESULT (__stdcall *GetMessageW)(struct ITfMessagePump *This, LPMSG pMsg, HWND hwnd, UINT wMsgFilterMin, UINT wMsgFilterMax, BOOL *pfResult);
};

struct ITfMessagePump
{
    ITfMessagePumpVtbl *lpVtbl;
};

struct ITfConfigureSystemKeystrokeFeedVtbl
{
  HRESULT (__stdcall *QueryInterface)(struct ITfConfigureSystemKeystrokeFeed *This, const IID *const riid, void **ppvObject);
  ULONG (__stdcall *AddRef)(struct ITfConfigureSystemKeystrokeFeed *This);
  ULONG (__stdcall *Release)(struct ITfConfigureSystemKeystrokeFeed *This);
  HRESULT (__stdcall *DisableSystemKeystrokeFeed)(struct ITfConfigureSystemKeystrokeFeed *This);
  HRESULT (__stdcall *EnableSystemKeystrokeFeed)(struct ITfConfigureSystemKeystrokeFeed *This);
};

struct ITfConfigureSystemKeystrokeFeed
{
    ITfConfigureSystemKeystrokeFeedVtbl *lpVtbl;
};

struct ITfClientIdVtbl
{
  HRESULT (__stdcall *QueryInterface)(struct ITfClientId *This, const IID *const riid, void **ppvObject);
  ULONG (__stdcall *AddRef)(struct ITfClientId *This);
  ULONG (__stdcall *Release)(struct ITfClientId *This);
  HRESULT (__stdcall *GetClientId)(struct ITfClientId *This, const IID *const rclsid, TfClientId *ptid);
};

struct ITfClientId
{
    ITfClientIdVtbl *lpVtbl;
};

struct ITfCompartmentMgrVtbl
{
  HRESULT (__stdcall *QueryInterface)(struct ITfCompartmentMgr *This, const IID *const riid, void **ppvObject);
  ULONG (__stdcall *AddRef)(struct ITfCompartmentMgr *This);
  ULONG (__stdcall *Release)(struct ITfCompartmentMgr *This);
  HRESULT (__stdcall *GetCompartment)(struct ITfCompartmentMgr *This, const GUID *const rguid, struct ITfCompartment **ppcomp);
  HRESULT (__stdcall *ClearCompartment)(struct ITfCompartmentMgr *This, TfClientId tid, const GUID *const rguid);
  HRESULT (__stdcall *EnumCompartments)(struct ITfCompartmentMgr *This, struct IEnumGUID **ppEnum);
};

struct ITfCompartmentMgr
{
    ITfCompartmentMgrVtbl *lpVtbl;
};

struct IEnumGUIDVtbl
{
  HRESULT (__stdcall *QueryInterface)(struct IEnumGUID *This, const IID *const riid, void **ppvObject);
  ULONG (__stdcall *AddRef)(struct IEnumGUID *This);
  ULONG (__stdcall *Release)(struct IEnumGUID *This);
  HRESULT (__stdcall *Next)(struct IEnumGUID *This, ULONG celt, GUID *rgelt, ULONG *pceltFetched);
  HRESULT (__stdcall *Skip)(struct IEnumGUID *This, ULONG celt);
  HRESULT (__stdcall *Reset)(struct IEnumGUID *This);
  HRESULT (__stdcall *Clone)(struct IEnumGUID *This, struct IEnumGUID **ppenum);
};

struct IEnumGUID
{
    IEnumGUIDVtbl *lpVtbl;
};

struct ITfRangeAnchorVtbl
{
  HRESULT (__stdcall *GetFormattedText)(TfEditCookie ec, IDataObject **ppDataObject);
  HRESULT (__stdcall *GetEmbedded)(TfEditCookie ec, const GUID *rguidService, const IID *riid, IUnknown **ppunk);
  HRESULT (__stdcall *InsertEmbedded)(TfEditCookie ec, DWORD dwFlags, IDataObject *pDataObject);
  HRESULT (__stdcall *ShiftStart)(TfEditCookie ec, LONG cchReq, LONG *pcch, const TF_HALTCOND *pHalt);
  HRESULT (__stdcall *ShiftEnd)(TfEditCookie ec, LONG cchReq, LONG *pcch, const TF_HALTCOND *pHalt);
  HRESULT (__stdcall *ShiftStartToRange)(TfEditCookie ec, ITfRange *pRange, TfAnchor aPos);
  HRESULT (__stdcall *ShiftEndToRange)(TfEditCookie ec, ITfRange *pRange, TfAnchor aPos);
  HRESULT (__stdcall *ShiftStartRegion)(TfEditCookie ec, TfShiftDir dir, BOOL *pfNoRegion);
  HRESULT (__stdcall *ShiftEndRegion)(TfEditCookie ec, TfShiftDir dir, BOOL *pfNoRegion);
  HRESULT (__stdcall *IsEmpty)(TfEditCookie ec, BOOL *pfEmpty);
  HRESULT (__stdcall *Collapse)(TfEditCookie ec, TfAnchor aPos);
  HRESULT (__stdcall *IsEqualStart)(TfEditCookie ec, ITfRange *pWith, TfAnchor aPos, BOOL *pfEqual);
  HRESULT (__stdcall *IsEqualEnd)(TfEditCookie ec, ITfRange *pWith, TfAnchor aPos, BOOL *pfEqual);
  HRESULT (__stdcall *CompareStart)(TfEditCookie ec, ITfRange *pWith, TfAnchor aPos, LONG *plResult);
  HRESULT (__stdcall *CompareEnd)(TfEditCookie ec, ITfRange *pWith, TfAnchor aPos, LONG *plResult);
  HRESULT (__stdcall *AdjustForInsert)(TfEditCookie ec, ULONG cchInsert, BOOL *pfInsertOk);
  HRESULT (__stdcall *GetGravity)(TfGravity *pgStart, TfGravity *pgEnd);
  HRESULT (__stdcall *SetGravity)(TfEditCookie ec, TfGravity gStart, TfGravity gEnd);
  HRESULT (__stdcall *Clone)(struct ITfRange **ppClone);
  HRESULT (__stdcall *GetContext)(struct ITfContext **ppContext);
};

struct ITfRangeAnchor
{
    ITfRangeAnchorVtbl *lpVtbl;
};
