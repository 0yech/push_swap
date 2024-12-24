![image](https://github.com/user-attachments/assets/94e4623d-3937-405a-a29d-4ba0c27c78d6)
<img align="right" width="199" alt="score" src="https://github.com/user-attachments/assets/bf5375e8-a4ba-4e7a-80cf-7282133b840c" />

# Push_swap - Sorting a pile with two stacks

One of the most rewarding Rank02 projects at 42, it is also the only one you can't choose.

## Goal
You're given two stacks/piles, A and B. You need to sort the pile only using "Push Swap language".

The program should be able to take parameters in different ways.

```./push_swap "99 50 33 12 0 19"```

or

```./push_swap 99 50 33 12 0 19```

## Initial input
```
Stack A:    Stack B:
  43
  95
  53
  88
  1
  49252
  -32
```
## Wanted outcome - Once sorted
```
Stack A:    Stack B:
  -32
  1
  43
  53
  88
  95
  49252
```
## Push_swap language ?

The program must print out all the Push_swap instructions you may need to sort the stack. Here are the possible Push_swap instructions.

```pa``` - Push A, takes the top element of B and puts it on top of A.

```pb``` - Push B, takes the top element of A and puts it on top of B.

-

```sa``` - Swap A, takes the two top elements of A and swaps them.

```sb``` - Swap B, takes the two top elements of B and swaps them.

```ss``` - Does both swaps in a single move ```(sa && sb)```.

-

```ra``` - Rotate A, takes the top element of A and puts it in the bottom of A.

```rb``` - Rotate B, takes the top element of B and puts it in the bottom of B.

```rr``` - Does both rotation in a single move ```(ra && rb)```.

-

```rra``` - Reverse Rotate A, takes the bottom element of A and puts it on top of A.

```rrb``` - Reverse Rotate B, takes the bottom element of B and puts it on top of B.

```rrr``` - Does both rotation in a single move ```(rra & rrb)```.


## What you'll learn

With Push_swap, you'll most likely learn about the following (as in the 42 cursus)

- Linked lists, if you decide to use them. You will most likely encounter them anyways when evaluating people.
- Sort algorithms and which ones shine more depending on each case.
- If you decide to come up with your own algorithm, you might end up discovering Bi-directional linked lists and more complex ideas like move cost.
- Working with structs more effeciently

## My Push_swap

I included bi-directional linked lists as well as additional tools for debug and solving. But for my initial evaluation, I used the **radix** algorithm. It solves the stacks using bits, this helped me to learn how to use bit operators, so i'd suggest exploring it for beginners.

## Authorized external functions and tools

- ```write, malloc, free```
- ```ft_printf or any self made code```

## Subject

[42 - Push_swap](https://cdn.intra.42.fr/pdf/pdf/116759/en.subject.pdf)

## Norm

42 projects are written under the [Norm V4](https://cdn.intra.42.fr/pdf/pdf/96987/en.norm.pdf)

42's Norm most notorious rules (just to name a few) implies things such as :

- No ```for``` loops.
- Max 25 lines per function.
- Max of one declaration or assignation per line.
- Strict indentation and formatting.
- No extra external functions or libraries.
- No Ternary operators.
- And many more.
