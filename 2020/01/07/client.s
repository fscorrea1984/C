	.file	"client.c"
	.text
.Ltext0:
	.section	.rodata
.LC0:
	.string	"usage: client hostname"
.LC1:
	.string	"The socket was created"
	.align 8
.LC2:
	.string	"The socket was not created: %d\n"
.LC3:
	.string	"gethostbyname"
.LC4:
	.string	"Connect error"
.LC5:
	.string	"Connected"
.LC6:
	.string	"GET /\r\n"
.LC7:
	.string	"ret = %d\n"
.LC8:
	.string	"Send failed"
	.text
	.globl	main
	.type	main, @function
main:
.LFB5:
	.file 1 "client.c"
	.loc 1 13 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$2128, %rsp
	movl	%edi, -2116(%rbp)
	movq	%rsi, -2128(%rbp)
	.loc 1 13 0
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	.loc 1 18 0
	cmpl	$2, -2116(%rbp)
	je	.L2
	.loc 1 19 0
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$22, %edx
	movl	$1, %esi
	leaq	.LC0(%rip), %rdi
	call	fwrite@PLT
	.loc 1 20 0
	movl	$1, %edi
	call	exit@PLT
.L2:
	.loc 1 23 0
	movl	$1, -2100(%rbp)
	.loc 1 29 0
	movl	$6, %edx
	movl	$1, %esi
	movl	$2, %edi
	call	socket@PLT
	movl	%eax, -2096(%rbp)
	cmpl	$0, -2096(%rbp)
	jle	.L3
	.loc 1 30 0
	leaq	.LC1(%rip), %rdi
	call	puts@PLT
	.loc 1 36 0
	leaq	-2100(%rbp), %rdx
	movl	-2096(%rbp), %eax
	movl	$4, %r8d
	movq	%rdx, %rcx
	movl	$1, %edx
	movl	$6, %esi
	movl	%eax, %edi
	call	setsockopt@PLT
	.loc 1 38 0
	movq	-2128(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	gethostbyname@PLT
	movq	%rax, -2088(%rbp)
	cmpq	$0, -2088(%rbp)
	jne	.L5
	jmp	.L12
.L3:
	.loc 1 32 0
	movl	-2096(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	.loc 1 33 0
	call	abort@PLT
.L12:
	.loc 1 39 0
	leaq	.LC3(%rip), %rdi
	call	herror@PLT
	.loc 1 40 0
	movl	$1, %eax
	jmp	.L10
.L5:
	.loc 1 49 0
	movq	-2088(%rbp), %rax
	movl	20(%rax), %eax
	.loc 1 49 0
	movslq	%eax, %rdx
	movq	-2088(%rbp), %rax
	movq	24(%rax), %rax
	movq	(%rax), %rax
	leaq	-2080(%rbp), %rcx
	addq	$4, %rcx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	bcopy@PLT
	.loc 1 52 0
	movw	$2, -2080(%rbp)
	.loc 1 53 0
	movl	$80, %edi
	call	htons@PLT
	movw	%ax, -2078(%rbp)
	.loc 1 57 0
	leaq	-2080(%rbp), %rax
	leaq	4(%rax), %rcx
	movl	-2096(%rbp), %eax
	movl	$16, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	connect@PLT
	testl	%eax, %eax
	jne	.L7
	.loc 1 58 0
	leaq	.LC4(%rip), %rdi
	call	puts@PLT
	.loc 1 59 0
	movl	$1, %eax
	jmp	.L10
.L7:
	.loc 1 62 0
	leaq	.LC5(%rip), %rdi
	call	puts@PLT
	.loc 1 79 0
	leaq	-2064(%rbp), %rax
	movabsq	$2829245824124231, %rcx
	movq	%rcx, (%rax)
	.loc 1 83 0
	movl	-2096(%rbp), %eax
	movl	$7, %edx
	leaq	.LC6(%rip), %rsi
	movl	%eax, %edi
	call	write@PLT
	movl	%eax, -2092(%rbp)
	.loc 1 85 0
	cmpl	$0, -2092(%rbp)
	jns	.L8
	.loc 1 86 0
	movl	-2092(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC7(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	.loc 1 87 0
	nop
.L9:
	.loc 1 92 0
	leaq	.LC8(%rip), %rdi
	call	puts@PLT
.L8:
	.loc 1 93 0
	movl	$1, %eax
.L10:
	.loc 1 108 0 discriminator 1
	movq	-8(%rbp), %rsi
	xorq	%fs:40, %rsi
	je	.L11
	.loc 1 108 0 is_stmt 0
	call	__stack_chk_fail@PLT
.L11:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	main, .-main
.Letext0:
	.file 2 "/usr/include/x86_64-linux-gnu/bits/types.h"
	.file 3 "/usr/include/x86_64-linux-gnu/bits/stdint-uintn.h"
	.file 4 "/usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h"
	.file 5 "/usr/include/x86_64-linux-gnu/bits/sockaddr.h"
	.file 6 "/usr/include/x86_64-linux-gnu/bits/socket.h"
	.file 7 "/usr/include/netinet/in.h"
	.file 8 "/usr/include/netdb.h"
	.file 9 "/usr/include/x86_64-linux-gnu/bits/libio.h"
	.file 10 "/usr/include/stdio.h"
	.file 11 "/usr/include/x86_64-linux-gnu/bits/sys_errlist.h"
	.file 12 "/usr/include/unistd.h"
	.file 13 "/usr/include/x86_64-linux-gnu/bits/getopt_core.h"
	.file 14 "/usr/include/x86_64-linux-gnu/bits/socket_type.h"
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	0x6d2
	.value	0x4
	.long	.Ldebug_abbrev0
	.byte	0x8
	.uleb128 0x1
	.long	.LASF132
	.byte	0xc
	.long	.LASF133
	.long	.LASF134
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.long	.Ldebug_line0
	.uleb128 0x2
	.byte	0x1
	.byte	0x8
	.long	.LASF0
	.uleb128 0x2
	.byte	0x2
	.byte	0x7
	.long	.LASF1
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.long	.LASF2
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.long	.LASF3
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.long	.LASF4
	.uleb128 0x3
	.long	.LASF6
	.byte	0x2
	.byte	0x25
	.long	0x2d
	.uleb128 0x2
	.byte	0x2
	.byte	0x5
	.long	.LASF5
	.uleb128 0x3
	.long	.LASF7
	.byte	0x2
	.byte	0x27
	.long	0x34
	.uleb128 0x4
	.byte	0x4
	.byte	0x5
	.string	"int"
	.uleb128 0x3
	.long	.LASF8
	.byte	0x2
	.byte	0x29
	.long	0x3b
	.uleb128 0x2
	.byte	0x8
	.byte	0x5
	.long	.LASF9
	.uleb128 0x3
	.long	.LASF10
	.byte	0x2
	.byte	0x8c
	.long	0x7f
	.uleb128 0x3
	.long	.LASF11
	.byte	0x2
	.byte	0x8d
	.long	0x7f
	.uleb128 0x5
	.byte	0x8
	.uleb128 0x6
	.byte	0x8
	.long	0xa4
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.long	.LASF12
	.uleb128 0x7
	.long	0xa4
	.uleb128 0x3
	.long	.LASF13
	.byte	0x3
	.byte	0x18
	.long	0x50
	.uleb128 0x3
	.long	.LASF14
	.byte	0x3
	.byte	0x19
	.long	0x62
	.uleb128 0x3
	.long	.LASF15
	.byte	0x3
	.byte	0x1a
	.long	0x74
	.uleb128 0x3
	.long	.LASF16
	.byte	0x4
	.byte	0xd8
	.long	0x42
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.long	.LASF17
	.uleb128 0x2
	.byte	0x8
	.byte	0x5
	.long	.LASF18
	.uleb128 0x8
	.long	.LASF135
	.byte	0x7
	.byte	0x4
	.long	0x3b
	.byte	0xe
	.byte	0x18
	.long	0x136
	.uleb128 0x9
	.long	.LASF19
	.byte	0x1
	.uleb128 0x9
	.long	.LASF20
	.byte	0x2
	.uleb128 0x9
	.long	.LASF21
	.byte	0x3
	.uleb128 0x9
	.long	.LASF22
	.byte	0x4
	.uleb128 0x9
	.long	.LASF23
	.byte	0x5
	.uleb128 0x9
	.long	.LASF24
	.byte	0x6
	.uleb128 0x9
	.long	.LASF25
	.byte	0xa
	.uleb128 0xa
	.long	.LASF26
	.long	0x80000
	.uleb128 0xb
	.long	.LASF27
	.value	0x800
	.byte	0
	.uleb128 0x3
	.long	.LASF28
	.byte	0x5
	.byte	0x1c
	.long	0x34
	.uleb128 0xc
	.long	.LASF32
	.byte	0x10
	.byte	0x6
	.byte	0xaf
	.long	0x166
	.uleb128 0xd
	.long	.LASF29
	.byte	0x6
	.byte	0xb1
	.long	0x136
	.byte	0
	.uleb128 0xd
	.long	.LASF30
	.byte	0x6
	.byte	0xb2
	.long	0x166
	.byte	0x2
	.byte	0
	.uleb128 0xe
	.long	0xa4
	.long	0x176
	.uleb128 0xf
	.long	0x42
	.byte	0xd
	.byte	0
	.uleb128 0x3
	.long	.LASF31
	.byte	0x7
	.byte	0x1e
	.long	0xc6
	.uleb128 0xc
	.long	.LASF33
	.byte	0x4
	.byte	0x7
	.byte	0x1f
	.long	0x19a
	.uleb128 0xd
	.long	.LASF34
	.byte	0x7
	.byte	0x21
	.long	0x176
	.byte	0
	.byte	0
	.uleb128 0x10
	.byte	0x7
	.byte	0x4
	.long	0x3b
	.byte	0x7
	.byte	0x29
	.long	0x245
	.uleb128 0x9
	.long	.LASF35
	.byte	0
	.uleb128 0x9
	.long	.LASF36
	.byte	0x1
	.uleb128 0x9
	.long	.LASF37
	.byte	0x2
	.uleb128 0x9
	.long	.LASF38
	.byte	0x4
	.uleb128 0x9
	.long	.LASF39
	.byte	0x6
	.uleb128 0x9
	.long	.LASF40
	.byte	0x8
	.uleb128 0x9
	.long	.LASF41
	.byte	0xc
	.uleb128 0x9
	.long	.LASF42
	.byte	0x11
	.uleb128 0x9
	.long	.LASF43
	.byte	0x16
	.uleb128 0x9
	.long	.LASF44
	.byte	0x1d
	.uleb128 0x9
	.long	.LASF45
	.byte	0x21
	.uleb128 0x9
	.long	.LASF46
	.byte	0x29
	.uleb128 0x9
	.long	.LASF47
	.byte	0x2e
	.uleb128 0x9
	.long	.LASF48
	.byte	0x2f
	.uleb128 0x9
	.long	.LASF49
	.byte	0x32
	.uleb128 0x9
	.long	.LASF50
	.byte	0x33
	.uleb128 0x9
	.long	.LASF51
	.byte	0x5c
	.uleb128 0x9
	.long	.LASF52
	.byte	0x5e
	.uleb128 0x9
	.long	.LASF53
	.byte	0x62
	.uleb128 0x9
	.long	.LASF54
	.byte	0x67
	.uleb128 0x9
	.long	.LASF55
	.byte	0x6c
	.uleb128 0x9
	.long	.LASF56
	.byte	0x84
	.uleb128 0x9
	.long	.LASF57
	.byte	0x88
	.uleb128 0x9
	.long	.LASF58
	.byte	0x89
	.uleb128 0x9
	.long	.LASF59
	.byte	0xff
	.uleb128 0xb
	.long	.LASF60
	.value	0x100
	.byte	0
	.uleb128 0x3
	.long	.LASF61
	.byte	0x7
	.byte	0x77
	.long	0xbb
	.uleb128 0x11
	.byte	0x10
	.byte	0x7
	.byte	0xd5
	.long	0x27a
	.uleb128 0x12
	.long	.LASF62
	.byte	0x7
	.byte	0xd7
	.long	0x27a
	.uleb128 0x12
	.long	.LASF63
	.byte	0x7
	.byte	0xd8
	.long	0x28a
	.uleb128 0x12
	.long	.LASF64
	.byte	0x7
	.byte	0xd9
	.long	0x29a
	.byte	0
	.uleb128 0xe
	.long	0xb0
	.long	0x28a
	.uleb128 0xf
	.long	0x42
	.byte	0xf
	.byte	0
	.uleb128 0xe
	.long	0xbb
	.long	0x29a
	.uleb128 0xf
	.long	0x42
	.byte	0x7
	.byte	0
	.uleb128 0xe
	.long	0xc6
	.long	0x2aa
	.uleb128 0xf
	.long	0x42
	.byte	0x3
	.byte	0
	.uleb128 0xc
	.long	.LASF65
	.byte	0x10
	.byte	0x7
	.byte	0xd3
	.long	0x2c3
	.uleb128 0xd
	.long	.LASF66
	.byte	0x7
	.byte	0xda
	.long	0x250
	.byte	0
	.byte	0
	.uleb128 0x7
	.long	0x2aa
	.uleb128 0x13
	.long	.LASF67
	.byte	0x7
	.byte	0xe3
	.long	0x2c3
	.uleb128 0x13
	.long	.LASF68
	.byte	0x7
	.byte	0xe4
	.long	0x2c3
	.uleb128 0xc
	.long	.LASF69
	.byte	0x10
	.byte	0x7
	.byte	0xed
	.long	0x31b
	.uleb128 0xd
	.long	.LASF70
	.byte	0x7
	.byte	0xef
	.long	0x136
	.byte	0
	.uleb128 0xd
	.long	.LASF71
	.byte	0x7
	.byte	0xf0
	.long	0x245
	.byte	0x2
	.uleb128 0xd
	.long	.LASF72
	.byte	0x7
	.byte	0xf1
	.long	0x181
	.byte	0x4
	.uleb128 0xd
	.long	.LASF73
	.byte	0x7
	.byte	0xf4
	.long	0x31b
	.byte	0x8
	.byte	0
	.uleb128 0xe
	.long	0x2d
	.long	0x32b
	.uleb128 0xf
	.long	0x42
	.byte	0x7
	.byte	0
	.uleb128 0x6
	.byte	0x8
	.long	0x9e
	.uleb128 0xc
	.long	.LASF74
	.byte	0x20
	.byte	0x8
	.byte	0x62
	.long	0x37a
	.uleb128 0xd
	.long	.LASF75
	.byte	0x8
	.byte	0x64
	.long	0x9e
	.byte	0
	.uleb128 0xd
	.long	.LASF76
	.byte	0x8
	.byte	0x65
	.long	0x32b
	.byte	0x8
	.uleb128 0xd
	.long	.LASF77
	.byte	0x8
	.byte	0x66
	.long	0x6d
	.byte	0x10
	.uleb128 0xd
	.long	.LASF78
	.byte	0x8
	.byte	0x67
	.long	0x6d
	.byte	0x14
	.uleb128 0xd
	.long	.LASF79
	.byte	0x8
	.byte	0x68
	.long	0x32b
	.byte	0x18
	.byte	0
	.uleb128 0xc
	.long	.LASF80
	.byte	0xd8
	.byte	0x9
	.byte	0xf5
	.long	0x4fa
	.uleb128 0xd
	.long	.LASF81
	.byte	0x9
	.byte	0xf6
	.long	0x6d
	.byte	0
	.uleb128 0xd
	.long	.LASF82
	.byte	0x9
	.byte	0xfb
	.long	0x9e
	.byte	0x8
	.uleb128 0xd
	.long	.LASF83
	.byte	0x9
	.byte	0xfc
	.long	0x9e
	.byte	0x10
	.uleb128 0xd
	.long	.LASF84
	.byte	0x9
	.byte	0xfd
	.long	0x9e
	.byte	0x18
	.uleb128 0xd
	.long	.LASF85
	.byte	0x9
	.byte	0xfe
	.long	0x9e
	.byte	0x20
	.uleb128 0xd
	.long	.LASF86
	.byte	0x9
	.byte	0xff
	.long	0x9e
	.byte	0x28
	.uleb128 0x14
	.long	.LASF87
	.byte	0x9
	.value	0x100
	.long	0x9e
	.byte	0x30
	.uleb128 0x14
	.long	.LASF88
	.byte	0x9
	.value	0x101
	.long	0x9e
	.byte	0x38
	.uleb128 0x14
	.long	.LASF89
	.byte	0x9
	.value	0x102
	.long	0x9e
	.byte	0x40
	.uleb128 0x14
	.long	.LASF90
	.byte	0x9
	.value	0x104
	.long	0x9e
	.byte	0x48
	.uleb128 0x14
	.long	.LASF91
	.byte	0x9
	.value	0x105
	.long	0x9e
	.byte	0x50
	.uleb128 0x14
	.long	.LASF92
	.byte	0x9
	.value	0x106
	.long	0x9e
	.byte	0x58
	.uleb128 0x14
	.long	.LASF93
	.byte	0x9
	.value	0x108
	.long	0x532
	.byte	0x60
	.uleb128 0x14
	.long	.LASF94
	.byte	0x9
	.value	0x10a
	.long	0x538
	.byte	0x68
	.uleb128 0x14
	.long	.LASF95
	.byte	0x9
	.value	0x10c
	.long	0x6d
	.byte	0x70
	.uleb128 0x14
	.long	.LASF96
	.byte	0x9
	.value	0x110
	.long	0x6d
	.byte	0x74
	.uleb128 0x14
	.long	.LASF97
	.byte	0x9
	.value	0x112
	.long	0x86
	.byte	0x78
	.uleb128 0x14
	.long	.LASF98
	.byte	0x9
	.value	0x116
	.long	0x34
	.byte	0x80
	.uleb128 0x14
	.long	.LASF99
	.byte	0x9
	.value	0x117
	.long	0x49
	.byte	0x82
	.uleb128 0x14
	.long	.LASF100
	.byte	0x9
	.value	0x118
	.long	0x53e
	.byte	0x83
	.uleb128 0x14
	.long	.LASF101
	.byte	0x9
	.value	0x11c
	.long	0x54e
	.byte	0x88
	.uleb128 0x14
	.long	.LASF102
	.byte	0x9
	.value	0x125
	.long	0x91
	.byte	0x90
	.uleb128 0x14
	.long	.LASF103
	.byte	0x9
	.value	0x12d
	.long	0x9c
	.byte	0x98
	.uleb128 0x14
	.long	.LASF104
	.byte	0x9
	.value	0x12e
	.long	0x9c
	.byte	0xa0
	.uleb128 0x14
	.long	.LASF105
	.byte	0x9
	.value	0x12f
	.long	0x9c
	.byte	0xa8
	.uleb128 0x14
	.long	.LASF106
	.byte	0x9
	.value	0x130
	.long	0x9c
	.byte	0xb0
	.uleb128 0x14
	.long	.LASF107
	.byte	0x9
	.value	0x132
	.long	0xd1
	.byte	0xb8
	.uleb128 0x14
	.long	.LASF108
	.byte	0x9
	.value	0x133
	.long	0x6d
	.byte	0xc0
	.uleb128 0x14
	.long	.LASF109
	.byte	0x9
	.value	0x135
	.long	0x554
	.byte	0xc4
	.byte	0
	.uleb128 0x15
	.long	.LASF136
	.byte	0x9
	.byte	0x9a
	.uleb128 0xc
	.long	.LASF110
	.byte	0x18
	.byte	0x9
	.byte	0xa0
	.long	0x532
	.uleb128 0xd
	.long	.LASF111
	.byte	0x9
	.byte	0xa1
	.long	0x532
	.byte	0
	.uleb128 0xd
	.long	.LASF112
	.byte	0x9
	.byte	0xa2
	.long	0x538
	.byte	0x8
	.uleb128 0xd
	.long	.LASF113
	.byte	0x9
	.byte	0xa6
	.long	0x6d
	.byte	0x10
	.byte	0
	.uleb128 0x6
	.byte	0x8
	.long	0x501
	.uleb128 0x6
	.byte	0x8
	.long	0x37a
	.uleb128 0xe
	.long	0xa4
	.long	0x54e
	.uleb128 0xf
	.long	0x42
	.byte	0
	.byte	0
	.uleb128 0x6
	.byte	0x8
	.long	0x4fa
	.uleb128 0xe
	.long	0xa4
	.long	0x564
	.uleb128 0xf
	.long	0x42
	.byte	0x13
	.byte	0
	.uleb128 0x16
	.long	.LASF137
	.uleb128 0x17
	.long	.LASF114
	.byte	0x9
	.value	0x13f
	.long	0x564
	.uleb128 0x17
	.long	.LASF115
	.byte	0x9
	.value	0x140
	.long	0x564
	.uleb128 0x17
	.long	.LASF116
	.byte	0x9
	.value	0x141
	.long	0x564
	.uleb128 0x6
	.byte	0x8
	.long	0xab
	.uleb128 0x7
	.long	0x58d
	.uleb128 0x13
	.long	.LASF117
	.byte	0xa
	.byte	0x87
	.long	0x538
	.uleb128 0x13
	.long	.LASF118
	.byte	0xa
	.byte	0x88
	.long	0x538
	.uleb128 0x13
	.long	.LASF119
	.byte	0xa
	.byte	0x89
	.long	0x538
	.uleb128 0x13
	.long	.LASF120
	.byte	0xb
	.byte	0x1a
	.long	0x6d
	.uleb128 0xe
	.long	0x593
	.long	0x5cf
	.uleb128 0x18
	.byte	0
	.uleb128 0x7
	.long	0x5c4
	.uleb128 0x13
	.long	.LASF121
	.byte	0xb
	.byte	0x1b
	.long	0x5cf
	.uleb128 0x17
	.long	.LASF122
	.byte	0xc
	.value	0x222
	.long	0x32b
	.uleb128 0x13
	.long	.LASF123
	.byte	0xd
	.byte	0x24
	.long	0x9e
	.uleb128 0x13
	.long	.LASF124
	.byte	0xd
	.byte	0x32
	.long	0x6d
	.uleb128 0x13
	.long	.LASF125
	.byte	0xd
	.byte	0x37
	.long	0x6d
	.uleb128 0x13
	.long	.LASF126
	.byte	0xd
	.byte	0x3b
	.long	0x6d
	.uleb128 0x19
	.long	.LASF138
	.byte	0x1
	.byte	0xd
	.long	0x6d
	.quad	.LFB5
	.quad	.LFE5-.LFB5
	.uleb128 0x1
	.byte	0x9c
	.long	0x6be
	.uleb128 0x1a
	.long	.LASF127
	.byte	0x1
	.byte	0xd
	.long	0x6d
	.uleb128 0x3
	.byte	0x91
	.sleb128 -2132
	.uleb128 0x1a
	.long	.LASF128
	.byte	0x1
	.byte	0xd
	.long	0x32b
	.uleb128 0x3
	.byte	0x91
	.sleb128 -2144
	.uleb128 0x1b
	.long	.LASF129
	.byte	0x1
	.byte	0x17
	.long	0x6d
	.uleb128 0x3
	.byte	0x91
	.sleb128 -2112
	.uleb128 0x1c
	.string	"on"
	.byte	0x1
	.byte	0x17
	.long	0x6d
	.uleb128 0x3
	.byte	0x91
	.sleb128 -2116
	.uleb128 0x1b
	.long	.LASF130
	.byte	0x1
	.byte	0x18
	.long	0x6be
	.uleb128 0x3
	.byte	0x91
	.sleb128 -2080
	.uleb128 0x1b
	.long	.LASF131
	.byte	0x1
	.byte	0x19
	.long	0x2de
	.uleb128 0x3
	.byte	0x91
	.sleb128 -2096
	.uleb128 0x1c
	.string	"he"
	.byte	0x1
	.byte	0x1a
	.long	0x6cf
	.uleb128 0x3
	.byte	0x91
	.sleb128 -2104
	.uleb128 0x1c
	.string	"ret"
	.byte	0x1
	.byte	0x53
	.long	0x6d
	.uleb128 0x3
	.byte	0x91
	.sleb128 -2108
	.uleb128 0x1d
	.string	"LAB"
	.byte	0x1
	.byte	0x5c
	.quad	.L9
	.byte	0
	.uleb128 0xe
	.long	0xa4
	.long	0x6cf
	.uleb128 0x1e
	.long	0x42
	.value	0x807
	.byte	0
	.uleb128 0x6
	.byte	0x8
	.long	0x331
	.byte	0
	.section	.debug_abbrev,"",@progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x26
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x4
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x28
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1c
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x28
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1c
	.uleb128 0x6
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x28
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1c
	.uleb128 0x5
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xf
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x10
	.uleb128 0x4
	.byte	0x1
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x11
	.uleb128 0x17
	.byte	0x1
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x12
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x13
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x14
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x15
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x16
	.uleb128 0x13
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x17
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x18
	.uleb128 0x21
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0x19
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1a
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x1b
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x1c
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x1d
	.uleb128 0xa
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x11
	.uleb128 0x1
	.byte	0
	.byte	0
	.uleb128 0x1e
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0x5
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"",@progbits
	.long	0x2c
	.value	0x2
	.long	.Ldebug_info0
	.byte	0x8
	.byte	0
	.value	0
	.value	0
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.quad	0
	.quad	0
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.section	.debug_str,"MS",@progbits,1
.LASF10:
	.string	"__off_t"
.LASF82:
	.string	"_IO_read_ptr"
.LASF94:
	.string	"_chain"
.LASF66:
	.string	"__in6_u"
.LASF16:
	.string	"size_t"
.LASF51:
	.string	"IPPROTO_MTP"
.LASF54:
	.string	"IPPROTO_PIM"
.LASF100:
	.string	"_shortbuf"
.LASF45:
	.string	"IPPROTO_DCCP"
.LASF6:
	.string	"__uint8_t"
.LASF44:
	.string	"IPPROTO_TP"
.LASF116:
	.string	"_IO_2_1_stderr_"
.LASF88:
	.string	"_IO_buf_base"
.LASF27:
	.string	"SOCK_NONBLOCK"
.LASF53:
	.string	"IPPROTO_ENCAP"
.LASF37:
	.string	"IPPROTO_IGMP"
.LASF31:
	.string	"in_addr_t"
.LASF118:
	.string	"stdout"
.LASF47:
	.string	"IPPROTO_RSVP"
.LASF18:
	.string	"long long int"
.LASF4:
	.string	"signed char"
.LASF42:
	.string	"IPPROTO_UDP"
.LASF17:
	.string	"long long unsigned int"
.LASF95:
	.string	"_fileno"
.LASF83:
	.string	"_IO_read_end"
.LASF63:
	.string	"__u6_addr16"
.LASF9:
	.string	"long int"
.LASF64:
	.string	"__u6_addr32"
.LASF81:
	.string	"_flags"
.LASF89:
	.string	"_IO_buf_end"
.LASF98:
	.string	"_cur_column"
.LASF19:
	.string	"SOCK_STREAM"
.LASF74:
	.string	"hostent"
.LASF14:
	.string	"uint16_t"
.LASF97:
	.string	"_old_offset"
.LASF102:
	.string	"_offset"
.LASF68:
	.string	"in6addr_loopback"
.LASF8:
	.string	"__uint32_t"
.LASF129:
	.string	"create_socket"
.LASF73:
	.string	"sin_zero"
.LASF55:
	.string	"IPPROTO_COMP"
.LASF110:
	.string	"_IO_marker"
.LASF22:
	.string	"SOCK_RDM"
.LASF2:
	.string	"unsigned int"
.LASF34:
	.string	"s_addr"
.LASF49:
	.string	"IPPROTO_ESP"
.LASF75:
	.string	"h_name"
.LASF137:
	.string	"_IO_FILE_plus"
.LASF86:
	.string	"_IO_write_ptr"
.LASF120:
	.string	"sys_nerr"
.LASF112:
	.string	"_sbuf"
.LASF1:
	.string	"short unsigned int"
.LASF72:
	.string	"sin_addr"
.LASF113:
	.string	"_pos"
.LASF90:
	.string	"_IO_save_base"
.LASF117:
	.string	"stdin"
.LASF77:
	.string	"h_addrtype"
.LASF101:
	.string	"_lock"
.LASF96:
	.string	"_flags2"
.LASF108:
	.string	"_mode"
.LASF46:
	.string	"IPPROTO_IPV6"
.LASF114:
	.string	"_IO_2_1_stdin_"
.LASF70:
	.string	"sin_family"
.LASF123:
	.string	"optarg"
.LASF131:
	.string	"address"
.LASF124:
	.string	"optind"
.LASF87:
	.string	"_IO_write_end"
.LASF76:
	.string	"h_aliases"
.LASF60:
	.string	"IPPROTO_MAX"
.LASF136:
	.string	"_IO_lock_t"
.LASF67:
	.string	"in6addr_any"
.LASF80:
	.string	"_IO_FILE"
.LASF133:
	.string	"client.c"
.LASF122:
	.string	"__environ"
.LASF24:
	.string	"SOCK_DCCP"
.LASF52:
	.string	"IPPROTO_BEETPH"
.LASF71:
	.string	"sin_port"
.LASF29:
	.string	"sa_family"
.LASF121:
	.string	"sys_errlist"
.LASF78:
	.string	"h_length"
.LASF79:
	.string	"h_addr_list"
.LASF135:
	.string	"__socket_type"
.LASF41:
	.string	"IPPROTO_PUP"
.LASF56:
	.string	"IPPROTO_SCTP"
.LASF0:
	.string	"unsigned char"
.LASF59:
	.string	"IPPROTO_RAW"
.LASF43:
	.string	"IPPROTO_IDP"
.LASF5:
	.string	"short int"
.LASF99:
	.string	"_vtable_offset"
.LASF115:
	.string	"_IO_2_1_stdout_"
.LASF132:
	.string	"GNU C11 7.4.0 -mtune=generic -march=x86-64 -g -fstack-protector-strong"
.LASF93:
	.string	"_markers"
.LASF25:
	.string	"SOCK_PACKET"
.LASF65:
	.string	"in6_addr"
.LASF126:
	.string	"optopt"
.LASF15:
	.string	"uint32_t"
.LASF57:
	.string	"IPPROTO_UDPLITE"
.LASF3:
	.string	"long unsigned int"
.LASF12:
	.string	"char"
.LASF40:
	.string	"IPPROTO_EGP"
.LASF134:
	.string	"/home/fscorrea/C/2020-01-07"
.LASF7:
	.string	"__uint16_t"
.LASF62:
	.string	"__u6_addr8"
.LASF130:
	.string	"buffer"
.LASF125:
	.string	"opterr"
.LASF111:
	.string	"_next"
.LASF11:
	.string	"__off64_t"
.LASF36:
	.string	"IPPROTO_ICMP"
.LASF84:
	.string	"_IO_read_base"
.LASF92:
	.string	"_IO_save_end"
.LASF48:
	.string	"IPPROTO_GRE"
.LASF103:
	.string	"__pad1"
.LASF104:
	.string	"__pad2"
.LASF105:
	.string	"__pad3"
.LASF106:
	.string	"__pad4"
.LASF107:
	.string	"__pad5"
.LASF58:
	.string	"IPPROTO_MPLS"
.LASF28:
	.string	"sa_family_t"
.LASF109:
	.string	"_unused2"
.LASF119:
	.string	"stderr"
.LASF128:
	.string	"argv"
.LASF26:
	.string	"SOCK_CLOEXEC"
.LASF32:
	.string	"sockaddr"
.LASF20:
	.string	"SOCK_DGRAM"
.LASF69:
	.string	"sockaddr_in"
.LASF13:
	.string	"uint8_t"
.LASF39:
	.string	"IPPROTO_TCP"
.LASF91:
	.string	"_IO_backup_base"
.LASF50:
	.string	"IPPROTO_AH"
.LASF127:
	.string	"argc"
.LASF30:
	.string	"sa_data"
.LASF38:
	.string	"IPPROTO_IPIP"
.LASF21:
	.string	"SOCK_RAW"
.LASF23:
	.string	"SOCK_SEQPACKET"
.LASF138:
	.string	"main"
.LASF85:
	.string	"_IO_write_base"
.LASF61:
	.string	"in_port_t"
.LASF33:
	.string	"in_addr"
.LASF35:
	.string	"IPPROTO_IP"
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
