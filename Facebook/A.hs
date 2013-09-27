---------------------Import--------------------------- {{{
import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char
import Data.Ratio                                   -- x = 5%6
import Data.Bits                                    -- (.&.), (.|.), shiftL...
import Text.Printf                                  -- printf "%0.6f" (1.0)
import qualified Data.ByteString.Char8 as BS-- }}}

---------------------Input---------------------------- {{{
getInteger = (\(Just (x,_)) -> x). BS.readInteger
getInt = (\(Just (x,_)) -> x). BS.readInt

getIntArray = readIntArray
getIntegerArray = readIntegerArray

readIntArray input = 
  case x of
    Just (a, xs) -> a : readIntArray xs
    Nothing -> []
  where
   x = BS.readInt. BS.dropWhile isSpace $ input 

readIntegerArray input = 
  case x of
    Nothing -> []
    Just (y, ys) -> y : readIntegerArray ys
  where
    x = BS.readInteger. BS.dropWhile isSpace $ input
------------------------------------------------------ }}}

main :: IO ()
--main = BS.getContents >>= mapM_ print. map sum. parse. map readIntArray. tail. BS.lines
main = BS.getContents >>= mapM_ print. map sum. parse. map readIntegerArray. tail. BS.lines

--parse :: [[Int]] -> [[Int]]
parse [] = []
parse ([n,k]:xs) = solve (([n, k]: (map sort. map tail $first))) : parse second
  where
    (first, second) = splitAt (fromIntegral n) xs

--solve :: [[Int]] -> [Int]
solve ([n,k]:arr) =
  let
    --ex :: [(Int, Int)]
    ex = (++[(1001, 1001)]). map (\x -> (head x, last x)) $arr

    --findMin :: Int -> [(Int, Int)] -> (Int, Int)
    findMin x xs = foldl' (\(p, q) (a, b) -> if b < x then (p+1,q) else if a < x then (p, q+1) else (p, q) ) (0, 0) xs

    --solveArr :: [[Int]] -> ([(Int, Int)], [(Int, Int)]) -> [Int]
    solveArr [] _ = []
    solveArr arr' (x, (y:ys)) = ( length. filter (==True). map (\(a, b) -> a < k && a+b>=k-1) .map (\( (a, b), (c, d) ) -> (a+c, b+d)). map (\k' -> (findMin k' x, findMin k' ys)) . head $ arr') : (solveArr (tail arr') (y:x, ys) )

  in
    solveArr arr ([], ex)
