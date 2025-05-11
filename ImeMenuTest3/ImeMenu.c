// License: MIT
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#include <windows.h>
#include <imm.h>
#include <stdio.h>
#include <assert.h>
#include "ImeMenu.h"

#if 0
/* fType of IMEMENUITEMINFO structure */
#define IMFT_RADIOCHECK         0x00001
#define IMFT_SEPARATOR          0x00002
#define IMFT_SUBMENU            0x00004

#define IMEMENUITEM_STRING_SIZE 80

typedef struct tagIMEMENUITEMINFOA {
    UINT        cbSize;
    UINT        fType;
    UINT        fState;
    UINT        wID;
    HBITMAP     hbmpChecked;
    HBITMAP     hbmpUnchecked;
    DWORD       dwItemData;
    CHAR        szString[IMEMENUITEM_STRING_SIZE];
    HBITMAP     hbmpItem;
} IMEMENUITEMINFOA, *PIMEMENUITEMINFOA, NEAR *NPIMEMENUITEMINFOA, FAR *LPIMEMENUITEMINFOA;

typedef struct tagIMEMENUITEMINFOW {
    UINT        cbSize;
    UINT        fType;
    UINT        fState;
    UINT        wID;
    HBITMAP     hbmpChecked;
    HBITMAP     hbmpUnchecked;
    DWORD       dwItemData;
    WCHAR       szString[IMEMENUITEM_STRING_SIZE];
    HBITMAP     hbmpItem;
} IMEMENUITEMINFOW, *PIMEMENUITEMINFOW, NEAR *NPIMEMENUITEMINFOW, FAR *LPIMEMENUITEMINFOW;
#endif

#define IMEMENUINFO_BUFFER_SIZE 0x20000

typedef struct tagIMEMENUINFO
{
    DWORD cbSize;
    DWORD cbCapacity;
    DWORD dwMagic;
    DWORD dwFlags;
    DWORD dwType;
    DWORD dwItemCount;
    DWORD dwParentOffset;
    DWORD dwItemsOffset;
    DWORD dwBitmapsOffset;
} IMEMENUINFO, *PIMEMENUINFO;

typedef struct tagBITMAPINFOMAX
{
    BITMAPINFOHEADER bmiHeader;
    RGBQUAD bmiColors[256];
} BITMAPINFOMAX, *PBITMAPINFOMAX;

typedef struct tagIMEMENUBITMAPHEADER
{
    DWORD cbSize;
    DWORD dwBitsOffset;
    HBITMAP hbm;
} IMEMENUBITMAPHEADER, *PIMEMENUBITMAPHEADER;

#define OFFSET_FROM_PTR(head, ptr)     (PVOID)((PBYTE)(ptr) - (PBYTE)(head))
#define PTR_FROM_OFFSET(head, offset)  (PVOID)((PBYTE)(head) + (SIZE_T)(offset))
#define BOUND_CHECK(target, begin, end) \
    ((PBYTE)(begin) <= (PBYTE)(target) && (PBYTE)(target) <= (PBYTE)(end))

BOOL MakeImeMenu(IN HMENU hMenu, IN const IMEMENUNODE *pMenu);

void *Alloc(size_t size)
{
    return calloc(1, size);
}

void Free(void *ptr)
{
    free(ptr);
}

PIMEMENUNODE g_pMenuList = NULL;
INT g_nNextMenuID = 0;

DWORD
FindImeMenuBitmap(
    _In_ const IMEMENUINFO *pView,
    _In_ HBITMAP hbm)
{
    const BYTE *pb = (const BYTE *)pView;
    pb += pView->dwBitmapsOffset;
    const IMEMENUBITMAPHEADER *pBitmap = (const IMEMENUBITMAPHEADER *)pb;
    while (pBitmap->cbSize)
    {
        if (pBitmap->hbm == hbm)
            return (PBYTE)pBitmap - (PBYTE)pView;
        pBitmap = PTR_FROM_OFFSET(pBitmap, pBitmap->cbSize);
    }
    return 0;
}

VOID DeleteImeMenuBitmaps(_Inout_ PIMEMENUINFO pView)
{
    PBYTE pb = (PBYTE)pView;
    pb += pView->dwBitmapsOffset;
    PIMEMENUBITMAPHEADER pBitmap = (PIMEMENUBITMAPHEADER)pb;
    while (pBitmap->cbSize)
    {
        if (pBitmap->hbm)
        {
            DeleteObject(pBitmap->hbm);
            pBitmap->hbm = NULL;
        }
        pBitmap = PTR_FROM_OFFSET(pBitmap, pBitmap->cbSize);
    }
}

