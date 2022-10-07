	.file	"hello14.cpp"
	.intel_syntax noprefix
	.text
	.section	.text$_Z6printfPKcz,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	__Z6printfPKcz
	.def	__Z6printfPKcz;	.scl	2;	.type	32;	.endef
__Z6printfPKcz:
	push	ebp
	mov	ebp, esp
	push	ebx
	lea	ebx, [ebp+12]
	sub	esp, 20
	mov	DWORD PTR [esp], 1
	call	[DWORD PTR __imp____acrt_iob_func]
	mov	edx, DWORD PTR [ebp+8]
	mov	DWORD PTR [esp+8], ebx
	mov	DWORD PTR [esp], eax
	mov	DWORD PTR [esp+4], edx
	call	___mingw_vfprintf
	add	esp, 20
	pop	ebx
	pop	ebp
	ret
	.section .rdata,"dr"
LC0:
	.ascii "---\12\0"
	.align 4
LC1:
	.ascii "%p(%d): pNode %p, value %d, pNext %p\12\0"
	.text
	.p2align 4,,15
	.globl	_printAllNodes@4
	.def	_printAllNodes@4;	.scl	2;	.type	32;	.endef
_printAllNodes@4:
	push	ebp
	mov	ebp, esp
	push	edi
	push	esi
	push	ebx
	sub	esp, 44
	mov	edi, DWORD PTR [ebp+8]
	mov	DWORD PTR [esp], OFFSET FLAT:LC0
	call	__Z6printfPKcz
	test	edi, edi
	je	L4
	mov	ebx, edi
	xor	esi, esi
	.p2align 4,,10
L6:
	mov	eax, DWORD PTR [ebx]
	mov	DWORD PTR [esp+20], eax
	mov	eax, DWORD PTR [ebx+4]
	mov	DWORD PTR [esp+12], ebx
	mov	DWORD PTR [esp+8], esi
	add	esi, 1
	mov	DWORD PTR [esp+16], eax
	mov	DWORD PTR [esp+4], edi
	mov	DWORD PTR [esp], OFFSET FLAT:LC1
	call	__Z6printfPKcz
	mov	ebx, DWORD PTR [ebx]
	test	ebx, ebx
	jne	L6
L4:
	add	esp, 44
	pop	ebx
	pop	esi
	pop	edi
	pop	ebp
	ret	4
	.p2align 4,,15
	.globl	_addNode
	.def	_addNode;	.scl	2;	.type	32;	.endef
_addNode:
	push	ebp
	mov	ebp, esp
	push	ebx
	sub	esp, 20
	mov	ebx, DWORD PTR [ebp+8]
	mov	DWORD PTR [esp], 8
	call	__Znwj
	mov	edx, DWORD PTR [ebp+12]
	mov	DWORD PTR [eax+4], edx
	mov	edx, DWORD PTR [ebx]
	mov	DWORD PTR [ebx], eax
	mov	DWORD PTR [eax], edx
	add	esp, 20
	mov	eax, 1
	pop	ebx
	pop	ebp
	ret
	.p2align 4,,15
	.globl	_findNode@8
	.def	_findNode@8;	.scl	2;	.type	32;	.endef
_findNode@8:
	push	ebp
	mov	ebp, esp
	mov	eax, DWORD PTR [ebp+8]
	mov	edx, DWORD PTR [ebp+12]
	test	eax, eax
	je	L15
	cmp	edx, DWORD PTR [eax+4]
	jne	L16
	jmp	L15
	.p2align 4,,10
L17:
	cmp	DWORD PTR [eax+4], edx
	je	L15
L16:
	mov	eax, DWORD PTR [eax]
	test	eax, eax
	jne	L17
L15:
	pop	ebp
	ret	8
	.p2align 4,,15
	.globl	_deleteNode@8
	.def	_deleteNode@8;	.scl	2;	.type	32;	.endef
_deleteNode@8:
	push	ebp
	mov	ebp, esp
	sub	esp, 24
	mov	ecx, DWORD PTR [ebp+12]
	test	ecx, ecx
	je	L22
	mov	eax, DWORD PTR [ebp+8]
	mov	edx, DWORD PTR [eax]
	test	edx, edx
	je	L24
	mov	eax, DWORD PTR [edx]
	cmp	ecx, eax
	jne	L26
	jmp	L40
	.p2align 4,,10
L38:
	mov	edx, DWORD PTR [eax]
	cmp	edx, ecx
	je	L25
	mov	eax, edx
L26:
	test	eax, eax
	jne	L38
