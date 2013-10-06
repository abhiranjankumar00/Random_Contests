module Main where
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

p1 = 993
p2 = 997

p3 = 10099
p4 = 10103

getArr :: (Int, Int) -> Int -> Int -> Int -> [(Int, Int)]
getArr (x, y) n a b = take n. generate $ (x`mod`p1, y`mod`p2)
  where
    generate (x1, y1) = (x1, y1): generate ((x1*a+b)`mod`p1, (y1*b+a)`mod`p2)

main :: IO()
main = do
  let
    arr :: [(Int, Int)]
    arr = getArr (3131, 544) 100000 142 523
    len = length arr
  print len
  mapM_ (\(x, y) -> putStrLn $ (show x) ++ " " ++ (show y)) arr
