import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char

_mod = 100000007

fact :: Int -> [Int] -> [Int]
fact cnt as
 | cnt > 1000010 = as
 | cnt == 0 = fact 1 [1]
 | cnt == 1 = fact 2 [2, 1]
 | otherwise = fact (cnt+1) (((as!!0 + as!!1) `mod` _mod) : as)

x = reverse $fact 0 []

main :: IO ()
main = do
--	let 
--		x = reverse (fact 0 [])
	_ <- getLine
	line <- getContents
	let 
		y = map (\t -> x !! (t-1)). map (\x -> read x :: Int). lines $ line
--	print $ map (\x -> read x :: Int). lines $ line
	mapM (\x -> print x) y
	return () 

