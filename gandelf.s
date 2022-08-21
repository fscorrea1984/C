	.file	"a.c"
	.text
	.globl	test
	.type	test, @function
test:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
#APP
# 9 "a.c" 1
	int3
# 0 "" 2
#NO_APP
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	test, .-test
	.globl	handler
	.type	handler, @function
handler:
.LFB1:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	addq	$40, %rax
	movq	%rax, -8(%rbp)
	leaq	test(%rip), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, 128(%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	handler, .-handler
	.section	.rodata
.LC0:
	.string	"waiting..."
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$160, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	handler(%rip), %rax
	movq	%rax, -160(%rbp)
	movl	$268435460, -24(%rbp)
	leaq	-160(%rbp), %rax
	movl	$0, %edx
	movq	%rax, %rsi
	movl	$14, %edi
	call	sigaction@PLT
	movl	$3, %edi
	call	alarm@PLT
.L4:
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
	movl	$1, %edi
	call	sleep@PLT
	jmp	.L4
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0"
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
