import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char

solve x = do
	arr <- sequence [getLine, getLine, getLine, getLine]
	_ <- getLine
	putStr $ "Case #" ++ (show x) ++ ": "
--	print arr
	let
		win x y xadd yadd p = and [ arr!!(x+xadd*add)!!(y+yadd*add) == p || arr!!(x+xadd*add)!!(y+yadd*add) == 'T' | add <- [0..3]]
		isOver =  not$ or [ '.' `elem` x | x <- arr]
		p1 = 'X'
		p2 = 'O'
		p1Win = or [win 0 0 1 0 p1, win 0 1 1 0 p1, win 0 2 1 0 p1, win 0 3 1 0 p1, win 0 0 0 1 p1, win 1 0 0 1 p1, win 2 0 0 1 p1, win 3 0 0 1 p1, win 0 0 1 1 p1, win 0 3 1 (-1) p1]
		p2Win = or [win 0 0 1 0 p2, win 0 1 1 0 p2, win 0 2 1 0 p2, win 0 3 1 0 p2, win 0 0 0 1 p2, win 1 0 0 1 p2, win 2 0 0 1 p2, win 3 0 0 1 p2, win 0 0 1 1 p2, win 0 3 1 (-1) p2]
--	putStrLn $ "isOver = " ++ show isOver
--	putStrLn $ "p1Win = " ++ show p1Win
--	putStrLn $ "p2Win = " ++ show p2Win
	putStrLn $ if p1Win then "X won" else if p2Win then "O won" else if isOver then "Draw" else "Game has not completed"

main :: IO ()
main = do
	line <- getLine
	let
		x = read line :: Int
	mapM_ solve $ [1..x]

