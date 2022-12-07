;James Riley Dorough
extern printf
global main

section .data
intPrint:
	db '%d', 10, 0
stringPrint:
	db '%s', 10, 0
one_int:
	db '%hhd', 32, 0
nl:
	db 10, 0

struc requirement_structure
	requirement_id resb 8
	requirement_priority resb 4
	team_assigned resb 30
	sub_requirements resb 10
	due_date resb 7
endstruc

first_requirement istruc requirement_structure
	at requirement_id, dq 19348275
	at requirement_priority, db 2
	at team_assigned, db "The A Team"
	at sub_requirements, db 1, 2, 3
	at due_date, db "18APR21"
iend

section .text
main:
	mov rdi, intPrint
	mov rsi, [first_requirement]
	xor rax, rax
	call printf

	mov rdi, intPrint
	mov rsi, [first_requirement + requirement_priority]
	xor rax, rax
	call printf

	mov rdi, stringPrint
	mov rsi, first_requirement + team_assigned
	xor rax, rax
	call printf

	mov rbx, 0
	call itterate

	mov rdi, nl
	xor rax, rax
	call printf

	mov rdi, stringPrint
	mov rsi, first_requirement + due_date
	xor rax, rax
	call printf

exit:
	mov rax, 60
	syscall

itterate:
	mov rdi, one_int
	xor rax, rax
	mov rsi, [first_requirement + sub_requirements + rbx]
	push rbx
	call printf
	pop rbx	
	add rbx, 1
	cmp rbx, 2
	jle itterate
	ret









