import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char

solve :: Int -> IO()
solve x = do
	line1 <- getLine
	let
		[n, m] = map (\x -> read x :: Int). words $ line1
	arr1 <- sequence $ replicate n getLine
	let
		arr = map (\x -> map (\y -> read y :: Int) x). map (\x -> words x) $ arr1
		mini x y xadd yadd mn 
		 | x == n || y == m = mn
		 | otherwise =  mini (x+xadd) (y+yadd) xadd yadd (min mn (arr!!x!!y))
		row = [ mini x 0 0 1 100 | x <- [0..(n-1)]]
		col = [mini 0 y 1 0 100 | y <- [0..(m-1)]]
		isValid = [ [ arr!!x!!y <= row!!x || arr!!x!!y <= col!!y | y <- [0..(m-1)]]  | x <- [0..(n-1)]]
	putStrLn $ "Case #" ++ show x ++ ": "
--	print arr1
	mapM_ print arr
	putStrLn ""
	print row
	print col
	print isValid
	putStrLn "---"



main :: IO ()
main = do
	line <- getLine
	let
		test = read line :: Int
	mapM_ solve $ [1..test]
