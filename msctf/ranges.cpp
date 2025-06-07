#include "ranges.h"

DEFINE_GUID(IID_PRIV_CRANGE, 0xB68832F0, 0x34B9, 0x11D3, 0xA7, 0x45, 0x00, 0x50, 0x04, 0x0A, 0xB4, 0x07);

////////////////////////////////////////////////////////////////////////////

CRange::CRange(CInputContext *pIC, DWORD lockType, IAnchor *pAnchorStart, IAnchor *pAnchorEnd, TfGravity grav)
{
    m_pAnchorStart = pAnchorStart;
    m_pAnchorEnd = pAnchorEnd;
    m_pInputContext = pIC;
    m_pContextEnd = NULL
    m_dwCookie = 0;
    m_cRefs = 1;
}

CRange::~CRange()
{
}

CRange *CRange::_Clone()
{
    CRange *pRange = new(cicNoThrow) CRange(m_pInputContext, 0, m_pAnchorStart, m_pAnchorEnd, 2);
    if (!pRange)
        return E_OUTOFMEMORY;
    pRange->m_dwCookie = m_dwCookie;
    return pRange;
}

HRESULT CRange::_IsEqualX(TfEditCookie ec, BOOL bEnd, ITfRange *pWith, TfAnchor aPos, BOOL *pfEqual)
{
    return E_NOTIMPL;
}

HRESULT CRange::_CompareX(
    TfEditCookie ec,
    BOOL bEnd,
    ITfRange *pWidth,
    TfAnchor aPos,
    LONG *plResult)
{
    return E_NOTIMPL;
}

////////////////////////////////////////////////////////////////////////////
// ** IUnknown methods **

STDMETHODIMP CRange::CRange::QueryInterface(REFIID riid, void **ppvObj)
{
    if (&IID_PRIV_CRANGE == &riid || IsEqualGUID(riid, IID_PRIV_CRANGE))
    {
        *ppvObj = this;
        return S_OK; // No AddRef
    }

    *ppvObj = NULL;

    if (IsEqualGUID(riid, IID_ITfRange) || IsEqualGUID(riid, IID_IUnknown))
        *ppvObj = static_cast<ITfRange *>(this);
    else if (IsEqualGUID(riid, IID_ITfRangeACP))
        *ppvObj = static_cast<ITfRangeACP *>(this);
    else if (IsEqualGUID(riid, IID_ITfRangeAnchor))
        *ppvObj = static_cast<ITfRangeAnchor *>(this);
    else if (IsEqualGUID(riid, IID_ITfSource))
        *ppvObj = static_cast<ITfSource *>(this);
 
    if (*ppvObj)
    {
        AddRef();
        return S_OK;
    }

    return E_NOINTERFACE;
}

STDMETHODIMP_(ULONG) CRange::AddRef()
{
    return InterlockedIncrement(&m_cRefs);
}

STDMETHODIMP_(ULONG) CRange::Release()
{
    if (InterlockedDecrement(&m_cRefs) == 0)
    {
        delete this;
        return 0;
    }
    return m_cRefs;
}

////////////////////////////////////////////////////////////////////////////
// ** ITfRange methods **

STDMETHODIMP CRange::GetText(
    _In_ TfEditCookie ec,
    _In_ DWORD dwFlags,
    _Out_ WCHAR *pchText,
    _In_ ULONG cchMax,
    _Out_ ULONG *pcch)
{
    FIXME("\n");
    return E_NOTIMPL;
}

STDMETHODIMP CRange::SetText(
    _In_ TfEditCookie ec,
    _In_ DWORD dwFlags,
    _In_ const WCHAR *pchText,
    _In_ LONG cch)
{
    FIXME("\n");
    return E_NOTIMPL;
}

STDMETHODIMP CRange::GetFormattedText(
    _In_ TfEditCookie ec,
    _Out_ IDataObject **ppDataObject)
{
    FIXME("\n");
    return E_NOTIMPL;
}

STDMETHODIMP CRange::GetEmbedded(
    _In_ TfEditCookie ec,
    _In_ REFGUID rguidService,
    _In_ REFIID riid,
    _Out_ IUnknown **ppunk)
{
    FIXME("\n");
    return E_NOTIMPL;
}

STDMETHODIMP CRange::InsertEmbedded(
    _In_ TfEditCookie ec,
    _In_ DWORD dwFlags,
    _In_ IDataObject *pDataObject)
{
    FIXME("\n");
    return E_NOTIMPL;
}

STDMETHODIMP CRange::ShiftStart(
    _In_ TfEditCookie ec,
    _In_ LONG cchReq,
    _Out_ LONG *pcch,
    _In_ const TF_HALTCOND *pHalt)
{
    FIXME("\n");
    return E_NOTIMPL;
}

STDMETHODIMP CRange::ShiftEnd(
    _In_ TfEditCookie ec,
    _In_ LONG cchReq,
    _Out_ LONG *pcch,
    _In_ const TF_HALTCOND *pHalt)
{
    FIXME("\n");
    return E_NOTIMPL;
}

