	.text
	.file	"main"
	.globl	main
	.p2align	4, 0x90
	.type	main,@function
main:
	.cfi_startproc
	xorl	%eax, %eax
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc

	.globl	f1
	.p2align	4, 0x90
	.type	f1,@function
f1:
	.cfi_startproc
	subq	$1172, %rsp
	.cfi_def_cfa_offset 1180
	movl	%edi, -128(%rsp)
	addq	$1172, %rsp
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end1:
	.size	f1, .Lfunc_end1-f1
	.cfi_endproc

	.globl	f2
	.p2align	4, 0x90
	.type	f2,@function
f2:
	.cfi_startproc
	subq	$424, %rsp
	.cfi_def_cfa_offset 432
	andl	$1, %edi
	movb	%dil, -121(%rsp)
	addq	$424, %rsp
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end2:
	.size	f2, .Lfunc_end2-f2
	.cfi_endproc

	.type	__tmp_str,@object
	.bss
	.globl	__tmp_str
	.p2align	4
__tmp_str:
	.zero	256
	.size	__tmp_str, 256

	.type	a,@object
	.globl	a
	.p2align	2
a:
	.long	0
	.size	a, 4

	.type	b,@object
	.globl	b
	.p2align	3
b:
	.quad	0
	.size	b, 8

	.type	c,@object
	.globl	c
c:
	.byte	0
	.size	c, 1

	.type	d,@object
	.globl	d
	.p2align	2
d:
	.long	0
	.size	d, 4

	.type	e,@object
	.globl	e
	.p2align	4
e:
	.zero	256
	.size	e, 256

	.type	f,@object
	.globl	f
f:
	.byte	0
	.size	f, 1


	.section	".note.GNU-stack","",@progbits
