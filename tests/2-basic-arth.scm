(load "tests/run-tests.scm")
;; (display (+ 1 201))
;; (newline)

;; (display (modulo 109 11))
;; (newline)

;; (display (> 11 9))
;; (newline)

;; (display (/ 123 7))
;; (newline)

(run-test (+ 1 201))
(run-test (modulo 109 11))
(run-test (> 11 9))
(run-test (/ 123 7))
