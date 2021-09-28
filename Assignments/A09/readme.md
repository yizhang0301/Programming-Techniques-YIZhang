## 10017 The Never Ending Towers of Hanoi
In 1883, Edward Lucas invented, or perhaps reinvented, one of the most popular puzzles of all times
– the Tower of Hanoi, as he called it – which is still used today in many computer science textbooks
to demonstrate how to write a recursive algorithm or program. First of all, we will make a list of the
rules of the puzzle:
• There are three pegs: A, B and C. • There are n disks. The number n is constant while working the puzzle.
• All disks are different in size.
• The disks are initially stacked on peg A so that they increase in size from the top to the bottom.
• The goal of the puzzle is to transfer the entire tower from the A peg to the peg C. • One disk at a time can be moved from the top of a stack either to an empty peg or to a peg with
a larger disk than itself on the top of its stack.
Your job will be to write a program which will show a copy of the puzzle on the screen step by step,
as you move the disks around. This program has to solve the problem in an efficient way.
TIP: It is well known and rather easy to prove that the minimum number of moves needed to complete
the puzzle with n disks is 2n − 1.

|   #   | File                       | Description           |
| :---: | -------------------------- | --------------------- |
|   1   | [10017.cpp](./P10017.cpp) | main file.            |
|   2   | [10017.pdf](./110017.pdf)   | question pdf          |
|   3   | [banner.txt](./banner.txt) | banner page           |