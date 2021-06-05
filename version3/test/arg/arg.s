	.text
	.file	"main"
	.section	.rodata.cst8,"aM",@progbits,8
	.p2align	3
.LCPI0_0:
	.quad	4607182418800017408
	.text
	.globl	main
	.p2align	4, 0x90
	.type	main,@function
main:
	.cfi_startproc
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$2, i(%rip)
	movabsq	$4609164002636060426, %rax
	movq	%rax, r(%rip)
	movl	$1, %edi
	callq	test1
	movsd	r(%rip), %xmm0
	callq	test2
	movl	i(%rip), %edi
	callq	test1
	xorps	%xmm0, %xmm0
	cvtsi2sdl	i(%rip), %xmm0
	callq	test2
	movl	$1, %edi
	callq	test1
	movsd	.LCPI0_0(%rip), %xmm0
	callq	test2
	movl	$99, %edi
	callq	test3
	xorl	%eax, %eax
	popq	%rcx
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc

	.globl	test1
	.p2align	4, 0x90
	.type	test1,@function
test1:
	.cfi_startproc
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	%edi, %esi
	movl	%edi, 4(%rsp)
	movl	$.L__unnamed_1, %edi
	xorl	%eax, %eax
	callq	printf
	movl	$.L__unnamed_2, %edi
	xorl	%eax, %eax
	callq	printf
	popq	%rax
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end1:
	.size	test1, .Lfunc_end1-test1
	.cfi_endproc

	.globl	test2
	.p2align	4, 0x90
	.type	test2,@function
test2:
	.cfi_startproc
	pushq	%rax
	.cfi_def_cfa_offset 16
	movsd	%xmm0, (%rsp)
	xorps	%xmm1, %xmm1
	ucomisd	%xmm1, %xmm0
	jb	.LBB2_2
	sqrtsd	%xmm0, %xmm0
	jmp	.LBB2_3
.LBB2_2:
	callq	sqrt
.LBB2_3:
	movl	$.L__unnamed_3, %edi
	movb	$1, %al
	callq	printf
	movl	$.L__unnamed_4, %edi
	xorl	%eax, %eax
	callq	printf
	popq	%rax
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end2:
	.size	test2, .Lfunc_end2-test2
	.cfi_endproc

	.globl	test3
	.p2align	4, 0x90
	.type	test3,@function
test3:
	.cfi_startproc
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	%edi, %esi
	movb	%sil, 7(%rsp)
	movl	$.L__unnamed_5, %edi
	xorl	%eax, %eax
	callq	printf
	movl	$.L__unnamed_6, %edi
	xorl	%eax, %eax
	callq	printf
	popq	%rax
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end3:
	.size	test3, .Lfunc_end3-test3
	.cfi_endproc

	.type	__tmp_str,@object
	.bss
	.globl	__tmp_str
	.p2align	4
__tmp_str:
	.zero	256
	.size	__tmp_str, 256

	.type	i,@object
	.globl	i
	.p2align	2
i:
	.long	0
	.size	i, 4

	.type	r,@object
	.globl	r
	.p2align	3
r:
	.quad	0
	.size	r, 8

	.type	.L__unnamed_1,@object
	.section	.rodata.str1.1,"aMS",@progbits,1
.L__unnamed_1:
	.asciz	"%d"
	.size	.L__unnamed_1, 3

	.type	.L__unnamed_2,@object
.L__unnamed_2:
	.asciz	"\n"
	.size	.L__unnamed_2, 2

	.type	.L__unnamed_3,@object
.L__unnamed_3:
	.asciz	"%f"
	.size	.L__unnamed_3, 3

	.type	.L__unnamed_4,@object
.L__unnamed_4:
	.asciz	"\n"
	.size	.L__unnamed_4, 2

	.type	.L__unnamed_5,@object
.L__unnamed_5:
	.asciz	"%c"
	.size	.L__unnamed_5, 3

	.type	.L__unnamed_6,@object
.L__unnamed_6:
	.asciz	"\n"
	.size	.L__unnamed_6, 2


	.section	".note.GNU-stack","",@progbits
