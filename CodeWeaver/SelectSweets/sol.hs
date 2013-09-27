import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char

_mod :: Integer
_mod = 10^9 + 7

_pow :: Integer -> Integer -> Integer
_pow _ 0 = 1
_pow a x = 
	let 
		tmp = _pow a (x `div` 2)
		tmp1 = ( tmp * tmp ) `mod` _mod
	in
		if even x then tmp1 else (tmp1 * a) `mod` _mod

inv x = _pow x (_mod - 2)

fact = scanl (\acc x -> (acc * fromIntegral x ) `mod` _mod) (1::Integer) [(1::Int)..(2000010::Int)]

c :: Integer -> Integer -> Integer
c n r =
 let 
 	num = fact !! fromIntegral n
	den1 = fact !! fromIntegral r
	den2 = fact !! fromIntegral (n-r)
	tmp = (num * (inv den1) ) `mod` _mod
	tmp2 = (tmp * (inv den2)) `mod` _mod
 in tmp2

main = do
	_line <- getLine
	content <- getContents
	let
		[nn, m, _] = map (\x -> read x :: Integer). words $ _line
		n = (\x -> nn - x). foldl (+) 0. map (\x -> read x :: Integer). map last. map words. lines $ content
	print $ c (n+m-1) (m-1)