DWORD
SerializeImeMenuBitmap(
    _In_ HDC hDC,
    _Inout_ PIMEMENUINFO pView,
    _In_ HBITMAP hbm)
{
    if (hbm == NULL)
        return 0;

    DWORD dwOffset = FindImeMenuBitmap(pView, hbm);
    if (dwOffset)
        return dwOffset;

    /* Get DIB info */
    BITMAPINFOMAX bmi;
    ZeroMemory(&bmi, sizeof(bmi));
    bmi.bmiHeader.biSize = sizeof(bmi.bmiHeader);
    if (!GetDIBits(hDC, hbm, 0, 0, NULL, (PBITMAPINFO)&bmi, DIB_RGB_COLORS))
    {
        assert(0);
        return 0;
    }

    /* Calculate the possible color table size */
    DWORD colorTableSize = 0;
    if (bmi.bmiHeader.biBitCount <= 8)
        colorTableSize = (1 << bmi.bmiHeader.biBitCount) * sizeof(RGBQUAD);
    else if (bmi.bmiHeader.biBitCount == 16 || bmi.bmiHeader.biBitCount == 32)
        colorTableSize = 3 * sizeof(DWORD);

    DWORD cbBitmapHeader = sizeof(IMEMENUBITMAPHEADER);
    DWORD dibHeaderSize = sizeof(BITMAPINFOHEADER) + colorTableSize;
    DWORD cbData = cbBitmapHeader + dibHeaderSize + bmi.bmiHeader.biSizeImage;

    if (pView->cbSize + cbData + sizeof(DWORD) > pView->cbCapacity)
    {
        assert(0);
        return 0;
    }

    /* Create a bitmap for getting bits */
    HBITMAP hbmTmp = CreateCompatibleBitmap(hDC, bmi.bmiHeader.biWidth, bmi.bmiHeader.biHeight);
    if (!hbmTmp)
    {
        assert(0);
        return 0;
    }

    PBYTE pb = (PBYTE)pView + pView->cbSize;
    PIMEMENUBITMAPHEADER pBitmap = (PIMEMENUBITMAPHEADER)pb;

    pBitmap->cbSize = cbData;
    pBitmap->dwBitsOffset = cbBitmapHeader + dibHeaderSize;
    pBitmap->hbm = hbm;
    pb += cbBitmapHeader;
    PBITMAPINFO pbmi = (PBITMAPINFO)pb;
    CopyMemory(pbmi, &bmi, dibHeaderSize);
    pb += dibHeaderSize;

    HGDIOBJ hbmOld = SelectObject(hDC, hbmTmp);
    BOOL ret = GetDIBits(hDC, hbm, 0, bmi.bmiHeader.biHeight, pb, pbmi, DIB_RGB_COLORS);
    SelectObject(hDC, hbmOld);
    DeleteObject(hbmTmp);

    if (!ret)
    {
        assert(0);
        pBitmap->cbSize = 0;
        return 0;
    }

    pView->cbSize += cbData;
    return (PBYTE)pBitmap - (PBYTE)pView;
}

HBITMAP
DeserializeImeMenuBitmap(_Inout_opt_ const IMEMENUBITMAPHEADER *pBitmap)
{
    const BYTE *pb = (const BYTE *)pBitmap;
    const BITMAPINFO *pbmi = (const BITMAPINFO *)(pb + sizeof(*pBitmap));

    HDC hDC = GetDC(NULL);
    HBITMAP hbm = CreateDIBitmap(hDC,
                                 &pbmi->bmiHeader,
                                 CBM_INIT,
                                 pb + pBitmap->dwBitsOffset,
                                 pbmi,
                                 DIB_RGB_COLORS);
    DWORD error = GetLastError();
    ReleaseDC(NULL, hDC);
    return hbm;
}

