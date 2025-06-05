-- Función para hacer swap no es necesaria porque Haskell no tiene variables mutables,
-- sino que se crea una nueva lista ordenada con QuickSort

import Data.Time.Clock

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
    -- Medir tiempo de ejecución
    start <- getCurrentTime

    let arreglo = [1,2,3,4,5,6,7,8,9]
    imprimirArreglo arreglo
    let arregloOrdenado = quickSort arreglo
    imprimirArreglo arregloOrdenado

    -- Calcular y mostrar el tiempo de ejecución en nanosegundos
    end <- getCurrentTime
    let diff = diffUTCTime end start
        diffInNanoseconds = diff * 1000000000  -- Convertir a nanosegundos
    putStrLn $ "Tiempo de ejecucion: " ++ show (round diffInNanoseconds) ++ " nanosegundos"
