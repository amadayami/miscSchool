#lang racket
;;problems 1.2, 1.3, 1.4, 1.5, 1.6, 1.10, 1.14
;;2.1, 2.3, 2.4, 2.6, 2.7, 2.10, 2.12, 2.13, 2.14, 2.15, 2.16, 2.18


;; exercise 1.2
(define big-number 10500900)
(define small-number 0.00000025)
(define cheshire 'cat)
(define number1 big-number)
(define number2 'big-number)

;; What values are returned when the following are entered in response to the prompt?
; a. big number => 10500900
; b. small-number => 2.5e-07
; c. 'big-number =>
; d. cheshire => 'cat
; e. 'cheshire => 'cheshire
; f. number1 => 10500900
; g. number2 => 'big-number
; h. 'number1 => 'number1

;; exercise 1.3
; What is the result of entering each of the following expressions in response to the Scheme prompt?
; a. (- 10(- 8 (- 6 4))) => 4
; b. (/ 40 (* 5 20)) => 2/5
; c. (/ 2 3) => 2/3
; d. (+ (* 0.1 20) (/ 4 -3) => 0.6666666666666667

;; exercise 1.4
; Write the Scheme expressions that denote the same calculation as the following arithmetic expressions.
; a. (4 x 7) - (13 + 5) => (- (* 4 7)(+ 13 5))
; b. (3 x (4+(-5 - -3))) => (* 3 (+ 4 (- -5 -3)))
; c. (2.5 / (5 x (1 / 10))) => (/ 2.5 (* 5 (/ 1 10)))
; d. 5 x ((537 x (98.3 + (375 - (2.5 x 153)))) + 255) => (* 5 (+ 255 (* 537 (+ 98.3 (- 375 (* 2.5 153))))))

;; exercise 1.5
; Note for grader: I'm going to use a for alpha, b for beta, and g for gamma since I don't have those characters
; a. (+ a (- (+b g) a)) => a + (a - (b + g))
; b. (+ (* a b) (* g b)) => (a * b) + (g * b)
; c. (/ (- a b) (- a g) => (a - g)/(a - b)

;; exercise 1.6
; a. (cons 'one (cons 'two (cons 'three (cons 'four '()))))
; b. (cons 'one (cons '(two three four) '()))
; c. (cons 'one (cons '(two three) (cons 'four '())))
; d. (cons '(one two) (cons '(three four) '()))
; e. (cons '((one)) '())

;; exercise 1.10
; a. (symbol? (cons a b)) =>
; b. (pair? (cons a b) =>
; c. (null? (cons a b)) =>
; d. (null? (cdr (cons a '()))) =>

;; exercise 1.14
; a. (symbol? (car '(cat mouse))) => #t
; b. (symbol? (cdr '((cat mouse)))) => #f
; c. (symbol? (cdr '(cat mouse))) => #f
; d. (pair? (cons 'hound '(dog))) => #t
; e. (pair? (car '(cheshire cat))) => #f
; f. (pair? (cons '() '())) => #t

;; exercise 2.1
; Define a procedure called second that takes as its argument a list
; and that returns the second item in the list. Assume that the list
; contains at leasr two items.
(define second
 (lambda (ls)
   (car
    (cdr ls))))

;; exercise 2.3
; a. '(1 2)
; b. '((a b) (e f))

;; exercise 2.4
; Define a procedure juggle that rotates a three-element list.
;; 1 to 2, 2 to 3, 3 to 1
(define juggle
  (lambda (ls)
    (cons (car (cdr (cdr ls)))
          (cons (car ls)
             (cons (car (cdr ls)) '())))))

;; exercise 2.6
; a. (and a (or b e)) => #t
; b. (or e (and (not f) a c)) => #t
; c. (not (or (not a) (not b))) => #t
; d. (and (or a f) (not (or b e))) => #f

;; exercise 2.7
; a. Would evaluate to true, one has to be true if the other is false, so the or would have to be true
; b. Would evaluate to false, the two expressions are always opposite, so the and would have to be false
; c. Would evaluate to true, the two expressions for the and can't both evaluate to true, so the not would cancel
; d. Would evaluate to false since the or would be true and the not would negate it

;; exercise 2.10
; Rewrite the definitions of the three procedures last-item,
; member? and remove-1st.
(define last-item
  (lambda (ls)
    (if(not(null? (cdr ls)))
       (last-item (cdr ls))
       (car ls))))

(define member?
  (lambda (item ls)
    (if(null? ls)
       (#f)
       (or(equal? (car ls) item
                  (member? item (cdr ls)))))))

(define remove-1st
  (lambda (item ls)
    (if(null? ls)
       '()
       (if(equal? (car ls) item)
          (cdr ls)
          (cons (car ls) (remove-1st item (cdr ls)))))))

;; exercise 2.12
(define mystery
  (lambda (ls)
    (if (null? (cddr ls))
        (cons (car ls) '())
        (cons (car ls) (mystery (cdr ls))))))
; (mystery '(1 2 3 4 5)) evaluates to '(1 2 3 4). The procedure runs through
; the list and creates a new one with each element, excluding the final one. A
; good name would be remove-last.

;; exercise 2.13
; Define a procedure subst-1st.

;; exercise 2.14
;; Need to define insert-left-1st
(define insert-right-1st
  (lambda (new old ls)
    (cond
      ((null? ls) '())
      ((equal? (car ls) old)
       (cons old (cons new (cdr ls))))
      (else (cons (car ls)
                  (insert-right-1st new old (cdr ls)))))))

;; My code for insert-left-1st implementation
(define insert-left-1st
  (lambda (new old ls)
    (cond
      ((null? ls) '())
      ((equal? (car ls) old)
       (cons new (cons old (cdr ls))))
      (else (cons (car ls)
                  (insert-left-1st new old (cdr ls)))))))

;; exercise 2.15
; Define a procedure list-of-first-items that takes as its argument
; a list of composed of nonempty list of items. Returns a list of
; the first items in each list in the bigger list
(define list-of-first-items
  (lambda (ls)
    (if (null? ls)
        '()
        (cons (car (car ls)) (list-of-first-items (cdr ls))))))
        
;; exercise 2.16
; Define a procedure replace that replaces each top-level item in a list
; of items ls by a given item new-item.
(define replace
  (lambda (new-item ls)
    (if (null? ls)
        '()
        (cons new-item (replace new-item (cdr ls))))))

;; exercise 2.18
; Define a procedure remove-last that removes the last top-level occurence
; of a given element item in a list ls.
(define remove-last
  (lambda (item ls)
    (reverse (remove item (reverse ls)))))