DWORD
SerializeImeMenu(
    _Out_ PIMEMENUINFO pView,
    _In_ DWORD cbCapacity,
    _In_ HIMC hIMC,
    _In_ DWORD dwFlags,
    _In_ DWORD dwType,
    _In_opt_ PIMEMENUITEMINFO lpImeParentMenu,
    _In_ BOOL bCountOnly)
{
    PBYTE pb = (PBYTE)pView;
    ZeroMemory(pView, cbCapacity);
    pView->cbSize = sizeof(*pView);
    pView->cbCapacity = cbCapacity;
    pView->dwMagic = 0xBABEF00D;
    pView->dwFlags = dwFlags;
    pView->dwType = dwType;
    pb += sizeof(*pView);

    DWORD dwItemCount = GetImeMenuItemsBase(hIMC, dwFlags, dwType, lpImeParentMenu, NULL, 0);
    pView->dwItemCount = dwItemCount;
    if (bCountOnly)
        return dwItemCount;

    if (!dwItemCount)
        return 0;

    if (lpImeParentMenu)
    {
        pView->dwParentOffset = pb - (PBYTE)pView;
        pView->cbSize += sizeof(*lpImeParentMenu);
        CopyMemory(pb, lpImeParentMenu, sizeof(*lpImeParentMenu));
        pb += sizeof(*lpImeParentMenu);
    }

    SIZE_T cbItems = dwItemCount * sizeof(IMEMENUITEMINFO);

    pView->dwItemsOffset = pb - (PBYTE)pView;
    pView->dwBitmapsOffset = pView->dwItemsOffset + cbItems;
    if (pView->dwBitmapsOffset + sizeof(DWORD) > pView->cbCapacity)
        return 0;

    PIMEMENUITEMINFO pItems = (PIMEMENUITEMINFO)pb;

    dwItemCount = GetImeMenuItemsBase(hIMC, dwFlags, dwType, lpImeParentMenu, pItems, cbItems);
    pView->dwItemCount = dwItemCount;
    pView->cbSize += cbItems;

    DWORD dwOffset;
    HDC hDC = CreateCompatibleDC(NULL);
    for (DWORD iItem = 0; iItem < dwItemCount; ++iItem)
    {
        PIMEMENUITEMINFO pItem = &pItems[iItem];

        dwOffset = SerializeImeMenuBitmap(hDC, pView, pItem->hbmpChecked);
        if (dwOffset)
            pItem->hbmpChecked = UlongToHandle(dwOffset);

        dwOffset = SerializeImeMenuBitmap(hDC, pView, pItem->hbmpUnchecked);
        if (dwOffset)
            pItem->hbmpUnchecked = UlongToHandle(dwOffset);

        dwOffset = SerializeImeMenuBitmap(hDC, pView, pItem->hbmpItem);
        if (dwOffset)
            pItem->hbmpItem = UlongToHandle(dwOffset);
    }
    DeleteDC(hDC);

    DeleteImeMenuBitmaps(pView);

    return dwItemCount;
}

DWORD
DeserializeImeMenu(
    _Inout_ PIMEMENUINFO pView,
    _Out_opt_ PIMEMENUITEMINFO lpImeMenu,
    _In_ DWORD dwSize)
{
    PBYTE pb = (PBYTE)pView;
    if (pView->dwMagic != 0xBABEF00D || pView->cbSize > pView->cbCapacity)
        return 0;

    DWORD dwItemCount = pView->dwItemCount;
    if (!lpImeMenu)
        return dwItemCount;

    if (dwItemCount > dwSize / sizeof(IMEMENUITEMINFO))
        dwItemCount = dwSize / sizeof(IMEMENUITEMINFO);

    pb += pView->dwItemsOffset;
    PIMEMENUITEMINFO pItems = (PIMEMENUITEMINFO)pb;

    PIMEMENUBITMAPHEADER pBitmap;
    for (DWORD iItem = 0; iItem < dwItemCount; ++iItem)
    {
        PIMEMENUITEMINFO pItem = &pItems[iItem];
        if (pItem->hbmpChecked)
        {
            pBitmap = PTR_FROM_OFFSET(pView, pItem->hbmpChecked);
            pItem->hbmpChecked = DeserializeImeMenuBitmap(pBitmap);
        }
        if (pItem->hbmpUnchecked)
        {
            pBitmap = PTR_FROM_OFFSET(pView, pItem->hbmpUnchecked);
            pItem->hbmpUnchecked = DeserializeImeMenuBitmap(pBitmap);
        }
        if (pItem->hbmpItem)
        {
            pBitmap = PTR_FROM_OFFSET(pView, pItem->hbmpItem);
            pItem->hbmpItem = DeserializeImeMenuBitmap(pBitmap);
        }
        lpImeMenu[iItem] = *pItem;
    }

    return dwItemCount;
}

