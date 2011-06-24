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
