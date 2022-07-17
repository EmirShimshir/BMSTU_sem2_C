# Tests for lab_01_07_04


## Input:
float: x, eps

## Output:
float: s, f, abs_error, rel_error

count: 1 / (x + 1)^3 by Telor's formula

## Positive tests:
- 01 - small eps
- 02 - average eps



## Negative tests:
- 01 - incorrect input
- 02 - eps > 1
- 03 - x > 1
