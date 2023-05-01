# Templates

Bislang haben wir Klassentemplates zwar benutzt ( z.B. std::vector<int> ) jetzt wollen wir aber unsere eigene Templateklasse.  
Warum wollen wir das? Die Klasse `CBattleFieldGrid` repräsentiert das Spielfeld, aber wir wollen nicht im Vorfeld festlegen müssen, welchen Datentyp wir da reinpacken. [In unserem Schiffe versenken - Spiel](/battleship.md) wird es ein Zeiger auf einen Button sein, aber wir wollen flexibel bleiben.
Also, machen wir eine [Templateklasse](https://de.wikibooks.org/wiki/C%2B%2B-Programmierung/_Templates/_Klassentemplates).

Wichtig ist zu wissen, wie der Compiler damit umgeht. Ein Template ist weder Klasse noch Funktion. Ein Template ist ein Pattern, welches dem Compiler erlaubt eine Gruppe von Funktion/Klassen zu erzeugen. Wenn wir so programmieren, wie wir es gewöhnt sind (wir trennen Deklaration und Definition) wird es mit an Sicherheit grenzender Wahrscheinlichkeit zu Linkerfehlern kommen, weil der Compiler einfach nicht alle Definitionen sehen kann ([siehe auch](https://de.wikibooks.org/wiki/C%2B%2B-Programmierung/_Templates/_Klassentemplates)). In diesem Artikel findet sich auch die [Lösung](https://isocpp.org/wiki/faq/templates#separate-template-fn-defn-from-decl) für das Problem:  
Entweder packen wir alles in den Header (wir machen das so bei [CBattleFieldGridIterator](/../main/Battleship/Battleship/cbattlefieldgriditerator.h)). Das ist hässlich und bläht den generierten Code auf. Oder man führt eine Art "Registrierung" für alle Anwendungen der Templateklasse ein, welche am Ende der Klassendefinition aufgerufen wird. So geschehen bei [CBattleFieldGrid](/../main/Battleship/Battleship/cbattlefieldgrid.h) Die Registrierung wurde in die Headerdatei [cbattlefieldgridregister](/../main/Battleship/Battleship/cbattlefieldgridregister.h) verlegt.

Generell ist die [FAQ von ISOCpp zu Templates](https://isocpp.org/wiki/faq/templates) echt nützlich aber Vorsicht: 
> This might hurt your head
