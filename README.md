Fillit
========
### 42 - Project #2

Fillit is a recursive backtracking algorithm that fits a set of Tetriminos in the smallest possible square without rotating the Tetriminos. More information can be found on this [PDF].

Here is an example of valid map of Tetriminos (maximum of 26 blocks) which the code fits in the solution below:

```
....
.##.
.##.
....

...#
...#
...#
...#

....
..##
.##.
....

....
..#.
.##.
.#..

.###
...#
....
....

##..
.#..
.#..
....

....
..##
.##.
....

.#..
.##.
..#.
....

....
###.
.#..
....
```

Solution (each individual tetriminos renamed starting from A):
```
AAB.CCD
AABCCDD
FFB..D.
.FBEEE.
HF.GGE.
HHGGIII
.H...I.
```
How to use:

    git clone --recursive https://github.com/JibranKalia/fillit.git
    choose a map from examples folder
    ./fillit examples/ok_09_block

Features
--------

- Implements error checking to detect invalid tetriminos. 

Official Team
--------
This project was developed jointly by Jibran Kalia [@jibrankalia](https://github.com/JibranKalia) and Giacomo Guiulfo [@giacomoguiulfo](https://github.com/giacomoguiulfo).

[PDF]: https://github.com/giacomoguiulfo/fillit/blob/master/fillit.en.pdf
