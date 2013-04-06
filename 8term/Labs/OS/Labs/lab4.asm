.model small
.data
	helloMessage db "Welcome to the NHK",10,13,"$"
	fileReadError db "Error reading file",10,13,"$"
	filesizeMSG db 10,13,"file size: $"
	dirname db "dir",0
	file1 db "111.txt",0
	file2 db "222.txt",0
	file3 db "333.txt",0
	
	buff db 0
	temp dw 0
	turn db 1
	isEnd db 0
	fileSize dw 0
	
.code
main proc
	call init
	call getFileHandles ; opens file in this 
	
	cycle:
	mov al, isEnd ;  == 11, each files had beed fully read
	cmp al, 3
	je endCycle
	
	cmp turn,1
	je readFromFile1
	jmp readFromFile2
	readFromFile1:
	mov bx, di
	mov turn, 2
	jmp endSettingReadHandle
	readFromFile2:
	mov bx, si
	mov turn, 1
	jmp endSettingReadHandle
	endSettingReadHandle:
	mov cx, 1
	mov ah, 3fh
	lea dx, buff
	int 21h
	;if nothing to read
	mov bl, isEnd
	cmp al, 0
	je markEnd
	jmp writeData
	markEnd:
	or bl, turn
	mov isEnd, bl
	jmp cycle
	writeData:
	;write to file
	mov ah, 40h
	mov bx, bp
	lea dx, buff
	int 21h
	inc fileSize
	;write to cmd
	mov ah, 2h
	mov dl, buff
	int 21h
	
	jmp cycle
	
	endCycle:
		
	call closeFiles
	
	mov ah, 9h
	lea dx, filesizeMSG
	int 21h
	
	mov ax, fileSize
	call writeNumber
	
	mov ax, 4c00h
	int 21h
main endp

writeNumber proc
	mov si, 10
	mov dx, 0
	mov di, ax
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
	ret
writeNumber endp

closeFiles proc
	mov ah, 3eh
	mov bx, di
	int 21h
	
	mov ah, 3eh
	mov bx, si
	int 21h
	
	mov ah, 3eh
	mov bx, bp
	int 21h
	ret
closeFiles endp

getFileHandles proc
	;file 1
	mov ax, 3D00h ;open read file
	lea dx, file1
	int 21h
	;ax now contains file 1 handle
	mov di, ax
	; file 2
	mov ax, 3D00h ;open read file
	lea dx, file2
	int 21h
	;ax now contains file 2 handle
	mov si, ax
	; file 3(output)
	mov ah, 41h ;delete file
	lea dx, file3
	int 21h
	;ax now contains deleted file handle
	mov bp, ax
	
	mov cx, 0
	mov ah, 3Ch ;open write file
	lea dx, file3
	int 21h
	;ax now contains file handle
	mov bp, ax
	
	ret 
getFileHandles endp

init proc
	mov AX, @data
	mov DS, AX
	lea DX, helloMessage
	call printString
	
	;select disc G as main
	mov ah, 0eh
	mov dl, 6
	int 21h
	ret
init endp

printString proc
	mov temp, ax
	mov ah, 9h
	int 21h
	mov ax, temp
	ret
printString endp

end