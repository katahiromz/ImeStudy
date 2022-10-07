	.file	"hello13.cpp"
	.intel_syntax noprefix
	.text
	.section	.text$_Z6printfPKcz,"x"
	.linkonce discard
	.globl	__Z6printfPKcz
	.def	__Z6printfPKcz;	.scl	2;	.type	32;	.endef
__Z6printfPKcz:
	push	ebp
	mov	ebp, esp
	push	ebx
	sub	esp, 36
	lea	eax, [ebp+12]
	mov	DWORD PTR [ebp-16], eax
	mov	ebx, DWORD PTR [ebp-16]
	mov	DWORD PTR [esp], 1
	mov	eax, DWORD PTR __imp____acrt_iob_func
	call	eax
	mov	edx, eax
	mov	DWORD PTR [esp+8], ebx
	mov	eax, DWORD PTR [ebp+8]
	mov	DWORD PTR [esp+4], eax
	mov	DWORD PTR [esp], edx
	call	___mingw_vfprintf
	mov	DWORD PTR [ebp-12], eax
	mov	eax, DWORD PTR [ebp-12]
	add	esp, 36
	pop	ebx
	pop	ebp
	ret
	.text
	.globl	_cfunc
	.def	_cfunc;	.scl	2;	.type	32;	.endef
_cfunc:
	push	ebp
	mov	ebp, esp
	mov	eax, DWORD PTR [ebp+8]
	sub	eax, DWORD PTR [ebp+12]
	pop	ebp
	ret
	.globl	_stdfunc@8
	.def	_stdfunc@8;	.scl	2;	.type	32;	.endef
_stdfunc@8:
	push	ebp
	mov	ebp, esp
	mov	eax, DWORD PTR [ebp+8]
	sub	eax, DWORD PTR [ebp+12]
	pop	ebp
	ret	8
	.section .rdata,"dr"
LC0:
	.ascii "cfunc: %d\12\0"
	.text
	.globl	_ccaller
	.def	_ccaller;	.scl	2;	.type	32;	.endef
_ccaller:
	push	ebp
	mov	ebp, esp
	sub	esp, 24
	mov	DWORD PTR [esp+4], 2
	mov	DWORD PTR [esp], 1
	call	_cfunc
	mov	DWORD PTR [esp+4], eax
	mov	DWORD PTR [esp], OFFSET FLAT:LC0
	call	__Z6printfPKcz
	nop
	leave
	ret
	.section .rdata,"dr"
LC1:
	.ascii "stdfunc: %d\12\0"
	.text
	.globl	_stdcaller
	.def	_stdcaller;	.scl	2;	.type	32;	.endef
_stdcaller:
	push	ebp
	mov	ebp, esp
	sub	esp, 24
	mov	DWORD PTR [esp+4], 4
	mov	DWORD PTR [esp], 3
	call	_stdfunc@8
	sub	esp, 8
	mov	DWORD PTR [esp+4], eax
	mov	DWORD PTR [esp], OFFSET FLAT:LC1
	call	__Z6printfPKcz
	nop
	leave
	ret
	.def	___main;	.scl	2;	.type	32;	.endef
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	push	ebp
	mov	ebp, esp
	and	esp, -16
	call	___main
	call	_ccaller
	call	_stdcaller
	mov	eax, 0
	leave
	ret
	.ident	"GCC: (RosBE-Windows) 8.4.0"
	.def	___mingw_vfprintf;	.scl	2;	.type	32;	.endef
