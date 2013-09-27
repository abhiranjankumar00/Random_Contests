import Text.Printf as P
l=scanl(\a x->a+(if even x then 1.0 else -1.0)/fromIntegral(2*x+1))(0::Double)$[0..10000000]
main=getContents>>= mapM_(P.printf"%.15f\n").map(l!!). map read. tail.words
