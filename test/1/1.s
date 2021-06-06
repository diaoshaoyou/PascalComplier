	.text
	.file	"main"
	.globl	main
	.p2align	4, 0x90
	.type	main,@function
main:
	.cfi_startproc
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$101, i(%rip)
	movl	$.L__unnamed_1, %edi
	movl	$101, %esi
	xorl	%eax, %eax
	callq	printf
	movl	$.L__unnamed_2, %edi
	xorl	%eax, %eax
	callq	printf
	cmpl	$99, i(%rip)
	jg	.LBB0_2
	movl	$.L__unnamed_3, %edi
	movl	$__unnamed_4, %esi
	xorl	%eax, %eax
	callq	printf
	movl	$.L__unnamed_5, %edi
	jmp	.LBB0_3
.LBB0_2:
	movl	$.L__unnamed_6, %edi
	movl	$__unnamed_7, %esi
	xorl	%eax, %eax
	callq	printf
	movl	$.L__unnamed_8, %edi
.LBB0_3:
	xorl	%eax, %eax
	callq	printf
	movl	$1, i(%rip)
	cmpl	$9, i(%rip)
	jg	.LBB0_6
	.p2align	4, 0x90
.LBB0_5:
	movl	i(%rip), %esi
	movl	$.L__unnamed_9, %edi
	xorl	%eax, %eax
	callq	printf
	incl	i(%rip)
	cmpl	$9, i(%rip)
	jle	.LBB0_5
.LBB0_6:
	movl	$.L__unnamed_10, %edi
	xorl	%eax, %eax
	callq	printf
	xorl	%eax, %eax
	popq	%rcx
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
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

	.type	.L__unnamed_1,@object
	.section	.rodata.str1.1,"aMS",@progbits,1
.L__unnamed_1:
	.asciz	"%d"
	.size	.L__unnamed_1, 3

	.type	.L__unnamed_2,@object
.L__unnamed_2:
	.asciz	"\n"
	.size	.L__unnamed_2, 2

	.type	__unnamed_4,@object
	.section	.rodata,"a",@progbits
	.globl	__unnamed_4
__unnamed_4:
	.asciz	"i < 100"
	.size	__unnamed_4, 8

	.type	.L__unnamed_3,@object
	.section	.rodata.str1.1,"aMS",@progbits,1
.L__unnamed_3:
	.asciz	"%s"
	.size	.L__unnamed_3, 3

	.type	.L__unnamed_5,@object
.L__unnamed_5:
	.asciz	"\n"
	.size	.L__unnamed_5, 2

	.type	__unnamed_7,@object
	.section	.rodata,"a",@progbits
	.globl	__unnamed_7
__unnamed_7:
	.asciz	"i >= 100"
	.size	__unnamed_7, 9

	.type	.L__unnamed_6,@object
	.section	.rodata.str1.1,"aMS",@progbits,1
.L__unnamed_6:
	.asciz	"%s"
	.size	.L__unnamed_6, 3

	.type	.L__unnamed_8,@object
.L__unnamed_8:
	.asciz	"\n"
	.size	.L__unnamed_8, 2

	.type	.L__unnamed_9,@object
.L__unnamed_9:
	.asciz	"%d"
	.size	.L__unnamed_9, 3

	.type	.L__unnamed_10,@object
.L__unnamed_10:
	.asciz	"\n"
	.size	.L__unnamed_10, 2


	.section	".note.GNU-stack","",@progbits
