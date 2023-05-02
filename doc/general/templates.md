# Templates

## Funktionstempates

Wir können eine Funktion schreiben ohne zu wissen was für Datentypen als Parameter verwendet werden. Dafür gibt es Templates.  
Beispiel:

    template<typename T>
    void output(T s)
    {
        std::cout << s << '\n';
    }

Solange `std::cout` mit der Variable klarkommt, kommt es unser template auch.

## Klassentemplates

Bislang haben wir Klassentemplates zwar benutzt ( z.B. std::vector<int> ) jetzt wollen wir aber unsere eigene Templateklasse.  
Warum wollen wir das? Die Klasse [CBattleFieldGrid](/../main/Battleship/Battleship/cbattlefieldgrid.h) repräsentiert das Spielfeld, aber wir wollen nicht im Vorfeld festlegen müssen, welchen Datentyp wir da reinpacken. [In unserem Schiffe versenken - Spiel](/../Battleship/battleship.md) wird es ein Zeiger auf einen Button sein, aber wir wollen flexibel bleiben.
Also, machen wir eine [Templateklasse](https://de.wikibooks.org/wiki/C%2B%2B-Programmierung/_Templates/_Klassentemplates).  
Beispiel:

    template<class T>
    class TClass()
    {
    public:    
        TClass(T& member) : _member(member){}
    private:
        T _member;
    };
    
Eine Klasse um eine Variable herum gestrickt, deren Typ wir nicht kennen. Wollen wir die Klasse jetzt instantiieren, machen wir einfach:

    TClass<int> c(25);
    
kommt uns bekannt vor oder?
Wichtig ist zu wissen, wie der Compiler damit umgeht. Ein Template ist weder Klasse noch Funktion. Ein Template ist ein Pattern, welches dem Compiler erlaubt eine Gruppe von Funktion/Klassen zu erzeugen. Wenn wir so programmieren, wie wir es gewöhnt sind (wir trennen Deklaration und Definition) wird es mit an Sicherheit grenzender Wahrscheinlichkeit zu Linkerfehlern kommen, weil der Compiler einfach nicht alle Definitionen sehen kann ([siehe auch](https://de.wikibooks.org/wiki/C%2B%2B-Programmierung/_Templates/_Klassentemplates)). In diesem Artikel findet sich auch die [Lösung](https://isocpp.org/wiki/faq/templates#separate-template-fn-defn-from-decl) für das Problem:  
Entweder packen wir alles in den Header (wir machen das so bei [CBattleFieldGridIterator](/../main/Battleship/Battleship/cbattlefieldgriditerator.h)). Das ist hässlich und bläht den generierten Code auf. Oder man führt eine Art "Registrierung" für alle Anwendungen der Templateklasse ein, welche am Ende der Klassendefinition aufgerufen wird. So geschehen bei [CBattleFieldGrid](/../main/Battleship/Battleship/cbattlefieldgrid.h) Die Registrierung wurde in die Headerdatei [cbattlefieldgridregister](/../main/Battleship/Battleship/cbattlefieldgridregister.h) verlegt.

Generell ist die [FAQ von ISOCpp zu Templates](https://isocpp.org/wiki/faq/templates) echt nützlich aber Vorsicht: 
> This might hurt your head

## Hinweis

Für den Compiler gibt es keinen Unterschied zwischen `template<typename T>` und `template<class T>` man kann jedezeit beides verwenden. Für die Lesbarkeit empfielt es sich jedoch `typename` für Funktionstemplates zu benutzen und `class` für Klassentemplates.
