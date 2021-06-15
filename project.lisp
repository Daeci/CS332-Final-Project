(defun merge-sort(nums)
  (defun merge-list(l r)
    (cond
      ((= 0 (list-length l)) r)
      ((= 0 (list-length r)) l)
      ((< (car l) (car r)) (append (list (car l)) (merge-list (cdr l) r)))
      ((> (car l) (car r)) (append (list (car r)) (merge-list l (cdr r))))
      ((= (car l) (car r)) (append (list (car l) (car r)) (merge-list (cdr l) (cdr r))))))
  (let ((len (list-length nums)))
    (cond
      ((= len 1) nums)
      (t
         (merge-list (merge-sort (subseq nums 0 (ceiling (/ len 2))))
                 (merge-sort (subseq nums (ceiling (/ len 2)))))))))
                 
(defparameter nums-list (list 7 47 100 22 92 60 97 14 69 54 20 38 45 69 31 36 48 92 51 29 90 24 9 1 60 25 40 99 6 57 23 70 86 72 72 13 92 79 71 61 99 55 8 94 14 32 15 64 73 63))

(write-string "Array before sort: ")
(write nums-list)
(fresh-line)
(terpri)
(write-string "Array after sort: ")
(time (write (merge-sort nums-list)))