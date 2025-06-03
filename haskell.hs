-- Función para hacer swap no es necesaria porque Haskell no tiene variables mutables,
-- sino que se crea una nueva lista ordenada con QuickSort

-- Implementación de QuickSort en Haskell
quickSort :: (Ord a) => [a] -> [a]
quickSort [] = []
quickSort (p:xs) =
    let menores = [x | x <- xs, x < p]
        mayoresIguales = [x | x <- xs, x >= p]
    in quickSort menores ++ [p] ++ quickSort mayoresIguales

-- Función para imprimir una lista en una línea
imprimirArreglo :: Show a => [a] -> IO ()
imprimirArreglo xs = putStrLn $ unwords $ map show xs

-- Función principal main
main :: IO ()
main = do
    let arreglo = [15,0,2,10,20,17,5]
    imprimirArreglo arreglo
    let arregloOrdenado = quickSort arreglo
    imprimirArreglo arregloOrdenado