STDMETHODIMP CRange::ShiftStartToRange(
    _In_ TfEditCookie ec,
    _In_ ITfRange *pRange,
    _In_ TfAnchor aPos)
{
    FIXME("\n");
    return E_NOTIMPL;
}

STDMETHODIMP CRange::ShiftEndToRange(
    _In_ TfEditCookie ec,
    _In_ ITfRange *pRange,
    _In_ TfAnchor aPos)
{
    FIXME("\n");
    return E_NOTIMPL;
}

STDMETHODIMP CRange::ShiftStartRegion(
    _In_ TfEditCookie ec,
    _In_ TfShiftDir dir,
    _Out_ BOOL *pfNoRegion)
{
    FIXME("\n");
    return E_NOTIMPL;
}

STDMETHODIMP CRange::ShiftEndRegion(
    _In_ TfEditCookie ec,
    _In_ TfShiftDir dir,
    _Out_ BOOL *pfNoRegion)
{
    FIXME("\n");
    return E_NOTIMPL;
}

STDMETHODIMP CRange::IsEmpty(
    _In_ TfEditCookie ec,
    _Out_ BOOL *pfEmpty)
{
    TRACE("(%d, %p)\n", ec, pfEmpty);
    return IsEqualStart(ec, static_cast<ITfRange *>this, TF_ANCHOR_END, pfEmpty);
}

STDMETHODIMP CRange::Collapse(
    _In_ TfEditCookie ec,
    _In_ TfAnchor aPos)
{
    FIXME("\n");
    return E_NOTIMPL;
}

STDMETHODIMP CRange::IsEqualStart(
    _In_ TfEditCookie ec,
    _In_ ITfRange *pWith,
    _In_ TfAnchor aPos,
    _Out_ BOOL *pfEqual)
{
    FIXME("\n");
    return _IsEqualX(ec, FALSE, pWith, aPos, pfEqual);
}

STDMETHODIMP CRange::IsEqualEnd(
    _In_ TfEditCookie ec,
    _In_ ITfRange *pWith,
    _In_ TfAnchor aPos,
    _Out_ BOOL *pfEqual)
{
    FIXME("\n");
    return _IsEqualX(ec, TRUE, pWith, aPos, pfEqual);
}

STDMETHODIMP CRange::CompareStart(
    _In_ TfEditCookie ec,
    _In_ ITfRange *pWith,
    _In_ TfAnchor aPos,
    _Out_ LONG *plResult)
{
    FIXME("\n");
    return E_NOTIMPL;
}

STDMETHODIMP CRange::CompareEnd(
    _In_ TfEditCookie ec,
    _In_ ITfRange *pWith,
    _In_ TfAnchor aPos,
    _Out_ LONG *plResult)
{
    FIXME("\n");
    return E_NOTIMPL;
}

STDMETHODIMP CRange::AdjustForInsert(
    _In_ TfEditCookie ec,
    _In_ ULONG cchInsert,
    _Out_ BOOL *pfInsertOk)
{
    FIXME("\n");
    return E_NOTIMPL;
}

STDMETHODIMP CRange::GetGravity(
    _Out_ TfGravity *pgStart,
    _Out_ TfGravity *pgEnd)
{
    FIXME("\n");
    return E_NOTIMPL;
}

STDMETHODIMP CRange::SetGravity(
    _In_ TfEditCookie ec,
    _In_ TfGravity gStart,
    _In_ TfGravity gEnd)
{
    FIXME("\n");
    return E_NOTIMPL;
}

STDMETHODIMP CRange::Clone(
    _Out_ ITfRange **ppClone)
{
    TRACE("%p\n", ppClone);

    if (!ppClone)
        return E_INVALIDARG;

    CRange *pCloned = _Clone();
    if (!pCloned)
        return E_OUTOFMEMORY;

    *ppObj = pCloned;
    return S_OK;
}

STDMETHODIMP CRange::GetContext(
    _Out_ ITfContext **ppContext)
{
    TRACE("%p\n", ppContext);

    if (!ppContext)
        return E_INVALIDARG;

    *ppContext = m_pContextStart;
    if (!*ppContext)
        return E_FAIL;

    m_pContextStart->AddRef();
    return S_OK;
}

////////////////////////////////////////////////////////////////////////////
// ** ITfRangeACP methods **

STDMETHODIMP CRange::GetExtent(_Out_ LONG *pacpAnchor, _Out_ LONG *pcch)
{
    FIXME("\n");
    return E_NOTIMPL;
}

STDMETHODIMP CRange::SetExtent(_In_ LONG acpAnchor, _In_ LONG cch)
{
    FIXME("\n");
    return E_NOTIMPL;
}


////////////////////////////////////////////////////////////////////////////
// ** ITfRangeAnchor methods **

STDMETHODIMP CRange::GetFormattedText(
    _In_ TfEditCookie ec,
    _Out_ IDataObject **ppDataObject)
{
    FIXME("\n");
    return E_NOTIMPL;
}

