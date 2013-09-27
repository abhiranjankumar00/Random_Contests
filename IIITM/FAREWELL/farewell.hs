import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char

count :: [Int] -> [Int] -> (Int, Int)
count [] [] = (0, 0)
count [] as = (0, length as)
count as [] = (length as, 0)

count aas@(a:as) bbs@(b:bs)
 | a == b = (p, q)
 | a < b = (r+1, s)
 | otherwise = (l, m+1)
 	where 
		(p, q) = count as bs
		(l, m) = count aas bs
		(r, s) = count as bbs

main :: IO ()
main = do
	line1 <- getLine
	line2 <- getLine
	line3 <- getLine
	line4 <- getLine
	let
		n = read line1 :: Int
		arr1 = sort. map (\x -> read x:: Int). words $ line2
		m = read line3 :: Int
		arr2 = sort. map (\x -> read x:: Int). words $ line4
		(p, q) = count arr1 arr2
--	print arr1
--	print arr2
--	print $ count arr1 arr2
	putStrLn $ "BOTH " ++ show ((n - p+q) `div` 2)
	putStrLn $ "Quadra " ++ show (p)
	putStrLn $ "PussyCatSinghal " ++ show (q)
