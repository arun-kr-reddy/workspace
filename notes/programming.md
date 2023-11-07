- [structure \& interpretation of computer programs](#structure--interpretation-of-computer-programs)
  - [introduction](#introduction)

# structure & interpretation of computer programs

## links  <!-- omit from toc -->
- [CS 61A](https://www.youtube.com/playlist?list=PLhMnuBfGeCDNgVzLPxF9o5UNKG1b-LFY9)
- [scheme interpreter](https://inst.eecs.berkeley.edu/~cs61a/fa14/assets/interpreter/scheme.html)

## todo  <!-- omit from toc -->

## introduction

in maths we have infix notation `x + y`, prefix notation `sin(x)`, postfix notation `x!` & all around for others `√x`  
scheme uses prefix notation `(+ x y)` uniformly since it is more generic & can take multiple arguments
```scheme
(+ 6 8 1)                    ; 15
(+ 4)                        ; 4
(+)                          ; 0 (additive identity)
(*)                          ; 1 (multiplicative identity)
+                            ; PrimitiveProcedure (functions)
'+                           ; + (quote followed by single word is itself)
(+ (* 3 7) (* 10 10))        ; 121 (composition of functions)
(define pi 3.141592654)      ; pi (define variable)
(define (square x) (* x x))  ; square (define procedure)
(square (+ 1 4))             ; 25
; define is called a special-form since it doesn't evaluate the arguments first
; "x" is formal parameter, "(* x x)" is the body
; "(+ 1 4)" is actual argument expression & 5 is actual argument value
```

**example: area of a square:**
```scheme
(define pi 3.141592654)
(define (square x) (* x x))
(define (area y) (* pi (square y)))
(area 1)                             ; 3.141592654
```

**recursion:** technique of making a function call itself, where solution depends on solutions to smaller instances of the same problem

**example: factorial using recursion:**
```scheme
(define (factorial x)
    (if (= x 0)
        1
        (* x (factorial (- x 1)))))
(factorial 3)                        ; 6
```