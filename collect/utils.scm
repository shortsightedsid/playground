;;; Utility functions
;;; This are not specified in R5RS



;; Check if the list is empty
;;
;; @param lst - the list to check
;;
;; @return boolean
(define (empty? lst)
  (if (eq? '() lst)
      #t
      #f))


;; Check if every element of the list passes a predicate
;;
;; @param predicate? - The predicate for each element
;; @param lst        - The list to check
;;
;; @return boolean
(define (every? predicate? lst)
  (if (eq? '() lst) #f
      (let ((checked-results (map predicate? lst)))
        (if (memv #f checked-results) #f #t))))


;; Check if some elements of the list passes a predicate.
;;
;; @param predicate? - The predicate for each element
;; @param lst        - The list to check
;;
;; @return boolean
(define (some? predicate? lst)
  (cond
   ((null? lst) #f)
   ((predicate? (car lst)) #t)
   (else
    (some? predicate? (cdr lst)))))


;; Filter a list against a predicate and returned a list of
;; filtered elements
;;
;; @param predicate? - The predicate for each element
;; @param lst        - The list to check
;;
;; @return list of filtered elements
(define (filter predicate? lst)
  (cond
   ((eq? '() lst) '())
   ((predicate? (car lst)) 
    (cons (car lst) (filter predicate? (cdr lst))))
   (else
    (filter predicate? (cdr lst)))))
