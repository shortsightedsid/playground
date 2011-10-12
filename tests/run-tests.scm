(define-macro (run-test test)
  `(begin
     (map display '("Running " ',test " => "))
     (display ,test)
     (newline)))
