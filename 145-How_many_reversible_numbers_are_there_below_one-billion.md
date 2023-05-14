# Problem

Some positive integers $n$ have the property that the $sum [ n + reverse(n) ]$ consists entirely of odd (decimal) digits. For instance, $36 + 63 = 99$ and $409 + 904 = 1313$. We will call such numbers reversible; so $36, 63, 409$, and $904$ are reversible. Leading zeroes are not allowed in either $n$ or $reverse(n)$.

There are $120$ reversible numbers below one-thousand.

How many reversible numbers are there below one-billion ($10^9$)?

## 1 digit, $n = a$

|     |     |
| --- | --- |
|     | a   |
|+)   | a   |
|     | A   |

A will always be even no matter the value of a.

## 2 digit, $n = ab$

|       |       |       |
|---    |---    |---    |
|       | a     | b     |
|+)     | b     | a     |
|       | A     | B     |

1. a + b must < 10 (i.e. should not have a carriage), or otherwise B will be even.
2. a and b can not be 0.

there are 20 possibilities.

## 3 digit, $n = abc$

|       |       |       |       |
|---    |---    |---    |---    |
|       | a     | b     | c     |
|+)     | c     | b     | a     |
|       | A     | B     | C     |

1. b + b must < 10, or otherwise C will be even. There are 5 choices.
2. a + c must > 10, or otherwise B will be even. There are 20 choices.
3. a and c can not be 0.

there are 100 possibilities.

## 4 digit, $n = abcd$

|       |       |       |       |       |
|---    |---    |---    |---    |---    |
|       | a     | b     | c     | d     |
|+)     | d     | c     | b     | a     |
|       | A     | B     | C     | D     |

1. c + b must < 10, or otherwise D will be even. There are 30 choices.
2. a + d must < 10, or otherwise B or C will be even. There are 20 choices.
3. a and d can not be 0.

There are 600 possibilities.

## 5 digit, $n = abcde$

|       |       |       |       |       |       |
|---    |---    |---    |---    |---    |---    |
|       | a     | b     | c     | d     | e     |
|+)     | e     | d     | c     | b     | a     |
|       | A     | B     | C     | D     | E     |

1. Since A is odd, For E to be odd, then d + b must < 10.
2. Since b + d < 10, there are no carriage for c + c, then C will always be even.

## 6 digit, $n = abcdef$

|       |       |       |       |       |       |       |
|---    |---    |---    |---    |---    |---    |---    |
|       | a     | b     | c     | d     | e     | f     |
|+)     | f     | e     | d     | c     | b     | a     |
|       | A     | B     | C     | D     | E     | F     |

1. For F to be odd, e + b can not have carriage.
2. Since there is no carriage for c + d, c + d must themselves be odd and < 10.
3. Then there are no carriage for e + b.
4. There can not have any carriage in this case.
5. a + f have 20 choices.
6. b + e have 30 choices.
7. c + d have 30 choices.

there are 18000 possibilities.

## 7 digit, $n = abcdefg$

|       |       |       |       |       |       |       |       |
|---    |---    |---    |---    |---    |---    |---    |---    |
|       | a     | b     | c     | d     | e     | f     | g     |
|+)     | g     | f     | e     | d     | c     | b     | a     |
|       | A     | B     | C     | D     | E     | F     | G     |

1. f + b must < 10, there are 25 choices.
2. c + e must > 10, there are 20 choices.
3. d + d must < 10, there are 5 choices.
4. a + g must > 10, there are 20 choices.

there are 50000 possibilities.

## 8 digit, $n = abcdefgh$

|       |       |       |       |       |       |       |       |       |
|---    |---    |---    |---    |---    |---    |---    |---    |---    |
|       | a     | b     | c     | d     | e     | f     | g     | h     |
|+)     | h     | g     | f     | e     | d     | c     | b     | a     |
|       | A     | B     | C     | D     | E     | F     | G     | H     |

There can not be any carriage in this case.  
There are 540000 possibilities.

## 9 digit, $n = abcdefghi$

|       |       |       |       |       |       |       |       |       |       |
|---    |---    |---    |---    |---    |---    |---    |---    |---    |---    |
|       | a     | b     | c     | d     | e     | f     | g     | h     | i     |
|+)     | i     | h     | g     | f     | e     | d     | c     | b     | a     |
|       | A     | B     | C     | D     | E     | F     | G     | H     | I     |

1. For I to be odd, h + b must < 10.
2. There can not be carriage for G, then f + d < 10.
3. There won't be a carriage for e + e, then E will always be even.
