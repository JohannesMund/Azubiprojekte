# Battleship


## Iteratoren
Wir nutzen unser Schiffe versenken, um einen tieferen Blick auf Iteratoren zu werfen.

### Was ist ein Iteratoren?

Kurz gesagt, ein Pointer mit Benefits.
Klassisch kapselt ein Iterator die Pointerarithmetik, die man damals(tm) benutzt hat, um sich durch verkettete Listen zu hangeln.
Beispiel:
    
    int i[1000]; //Ein Array mit 1000 integers
    int *it = 0; //Ein Zeiger auf das erste Element des Arrays

Mit Hilfe des Präfix/Postfix Inkrement/Dekrement kann man nun durch den Array navigieren:
    
    int summe = 0;
    while( it != &i[1000] )
    {
       summe += *it;
       ++it;
    }

Dies nennt man Pointerarithmetik und das ist in modernem C++ absolut verpönt.
Warum ist das so?
 * Man weiß nicht, wnn man über den Beginn oder das Ende des Arrays hinauskommt. Die Folge ist ein Crash.
 * Man muss sämtliche Absicherungen im Code implementieren, was gegen den Grundsatz der Abstraktion verstößt
 
Was ist jetzt ein Iterator?
Nun, genau das, nur als Klasse implementiert. Der Container verfügt über eine Begin- und eine End Funktion (in userem Falle ein Array, in diesem Falle `std::begin(i)` und `std::end(i)`) Diese Funktionen haben einen Iterator als Rückgabewert, die auf den Beginn, bzw. das Ende des Containers zeigen.
Jeder STL-Container (z.b. `std::vector`) besitzt passende Iteratoren.
