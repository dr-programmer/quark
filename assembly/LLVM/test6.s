	.text
	.file	"test6.ll"
	.globl	printINT                        # -- Begin function printINT
	.p2align	4, 0x90
	.type	printINT,@function
printINT:                               # @printINT
	.cfi_startproc
# %bb.0:                                # %.printINT_body
	pushq	%rbx
	.cfi_def_cfa_offset 16
	subq	$16, %rsp
	.cfi_def_cfa_offset 32
	.cfi_offset %rbx, -16
	movl	%edi, %ebx
	movl	%edi, 12(%rsp)
	movl	$680997, 7(%rsp)                # imm = 0xA6425
	leaq	7(%rsp), %rdi
	movl	%ebx, %esi
	xorl	%eax, %eax
	callq	printf@PLT
	movl	%ebx, %eax
	addq	$16, %rsp
	.cfi_def_cfa_offset 16
	popq	%rbx
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end0:
	.size	printINT, .Lfunc_end0-printINT
	.cfi_endproc
                                        # -- End function
	.globl	function                        # -- Begin function function
	.p2align	4, 0x90
	.type	function,@function
function:                               # @function
	.cfi_startproc
# %bb.0:                                # %.function_body
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	%edi, 4(%rsp)
	movl	%esi, (%rsp)
	addl	%esi, %edi
	callq	printINT@PLT
	movl	4(%rsp), %eax
	addl	(%rsp), %eax
	cmpl	$11, %eax
	jl	.LBB1_2
# %bb.1:                                # %.L0
	movl	4(%rsp), %eax
	addl	(%rsp), %eax
	popq	%rcx
	.cfi_def_cfa_offset 8
	retq
.LBB1_2:                                # %.L1
	.cfi_def_cfa_offset 16
	movl	4(%rsp), %edi
	incl	%edi
	movl	(%rsp), %esi
	incl	%esi
	callq	function@PLT
	popq	%rcx
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end1:
	.size	function, .Lfunc_end1-function
	.cfi_endproc
                                        # -- End function
	.globl	fibonachi                       # -- Begin function fibonachi
	.p2align	4, 0x90
	.type	fibonachi,@function
fibonachi:                              # @fibonachi
	.cfi_startproc
# %bb.0:                                # %.fibonachi_body
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	pushq	%r14
	pushq	%rbx
	subq	$16, %rsp
	.cfi_offset %rbx, -32
	.cfi_offset %r14, -24
	movl	%edi, -20(%rbp)
	cmpl	$1, %edi
	jg	.LBB2_3
# %bb.1:                                # %.L3
	movl	-20(%rbp), %ebx
	movq	%rsp, %rax
	leaq	-16(%rax), %rdi
	movq	%rdi, %rsp
	movl	$680997, -16(%rax)              # imm = 0xA6425
	movl	%ebx, %esi
	xorl	%eax, %eax
	callq	printf@PLT
	movl	%ebx, %eax
	jmp	.LBB2_2
.LBB2_3:                                # %.L4
	movl	-20(%rbp), %edi
	decl	%edi
	callq	fibonachi@PLT
	movl	%eax, %ebx
	movl	-20(%rbp), %edi
	addl	$-2, %edi
	callq	fibonachi@PLT
	movl	%eax, %r14d
	addl	%ebx, %r14d
	movq	%rsp, %rax
	leaq	-16(%rax), %rdi
	movq	%rdi, %rsp
	movl	$680997, -16(%rax)              # imm = 0xA6425
	movl	%r14d, %esi
	xorl	%eax, %eax
	callq	printf@PLT
	movl	%r14d, %eax
.LBB2_2:                                # %.L3
	leaq	-16(%rbp), %rsp
	popq	%rbx
	popq	%r14
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end2:
	.size	fibonachi, .Lfunc_end2-fibonachi
	.cfi_endproc
                                        # -- End function
	.section	.rodata.cst8,"aM",@progbits,8
	.p2align	3, 0x0                          # -- Begin function main
.LCPI3_0:
	.quad	0x4011333333333333              # double 4.2999999999999998
	.text
	.globl	main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:                                # %.main_body
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	$5, -4(%rbp)
	movl	$6, -8(%rbp)
	movb	$1, -9(%rbp)
	movb	$1, %al
	testb	%al, %al
	jne	.LBB3_2
# %bb.1:                                # %.L6
	movl	-8(%rbp), %eax
	addl	%eax, -4(%rbp)
	jmp	.LBB3_3
.LBB3_2:                                # %.L7
	movl	-8(%rbp), %eax
	subl	%eax, -4(%rbp)
.LBB3_3:                                # %.L8
	movq	%rsp, %rcx
	leaq	-16(%rcx), %rax
	movq	%rax, %rsp
	movl	$0, -16(%rcx)
	cmpl	$9, (%rax)
	jg	.LBB3_6
	.p2align	4, 0x90
.LBB3_5:                                # %.L10
                                        # =>This Inner Loop Header: Depth=1
	movl	(%rax), %ecx
	addl	%ecx, -4(%rbp)
	incl	(%rax)
	cmpl	$9, (%rax)
	jle	.LBB3_5
.LBB3_6:                                # %.L11
	movl	$3, -4(%rbp)
	movq	%rsp, %rax
	leaq	-16(%rax), %rsp
	movabsq	$4616527388026811187, %rcx      # imm = 0x4011333333333333
	movq	%rcx, -16(%rax)
	cvtsi2sdl	-4(%rbp), %xmm0
	addsd	.LCPI3_0(%rip), %xmm0
	movsd	%xmm0, -16(%rax)
	movl	-4(%rbp), %esi
	movq	y@GOTPCREL(%rip), %rax
	movl	%esi, (%rax)
	movq	x@GOTPCREL(%rip), %rax
	movl	(%rax), %edi
	movl	%esi, %eax
	subl	%edi, %eax
	movl	%eax, -4(%rbp)
	callq	function@PLT
	movl	%eax, -8(%rbp)
	movl	%eax, %edi
	callq	printINT@PLT
	movl	-8(%rbp), %edi
	callq	printINT@PLT
	movl	-4(%rbp), %eax
	leal	-1(%rax,%rax,2), %edi
	movl	%edi, -8(%rbp)
	callq	printINT@PLT
	movl	$3, -4(%rbp)
	movl	$3, %edi
	callq	printINT@PLT
	movl	$0, -4(%rbp)
	xorl	%edi, %edi
	callq	fibonachi@PLT
	movl	-8(%rbp), %eax
	movq	%rbp, %rsp
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end3:
	.size	main, .Lfunc_end3-main
	.cfi_endproc
                                        # -- End function
	.type	.str,@object                    # @.str
	.section	.rodata,"a",@progbits
	.globl	.str
.str:
	.asciz	"%d\n"
	.size	.str, 4

	.type	x,@object                       # @x
	.data
	.globl	x
	.p2align	2, 0x0
x:
	.long	3                               # 0x3
	.size	x, 4

	.type	y,@object                       # @y
	.globl	y
	.p2align	2, 0x0
y:
	.long	6                               # 0x6
	.size	y, 4

	.section	".note.GNU-stack","",@progbits
