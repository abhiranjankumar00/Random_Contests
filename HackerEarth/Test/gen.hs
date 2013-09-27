import Data.List-- {{{
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char
import Data.Ratio
import qualified Data.ByteString.Char8 as BS-- }}}

getInteger = (\(Just (x,_)) -> x). BS.readInteger-- {{{
getInt = (\(Just (x,_)) -> x). BS.readInt

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
    x = BS.readInteger. BS.dropWhile isSpace $ input-- }}}

main :: IO ()
main = do
  print. length $arr
  mapM_ print arr
  where arr = [2..100]

