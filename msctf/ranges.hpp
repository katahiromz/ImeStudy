class CInputContext;

extern GUID IID_PRIV_CRANGE;

class CRange
    : public ITfRangeACP
    , public ITfRangeAnchor
    , public ITfSource
{
    DWORD m_dwUnknown1;
    CComPtr<IAnchor> m_pAnchorStart;
    CComPtr<IAnchor> m_pAnchorEnd;
    CInputContext *m_pInputContext;
    CComPtr<ITfContext> m_pContextEnd;
    DWORD m_dwCookie;
    DWORD m_dwUnknown2;
    LONG m_cRefs;

public:
    CRange(CInputContext *pIC, DWORD lockType, IAnchor *pAnchorStart, IAnchor *pAnchorEnd, TfGravity grav);
    virtual ~CRange();

    // ** IUnknown methods **
    STDMETHODIMP QueryInterface(REFIID riid, void **ppvObj) override;
    STDMETHODIMP_(ULONG) AddRef() override;
    STDMETHODIMP_(ULONG) Release() override;

    // ** ITfRange methods **
    STDMETHODIMP GetText(
        _In_ TfEditCookie ec,
        _In_ DWORD dwFlags,
        _Out_ WCHAR *pchText,
        _In_ ULONG cchMax,
        _Out_ ULONG *pcch) override;
    STDMETHODIMP SetText(
        _In_ TfEditCookie ec,
        _In_ DWORD dwFlags,
        _In_ const WCHAR *pchText,
        _In_ LONG cch) override;
    STDMETHODIMP GetFormattedText(
        _In_ TfEditCookie ec,
        _Out_ IDataObject **ppDataObject) override;
    STDMETHODIMP GetEmbedded(
        _In_ TfEditCookie ec,
        _In_ REFGUID rguidService,
        _In_ REFIID riid,
        _Out_ IUnknown **ppunk) override;
    STDMETHODIMP InsertEmbedded(
        _In_ TfEditCookie ec,
        _In_ DWORD dwFlags,
        _In_ IDataObject *pDataObject) override;
    STDMETHODIMP ShiftStart(
        _In_ TfEditCookie ec,
        _In_ LONG cchReq,
        _Out_ LONG *pcch,
        _In_ const TF_HALTCOND *pHalt) override;
    STDMETHODIMP ShiftEnd(
        _In_ TfEditCookie ec,
        _In_ LONG cchReq,
        _Out_ LONG *pcch,
        _In_ const TF_HALTCOND *pHalt) override;
    STDMETHODIMP ShiftStartToRange(
        _In_ TfEditCookie ec,
        _In_ ITfRange *pRange,
        _In_ TfAnchor aPos) override;
    STDMETHODIMP ShiftEndToRange(
        _In_ TfEditCookie ec,
        _In_ ITfRange *pRange,
        _In_ TfAnchor aPos) override;
    STDMETHODIMP ShiftStartRegion(
        _In_ TfEditCookie ec,
        _In_ TfShiftDir dir,
        _Out_ BOOL *pfNoRegion) override;
    STDMETHODIMP ShiftEndRegion(
        _In_ TfEditCookie ec,
        _In_ TfShiftDir dir,
        _Out_ BOOL *pfNoRegion) override;
    STDMETHODIMP IsEmpty(
        _In_ TfEditCookie ec,
        _Out_ BOOL *pfEmpty) override;
    STDMETHODIMP Collapse(
        _In_ TfEditCookie ec,
        _In_ TfAnchor aPos) override;
    STDMETHODIMP IsEqualStart(
        _In_ TfEditCookie ec,
        _In_ ITfRange *pWith,
        _In_ TfAnchor aPos,
        _Out_ BOOL *pfEqual) override;
    STDMETHODIMP IsEqualEnd(
        _In_ TfEditCookie ec,
        _In_ ITfRange *pWith,
        _In_ TfAnchor aPos,
        _Out_ BOOL *pfEqual) override;
    STDMETHODIMP CompareStart(
        _In_ TfEditCookie ec,
        _In_ ITfRange *pWith,
        _In_ TfAnchor aPos,
        _Out_ LONG *plResult) override;
    STDMETHODIMP CompareEnd(
        _In_ TfEditCookie ec,
        _In_ ITfRange *pWith,
        _In_ TfAnchor aPos,
        _Out_ LONG *plResult) override;
    STDMETHODIMP AdjustForInsert(
        _In_ TfEditCookie ec,
        _In_ ULONG cchInsert,
        _Out_ BOOL *pfInsertOk) override;
    STDMETHODIMP GetGravity(
        _Out_ TfGravity *pgStart,
        _Out_ TfGravity *pgEnd) override;
    STDMETHODIMP SetGravity(
        _In_ TfEditCookie ec,
        _In_ TfGravity gStart,
        _In_ TfGravity gEnd) override;
    STDMETHODIMP Clone(
        _Out_ ITfRange **ppClone) override;
    STDMETHODIMP GetContext(
        _Out_ ITfContext **ppContext) override;

    // ** ITfRangeACP methods **
    STDMETHODIMP GetExtent(_Out_ LONG *pacpAnchor, _Out_ LONG *pcch) override;
    STDMETHODIMP SetExtent(_In_ LONG acpAnchor, _In_ LONG cch) override;

    // ** ITfRangeAnchor methods **
    STDMETHODIMP GetFormattedText(
        _In_ TfEditCookie ec,
        _Out_ IDataObject **ppDataObject) override;
    STDMETHODIMP GetEmbedded(
        _In_ TfEditCookie ec,
        _In_ REFGUID rguidService,
        _In_ REFIID riid,
        _Out_ IUnknown **ppunk) override;
    STDMETHODIMP InsertEmbedded(
        _In_ TfEditCookie ec,
        _In_ DWORD dwFlags,
        _In_ IDataObject *pDataObject) override;
    STDMETHODIMP ShiftStart(
        _In_ TfEditCookie ec,
        _In_ LONG cchReq,
        _Out_ LONG *pcch,
        _In_ const TF_HALTCOND *pHalt) override;
    STDMETHODIMP ShiftEnd(
        _In_ TfEditCookie ec,
        _In_ LONG cchReq,
        _Out_ LONG *pcch,
        _In_ const TF_HALTCOND *pHalt) override;
    STDMETHODIMP ShiftStartToRange(
        _In_ TfEditCookie ec,
        _In_ ITfRange *pRange,
        _In_ TfAnchor aPos) override;
    STDMETHODIMP ShiftEndToRange(
        _In_ TfEditCookie ec,
        _In_ ITfRange *pRange,
        _In_ TfAnchor aPos) override;
    STDMETHODIMP ShiftStartRegion(
        _In_ TfEditCookie ec,
        _In_ TfShiftDir dir,
        _Out_ BOOL *pfNoRegion) override;
    STDMETHODIMP ShiftEndRegion(
        _In_ TfEditCookie ec,
        _In_ TfShiftDir dir,
        _Out_ BOOL *pfNoRegion) override;
    STDMETHODIMP IsEmpty(
        _In_ TfEditCookie ec,
        _Out_ BOOL *pfEmpty) override;
    STDMETHODIMP Collapse(
        _In_ TfEditCookie ec,
        _In_ TfAnchor aPos) override;
    STDMETHODIMP IsEqualStart(
        _In_ TfEditCookie ec,
        _In_ ITfRange *pWith,
        _In_ TfAnchor aPos,
        _Out_ BOOL *pfEqual) override;
    STDMETHODIMP IsEqualEnd(
        _In_ TfEditCookie ec,
        _In_ ITfRange *pWith,
        _In_ TfAnchor aPos,
        _Out_ BOOL *pfEqual) override;
    STDMETHODIMP CompareStart(
        _In_ TfEditCookie ec,
        _In_ ITfRange *pWith,
        _In_ TfAnchor aPos,
        _Out_ LONG *plResult) override;
    STDMETHODIMP CompareEnd(
        _In_ TfEditCookie ec,
        _In_ ITfRange *pWith,
        _In_ TfAnchor aPos,
        _Out_ LONG *plResult) override;
    STDMETHODIMP AdjustForInsert(
        _In_ TfEditCookie ec,
        _In_ ULONG cchInsert,
        _Out_ BOOL *pfInsertOk) override;
    STDMETHODIMP GetGravity(
        _Out_ TfGravity *pgStart,
        _Out_ TfGravity *pgEnd) override;
    STDMETHODIMP SetGravity(
        _In_ TfEditCookie ec,
        _In_ TfGravity gStart,
        _In_ TfGravity gEnd) override;
    STDMETHODIMP Clone(_Out_ ITfRange **ppClone) override;
    STDMETHODIMP GetContext(_Out_ ITfContext **ppContext) override;

    // ** ITfSource methods **
    STDMETHODIMP AdviseSink(
        _In_ REFIID riid,
        _In_ IUnknown *punk,
        _Out_ DWORD *pdwCookie) override;
    STDMETHODIMP UnadviseSink(
        _In_ DWORD dwCookie) override;

protected:
    CRange *_Clone();

    HRESULT _IsEqualX(TfEditCookie ec, BOOL bEnd, ITfRange *pWith, TfAnchor aPos, BOOL *pfEqual);

    HRESULT _CompareX(
        TfEditCookie ec,
        BOOL bEnd,
        ITfRange *pWidth,
        TfAnchor aPos,
        LONG *plResult);
};
