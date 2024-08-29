start:
    mov ax, 5       ; Number to calculate factorial for
    push ax         ; Push argument onto stack
    call factorial  ; Call factorial function
    add sp, 2       ; Clean up stack after call
    
    ; Result is now in AX
    ; You can add code here to display or use the result
    
    ; Exit program
    mov ah, 4Ch
    int 21h

factorial proc:
    push bp         ; Save base pointer
    mov bp, sp      ; Set up stack frame
    
    mov ax, [bp+4]  ; Get argument (n)
    cmp ax, 1       ; Check if n <= 1
    jle base_case   ; If so, go to base case
    
    dec ax          ; n - 1
    push ax         ; Push (n-1) as argument for recursive call
    call factorial  ; Recursive call
    add sp, 2       ; Clean up stack after recursive call
    
    mov bx, [bp+4]  ; Get original n
    mul bx          ; AX = AX * BX (result * n)
    jmp end_func

    ret
factorial endp

base_case:
    mov ax, 1       ; Return 1 for base case

end_func:
    mov sp, bp      ; Restore stack pointer
    pop bp          ; Restore base pointer
    ret             ; Return to caller