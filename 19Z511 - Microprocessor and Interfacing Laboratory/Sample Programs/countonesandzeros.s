; count 1s and 0s in the given binary 7 bit number and check parity
; parity -> check if number of 1s is odd or even

start:
    MOV SI, 0x2000
    MOV AX, 0 ;counter for 0
    MOV BX, 0 ;counter for 1

    MOV CX, 7
    MOV DX, 0

countloop:
    MOV DL, BYTE [DI]
    CMP DL, 1
    JE ifone
    JNE ifzero

ifone:
    INC AX
    DEC CX
    INC DI
    CMP CX, 0
    JNE countloop
    JE parity

ifzero:
    INC BX
    DEC CX
    INC DI
    CMP CX, 0
    JNE countloop
    JE parity

parity:
    MOV WORD [0x3000], AX
    MOV WORD [0x3004], BX

    MOV AX, 0x0002
    DIV BX
    CMP DX, 1
    JE oddparity
    JNE evenparity

oddparity:
    ; do whatever is asked in the question for representating that the number has odd parity
    ; ideally some alternative to print statements

evenparity:
    ; do whatever is asked in the question for representating that the number has even parity
    ; ideally some alternative to print statements
