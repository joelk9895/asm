.text
    .global _main
    .align 2

_main:
    bl _printprompt
    bl _read
    bl _printbuffer
    bl _terminate

_printprompt:
    mov x0, #1                      // stdout
    adrp x1, prompt@PAGE            // address of string
    add x1, x1, prompt@PAGEOFF
    mov x2, #17                     // nbyte
    mov x16, #4                     // write
    svc 0                           // call syscall
    ret

_read:
    mov x0, #0                      // stdin
    adrp x1, buffer@PAGE            // address of buffer
    add x1, x1, buffer@PAGEOFF
    mov x2, #1024                   // maximum number of bytes to read
    mov x16, #3                     // read
    svc 0                           // call syscall
    ret

_printbuffer:
    mov x2, x0                      // move byte count to x2 (the nbyte for write syscall)
    mov x0, #1                      // stdout
    adrp x1, buffer@PAGE            // address of buffer
    add x1, x1, buffer@PAGEOFF
    // mov x2, #1024                // nbyte
    mov x16, #4                     // write
    svc 0                           // call syscall
    ret

_terminate:
    mov x0, #0                      // return 0
    mov x16, #1                     // terminate
    svc 0                           // call syscall
    ret

.data
    prompt: .ascii "Say something: \n"
    .align 2
    buffer: .space 1024