import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Char
import Data.Ratio

ans :: [Integer]
ans = [ maximum [arr!!y * arr!!(x-y) | y <- [1..x-1]] | x <- [0..]]
  where
    arr:: [Integer]
    arr = [solve' x | x <- [0..]]
      where
        solve' :: Int -> Integer
        solve' x
          | x <= 1 = fromIntegral x
          | otherwise = maximum $ fromIntegral x:[ arr!!y * arr!!(x-y)| y <- [1..x-1]]

solve x
  | x <= 0 = error "Invalid range"
  | x == 1 = fromIntegral x
  | x > 50 = ret
  | otherwise = ret
  where
    ret = ans!!x

main :: IO ()
main = getContents >>= mapM_ print. map solve. map (\x->read x::Int). tail. words

