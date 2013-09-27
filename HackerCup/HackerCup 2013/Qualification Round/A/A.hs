import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char

filterString:: String -> String
filterString []  = []
filterString (x:xs) = if isAlpha x then toLower x : filterString(xs) else filterString (xs)

solve :: Int -> [Int] -> Int
solve _ [] = 0
solve x (s:st) = s*x + solve (x-1) st

appendCase :: Int -> [Int] -> [String]
appendCase _ [] = []
appendCase n (x:xt) = ("Case #" ++ show n ++ ": "  ++ show x) : appendCase (n+1) xt

main :: IO ()
main = getContents >>= mapM_ putStrLn. appendCase 1. map (solve 26). map reverse. map sort. map (map length). map group. map sort. map filterString. tail. lines 
