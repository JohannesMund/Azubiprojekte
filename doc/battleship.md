# Battleship

Wir nutzen unser Schiffe versenken, um einen tieferen Blick auf [Iteratoren](/iterators.md) zu werfen.

## Eigene Iteratoren

Wir haben mit `CBattleFieldGrid` einen eigenen Container gebaut. Da dieser Container nicht von STL - Containern ableitet, hat er auch keine Iteratoren.  
Besser wäre natürlich, wenn `CBattleFieldGrid` entweder von STL Iteratoren ableiten würde, und das Grid in einem eindimensionalen Vektor verwaltet (Was ohne weiteres möglich wäre) Aber es ist wie es ist, eigener Container, eigene Iteratoren. Wir nutzen die Gelegenheit, uns Iteratoren genau anzuschauen.

Werfen wir also eine Blick in die Klasse [CBattleFieldGridIterator](/../main/Battleship/Battleship/cbattlefieldgriditerator.h)  

Zuallererst fällt auf, dass es sich um eine [Template](/tempates.md) Klasse handelt. auch das wäre in unserem Falle nicht notwendig, aber wenn, dann richtig.  
Unser Iterator funktioniert mit einem `TContainerType<TIteratorType>` Das ganze geht natürlich schief, wenn der TContainerType das Interface nicht erfüllt, das wir benötigen, aber was den TIteratorType angeht, sind wir recht frei. (Wir benutzen das im UnitTest, wo wir da einfach INTs reinpumpen).  

Als nächstes, der using - Block:

    using iterator_category = std::random_access_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = std::remove_cv_t<TIteratorType>;
    
iterator_category gibt an, dass wir einen Random Access Iterator haben  
difference_type ist der Datentyp mit dem Der Unterschied zwischen den Containerelementen beschrieben werden kann `std::ptr_diff_t` besagt, dass wir mit Pointerarithmetik hantieren. std::ptr_diff_t ist ein vorzeichenfreier Integertyp.  
value_type gibt an welchen Typ unser Container enthält. Da wir sowohl const- also nicht const Iteratoren wollen, benutzen wir `std::remove_cv_t` welches das für uns normalisiert.

    using pointer = TIteratorType*;
    using reference = TIteratorType&;
    using self_type = CBattleFieldGridIterator;
    
Die drei sind für die bessere Lesbarkeit.

Ansonsten ist es wichtig, sich nochmal die Funktionsweise des *-Operators vor Augen zu führen.   
Wir erinnern uns: * dereferenziert.  
Mit * Kommen wir an den Wert dran, auf dein ein Pointer zeigt. * Wird auch für Container Typen benutzt, um den enthaltenen Wert zu bekommen. Beispielsweise:

    std::optional<int> i;
    if( i.has_value() )
    {
        int j = *i;
    }
    
So auch bei Iteratoren, mit `*it` kommt man an den Wert, auf den der Iterator zeigt. Aus diesem Grunde muss der *-Operator auch für unseren Iterator implementiert werden, und gibt den Wert des Iterators zurück. Wenn wir in vielen Funktionen `*this` zurückgeben, dann passiert was anderes, wir dereferenzieren den this-Zeiger und geben eine Kopie von dem Iterator selbst oder eine Referenz auf den Iterator selbst zurück.  
Das ist schwiertig zu lesen und führt schnell zu Verständnisproblemen.

Ansonsten straight foreward. Es müssen die *, & und -> Operatoren für den Zugriff const und nicht-const implementiert werden.  
Wir brauchen den Postfix und Prefix Inkrement und Dekrement, naturgemäß nicht const.

Für den random access iterator müssen auch + und - implementiert werden und auch ein difference Operator (was ein - Operator ist, der 2x TIteratorType als Input bekommt und den Abstand zwischen beiden als difference_type zurückliefert).

Damit die STL-Algorithmen auch suchen und filtern können, brauchen wir ==, <, >, <=, >=

Ab hier verlassen wir den Standard. Unser Iterator muss seinen Container kennen, um im Grid navigieren zu können. Deswegen bekommt er einen Zeiger mit. Wichtig ist, dass es ein Zeiger ist, damit wir änderungen im Container mitbekommen. Und wenn wir den Container kennen, kennen und definieren wir kurzerhand begin() und end() im Iterator.

Wichtig ist hier auch das Mittel der Abstraktion, Wir implementieren alles nur einmal. Iterator-Code ist schwierig. Durch das Rumreferenziere schwer zu lesen und man hat viel Funktionalität in wenig code. UnitTests sind hier auch extrem wichtig!

