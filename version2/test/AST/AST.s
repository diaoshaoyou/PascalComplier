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
	movl	$__unnamed_2, %esi
	xorl	%eax, %eax
	callq	printf
	movl	$.L__unnamed_3, %edi
	xorl	%eax, %eax
	callq	printf
	movl	$0, i(%rip)
	movl	$.L__unnamed_4, %edi
	xorl	%esi, %esi
	xorl	%eax, %eax
	callq	printf
	incl	i(%rip)
	movl	$.L__unnamed_5, %edi
	xorl	%eax, %eax
	callq	printf
	movl	$.L__unnamed_6, %edi
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

	.type	__unnamed_2,@object
	.section	.rodata,"a",@progbits
	.globl	__unnamed_2
__unnamed_2:
	.asciz	"x < y"
	.size	__unnamed_2, 6

	.type	.L__unnamed_1,@object
	.section	.rodata.str1.1,"aMS",@progbits,1
.L__unnamed_1:
	.asciz	"%s"
	.size	.L__unnamed_1, 3

	.type	.L__unnamed_3,@object
.L__unnamed_3:
	.asciz	"\n"
	.size	.L__unnamed_3, 2

	.type	__unnamed_7,@object
	.section	.rodata,"a",@progbits
	.globl	__unnamed_7
__unnamed_7:
	.asciz	"x >= y"
	.size	__unnamed_7, 7

	.type	.L__unnamed_8,@object
	.section	.rodata.str1.1,"aMS",@progbits,1
.L__unnamed_8:
	.asciz	"%s"
	.size	.L__unnamed_8, 3

	.type	.L__unnamed_9,@object
.L__unnamed_9:
	.asciz	"\n"
	.size	.L__unnamed_9, 2

	.type	.L__unnamed_4,@object
.L__unnamed_4:
	.asciz	"%d"
	.size	.L__unnamed_4, 3

	.type	.L__unnamed_5,@object
.L__unnamed_5:
	.asciz	"\n"
	.size	.L__unnamed_5, 2

	.type	.L__unnamed_10,@object
.L__unnamed_10:
	.asciz	"%d"
	.size	.L__unnamed_10, 3

	.type	.L__unnamed_6,@object
.L__unnamed_6:
	.asciz	"\n"
	.size	.L__unnamed_6, 2


	.section	".note.GNU-stack","",@progbits
