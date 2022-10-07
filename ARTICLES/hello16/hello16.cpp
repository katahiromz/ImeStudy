#include <windows.h>
#include <imm.h>
#include <stdio.h>
#pragma comment(lib, "imm32.lib")

int main(void)
{
#define SEH_CATCH(stmt) puts(#stmt); \
    __try { stmt; } \
    __except(GetExceptionCode() == EXCEPTION_ACCESS_VIOLATION ? EXCEPTION_EXECUTE_HANDLER : EXCEPTION_CONTINUE_SEARCH) \
    { puts("catched"); }

    DebugBreak();
    SEH_CATCH(ImmInstallIMEA(0, 0));
    SEH_CATCH(ImmInstallIMEW(0, 0));
    SEH_CATCH(ImmGetDefaultIMEWnd(0));
    SEH_CATCH(ImmGetDescriptionA(0, 0, 0));
    SEH_CATCH(ImmGetDescriptionW(0, 0, 0));
    SEH_CATCH(ImmGetIMEFileNameA(0, 0, 0));
    SEH_CATCH(ImmGetIMEFileNameW(0, 0, 0));
    SEH_CATCH(ImmGetProperty(0, 0));
    SEH_CATCH(ImmIsIME(0));
    SEH_CATCH(ImmSimulateHotKey(0, 0));
    SEH_CATCH(ImmCreateContext());
    SEH_CATCH(ImmDestroyContext(0));
    SEH_CATCH(ImmGetContext(0));
    SEH_CATCH(ImmReleaseContext(0, 0));
    SEH_CATCH(ImmAssociateContext(0, 0));
    SEH_CATCH(ImmAssociateContextEx(0, 0, 0));
    SEH_CATCH(ImmGetCompositionStringA(0, 0, 0, 0));
    SEH_CATCH(ImmGetCompositionStringW(0, 0, 0, 0));
    SEH_CATCH(ImmSetCompositionStringA(0, 0, 0, 0, 0, 0));
    SEH_CATCH(ImmSetCompositionStringW(0, 0, 0, 0, 0, 0));
    SEH_CATCH(ImmGetCandidateListCountA(0, 0));
    SEH_CATCH(ImmGetCandidateListCountW(0, 0));
    SEH_CATCH(ImmGetCandidateListA(0, 0, 0, 0));
    SEH_CATCH(ImmGetCandidateListW(0, 0, 0, 0));
    SEH_CATCH(ImmGetGuideLineA(0, 0, 0, 0));
    SEH_CATCH(ImmGetGuideLineW(0, 0, 0, 0));
    SEH_CATCH(ImmGetConversionStatus(0, 0, 0));
    SEH_CATCH(ImmGetOpenStatus(0));
    SEH_CATCH(ImmSetOpenStatus(0, 0));
    SEH_CATCH(ImmGetCompositionFontA(0, 0));
    SEH_CATCH(ImmGetCompositionFontW(0, 0));
    SEH_CATCH(ImmSetCompositionFontA(0, 0));
    SEH_CATCH(ImmSetCompositionFontW(0, 0));
    SEH_CATCH(ImmConfigureIMEA(0, 0, 0, 0));
    SEH_CATCH(ImmConfigureIMEW(0, 0, 0, 0));
    SEH_CATCH(ImmEscapeA(0, 0, 0, 0));
    SEH_CATCH(ImmEscapeW(0, 0, 0, 0));
    SEH_CATCH(ImmGetConversionListA(0, 0, 0, 0, 0, 0));
    SEH_CATCH(ImmGetConversionListW(0, 0, 0, 0, 0, 0));
    SEH_CATCH(ImmNotifyIME(0, 0, 0, 0));
    SEH_CATCH(ImmGetStatusWindowPos(0, 0));
    SEH_CATCH(ImmSetStatusWindowPos(0, 0));
    SEH_CATCH(ImmGetCompositionWindow(0, 0));
    SEH_CATCH(ImmSetCompositionWindow(0, 0));
    SEH_CATCH(ImmGetCandidateWindow(0, 0, 0));
    SEH_CATCH(ImmSetCandidateWindow(0, 0));
    SEH_CATCH(ImmIsUIMessageA(0, 0, 0, 0));
    SEH_CATCH(ImmIsUIMessageW(0, 0, 0, 0));
    SEH_CATCH(ImmGetVirtualKey(0));
    SEH_CATCH(ImmRegisterWordA(0, 0, 0, 0));
    SEH_CATCH(ImmRegisterWordW(0, 0, 0, 0));
    SEH_CATCH(ImmUnregisterWordA(0, 0, 0, 0));
    SEH_CATCH(ImmUnregisterWordW(0, 0, 0, 0));
    SEH_CATCH(ImmGetRegisterWordStyleA(0, 0, 0));
    SEH_CATCH(ImmGetRegisterWordStyleW(0, 0, 0));
    SEH_CATCH(ImmEnumRegisterWordA(0, 0, 0, 0, 0, 0));
    SEH_CATCH(ImmEnumRegisterWordW(0, 0, 0, 0, 0, 0));
    SEH_CATCH(ImmDisableIME(0));
    SEH_CATCH(ImmEnumInputContext(0, 0, 0));
    SEH_CATCH(ImmGetImeMenuItemsA(0, 0, 0, 0, 0, 0));
    SEH_CATCH(ImmGetImeMenuItemsW(0, 0, 0, 0, 0, 0));
    puts("OK");
    return 0;
}
