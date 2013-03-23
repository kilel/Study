.model small
.data
	message db "Hello World! Kilel asks you to enter some data [a-zA-Z0-9]+ $"
	buff db 3600 dup(18)
	maxel db 0
.code
	mov AX, @data
	mov DS, AX
	;message printing
	lea DX, message
	mov AH, 9h
	int 21h
	;\n\r
	mov ah, 02h
	mov dl, 13
	int 21h
	mov ah, 02h
	mov dl, 10
	int 21h
	
	;reading loop
	mov cx, 0
	mov di, 0
	;dx contains value
	mov dl, 10
	mov ah, 01h
	readloop:

		int 21h
		cmp al, 13
		;if pressed "enter"
		je endread
		;else
		mov buff[di], al
		inc di
		cmp al, 30h
		jl readloop
		cmp al, 39h
		jg readloop
		
		cmp dl, al
		jge readloop
		;else
		mov dl, al
		jmp readloop
	
	endread:
	
	mov maxel, dl
	;write heart
	mov ah, 02h
	mov dl, 13
	int 21h
	mov dl, 10
	int 21h
	mov dl, 3
	int 21h
	mov dl, 13
	int 21h
	mov dl, 10
	int 21h
	
	mov cx,di
	mov di,0
	mov si, 0ah
	
	writeloop:
		cmp di, cx
		je endwrite
		mov dl, buff[di]
		inc di
		cmp maxel, dl
		jne writeloop
		
		;place to write di as a 
		mov dx, 0
		mov ax, di

		
		div si 
		mov bx, ax
		mov ax, 1
		degtensearch:
			cmp ax, bx
			jg enddts
			mul si
			jmp degtensearch
		enddts:
		
		mov bx, ax
		;bx now contains 10^n, which is lower, than di
		mov ax, di
		mov dx, 0
		
		parserloop:
		div bx
		mov bp, dx
		mov dx, ax
		add dl, 30h
		mov ah, 2
		int 21h
		
		
		
		mov dx, 0
		mov ax, bx
		div si
		mov bx, ax
		
		mov ax, bp
		
		cmp bx, 0
		jne parserloop
		
		endparser: 
		
		mov ah, 2h
		mov dl, 20h
		int 21h
		
		;end place
		jmp writeloop
		
	endwrite:
	
	mov ah, 2h
	mov dl, 24
	int 21h
	mov dl, 32
	int 21h
	mov dl, maxel
	int 21h
	
	mov ax, 4c00h
	int 21h
end