L24:
	mov	DWORD PTR [esp+4], 8
	mov	DWORD PTR [esp], ecx
	call	__ZdlPvj
L22:
	leave
	ret	8
L40:
	mov	eax, edx
	.p2align 4,,10
L25:
	mov	edx, DWORD PTR [ecx]
	mov	DWORD PTR [eax], edx
	jmp	L24
	.p2align 4,,15
	.globl	_deleteAllNodes@4
	.def	_deleteAllNodes@4;	.scl	2;	.type	32;	.endef
_deleteAllNodes@4:
	push	ebp
	mov	ebp, esp
	push	esi
	push	ebx
	sub	esp, 16
	mov	esi, DWORD PTR [ebp+8]
	mov	eax, DWORD PTR [esi]
	test	eax, eax
	je	L42
	.p2align 4,,10
L43:
	mov	ebx, DWORD PTR [eax]
	mov	DWORD PTR [esp], eax
	mov	DWORD PTR [esp+4], 8
	call	__ZdlPvj
	mov	eax, ebx
	test	ebx, ebx
	jne	L43
L42:
	mov	DWORD PTR [esi], 0
	add	esp, 16
	pop	ebx
	pop	esi
	pop	ebp
	ret	4
	.def	___main;	.scl	2;	.type	32;	.endef
	.section	.text.startup,"x"
	.p2align 4,,15
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	lea	ecx, [esp+4]
	and	esp, -16
	push	DWORD PTR [ecx-4]
	push	ebp
	mov	ebp, esp
	push	ebx
	push	ecx
	sub	esp, 16
	call	___main
	mov	eax, DWORD PTR _g_pHead
	mov	DWORD PTR [esp], eax
	call	_printAllNodes@4
	sub	esp, 4
	mov	DWORD PTR [esp], 8
	call	__Znwj
	mov	edx, DWORD PTR _g_pHead
	mov	DWORD PTR [eax+4], 123
	mov	DWORD PTR [eax], edx
	mov	DWORD PTR [esp], eax
	mov	DWORD PTR _g_pHead, eax
	call	_printAllNodes@4
	sub	esp, 4
	mov	DWORD PTR [esp], 8
	call	__Znwj
	mov	edx, DWORD PTR _g_pHead
	mov	DWORD PTR [eax+4], 456
	mov	DWORD PTR [eax], edx
	mov	DWORD PTR [esp], eax
	mov	DWORD PTR _g_pHead, eax
	call	_printAllNodes@4
	mov	eax, DWORD PTR _g_pHead
	sub	esp, 4
	mov	DWORD PTR [esp], eax
	call	_printAllNodes@4
	sub	esp, 4
	mov	DWORD PTR [esp], 8
	call	__Znwj
	mov	edx, DWORD PTR _g_pHead
	mov	DWORD PTR [eax+4], 789
	mov	DWORD PTR [eax], edx
	mov	DWORD PTR [esp], eax
	mov	DWORD PTR _g_pHead, eax
	call	_printAllNodes@4
	sub	esp, 4
	mov	DWORD PTR [esp], 8
	call	__Znwj
	mov	edx, DWORD PTR _g_pHead
	mov	DWORD PTR [eax+4], 555
	mov	DWORD PTR [eax], edx
	mov	DWORD PTR [esp], eax
	mov	DWORD PTR _g_pHead, eax
	call	_printAllNodes@4
	mov	eax, DWORD PTR _g_pHead
	sub	esp, 4
	test	eax, eax
	je	L50
	.p2align 4,,10
L51:
	mov	ebx, DWORD PTR [eax]
	mov	DWORD PTR [esp], eax
	mov	DWORD PTR [esp+4], 8
	call	__ZdlPvj
	mov	eax, ebx
	test	ebx, ebx
	jne	L51
L50:
	mov	DWORD PTR [esp], 0
	mov	DWORD PTR _g_pHead, 0
	call	_printAllNodes@4
	xor	eax, eax
	sub	esp, 4
	lea	esp, [ebp-8]
	pop	ecx
	pop	ebx
	pop	ebp
	lea	esp, [ecx-4]
	ret
	.globl	_g_pHead
	.bss
	.align 4
_g_pHead:
	.space 4
	.ident	"GCC: (RosBE-Windows) 8.4.0"
	.def	___mingw_vfprintf;	.scl	2;	.type	32;	.endef
	.def	__Znwj;	.scl	2;	.type	32;	.endef
	.def	__ZdlPvj;	.scl	2;	.type	32;	.endef
