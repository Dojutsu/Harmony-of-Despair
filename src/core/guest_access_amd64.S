// Registered destructor-free access leaves. Failure uses the same CALL/RET.
.text
.macro START name
.globl \name
.hidden \name
.type \name,@function
\name:
.cfi_startproc
.endm
.macro END name
.cfi_endproc
.size \name, .-\name
.endm
START rex_guest_read1
.globl rex_guest_read1_site, rex_guest_read1_fail
.hidden rex_guest_read1_site, rex_guest_read1_fail
rex_guest_read1_site:
 movb (%rdi), %dl
 movb %dl, (%rsi)
 xorl %eax, %eax
 ret
rex_guest_read1_fail:
 movl $1, %eax
 ret
END rex_guest_read1
START rex_guest_write1
.globl rex_guest_write1_site, rex_guest_write1_fail
.hidden rex_guest_write1_site, rex_guest_write1_fail
 movb (%rsi), %dl
rex_guest_write1_site:
 movb %dl, (%rdi)
 xorl %eax, %eax
 ret
rex_guest_write1_fail:
 movl $1, %eax
 ret
END rex_guest_write1
START rex_guest_read2
.globl rex_guest_read2_site, rex_guest_read2_fail
.hidden rex_guest_read2_site, rex_guest_read2_fail
rex_guest_read2_site:
 movw (%rdi), %dx
 movw %dx, (%rsi)
 xorl %eax, %eax
 ret
rex_guest_read2_fail:
 movl $1, %eax
 ret
END rex_guest_read2
START rex_guest_write2
.globl rex_guest_write2_site, rex_guest_write2_fail
.hidden rex_guest_write2_site, rex_guest_write2_fail
 movw (%rsi), %dx
rex_guest_write2_site:
 movw %dx, (%rdi)
 xorl %eax, %eax
 ret
rex_guest_write2_fail:
 movl $1, %eax
 ret
END rex_guest_write2
START rex_guest_read4
.globl rex_guest_read4_site, rex_guest_read4_fail
.hidden rex_guest_read4_site, rex_guest_read4_fail
rex_guest_read4_site:
 movl (%rdi), %edx
 movl %edx, (%rsi)
 xorl %eax, %eax
 ret
rex_guest_read4_fail:
 movl $1, %eax
 ret
END rex_guest_read4
START rex_guest_write4
.globl rex_guest_write4_site, rex_guest_write4_fail
.hidden rex_guest_write4_site, rex_guest_write4_fail
 movl (%rsi), %edx
rex_guest_write4_site:
 movl %edx, (%rdi)
 xorl %eax, %eax
 ret
rex_guest_write4_fail:
 movl $1, %eax
 ret
END rex_guest_write4
START rex_guest_read8
.globl rex_guest_read8_site, rex_guest_read8_fail
.hidden rex_guest_read8_site, rex_guest_read8_fail
rex_guest_read8_site:
 movq (%rdi), %rdx
 movq %rdx, (%rsi)
 xorl %eax, %eax
 ret
rex_guest_read8_fail:
 movl $1, %eax
 ret
END rex_guest_read8
START rex_guest_write8
.globl rex_guest_write8_site, rex_guest_write8_fail
.hidden rex_guest_write8_site, rex_guest_write8_fail
 movq (%rsi), %rdx
rex_guest_write8_site:
 movq %rdx, (%rdi)
 xorl %eax, %eax
 ret
rex_guest_write8_fail:
 movl $1, %eax
 ret
END rex_guest_write8
START rex_guest_vector_read
.globl rex_guest_vector_read_site, rex_guest_vector_read_fail
.hidden rex_guest_vector_read_site, rex_guest_vector_read_fail
rex_guest_vector_read_site:
 movdqu (%rdi), %xmm0
 movdqu %xmm0, (%rsi)
 xorl %eax, %eax
 ret
rex_guest_vector_read_fail:
 movl $1, %eax
 ret
END rex_guest_vector_read
START rex_guest_vector_write
.globl rex_guest_vector_write_site, rex_guest_vector_write_fail
.hidden rex_guest_vector_write_site, rex_guest_vector_write_fail
 movdqu (%rsi), %xmm0
rex_guest_vector_write_site:
 movdqu %xmm0, (%rdi)
 xorl %eax, %eax
 ret
rex_guest_vector_write_fail:
 movl $1, %eax
 ret
END rex_guest_vector_write
START rex_guest_cas4
.globl rex_guest_cas4_site, rex_guest_cas4_fail
.hidden rex_guest_cas4_site, rex_guest_cas4_fail
 movl %esi, %eax
rex_guest_cas4_site:
 lock cmpxchgl %edx, (%rdi)
 movl %eax, (%rcx)
 xorl %eax, %eax
 ret
rex_guest_cas4_fail:
 movl $1, %eax
 ret
END rex_guest_cas4
START rex_guest_cas8
.globl rex_guest_cas8_site, rex_guest_cas8_fail
.hidden rex_guest_cas8_site, rex_guest_cas8_fail
 movq %rsi, %rax
rex_guest_cas8_site:
 lock cmpxchgq %rdx, (%rdi)
 movq %rax, (%rcx)
 xorl %eax, %eax
 ret
rex_guest_cas8_fail:
 movl $1, %eax
 ret
END rex_guest_cas8
START rex_guest_copy
.globl rex_guest_copy_site, rex_guest_copy_fail
.hidden rex_guest_copy_site, rex_guest_copy_fail
 movq %rdx, %rcx
 cld
rex_guest_copy_site:
 rep movsb
 xorl %eax, %eax
 ret
rex_guest_copy_fail:
 movl $1, %eax
 ret
END rex_guest_copy
.section .note.GNU-stack,"",@progbits
