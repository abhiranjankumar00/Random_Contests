import Data.List

main :: IO ()
main = do
	line1 <- getLine
	line2 <- getLine
	let
		[n, k] = map (\x -> read x :: Int). words $ line1
		(x:arr) = sort.map (\x -> read x :: Int). words $ line2
	print$ snd . foldl' (\(lst, cnt) y -> if y <= lst+k then (lst, cnt) else (y + k, cnt+1)) (x + k, 1) $ arr


