_mod :: Integer
_mod = 100000007

mult :: [Integer] -> [Integer] -> [Integer]
mult [a, b, c, d] [p, q, r, s] = [(a*p + b*r) `mod` _mod, (a*q + b*s) `mod` _mod, (c*p + d*r) `mod` _mod, (c*q + d*s) `mod` _mod]

solve :: Int -> [Integer]
solve 0 = [1, 0, 0, 1]
solve n = 
	let
		tmp = solve (n `div` 2)
		tmp1 = mult tmp tmp
	in
		if even n then
			tmp1
			else
				mult tmp1 [1, 1, 1, 0]

main = getContents >>= mapM_ print . map head. map solve.map read. tail. lines