STDMETHODIMP CRange::GetEmbedded(
    _In_ TfEditCookie ec,
    _In_ REFGUID rguidService,
    _In_ REFIID riid,
    _Out_ IUnknown **ppunk)
{
    FIXME("\n");
    return E_NOTIMPL;
}

STDMETHODIMP CRange::InsertEmbedded(
    _In_ TfEditCookie ec,
    _In_ DWORD dwFlags,
    _In_ IDataObject *pDataObject)
{
    FIXME("\n");
    return E_NOTIMPL;
}

STDMETHODIMP CRange::ShiftStart(
    _In_ TfEditCookie ec,
    _In_ LONG cchReq,
    _Out_ LONG *pcch,
    _In_ const TF_HALTCOND *pHalt)
{
    FIXME("\n");
    return E_NOTIMPL;
}

STDMETHODIMP CRange::ShiftEnd(
    _In_ TfEditCookie ec,
    _In_ LONG cchReq,
    _Out_ LONG *pcch,
    _In_ const TF_HALTCOND *pHalt)
{
    FIXME("\n");
    return E_NOTIMPL;
}

STDMETHODIMP CRange::ShiftStartToRange(
    _In_ TfEditCookie ec,
    _In_ ITfRange *pRange,
    _In_ TfAnchor aPos)
{
    FIXME("\n");
    return E_NOTIMPL;
}

STDMETHODIMP CRange::ShiftEndToRange(
    _In_ TfEditCookie ec,
    _In_ ITfRange *pRange,
    _In_ TfAnchor aPos)
{
    FIXME("\n");
    return E_NOTIMPL;
}

STDMETHODIMP CRange::ShiftStartRegion(
    _In_ TfEditCookie ec,
    _In_ TfShiftDir dir,
    _Out_ BOOL *pfNoRegion)
{
    FIXME("\n");
    return E_NOTIMPL;
}

STDMETHODIMP CRange::ShiftEndRegion(
    _In_ TfEditCookie ec,
    _In_ TfShiftDir dir,
    _Out_ BOOL *pfNoRegion)
{
    FIXME("\n");
    return E_NOTIMPL;
}

STDMETHODIMP CRange::IsEmpty(
    _In_ TfEditCookie ec,
    _Out_ BOOL *pfEmpty)
{
    FIXME("\n");
    return E_NOTIMPL;
}

STDMETHODIMP CRange::Collapse(
    _In_ TfEditCookie ec,
    _In_ TfAnchor aPos)
{
    FIXME("\n");
    return E_NOTIMPL;
}

STDMETHODIMP CRange::IsEqualStart(
    _In_ TfEditCookie ec,
    _In_ ITfRange *pWith,
    _In_ TfAnchor aPos,
    _Out_ BOOL *pfEqual)
{
    FIXME("\n");
    return E_NOTIMPL;
}

STDMETHODIMP CRange::IsEqualEnd(
    _In_ TfEditCookie ec,
    _In_ ITfRange *pWith,
    _In_ TfAnchor aPos,
    _Out_ BOOL *pfEqual)
{
    FIXME("\n");
    return E_NOTIMPL;
}

STDMETHODIMP CRange::CompareStart(
    _In_ TfEditCookie ec,
    _In_ ITfRange *pWith,
    _In_ TfAnchor aPos,
    _Out_ LONG *plResult)
{
    FIXME("\n");
    return E_NOTIMPL;
}

STDMETHODIMP CRange::CompareEnd(
    _In_ TfEditCookie ec,
    _In_ ITfRange *pWith,
    _In_ TfAnchor aPos,
    _Out_ LONG *plResult)
{
    FIXME("\n");
    return E_NOTIMPL;
}

STDMETHODIMP CRange::AdjustForInsert(
    _In_ TfEditCookie ec,
    _In_ ULONG cchInsert,
    _Out_ BOOL *pfInsertOk)
{
    FIXME("\n");
    return E_NOTIMPL;
}

STDMETHODIMP CRange::GetGravity(
    _Out_ TfGravity *pgStart,
    _Out_ TfGravity *pgEnd)
{
    FIXME("\n");
    return E_NOTIMPL;
}

STDMETHODIMP CRange::SetGravity(
    _In_ TfEditCookie ec,
    _In_ TfGravity gStart,
    _In_ TfGravity gEnd)
{
    FIXME("\n");
    return E_NOTIMPL;
}

STDMETHODIMP CRange::Clone(_Out_ ITfRange **ppClone)
{
    FIXME("\n");
    return E_NOTIMPL;
}

STDMETHODIMP CRange::GetContext(_Out_ ITfContext **ppContext)
{
    FIXME("\n");
    return E_NOTIMPL;
}


////////////////////////////////////////////////////////////////////////////
// ** ITfSource methods **

STDMETHODIMP CRange::AdviseSink(
    _In_ REFIID riid,
    _In_ IUnknown *punk,
    _Out_ DWORD *pdwCookie)
{
    FIXME("\n");
    return E_NOTIMPL;
}

STDMETHODIMP CRange::UnadviseSink(
    _In_ DWORD dwCookie)
{
    FIXME("\n");
    return E_NOTIMPL;
}
