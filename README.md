# Smith-Waterman Algorithm

This project was a coursework task for the Systems Programming (H) course at the University of Glasgow. It was to be written in C and provided us with a good introduction to pointers/memory allocation.

## Description
The Smith–Waterman algorithm performs local sequence alignment. It determines similar regions between two strings of nucleic acid or protein sequences. Instead of looking at the entire sequence, the Smith–Waterman algorithm compares segments of all possible lengths and optimizes the similarity measure.

https://en.wikipedia.org/wiki/Smith%E2%80%93Waterman_algorithm

## Installation
Clone the repository and run test in the makefile to run the program. To run using the csv file, use from-csv in the makefile.
```
make test
./test
```
```
make from-csv
./from-csv [file]
```