VOID FillImeMenuItem(OUT LPMENUITEMINFO pItemInfo, IN const IMEMENUITEM *pItem)
{
    ZeroMemory(pItemInfo, sizeof(MENUITEMINFO));
    pItemInfo->cbSize = sizeof(MENUITEMINFO);
    pItemInfo->fMask = MIIM_ID | MIIM_STATE | MIIM_DATA;
    pItemInfo->wID = pItem->m_Info.wID;
    pItemInfo->fState = pItem->m_Info.fState;
    pItemInfo->dwItemData = pItem->m_Info.dwItemData;

    if (pItem->m_Info.fType)
    {
        pItemInfo->fMask |= MIIM_FTYPE;
        pItemInfo->fType = 0;
        if (pItem->m_Info.fType & IMFT_RADIOCHECK)
            pItemInfo->fType |= MFT_RADIOCHECK;
        if (pItem->m_Info.fType & IMFT_SEPARATOR)
            pItemInfo->fType |= MFT_SEPARATOR;
    }

    if (pItem->m_Info.fType & IMFT_SUBMENU)
    {
        pItemInfo->fMask |= MIIM_SUBMENU;
        pItemInfo->hSubMenu = CreatePopupMenu();
        MakeImeMenu(pItemInfo->hSubMenu, pItem->m_pSubMenu);
    }

    if (pItem->m_Info.hbmpChecked && pItem->m_Info.hbmpUnchecked)
    {
        pItemInfo->fMask |= MIIM_CHECKMARKS;
        pItemInfo->hbmpChecked = pItem->m_Info.hbmpChecked;
        pItemInfo->hbmpUnchecked = pItem->m_Info.hbmpUnchecked;
    }

    if (pItem->m_Info.hbmpItem)
    {
        pItemInfo->fMask |= MIIM_BITMAP;
        pItemInfo->hbmpItem = pItem->m_Info.hbmpItem;
    }

    PCTSTR szString = pItem->m_Info.szString;
    if (szString && szString[0])
    {
        pItemInfo->fMask |= MIIM_STRING;
        pItemInfo->dwTypeData = (PTSTR)szString;
        pItemInfo->cch = lstrlen(szString);
    }
}

BOOL MakeImeMenu(IN HMENU hMenu, IN const IMEMENUNODE *pMenu)
{
    if (!pMenu->m_nItems)
        return FALSE;

    for (INT iItem = 0; iItem < pMenu->m_nItems; ++iItem)
    {
        MENUITEMINFO mi = { sizeof(mi) };
        FillImeMenuItem(&mi, &pMenu->m_Items[iItem]);
        InsertMenuItem(hMenu, iItem, TRUE, &mi);
    }

    return TRUE;
}

void AddImeMenuNode(PIMEMENUNODE pMenu)
{
    if (!g_pMenuList)
    {
        g_pMenuList = pMenu;
        return;
    }

    pMenu->m_pNext = g_pMenuList;
    g_pMenuList = pMenu;
}

PIMEMENUNODE AllocateImeMenu(DWORD itemCount)
{
    SIZE_T cbMenu = sizeof(IMEMENUNODE) + (itemCount - 1) * sizeof(IMEMENUITEM);
    PIMEMENUNODE pMenu = (PIMEMENUNODE)Alloc(cbMenu);
    if (!pMenu)
        return NULL;
    AddImeMenuNode(pMenu);
    pMenu->m_nItems = itemCount;
    return pMenu;
}

void GetImeMenuItem(IN HWND hWnd, IN HIMC hIMC, OUT PIMEMENUITEMINFO lpImeParentMenu, IN BOOL bRightMenu, OUT PIMEMENUITEM pItem)
{
    ZeroMemory(pItem, sizeof(IMEMENUITEM));
    pItem->m_Info = *lpImeParentMenu;

    if (lpImeParentMenu->fType & IMFT_SUBMENU)
        pItem->m_pSubMenu = CreateImeMenu(hWnd, hIMC, lpImeParentMenu, bRightMenu);

    pItem->m_nRealID = pItem->m_Info.wID;
    pItem->m_Info.wID = ID_STARTIMEMENU + g_nNextMenuID++;
}

#ifdef USE_CUSTOM
#include "CustomImeMenu.c"
#endif

DWORD
GetImeMenuItemsBase(
    IN HIMC hIMC,
    IN DWORD dwFlags,
    IN DWORD dwType,
    IN OUT PIMEMENUITEMINFO lpImeParentMenu OPTIONAL,
    OUT PIMEMENUITEMINFO pImeMenuItems OPTIONAL,
    IN DWORD cbItems)
{
#ifdef USE_CUSTOM
    return ImeGetImeMenuItems(hIMC, dwFlags, dwType, lpImeParentMenu, pImeMenuItems, cbItems);
#else
    return ImmGetImeMenuItems(hIMC, dwFlags, dwType, lpImeParentMenu, pImeMenuItems, cbItems);
#endif
}

