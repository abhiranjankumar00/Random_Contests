import Text.Printf as P
a=[solve x|x<-[0..]]
solve 0=1.0::Double
solve n=(if even n then 1.0 else -1.0)/fromIntegral(2*n+1)+(solve(n-1))
main=getContents>>=mapM_(P.printf "%.15f\n").map(\x->a!!(x-1)).map read.tail.words
