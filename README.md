## PUSH_SWAP

Given a set of integers, sort it using a predefined set of instructions using two stacks. The instruction set is defined below. This program outputs a program in push_swap instructions that sorts the input integers.

## Instruction set

Code	Instruction	Action
sa	swap a	swaps the 2 top elements of stack a
sb	swap b	swaps the 2 top elements of stack b
ss	swap a + swap b	both sa and sb
pa	push a	moves the top element of stack b at the top of stack a
pb	push b	moves the top element of stack a at the top of stack b
ra	rotate a	shifts all elements of stack a from bottom to top
rb	rotate b	shifts all elements of stack b from bottom to top
rr	rotate a + rotate b	both ra and rb
rra	reverse rotate a	shifts all elements of stack a from top to bottom
rrb	reverse rotate b	shifts all elements of stack b from top to bottom
rrr	reverse rotate a + reverse rotate b	both rra and rrb

## Algorithm

The Turk algorithm is implemented. It calculates the cost of swap for every element 
of a stack, chooses the cheapest and pushes it inot another register.
Details: https://medium.com/@ayogun/push-swap-c1f5d2d41e97

##  Grading

The grade depends on how efficient the program's sorting process is.

Sorting 3 values: no more than 3 actions.
Sorting 5 values: no more than 12 actions.
Sorting 100 values: rating from 1 to 5 points depending on the number of actions:
5 points for less than 700 actions
4 points for less than 900
3 points for less than 1100
2 points for less than 1300
1 point for less than 1500
Sorting 500 values: rating from 1 to 5 points depending on the number of actions:
5 points for less than 5500 actions
4 points for less than 7000
3 points for less than 8500
2 points for less than 10000
1 point for less than 11500
Validating the project requires at least 80/100.

## HOW EFFECTIVE IT TURNED OUT TO BE?

All test found on GitHub gave 100% resuls so I get 100/100 without bonus part.

## COMPATIBILITY

Currently compatible with MacOS only.
