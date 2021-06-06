	.text
	.file	"main"
	.globl	main
	.p2align	4, 0x90
	.type	main,@function
main:
	.cfi_startproc
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$27, a(%rip)
	movl	$12, b(%rip)
	movl	$27, %edi
	movl	$12, %esi
	callq	gcd
	movl	%eax, c(%rip)
	movl	$.L__unnamed_1, %edi
	movl	$__unnamed_2, %esi
	xorl	%eax, %eax
	callq	printf
	movl	c(%rip), %esi
	movl	$.L__unnamed_3, %edi
	xorl	%eax, %eax
	callq	printf
	movl	$.L__unnamed_4, %edi
	xorl	%eax, %eax
	callq	printf
	xorl	%eax, %eax
	popq	%rcx
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc

	.globl	gcd
	.p2align	4, 0x90
	.type	gcd,@function
gcd:
	.cfi_startproc
	subq	$24, %rsp
	.cfi_def_cfa_offset 32
	movl	%edi, 16(%rsp)
	movl	%esi, 20(%rsp)
	testl	%esi, %esi
	je	.LBB1_1
	movl	20(%rsp), %edi
	movl	16(%rsp), %eax
	cltd
	idivl	%edi
	movl	%edx, %esi
	callq	gcd
	jmp	.LBB1_3
.LBB1_1:
	movl	16(%rsp), %eax
.LBB1_3:
	movl	%eax, 12(%rsp)
	movl	12(%rsp), %eax
	addq	$24, %rsp
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end1:
	.size	gcd, .Lfunc_end1-gcd
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
	.p2align	2
b:
	.long	0
	.size	b, 4

	.type	c,@object
	.globl	c
	.p2align	2
c:
	.long	0
	.size	c, 4

	.type	d,@object
	.globl	d
	.p2align	3
d:
	.quad	0
	.size	d, 8

	.type	e,@object
	.globl	e
	.p2align	3
e:
	.quad	0
	.size	e, 8

	.type	f,@object
	.globl	f
f:
	.byte	0
	.size	f, 1

	.type	__unnamed_2,@object
	.section	.rodata,"a",@progbits
	.globl	__unnamed_2
__unnamed_2:
	.asciz	"gcd="
	.size	__unnamed_2, 5

	.type	.L__unnamed_1,@object
	.section	.rodata.str1.1,"aMS",@progbits,1
.L__unnamed_1:
	.asciz	"%s"
	.size	.L__unnamed_1, 3

	.type	.L__unnamed_3,@object
.L__unnamed_3:
	.asciz	"%d"
	.size	.L__unnamed_3, 3

	.type	.L__unnamed_4,@object
.L__unnamed_4:
	.asciz	"\n"
	.size	.L__unnamed_4, 2


	.section	".note.GNU-stack","",@progbits