DWORD
GetImeMenuItems(
    IN HIMC hIMC,
    IN DWORD dwFlags,
    IN DWORD dwType,
    IN OUT PIMEMENUITEMINFO lpImeParentMenu OPTIONAL,
    OUT PIMEMENUITEMINFO pImeMenuItems OPTIONAL,
    IN DWORD dwSize)
{
#ifdef DO_TRANSPORT
    PBYTE pb = Alloc(IMEMENUINFO_BUFFER_SIZE);
    if (!pb)
    {
        assert(0);
        return 0;
    }
    DWORD dwItemCount = SerializeImeMenu(pb, IMEMENUINFO_BUFFER_SIZE,
                                         hIMC,
                                         dwFlags,
                                         dwType,
                                         lpImeParentMenu,
                                         !pImeMenuItems);
    if (!dwItemCount)
    {
        assert(0);
        return 0;
    }
    DWORD ret = DeserializeImeMenu(pb, pImeMenuItems, dwSize);
    Free(pb);
    return ret;
#else
    return GetImeMenuItemsBase(hIMC, dwFlags, dwType, lpImeParentMenu, pImeMenuItems, dwSize);
#endif
}

PIMEMENUNODE
CreateImeMenu(IN HWND hWnd, IN HIMC hIMC, IN OUT PIMEMENUITEMINFO lpImeParentMenu OPTIONAL, IN BOOL bRightMenu)
{
    DWORD itemCount = GetImeMenuItems(hIMC, bRightMenu, 0x3F, lpImeParentMenu, NULL, 0);
    if (!itemCount)
        return NULL;

    PIMEMENUNODE pMenu = AllocateImeMenu(itemCount);
    if (!pMenu)
        return NULL;

    DWORD cbItems = sizeof(IMEMENUITEMINFO) * itemCount;
    PIMEMENUITEMINFO pImeMenuItems = (PIMEMENUITEMINFO)Alloc(cbItems);
    if (!pImeMenuItems)
        return NULL;

    DWORD newItemCount = GetImeMenuItems(hIMC, bRightMenu, 0x3F, lpImeParentMenu, pImeMenuItems, cbItems);
    if (!newItemCount)
    {
        Free(pImeMenuItems);
        return NULL;
    }

    PIMEMENUITEM pItems = pMenu->m_Items;
    for (DWORD iItem = 0; iItem < newItemCount; ++iItem)
    {
        GetImeMenuItem(hWnd, hIMC, &pImeMenuItems[iItem], bRightMenu, &pItems[iItem]);
    }

    Free(pImeMenuItems);
    return pMenu;
}

HMENU MenuFromImeMenu(const IMEMENUNODE *pMenu)
{
    if (!pMenu)
        return NULL;
    HMENU hMenu = CreatePopupMenu();
    if (!MakeImeMenu(hMenu, pMenu))
    {
        DestroyMenu(hMenu);
        return NULL;
    }
    return hMenu;
}

BOOL FreeMenuNode(PIMEMENUNODE pMenuNode)
{
    if (!pMenuNode)
        return FALSE;

    for (INT iItem = 0; iItem < pMenuNode->m_nItems; ++iItem)
    {
        PIMEMENUITEM pItem = &pMenuNode->m_Items[iItem];
        if (pItem->m_Info.hbmpChecked)
            DeleteObject(pItem->m_Info.hbmpChecked);
        if (pItem->m_Info.hbmpUnchecked)
            DeleteObject(pItem->m_Info.hbmpUnchecked);
        if (pItem->m_Info.hbmpItem)
            DeleteObject(pItem->m_Info.hbmpItem);
    }

    Free(pMenuNode);
    return TRUE;
}

VOID CleanupImeMenus(VOID)
{
    if (!g_pMenuList)
        return;

    PIMEMENUNODE pNext;
    for (PIMEMENUNODE pNode = g_pMenuList; pNode; pNode = pNext)
    {
        pNext = pNode->m_pNext;
        FreeMenuNode(pNode);
    }

    g_pMenuList = NULL;
    g_nNextMenuID = 0;
}

INT GetRealImeMenuID(IN const IMEMENUNODE *pMenu, INT nID)
{
    if (!pMenu || !pMenu->m_nItems || nID < ID_STARTIMEMENU)
        return 0;

    for (INT iItem = 0; iItem < pMenu->m_nItems; ++iItem)
    {
        const IMEMENUITEM *pItem = &pMenu->m_Items[iItem];
        if (pItem->m_Info.wID == nID)
            return pItem->m_nRealID;

        if (pItem->m_pSubMenu)
        {
            INT nRealID = GetRealImeMenuID(pItem->m_pSubMenu, nID);
            if (nRealID)
                return nRealID;
        }
    }

    return 0;
}
