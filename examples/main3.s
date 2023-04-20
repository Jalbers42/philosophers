	.file	"main3.c"
	.text
	.globl	g
	.bss
	.align 4
	.type	g, @object
	.size	g, 4
g:
	.zero	4
	.section	.rodata
	.align 8
.LC0:
	.string	"Thread ID: %d, Static: %d, Global: %d\n"
	.text
	.globl	myThreadFun
	.type	myThreadFun, @function
myThreadFun:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, -12(%rbp)
	movl	s.0(%rip), %eax
	addl	$1, %eax
	movl	%eax, s.0(%rip)
	movl	g(%rip), %eax
	addl	$1, %eax
	movl	%eax, g(%rip)
	movl	g(%rip), %ecx
	movl	s.0(%rip), %edx
	movl	-12(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %edi
	call	pthread_exit@PLT
	.cfi_endproc
.LFE6:
	.size	myThreadFun, .-myThreadFun
	.section	.rodata
.LC1:
	.string	"ERROR"
	.text
	.globl	main
	.type	main, @function
main:
.LFB7:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$80, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, -72(%rbp)
	jmp	.L3
.L5:
	movl	-72(%rbp), %eax
	cltq
	movl	-72(%rbp), %edx
	movl	%edx, -32(%rbp,%rax,8)
	movl	-72(%rbp), %eax
	cltq
	movl	-72(%rbp), %edx
	movl	%edx, -28(%rbp,%rax,8)
	leaq	-32(%rbp), %rdx
	movl	-72(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	%rax, %rdx
	leaq	-64(%rbp), %rcx
	movl	-72(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	%rcx, %rax
	movq	%rdx, %rcx
	leaq	myThreadFun(%rip), %rdx
	movl	$0, %esi
	movq	%rax, %rdi
	call	pthread_create@PLT
	testl	%eax, %eax
	je	.L4
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
.L4:
	addl	$1, -72(%rbp)
.L3:
	cmpl	$2, -72(%rbp)
	jle	.L5
	movl	$0, -68(%rbp)
	jmp	.L6
.L7:
	movl	-68(%rbp), %eax
	cltq
	movq	-64(%rbp,%rax,8), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	call	pthread_join@PLT
	addl	$1, -68(%rbp)
.L6:
	cmpl	$2, -68(%rbp)
	jle	.L7
	movl	$0, %eax
	movq	-8(%rbp), %rsi
	subq	%fs:40, %rsi
	je	.L9
	call	__stack_chk_fail@PLT
.L9:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	main, .-main
	.local	s.0
	.comm	s.0,4,4
	.ident	"GCC: (Ubuntu 10.4.0-4ubuntu1~22.04) 10.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
