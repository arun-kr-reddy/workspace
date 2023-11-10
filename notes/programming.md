- [structure \& interpretation of computer programs](#structure--interpretation-of-computer-programs)
  - [introduction](#introduction)

# structure & interpretation of computer programs

## links  <!-- omit from toc -->
- [MIT 1986](https://www.youtube.com/playlist?list=PLE18841CABEA24090)
- [scheme interpreter](https://inst.eecs.berkeley.edu/~cs61a/fa14/assets/interpreter/scheme.html)

## todo  <!-- omit from toc -->

## introduction
- **declarative:** "what is true" knowledge, example: `y` is `sqrt(x)` if `y^2 = x`  
**imperative:** "how to" knowledge, example: square-root by successive averaging of guess `g` & `x/g` until result doesn't change much
- **process:** "how to do things"  
**procedure:** pattern of rules that control the process
- computer science deals with idealised components unlike physical system where one has to worry about constraints of tolerance, approximation & noise  
so for building a large program there isn't much difference between what I can imagine & what I can build
- **techniques for controlling complexity:** make building very large programs possible
  - **black-box abstraction:** putting something in a box to supress details to go ahead & build bigger boxes OR your "how-to" method is an instance of a more general thing, example: fixed point of a function (`f(y) = y`) by succesive applying `f(g)` until result doesn't change much can be used for square-root if `f(g)` is average of `g` & `x/g`
  - **conventional interfaces:** agreed upon ways of plugging things together, example: use `(* x (+ a b))` to add numbers, vectors, polynomial, analog signals etc
  - **metalinguistic abstraction:** pick a new design language to highlight different aspect of the system (supress some kind of details & emphasize others)
- **lisp basics:** for learning any language we need to know three things: primitive elements, means of combination & means of abstraction  
prefix notation `(+ x y)` used uniformly since it is more generic & can take multiple arguments
  ```lisp
  ; primitive elements
  5                             ;5
  3.14                          ; 3.14
  +                             ; PrimitiveProcedure (functions)

  ; means of combination
  ; composition
  (+ 5 3.14 1)                  ; 9.14
  (+ 4 (* 3 6) 8 2)             ; 32
  ; case analysis
  (define (abs x)               ; (using cond)
    (cond ((< x 0) (- x)))
          ((= x 0) 0)
          ((> x 0) x))
  (define (abs x)               ; (using if for single case)
    (if (< x 0)
        (- x)
        x))

  ; means of abstraction
  (define pi 3.14)              ; pi (define variable)
  (* pi pi)                     ; 9.869604403666765
  (define (square x) (* x x))   ; square (define procedure)
  (square (+ 1 4))              ; 25
  square                        ; (lambda (x) (* x x)) (above define is syntactic sugar for this)
                                ; lambda (x) is to construct a procedure with argument x
  ```
- **example: square root by sucessive averaging:**  
**recursive definitions:** allows you to do infinite computations that go on until something is true
  ```lisp
  ; block structure: package internals inside of definition
  (define (sqrt x)
    (define (try g x)                       ; try
      (if (goodenough? g x)
          g
          (try (improve g x) x)))
    (define (improve guess x)               ; improve
      (average guess (/ x guess)))
    (define (goodenough? g x)               ; goodenough?
      (< (abs (- (square x) x))
         0.001))
    (define (square x) (* x x))             ; square
    (define (average x y) (* (+ x y) 0.5))  ; average
    (try 1 x))                              ; sqrt
  (sqrt 2)                                  ; 1.41421568
  ```
- [continue](https://youtu.be/V_7mmwpgJHU?list=PLE18841CABEA24090&t=1)