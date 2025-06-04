-- Función para hacer swap no es necesaria porque Haskell no tiene variables mutables,
-- sino que se crea una nueva lista ordenada con QuickSort

-- Implementación de QuickSort en Haskell
quickSort :: (Ord a) => [a] -> [a]
quickSort [] = []
quickSort xs =
    let pivote = last xs   -- pivote es el último elemento
        resto = init xs   -- resto es la lista sin el último elemento
        menores = [x | x <- resto, x < pivote]
        mayoresIguales = [x | x <- resto, x >= pivote]
    in quickSort menores ++ [pivote] ++ quickSort mayoresIguales

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
