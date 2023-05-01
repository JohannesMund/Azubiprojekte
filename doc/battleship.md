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
 * Man weiß nicht, ob an der Stelle, die man dereferenziert überhaupt etwas steht, der obige Code ist ein garantierter Absturz!

Was ist jetzt ein Iterator?
Nun, genau das, nur als Klasse implementiert. Der Container verfügt über eine Begin- und eine End Funktion (in userem Falle ein Array, in diesem Falle `std::begin(i)` und `std::end(i)`) Diese Funktionen haben einen Iterator als Rückgabewert, die auf den Beginn, bzw. das Ende des Containers zeigen.
Jeder STL-Container (z.b. `std::vector`) besitzt passende Iteratoren.
Unser Code in besser:

    std::vector<int> i;
    auto it = i.begin();
    int summe = 0;
    while(it != i.end() )
    {
        summe += *it:
        ++it;
    }
    
oder noch besser:

    std::vector<int> i;
    for(auto j: i)
    {
        summe += j:
    }
    
Beide Varianten benutzen Iteratoren und sind robust(er). Besser ist es, die STL - Algorithmen zu benutzen.

Für mehr Informationen zu Iteratoren, siehe [C++-Programmierung/ Die STL/ Iteratoren](https://de.wikibooks.org/wiki/C%2B%2B-Programmierung/_Die_STL/_Iteratoren)

### Eigene Iteratoren

Wir haben mit `CBattleFieldGrid` einen eigenen Container gebaut. Da dieser Container nicht von STL - Containern ableitet, hat er auch keine Iteratoren.
Besser wäre natürlich, wenn `CBattleFieldGrid` entweder von STL Iteratoren ableiten würde, und das Grid in einem eindimensionalen Vektor verwaltet (Was ohne weiteres möglich wäre) Aber es ist wie es ist, eigener Container, eigene Iteratoren. Wir nutzen die Gelegenheit, uns Iteratoren genau anzuschauen.

Werfen wir also eine Blick in die Klasse [CBattleFieldGridIterator](/../main/Battleship/Battleship/cbattlefieldgriditerator.h)

Zuallererst fällt auf, dass es sich um eine Template Klasse handelt. auch das wäre in unserem Falle nicht notwendig, aber wenn, dann richtig.
Unser Iterator funktioniert mit einem `TContainerType<TIteratorType>` Das ganze geht natürlich schief, wenn der TContainerType das Interface nicht erfüllt, das wir benötigen, aber was den TIteratorType angeht, sind wir recht frei. (Wir benutzen das im UnitTest, wo wir da einfach INTs reinpumpen).

