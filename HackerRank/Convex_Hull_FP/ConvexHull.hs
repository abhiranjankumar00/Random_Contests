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

type Point = (Int, Int)

data Direction = DLeft | DStraight | DRight
  deriving (Show, Eq)

getDirection :: Point -> Point -> Point -> Direction
getDirection (xa, ya) (xb, yb) (xc, yc) = if diff < 0 then DLeft else if diff == 0 then DStraight else DRight
  where
    x1 = xb - xa
    y1 = yb - ya
    x2 = xb - xc
    y2 = yb - yc
    diff = x2*y1 - x1*y2

compareTo :: Point -> Point -> Ordering
compareTo (x1, y1) (x2, y2) = if y1 == y2 then compare x1 x2 else compare y1 y2

getSemiHull :: [Point] -> Direction -> [Point]
getSemiHull [x] _ = [x]
getSemiHull (p:px) dir = 
  let
    prevHull = getSemiHull px dir
    reviseHull :: Point -> [Point] -> [Point]
    reviseHull pt [x] = [p, x]
    reviseHull pt (p1:p2:ps) = if getDirection pt p2 p1 == dir then (pt:p1:p2:ps) else reviseHull pt (p2:ps) 
  in reviseHull p prevHull

getHull :: [Point] -> [Point]
getHull pts = 
  let
    pts' = reverse. sortBy compareTo $ pts
    sortedPoints =  reverse. sortBy compareTo $ pts
    lowerHull = getSemiHull sortedPoints DLeft
    upperHull = getSemiHull sortedPoints DRight
  in lowerHull ++  (tail. reverse $upperHull)

getDistance :: [Point] -> Double 
getDistance [_] = 0.0
getDistance ((x1, y1): (x2, y2):p) = sqrt(fromIntegral ((x2-x1)^2 + (y2-y1)^2) ) + getDistance ((x2, y2):p)


getPoints :: [Int] -> [(Int, Int)]
getPoints [] = []
getPoints (a:b:c) = (a, b):getPoints c

main :: IO ()
--main = getContents >>= printf "%.1f". getDistance. getHull. map (\[x,y] -> (x, y)). map (map read). map words. tail. lines
main = BS.getContents >>= printf "%.1f". getDistance. getHull. getPoints. tail. readIntArray 

