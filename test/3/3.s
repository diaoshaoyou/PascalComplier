	.text
	.file	"main"
	.section	.rodata.cst8,"aM",@progbits,8
	.p2align	3
.LCPI0_0:
	.quad	-4616189618054758400
.LCPI0_1:
	.quad	4611686018427387904
	.text
	.globl	main
	.p2align	4, 0x90
	.type	main,@function
main:
	.cfi_startproc
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$.L__unnamed_1, %edi
	movl	$__unnamed_2, %esi
	xorl	%eax, %eax
	callq	printf
	movl	$-1, %edi
	callq	abs
	movl	$.L__unnamed_3, %edi
	movl	%eax, %esi
	xorl	%eax, %eax
	callq	printf
	movl	$.L__unnamed_4, %edi
	xorl	%eax, %eax
	callq	printf
	movl	$.L__unnamed_5, %edi
	movl	$__unnamed_6, %esi
	xorl	%eax, %eax
	callq	printf
	movsd	.LCPI0_0(%rip), %xmm0
	callq	fabs
	movl	$.L__unnamed_7, %edi
	movb	$1, %al
	callq	printf
	movl	$.L__unnamed_8, %edi
	xorl	%eax, %eax
	callq	printf
	movl	$.L__unnamed_9, %edi
	movl	$__unnamed_10, %esi
	xorl	%eax, %eax
	callq	printf
	movsd	.LCPI0_1(%rip), %xmm0
	sqrtsd	%xmm0, %xmm0
	movl	$.L__unnamed_11, %edi
	movb	$1, %al
	callq	printf
	movl	$.L__unnamed_12, %edi
	xorl	%eax, %eax
	callq	printf
	movl	$.L__unnamed_13, %edi
	movl	$__unnamed_14, %esi
	xorl	%eax, %eax
	callq	printf
	movl	$.L__unnamed_15, %edi
	movl	$65, %esi
	xorl	%eax, %eax
	callq	printf
	movl	$.L__unnamed_16, %edi
	xorl	%eax, %eax
	callq	printf
	movl	$.L__unnamed_17, %edi
	movl	$__unnamed_18, %esi
	xorl	%eax, %eax
	callq	printf
	movl	$.L__unnamed_19, %edi
	movl	$65, %esi
	xorl	%eax, %eax
	callq	printf
	movl	$.L__unnamed_20, %edi
	xorl	%eax, %eax
	callq	printf
	movl	$.L__unnamed_21, %edi
	movl	$__unnamed_22, %esi
	xorl	%eax, %eax
	callq	printf
	movl	$.L__unnamed_23, %edi
	movl	$66, %esi
	xorl	%eax, %eax
	callq	printf
	movl	$.L__unnamed_24, %edi
	xorl	%eax, %eax
	callq	printf
	movl	$.L__unnamed_25, %edi
	movl	$__unnamed_26, %esi
	xorl	%eax, %eax
	callq	printf
	movl	$.L__unnamed_27, %edi
	movl	$89, %esi
	xorl	%eax, %eax
	callq	printf
	movl	$.L__unnamed_28, %edi
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

	.type	ss,@object
	.section	.rodata,"a",@progbits
	.globl	ss
ss:
	.asciz	"wow"
	.size	ss, 4

	.type	a,@object
	.bss
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
c:
	.byte	0
	.size	c, 1

	.type	s,@object
	.globl	s
	.p2align	4
s:
	.zero	256
	.size	s, 256

	.type	__unnamed_2,@object
	.section	.rodata,"a",@progbits
	.globl	__unnamed_2
__unnamed_2:
	.asciz	"abs(-1): "
	.size	__unnamed_2, 10

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

	.type	__unnamed_6,@object
	.section	.rodata,"a",@progbits
	.globl	__unnamed_6
__unnamed_6:
	.asciz	"abs(-1.0): "
	.size	__unnamed_6, 12

	.type	.L__unnamed_5,@object
	.section	.rodata.str1.1,"aMS",@progbits,1
