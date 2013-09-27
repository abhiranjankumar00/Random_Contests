import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char

--main :: IO ()
--main = getContents >>= mapM_ print.(\arr->let mul=foldl (*) 1 arr in map (\x -> mul `div` x) arr).map (\x->read x::Integer).tail.words
 	
main :: IO()
main = do
	_n <- getLine
	content <- getContents
	let
		n = read _n::Int
		arr = map(\x->read x::Integer). words $ content
		zero = length. filter (==0) $ arr
		ans = if zero > 1 then
			take n $ repeat 0
			else if zero == 1 then
				map (\x-> if x ==0 then (foldl (*) 1. filter (/=0) $ arr)  else 0) $ arr
				else
					let mul = foldl (*) 1 arr in map (\x -> mul `div` x) arr
--	print n
--	print arr
--	print zero
--	print ans
	mapM_ print ans

