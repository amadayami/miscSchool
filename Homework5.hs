{-
Name: Michael, Amadaya
Net ID: amadayami@unm.edu
-}


-- Note: you cannot put a = b, where b is some built in function. I.e. no myTakeWhile = takeWhile
-- Problem 1, myTakeWhile
myTakeWhile :: (a-> Bool ) -> [a] -> [a]
myTakeWhile _ [] = []
myTakeWhile f (x:xs) = if f x then x : myTakeWhile f xs else []

p1tests = [myTakeWhile (/= ' ') "This is practice." == "This"]


-- Problem 2, mySpan
mySpan :: (a->Bool) -> [a] -> ([a],[a])
mySpan f xs = (takeWhile f xs, dropWhile f xs)

p2tests = [mySpan (/= ' ') "This is practice." == ("This"," is practice.")]


-- Problem 3, combinations3
combinations3 :: Ord a => [a] -> [[a]]
combinations3 = undefined

--permutations' [] = [[]]
--permutations' xs [ x:perms | x <- xs, perms <- permutations' filter (/= x) xs)]

p3tests = [combinations3 "ABCDE" == ["ABC","ABD","ABE","ACD","ACE","ADE","BCD","BCE","BDE","CDE"]]


-- Problem 4, runLengthEncode
runLengthEncode :: Eq a => [a] -> [(a, Int)]
runLengthEncode xs = map makePair (group xs)

group :: Eq a => [a] -> [[a]]
group = foldr f []
 where f x []          = [[x]]
       f x (ys@(y:_):yss) | x == y  = (x:ys):yss | otherwise = [x]:ys:yss

makePair xs = (head xs, length xs)

p4tests = [runLengthEncode [4,2,2,1,1,1,1,4,4,4,4] == [(4,1),(2,2),(1,4),(4,4)], runLengthEncode "foo" == [('f',1),('o',2)]]


-- Problem 5, runLengthDecode
runLengthDecode :: [(a, Int)] -> [a]
--runLengthDecode [] = []
--runLengthDecode (x:xs) = (makeList (fst (head x)) (snd (head x))) ++ runLengthDecode xs
runLengthDecode = undefined
--pullInfo xs = makeList (fst (head xs)) (snd (head xs))

makeList a 0 = []
makeList a x = a : (makeList a (x - 1))

p5tests = [runLengthDecode [(4,1),(2,2),(1,4),(4,4)] == [4,2,2,1,1,1,1,4,4,4,4], (runLengthDecode $ runLengthEncode "foobar") == "foobar"]


-- Problem 6, splitText
splitText :: Ord a => (a -> Bool) -> [a] -> [[a]]
splitText = undefined

p6tests = [splitText (/= ' ') "This is practice." == ["This","is","practice."]]


-- Problem 7, encipher
encipher :: Eq a => [a] -> [b] -> [a] -> [b]

encipher xs ys zs = [ y | z <- zs, (x,y) <- zip xs ys, x == z]

--let2num c = head [ b | (a,b) <- zip ['a'..'z'] [0..25], a==c]

cipher [] [] z = []
cipher (x:xs) (y:ys) z = if x == z then [y] else cipher xs ys z

p7tests = [encipher ['A'..'Z'] ['a'..'z'] "THIS" == "this",encipher [1..10] (map (\x -> x*x) [1..10]) [10,9..1] == [100,81,64,49,36,25,16,9,4,1],encipher [10,9..0] [10,9..0] [0..10] == [0,1,2,3,4,5,6,7,8,9,10],encipher (['A','C'..'Z'] ++ ['B','D'..'Z']) [1..26] ['A'..'Z'] == [1,14,2,15,3,16,4,17,5,18,6,19,7,20,8,21,9,22,10,23,11,24,12,25,13,26]]


-- Problem 8, goldbach
goldbach :: Int -> [(Int, Int)]
goldbach n = [(a,b) | a <- takeWhile (< n) primes, b <- takeWhile (< n) primes, n == a + b]

primes = [x | x <- [2..], isPrime x] where
 isPrime x = divisors x == [1,x]
 divisors x = 1 : [y | y <- [2..(div x 2)], mod x y == 0] ++ [x]

p8tests = [goldbach 6 == [(3,3)], goldbach 9 == [(2,7)]]


-- Problem 9, increasing
increasing :: Ord a => [a] -> Bool
increasing [] = True
increasing [x] = True
increasing (x:xs) = if (x <= head xs) then increasing xs else False

p9tests = [increasing "ABBD", not $ increasing [100,99..1]]


-- Problem 10, select
select :: (t -> Bool) -> [t] -> [a] -> [a]

select _ [] [] = []
select pred xs ys = [ y | (x,y) <- zip xs ys, pred x]

p10tests = [select even [1..26] "abcdefghijklmnopqrstuvwxyz" == "bdfhjlnprtvxz", select (<= 'g') "abcdefghijklmnopqrstuvwxyz" [1..26] == [1,2,3,4,5,6,7]]


-- Problem 11, combinations
combinations :: Ord a => Int -> [a] -> [[a]]
combinations n xs = undefined

p11tests = [combinations 3 "ABCDE" == ["ABC","ABD","ABE","ACD","ACE","ADE","BCD","BCE","BDE","CDE"]]


-- Note: Uncomment the pNtests and in tests below and in tests once you have given a definiton for problem 12

-- Problem 12, ComplexInteger, real, imaginary
data ComplexInteger = ComplexInteger {real :: Int, imaginary :: Int}

-- p12tests = [real (ComplexInteger 1 2) == 1, imaginary (ComplexInteger 2 3) == 3]


-- Problem 13, Eq
-- instance ??? => Eq (ComplexInteger ???) where
instance Eq ComplexInteger where
 (ComplexInteger a b) == (ComplexInteger c d) = (a == c) && (b == d)

p13tests = [(ComplexInteger 1 2) /= (ComplexInteger 3 4)]


-- Problem 14, Show
-- instance ??? => Show (ComplexInteger ???) where
instance Show ComplexInteger where
 show (ComplexInteger x 0) = show x
 show (ComplexInteger 0 y) = show y ++ "i"
 show (ComplexInteger x y) = show x ++ "+" ++ show y ++ "i"

p14tests = [(show $ ComplexInteger 1 2) == "1+2i", (show $ ComplexInteger 1 0) == "1", (show $ ComplexInteger 0 1) == "1i"]


-- Problem 15, Num
-- instance ??? => Num (ComplexInteger ???) where

instance Num ComplexInteger where
 (ComplexInteger a b) * (ComplexInteger c d) = (ComplexInteger ( (a * c) - (b * d) ) ( (a * d) + (b * c) ))
 (ComplexInteger a b) + (ComplexInteger c d) = (ComplexInteger (a + c) (b + d))
 abs (ComplexInteger a b) = (ComplexInteger a b)
 (ComplexInteger a b) - (ComplexInteger c d) = (ComplexInteger (a - c) (b - d))
 signum (ComplexInteger a b) = 1

-- p15tests = [(ComplexInteger 1 2) * (ComplexInteger 3 4) == (ComplexInteger (-5) 10)]


tests = [p1tests,p2tests,p3tests,p4tests,p5tests,p6tests,p7tests,p8tests,p9tests,p10tests,p11tests] -- ++[p12tests,p13tests,p14tests,p15tests]
likelyCorrect = (and [and t | t <- tests], if length tests < 15 then "lacking ComplexInteger tests?" else "")