.L__unnamed_5:
	.asciz	"%s"
	.size	.L__unnamed_5, 3

	.type	.L__unnamed_7,@object
.L__unnamed_7:
	.asciz	"%f"
	.size	.L__unnamed_7, 3

	.type	.L__unnamed_8,@object
.L__unnamed_8:
	.asciz	"\n"
	.size	.L__unnamed_8, 2

	.type	__unnamed_10,@object
	.section	.rodata,"a",@progbits
	.globl	__unnamed_10
__unnamed_10:
	.asciz	"sqrt(2): "
	.size	__unnamed_10, 10

	.type	.L__unnamed_9,@object
	.section	.rodata.str1.1,"aMS",@progbits,1
.L__unnamed_9:
	.asciz	"%s"
	.size	.L__unnamed_9, 3

	.type	.L__unnamed_11,@object
.L__unnamed_11:
	.asciz	"%f"
	.size	.L__unnamed_11, 3

	.type	.L__unnamed_12,@object
.L__unnamed_12:
	.asciz	"\n"
	.size	.L__unnamed_12, 2

	.type	__unnamed_14,@object
	.section	.rodata,"a",@progbits
	.globl	__unnamed_14
__unnamed_14:
	.asciz	"chr(65): "
	.size	__unnamed_14, 10

	.type	.L__unnamed_13,@object
	.section	.rodata.str1.1,"aMS",@progbits,1
.L__unnamed_13:
	.asciz	"%s"
	.size	.L__unnamed_13, 3

	.type	.L__unnamed_15,@object
.L__unnamed_15:
	.asciz	"%c"
	.size	.L__unnamed_15, 3

	.type	.L__unnamed_16,@object
.L__unnamed_16:
	.asciz	"\n"
	.size	.L__unnamed_16, 2

	.type	__unnamed_18,@object
	.section	.rodata,"a",@progbits
	.globl	__unnamed_18
__unnamed_18:
	.asciz	"ord(A): "
	.size	__unnamed_18, 9

	.type	.L__unnamed_17,@object
	.section	.rodata.str1.1,"aMS",@progbits,1
.L__unnamed_17:
	.asciz	"%s"
	.size	.L__unnamed_17, 3

	.type	.L__unnamed_19,@object
.L__unnamed_19:
	.asciz	"%d"
	.size	.L__unnamed_19, 3

	.type	.L__unnamed_20,@object
.L__unnamed_20:
	.asciz	"\n"
	.size	.L__unnamed_20, 2

	.type	__unnamed_22,@object
	.section	.rodata,"a",@progbits
	.globl	__unnamed_22
__unnamed_22:
	.asciz	"succ(A): "
	.size	__unnamed_22, 10

	.type	.L__unnamed_21,@object
	.section	.rodata.str1.1,"aMS",@progbits,1
.L__unnamed_21:
	.asciz	"%s"
	.size	.L__unnamed_21, 3

	.type	.L__unnamed_23,@object
.L__unnamed_23:
	.asciz	"%c"
	.size	.L__unnamed_23, 3

	.type	.L__unnamed_24,@object
.L__unnamed_24:
	.asciz	"\n"
	.size	.L__unnamed_24, 2

	.type	__unnamed_26,@object
	.section	.rodata,"a",@progbits
	.globl	__unnamed_26
__unnamed_26:
	.asciz	"pred(Z): "
	.size	__unnamed_26, 10

	.type	.L__unnamed_25,@object
	.section	.rodata.str1.1,"aMS",@progbits,1
.L__unnamed_25:
	.asciz	"%s"
	.size	.L__unnamed_25, 3

	.type	.L__unnamed_27,@object
.L__unnamed_27:
	.asciz	"%c"
	.size	.L__unnamed_27, 3

	.type	.L__unnamed_28,@object
.L__unnamed_28:
	.asciz	"\n"
	.size	.L__unnamed_28, 2


	.section	".note.GNU-stack","",@progbits
