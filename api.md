# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`namespace `[`BattleFieldCoords`](#namespace_battle_field_coords) | [BattleFieldCoords](#namespace_battle_field_coords) Koordinaten auf dem Battlefield.
`namespace `[`GameManagement`](#namespace_game_management) | handelt das [GameManagement](#namespace_game_management)
`namespace `[`QT_WARNING_DISABLE_DEPRECATED`](#namespace_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d) | 
`namespace `[`Randomizer`](#namespace_randomizer) | [Randomizer](#namespace_randomizer) Hilfsfunktionen rund um den Zufall.
`namespace `[`Ui`](#namespace_ui) | 
`class `[`BattleFieldGrid_Test`](#class_battle_field_grid___test) | 
`class `[`CAbstractBattleField`](#class_c_abstract_battle_field) | The [CAbstractBattleField](#class_c_abstract_battle_field) class Repräsentiert das Spielfeld. Enthält Spiel-bezogene Convinience-Funktionen.
`class `[`CAbstractBattleFieldLabel`](#class_c_abstract_battle_field_label) | The [CAbstractBattleFieldLabel](#class_c_abstract_battle_field_label) class Ein Abstraktes Label das Treffer zählt und darstellt.
`class `[`Calculator`](#class_calculator) | [Calculator](#class_calculator) Kapselt die Rechenrei, und schickt Signale wenn was anzuzeigen ist.
`class `[`CalculatorNumber`](#class_calculator_number) | The [CalculatorNumber](#class_calculator_number) class Kapselt eine Zahl, die in der Anzeige des Taschenrechners angezeigt werden kann.
`class `[`CalculatorNumber_Test`](#class_calculator_number___test) | 
`class `[`CBattleFieldButton`](#class_c_battle_field_button) | The [CBattleFieldButton](#class_c_battle_field_button) class Ein Button auf dem Spielfeld. Der Button weiß ob ein Schiff zu ihm gehört, und kenn die ID des schiffs.
`class `[`CBattleFieldGrid`](#class_c_battle_field_grid) | The [CBattleFieldGrid](#class_c_battle_field_grid) class Wir bauen uns einen eigenen, 2 dimensionalen Container.
`class `[`CButtonBox`](#class_c_button_box) | Die Box, die die Buttons enthält. Ein Button pro Spalte.
`class `[`CComputerBattleField`](#class_c_computer_battle_field) | 
`class `[`CComputerBattleFieldLabel`](#class_c_computer_battle_field_label) | The [CComputerBattleFieldLabel](#class_c_computer_battle_field_label) class Das BattlefieldLabel für den Comuterspieler.
`class `[`CComputerPlayer`](#class_c_computer_player) | The [CComputerPlayer](#class_c_computer_player) class Hier haben wir die "KI" implementiert. verbindet das signal "compouterTurn" von [CGameManagement](#class_c_game_management) mit doMove()
`class `[`CDisplay`](#class_c_display) | [CDisplay](#class_c_display) repräsentiert die Anzeige.
`class `[`CDisplayLabel`](#class_c_display_label) | Handelt die Anzeige des Spielstandes.
`class `[`CField`](#class_c_field) | [CField](#class_c_field) Repräsentiert ein Feld auf dem Spielfeld.
`class `[`CGameManagement`](#class_c_game_management) | The [CGameManagement](#class_c_game_management) class Handelt den Spielablauf.
`class `[`CMemoryButton`](#class_c_memory_button) | Repräsentiert eine einzelne Spielkarte.
`class `[`CMineSweeperButton`](#class_c_mine_sweeper_button) | Repräsentiert eine einzelnes Spielfeld.
`class `[`ComputerEnemy`](#class_computer_enemy) | The [ComputerEnemy](#class_computer_enemy) class Repräsentiert den Computergegner.
`class `[`ComputerEnemy_Test`](#class_computer_enemy___test) | 
`class `[`CPlayerBattleField`](#class_c_player_battle_field) | 
`class `[`CPlayerBattleFieldLabel`](#class_c_player_battle_field_label) | The [CPlayerBattleFieldLabel](#class_c_player_battle_field_label) class Das BattlefieldLabel für den Spieler.
`class `[`CPlayerManagement`](#class_c_player_management) | [CPlayerManagement](#class_c_player_management) handelt das [PlayerManagement](#class_player_management), und weiß, welcher Spieler gerade am Zug ist.
`class `[`CPlayerPlacement`](#class_c_player_placement) | The [CPlayerPlacement](#class_c_player_placement) class Hilfsklasse zum Platzieren der Schiffe des Spielers. Verwaltet die Schiffe die zu platzieren sind. Kennt ein Label, auf dass es Text blubbern kann.
`class `[`CPlayField`](#class_c_play_field) | [CPlayField](#class_c_play_field) Das Spielfeld.
`class `[`CResourceHelper`](#class_c_resource_helper) | [CResourceHelper](#class_c_resource_helper) Managed die Recourcen.
`class `[`CShipAtCoords`](#class_c_ship_at_coords) | The [CShipAtCoords](#class_c_ship_at_coords) class Repräsentiert ein Schiff mit koordinaten Man könnte das auch einfach über ein std::pair<BattleFieldCoords::BattleFieldCoords, int> realisieren, da wir hier nur Getter haben und eine funktion von [BattleFieldCoords](#namespace_battle_field_coords) durchreichen, aber die Filter- und Vergleichsfunktionen in der Klasse zu definieren ist convinient und schön abstrakt.
`class `[`CShipVector`](#class_c_ship_vector) | The [CShipVector](#class_c_ship_vector) class Ein Vektor mit Elementen [CShipAtCoords](#class_c_ship_at_coords) Wir leiten das ab, um ein paar Convinience funktionen zu bekommen.
`class `[`MainWindow`](#class_main_window) | 
`class `[`PlayerManagement`](#class_player_management) | The [PlayerManagement](#class_player_management) class Klasse um die SPieler zu verwalten.
`class `[`PlayField`](#class_play_field) | The [PlayField](#class_play_field) class Kapselt das Spielfeld in einerm 3x3 Array.
`class `[`PlayField_Test`](#class_play_field___test) | 
`class `[`PlayFieldCoords_Test`](#class_play_field_coords___test) | 
`class `[`Result`](#class_result) | The [Result](#class_result) class kapselt das Ergebnis der Rechnerei als float.
`class `[`Result_Test`](#class_result___test) | 
`class `[`ShipVector_Test`](#class_ship_vector___test) | 
`class `[`Ui_MainWindow`](#class_ui___main_window) | 
`struct `[`CBattleFieldGridIterator`](#struct_c_battle_field_grid_iterator) | The [CBattleFieldGridIterator](#struct_c_battle_field_grid_iterator) class Wir bauen uns einen Iterator für einen 2 dimensionalen Vektor.
`struct `[`PlayFieldCoords`](#struct_play_field_coords) | The [PlayFieldCoords](#struct_play_field_coords) struct Koordinaten auf dem Spielfeld, mit valid funktion.
`struct `[`TGridSize`](#struct_t_grid_size) | The [TGridSize](#struct_t_grid_size) struct für die Größe bauen wir uns eine Struktur.

# namespace `BattleFieldCoords` 

[BattleFieldCoords](#namespace_battle_field_coords) Koordinaten auf dem Battlefield.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`enum `[`EDirections`](#namespace_battle_field_coords_1ad253a37450970b990cd675e1070c1055)            | The EDirections enum Straight Forward, horizontal oder vertikal.
`struct `[`BattleFieldCoords::BattleFieldCoords`](#struct_battle_field_coords_1_1_battle_field_coords) | The [BattleFieldCoords](#struct_battle_field_coords_1_1_battle_field_coords) struct Repräsentiert Koordinaten auf dem Battlefield.

## Members

#### `enum `[`EDirections`](#namespace_battle_field_coords_1ad253a37450970b990cd675e1070c1055) 

 Values                         | Descriptions                                
--------------------------------|---------------------------------------------
eHorizontal            | 
eVertical            | 

The EDirections enum Straight Forward, horizontal oder vertikal.

# struct `BattleFieldCoords::BattleFieldCoords` 

The [BattleFieldCoords](#struct_battle_field_coords_1_1_battle_field_coords) struct Repräsentiert Koordinaten auf dem Battlefield.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public unsigned int `[`x`](#struct_battle_field_coords_1_1_battle_field_coords_1a4a1ddff7f49ba429f8953a4aa8e6ba67) | 
`public unsigned int `[`y`](#struct_battle_field_coords_1_1_battle_field_coords_1ab9b59fab9703f0076d7026e2b51eab82) | 
`public bool `[`operator==`](#struct_battle_field_coords_1_1_battle_field_coords_1ae1343fe0a8f692f0a7eddf554d8e41a6)`(const `[`BattleFieldCoords`](#struct_battle_field_coords_1_1_battle_field_coords)` & other) const` | operator == Gleichheitsoperator
`public void `[`transpose`](#struct_battle_field_coords_1_1_battle_field_coords_1a3d2c357b912ef54afe6a8305469fc9d6)`(const `[`EDirections`](#namespace_battle_field_coords_1ad253a37450970b990cd675e1070c1055)` dir,const bool min)` | transpose verschiebt die Koordinaten um 1 Feld Richrung Minimum oder Maximum auf der horizontalen oder vertikalen Achse
`public void `[`inc`](#struct_battle_field_coords_1_1_battle_field_coords_1a552ce8a4e3968a5ee489c089ccf61b79)`(const `[`EDirections`](#namespace_battle_field_coords_1ad253a37450970b990cd675e1070c1055)` dir)` | inc Inkrementiert die Koordinaten um ein Feld in Richtung dir
`public void `[`dec`](#struct_battle_field_coords_1_1_battle_field_coords_1a489573c724e19d11b65c69694d9d926e)`(`[`EDirections`](#namespace_battle_field_coords_1ad253a37450970b990cd675e1070c1055)` dir)` | dec Dekrementiert die Koordinaten um ein Feld in Richrung dir

## Members

#### `public unsigned int `[`x`](#struct_battle_field_coords_1_1_battle_field_coords_1a4a1ddff7f49ba429f8953a4aa8e6ba67) 

#### `public unsigned int `[`y`](#struct_battle_field_coords_1_1_battle_field_coords_1ab9b59fab9703f0076d7026e2b51eab82) 

#### `public bool `[`operator==`](#struct_battle_field_coords_1_1_battle_field_coords_1ae1343fe0a8f692f0a7eddf554d8e41a6)`(const `[`BattleFieldCoords`](#struct_battle_field_coords_1_1_battle_field_coords)` & other) const` 

operator == Gleichheitsoperator

#### Parameters
* `other`

#### `public void `[`transpose`](#struct_battle_field_coords_1_1_battle_field_coords_1a3d2c357b912ef54afe6a8305469fc9d6)`(const `[`EDirections`](#namespace_battle_field_coords_1ad253a37450970b990cd675e1070c1055)` dir,const bool min)` 

transpose verschiebt die Koordinaten um 1 Feld Richrung Minimum oder Maximum auf der horizontalen oder vertikalen Achse

#### Parameters
* `dir` 

* `min`

#### `public void `[`inc`](#struct_battle_field_coords_1_1_battle_field_coords_1a552ce8a4e3968a5ee489c089ccf61b79)`(const `[`EDirections`](#namespace_battle_field_coords_1ad253a37450970b990cd675e1070c1055)` dir)` 

inc Inkrementiert die Koordinaten um ein Feld in Richtung dir

#### Parameters
* `dir`

#### `public void `[`dec`](#struct_battle_field_coords_1_1_battle_field_coords_1a489573c724e19d11b65c69694d9d926e)`(`[`EDirections`](#namespace_battle_field_coords_1ad253a37450970b990cd675e1070c1055)` dir)` 

dec Dekrementiert die Koordinaten um ein Feld in Richrung dir

#### Parameters
* `dir`

# namespace `GameManagement` 

handelt das [GameManagement](#namespace_game_management)

als namespace implementiert, da es global verfügbar sein soll und Singletons nicht so geil sind

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`enum `[`EPlayer`](#namespace_game_management_1a6715f5903fec646578e782c98204d15d)            | 
`public void `[`toggleCurrentPlayer`](#namespace_game_management_1a5e57474bd78e263547913a69b6579445)`()`            | toggleCurrentPlayer schaltet zwischen den aktiven Spielern hin und her
`public `[`EPlayer`](#namespace_game_management_1a6715f5903fec646578e782c98204d15d)` `[`getCurrentPlayer`](#namespace_game_management_1a966d34bde3bdb22c9f37f440126a9c8d)`()`            | getCurrentPlayer gibt zurück welcher spieler gerade am start ist.
`public bool `[`isGameRunning`](#namespace_game_management_1af3e9153a553a03b12fb33ac1c110c5d6)`()`            | isGameRunning ermittelt, ob ein Spiel läuft
`public void `[`startGame`](#namespace_game_management_1a74e01139f36dd9830f1dd66def079c3f)`()`            | startGame startet das Spiel
`public void `[`stopGame`](#namespace_game_management_1a175c47c48e8e93c828c8ffa7a55fb833)`()`            | stopGame Beendet das Spiel

## Members

#### `enum `[`EPlayer`](#namespace_game_management_1a6715f5903fec646578e782c98204d15d) 

 Values                         | Descriptions                                
--------------------------------|---------------------------------------------
ePlayer1            | 
ePlayer2            | 

#### `public void `[`toggleCurrentPlayer`](#namespace_game_management_1a5e57474bd78e263547913a69b6579445)`()` 

toggleCurrentPlayer schaltet zwischen den aktiven Spielern hin und her

#### `public `[`EPlayer`](#namespace_game_management_1a6715f5903fec646578e782c98204d15d)` `[`getCurrentPlayer`](#namespace_game_management_1a966d34bde3bdb22c9f37f440126a9c8d)`()` 

getCurrentPlayer gibt zurück welcher spieler gerade am start ist.

#### Returns

#### `public bool `[`isGameRunning`](#namespace_game_management_1af3e9153a553a03b12fb33ac1c110c5d6)`()` 

isGameRunning ermittelt, ob ein Spiel läuft

#### `public void `[`startGame`](#namespace_game_management_1a74e01139f36dd9830f1dd66def079c3f)`()` 

startGame startet das Spiel

#### `public void `[`stopGame`](#namespace_game_management_1a175c47c48e8e93c828c8ffa7a55fb833)`()` 

stopGame Beendet das Spiel

# namespace `QT_WARNING_DISABLE_DEPRECATED` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`struct `[`QT_WARNING_DISABLE_DEPRECATED::qt_meta_stringdata_CLASSCBattleFieldButtonENDCLASS_t`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aab0616bc40c189f4ba682952bc5f4962) | 
`struct `[`QT_WARNING_DISABLE_DEPRECATED::qt_meta_stringdata_CLASSCGameManagementENDCLASS_t`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_af1d052f8e8cc6f6d765518b5fcf4dde4) | 
`struct `[`QT_WARNING_DISABLE_DEPRECATED::qt_meta_stringdata_CLASSCPlayerPlacementENDCLASS_t`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a97c37f023cd94efc7ea296c9fd755c18) | 
`struct `[`QT_WARNING_DISABLE_DEPRECATED::qt_meta_stringdata_CLASSMainWindowENDCLASS_t`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5) | 
`struct `[`QT_WARNING_DISABLE_DEPRECATED::qt_meta_stringdata_CLASSBattleFieldGrid_TestENDCLASS_t`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a917e15d770c93e7c5a7ffac87671ee4a) | 
`struct `[`QT_WARNING_DISABLE_DEPRECATED::qt_meta_stringdata_CLASSShipVector_TestENDCLASS_t`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a8dd12722ab47d1471c21e011c1bb7386) | 
`struct `[`QT_WARNING_DISABLE_DEPRECATED::qt_meta_stringdata_CLASSCButtonBoxENDCLASS_t`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_ad4d16dbb861ea1302a175398e2d768b7) | 
`struct `[`QT_WARNING_DISABLE_DEPRECATED::qt_meta_stringdata_CLASSCDisplayLabelENDCLASS_t`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a9d60a8951a0f8c7addbd3e9ee7ceff0a) | 
`struct `[`QT_WARNING_DISABLE_DEPRECATED::qt_meta_stringdata_CLASSCMemoryButtonENDCLASS_t`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a77f269f13b37cae8c4282c68f7a28812) | 
`struct `[`QT_WARNING_DISABLE_DEPRECATED::qt_meta_stringdata_CLASSCPlayFieldENDCLASS_t`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_add49c403ee60313555e7b8069c579a15) | 
`struct `[`QT_WARNING_DISABLE_DEPRECATED::qt_meta_stringdata_CLASSCMineSweeperButtonENDCLASS_t`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_ababdf8027d72522dc8c876fee50d82b4) | 
`struct `[`QT_WARNING_DISABLE_DEPRECATED::qt_meta_stringdata_CLASSCalculatorENDCLASS_t`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_af01bc13515ae0cfa63b109faab7b0802) | 
`struct `[`QT_WARNING_DISABLE_DEPRECATED::qt_meta_stringdata_CLASSCalculatorNumberENDCLASS_t`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a763500a1d050d46763b99a209d8d1718) | 
`struct `[`QT_WARNING_DISABLE_DEPRECATED::qt_meta_stringdata_CLASSCalculatorNumber_TestENDCLASS_t`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a6a73d0ea3fb8a2acabb6af75a237fa95) | 
`struct `[`QT_WARNING_DISABLE_DEPRECATED::qt_meta_stringdata_CLASSResult_TestENDCLASS_t`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a53bb93236640c991647ed42aec9c6396) | 
`struct `[`QT_WARNING_DISABLE_DEPRECATED::qt_meta_stringdata_CLASSComputerEnemy_TestENDCLASS_t`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_abf462d7ad3b96e86e71f41a7eb2a39aa) | 
`struct `[`QT_WARNING_DISABLE_DEPRECATED::qt_meta_stringdata_CLASSPlayField_TestENDCLASS_t`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a5887b5abfe98afefa6c679034e163a94) | 
`struct `[`QT_WARNING_DISABLE_DEPRECATED::qt_meta_stringdata_CLASSPlayFieldCoords_TestENDCLASS_t`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aeb17f8216c5e975d23b687f1ac300464) | 

# struct `QT_WARNING_DISABLE_DEPRECATED::qt_meta_stringdata_CLASSCBattleFieldButtonENDCLASS_t` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public uint `[`offsetsAndSizes`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aab0616bc40c189f4ba682952bc5f4962_1a971d028682c7f83f15a401fa56b6e4ce) | 
`public char `[`stringdata0`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aab0616bc40c189f4ba682952bc5f4962_1af26fe291fc2f9c723ef96264e63351e0) | 
`public char `[`stringdata1`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aab0616bc40c189f4ba682952bc5f4962_1a7533768dc235872e7e34c6a5fb7ab303) | 
`public char `[`stringdata2`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aab0616bc40c189f4ba682952bc5f4962_1a2d00b8e9fa995237336bab31a5fa21ab) | 

## Members

#### `public uint `[`offsetsAndSizes`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aab0616bc40c189f4ba682952bc5f4962_1a971d028682c7f83f15a401fa56b6e4ce) 

#### `public char `[`stringdata0`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aab0616bc40c189f4ba682952bc5f4962_1af26fe291fc2f9c723ef96264e63351e0) 

#### `public char `[`stringdata1`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aab0616bc40c189f4ba682952bc5f4962_1a7533768dc235872e7e34c6a5fb7ab303) 

#### `public char `[`stringdata2`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aab0616bc40c189f4ba682952bc5f4962_1a2d00b8e9fa995237336bab31a5fa21ab) 

# struct `QT_WARNING_DISABLE_DEPRECATED::qt_meta_stringdata_CLASSCGameManagementENDCLASS_t` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public uint `[`offsetsAndSizes`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_af1d052f8e8cc6f6d765518b5fcf4dde4_1aa9f2e52f59b29c9880a5e6f862e2d4f7) | 
`public char `[`stringdata0`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_af1d052f8e8cc6f6d765518b5fcf4dde4_1a8522facd6132a82c1f88bf1ca636709b) | 
`public char `[`stringdata1`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_af1d052f8e8cc6f6d765518b5fcf4dde4_1a263db454fc8dfae29920768f02d6b8af) | 
`public char `[`stringdata2`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_af1d052f8e8cc6f6d765518b5fcf4dde4_1ae7a3ef44375f778f958d6a24b5b8f955) | 
`public char `[`stringdata3`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_af1d052f8e8cc6f6d765518b5fcf4dde4_1a6d2dad852fa92440ae7e9ac9038ce0b2) | 
`public char `[`stringdata4`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_af1d052f8e8cc6f6d765518b5fcf4dde4_1a109fd14643fd0cdb07999a355437c766) | 
`public char `[`stringdata5`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_af1d052f8e8cc6f6d765518b5fcf4dde4_1a222b2aab7e05664c9149e2c654495b73) | 
`public char `[`stringdata6`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_af1d052f8e8cc6f6d765518b5fcf4dde4_1a82d7d3662a15977293d8fb9f77672c51) | 

## Members

#### `public uint `[`offsetsAndSizes`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_af1d052f8e8cc6f6d765518b5fcf4dde4_1aa9f2e52f59b29c9880a5e6f862e2d4f7) 

#### `public char `[`stringdata0`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_af1d052f8e8cc6f6d765518b5fcf4dde4_1a8522facd6132a82c1f88bf1ca636709b) 

#### `public char `[`stringdata1`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_af1d052f8e8cc6f6d765518b5fcf4dde4_1a263db454fc8dfae29920768f02d6b8af) 

#### `public char `[`stringdata2`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_af1d052f8e8cc6f6d765518b5fcf4dde4_1ae7a3ef44375f778f958d6a24b5b8f955) 

#### `public char `[`stringdata3`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_af1d052f8e8cc6f6d765518b5fcf4dde4_1a6d2dad852fa92440ae7e9ac9038ce0b2) 

#### `public char `[`stringdata4`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_af1d052f8e8cc6f6d765518b5fcf4dde4_1a109fd14643fd0cdb07999a355437c766) 

#### `public char `[`stringdata5`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_af1d052f8e8cc6f6d765518b5fcf4dde4_1a222b2aab7e05664c9149e2c654495b73) 

#### `public char `[`stringdata6`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_af1d052f8e8cc6f6d765518b5fcf4dde4_1a82d7d3662a15977293d8fb9f77672c51) 

# struct `QT_WARNING_DISABLE_DEPRECATED::qt_meta_stringdata_CLASSCPlayerPlacementENDCLASS_t` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public uint `[`offsetsAndSizes`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a97c37f023cd94efc7ea296c9fd755c18_1a9f247d41802aec98d2d38bba8ff9b2fa) | 
`public char `[`stringdata0`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a97c37f023cd94efc7ea296c9fd755c18_1ad7f5051be6407a95ea0bb695d9b909e2) | 
`public char `[`stringdata1`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a97c37f023cd94efc7ea296c9fd755c18_1a2a7b1552783e37bd57d50071bffcf012) | 
`public char `[`stringdata2`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a97c37f023cd94efc7ea296c9fd755c18_1a3032eab3e8f0a0bde51ee4e591ad94f6) | 
`public char `[`stringdata3`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a97c37f023cd94efc7ea296c9fd755c18_1ac17e2bc24fd8ab50735440b757b8f2f3) | 
`public char `[`stringdata4`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a97c37f023cd94efc7ea296c9fd755c18_1a945fe9a0b8c26ff12b22c87b8d62d99f) | 
`public char `[`stringdata5`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a97c37f023cd94efc7ea296c9fd755c18_1a0554297c27c37ddd58262650eae8b699) | 
`public char `[`stringdata6`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a97c37f023cd94efc7ea296c9fd755c18_1af02a3b17b588d2b363b28dc3b6cbc0fc) | 
`public char `[`stringdata7`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a97c37f023cd94efc7ea296c9fd755c18_1a8c814297a2317f7a51360cc5111c592d) | 

## Members

#### `public uint `[`offsetsAndSizes`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a97c37f023cd94efc7ea296c9fd755c18_1a9f247d41802aec98d2d38bba8ff9b2fa) 

#### `public char `[`stringdata0`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a97c37f023cd94efc7ea296c9fd755c18_1ad7f5051be6407a95ea0bb695d9b909e2) 

#### `public char `[`stringdata1`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a97c37f023cd94efc7ea296c9fd755c18_1a2a7b1552783e37bd57d50071bffcf012) 

#### `public char `[`stringdata2`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a97c37f023cd94efc7ea296c9fd755c18_1a3032eab3e8f0a0bde51ee4e591ad94f6) 

#### `public char `[`stringdata3`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a97c37f023cd94efc7ea296c9fd755c18_1ac17e2bc24fd8ab50735440b757b8f2f3) 

#### `public char `[`stringdata4`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a97c37f023cd94efc7ea296c9fd755c18_1a945fe9a0b8c26ff12b22c87b8d62d99f) 

#### `public char `[`stringdata5`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a97c37f023cd94efc7ea296c9fd755c18_1a0554297c27c37ddd58262650eae8b699) 

#### `public char `[`stringdata6`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a97c37f023cd94efc7ea296c9fd755c18_1af02a3b17b588d2b363b28dc3b6cbc0fc) 

#### `public char `[`stringdata7`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a97c37f023cd94efc7ea296c9fd755c18_1a8c814297a2317f7a51360cc5111c592d) 

# struct `QT_WARNING_DISABLE_DEPRECATED::qt_meta_stringdata_CLASSMainWindowENDCLASS_t` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public uint `[`offsetsAndSizes`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5_1a9cc77c34247a3b65019de70fdd09a6b3) | 
`public char `[`stringdata0`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5_1a6c74195db9cf11c464f000ad3bd372f1) | 
`public char `[`stringdata1`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5_1ae21743773ebd6cff3c01772db462bec6) | 
`public char `[`stringdata2`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5_1a1aeaba23c7533572dcee184290245e43) | 
`public char `[`stringdata3`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5_1a847028068c07c838e836651773eeffd2) | 
`public char `[`stringdata4`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5_1aa73c20b2f0219d97f8a058cdd85482d1) | 
`public char `[`stringdata5`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5_1a9343c20e8e47175d1fd7b08764bcfbbd) | 
`public char `[`stringdata6`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5_1a245e786c2d69447401fc6e22e30f3c0c) | 
`public char `[`stringdata7`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5_1a10758510decd44882aa6e7ec1c51627c) | 
`public char `[`stringdata8`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5_1aa272ba6d585f371155ca0767aadcd640) | 
`public char `[`stringdata9`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5_1a8f63e78279713916308cd5455541c0a0) | 
`public char `[`stringdata10`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5_1a52f453d7ad96fd525647be82d61a1d1b) | 
`public char `[`stringdata11`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5_1a18be44744c1f761e98e29df267a395ad) | 
`public char `[`stringdata12`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5_1ae4e64af6e6839318d5f4af35a3389808) | 
`public char `[`stringdata13`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5_1af42cdd79bc2a3d64b76037d439666921) | 
`public char `[`stringdata14`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5_1a948b66e331ccac15fd21d28ec9372185) | 
`public char `[`stringdata15`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5_1a01b12f935afb58e2a3ad1aec2dddb3a2) | 
`public char `[`stringdata16`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5_1afe0fd8dc573c2ead7d450ad66a0279af) | 
`public char `[`stringdata17`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5_1a76b57c8ab7110aeff8f9d38f5611544c) | 
`public char `[`stringdata18`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5_1abd9f3f0dc13061a5e176f1acf8b7e8b5) | 
`public char `[`stringdata19`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5_1a9f69c48f87ae14f346438d208184a8f5) | 
`public char `[`stringdata20`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5_1a823185f40450bf6041133279003d012e) | 
`public char `[`stringdata21`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5_1a51661fb39cbbe7ddd95ee7a3cfecf7ab) | 
`public char `[`stringdata22`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5_1af138745865fbb1df8747ae32b3ab1e7c) | 
`public char `[`stringdata23`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5_1a92f7d249154470608cef3273e632c476) | 
`public char `[`stringdata24`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5_1aecaf1703599b11d847046e9fc204d0d8) | 

## Members

#### `public uint `[`offsetsAndSizes`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5_1a9cc77c34247a3b65019de70fdd09a6b3) 

#### `public char `[`stringdata0`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5_1a6c74195db9cf11c464f000ad3bd372f1) 

#### `public char `[`stringdata1`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5_1ae21743773ebd6cff3c01772db462bec6) 

#### `public char `[`stringdata2`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5_1a1aeaba23c7533572dcee184290245e43) 

#### `public char `[`stringdata3`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5_1a847028068c07c838e836651773eeffd2) 

#### `public char `[`stringdata4`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5_1aa73c20b2f0219d97f8a058cdd85482d1) 

#### `public char `[`stringdata5`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5_1a9343c20e8e47175d1fd7b08764bcfbbd) 

#### `public char `[`stringdata6`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5_1a245e786c2d69447401fc6e22e30f3c0c) 

#### `public char `[`stringdata7`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5_1a10758510decd44882aa6e7ec1c51627c) 

#### `public char `[`stringdata8`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5_1aa272ba6d585f371155ca0767aadcd640) 

#### `public char `[`stringdata9`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5_1a8f63e78279713916308cd5455541c0a0) 

#### `public char `[`stringdata10`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5_1a52f453d7ad96fd525647be82d61a1d1b) 

#### `public char `[`stringdata11`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5_1a18be44744c1f761e98e29df267a395ad) 

#### `public char `[`stringdata12`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5_1ae4e64af6e6839318d5f4af35a3389808) 

#### `public char `[`stringdata13`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5_1af42cdd79bc2a3d64b76037d439666921) 

#### `public char `[`stringdata14`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5_1a948b66e331ccac15fd21d28ec9372185) 

#### `public char `[`stringdata15`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5_1a01b12f935afb58e2a3ad1aec2dddb3a2) 

#### `public char `[`stringdata16`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5_1afe0fd8dc573c2ead7d450ad66a0279af) 

#### `public char `[`stringdata17`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5_1a76b57c8ab7110aeff8f9d38f5611544c) 

#### `public char `[`stringdata18`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5_1abd9f3f0dc13061a5e176f1acf8b7e8b5) 

#### `public char `[`stringdata19`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5_1a9f69c48f87ae14f346438d208184a8f5) 

#### `public char `[`stringdata20`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5_1a823185f40450bf6041133279003d012e) 

#### `public char `[`stringdata21`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5_1a51661fb39cbbe7ddd95ee7a3cfecf7ab) 

#### `public char `[`stringdata22`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5_1af138745865fbb1df8747ae32b3ab1e7c) 

#### `public char `[`stringdata23`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5_1a92f7d249154470608cef3273e632c476) 

#### `public char `[`stringdata24`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aa48c4f7148681482a19d10736c6999b5_1aecaf1703599b11d847046e9fc204d0d8) 

# struct `QT_WARNING_DISABLE_DEPRECATED::qt_meta_stringdata_CLASSBattleFieldGrid_TestENDCLASS_t` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public uint `[`offsetsAndSizes`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a917e15d770c93e7c5a7ffac87671ee4a_1ab5f53bcf771347f74c6de32e4a8e82b2) | 
`public char `[`stringdata0`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a917e15d770c93e7c5a7ffac87671ee4a_1a358f9c344a5dfeecc5e60dfafb557efb) | 
`public char `[`stringdata1`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a917e15d770c93e7c5a7ffac87671ee4a_1adb7aace466042986ef8249746e0d255c) | 
`public char `[`stringdata2`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a917e15d770c93e7c5a7ffac87671ee4a_1af3cb57a4139c3c929fac9d7f68a38c0d) | 
`public char `[`stringdata3`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a917e15d770c93e7c5a7ffac87671ee4a_1a0f770fb44fe0012b133f054af16cb0c4) | 
`public char `[`stringdata4`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a917e15d770c93e7c5a7ffac87671ee4a_1a87926e36e716696c8e8808328c46917a) | 
`public char `[`stringdata5`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a917e15d770c93e7c5a7ffac87671ee4a_1a0bf2461c2d8aa7d216318a1e5622983c) | 
`public char `[`stringdata6`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a917e15d770c93e7c5a7ffac87671ee4a_1a3b7bd48a528169d8a98d27d4c181dd3e) | 
`public char `[`stringdata7`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a917e15d770c93e7c5a7ffac87671ee4a_1ad09330174e26cbfa6f7917b8f3532303) | 
`public char `[`stringdata8`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a917e15d770c93e7c5a7ffac87671ee4a_1a35eb628fe9c08b5d1e98a97ff0873731) | 

## Members

#### `public uint `[`offsetsAndSizes`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a917e15d770c93e7c5a7ffac87671ee4a_1ab5f53bcf771347f74c6de32e4a8e82b2) 

#### `public char `[`stringdata0`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a917e15d770c93e7c5a7ffac87671ee4a_1a358f9c344a5dfeecc5e60dfafb557efb) 

#### `public char `[`stringdata1`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a917e15d770c93e7c5a7ffac87671ee4a_1adb7aace466042986ef8249746e0d255c) 

#### `public char `[`stringdata2`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a917e15d770c93e7c5a7ffac87671ee4a_1af3cb57a4139c3c929fac9d7f68a38c0d) 

#### `public char `[`stringdata3`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a917e15d770c93e7c5a7ffac87671ee4a_1a0f770fb44fe0012b133f054af16cb0c4) 

#### `public char `[`stringdata4`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a917e15d770c93e7c5a7ffac87671ee4a_1a87926e36e716696c8e8808328c46917a) 

#### `public char `[`stringdata5`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a917e15d770c93e7c5a7ffac87671ee4a_1a0bf2461c2d8aa7d216318a1e5622983c) 

#### `public char `[`stringdata6`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a917e15d770c93e7c5a7ffac87671ee4a_1a3b7bd48a528169d8a98d27d4c181dd3e) 

#### `public char `[`stringdata7`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a917e15d770c93e7c5a7ffac87671ee4a_1ad09330174e26cbfa6f7917b8f3532303) 

#### `public char `[`stringdata8`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a917e15d770c93e7c5a7ffac87671ee4a_1a35eb628fe9c08b5d1e98a97ff0873731) 

# struct `QT_WARNING_DISABLE_DEPRECATED::qt_meta_stringdata_CLASSShipVector_TestENDCLASS_t` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public uint `[`offsetsAndSizes`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a8dd12722ab47d1471c21e011c1bb7386_1ae7a3263280011d3f6d516eda3d64c3c9) | 
`public char `[`stringdata0`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a8dd12722ab47d1471c21e011c1bb7386_1ace6fe824c70ad3e09b5fbe47a75aae16) | 
`public char `[`stringdata1`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a8dd12722ab47d1471c21e011c1bb7386_1adca481a0f11ba5b68642de634d77dd7a) | 
`public char `[`stringdata2`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a8dd12722ab47d1471c21e011c1bb7386_1ae12613ec45bf81878d3a1c9b05f85661) | 
`public char `[`stringdata3`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a8dd12722ab47d1471c21e011c1bb7386_1a9b661772ea15dc047ce0e8da49be5708) | 

## Members

#### `public uint `[`offsetsAndSizes`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a8dd12722ab47d1471c21e011c1bb7386_1ae7a3263280011d3f6d516eda3d64c3c9) 

#### `public char `[`stringdata0`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a8dd12722ab47d1471c21e011c1bb7386_1ace6fe824c70ad3e09b5fbe47a75aae16) 

#### `public char `[`stringdata1`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a8dd12722ab47d1471c21e011c1bb7386_1adca481a0f11ba5b68642de634d77dd7a) 

#### `public char `[`stringdata2`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a8dd12722ab47d1471c21e011c1bb7386_1ae12613ec45bf81878d3a1c9b05f85661) 

#### `public char `[`stringdata3`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a8dd12722ab47d1471c21e011c1bb7386_1a9b661772ea15dc047ce0e8da49be5708) 

# struct `QT_WARNING_DISABLE_DEPRECATED::qt_meta_stringdata_CLASSCButtonBoxENDCLASS_t` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public uint `[`offsetsAndSizes`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_ad4d16dbb861ea1302a175398e2d768b7_1a1df9774c701baf2c78b44b6bcfc26120) | 
`public char `[`stringdata0`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_ad4d16dbb861ea1302a175398e2d768b7_1a6d8c9c3b95f4c55c578ccaacf5e85ef3) | 
`public char `[`stringdata1`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_ad4d16dbb861ea1302a175398e2d768b7_1ae0ba3a0004d80404e8284e2ae5d2819b) | 
`public char `[`stringdata2`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_ad4d16dbb861ea1302a175398e2d768b7_1a8c201995dc8ae65dc328f8ee467d7609) | 
`public char `[`stringdata3`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_ad4d16dbb861ea1302a175398e2d768b7_1a9aaa6bbb6e3439d5da2811834f9da323) | 

## Members

#### `public uint `[`offsetsAndSizes`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_ad4d16dbb861ea1302a175398e2d768b7_1a1df9774c701baf2c78b44b6bcfc26120) 

#### `public char `[`stringdata0`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_ad4d16dbb861ea1302a175398e2d768b7_1a6d8c9c3b95f4c55c578ccaacf5e85ef3) 

#### `public char `[`stringdata1`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_ad4d16dbb861ea1302a175398e2d768b7_1ae0ba3a0004d80404e8284e2ae5d2819b) 

#### `public char `[`stringdata2`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_ad4d16dbb861ea1302a175398e2d768b7_1a8c201995dc8ae65dc328f8ee467d7609) 

#### `public char `[`stringdata3`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_ad4d16dbb861ea1302a175398e2d768b7_1a9aaa6bbb6e3439d5da2811834f9da323) 

# struct `QT_WARNING_DISABLE_DEPRECATED::qt_meta_stringdata_CLASSCDisplayLabelENDCLASS_t` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public uint `[`offsetsAndSizes`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a9d60a8951a0f8c7addbd3e9ee7ceff0a_1a41cfc0de65c9d8b268ca7dad91b28064) | 
`public char `[`stringdata0`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a9d60a8951a0f8c7addbd3e9ee7ceff0a_1a414962dfc3881a59b3469302413e412e) | 

## Members

#### `public uint `[`offsetsAndSizes`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a9d60a8951a0f8c7addbd3e9ee7ceff0a_1a41cfc0de65c9d8b268ca7dad91b28064) 

#### `public char `[`stringdata0`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a9d60a8951a0f8c7addbd3e9ee7ceff0a_1a414962dfc3881a59b3469302413e412e) 

# struct `QT_WARNING_DISABLE_DEPRECATED::qt_meta_stringdata_CLASSCMemoryButtonENDCLASS_t` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public uint `[`offsetsAndSizes`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a77f269f13b37cae8c4282c68f7a28812_1a6197203bd443819991589305f5c7762c) | 
`public char `[`stringdata0`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a77f269f13b37cae8c4282c68f7a28812_1a8cddc31d09cd45dd63c8c5ae028de8df) | 
`public char `[`stringdata1`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a77f269f13b37cae8c4282c68f7a28812_1a466675a20f504f7aeaa8fa17b7b80459) | 
`public char `[`stringdata2`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a77f269f13b37cae8c4282c68f7a28812_1ab1c71f78f86c9018814afcee1b1926d6) | 

## Members

#### `public uint `[`offsetsAndSizes`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a77f269f13b37cae8c4282c68f7a28812_1a6197203bd443819991589305f5c7762c) 

#### `public char `[`stringdata0`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a77f269f13b37cae8c4282c68f7a28812_1a8cddc31d09cd45dd63c8c5ae028de8df) 

#### `public char `[`stringdata1`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a77f269f13b37cae8c4282c68f7a28812_1a466675a20f504f7aeaa8fa17b7b80459) 

#### `public char `[`stringdata2`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a77f269f13b37cae8c4282c68f7a28812_1ab1c71f78f86c9018814afcee1b1926d6) 

# struct `QT_WARNING_DISABLE_DEPRECATED::qt_meta_stringdata_CLASSCPlayFieldENDCLASS_t` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public uint `[`offsetsAndSizes`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_add49c403ee60313555e7b8069c579a15_1a05dc4eface3ef0efa118a989f5b70b45) | 
`public char `[`stringdata0`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_add49c403ee60313555e7b8069c579a15_1aef6a66995e7dba5d9721c25f1ee075a4) | 
`public char `[`stringdata1`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_add49c403ee60313555e7b8069c579a15_1a4e61214aba17e4bb7f7dc41c06ce3ef1) | 
`public char `[`stringdata2`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_add49c403ee60313555e7b8069c579a15_1a6b2d2e8295b777f856cb0f8b69bd765d) | 
`public char `[`stringdata3`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_add49c403ee60313555e7b8069c579a15_1acb95d92de3eafc27d9c48b8c9ad8c162) | 
`public char `[`stringdata4`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_add49c403ee60313555e7b8069c579a15_1a49394bd6000cb4a91a98cc8fd8ed59b0) | 
`public char `[`stringdata5`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_add49c403ee60313555e7b8069c579a15_1a73e83c6e6fbbf65573626a73b1baf528) | 

## Members

#### `public uint `[`offsetsAndSizes`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_add49c403ee60313555e7b8069c579a15_1a05dc4eface3ef0efa118a989f5b70b45) 

#### `public char `[`stringdata0`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_add49c403ee60313555e7b8069c579a15_1aef6a66995e7dba5d9721c25f1ee075a4) 

#### `public char `[`stringdata1`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_add49c403ee60313555e7b8069c579a15_1a4e61214aba17e4bb7f7dc41c06ce3ef1) 

#### `public char `[`stringdata2`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_add49c403ee60313555e7b8069c579a15_1a6b2d2e8295b777f856cb0f8b69bd765d) 

#### `public char `[`stringdata3`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_add49c403ee60313555e7b8069c579a15_1acb95d92de3eafc27d9c48b8c9ad8c162) 

#### `public char `[`stringdata4`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_add49c403ee60313555e7b8069c579a15_1a49394bd6000cb4a91a98cc8fd8ed59b0) 

#### `public char `[`stringdata5`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_add49c403ee60313555e7b8069c579a15_1a73e83c6e6fbbf65573626a73b1baf528) 

# struct `QT_WARNING_DISABLE_DEPRECATED::qt_meta_stringdata_CLASSCMineSweeperButtonENDCLASS_t` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public uint `[`offsetsAndSizes`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_ababdf8027d72522dc8c876fee50d82b4_1a8eb4609c1074f5470c3a9d32cfb5bbe0) | 
`public char `[`stringdata0`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_ababdf8027d72522dc8c876fee50d82b4_1a9556febfd91e3d550795942363aa96aa) | 
`public char `[`stringdata1`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_ababdf8027d72522dc8c876fee50d82b4_1a7d1cd430e3c87996a77d69d7a71f1557) | 
`public char `[`stringdata2`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_ababdf8027d72522dc8c876fee50d82b4_1a628577554c6e886c55b19def0de9ab44) | 
`public char `[`stringdata3`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_ababdf8027d72522dc8c876fee50d82b4_1a7be3701f625c551b28ddb5acaafef2be) | 
`public char `[`stringdata4`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_ababdf8027d72522dc8c876fee50d82b4_1a5694a25cd6e39450a0912ae3900e4513) | 
`public char `[`stringdata5`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_ababdf8027d72522dc8c876fee50d82b4_1a9a29452ff680eeae5c6013ee1b7589a3) | 
`public char `[`stringdata6`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_ababdf8027d72522dc8c876fee50d82b4_1adc953004ad3cce6c4d74b2b434b85ff0) | 
`public char `[`stringdata7`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_ababdf8027d72522dc8c876fee50d82b4_1a8798cdaaa62d18624266998612a8b73f) | 
`public char `[`stringdata8`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_ababdf8027d72522dc8c876fee50d82b4_1a9dd8ada3ac03b1964696b3aa66a913b4) | 

## Members

#### `public uint `[`offsetsAndSizes`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_ababdf8027d72522dc8c876fee50d82b4_1a8eb4609c1074f5470c3a9d32cfb5bbe0) 

#### `public char `[`stringdata0`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_ababdf8027d72522dc8c876fee50d82b4_1a9556febfd91e3d550795942363aa96aa) 

#### `public char `[`stringdata1`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_ababdf8027d72522dc8c876fee50d82b4_1a7d1cd430e3c87996a77d69d7a71f1557) 

#### `public char `[`stringdata2`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_ababdf8027d72522dc8c876fee50d82b4_1a628577554c6e886c55b19def0de9ab44) 

#### `public char `[`stringdata3`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_ababdf8027d72522dc8c876fee50d82b4_1a7be3701f625c551b28ddb5acaafef2be) 

#### `public char `[`stringdata4`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_ababdf8027d72522dc8c876fee50d82b4_1a5694a25cd6e39450a0912ae3900e4513) 

#### `public char `[`stringdata5`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_ababdf8027d72522dc8c876fee50d82b4_1a9a29452ff680eeae5c6013ee1b7589a3) 

#### `public char `[`stringdata6`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_ababdf8027d72522dc8c876fee50d82b4_1adc953004ad3cce6c4d74b2b434b85ff0) 

#### `public char `[`stringdata7`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_ababdf8027d72522dc8c876fee50d82b4_1a8798cdaaa62d18624266998612a8b73f) 

#### `public char `[`stringdata8`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_ababdf8027d72522dc8c876fee50d82b4_1a9dd8ada3ac03b1964696b3aa66a913b4) 

# struct `QT_WARNING_DISABLE_DEPRECATED::qt_meta_stringdata_CLASSCalculatorENDCLASS_t` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public uint `[`offsetsAndSizes`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_af01bc13515ae0cfa63b109faab7b0802_1a69165c1fd6a25fa4d9f8d408e7347174) | 
`public char `[`stringdata0`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_af01bc13515ae0cfa63b109faab7b0802_1ad70644043e31be1ae6f1b14629ba661d) | 
`public char `[`stringdata1`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_af01bc13515ae0cfa63b109faab7b0802_1a4446e25f4d04396f60e5a09f500f5d0d) | 
`public char `[`stringdata2`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_af01bc13515ae0cfa63b109faab7b0802_1a85d75c56a82804eae2fae7fcbd3366fd) | 
`public char `[`stringdata3`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_af01bc13515ae0cfa63b109faab7b0802_1a0183699bb6cd446a7d4aca25b0465ce8) | 
`public char `[`stringdata4`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_af01bc13515ae0cfa63b109faab7b0802_1a4a2e38c49352a348a9bf2b7a27213285) | 
`public char `[`stringdata5`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_af01bc13515ae0cfa63b109faab7b0802_1aab84e7a7fda5cb940f83c2e5edb816d3) | 
`public char `[`stringdata6`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_af01bc13515ae0cfa63b109faab7b0802_1ab6044ae7289f3bc2a510cbd2fa25e73f) | 
`public char `[`stringdata7`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_af01bc13515ae0cfa63b109faab7b0802_1ade40c5b190af0cce47942dad097ede65) | 
`public char `[`stringdata8`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_af01bc13515ae0cfa63b109faab7b0802_1ad38fdc559bedce6f4f1c4f64bbb575c0) | 
`public char `[`stringdata9`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_af01bc13515ae0cfa63b109faab7b0802_1a325bea190bfdb00878933fcb061bb488) | 

## Members

#### `public uint `[`offsetsAndSizes`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_af01bc13515ae0cfa63b109faab7b0802_1a69165c1fd6a25fa4d9f8d408e7347174) 

#### `public char `[`stringdata0`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_af01bc13515ae0cfa63b109faab7b0802_1ad70644043e31be1ae6f1b14629ba661d) 

#### `public char `[`stringdata1`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_af01bc13515ae0cfa63b109faab7b0802_1a4446e25f4d04396f60e5a09f500f5d0d) 

#### `public char `[`stringdata2`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_af01bc13515ae0cfa63b109faab7b0802_1a85d75c56a82804eae2fae7fcbd3366fd) 

#### `public char `[`stringdata3`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_af01bc13515ae0cfa63b109faab7b0802_1a0183699bb6cd446a7d4aca25b0465ce8) 

#### `public char `[`stringdata4`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_af01bc13515ae0cfa63b109faab7b0802_1a4a2e38c49352a348a9bf2b7a27213285) 

#### `public char `[`stringdata5`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_af01bc13515ae0cfa63b109faab7b0802_1aab84e7a7fda5cb940f83c2e5edb816d3) 

#### `public char `[`stringdata6`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_af01bc13515ae0cfa63b109faab7b0802_1ab6044ae7289f3bc2a510cbd2fa25e73f) 

#### `public char `[`stringdata7`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_af01bc13515ae0cfa63b109faab7b0802_1ade40c5b190af0cce47942dad097ede65) 

#### `public char `[`stringdata8`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_af01bc13515ae0cfa63b109faab7b0802_1ad38fdc559bedce6f4f1c4f64bbb575c0) 

#### `public char `[`stringdata9`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_af01bc13515ae0cfa63b109faab7b0802_1a325bea190bfdb00878933fcb061bb488) 

# struct `QT_WARNING_DISABLE_DEPRECATED::qt_meta_stringdata_CLASSCalculatorNumberENDCLASS_t` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public uint `[`offsetsAndSizes`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a763500a1d050d46763b99a209d8d1718_1a60533a230fdccaabf404cbfd5e3ee5ce) | 
`public char `[`stringdata0`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a763500a1d050d46763b99a209d8d1718_1a00087f4bb119fa507ec445fe84a4b758) | 
`public char `[`stringdata1`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a763500a1d050d46763b99a209d8d1718_1aaeedd7995125e4c91d253a80c48a86b5) | 
`public char `[`stringdata2`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a763500a1d050d46763b99a209d8d1718_1afd9ef4089e83988e6aaabed1e2727df1) | 
`public char `[`stringdata3`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a763500a1d050d46763b99a209d8d1718_1aeab7ecef42d16c0b20159eee3f25daf1) | 

## Members

#### `public uint `[`offsetsAndSizes`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a763500a1d050d46763b99a209d8d1718_1a60533a230fdccaabf404cbfd5e3ee5ce) 

#### `public char `[`stringdata0`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a763500a1d050d46763b99a209d8d1718_1a00087f4bb119fa507ec445fe84a4b758) 

#### `public char `[`stringdata1`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a763500a1d050d46763b99a209d8d1718_1aaeedd7995125e4c91d253a80c48a86b5) 

#### `public char `[`stringdata2`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a763500a1d050d46763b99a209d8d1718_1afd9ef4089e83988e6aaabed1e2727df1) 

#### `public char `[`stringdata3`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a763500a1d050d46763b99a209d8d1718_1aeab7ecef42d16c0b20159eee3f25daf1) 

# struct `QT_WARNING_DISABLE_DEPRECATED::qt_meta_stringdata_CLASSCalculatorNumber_TestENDCLASS_t` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public uint `[`offsetsAndSizes`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a6a73d0ea3fb8a2acabb6af75a237fa95_1a104560bd9e057b1ddc40c1e9246a747b) | 
`public char `[`stringdata0`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a6a73d0ea3fb8a2acabb6af75a237fa95_1a2e6cbda650f49cad418a26b2afd1844b) | 
`public char `[`stringdata1`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a6a73d0ea3fb8a2acabb6af75a237fa95_1a8743074707f566ea2ea50108b69ed1af) | 
`public char `[`stringdata2`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a6a73d0ea3fb8a2acabb6af75a237fa95_1ab3484eee9d66e61e8f295a2dd54bde6d) | 
`public char `[`stringdata3`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a6a73d0ea3fb8a2acabb6af75a237fa95_1aef63ff16abc51af96a87b8a19a6aedae) | 
`public char `[`stringdata4`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a6a73d0ea3fb8a2acabb6af75a237fa95_1a6cdd0610925bb8d35f293be2ca4d393c) | 
`public char `[`stringdata5`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a6a73d0ea3fb8a2acabb6af75a237fa95_1aa90f652391cd9973bff48ddf71b7d606) | 
`public char `[`stringdata6`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a6a73d0ea3fb8a2acabb6af75a237fa95_1af36bf85faf22813de56373f7f51053e9) | 
`public char `[`stringdata7`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a6a73d0ea3fb8a2acabb6af75a237fa95_1af15068ba79249bdf40d66117b1997487) | 
`public char `[`stringdata8`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a6a73d0ea3fb8a2acabb6af75a237fa95_1a317afb14bbca3a6c767dd9fbef8865cf) | 
`public char `[`stringdata9`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a6a73d0ea3fb8a2acabb6af75a237fa95_1ad590c17e73198ab13ec361edb114241f) | 
`public char `[`stringdata10`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a6a73d0ea3fb8a2acabb6af75a237fa95_1a0ded2c0ba85749b89eb0ade622833286) | 
`public char `[`stringdata11`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a6a73d0ea3fb8a2acabb6af75a237fa95_1adfc88280710fcfe1bb74364635367b50) | 
`public char `[`stringdata12`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a6a73d0ea3fb8a2acabb6af75a237fa95_1a86c24792f4ae2cc24ca023a1915b8b48) | 
`public char `[`stringdata13`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a6a73d0ea3fb8a2acabb6af75a237fa95_1aea8b5e626cc58bfaeeed21d871c09644) | 
`public char `[`stringdata14`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a6a73d0ea3fb8a2acabb6af75a237fa95_1a6369f62b7e0cd513b9371355e2c932cb) | 
`public char `[`stringdata15`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a6a73d0ea3fb8a2acabb6af75a237fa95_1a8cc2e88f94f4e6c9ca315eb7ce8a854e) | 
`public char `[`stringdata16`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a6a73d0ea3fb8a2acabb6af75a237fa95_1aca464a81c769b79bed0d9dcb8ea4f16f) | 
`public char `[`stringdata17`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a6a73d0ea3fb8a2acabb6af75a237fa95_1a18bd310b31a587cebf27623083d8f457) | 

## Members

#### `public uint `[`offsetsAndSizes`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a6a73d0ea3fb8a2acabb6af75a237fa95_1a104560bd9e057b1ddc40c1e9246a747b) 

#### `public char `[`stringdata0`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a6a73d0ea3fb8a2acabb6af75a237fa95_1a2e6cbda650f49cad418a26b2afd1844b) 

#### `public char `[`stringdata1`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a6a73d0ea3fb8a2acabb6af75a237fa95_1a8743074707f566ea2ea50108b69ed1af) 

#### `public char `[`stringdata2`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a6a73d0ea3fb8a2acabb6af75a237fa95_1ab3484eee9d66e61e8f295a2dd54bde6d) 

#### `public char `[`stringdata3`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a6a73d0ea3fb8a2acabb6af75a237fa95_1aef63ff16abc51af96a87b8a19a6aedae) 

#### `public char `[`stringdata4`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a6a73d0ea3fb8a2acabb6af75a237fa95_1a6cdd0610925bb8d35f293be2ca4d393c) 

#### `public char `[`stringdata5`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a6a73d0ea3fb8a2acabb6af75a237fa95_1aa90f652391cd9973bff48ddf71b7d606) 

#### `public char `[`stringdata6`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a6a73d0ea3fb8a2acabb6af75a237fa95_1af36bf85faf22813de56373f7f51053e9) 

#### `public char `[`stringdata7`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a6a73d0ea3fb8a2acabb6af75a237fa95_1af15068ba79249bdf40d66117b1997487) 

#### `public char `[`stringdata8`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a6a73d0ea3fb8a2acabb6af75a237fa95_1a317afb14bbca3a6c767dd9fbef8865cf) 

#### `public char `[`stringdata9`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a6a73d0ea3fb8a2acabb6af75a237fa95_1ad590c17e73198ab13ec361edb114241f) 

#### `public char `[`stringdata10`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a6a73d0ea3fb8a2acabb6af75a237fa95_1a0ded2c0ba85749b89eb0ade622833286) 

#### `public char `[`stringdata11`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a6a73d0ea3fb8a2acabb6af75a237fa95_1adfc88280710fcfe1bb74364635367b50) 

#### `public char `[`stringdata12`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a6a73d0ea3fb8a2acabb6af75a237fa95_1a86c24792f4ae2cc24ca023a1915b8b48) 

#### `public char `[`stringdata13`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a6a73d0ea3fb8a2acabb6af75a237fa95_1aea8b5e626cc58bfaeeed21d871c09644) 

#### `public char `[`stringdata14`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a6a73d0ea3fb8a2acabb6af75a237fa95_1a6369f62b7e0cd513b9371355e2c932cb) 

#### `public char `[`stringdata15`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a6a73d0ea3fb8a2acabb6af75a237fa95_1a8cc2e88f94f4e6c9ca315eb7ce8a854e) 

#### `public char `[`stringdata16`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a6a73d0ea3fb8a2acabb6af75a237fa95_1aca464a81c769b79bed0d9dcb8ea4f16f) 

#### `public char `[`stringdata17`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a6a73d0ea3fb8a2acabb6af75a237fa95_1a18bd310b31a587cebf27623083d8f457) 

# struct `QT_WARNING_DISABLE_DEPRECATED::qt_meta_stringdata_CLASSResult_TestENDCLASS_t` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public uint `[`offsetsAndSizes`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a53bb93236640c991647ed42aec9c6396_1ac9a51bb047e424aa9f06a13cca79d7cc) | 
`public char `[`stringdata0`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a53bb93236640c991647ed42aec9c6396_1a1eca97613795a22a62c4ce7eed6a7af0) | 
`public char `[`stringdata1`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a53bb93236640c991647ed42aec9c6396_1a94dc7041b7c658c6ca44539d6fa61845) | 
`public char `[`stringdata2`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a53bb93236640c991647ed42aec9c6396_1ab8211de5683faab894bf08a45738ae5d) | 
`public char `[`stringdata3`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a53bb93236640c991647ed42aec9c6396_1a8f0a449942b095e980d186c9ce53fbd3) | 

## Members

#### `public uint `[`offsetsAndSizes`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a53bb93236640c991647ed42aec9c6396_1ac9a51bb047e424aa9f06a13cca79d7cc) 

#### `public char `[`stringdata0`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a53bb93236640c991647ed42aec9c6396_1a1eca97613795a22a62c4ce7eed6a7af0) 

#### `public char `[`stringdata1`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a53bb93236640c991647ed42aec9c6396_1a94dc7041b7c658c6ca44539d6fa61845) 

#### `public char `[`stringdata2`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a53bb93236640c991647ed42aec9c6396_1ab8211de5683faab894bf08a45738ae5d) 

#### `public char `[`stringdata3`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a53bb93236640c991647ed42aec9c6396_1a8f0a449942b095e980d186c9ce53fbd3) 

# struct `QT_WARNING_DISABLE_DEPRECATED::qt_meta_stringdata_CLASSComputerEnemy_TestENDCLASS_t` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public uint `[`offsetsAndSizes`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_abf462d7ad3b96e86e71f41a7eb2a39aa_1a7da176a6dada3aa371115708a7b90431) | 
`public char `[`stringdata0`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_abf462d7ad3b96e86e71f41a7eb2a39aa_1ac42ee73adf0dc42382681cc00648aedd) | 
`public char `[`stringdata1`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_abf462d7ad3b96e86e71f41a7eb2a39aa_1acf9a7610d9ed800e69a976db9e51965d) | 
`public char `[`stringdata2`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_abf462d7ad3b96e86e71f41a7eb2a39aa_1aab4be14f2f899fd7092bbf8d90bde737) | 
`public char `[`stringdata3`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_abf462d7ad3b96e86e71f41a7eb2a39aa_1af72032e94f564ace77d4a7b40e0a1496) | 
`public char `[`stringdata4`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_abf462d7ad3b96e86e71f41a7eb2a39aa_1af2b3d3f4767917b3a5f345d7bc35cadd) | 
`public char `[`stringdata5`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_abf462d7ad3b96e86e71f41a7eb2a39aa_1ae30edc7258371df7dfaeff70cbd114e8) | 
`public char `[`stringdata6`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_abf462d7ad3b96e86e71f41a7eb2a39aa_1a62bb9b3fe246bdbe131a29b420a8dee8) | 
`public char `[`stringdata7`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_abf462d7ad3b96e86e71f41a7eb2a39aa_1a40c21dda844be64b39cca7f8a5ccceb7) | 
`public char `[`stringdata8`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_abf462d7ad3b96e86e71f41a7eb2a39aa_1a5dcc1c8c41519f002c8dcd2ae9fc2236) | 
`public char `[`stringdata9`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_abf462d7ad3b96e86e71f41a7eb2a39aa_1af91e17e5cb4a2229528b0038e291cb98) | 

## Members

#### `public uint `[`offsetsAndSizes`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_abf462d7ad3b96e86e71f41a7eb2a39aa_1a7da176a6dada3aa371115708a7b90431) 

#### `public char `[`stringdata0`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_abf462d7ad3b96e86e71f41a7eb2a39aa_1ac42ee73adf0dc42382681cc00648aedd) 

#### `public char `[`stringdata1`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_abf462d7ad3b96e86e71f41a7eb2a39aa_1acf9a7610d9ed800e69a976db9e51965d) 

#### `public char `[`stringdata2`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_abf462d7ad3b96e86e71f41a7eb2a39aa_1aab4be14f2f899fd7092bbf8d90bde737) 

#### `public char `[`stringdata3`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_abf462d7ad3b96e86e71f41a7eb2a39aa_1af72032e94f564ace77d4a7b40e0a1496) 

#### `public char `[`stringdata4`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_abf462d7ad3b96e86e71f41a7eb2a39aa_1af2b3d3f4767917b3a5f345d7bc35cadd) 

#### `public char `[`stringdata5`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_abf462d7ad3b96e86e71f41a7eb2a39aa_1ae30edc7258371df7dfaeff70cbd114e8) 

#### `public char `[`stringdata6`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_abf462d7ad3b96e86e71f41a7eb2a39aa_1a62bb9b3fe246bdbe131a29b420a8dee8) 

#### `public char `[`stringdata7`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_abf462d7ad3b96e86e71f41a7eb2a39aa_1a40c21dda844be64b39cca7f8a5ccceb7) 

#### `public char `[`stringdata8`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_abf462d7ad3b96e86e71f41a7eb2a39aa_1a5dcc1c8c41519f002c8dcd2ae9fc2236) 

#### `public char `[`stringdata9`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_abf462d7ad3b96e86e71f41a7eb2a39aa_1af91e17e5cb4a2229528b0038e291cb98) 

# struct `QT_WARNING_DISABLE_DEPRECATED::qt_meta_stringdata_CLASSPlayField_TestENDCLASS_t` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public uint `[`offsetsAndSizes`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a5887b5abfe98afefa6c679034e163a94_1a60b9a57d7cf419678b473b0c16011f62) | 
`public char `[`stringdata0`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a5887b5abfe98afefa6c679034e163a94_1a3af5b7c26b0fb65ab914385a70f7eb1e) | 
`public char `[`stringdata1`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a5887b5abfe98afefa6c679034e163a94_1a7e92e282ebe3ece51d9ace413287dc5b) | 
`public char `[`stringdata2`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a5887b5abfe98afefa6c679034e163a94_1a9a0547eb1057e93481826d2071754422) | 
`public char `[`stringdata3`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a5887b5abfe98afefa6c679034e163a94_1a466cc16a937a5742b2a7f2f0b892330a) | 
`public char `[`stringdata4`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a5887b5abfe98afefa6c679034e163a94_1aea620c0dcf848c337f64099d7255d694) | 
`public char `[`stringdata5`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a5887b5abfe98afefa6c679034e163a94_1a1e03f297281d2f9773f5ad3758afa27f) | 
`public char `[`stringdata6`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a5887b5abfe98afefa6c679034e163a94_1a9359cdf1f808744cf562f06abc5bc7f1) | 
`public char `[`stringdata7`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a5887b5abfe98afefa6c679034e163a94_1a87e37d08c4718b721807bdf107ccaf9e) | 

## Members

#### `public uint `[`offsetsAndSizes`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a5887b5abfe98afefa6c679034e163a94_1a60b9a57d7cf419678b473b0c16011f62) 

#### `public char `[`stringdata0`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a5887b5abfe98afefa6c679034e163a94_1a3af5b7c26b0fb65ab914385a70f7eb1e) 

#### `public char `[`stringdata1`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a5887b5abfe98afefa6c679034e163a94_1a7e92e282ebe3ece51d9ace413287dc5b) 

#### `public char `[`stringdata2`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a5887b5abfe98afefa6c679034e163a94_1a9a0547eb1057e93481826d2071754422) 

#### `public char `[`stringdata3`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a5887b5abfe98afefa6c679034e163a94_1a466cc16a937a5742b2a7f2f0b892330a) 

#### `public char `[`stringdata4`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a5887b5abfe98afefa6c679034e163a94_1aea620c0dcf848c337f64099d7255d694) 

#### `public char `[`stringdata5`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a5887b5abfe98afefa6c679034e163a94_1a1e03f297281d2f9773f5ad3758afa27f) 

#### `public char `[`stringdata6`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a5887b5abfe98afefa6c679034e163a94_1a9359cdf1f808744cf562f06abc5bc7f1) 

#### `public char `[`stringdata7`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_a5887b5abfe98afefa6c679034e163a94_1a87e37d08c4718b721807bdf107ccaf9e) 

# struct `QT_WARNING_DISABLE_DEPRECATED::qt_meta_stringdata_CLASSPlayFieldCoords_TestENDCLASS_t` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public uint `[`offsetsAndSizes`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aeb17f8216c5e975d23b687f1ac300464_1aba324d841e2f2cc8e206e925179f9698) | 
`public char `[`stringdata0`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aeb17f8216c5e975d23b687f1ac300464_1aee44ee88b1362363807fd16fe239d192) | 
`public char `[`stringdata1`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aeb17f8216c5e975d23b687f1ac300464_1a003c21cce7d0efdc33876c2609569330) | 
`public char `[`stringdata2`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aeb17f8216c5e975d23b687f1ac300464_1a6705d2167d81224072fbebf8d5fb27a6) | 
`public char `[`stringdata3`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aeb17f8216c5e975d23b687f1ac300464_1a5cdb8ee0ac046d4dbd415c7117494702) | 
`public char `[`stringdata4`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aeb17f8216c5e975d23b687f1ac300464_1ac195d013dac8c3e2fb554baf647d6bfb) | 

## Members

#### `public uint `[`offsetsAndSizes`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aeb17f8216c5e975d23b687f1ac300464_1aba324d841e2f2cc8e206e925179f9698) 

#### `public char `[`stringdata0`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aeb17f8216c5e975d23b687f1ac300464_1aee44ee88b1362363807fd16fe239d192) 

#### `public char `[`stringdata1`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aeb17f8216c5e975d23b687f1ac300464_1a003c21cce7d0efdc33876c2609569330) 

#### `public char `[`stringdata2`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aeb17f8216c5e975d23b687f1ac300464_1a6705d2167d81224072fbebf8d5fb27a6) 

#### `public char `[`stringdata3`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aeb17f8216c5e975d23b687f1ac300464_1a5cdb8ee0ac046d4dbd415c7117494702) 

#### `public char `[`stringdata4`](#struct_q_t___w_a_r_n_i_n_g___d_i_s_a_b_l_e___d_e_p_r_e_c_a_t_e_d_1_1qt__meta__stringdata___c_l_aeb17f8216c5e975d23b687f1ac300464_1ac195d013dac8c3e2fb554baf647d6bfb) 

# namespace `Randomizer` 

[Randomizer](#namespace_randomizer) Hilfsfunktionen rund um den Zufall.

Hilfskonstrukt für random funktionen

Hilfsfunktionen

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline void `[`initRand`](#namespace_randomizer_1a794b645d68992b5a4d031255f5c9169c)`()`            | 
`public template<>`  <br/>`void `[`shuffle`](#namespace_randomizer_1aa0e8e81e70733946ad4a4875f5585963)`(T & v)`            | 
`public void `[`shuffle`](#namespace_randomizer_1a318f590f2385299f58ee9730d81cba1a)`(std::vector< unsigned int > & v)`            | shuffle mischelt einen Vektor

## Members

#### `public inline void `[`initRand`](#namespace_randomizer_1a794b645d68992b5a4d031255f5c9169c)`()` 

#### `public template<>`  <br/>`void `[`shuffle`](#namespace_randomizer_1aa0e8e81e70733946ad4a4875f5585963)`(T & v)` 

#### `public void `[`shuffle`](#namespace_randomizer_1a318f590f2385299f58ee9730d81cba1a)`(std::vector< unsigned int > & v)` 

shuffle mischelt einen Vektor

# namespace `Ui` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`Ui::MainWindow`](#class_ui_1_1_main_window) | 

# class `Ui::MainWindow` 

```
class Ui::MainWindow
  : public Ui_MainWindow
  : public Ui_MainWindow
  : public Ui_MainWindow
  : public Ui_MainWindow
  : public Ui_MainWindow
  : public Ui_MainWindow
  : public Ui_MainWindow
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# class `BattleFieldGrid_Test` 

```
class BattleFieldGrid_Test
  : public QObject
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# class `CAbstractBattleField` 

```
class CAbstractBattleField
  : public QFrame
```  

The [CAbstractBattleField](#class_c_abstract_battle_field) class Repräsentiert das Spielfeld. Enthält Spiel-bezogene Convinience-Funktionen.

pure virtual. Muss sowohl für den Computerspieler als auch für den Spieler abgeleitet werden.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline auto `[`begin`](#class_c_abstract_battle_field_1a65fa33a9b4dec78812d90ad4f2d0f6d0)`()` | begin end Wir haben eine Containerklasse im Bauch, und die hat Iteratoren. Die sollen auch von aussen Nutzbar seinl, also reichen wir begin und end nach draussen durch.
`public inline auto `[`end`](#class_c_abstract_battle_field_1af5c4b40faf911e1e9e50d648a6fbdd7d)`()` | 
`public  `[`CAbstractBattleField`](#class_c_abstract_battle_field_1ae17bdc6588dc1fb44cc3971520146224)`(QWidget * parent)` | 
`public void `[`setLabel`](#class_c_abstract_battle_field_1a8919425d8345cbca18a847d5384e8d56)`(`[`CAbstractBattleFieldLabel`](#class_c_abstract_battle_field_label)` * label)` | setLabel Das Spielfeld kennt auch ein Label, dem es mitteilen kann, ob ein Treffer registriert wurde.
`public bool `[`hasShipAround`](#class_c_abstract_battle_field_1a95d6b183e1ddd7bc4212741d99328972)`(const `[`BattleFieldCoords::BattleFieldCoords`](#struct_battle_field_coords_1_1_battle_field_coords)` coords) const` | hasShipAround Ermittelt, um sich um ein feld herum ein schiff befindet.
`public bool `[`hasShipAround_if`](#class_c_abstract_battle_field_1a83e6f65277091fc276e4af84befef382)`(const `[`BattleFieldCoords::BattleFieldCoords`](#struct_battle_field_coords_1_1_battle_field_coords)` coords,`[`fnAround`](#class_c_abstract_battle_field_1a8fb7bd7138ca5d4ce352767ac935b037)` fn) const` | hasShipAround_if Das Gleiche wie hasShipAround, nur kann zusätzlich eine Bedingung angegeben werden
`public bool `[`isInRange`](#class_c_abstract_battle_field_1a874ea81ef42c472570073583ed4e331c)`(const `[`BattleFieldCoords::BattleFieldCoords`](#struct_battle_field_coords_1_1_battle_field_coords)` coords) const` | isInRange prüft, ob gegebene Koordinante innerhalb des BattleFields sind.
`public bool `[`checkForWin`](#class_c_abstract_battle_field_1a08c75401a1e2b0b96fa16d306f4b084c)`() const` | checkForWin Prüft, ob alle Schiffe aufgedeckt sind
`public `[`CBattleFieldButton`](#class_c_battle_field_button)` * `[`at`](#class_c_abstract_battle_field_1aa9eed4d0c9de5178b9665497606f297e)`(const `[`BattleFieldCoords::BattleFieldCoords`](#struct_battle_field_coords_1_1_battle_field_coords)` coords) const` | at Gibt den Button an den Koordinaten coords zurück
`protected `[`CBattleFieldGrid](#class_c_battle_field_grid)< [CBattleFieldButton`](#class_c_battle_field_button)` * > `[`_grid`](#class_c_abstract_battle_field_1ab81efdb0f2ab23688b5040a47aa26eb3) | 
`protected `[`CAbstractBattleFieldLabel`](#class_c_abstract_battle_field_label)` * `[`_label`](#class_c_abstract_battle_field_1a07269dfc71d542de9e3145ec510e7aaa) | 
`protected void `[`init`](#class_c_abstract_battle_field_1a1abfc8084482be263d920de7a27c6d8e)`()` | 
`protected void `[`placeBattleShips`](#class_c_abstract_battle_field_1a91d6b2d9bc8dcda27ca807b1f1bf12c4)`()` | placeBattleShips Virtuell - Wird aufgerufen, wenn es an der Zeit ist, Schiffe zu platzieren.
`protected void `[`startGame`](#class_c_abstract_battle_field_1a80c542e01d9bbd9ac6c8968941850229)`()` | startGame Virtuell - Wird aufgerufen, wenn das Spiel losgeht
`protected void `[`buttonToggled`](#class_c_abstract_battle_field_1a30cdcc6f8a66624c9e1c24d79f7afa54)`(const bool toggleState,const `[`BattleFieldCoords::BattleFieldCoords`](#struct_battle_field_coords_1_1_battle_field_coords)` coords)` | buttonToggled Virtuell - Wird aufgerufen, wenn ein Knopf gedrückt wurde.
`protected void `[`shipHit`](#class_c_abstract_battle_field_1aaab4b98508ea192be21685b21e6d2b1b)`(const `[`BattleFieldCoords::BattleFieldCoords`](#struct_battle_field_coords_1_1_battle_field_coords)` coords)` | shipHit Virtuell - Wird aufgerufen, wenn ein Schiff getroffen wurde.
`protected void `[`clearGrid`](#class_c_abstract_battle_field_1ae809c01e38cab6d0aefedc1d12bf8f11)`()` | 
`protected void `[`enableAll`](#class_c_abstract_battle_field_1a36c433d1aaecdfdb2b29334faf8cb36b)`(const bool bEnable)` | 
`protected void `[`revealAll`](#class_c_abstract_battle_field_1a9df3d6f1bc011d09dca3d8554213eaa3)`()` | 
`typedef `[`fnAround`](#class_c_abstract_battle_field_1a8fb7bd7138ca5d4ce352767ac935b037) | Funktionsdefinition für hasShipAround_if 

## Members

#### `public inline auto `[`begin`](#class_c_abstract_battle_field_1a65fa33a9b4dec78812d90ad4f2d0f6d0)`()` 

begin end Wir haben eine Containerklasse im Bauch, und die hat Iteratoren. Die sollen auch von aussen Nutzbar seinl, also reichen wir begin und end nach draussen durch.

Ja, wir erlauben damit public access auf ein privates Member. Bei genauer Betrachtung aber nicht auf das Private member selbst, wir erlauben den Inhalt zu manipulieren. und wir haben immernoch die Kontrolle. wir können die Iteratoren const machen wenn wir das wollen und, und, und...

#### `public inline auto `[`end`](#class_c_abstract_battle_field_1af5c4b40faf911e1e9e50d648a6fbdd7d)`()` 

#### `public  `[`CAbstractBattleField`](#class_c_abstract_battle_field_1ae17bdc6588dc1fb44cc3971520146224)`(QWidget * parent)` 

#### `public void `[`setLabel`](#class_c_abstract_battle_field_1a8919425d8345cbca18a847d5384e8d56)`(`[`CAbstractBattleFieldLabel`](#class_c_abstract_battle_field_label)` * label)` 

setLabel Das Spielfeld kennt auch ein Label, dem es mitteilen kann, ob ein Treffer registriert wurde.

#### Parameters
* `label`

#### `public bool `[`hasShipAround`](#class_c_abstract_battle_field_1a95d6b183e1ddd7bc4212741d99328972)`(const `[`BattleFieldCoords::BattleFieldCoords`](#struct_battle_field_coords_1_1_battle_field_coords)` coords) const` 

hasShipAround Ermittelt, um sich um ein feld herum ein schiff befindet.

#### Parameters
* `coords` 

#### Returns

#### `public bool `[`hasShipAround_if`](#class_c_abstract_battle_field_1a83e6f65277091fc276e4af84befef382)`(const `[`BattleFieldCoords::BattleFieldCoords`](#struct_battle_field_coords_1_1_battle_field_coords)` coords,`[`fnAround`](#class_c_abstract_battle_field_1a8fb7bd7138ca5d4ce352767ac935b037)` fn) const` 

hasShipAround_if Das Gleiche wie hasShipAround, nur kann zusätzlich eine Bedingung angegeben werden

#### Parameters
* `coords` 

* `fn` eine Funktion vom Typ fnAround 

**See also**: [fnAround](#class_c_abstract_battle_field_1a8fb7bd7138ca5d4ce352767ac935b037)

**See also**: [hasShipAround](#class_c_abstract_battle_field_1a95d6b183e1ddd7bc4212741d99328972)

#### `public bool `[`isInRange`](#class_c_abstract_battle_field_1a874ea81ef42c472570073583ed4e331c)`(const `[`BattleFieldCoords::BattleFieldCoords`](#struct_battle_field_coords_1_1_battle_field_coords)` coords) const` 

isInRange prüft, ob gegebene Koordinante innerhalb des BattleFields sind.

#### Parameters
* `coords`

#### `public bool `[`checkForWin`](#class_c_abstract_battle_field_1a08c75401a1e2b0b96fa16d306f4b084c)`() const` 

checkForWin Prüft, ob alle Schiffe aufgedeckt sind

#### `public `[`CBattleFieldButton`](#class_c_battle_field_button)` * `[`at`](#class_c_abstract_battle_field_1aa9eed4d0c9de5178b9665497606f297e)`(const `[`BattleFieldCoords::BattleFieldCoords`](#struct_battle_field_coords_1_1_battle_field_coords)` coords) const` 

at Gibt den Button an den Koordinaten coords zurück

#### Parameters
* `coords`

#### `protected `[`CBattleFieldGrid](#class_c_battle_field_grid)< [CBattleFieldButton`](#class_c_battle_field_button)` * > `[`_grid`](#class_c_abstract_battle_field_1ab81efdb0f2ab23688b5040a47aa26eb3) 

#### `protected `[`CAbstractBattleFieldLabel`](#class_c_abstract_battle_field_label)` * `[`_label`](#class_c_abstract_battle_field_1a07269dfc71d542de9e3145ec510e7aaa) 

#### `protected void `[`init`](#class_c_abstract_battle_field_1a1abfc8084482be263d920de7a27c6d8e)`()` 

#### `protected void `[`placeBattleShips`](#class_c_abstract_battle_field_1a91d6b2d9bc8dcda27ca807b1f1bf12c4)`()` 

placeBattleShips Virtuell - Wird aufgerufen, wenn es an der Zeit ist, Schiffe zu platzieren.

Muss von den abgeleiteten Klassen implementiert werden

#### `protected void `[`startGame`](#class_c_abstract_battle_field_1a80c542e01d9bbd9ac6c8968941850229)`()` 

startGame Virtuell - Wird aufgerufen, wenn das Spiel losgeht

Muss von den abgeleiteten Klassen implementiert werden

#### `protected void `[`buttonToggled`](#class_c_abstract_battle_field_1a30cdcc6f8a66624c9e1c24d79f7afa54)`(const bool toggleState,const `[`BattleFieldCoords::BattleFieldCoords`](#struct_battle_field_coords_1_1_battle_field_coords)` coords)` 

buttonToggled Virtuell - Wird aufgerufen, wenn ein Knopf gedrückt wurde.

Muss von den abgeleiteten Klassen implementiert werden 

#### Parameters
* `toggleState` 

* `coords`

#### `protected void `[`shipHit`](#class_c_abstract_battle_field_1aaab4b98508ea192be21685b21e6d2b1b)`(const `[`BattleFieldCoords::BattleFieldCoords`](#struct_battle_field_coords_1_1_battle_field_coords)` coords)` 

shipHit Virtuell - Wird aufgerufen, wenn ein Schiff getroffen wurde.

Muss von den abgeleiteten Klassen implementiert werden 

#### Parameters
* `coords`

#### `protected void `[`clearGrid`](#class_c_abstract_battle_field_1ae809c01e38cab6d0aefedc1d12bf8f11)`()` 

#### `protected void `[`enableAll`](#class_c_abstract_battle_field_1a36c433d1aaecdfdb2b29334faf8cb36b)`(const bool bEnable)` 

#### `protected void `[`revealAll`](#class_c_abstract_battle_field_1a9df3d6f1bc011d09dca3d8554213eaa3)`()` 

#### `typedef `[`fnAround`](#class_c_abstract_battle_field_1a8fb7bd7138ca5d4ce352767ac935b037) 

Funktionsdefinition für hasShipAround_if 
**See also**: [hasShipAround_if](#class_c_abstract_battle_field_1a83e6f65277091fc276e4af84befef382)

# class `CAbstractBattleFieldLabel` 

```
class CAbstractBattleFieldLabel
  : public QLabel
```  

The [CAbstractBattleFieldLabel](#class_c_abstract_battle_field_label) class Ein Abstraktes Label das Treffer zählt und darstellt.

pure virtual, muss also noch abgeleitet werden.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public void `[`hit`](#class_c_abstract_battle_field_label_1ab420103e6fceaf44d6218bb5e7af31b8)`(const int id)` | hit Ein Schiff wurde getroffen
`public void `[`update`](#class_c_abstract_battle_field_label_1a6a97517a981337e4511469ee98e54a3b)`()` | update Aktualisiert das Label
`protected std::vector< std::pair< `[`CGameManagement::EShips`](#class_c_game_management_1a25f44a7fe275bfddce7658eeac27f14e)`, unsigned int > > `[`_shipsAndHits`](#class_c_abstract_battle_field_label_1aa653aaaa16d00ddbd179354e4d7a762b) | 
`protected  `[`CAbstractBattleFieldLabel`](#class_c_abstract_battle_field_label_1a5c80adb1565dc2c677bbecd36eaa4639)`(QWidget * parent)` | 
`protected void `[`init`](#class_c_abstract_battle_field_label_1ae945edba2d8e4a313a14dd208cd2f892)`()` | 
`protected QString `[`updateHitArea`](#class_c_abstract_battle_field_label_1ab83240e5165ccf2604a475bd00b0cbdd)`(const int shipId)` | updateHitArea Wir wollen, dass beim Gegner nur angezeitg wird, wenn ein Schiff versenkt wird, beim Spieler die Treffer. Deswegen muss diese FUnktion abgeleitet werden.

## Members

#### `public void `[`hit`](#class_c_abstract_battle_field_label_1ab420103e6fceaf44d6218bb5e7af31b8)`(const int id)` 

hit Ein Schiff wurde getroffen

#### Parameters
* `id`

#### `public void `[`update`](#class_c_abstract_battle_field_label_1a6a97517a981337e4511469ee98e54a3b)`()` 

update Aktualisiert das Label

#### `protected std::vector< std::pair< `[`CGameManagement::EShips`](#class_c_game_management_1a25f44a7fe275bfddce7658eeac27f14e)`, unsigned int > > `[`_shipsAndHits`](#class_c_abstract_battle_field_label_1aa653aaaa16d00ddbd179354e4d7a762b) 

#### `protected  `[`CAbstractBattleFieldLabel`](#class_c_abstract_battle_field_label_1a5c80adb1565dc2c677bbecd36eaa4639)`(QWidget * parent)` 

#### `protected void `[`init`](#class_c_abstract_battle_field_label_1ae945edba2d8e4a313a14dd208cd2f892)`()` 

#### `protected QString `[`updateHitArea`](#class_c_abstract_battle_field_label_1ab83240e5165ccf2604a475bd00b0cbdd)`(const int shipId)` 

updateHitArea Wir wollen, dass beim Gegner nur angezeitg wird, wenn ein Schiff versenkt wird, beim Spieler die Treffer. Deswegen muss diese FUnktion abgeleitet werden.

#### Parameters
* `shipId` 

#### Returns

# class `Calculator` 

```
class Calculator
  : public QObject
```  

[Calculator](#class_calculator) Kapselt die Rechenrei, und schickt Signale wenn was anzuzeigen ist.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  explicit `[`Calculator`](#class_calculator_1ae00996e83767d9cc7bb958b39244180a)`(QObject * parent)` | 
`public void `[`numberPressed`](#class_calculator_1a6ba6db5bbc2d9952090f95ab693720f1)`(const int i)` | numberPressed Schiebt eine Ziffer in [CalculatorNumber](#class_calculator_number)
`public void `[`removeLast`](#class_calculator_1a7edfe1d2349a267248416195f090f949)`()` | removeLast entfernt die letzte Eingabe aus [CalculatorNumber](#class_calculator_number)
`public void `[`commaPressed`](#class_calculator_1acd6e6000560daac8ecdad64fb0f1b71a)`()` | commaPressed Komma wurde gedrückt
`public void `[`negatedPressed`](#class_calculator_1ab9add8d3b2d65bde8f7ef97ae27df7b6)`()` | negatedPressed +/- wurde gedrückt
`public void `[`setOperator`](#class_calculator_1abe0f321b23e317e0a9852bb940b7c626)`(const `[`Operator`](#class_calculator_1af625a689be833826179dc00872985437)` op)` | setOperator
`public void `[`clearCurrent`](#class_calculator_1a7039bbbec8ae0975c303b38fb1db2185)`()` | clearCurrent C/CE
`public void `[`clearAll`](#class_calculator_1a2362ce13a8f2b8d6d025007eeecc75a8)`()` | 
`public void `[`calc`](#class_calculator_1ae6c8965c15fed50a4b396e9fe31baf5d)`()` | calc rechnet
`{signal} public void `[`errorOccured`](#class_calculator_1aed0cbb0335fdef456f25e9249a4441d7)`(const bool b)` | errorOccured wird gesendet, wenn ein Fehler aufgetreten ist (z.B. die Genauigkeit gesprengt wurde, oder DIVby0 oder SQRT(-1)
`{signal} public void `[`resultUpdated`](#class_calculator_1ad02768095b8763b3bfbdd6ab394b20c7)`(const QString & result)` | resultUpdated wird gesendet, wenn sich das ergebniss geändert hat
`{signal} public void `[`numberUpdated`](#class_calculator_1af500dbb247ee5b196ba31b4890f37197)`(const QString & number)` | numberUpdated wird gesendet, wenn sich der aktuelle Operand geändert hat
`{signal} public void `[`operatorUpdated`](#class_calculator_1a8d5e3a86d15875fc1e4b1c9474d38fa3)`(const QString & op)` | operatorUpdated wird gesendet, wenn sich der Operator geändert hat.
`enum `[`Operator`](#class_calculator_1af625a689be833826179dc00872985437) | eOperator unterstützte Operatoren

## Members

#### `public  explicit `[`Calculator`](#class_calculator_1ae00996e83767d9cc7bb958b39244180a)`(QObject * parent)` 

#### `public void `[`numberPressed`](#class_calculator_1a6ba6db5bbc2d9952090f95ab693720f1)`(const int i)` 

numberPressed Schiebt eine Ziffer in [CalculatorNumber](#class_calculator_number)

#### Parameters
* `i`

#### `public void `[`removeLast`](#class_calculator_1a7edfe1d2349a267248416195f090f949)`()` 

removeLast entfernt die letzte Eingabe aus [CalculatorNumber](#class_calculator_number)

#### `public void `[`commaPressed`](#class_calculator_1acd6e6000560daac8ecdad64fb0f1b71a)`()` 

commaPressed Komma wurde gedrückt

#### `public void `[`negatedPressed`](#class_calculator_1ab9add8d3b2d65bde8f7ef97ae27df7b6)`()` 

negatedPressed +/- wurde gedrückt

#### `public void `[`setOperator`](#class_calculator_1abe0f321b23e317e0a9852bb940b7c626)`(const `[`Operator`](#class_calculator_1af625a689be833826179dc00872985437)` op)` 

setOperator

#### Parameters
* `op` gibt den Operator für die nächste Rechnung vor

#### `public void `[`clearCurrent`](#class_calculator_1a7039bbbec8ae0975c303b38fb1db2185)`()` 

clearCurrent C/CE

#### `public void `[`clearAll`](#class_calculator_1a2362ce13a8f2b8d6d025007eeecc75a8)`()` 

#### `public void `[`calc`](#class_calculator_1ae6c8965c15fed50a4b396e9fe31baf5d)`()` 

calc rechnet

#### `{signal} public void `[`errorOccured`](#class_calculator_1aed0cbb0335fdef456f25e9249a4441d7)`(const bool b)` 

errorOccured wird gesendet, wenn ein Fehler aufgetreten ist (z.B. die Genauigkeit gesprengt wurde, oder DIVby0 oder SQRT(-1)

#### Parameters
* `b`

#### `{signal} public void `[`resultUpdated`](#class_calculator_1ad02768095b8763b3bfbdd6ab394b20c7)`(const QString & result)` 

resultUpdated wird gesendet, wenn sich das ergebniss geändert hat

#### Parameters
* `result`

#### `{signal} public void `[`numberUpdated`](#class_calculator_1af500dbb247ee5b196ba31b4890f37197)`(const QString & number)` 

numberUpdated wird gesendet, wenn sich der aktuelle Operand geändert hat

#### Parameters
* `number`

#### `{signal} public void `[`operatorUpdated`](#class_calculator_1a8d5e3a86d15875fc1e4b1c9474d38fa3)`(const QString & op)` 

operatorUpdated wird gesendet, wenn sich der Operator geändert hat.

#### Parameters
* `op`

#### `enum `[`Operator`](#class_calculator_1af625a689be833826179dc00872985437) 

 Values                         | Descriptions                                
--------------------------------|---------------------------------------------
none            | 
plus            | 
minus            | 
division            | 
multiplication            | 
percent            | 
square            | 
squareroot            | 

eOperator unterstützte Operatoren

# class `CalculatorNumber` 

```
class CalculatorNumber
  : public QObject
```  

The [CalculatorNumber](#class_calculator_number) class Kapselt eine Zahl, die in der Anzeige des Taschenrechners angezeigt werden kann.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`CalculatorNumber`](#class_calculator_number_1a041a91da4526cb240678cb007424a8c2)`()` | Standard- und Copykonstruktor.
`public  `[`CalculatorNumber`](#class_calculator_number_1a4bb3c582b6e7a6ee03bbc9b6aac460c7)`(const `[`CalculatorNumber`](#class_calculator_number)` & c)` | 
`public void `[`addDigit`](#class_calculator_number_1a2e5cdc92809cb1dc3920e5b8a7fdfcf5)`(const int i)` | addDigit fügt eine Ziffer hinzu. hierbei wird darauf geachtet, dass andere Eingaben (Komma, +/-, etc) beachtet werden
`public void `[`removeLast`](#class_calculator_number_1a6f4bbc45ec4612eedb7abe2a94f67eb5)`()` | removeLast entfernt die letzte Ziffer oder das komma
`public bool `[`isNull`](#class_calculator_number_1af45d853fab74eee41fe9425ed86fa7f6)`() const` | isNull
`public void `[`setCommaPressed`](#class_calculator_number_1ae793a1db37cd3150636644956b25c465)`(const bool b)` | setCommaPressed es wurde auf komma gedrückt
`public void `[`toggleNegated`](#class_calculator_number_1a14696ae448fef4cb29622d3cb8a94e71)`()` | toggleNegated toggelt +/-
`public double `[`get`](#class_calculator_number_1aab2054ee496ebca5d60e0f1cd8270a0e)`() const` | get
`public void `[`set`](#class_calculator_number_1ac3586ae5f3a98935e080340801ba917e)`(const double d)` | set schreibt einen double
`public void `[`setVolatile`](#class_calculator_number_1a70cf7004dc2273ed8ad053417883264d)`()` | setVolatile setzt den wert volatile, die nächste eingabe wirde den wert resetten
`public QString `[`toString`](#class_calculator_number_1a4a231677095ca32a244d08f9f15bd44a)`() const` | toString
`public void `[`reset`](#class_calculator_number_1af9b4c7efdaa64765b26cb40fbc513f58)`()` | reset setzt die Zahl zurück
`public bool `[`operator==`](#class_calculator_number_1a5510ecbfc40417dba7021a7406b1d6b0)`(const `[`CalculatorNumber`](#class_calculator_number)` & op) const` | Überladene Operatoren.
`public bool `[`operator!=`](#class_calculator_number_1a6c0d071fd0b253160e81857c309f1f33)`(const `[`CalculatorNumber`](#class_calculator_number)` & op) const` | 
`public void `[`operator=`](#class_calculator_number_1a00c0de876d2d23f04e3f458049954dff)`(const `[`CalculatorNumber`](#class_calculator_number)` & op)` | 
`public void `[`operator=`](#class_calculator_number_1a56571ccaeef6c34cf4f0086f048ab92a)`(const double & op)` | 
`public void `[`operator<<`](#class_calculator_number_1a3c2ae08f3f5282a2233fdb5a59904b09)`(const int i)` | 
`public void `[`operator<<`](#class_calculator_number_1a1082eca0004cf152ffa00e3a8fb3c6c3)`(const char c)` | 
`public bool `[`operator>`](#class_calculator_number_1a97c7d6b4a67e9c70d7219fe1ff8d8b17)`(const double op) const` | 
`public bool `[`operator>`](#class_calculator_number_1a60903ef3879f9685218aa8b9dcea9e34)`(const `[`CalculatorNumber`](#class_calculator_number)` & op) const` | 
`public bool `[`operator<`](#class_calculator_number_1abbee600ca80c792aae11c1c873129d24)`(const double op) const` | 
`public bool `[`operator<`](#class_calculator_number_1ab49cab8152174101e1ffa11f62609eb3)`(const `[`CalculatorNumber`](#class_calculator_number)` & op) const` | 
`{signal} public void `[`errorOccured`](#class_calculator_number_1a9622f1c92c49f22bb9c864b8bf4b377a)`(const bool b)` | errorOccured wird emittiert wenn ein Fehler aufgetreten ist (z.B. die maximale Präzision eines floats erreicht wird

## Members

#### `public inline  `[`CalculatorNumber`](#class_calculator_number_1a041a91da4526cb240678cb007424a8c2)`()` 

Standard- und Copykonstruktor.

#### `public  `[`CalculatorNumber`](#class_calculator_number_1a4bb3c582b6e7a6ee03bbc9b6aac460c7)`(const `[`CalculatorNumber`](#class_calculator_number)` & c)` 

#### `public void `[`addDigit`](#class_calculator_number_1a2e5cdc92809cb1dc3920e5b8a7fdfcf5)`(const int i)` 

addDigit fügt eine Ziffer hinzu. hierbei wird darauf geachtet, dass andere Eingaben (Komma, +/-, etc) beachtet werden

#### Parameters
* `i` die hinzuzufügende ziffer

#### `public void `[`removeLast`](#class_calculator_number_1a6f4bbc45ec4612eedb7abe2a94f67eb5)`()` 

removeLast entfernt die letzte Ziffer oder das komma

#### `public bool `[`isNull`](#class_calculator_number_1af45d853fab74eee41fe9425ed86fa7f6)`() const` 

isNull

#### Returns
ob der Wert 0 ist 

[get()](#class_calculator_number_1aab2054ee496ebca5d60e0f1cd8270a0e) == 0 sollte NICHT geprüft werden

#### `public void `[`setCommaPressed`](#class_calculator_number_1ae793a1db37cd3150636644956b25c465)`(const bool b)` 

setCommaPressed es wurde auf komma gedrückt

#### Parameters
* `b` komma hin oder komma weg

#### `public void `[`toggleNegated`](#class_calculator_number_1a14696ae448fef4cb29622d3cb8a94e71)`()` 

toggleNegated toggelt +/-

#### `public double `[`get`](#class_calculator_number_1aab2054ee496ebca5d60e0f1cd8270a0e)`() const` 

get

#### Returns
die Zahl als float

#### `public void `[`set`](#class_calculator_number_1ac3586ae5f3a98935e080340801ba917e)`(const double d)` 

set schreibt einen double

#### Parameters
* `d`

#### `public void `[`setVolatile`](#class_calculator_number_1a70cf7004dc2273ed8ad053417883264d)`()` 

setVolatile setzt den wert volatile, die nächste eingabe wirde den wert resetten

#### `public QString `[`toString`](#class_calculator_number_1a4a231677095ca32a244d08f9f15bd44a)`() const` 

toString

#### Returns
die Zahl als string

#### `public void `[`reset`](#class_calculator_number_1af9b4c7efdaa64765b26cb40fbc513f58)`()` 

reset setzt die Zahl zurück

#### `public bool `[`operator==`](#class_calculator_number_1a5510ecbfc40417dba7021a7406b1d6b0)`(const `[`CalculatorNumber`](#class_calculator_number)` & op) const` 

Überladene Operatoren.

#### `public bool `[`operator!=`](#class_calculator_number_1a6c0d071fd0b253160e81857c309f1f33)`(const `[`CalculatorNumber`](#class_calculator_number)` & op) const` 

#### `public void `[`operator=`](#class_calculator_number_1a00c0de876d2d23f04e3f458049954dff)`(const `[`CalculatorNumber`](#class_calculator_number)` & op)` 

#### `public void `[`operator=`](#class_calculator_number_1a56571ccaeef6c34cf4f0086f048ab92a)`(const double & op)` 

#### `public void `[`operator<<`](#class_calculator_number_1a3c2ae08f3f5282a2233fdb5a59904b09)`(const int i)` 

#### `public void `[`operator<<`](#class_calculator_number_1a1082eca0004cf152ffa00e3a8fb3c6c3)`(const char c)` 

#### `public bool `[`operator>`](#class_calculator_number_1a97c7d6b4a67e9c70d7219fe1ff8d8b17)`(const double op) const` 

#### `public bool `[`operator>`](#class_calculator_number_1a60903ef3879f9685218aa8b9dcea9e34)`(const `[`CalculatorNumber`](#class_calculator_number)` & op) const` 

#### `public bool `[`operator<`](#class_calculator_number_1abbee600ca80c792aae11c1c873129d24)`(const double op) const` 

#### `public bool `[`operator<`](#class_calculator_number_1ab49cab8152174101e1ffa11f62609eb3)`(const `[`CalculatorNumber`](#class_calculator_number)` & op) const` 

#### `{signal} public void `[`errorOccured`](#class_calculator_number_1a9622f1c92c49f22bb9c864b8bf4b377a)`(const bool b)` 

errorOccured wird emittiert wenn ein Fehler aufgetreten ist (z.B. die maximale Präzision eines floats erreicht wird

#### Parameters
* `b` fehler oder nicht fehler, das ist hier die frage

# class `CalculatorNumber_Test` 

```
class CalculatorNumber_Test
  : public QObject
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# class `CBattleFieldButton` 

```
class CBattleFieldButton
  : public QPushButton
```  

The [CBattleFieldButton](#class_c_battle_field_button) class Ein Button auf dem Spielfeld. Der Button weiß ob ein Schiff zu ihm gehört, und kenn die ID des schiffs.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`CBattleFieldButton`](#class_c_battle_field_button_1a8f8ca20e0e6955e2b3f0399a2b788b6e)`()` | 
`public bool `[`hasShip`](#class_c_battle_field_button_1ae779a7753063a5bab75a27d86cb09134)`() const` | hasShip Hat der Button ein Schiff?
`public void `[`setHasShip`](#class_c_battle_field_button_1a096b806a641b33e2a472f9ac2d5240d0)`(const int id,const bool bShow)` | setHasShip Setter, gibt den Button ein Schiff
`public int `[`getShipId`](#class_c_battle_field_button_1a0df46500a164175a0427db6ac878f48b)`() const` | getShipId Gibt die SchiffsID zurück
`public void `[`reveal`](#class_c_battle_field_button_1afed512e02f837e50a8f3aa2acb8154bc)`(const bool bMarkHit)` | reveal Deckt den Button auf. Der Button ist danach nicht mehr klickbar. Wenn er ein Schiff enthält, zeigt er eine Explosion an.
`public bool `[`isRevealed`](#class_c_battle_field_button_1a75a2a92a0e53ce2bdb862236559babfe)`() const` | 
`public bool `[`isRevealedHit`](#class_c_battle_field_button_1aaf875799bd1520f28db40b8a59513607)`() const` | 
`{signal} public void `[`hit`](#class_c_battle_field_button_1a478a07dfa8f6427a64b36ed29d21f010)`()` | hit wird gesendet, wenn der Button aufgedeckt wird, und ein Schiff enthält.

## Members

#### `public  `[`CBattleFieldButton`](#class_c_battle_field_button_1a8f8ca20e0e6955e2b3f0399a2b788b6e)`()` 

#### `public bool `[`hasShip`](#class_c_battle_field_button_1ae779a7753063a5bab75a27d86cb09134)`() const` 

hasShip Hat der Button ein Schiff?

#### `public void `[`setHasShip`](#class_c_battle_field_button_1a096b806a641b33e2a472f9ac2d5240d0)`(const int id,const bool bShow)` 

setHasShip Setter, gibt den Button ein Schiff

#### Parameters
* `id` 

* `bShow` gibt an ob der Button auch markiert werden soll (für das Placement des Spielers

#### `public int `[`getShipId`](#class_c_battle_field_button_1a0df46500a164175a0427db6ac878f48b)`() const` 

getShipId Gibt die SchiffsID zurück

#### `public void `[`reveal`](#class_c_battle_field_button_1afed512e02f837e50a8f3aa2acb8154bc)`(const bool bMarkHit)` 

reveal Deckt den Button auf. Der Button ist danach nicht mehr klickbar. Wenn er ein Schiff enthält, zeigt er eine Explosion an.

#### Parameters
* `bMarkHit` wenn der Button kein Schiff kann er trotzdem markiert werden, z.B. um zu zeigen, wo der Computer hingeschossen hat.

#### `public bool `[`isRevealed`](#class_c_battle_field_button_1a75a2a92a0e53ce2bdb862236559babfe)`() const` 

#### `public bool `[`isRevealedHit`](#class_c_battle_field_button_1aaf875799bd1520f28db40b8a59513607)`() const` 

#### `{signal} public void `[`hit`](#class_c_battle_field_button_1a478a07dfa8f6427a64b36ed29d21f010)`()` 

hit wird gesendet, wenn der Button aufgedeckt wird, und ein Schiff enthält.

# class `CBattleFieldGrid` 

The [CBattleFieldGrid](#class_c_battle_field_grid) class Wir bauen uns einen eigenen, 2 dimensionalen Container.

Das Template wäre nicht wirklich notwendig, da wir den Container nur für einen typ brauchen, aber so können wir Temaplates üben uns sehen ein paar tolle Fallstricke. 

Reden wir über Fallstricke bei Templates. Templatisierte Klassen sind etwas zickig. Der Compiler verzögert das Compilieren, so lange wie es geht, da er ja die möglichen Aufrufe kennen muss. das führt am ende dazu, dass die Klasse eventuell noch nicht kompiliert ist, wenn sie gebraucht wird. Um das zu umgehen, gibt es zwei Möglichleiten: Option 1: Am Ende der Implementierung instantiiert man einach jeden möglichem Aufruf. Das machen wir hier so. Wir erfinden den header 

**See also**: [cbattlefieldgridregister.h](#cbattlefieldgridregister_8h) und inkludieren ihn am ende der Implementierung. Jeder, der diesen Container nutzen möchte, trägt sich da ein. Option 2: Wir implementieren alles im Header 

**See also**: cbattlefieldgriditerator

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline `[`Iterator`](#class_c_battle_field_grid_1a13e9d26094a525c8f9a879a40d0bdb14)` `[`begin`](#class_c_battle_field_grid_1a62526e2673374a685e3e01aedc227ac5)`()` | begin
`public inline `[`Iterator`](#class_c_battle_field_grid_1a13e9d26094a525c8f9a879a40d0bdb14)` `[`end`](#class_c_battle_field_grid_1a165de2dc20398576cea5af4b5e18b75a)`()` | end
`public inline `[`ConstIterator`](#class_c_battle_field_grid_1a5f5d5ed99a35ea03ea3f64d23a7b30dd)` `[`begin`](#class_c_battle_field_grid_1acfe72f282bab8b57cfc6d0c0edfa587a)`() const` | begin
`public inline `[`ConstIterator`](#class_c_battle_field_grid_1a5f5d5ed99a35ea03ea3f64d23a7b30dd)` `[`end`](#class_c_battle_field_grid_1a724e1292539287b79a0132f02c573603)`() const` | end
`public  `[`CBattleFieldGrid`](#class_c_battle_field_grid_1acaad329aef5d9e228574c2d5377ef01d)`() = default` | [CBattleFieldGrid](#class_c_battle_field_grid) Ein Standardkonstruktor.
`public void `[`resize`](#class_c_battle_field_grid_1a4854004aba7871c5253229a783947a41)`(const `[`TGridSize`](#struct_t_grid_size)` & sz)` | resize Um das push_back zu implementieren wie wir es implementiert haben muss der Container seine Dimensionen kennen.
`public `[`TGridSize`](#struct_t_grid_size)` `[`size`](#class_c_battle_field_grid_1a7638d4f4e36423ed42ede85f9c7fca0c)`() const` | size
`public void `[`clear`](#class_c_battle_field_grid_1a5fcc4a07c43f2c112a3cffd18426eb34)`()` | clear leert alle vektoren.
`public TValueType `[`at`](#class_c_battle_field_grid_1ac900aed48867fe94369484995ee810a0)`(const `[`BattleFieldCoords::BattleFieldCoords`](#struct_battle_field_coords_1_1_battle_field_coords)` coords) const` | at Gibt den Wert an gegebenen Koordinaten zurück
`public std::optional< `[`BattleFieldCoords::BattleFieldCoords`](#struct_battle_field_coords_1_1_battle_field_coords)` > `[`push_back`](#class_c_battle_field_grid_1a6c30baf8cefb0def5be466d2da5dfb8e)`(const TValueType & val)` | push_back schiebt einen wert in das Grid.
`typedef `[`Iterator`](#class_c_battle_field_grid_1a13e9d26094a525c8f9a879a40d0bdb14) | Typdefinitionen für die Iteratoren Ja, wir bauen uns eigene Iteratoren. Damit diese einfacher zu handhaben sind, definieren wir Typen. 
`typedef `[`ConstIterator`](#class_c_battle_field_grid_1a5f5d5ed99a35ea03ea3f64d23a7b30dd) | 

## Members

#### `public inline `[`Iterator`](#class_c_battle_field_grid_1a13e9d26094a525c8f9a879a40d0bdb14)` `[`begin`](#class_c_battle_field_grid_1a62526e2673374a685e3e01aedc227ac5)`()` 

begin

#### Returns
der Begin-Iterator

#### `public inline `[`Iterator`](#class_c_battle_field_grid_1a13e9d26094a525c8f9a879a40d0bdb14)` `[`end`](#class_c_battle_field_grid_1a165de2dc20398576cea5af4b5e18b75a)`()` 

end

#### Returns
der Ende-Iterator 

Achtung! [end()](#class_c_battle_field_grid_1a165de2dc20398576cea5af4b5e18b75a) zeigt immer HINTER das Ende des Containers, ist also ungültig! Das ist bei Iteratoren Konvention. Der Versuch den [end()](#class_c_battle_field_grid_1a165de2dc20398576cea5af4b5e18b75a) - Iterator zu dereferenzieren endet in einem Crash.

#### `public inline `[`ConstIterator`](#class_c_battle_field_grid_1a5f5d5ed99a35ea03ea3f64d23a7b30dd)` `[`begin`](#class_c_battle_field_grid_1acfe72f282bab8b57cfc6d0c0edfa587a)`() const` 

begin

#### Returns
der const Begin-Iterator

#### `public inline `[`ConstIterator`](#class_c_battle_field_grid_1a5f5d5ed99a35ea03ea3f64d23a7b30dd)` `[`end`](#class_c_battle_field_grid_1a724e1292539287b79a0132f02c573603)`() const` 

end

#### Returns
der const end-Iterator 

Auch hier, zeigt hinter das Ende des Containers.

#### `public  `[`CBattleFieldGrid`](#class_c_battle_field_grid_1acaad329aef5d9e228574c2d5377ef01d)`() = default` 

[CBattleFieldGrid](#class_c_battle_field_grid) Ein Standardkonstruktor.

#### `public void `[`resize`](#class_c_battle_field_grid_1a4854004aba7871c5253229a783947a41)`(const `[`TGridSize`](#struct_t_grid_size)` & sz)` 

resize Um das push_back zu implementieren wie wir es implementiert haben muss der Container seine Dimensionen kennen.

#### Parameters
* `sz` die größe des Containers 

Es findet kein resize der Vektoren statt! 

Die bestehenden Vektoren werden einfach geleert.

#### `public `[`TGridSize`](#struct_t_grid_size)` `[`size`](#class_c_battle_field_grid_1a7638d4f4e36423ed42ede85f9c7fca0c)`() const` 

size

#### Returns
Getter für die Größe

#### `public void `[`clear`](#class_c_battle_field_grid_1a5fcc4a07c43f2c112a3cffd18426eb34)`()` 

clear leert alle vektoren.

Die Größe bleibt unangetastet.

#### `public TValueType `[`at`](#class_c_battle_field_grid_1ac900aed48867fe94369484995ee810a0)`(const `[`BattleFieldCoords::BattleFieldCoords`](#struct_battle_field_coords_1_1_battle_field_coords)` coords) const` 

at Gibt den Wert an gegebenen Koordinaten zurück

#### Parameters
* `coords` Koordinaten des Wertes 

#### Returns
der Wert an den gegebenen Koordinaten 

Es findet keine Zugriffsprüfung statt

#### `public std::optional< `[`BattleFieldCoords::BattleFieldCoords`](#struct_battle_field_coords_1_1_battle_field_coords)` > `[`push_back`](#class_c_battle_field_grid_1a6c30baf8cefb0def5be466d2da5dfb8e)`(const TValueType & val)` 

push_back schiebt einen wert in das Grid.

#### Parameters
* `val` 

#### Returns
die Koordinaten, an denen der Wert eingefügt wurde 

Es wird geprüft ob das Grid voll ist. In dem Falle ist das Optional leer. 

**See also**: [resize](#class_c_battle_field_grid_1a4854004aba7871c5253229a783947a41)

#### `typedef `[`Iterator`](#class_c_battle_field_grid_1a13e9d26094a525c8f9a879a40d0bdb14) 

Typdefinitionen für die Iteratoren Ja, wir bauen uns eigene Iteratoren. Damit diese einfacher zu handhaben sind, definieren wir Typen. 

Damit wir unseren Container in den STD-Algorithmen und in einer FOREACH Schleife verwenden können, benötigen wir begin- und end- Funktionen, die passende Iteratoren zurückgeben. Beide müssen auch als const vorliegen, damit die Iteratoren auch in konstanten Funktionen benutzt werden können.

#### `typedef `[`ConstIterator`](#class_c_battle_field_grid_1a5f5d5ed99a35ea03ea3f64d23a7b30dd) 

# class `CButtonBox` 

```
class CButtonBox
  : public QFrame
```  

Die Box, die die Buttons enthält. Ein Button pro Spalte.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`CButtonBox`](#class_c_button_box_1accec9965f77c30e90a6c8f575a088d89)`(QWidget * parent)` | 
`public void `[`deactivateButton`](#class_c_button_box_1a8d7a6fd83bb51c861d3d1232dab14920)`(const unsigned int index)` | deactivateButton deaktiviert den Button für Spalte index
`public void `[`reset`](#class_c_button_box_1a7ced6e5eabd3420a6376766fc7cce5b5)`()` | reset setzt die Buttons zurück
`{signal} public void `[`buttonClicked`](#class_c_button_box_1a1375fcba26e40cb61e4b6d7791f0f524)`(const unsigned int index)` | buttonClicked wird gesendet, wenn ein Button geklicked wird. Gibt den Index der zugehörigen Spalte mit

## Members

#### `public  `[`CButtonBox`](#class_c_button_box_1accec9965f77c30e90a6c8f575a088d89)`(QWidget * parent)` 

#### `public void `[`deactivateButton`](#class_c_button_box_1a8d7a6fd83bb51c861d3d1232dab14920)`(const unsigned int index)` 

deactivateButton deaktiviert den Button für Spalte index

#### `public void `[`reset`](#class_c_button_box_1a7ced6e5eabd3420a6376766fc7cce5b5)`()` 

reset setzt die Buttons zurück

#### `{signal} public void `[`buttonClicked`](#class_c_button_box_1a1375fcba26e40cb61e4b6d7791f0f524)`(const unsigned int index)` 

buttonClicked wird gesendet, wenn ein Button geklicked wird. Gibt den Index der zugehörigen Spalte mit

# class `CComputerBattleField` 

```
class CComputerBattleField
  : public CAbstractBattleField
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`CComputerBattleField`](#class_c_computer_battle_field_1a63f6f77e151fc3d886171873f13773ee)`(QWidget * parent)` | 

## Members

#### `public  `[`CComputerBattleField`](#class_c_computer_battle_field_1a63f6f77e151fc3d886171873f13773ee)`(QWidget * parent)` 

# class `CComputerBattleFieldLabel` 

```
class CComputerBattleFieldLabel
  : public CAbstractBattleFieldLabel
```  

The [CComputerBattleFieldLabel](#class_c_computer_battle_field_label) class Das BattlefieldLabel für den Comuterspieler.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`CComputerBattleFieldLabel`](#class_c_computer_battle_field_label_1a16bc82743afff1849fd98b631aa33085)`(QWidget * parent)` | 

## Members

#### `public  `[`CComputerBattleFieldLabel`](#class_c_computer_battle_field_label_1a16bc82743afff1849fd98b631aa33085)`(QWidget * parent)` 

# class `CComputerPlayer` 

```
class CComputerPlayer
  : public QObject
```  

The [CComputerPlayer](#class_c_computer_player) class Hier haben wir die "KI" implementiert. verbindet das signal "compouterTurn" von [CGameManagement](#class_c_game_management) mit doMove()

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  explicit `[`CComputerPlayer`](#class_c_computer_player_1a57a00eee188cc9195afd1e31aec86d23)`(`[`CAbstractBattleField`](#class_c_abstract_battle_field)` * battleField,QObject * parent)` | 
`public void `[`init`](#class_c_computer_player_1a5306e680c4827c5a3bde81207bd37b69)`()` | 

## Members

#### `public  explicit `[`CComputerPlayer`](#class_c_computer_player_1a57a00eee188cc9195afd1e31aec86d23)`(`[`CAbstractBattleField`](#class_c_abstract_battle_field)` * battleField,QObject * parent)` 

#### `public void `[`init`](#class_c_computer_player_1a5306e680c4827c5a3bde81207bd37b69)`()` 

# class `CDisplay` 

```
class CDisplay
  : public QLabel
```  

[CDisplay](#class_c_display) repräsentiert die Anzeige.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`CDisplay`](#class_c_display_1aa7585a55aa1f7b57f0af5ac8bdab7430)`(QWidget * parent)` | 
`public void `[`setBombs`](#class_c_display_1a2dd7646a38e14c310bca63d662ddfb76)`(const int i)` | setBombs Setter für die Anzahl der Bomben
`public void `[`setGameOver`](#class_c_display_1a47b856875799bd00f2ea7ed3201397eb)`(const bool bWin)` | setGameOver Anzeige für Game over
`public void `[`addRevealedBomb`](#class_c_display_1af058df301df323ce7202b7ad08feab6c)`(const bool bAdd)` | addRevealedBomb fügt eine markierte Bombe hinzu, oder entfernt sie
`public void `[`reset`](#class_c_display_1a65b1024228ec8408eea6a165a5516d67)`()` | reset setzt die Anzeige zurück

## Members

#### `public  `[`CDisplay`](#class_c_display_1aa7585a55aa1f7b57f0af5ac8bdab7430)`(QWidget * parent)` 

#### `public void `[`setBombs`](#class_c_display_1a2dd7646a38e14c310bca63d662ddfb76)`(const int i)` 

setBombs Setter für die Anzahl der Bomben

#### Parameters
* `i` Anzahl der Bomben

#### `public void `[`setGameOver`](#class_c_display_1a47b856875799bd00f2ea7ed3201397eb)`(const bool bWin)` 

setGameOver Anzeige für Game over

#### Parameters
* `bWin` gewonnen oder verloren

#### `public void `[`addRevealedBomb`](#class_c_display_1af058df301df323ce7202b7ad08feab6c)`(const bool bAdd)` 

addRevealedBomb fügt eine markierte Bombe hinzu, oder entfernt sie

#### Parameters
* `bAdd` hinzufügen oder entfernen

#### `public void `[`reset`](#class_c_display_1a65b1024228ec8408eea6a165a5516d67)`()` 

reset setzt die Anzeige zurück

# class `CDisplayLabel` 

```
class CDisplayLabel
  : public QFrame
```  

Handelt die Anzeige des Spielstandes.

eine Änderung

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`CDisplayLabel`](#class_c_display_label_1a561389cfc4072a7a537b167f19a67aab)`(QWidget * parent,Qt::WindowFlags f)` | 
`public void `[`togglePlayer`](#class_c_display_label_1acd44c469ad163be98225735fa458f7a5)`()` | togglePlayer wechselt den Spieler
`public void `[`addPoints`](#class_c_display_label_1a444a431d3810c38ab2589679e490d9f2)`()` | addPoints Der aktuelle Spieler bekommt Punkte
`public void `[`reset`](#class_c_display_label_1a6829f0aa655ba33c717366b911d5855d)`()` | reset setzt die Anzeige zurück
`public void `[`gameOver`](#class_c_display_label_1af6e3c3a84c5f568c50e5cd730be81c27)`()` | gameOver ermittelt den Gewinner und macht eine MessageBox auf

## Members

#### `public  `[`CDisplayLabel`](#class_c_display_label_1a561389cfc4072a7a537b167f19a67aab)`(QWidget * parent,Qt::WindowFlags f)` 

#### `public void `[`togglePlayer`](#class_c_display_label_1acd44c469ad163be98225735fa458f7a5)`()` 

togglePlayer wechselt den Spieler

#### `public void `[`addPoints`](#class_c_display_label_1a444a431d3810c38ab2589679e490d9f2)`()` 

addPoints Der aktuelle Spieler bekommt Punkte

#### `public void `[`reset`](#class_c_display_label_1a6829f0aa655ba33c717366b911d5855d)`()` 

reset setzt die Anzeige zurück

#### `public void `[`gameOver`](#class_c_display_label_1af6e3c3a84c5f568c50e5cd730be81c27)`()` 

gameOver ermittelt den Gewinner und macht eine MessageBox auf

# class `CField` 

```
class CField
  : public QLabel
```  

[CField](#class_c_field) Repräsentiert ein Feld auf dem Spielfeld.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`CField`](#class_c_field_1abf9742b8a86cd3cfe63f11dffbad0600)`(QWidget * parent)` | 
`public `[`CPlayerManagement::Player`](#class_c_player_management_1abbc43b28d56406ffea0c778ed5453ff2)` `[`getState`](#class_c_field_1a217c203222441db656e12013c9ad5784)`() const` | getState gibt den Zustand des Felds zurück
`public void `[`setState`](#class_c_field_1a70566402d08b83a17157ab5d5ca0dba4)`(const `[`CPlayerManagement::Player`](#class_c_player_management_1abbc43b28d56406ffea0c778ed5453ff2)` & s)` | setState setzt den Zustand eines feldes
`public void `[`reset`](#class_c_field_1ae55709301f4adcf1a5def71c72530d4e)`()` | reset setzt das Feld zurück
`public void `[`setWinningField`](#class_c_field_1a7ea4517b79d7e10fab169ab3817d5ab8)`()` | setWinningField setzt ob das Feld zu den Gewinnerfeldern gehört
`protected void `[`resizeEvent`](#class_c_field_1a522ad5d21429295195a0fe832fbc8110)`(QResizeEvent * e)` | resizeEvent überschrieben von QPushButton. Wird benötigt, um bei Größenänderung die Pixmap anzupassen

## Members

#### `public  `[`CField`](#class_c_field_1abf9742b8a86cd3cfe63f11dffbad0600)`(QWidget * parent)` 

#### `public `[`CPlayerManagement::Player`](#class_c_player_management_1abbc43b28d56406ffea0c778ed5453ff2)` `[`getState`](#class_c_field_1a217c203222441db656e12013c9ad5784)`() const` 

getState gibt den Zustand des Felds zurück

**See also**: [CPlayerManagement::Player](#class_c_player_management_1abbc43b28d56406ffea0c778ed5453ff2)

#### `public void `[`setState`](#class_c_field_1a70566402d08b83a17157ab5d5ca0dba4)`(const `[`CPlayerManagement::Player`](#class_c_player_management_1abbc43b28d56406ffea0c778ed5453ff2)` & s)` 

setState setzt den Zustand eines feldes

#### Parameters
* `s` der Spieler der das Feld besetzt

#### `public void `[`reset`](#class_c_field_1ae55709301f4adcf1a5def71c72530d4e)`()` 

reset setzt das Feld zurück

#### `public void `[`setWinningField`](#class_c_field_1a7ea4517b79d7e10fab169ab3817d5ab8)`()` 

setWinningField setzt ob das Feld zu den Gewinnerfeldern gehört

**See also**: [CPlayField::checkWinner](#class_c_play_field_1afab0be9d13aaa134e34cbbbb82ed680c)

#### `protected void `[`resizeEvent`](#class_c_field_1a522ad5d21429295195a0fe832fbc8110)`(QResizeEvent * e)` 

resizeEvent überschrieben von QPushButton. Wird benötigt, um bei Größenänderung die Pixmap anzupassen

#### Parameters
* `e` das ResizeEvent (nicht vergessen weiterzuschicken)

# class `CGameManagement` 

```
class CGameManagement
  : public QObject
```  

The [CGameManagement](#class_c_game_management) class Handelt den Spielablauf.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public void `[`initGame`](#class_c_game_management_1afa8258831b5ed6bc6eddc12d741f44dd)`(`[`EDifficulty`](#class_c_game_management_1aa9d52466bca2ade3ddbe44ca8eff4763)` difficulty)` | initGame Initialisiert das Spiel mit Schwierigkeitsgrad
`public void `[`start`](#class_c_game_management_1a7adbc1af4ff015392610e776910bf54d)`()` | start Startet das Spiel
`public `[`EDifficulty`](#class_c_game_management_1aa9d52466bca2ade3ddbe44ca8eff4763)` `[`getDifficulty`](#class_c_game_management_1a88fb2723862d6c758fdf91c20356c2af)`() const` | getDifficulty Getter für den Schwierigkeitsgrad
`public `[`ShipVector`](#class_c_game_management_1a9790420240d0e10290d0683a95cdd220)` `[`getAvailableShips`](#class_c_game_management_1a1a00062c75097ba0c50859dd8447772a)`() const` | getAvailableShips Getter für die Liste an Schiffen, die platziert werden
`public `[`TGridSize`](#struct_t_grid_size)` `[`getGridSize`](#class_c_game_management_1a980a60ec60ce450ae3baafa154647c0e)`() const` | getGridSize Getter für die Größe des Spielfeldes
`public unsigned int `[`getHitsForWin`](#class_c_game_management_1a71f65fc486251182669cf806695eeeed)`() const` | getHitsForWin Wieviele Treffer sind für einen Sieg notwendig
`public void `[`playerFinished`](#class_c_game_management_1a7deb72a08776782e0b61f03d55ee9f20)`()` | playerFinished Wird vom Spieler aufgerufen, wenn der Spieler seinen Zug beendet hat.
`public void `[`computerFinished`](#class_c_game_management_1a5e3d3125384ba011fdf02e4d402d7f89)`()` | computerFinished Wird vom Computer aufgerufen, wenn der Computer seinen Zug beendet hat.
`public void `[`playerWins`](#class_c_game_management_1add07076fc0da3e28100cfba86683f815)`()` | playerWins Wird vom Spieler aufgerufen um den Sieg zu signalisieren
`public void `[`computerWins`](#class_c_game_management_1adf075e9c71d24d10de441e635aebe139)`()` | computerWins Wird vom Computer aufgerufen um den Sieg zu signalisieren
`{signal} public void `[`newGame`](#class_c_game_management_1a6729d88eed6dcf4656e4cd3e53b8c1ae)`()` | newGame Signalisiert ein neues Spiel
`{signal} public void `[`startGame`](#class_c_game_management_1a098b68b2e4457d8ba8d0dbda2eef8299)`()` | startGame Signalisiert den Start des Spiels
`{signal} public void `[`computerTurn`](#class_c_game_management_1a48bfb34b056db1beccdc9dda2dcd60ce)`()` | computerTurn Signalisiert dem ComputerSpieler, dass er am Zug ist.
`{signal} public void `[`playerTurn`](#class_c_game_management_1ae089baaceec67f6b837e2e2755e18a97)`()` | playerTurn Signalisiert dem Spieler, dass er am Zug ist.
`{signal} public void `[`gameOver`](#class_c_game_management_1ade66c4f5f02c650bdca13e452cc1a434)`()` | gameOver Signalisiert das Spielende
`enum `[`EShips`](#class_c_game_management_1a25f44a7fe275bfddce7658eeac27f14e) | The EShips enum Die verfügbaren Schiffe und ihre Größe.
`enum `[`EDifficulty`](#class_c_game_management_1aa9d52466bca2ade3ddbe44ca8eff4763) | The EDifficulty enum Der Schwirigkeitsgrad.
`enum `[`EPhase`](#class_c_game_management_1a3352e482e7b3c4d80ca205ecba169099) | The EPhase enum Die Phase des Spiels.
`enum `[`EPlayer`](#class_c_game_management_1a6a69737fd0108902249b2fc57f1c5af7) | The EPlayer enum Spieler oder Computer.
`typedef `[`ShipVector`](#class_c_game_management_1a9790420240d0e10290d0683a95cdd220) | ShipVector Eine Definition für einen vektor aus Schiffen.

## Members

#### `public void `[`initGame`](#class_c_game_management_1afa8258831b5ed6bc6eddc12d741f44dd)`(`[`EDifficulty`](#class_c_game_management_1aa9d52466bca2ade3ddbe44ca8eff4763)` difficulty)` 

initGame Initialisiert das Spiel mit Schwierigkeitsgrad

#### Parameters
* `difficulty`

#### `public void `[`start`](#class_c_game_management_1a7adbc1af4ff015392610e776910bf54d)`()` 

start Startet das Spiel

#### `public `[`EDifficulty`](#class_c_game_management_1aa9d52466bca2ade3ddbe44ca8eff4763)` `[`getDifficulty`](#class_c_game_management_1a88fb2723862d6c758fdf91c20356c2af)`() const` 

getDifficulty Getter für den Schwierigkeitsgrad

#### `public `[`ShipVector`](#class_c_game_management_1a9790420240d0e10290d0683a95cdd220)` `[`getAvailableShips`](#class_c_game_management_1a1a00062c75097ba0c50859dd8447772a)`() const` 

getAvailableShips Getter für die Liste an Schiffen, die platziert werden

#### `public `[`TGridSize`](#struct_t_grid_size)` `[`getGridSize`](#class_c_game_management_1a980a60ec60ce450ae3baafa154647c0e)`() const` 

getGridSize Getter für die Größe des Spielfeldes

#### `public unsigned int `[`getHitsForWin`](#class_c_game_management_1a71f65fc486251182669cf806695eeeed)`() const` 

getHitsForWin Wieviele Treffer sind für einen Sieg notwendig

#### `public void `[`playerFinished`](#class_c_game_management_1a7deb72a08776782e0b61f03d55ee9f20)`()` 

playerFinished Wird vom Spieler aufgerufen, wenn der Spieler seinen Zug beendet hat.

#### `public void `[`computerFinished`](#class_c_game_management_1a5e3d3125384ba011fdf02e4d402d7f89)`()` 

computerFinished Wird vom Computer aufgerufen, wenn der Computer seinen Zug beendet hat.

#### `public void `[`playerWins`](#class_c_game_management_1add07076fc0da3e28100cfba86683f815)`()` 

playerWins Wird vom Spieler aufgerufen um den Sieg zu signalisieren

#### `public void `[`computerWins`](#class_c_game_management_1adf075e9c71d24d10de441e635aebe139)`()` 

computerWins Wird vom Computer aufgerufen um den Sieg zu signalisieren

#### `{signal} public void `[`newGame`](#class_c_game_management_1a6729d88eed6dcf4656e4cd3e53b8c1ae)`()` 

newGame Signalisiert ein neues Spiel

#### `{signal} public void `[`startGame`](#class_c_game_management_1a098b68b2e4457d8ba8d0dbda2eef8299)`()` 

startGame Signalisiert den Start des Spiels

#### `{signal} public void `[`computerTurn`](#class_c_game_management_1a48bfb34b056db1beccdc9dda2dcd60ce)`()` 

computerTurn Signalisiert dem ComputerSpieler, dass er am Zug ist.

#### `{signal} public void `[`playerTurn`](#class_c_game_management_1ae089baaceec67f6b837e2e2755e18a97)`()` 

playerTurn Signalisiert dem Spieler, dass er am Zug ist.

#### `{signal} public void `[`gameOver`](#class_c_game_management_1ade66c4f5f02c650bdca13e452cc1a434)`()` 

gameOver Signalisiert das Spielende

#### `enum `[`EShips`](#class_c_game_management_1a25f44a7fe275bfddce7658eeac27f14e) 

 Values                         | Descriptions                                
--------------------------------|---------------------------------------------
eNoShip            | 
eAircrafrCarrier            | 
eBattleShip            | 
eCruiser            | 
eDestroyer            | 
eSubMarine            | 

The EShips enum Die verfügbaren Schiffe und ihre Größe.

wir beschränken uns auf Linien, der Bums hier ist schon komplizert genug.

#### `enum `[`EDifficulty`](#class_c_game_management_1aa9d52466bca2ade3ddbe44ca8eff4763) 

 Values                         | Descriptions                                
--------------------------------|---------------------------------------------
eEasy            | 
eMedium            | 
eHard            | 

The EDifficulty enum Der Schwirigkeitsgrad.

#### `enum `[`EPhase`](#class_c_game_management_1a3352e482e7b3c4d80ca205ecba169099) 

 Values                         | Descriptions                                
--------------------------------|---------------------------------------------
ePlacement            | 
ePlay            | 
eFinish            | 

The EPhase enum Die Phase des Spiels.

#### `enum `[`EPlayer`](#class_c_game_management_1a6a69737fd0108902249b2fc57f1c5af7) 

 Values                         | Descriptions                                
--------------------------------|---------------------------------------------
ePlayer            | 
eComputer            | 
eNone            | 

The EPlayer enum Spieler oder Computer.

#### `typedef `[`ShipVector`](#class_c_game_management_1a9790420240d0e10290d0683a95cdd220) 

ShipVector Eine Definition für einen vektor aus Schiffen.

Nicht mit [CShipVector](#class_c_ship_vector) verwechseln

# class `CMemoryButton` 

```
class CMemoryButton
  : public QPushButton
```  

Repräsentiert eine einzelne Spielkarte.

wird mit einem Integer initialisiert, welcher das anzuzeigende Bild repräsentiert

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`CMemoryButton`](#class_c_memory_button_1a5566f7faec4ac9e35efa566e531de987)`(const int internalValue)` | [CMemoryButton](#class_c_memory_button) Konstruktor.
`public int `[`getInternalValue`](#class_c_memory_button_1a7d4cad7edbce19520d65422556c479c7)`() const` | getInternalValue gibt den internen Wert (der für die Auswahl des Bildes veramtwortlich ist) zurück
`public void `[`unreveal`](#class_c_memory_button_1a486d15394bc2e39f94dfc9719b0ff589)`()` | unreveal dreht eine audgwedeckte Karte um.
`public bool `[`isSelectable`](#class_c_memory_button_1a0e1c8ecf332ee947d562115c91a8693c)`() const` | isSelectable prüft ob der Button noch gewählt werden kann
`protected void `[`resizeEvent`](#class_c_memory_button_1a5989bf94d76c4cdb2cc301cf842ff8d4)`(QResizeEvent * e)` | resizeEvent überschrieben von QPushButton. Wird benötigt, um bei Größenänderung die Pixmap anzupassen
`{signal} public void `[`buttonSelected`](#class_c_memory_button_1a3f92b6d36407761d168f6858ec737f2d)`()` | buttonSelected wird gesendet, wenn ein Spieler diese Karte ausgewählt hat.

## Members

#### `public  `[`CMemoryButton`](#class_c_memory_button_1a5566f7faec4ac9e35efa566e531de987)`(const int internalValue)` 

[CMemoryButton](#class_c_memory_button) Konstruktor.

#### Parameters
* `internalValue` in interner Wert der das Bild auf dem Button indentifiziert

#### `public int `[`getInternalValue`](#class_c_memory_button_1a7d4cad7edbce19520d65422556c479c7)`() const` 

getInternalValue gibt den internen Wert (der für die Auswahl des Bildes veramtwortlich ist) zurück

#### `public void `[`unreveal`](#class_c_memory_button_1a486d15394bc2e39f94dfc9719b0ff589)`()` 

unreveal dreht eine audgwedeckte Karte um.

#### `public bool `[`isSelectable`](#class_c_memory_button_1a0e1c8ecf332ee947d562115c91a8693c)`() const` 

isSelectable prüft ob der Button noch gewählt werden kann

#### `protected void `[`resizeEvent`](#class_c_memory_button_1a5989bf94d76c4cdb2cc301cf842ff8d4)`(QResizeEvent * e)` 

resizeEvent überschrieben von QPushButton. Wird benötigt, um bei Größenänderung die Pixmap anzupassen

#### Parameters
* `e` das ResizeEvent (nicht vergessen weiterzuschicken)

#### `{signal} public void `[`buttonSelected`](#class_c_memory_button_1a3f92b6d36407761d168f6858ec737f2d)`()` 

buttonSelected wird gesendet, wenn ein Spieler diese Karte ausgewählt hat.

# class `CMineSweeperButton` 

```
class CMineSweeperButton
  : public QPushButton
```  

Repräsentiert eine einzelnes Spielfeld.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`CMineSweeperButton`](#class_c_mine_sweeper_button_1a1c57a2c9e63fc0617d4e8027decac253)`(const unsigned int bombChance)` | [CMineSweeperButton](#class_c_mine_sweeper_button).
`public void `[`unreveal`](#class_c_mine_sweeper_button_1ad1036cea1c7ce5c444393ee624ce5d66)`()` | unreveal dreht eine audgwedeckte Karte um.
`public void `[`reveal`](#class_c_mine_sweeper_button_1a40abb18847c92ad83a3ed4f6db7cefe2)`(const bool bRevealAll)` | unreveal dreht eine audgwedeckte Karte um.
`public bool `[`isSelectable`](#class_c_mine_sweeper_button_1a2810adb37b231dd04eb8e9f66729f74f)`() const` | isSelectable prüft ob der Button noch gewählt werden kann
`public bool `[`hasBomb`](#class_c_mine_sweeper_button_1a0e4a277b5f82ac1512a667ea3a961eaf)`() const` | hasBomb prüft, ob der Button eine Bombe enthält
`public void `[`setBombsAround`](#class_c_mine_sweeper_button_1acea3f8ba38d8516d307d83f30b14a13d)`(const unsigned int i)` | setBombsAround wiviele Bomben sind um den Button herum
`public unsigned int `[`getBombsAround`](#class_c_mine_sweeper_button_1a45cd61d8a45bd9c55c0ccbc6ceaaf16e)`() const` | getBombsAround prüft, wieviele bomben um den Button herum sind
`{signal} public void `[`boom`](#class_c_mine_sweeper_button_1a3b02f2a08c03370420104a73fe005c46)`()` | boom wird gesendet, wenn der Spieler eine Bombe aufdeckt
`{signal} public void `[`buttonSelected`](#class_c_mine_sweeper_button_1a1494939ca7cac0fe0a1d845911ebd92b)`()` | buttonSelected wird gesendet, wenn der Spieler das Feld aufdeckt
`{signal} public void `[`buttonFlagged`](#class_c_mine_sweeper_button_1a4f9d1a1e6a3dd9292d346145d6668243)`(const bool b)` | buttonFlagged wird gesetzt, wenn der Spieler den Button markiert

## Members

#### `public  `[`CMineSweeperButton`](#class_c_mine_sweeper_button_1a1c57a2c9e63fc0617d4e8027decac253)`(const unsigned int bombChance)` 

[CMineSweeperButton](#class_c_mine_sweeper_button).

#### `public void `[`unreveal`](#class_c_mine_sweeper_button_1ad1036cea1c7ce5c444393ee624ce5d66)`()` 

unreveal dreht eine audgwedeckte Karte um.

#### `public void `[`reveal`](#class_c_mine_sweeper_button_1a40abb18847c92ad83a3ed4f6db7cefe2)`(const bool bRevealAll)` 

unreveal dreht eine audgwedeckte Karte um.

#### Parameters
* `bRevealAll` wenn true, wird das ganze feld aufgedeckt, und es dürfen falsche Marker angezeigt werden.

#### `public bool `[`isSelectable`](#class_c_mine_sweeper_button_1a2810adb37b231dd04eb8e9f66729f74f)`() const` 

isSelectable prüft ob der Button noch gewählt werden kann

#### `public bool `[`hasBomb`](#class_c_mine_sweeper_button_1a0e4a277b5f82ac1512a667ea3a961eaf)`() const` 

hasBomb prüft, ob der Button eine Bombe enthält

#### `public void `[`setBombsAround`](#class_c_mine_sweeper_button_1acea3f8ba38d8516d307d83f30b14a13d)`(const unsigned int i)` 

setBombsAround wiviele Bomben sind um den Button herum

#### Parameters
* `i` die Anzahl der Bomben drumherum

#### `public unsigned int `[`getBombsAround`](#class_c_mine_sweeper_button_1a45cd61d8a45bd9c55c0ccbc6ceaaf16e)`() const` 

getBombsAround prüft, wieviele bomben um den Button herum sind

#### Returns
die Anzahl der Bomben drumherum

#### `{signal} public void `[`boom`](#class_c_mine_sweeper_button_1a3b02f2a08c03370420104a73fe005c46)`()` 

boom wird gesendet, wenn der Spieler eine Bombe aufdeckt

#### `{signal} public void `[`buttonSelected`](#class_c_mine_sweeper_button_1a1494939ca7cac0fe0a1d845911ebd92b)`()` 

buttonSelected wird gesendet, wenn der Spieler das Feld aufdeckt

#### `{signal} public void `[`buttonFlagged`](#class_c_mine_sweeper_button_1a4f9d1a1e6a3dd9292d346145d6668243)`(const bool b)` 

buttonFlagged wird gesetzt, wenn der Spieler den Button markiert

#### Parameters
* `b`

# class `ComputerEnemy` 

The [ComputerEnemy](#class_computer_enemy) class Repräsentiert den Computergegner.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public void `[`setDifficulty`](#class_computer_enemy_1aa69c1a234866e1d9086938fe27c7d41b)`(const `[`Difficulty`](#class_computer_enemy_1ad5e2c6f665dfe12324073c77b9966c81)` difficulty)` | 
`public `[`PlayFieldCoords`](#struct_play_field_coords)` `[`doMove`](#class_computer_enemy_1a88a2f4086359ecb3d32188494053bc69)`(const `[`PlayField`](#class_play_field)` & snapShot) const` | doMove macht einen Move in abhängigkeit von der Schwierigkeit
`enum `[`Difficulty`](#class_computer_enemy_1ad5e2c6f665dfe12324073c77b9966c81) | 
`typedef `[`DifficultyMap`](#class_computer_enemy_1ac286733c527d65af255854942d293ce7) | 
`typedef `[`DifficultyMapIterator`](#class_computer_enemy_1a173d0f27abfaf5b24aebe4b87c648ae0) | 

## Members

#### `public void `[`setDifficulty`](#class_computer_enemy_1aa69c1a234866e1d9086938fe27c7d41b)`(const `[`Difficulty`](#class_computer_enemy_1ad5e2c6f665dfe12324073c77b9966c81)` difficulty)` 

#### `public `[`PlayFieldCoords`](#struct_play_field_coords)` `[`doMove`](#class_computer_enemy_1a88a2f4086359ecb3d32188494053bc69)`(const `[`PlayField`](#class_play_field)` & snapShot) const` 

doMove macht einen Move in abhängigkeit von der Schwierigkeit

#### Parameters
* `snapShot` das Spielfeld 

#### Returns
Gibt die Koordinaten für den Move zurück

#### `enum `[`Difficulty`](#class_computer_enemy_1ad5e2c6f665dfe12324073c77b9966c81) 

 Values                         | Descriptions                                
--------------------------------|---------------------------------------------
easy            | 
medium            | 
hard            | 
insane            | 
minmax            | 

#### `typedef `[`DifficultyMap`](#class_computer_enemy_1ac286733c527d65af255854942d293ce7) 

#### `typedef `[`DifficultyMapIterator`](#class_computer_enemy_1a173d0f27abfaf5b24aebe4b87c648ae0) 

# class `ComputerEnemy_Test` 

```
class ComputerEnemy_Test
  : public QObject
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# class `CPlayerBattleField` 

```
class CPlayerBattleField
  : public CAbstractBattleField
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`CPlayerBattleField`](#class_c_player_battle_field_1a9735bfe513412180383db2999f1f5ff7)`(QWidget * parent)` | 

## Members

#### `public  `[`CPlayerBattleField`](#class_c_player_battle_field_1a9735bfe513412180383db2999f1f5ff7)`(QWidget * parent)` 

# class `CPlayerBattleFieldLabel` 

```
class CPlayerBattleFieldLabel
  : public CAbstractBattleFieldLabel
```  

The [CPlayerBattleFieldLabel](#class_c_player_battle_field_label) class Das BattlefieldLabel für den Spieler.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`CPlayerBattleFieldLabel`](#class_c_player_battle_field_label_1a715f884d4564b154d01a14143f39e8f5)`(QWidget * parent)` | 

## Members

#### `public  `[`CPlayerBattleFieldLabel`](#class_c_player_battle_field_label_1a715f884d4564b154d01a14143f39e8f5)`(QWidget * parent)` 

# class `CPlayerManagement` 

[CPlayerManagement](#class_c_player_management) handelt das [PlayerManagement](#class_player_management), und weiß, welcher Spieler gerade am Zug ist.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`CPlayerManagement`](#class_c_player_management_1a2004df0670aaf19361c6effc7adbd68b)`()` | 
`public void `[`reset`](#class_c_player_management_1a6b2019de3c0bca85af780f6de6493b64)`()` | reset setzt das [PlayerManagement](#class_player_management) zurück
`public `[`Player`](#class_c_player_management_1abbc43b28d56406ffea0c778ed5453ff2)` `[`getCurrentPlayer`](#class_c_player_management_1a950aeb8db6767efa1ba085bae668fc5f)`() const` | gibt den aktuellen Spieler zurück
`public void `[`toggleCurrentPlayer`](#class_c_player_management_1a06edf7eabaebfa554ca5039a8aa087b5)`()` | toggleCurrentPlayer schaltet den Spieler um
`enum `[`Player`](#class_c_player_management_1abbc43b28d56406ffea0c778ed5453ff2) | 

## Members

#### `public  `[`CPlayerManagement`](#class_c_player_management_1a2004df0670aaf19361c6effc7adbd68b)`()` 

#### `public void `[`reset`](#class_c_player_management_1a6b2019de3c0bca85af780f6de6493b64)`()` 

reset setzt das [PlayerManagement](#class_player_management) zurück

#### `public `[`Player`](#class_c_player_management_1abbc43b28d56406ffea0c778ed5453ff2)` `[`getCurrentPlayer`](#class_c_player_management_1a950aeb8db6767efa1ba085bae668fc5f)`() const` 

gibt den aktuellen Spieler zurück

#### `public void `[`toggleCurrentPlayer`](#class_c_player_management_1a06edf7eabaebfa554ca5039a8aa087b5)`()` 

toggleCurrentPlayer schaltet den Spieler um

#### `enum `[`Player`](#class_c_player_management_1abbc43b28d56406ffea0c778ed5453ff2) 

 Values                         | Descriptions                                
--------------------------------|---------------------------------------------
none            | 
red            | 
yellow            | 

# class `CPlayerPlacement` 

```
class CPlayerPlacement
  : public QObject
```  

The [CPlayerPlacement](#class_c_player_placement) class Hilfsklasse zum Platzieren der Schiffe des Spielers. Verwaltet die Schiffe die zu platzieren sind. Kennt ein Label, auf dass es Text blubbern kann.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`CPlayerPlacement`](#class_c_player_placement_1a75b6e951478f7881185d2058b59a2844)`()` | 
`public void `[`init`](#class_c_player_placement_1a5f9542c7ea5307850c740c6464af1622)`(QLabel * label)` | init Initialisierung mit dem Label, auf das man blubbern kann
`public void `[`set`](#class_c_player_placement_1a8122ab110ed314cae4da181163c09f7b)`(const `[`BattleFieldCoords::BattleFieldCoords`](#struct_battle_field_coords_1_1_battle_field_coords)` coords)` | set Schiebt eine Koordinate ins Placement an die der Spieler ein Schiff platzieren will Das Placement übernimmt den Rest
`public bool `[`isDone`](#class_c_player_placement_1ad18ad85e4743e3f9baad39aedae0f3fa)`() const` | isDone Gibt zurück ob alle Schiffe platziert sind.
`public int `[`currentId`](#class_c_player_placement_1afc545aa7c341f30faf5877089b142a21)`() const` | currentId Gibt die aktuelle ID zurück
`{signal} public void `[`unsetButtons`](#class_c_player_placement_1af6f8b5f1888de102a36b44e5c2e90277)`(const `[`CShipVector`](#class_c_ship_vector)` & ships)` | 
`{signal} public void `[`setButton`](#class_c_player_placement_1adcd8b5e6efb33bcfb036c7476bd9fb05)`(const `[`CShipAtCoords`](#class_c_ship_at_coords)` & ship)` | 

## Members

#### `public  `[`CPlayerPlacement`](#class_c_player_placement_1a75b6e951478f7881185d2058b59a2844)`()` 

#### `public void `[`init`](#class_c_player_placement_1a5f9542c7ea5307850c740c6464af1622)`(QLabel * label)` 

init Initialisierung mit dem Label, auf das man blubbern kann

#### Parameters
* `label`

#### `public void `[`set`](#class_c_player_placement_1a8122ab110ed314cae4da181163c09f7b)`(const `[`BattleFieldCoords::BattleFieldCoords`](#struct_battle_field_coords_1_1_battle_field_coords)` coords)` 

set Schiebt eine Koordinate ins Placement an die der Spieler ein Schiff platzieren will Das Placement übernimmt den Rest

#### Parameters
* `coords`

#### `public bool `[`isDone`](#class_c_player_placement_1ad18ad85e4743e3f9baad39aedae0f3fa)`() const` 

isDone Gibt zurück ob alle Schiffe platziert sind.

#### `public int `[`currentId`](#class_c_player_placement_1afc545aa7c341f30faf5877089b142a21)`() const` 

currentId Gibt die aktuelle ID zurück

#### `{signal} public void `[`unsetButtons`](#class_c_player_placement_1af6f8b5f1888de102a36b44e5c2e90277)`(const `[`CShipVector`](#class_c_ship_vector)` & ships)` 

#### `{signal} public void `[`setButton`](#class_c_player_placement_1adcd8b5e6efb33bcfb036c7476bd9fb05)`(const `[`CShipAtCoords`](#class_c_ship_at_coords)` & ship)` 

# class `CPlayField` 

```
class CPlayField
  : public QFrame
  : public QFrame
  : public QFrame
```  

[CPlayField](#class_c_play_field) Das Spielfeld.

[CPlayField](#class_c_play_field) Repräsentiert das Spielfeld.

Repräsentiert das Spielfeld.

Es wird in erster Linie nur ein Layout mit Buttons gefüllt und ein wenig der Spielablauf gemanaged

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`CPlayField`](#class_c_play_field_1a8b9473617189c355a26bc9c05031e41c)`(QWidget * parent)` | 
`public void `[`addToColumn`](#class_c_play_field_1a8d5ba70568e2ec0fc8ae605ee7fd267f)`(const unsigned int column,const `[`CPlayerManagement::Player`](#class_c_player_management_1abbc43b28d56406ffea0c778ed5453ff2)` p)` | addToColumn fügt Spieler p zu Spalte column hinzu
`public bool `[`isColumnFull`](#class_c_play_field_1a56e5e7bb66a683296128665288982d04)`(const unsigned int column) const` | isColumnFull ermittelt, ob Spalte column voll ist
`public `[`CPlayerManagement::Player`](#class_c_player_management_1abbc43b28d56406ffea0c778ed5453ff2)` `[`checkWinner`](#class_c_play_field_1afab0be9d13aaa134e34cbbbb82ed680c)`() const` | checkWinner prüft, ob es einen Gewinner gibt
`public void `[`reset`](#class_c_play_field_1a934860cee307169d83c5b05dfd15cc65)`()` | reset setzt das Spielfeld zurück
`public void `[`init`](#class_c_play_field_1a28b47a0e1ae244c2f082742010e1c270)`(const int fields)` | init initialisiert das Spielfeld mit fields feldern
`public  `[`CPlayField`](#class_c_play_field_1afa449de0c348098688723f8d9e4096bc)`(QWidget * parent,Qt::WindowFlags f)` | 
`public void `[`init`](#class_c_play_field_1a770756c56307e3a2dd77dc570e044caa)`(const `[`PlayFieldSize`](#class_c_play_field_1a3fa70467e1bbb6b7465a1986e3de30b3)` size,const `[`BombCount`](#class_c_play_field_1a4d17369f8324b9fa0a1987bd881ad506)` bombCount)` | init Initialisiert das Spielfeld
`public unsigned int `[`getNumBombs`](#class_c_play_field_1a0a52875078cd30a0bdf461b2203d632a)`() const` | getNumBombs für die Anzahl der Bomben auf dem Feld
`protected void `[`resizeEvent`](#class_c_play_field_1ac9b5124694a53ef37aafcaebb38ae02d)`(QResizeEvent * e)` | 
`{signal} public void `[`togglePlayer`](#class_c_play_field_1ac2153cf94c0a3d078bc486ea7e7d529b)`()` | togglePlayer Wird gesendet, wenn der Spieler wechelt
`{signal} public void `[`playerScored`](#class_c_play_field_1a840345ef88571eeb1e5c704437df98d8)`()` | playerScored Wird gesendet, wenn der aktuelle Spieler scored
`{signal} public void `[`gameOver`](#class_c_play_field_1ae37bfa1e2e270e99ed57628d0b2f1a8f)`()` | gameOver Wird gesendet, wenn das Spiel vorbei ist.
`{signal} public void `[`gameOver`](#class_c_play_field_1aa5551737265d822912fbc34d64bffe85)`(const bool bWin)` | gameOver wird gesendet, wenn das spiel vorbei ist
`{signal} public void `[`buttonFlagged`](#class_c_play_field_1a38f8a57ffae1b48ab9ef8c4360466ba4)`(const bool bFlag)` | buttonFlagged wird gesendet, wenn ein button geflagged wird
`enum `[`PlayFieldSize`](#class_c_play_field_1a3fa70467e1bbb6b7465a1986e3de30b3) | 
`enum `[`BombCount`](#class_c_play_field_1a4d17369f8324b9fa0a1987bd881ad506) | 

## Members

#### `public  `[`CPlayField`](#class_c_play_field_1a8b9473617189c355a26bc9c05031e41c)`(QWidget * parent)` 

#### `public void `[`addToColumn`](#class_c_play_field_1a8d5ba70568e2ec0fc8ae605ee7fd267f)`(const unsigned int column,const `[`CPlayerManagement::Player`](#class_c_player_management_1abbc43b28d56406ffea0c778ed5453ff2)` p)` 

addToColumn fügt Spieler p zu Spalte column hinzu

packt den Spielstein oben drauf 

**See also**: getTopEmptyField

#### `public bool `[`isColumnFull`](#class_c_play_field_1a56e5e7bb66a683296128665288982d04)`(const unsigned int column) const` 

isColumnFull ermittelt, ob Spalte column voll ist

#### `public `[`CPlayerManagement::Player`](#class_c_player_management_1abbc43b28d56406ffea0c778ed5453ff2)` `[`checkWinner`](#class_c_play_field_1afab0be9d13aaa134e34cbbbb82ed680c)`() const` 

checkWinner prüft, ob es einen Gewinner gibt

#### Returns
den Gewinner oder [CPlayerManagement::Player::none](#class_c_player_management_1abbc43b28d56406ffea0c778ed5453ff2a334c4a4c42fdb79d7ebc3e73b517e6f8)

#### `public void `[`reset`](#class_c_play_field_1a934860cee307169d83c5b05dfd15cc65)`()` 

reset setzt das Spielfeld zurück

#### `public void `[`init`](#class_c_play_field_1a28b47a0e1ae244c2f082742010e1c270)`(const int fields)` 

init initialisiert das Spielfeld mit fields feldern

#### Parameters
* `fields` anzahl der Felder für das Spiel

#### `public  `[`CPlayField`](#class_c_play_field_1afa449de0c348098688723f8d9e4096bc)`(QWidget * parent,Qt::WindowFlags f)` 

#### `public void `[`init`](#class_c_play_field_1a770756c56307e3a2dd77dc570e044caa)`(const `[`PlayFieldSize`](#class_c_play_field_1a3fa70467e1bbb6b7465a1986e3de30b3)` size,const `[`BombCount`](#class_c_play_field_1a4d17369f8324b9fa0a1987bd881ad506)` bombCount)` 

init Initialisiert das Spielfeld

#### Parameters
* `size` Größe des Spielfeldes 

* `bombCount` Menge der Bomben

#### `public unsigned int `[`getNumBombs`](#class_c_play_field_1a0a52875078cd30a0bdf461b2203d632a)`() const` 

getNumBombs für die Anzahl der Bomben auf dem Feld

#### Returns
Die tatsächliche Anzahl der Bomben

#### `protected void `[`resizeEvent`](#class_c_play_field_1ac9b5124694a53ef37aafcaebb38ae02d)`(QResizeEvent * e)` 

#### `{signal} public void `[`togglePlayer`](#class_c_play_field_1ac2153cf94c0a3d078bc486ea7e7d529b)`()` 

togglePlayer Wird gesendet, wenn der Spieler wechelt

#### `{signal} public void `[`playerScored`](#class_c_play_field_1a840345ef88571eeb1e5c704437df98d8)`()` 

playerScored Wird gesendet, wenn der aktuelle Spieler scored

#### `{signal} public void `[`gameOver`](#class_c_play_field_1ae37bfa1e2e270e99ed57628d0b2f1a8f)`()` 

gameOver Wird gesendet, wenn das Spiel vorbei ist.

#### `{signal} public void `[`gameOver`](#class_c_play_field_1aa5551737265d822912fbc34d64bffe85)`(const bool bWin)` 

gameOver wird gesendet, wenn das spiel vorbei ist

#### Parameters
* `bWin` gewonnen oder verloren

#### `{signal} public void `[`buttonFlagged`](#class_c_play_field_1a38f8a57ffae1b48ab9ef8c4360466ba4)`(const bool bFlag)` 

buttonFlagged wird gesendet, wenn ein button geflagged wird

#### Parameters
* `bFlag` Flag gesetzt oder zurückgesetzt

#### `enum `[`PlayFieldSize`](#class_c_play_field_1a3fa70467e1bbb6b7465a1986e3de30b3) 

 Values                         | Descriptions                                
--------------------------------|---------------------------------------------
s            | 
m            | 
l            | 
xl            | 

#### `enum `[`BombCount`](#class_c_play_field_1a4d17369f8324b9fa0a1987bd881ad506) 

 Values                         | Descriptions                                
--------------------------------|---------------------------------------------
little            | 
few            | 
many            | 
shitLoad            | 
custom            | 

# class `CResourceHelper` 

[CResourceHelper](#class_c_resource_helper) Managed die Recourcen.

In den Resourcen findet sich pro Bildersatz ein Verzeichnis im Unterverzeichnis /cards Bilder sind im png format und durchnummeriert Eine datei ".info" im unterverzeichnis enthält den Namen des Bildersatzes. ToDo: Es sollte mit Lücken umgegangen werden.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public unsigned int `[`countCards`](#class_c_resource_helper_1ad3cc271c2b49b9c2fc037721c59a7a6e)`(const QString & resourceDir)` | zählt die für uns relevanten Resourcendateien in resourceDir
`public QString `[`getResourceName`](#class_c_resource_helper_1aaac7b572ec7e278faccd86ea7859d4de)`(const QString & resourceDir)` | Ermittelt den ResourcenNamen in resourceDir.
`public const QStringList `[`getRecourceDirectories`](#class_c_resource_helper_1a3fdb5f043ed7bc3d01d91eefd2ebf746)`()` | getRecourceDirectories listet die Karten-Unterverzeichnisse auf, und gibt damit die Spielmodi vor
`public QString `[`getCurrentRecourceDirectory`](#class_c_resource_helper_1a3bbaba9738a2a52c7efaed8d25aae8cb)`()` | getCurrentRecourceDirectory gibt das Unterverzeichnis des aktuellen Modus an
`public QString `[`getRecourceFileName`](#class_c_resource_helper_1aa61471f2737fa1a37f783aa47888c573)`(const QString & fileName,const QString & resourceDirectoy)` | getRecourceFileName Gibt den kompletten Resourcendateinamen für fileName zurück
`public QString `[`getRecourceFileName`](#class_c_resource_helper_1adec99d8f3af68fcff7a127ae6632b239)`(const unsigned int fileName,const QString & resourceDirectoy)` | getRecourceFileName Convinience, da die Resourcen durchnummeriert sind kann man auch eine Zahl angeben
`public QString `[`getCardBackSide`](#class_c_resource_helper_1afd97a791f7480f3e705042de741ee21a)`()` | getCardBackSide gibt den kompletten Resourcendateinamen der Kartenrückseite zurück
`public void `[`setGameMode`](#class_c_resource_helper_1adcca1e782ab0b1e4bad9f0fc9c068bd7)`(const QString & s)` | setGameMode ändert den Spielmodus

## Members

#### `public unsigned int `[`countCards`](#class_c_resource_helper_1ad3cc271c2b49b9c2fc037721c59a7a6e)`(const QString & resourceDir)` 

zählt die für uns relevanten Resourcendateien in resourceDir

#### Parameters
* `(optional)` resourceDir das unterverzeichnis um das es geht. Ist nichts angegeben wird das _currentResourceDir genommen 

die Zahl wird gecached, wenn es um das aktelle Verzeichnis geht

#### `public QString `[`getResourceName`](#class_c_resource_helper_1aaac7b572ec7e278faccd86ea7859d4de)`(const QString & resourceDir)` 

Ermittelt den ResourcenNamen in resourceDir.

#### Parameters
* `(optional)` resourceDir das unterverzeichnis um das es geht. Ist nichts angegeben wird das _currentResourceDir genommen

#### `public const QStringList `[`getRecourceDirectories`](#class_c_resource_helper_1a3fdb5f043ed7bc3d01d91eefd2ebf746)`()` 

getRecourceDirectories listet die Karten-Unterverzeichnisse auf, und gibt damit die Spielmodi vor

> Todo: eine IndexDatei reinpacken, die infos über den Spielmodus angibt

#### `public QString `[`getCurrentRecourceDirectory`](#class_c_resource_helper_1a3bbaba9738a2a52c7efaed8d25aae8cb)`()` 

getCurrentRecourceDirectory gibt das Unterverzeichnis des aktuellen Modus an

#### `public QString `[`getRecourceFileName`](#class_c_resource_helper_1aa61471f2737fa1a37f783aa47888c573)`(const QString & fileName,const QString & resourceDirectoy)` 

getRecourceFileName Gibt den kompletten Resourcendateinamen für fileName zurück

#### Parameters
* `fileName` der Name der Datei ohne Extension 

* `resourceDirectoy` (optional) das unterverzeichnis, wenn leer wird das aktuelle Verzeichnis genommen

#### `public QString `[`getRecourceFileName`](#class_c_resource_helper_1adec99d8f3af68fcff7a127ae6632b239)`(const unsigned int fileName,const QString & resourceDirectoy)` 

getRecourceFileName Convinience, da die Resourcen durchnummeriert sind kann man auch eine Zahl angeben

**See also**: [getRecourceFileName](#class_c_resource_helper_1aa61471f2737fa1a37f783aa47888c573)(const QString& fileName, const QString& resourceDirectoy = QString())

#### `public QString `[`getCardBackSide`](#class_c_resource_helper_1afd97a791f7480f3e705042de741ee21a)`()` 

getCardBackSide gibt den kompletten Resourcendateinamen der Kartenrückseite zurück

#### `public void `[`setGameMode`](#class_c_resource_helper_1adcca1e782ab0b1e4bad9f0fc9c068bd7)`(const QString & s)` 

setGameMode ändert den Spielmodus

Es sollte einer sein der in getRecourceDirectories angegeben wurde, es findet keine Prüfung statt

# class `CShipAtCoords` 

The [CShipAtCoords](#class_c_ship_at_coords) class Repräsentiert ein Schiff mit koordinaten Man könnte das auch einfach über ein std::pair<BattleFieldCoords::BattleFieldCoords, int> realisieren, da wir hier nur Getter haben und eine funktion von [BattleFieldCoords](#namespace_battle_field_coords) durchreichen, aber die Filter- und Vergleichsfunktionen in der Klasse zu definieren ist convinient und schön abstrakt.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`CShipAtCoords`](#class_c_ship_at_coords_1a97458d65651ef5369cd8a60038592b73)`()` | 
`public  `[`CShipAtCoords`](#class_c_ship_at_coords_1a27fd84e1dffa5f86927d5c5f357def55)`(const `[`BattleFieldCoords::BattleFieldCoords`](#struct_battle_field_coords_1_1_battle_field_coords)` & coords,const int shipId)` | 
`public `[`BattleFieldCoords::BattleFieldCoords`](#struct_battle_field_coords_1_1_battle_field_coords)` `[`getCoords`](#class_c_ship_at_coords_1ae9a73a0271b7f74636a7901afa97e56f)`() const` | 
`public unsigned int `[`getShipId`](#class_c_ship_at_coords_1a1338ee1ec7899d31e1dfa833db93a068)`() const` | 
`public void `[`transposeCoords`](#class_c_ship_at_coords_1ad893dd879e8137761d7a78e1840fa5b9)`(const `[`BattleFieldCoords::EDirections`](#namespace_battle_field_coords_1ad253a37450970b990cd675e1070c1055)` dir,const bool min)` | 
`typedef `[`fnLT`](#class_c_ship_at_coords_1a47059751aa54c0699877f647a7205a43) | Wir definieren Typnamen für die Filter- und Vergleichsfunktionen, um das Handling einfacher zu machen.
`typedef `[`fnFilter`](#class_c_ship_at_coords_1a00d798b2aad32136a9121f2b61b5bf42) | 

## Members

#### `public  `[`CShipAtCoords`](#class_c_ship_at_coords_1a97458d65651ef5369cd8a60038592b73)`()` 

#### `public  `[`CShipAtCoords`](#class_c_ship_at_coords_1a27fd84e1dffa5f86927d5c5f357def55)`(const `[`BattleFieldCoords::BattleFieldCoords`](#struct_battle_field_coords_1_1_battle_field_coords)` & coords,const int shipId)` 

#### `public `[`BattleFieldCoords::BattleFieldCoords`](#struct_battle_field_coords_1_1_battle_field_coords)` `[`getCoords`](#class_c_ship_at_coords_1ae9a73a0271b7f74636a7901afa97e56f)`() const` 

#### `public unsigned int `[`getShipId`](#class_c_ship_at_coords_1a1338ee1ec7899d31e1dfa833db93a068)`() const` 

#### `public void `[`transposeCoords`](#class_c_ship_at_coords_1ad893dd879e8137761d7a78e1840fa5b9)`(const `[`BattleFieldCoords::EDirections`](#namespace_battle_field_coords_1ad253a37450970b990cd675e1070c1055)` dir,const bool min)` 

#### `typedef `[`fnLT`](#class_c_ship_at_coords_1a47059751aa54c0699877f647a7205a43) 

Wir definieren Typnamen für die Filter- und Vergleichsfunktionen, um das Handling einfacher zu machen.

#### `typedef `[`fnFilter`](#class_c_ship_at_coords_1a00d798b2aad32136a9121f2b61b5bf42) 

# class `CShipVector` 

```
class CShipVector
  : public std::vector< CShipAtCoords >
```  

The [CShipVector](#class_c_ship_vector) class Ein Vektor mit Elementen [CShipAtCoords](#class_c_ship_at_coords) Wir leiten das ab, um ein paar Convinience funktionen zu bekommen.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`CShipVector`](#class_c_ship_vector_1a8710c6779e9924e2c6495cec9013ec34)`()` | 
`public bool `[`contains`](#class_c_ship_vector_1ae0c5c7e53fd39f9249b4622074922a6e)`(const `[`BattleFieldCoords::BattleFieldCoords`](#struct_battle_field_coords_1_1_battle_field_coords)` coords)` | contains Convinience: Prüft, ob der Vektor ein Schiff mit gegebenen Coordinaten enthält.
`public bool `[`contains`](#class_c_ship_vector_1a9f09f8a5f2f20658d0c3866b554d5daf)`(const unsigned int shipId)` | contains Convinience: Prüft, ob der Vektor ein Schiff mit gegebener ID enthält.
`public bool `[`isInLine`](#class_c_ship_vector_1a66d23d0d3645f73a9c5d70488202e242)`(const `[`CShipAtCoords`](#class_c_ship_at_coords)` s)` | isInLine Prüft, ob ein Schiff in einer Reihe oder Spalte mit den Schiffen im Vektor ist
`public bool `[`isVerticalLine`](#class_c_ship_vector_1ac61ad8380d890533fa3c888c0a90319a)`() const` | isVerticalLine Prüft, ob alle Schiffe im Vektor eine vertikale Linie bilden
`public bool `[`isHorizontalLine`](#class_c_ship_vector_1aba2a54f2a0dfc1566ef2421f44b3f5ed)`() const` | isVerticalLine Prüft, ob alle Schiffe im Vektor eine horizontale Linie bilden
`public `[`CShipVector`](#class_c_ship_vector)` `[`filter`](#class_c_ship_vector_1aa99466fbcf87da225ba10dd959f739dc)`(const `[`CShipAtCoords::fnFilter`](#class_c_ship_at_coords_1a00d798b2aad32136a9121f2b61b5bf42)` fn) const` | filter Filtert den Vektor mit einer Filterfunktion

## Members

#### `public  `[`CShipVector`](#class_c_ship_vector_1a8710c6779e9924e2c6495cec9013ec34)`()` 

#### `public bool `[`contains`](#class_c_ship_vector_1ae0c5c7e53fd39f9249b4622074922a6e)`(const `[`BattleFieldCoords::BattleFieldCoords`](#struct_battle_field_coords_1_1_battle_field_coords)` coords)` 

contains Convinience: Prüft, ob der Vektor ein Schiff mit gegebenen Coordinaten enthält.

#### Parameters
* `coords` 

bentutzt std::vector::find_if

#### `public bool `[`contains`](#class_c_ship_vector_1a9f09f8a5f2f20658d0c3866b554d5daf)`(const unsigned int shipId)` 

contains Convinience: Prüft, ob der Vektor ein Schiff mit gegebener ID enthält.

#### Parameters
* `shipId` 

bentutzt std::vector::find_if

#### `public bool `[`isInLine`](#class_c_ship_vector_1a66d23d0d3645f73a9c5d70488202e242)`(const `[`CShipAtCoords`](#class_c_ship_at_coords)` s)` 

isInLine Prüft, ob ein Schiff in einer Reihe oder Spalte mit den Schiffen im Vektor ist

#### Parameters
* `s` 

macht am ehesten sinn, wenn alle Schiffe im Vektor in einer Reihe oder Spalte sind

#### `public bool `[`isVerticalLine`](#class_c_ship_vector_1ac61ad8380d890533fa3c888c0a90319a)`() const` 

isVerticalLine Prüft, ob alle Schiffe im Vektor eine vertikale Linie bilden

#### `public bool `[`isHorizontalLine`](#class_c_ship_vector_1aba2a54f2a0dfc1566ef2421f44b3f5ed)`() const` 

isVerticalLine Prüft, ob alle Schiffe im Vektor eine horizontale Linie bilden

#### `public `[`CShipVector`](#class_c_ship_vector)` `[`filter`](#class_c_ship_vector_1aa99466fbcf87da225ba10dd959f739dc)`(const `[`CShipAtCoords::fnFilter`](#class_c_ship_at_coords_1a00d798b2aad32136a9121f2b61b5bf42)` fn) const` 

filter Filtert den Vektor mit einer Filterfunktion

**See also**: [CShipAtCoords::fnFilter](#class_c_ship_at_coords_1a00d798b2aad32136a9121f2b61b5bf42)

#### Parameters
* `fn`

# class `MainWindow` 

```
class MainWindow
  : public QMainWindow
  : public QMainWindow
  : public QMainWindow
  : public QMainWindow
  : public QMainWindow
  : public QMainWindow
  : public QMainWindow
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  explicit `[`MainWindow`](#class_main_window_1a996c5a2b6f77944776856f08ec30858d)`(QWidget * parent)` | 
`public  `[`~MainWindow`](#class_main_window_1ae98d00a93bc118200eeef9f9bba1dba7)`()` | 
`protected void `[`closeEvent`](#class_main_window_1a80687075bdf1bd9004a1aa6e712198ad)`(QCloseEvent * e)` | 

## Members

#### `public  explicit `[`MainWindow`](#class_main_window_1a996c5a2b6f77944776856f08ec30858d)`(QWidget * parent)` 

#### `public  `[`~MainWindow`](#class_main_window_1ae98d00a93bc118200eeef9f9bba1dba7)`()` 

#### `protected void `[`closeEvent`](#class_main_window_1a80687075bdf1bd9004a1aa6e712198ad)`(QCloseEvent * e)` 

# class `PlayerManagement` 

The [PlayerManagement](#class_player_management) class Klasse um die SPieler zu verwalten.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`PlayerManagement`](#class_player_management_1aba6010bb989891ae1525dfc1adf82217)`()` | 
`public `[`Player`](#class_player_management_1ad7900c36626ac05beb952da577b70fd7)` `[`getCurrentPlayer`](#class_player_management_1a6b2bff086cc613af0b530ebc6ff95109)`() const` | 
`public void `[`setGameMode`](#class_player_management_1a7eec2f1e457d8e11df46702c3fd90f05)`(const `[`GameMode`](#class_player_management_1ad52c0cc2e842f55453b74dda5f2237c8)` mode)` | setComputerEnemy Gibt an ob ein computer im spiel ist
`public void `[`togglePlayer`](#class_player_management_1a20831604254d1f6c4857ac64edc7278e)`()` | togglePlayer Schaltet den current player um
`public QString `[`currentPlayerText`](#class_player_management_1a000b9216140aebeddcba55f21a49ac25)`() const` | currentPlayerText
`public QColor `[`currentPlayerColor`](#class_player_management_1a580668f8ffc0f359adf2c7b6a276c3ce)`() const` | currentPlayerColor
`public `[`Player`](#class_player_management_1ad7900c36626ac05beb952da577b70fd7)` `[`getCurrentPlayer`](#class_player_management_1a1a80eb047631e8641668a8cc953e8fdf)`() const` | getCurrentPlayer
`public QString `[`currentPlayerName`](#class_player_management_1aa2959d2dc4aa1ee8eef5490418e9de76)`() const` | currentPlayerName
`public bool `[`isPlayerTurn`](#class_player_management_1af5b9354e6eaff071a134a8fd161cda3e)`() const` | isPlayerTurn
`enum `[`Player`](#class_player_management_1ad7900c36626ac05beb952da577b70fd7) | The Player enum Spieler X, Spieler O oder keiner.
`enum `[`GameMode`](#class_player_management_1ad52c0cc2e842f55453b74dda5f2237c8) | 

## Members

#### `public  `[`PlayerManagement`](#class_player_management_1aba6010bb989891ae1525dfc1adf82217)`()` 

#### `public `[`Player`](#class_player_management_1ad7900c36626ac05beb952da577b70fd7)` `[`getCurrentPlayer`](#class_player_management_1a6b2bff086cc613af0b530ebc6ff95109)`() const` 

#### `public void `[`setGameMode`](#class_player_management_1a7eec2f1e457d8e11df46702c3fd90f05)`(const `[`GameMode`](#class_player_management_1ad52c0cc2e842f55453b74dda5f2237c8)` mode)` 

setComputerEnemy Gibt an ob ein computer im spiel ist

#### Parameters
* `b` ja oder nein

#### `public void `[`togglePlayer`](#class_player_management_1a20831604254d1f6c4857ac64edc7278e)`()` 

togglePlayer Schaltet den current player um

#### `public QString `[`currentPlayerText`](#class_player_management_1a000b9216140aebeddcba55f21a49ac25)`() const` 

currentPlayerText

#### Returns
Buttonbeschriftung des aktuellen Spielers

#### `public QColor `[`currentPlayerColor`](#class_player_management_1a580668f8ffc0f359adf2c7b6a276c3ce)`() const` 

currentPlayerColor

#### Returns
passende Farbe für den aktuellen Spieler

#### `public `[`Player`](#class_player_management_1ad7900c36626ac05beb952da577b70fd7)` `[`getCurrentPlayer`](#class_player_management_1a1a80eb047631e8641668a8cc953e8fdf)`() const` 

getCurrentPlayer

#### Returns
der aktuelle Spieler

#### `public QString `[`currentPlayerName`](#class_player_management_1aa2959d2dc4aa1ee8eef5490418e9de76)`() const` 

currentPlayerName

#### Returns
name des aktuellen Spielers

#### `public bool `[`isPlayerTurn`](#class_player_management_1af5b9354e6eaff071a134a8fd161cda3e)`() const` 

isPlayerTurn

#### Returns
ist ein Spieler am zug oder der Computer

#### `enum `[`Player`](#class_player_management_1ad7900c36626ac05beb952da577b70fd7) 

 Values                         | Descriptions                                
--------------------------------|---------------------------------------------
none            | 
plX            | 
plO            | 
none            | 
plX            | 
plO            | 

The Player enum Spieler X, Spieler O oder keiner.

#### `enum `[`GameMode`](#class_player_management_1ad52c0cc2e842f55453b74dda5f2237c8) 

 Values                         | Descriptions                                
--------------------------------|---------------------------------------------
pvp            | 
pvc            | 

# class `PlayField` 

The [PlayField](#class_play_field) class Kapselt das Spielfeld in einerm 3x3 Array.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public bool `[`setField`](#class_play_field_1a25fa00159c04a1049d2cc1a07dec6175)`(const int x,const int y,const `[`PlayerManagement::Player`](#class_player_management_1ad7900c36626ac05beb952da577b70fd7)` p)` | 
`public void `[`checkWinner`](#class_play_field_1af41bd74317b49b0060dc63461a7ee7d7)`()` | 
`public bool `[`gameOver`](#class_play_field_1ab566441bdd076b5f6b5bf99cd8ad8ccf)`() const` | 
`public `[`PlayerManagement::Player`](#class_player_management_1ad7900c36626ac05beb952da577b70fd7)` `[`winner`](#class_play_field_1a7647be9c8d4e26360d82e649c93743c5)`() const` | 
`public  `[`PlayField`](#class_play_field_1af34bf9d2f31961f4c15b10fbda384012)`()` | 
`public bool `[`set`](#class_play_field_1a63512a1ae1cb83889a711cf9ee42a09b)`(const `[`PlayFieldCoords`](#struct_play_field_coords)` coords,const `[`PlayerManagement::Player`](#class_player_management_1ad7900c36626ac05beb952da577b70fd7)` p)` | setField Setzt ein Feld
`public `[`PlayerManagement::Player`](#class_player_management_1ad7900c36626ac05beb952da577b70fd7)` `[`at`](#class_play_field_1afd598079522ebdaa494e4af4ff0f67e7)`(const `[`PlayFieldCoords`](#struct_play_field_coords)` coords) const` | at gibt den Wert eines Feldes zurück
`public void `[`reset`](#class_play_field_1aa3927e88438140170423f3b1dc1e27e0)`()` | reset Setzt das Spielfeld zurück
`public bool `[`getGameOver`](#class_play_field_1a72340ff1fdd4b10a9e475bd4d41395a1)`() const` | getGameOver
`public `[`PlayerManagement::Player`](#class_player_management_1ad7900c36626ac05beb952da577b70fd7)` `[`getWinner`](#class_play_field_1a51d71ad773a9bba8529447eac7f1e315)`() const` | getWinner
`public QVector< `[`PlayFieldCoords`](#struct_play_field_coords)` > `[`getEmptyFields`](#class_play_field_1a11e5c31350e577a6b57f042359e94662)`() const` | 

## Members

#### `public bool `[`setField`](#class_play_field_1a25fa00159c04a1049d2cc1a07dec6175)`(const int x,const int y,const `[`PlayerManagement::Player`](#class_player_management_1ad7900c36626ac05beb952da577b70fd7)` p)` 

#### `public void `[`checkWinner`](#class_play_field_1af41bd74317b49b0060dc63461a7ee7d7)`()` 

#### `public bool `[`gameOver`](#class_play_field_1ab566441bdd076b5f6b5bf99cd8ad8ccf)`() const` 

#### `public `[`PlayerManagement::Player`](#class_player_management_1ad7900c36626ac05beb952da577b70fd7)` `[`winner`](#class_play_field_1a7647be9c8d4e26360d82e649c93743c5)`() const` 

#### `public  `[`PlayField`](#class_play_field_1af34bf9d2f31961f4c15b10fbda384012)`()` 

#### `public bool `[`set`](#class_play_field_1a63512a1ae1cb83889a711cf9ee42a09b)`(const `[`PlayFieldCoords`](#struct_play_field_coords)` coords,const `[`PlayerManagement::Player`](#class_player_management_1ad7900c36626ac05beb952da577b70fd7)` p)` 

setField Setzt ein Feld

#### Parameters
* `coords` die Koordinaten eines Feldes 

* `p` der Spieler der das Feld besetzt 

#### Returns
true, wenns geklappt hat, false, wenn das Feld. z.b. schon besetzt ist.

#### `public `[`PlayerManagement::Player`](#class_player_management_1ad7900c36626ac05beb952da577b70fd7)` `[`at`](#class_play_field_1afd598079522ebdaa494e4af4ff0f67e7)`(const `[`PlayFieldCoords`](#struct_play_field_coords)` coords) const` 

at gibt den Wert eines Feldes zurück

#### Parameters
* `coords` die Koordinaten des Feldes 

#### Returns
den spieler an coords

#### `public void `[`reset`](#class_play_field_1aa3927e88438140170423f3b1dc1e27e0)`()` 

reset Setzt das Spielfeld zurück

#### `public bool `[`getGameOver`](#class_play_field_1a72340ff1fdd4b10a9e475bd4d41395a1)`() const` 

getGameOver

#### Returns
true wenn das spiel vorbei ist

#### `public `[`PlayerManagement::Player`](#class_player_management_1ad7900c36626ac05beb952da577b70fd7)` `[`getWinner`](#class_play_field_1a51d71ad773a9bba8529447eac7f1e315)`() const` 

getWinner

#### Returns
gibt den Sieger zurück, PlayerManagement::Player::none bei unentschieden 

nur sinnvoll wenn _gameOver == true

#### `public QVector< `[`PlayFieldCoords`](#struct_play_field_coords)` > `[`getEmptyFields`](#class_play_field_1a11e5c31350e577a6b57f042359e94662)`() const` 

# class `PlayField_Test` 

```
class PlayField_Test
  : public QObject
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# class `PlayFieldCoords_Test` 

```
class PlayFieldCoords_Test
  : public QObject
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# class `Result` 

The [Result](#class_result) class kapselt das Ergebnis der Rechnerei als float.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public double `[`get`](#class_result_1aaec8e5da3ba7294974ddcf1179f6cb48)`() const` | get
`public bool `[`isValid`](#class_result_1a847fbda3c11b0c053387a09d5ad04743)`() const` | isValid
`public void `[`set`](#class_result_1aa8e934207f5b24f010964f9ea1d5c544)`(const double i)` | set setzt den wert
`public void `[`reset`](#class_result_1aceb8eaf403179f461b8be6c5c102f1ba)`()` | reset Setzt den wert zurück, isValid ist false
`public QString `[`toString`](#class_result_1a83be74e25389aa14ac2ec0519402ba55)`() const` | toString

## Members

#### `public double `[`get`](#class_result_1aaec8e5da3ba7294974ddcf1179f6cb48)`() const` 

get

#### Returns
die enthaltene Zahl als float

#### `public bool `[`isValid`](#class_result_1a847fbda3c11b0c053387a09d5ad04743)`() const` 

isValid

#### Returns
ist das aktuelle ergebnis gültig oder uninitialisiert

#### `public void `[`set`](#class_result_1aa8e934207f5b24f010964f9ea1d5c544)`(const double i)` 

set setzt den wert

#### Parameters
* `i`

#### `public void `[`reset`](#class_result_1aceb8eaf403179f461b8be6c5c102f1ba)`()` 

reset Setzt den wert zurück, isValid ist false

#### `public QString `[`toString`](#class_result_1a83be74e25389aa14ac2ec0519402ba55)`() const` 

toString

#### Returns
die Zahl als String mit passender Präzision

# class `Result_Test` 

```
class Result_Test
  : public QObject
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# class `ShipVector_Test` 

```
class ShipVector_Test
  : public QObject
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# class `Ui_MainWindow` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public QAction * `[`_actionStartEasy`](#class_ui___main_window_1a7539880ad78d32024474bec5defe7d23) | 
`public QAction * `[`_actionStartMedium`](#class_ui___main_window_1ab4b0e670eb6b2a9615c21747501cff60) | 
`public QAction * `[`_actionStartHard`](#class_ui___main_window_1a3aa57e184f82ccafd511c900dbb60992) | 
`public QWidget * `[`centralwidget`](#class_ui___main_window_1a39420100bfee3ba57f137af5a3b0f8e9) | 
`public QHBoxLayout * `[`horizontalLayout`](#class_ui___main_window_1ae7104d878681f568e492c5bd0f653157) | 
`public QVBoxLayout * `[`verticalLayout_3`](#class_ui___main_window_1a38b8a4b887f3b58e2a49e7905ae6f1f0) | 
`public QLabel * `[`_enemyShoutbox`](#class_ui___main_window_1a9af431f477e11650b3ba2219499eba97) | 
`public `[`CPlayerBattleFieldLabel`](#class_c_player_battle_field_label)` * `[`_playerDisplay`](#class_ui___main_window_1a2282dc67b790ad10cbe738a12156ede1) | 
`public QVBoxLayout * `[`verticalLayout_2`](#class_ui___main_window_1a0c01bad60d9f422a1258e710635a2f65) | 
`public `[`CComputerBattleField`](#class_c_computer_battle_field)` * `[`_enemyGround`](#class_ui___main_window_1a178e84d003302e6cd1cf5900a23090b5) | 
`public `[`CPlayerBattleField`](#class_c_player_battle_field)` * `[`_playerGround`](#class_ui___main_window_1a230a850baf65cce5df64694b540ffb75) | 
`public QVBoxLayout * `[`verticalLayout`](#class_ui___main_window_1a649287f742c9a33b8444116dccb1b72b) | 
`public `[`CComputerBattleFieldLabel`](#class_c_computer_battle_field_label)` * `[`_enemyDisplay`](#class_ui___main_window_1a77fd407a3eb337f706ed0d52f31b969d) | 
`public QLabel * `[`_playerShoutBox`](#class_ui___main_window_1abd249ea15b5429e5d6db40e2e797404e) | 
`public QMenuBar * `[`menubar`](#class_ui___main_window_1a734b1d3bb71c1b8e1ea01b7fa4344fce) | 
`public QMenu * `[`menunew_game`](#class_ui___main_window_1a05cb37149c85efe4b87d592d270400a6) | 
`public QStatusBar * `[`statusbar`](#class_ui___main_window_1a07519bbb9a350befd6feb4e84ef299fd) | 
`public QPushButton * `[`pbReset`](#class_ui___main_window_1a9dede260e66a4c0ca575cbcbf60b4671) | 
`public `[`CButtonBox`](#class_c_button_box)` * `[`frmButtonBox`](#class_ui___main_window_1a57835849bf42e9feef30729898be6c80) | 
`public `[`CPlayField`](#class_c_play_field)` * `[`frmPlayfield`](#class_ui___main_window_1a1a8db9b9715c71c0bfc66b2b7c3ba7db) | 
`public `[`CDisplayLabel`](#class_c_display_label)` * `[`frmDisplay`](#class_ui___main_window_1a9addec087731e7c7f75d1fbf6f107761) | 
`public QSpacerItem * `[`horizontalSpacer`](#class_ui___main_window_1ae189b5a48fa6e6f4b6775f1f832afe9c) | 
`public QComboBox * `[`cbGameMode`](#class_ui___main_window_1a3df3e22231a2684265822cdd1b4ebfa9) | 
`public QSpinBox * `[`sbNumFields`](#class_ui___main_window_1a16db84e1b81269e927eaa8ff18ad9d9f) | 
`public `[`CDisplay`](#class_c_display)` * `[`display`](#class_ui___main_window_1ac0798d0d2e694fe503b9588eb963694a) | 
`public `[`CPlayField`](#class_c_play_field)` * `[`playField`](#class_ui___main_window_1a7a0a2fa4a7f4873085cd0f7cba189ebf) | 
`public QMenu * `[`menuGame`](#class_ui___main_window_1a83c095b7e1caa75f895adee845fd5a65) | 
`public QMenu * `[`menuSize`](#class_ui___main_window_1a1ab861653515a2244919577b4595c3b5) | 
`public QMenu * `[`menuBombs`](#class_ui___main_window_1a446acbaa21484c250f743a52411d9ff3) | 
`public QWidget * `[`centralWidget`](#class_ui___main_window_1a6600dd3bdd3d55e535659e4a4096ea48) | 
`public QLabel * `[`lb_lastResult`](#class_ui___main_window_1ac75c8544696921a3f1e27d5c4146bb0a) | 
`public QLabel * `[`lb_operator`](#class_ui___main_window_1ab9662940cae3c1e1b81c0fbc176997da) | 
`public QGridLayout * `[`gridLayout`](#class_ui___main_window_1ac4586abe48f0aabf940b0dc2df3772ed) | 
`public QLabel * `[`lb_display`](#class_ui___main_window_1a2c69a69b27621de53cb1554e46d6f738) | 
`public QSpacerItem * `[`verticalSpacer`](#class_ui___main_window_1a8384329c3663ff274e926a12024aab52) | 
`public QLabel * `[`lb_ErrorDisplay`](#class_ui___main_window_1a0633a696ce28aa4a5fb4f3475c604e6e) | 
`public QGridLayout * `[`gridLayout_2`](#class_ui___main_window_1a6b2a0c5f7e8ff2a87134908dd770d2d2) | 
`public QPushButton * `[`pb_cmd_clear`](#class_ui___main_window_1af638eb704ad4cbd10013006c2bfc0096) | 
`public QPushButton * `[`pb_cmd_clearE`](#class_ui___main_window_1aa371e98adef206acdee947bf57ccfe9f) | 
`public QPushButton * `[`pb_cmd_back`](#class_ui___main_window_1a4435e6722c8f82434df45dfbf9f296d9) | 
`public QPushButton * `[`pb_op_sqrt`](#class_ui___main_window_1a8ba43522f28ce36f9951bab67ff77cfb) | 
`public QPushButton * `[`pb_op_sq`](#class_ui___main_window_1a81aaadee5c6ff7cb5a80b43d10e79632) | 
`public QPushButton * `[`pb_op_percent`](#class_ui___main_window_1ada89083cbdae40ebd9faa2c0754123d7) | 
`public QPushButton * `[`pb_op_plus`](#class_ui___main_window_1a7164d0c6418677020a77df64e68a399c) | 
`public QPushButton * `[`pb_1`](#class_ui___main_window_1ab11497495df82c10050dac3fe6cad125) | 
`public QPushButton * `[`pb_2`](#class_ui___main_window_1a2eeadd08c2414c02f065325ac283def1) | 
`public QPushButton * `[`pb_3`](#class_ui___main_window_1a68c14ca6b4a1cd0a1d6322c722568284) | 
`public QPushButton * `[`pb_op_min`](#class_ui___main_window_1af6c6029df0ed8a0da123b6ef32f3fd43) | 
`public QPushButton * `[`pb_4`](#class_ui___main_window_1abef85cdb9c488524b2f145862eeee13f) | 
`public QPushButton * `[`pb_5`](#class_ui___main_window_1ae360787215f6e5dec7cfe40a62d4e0df) | 
`public QPushButton * `[`pb_6`](#class_ui___main_window_1a9445b5598c993dd17e5db7200008a66f) | 
`public QPushButton * `[`pb_op_mul`](#class_ui___main_window_1a36a1278ef310e54aa1afabfe16b51a35) | 
`public QPushButton * `[`pb_7`](#class_ui___main_window_1ab7f72cff98b570aaef6cc50ca25227ed) | 
`public QPushButton * `[`pb_8`](#class_ui___main_window_1a27d521b9a2423842e4e81d79b7725841) | 
`public QPushButton * `[`pb_9`](#class_ui___main_window_1a90e18bb5639c26308b8bb35d114cf63f) | 
`public QPushButton * `[`pb_op_div`](#class_ui___main_window_1a21788d666028a4281aad11e588d2cfb5) | 
`public QPushButton * `[`pb_pt`](#class_ui___main_window_1a4c2896c1def2a3284efb187567c8ded4) | 
`public QPushButton * `[`pb_0`](#class_ui___main_window_1aa0fd148a57a5a15ac76a685a398d38dd) | 
`public QPushButton * `[`pb_plus_minus`](#class_ui___main_window_1ac56efc679c953678227fadcbe1e12edc) | 
`public QPushButton * `[`pb_cmd_enter`](#class_ui___main_window_1a08a848dd88636984ec2ac70c72118542) | 
`public QStatusBar * `[`statusBar`](#class_ui___main_window_1afa919f3af6f2f526a70f1fa331f63724) | 
`public QPushButton * `[`pb1`](#class_ui___main_window_1a23eb68fbebd4c24ef320279562b620d8) | 
`public QPushButton * `[`pb3`](#class_ui___main_window_1a71e84c6fcd472252df0af26f4a24281c) | 
`public QPushButton * `[`pb4`](#class_ui___main_window_1a4f2b5b986ff25f1dd3599d5a307b02fc) | 
`public QPushButton * `[`pb2`](#class_ui___main_window_1a7873b3a0dcbf1d553dd38c9e7b488931) | 
`public QPushButton * `[`pb6`](#class_ui___main_window_1ae686f88a178ef7af71103297af26a4ff) | 
`public QPushButton * `[`pb9`](#class_ui___main_window_1a75325029b59062f6a8b0282cfeff5e20) | 
`public QLabel * `[`lbOut`](#class_ui___main_window_1a67cbe8c516acc380833e21e828e63585) | 
`public QPushButton * `[`pb7`](#class_ui___main_window_1a8e8634c634efc288fece44c3136263db) | 
`public QPushButton * `[`pb5`](#class_ui___main_window_1a6a03f1ba6305323b05eaf49627096ccf) | 
`public QPushButton * `[`pb8`](#class_ui___main_window_1a411fffdfb30284be90cf0a70e4ac15c0) | 
`public QComboBox * `[`cbModeSelect`](#class_ui___main_window_1a2ae9a3cce827922e727fc1bda610b0ec) | 
`public QLabel * `[`lbMode`](#class_ui___main_window_1a2561845101d70ef59264e630badc95b6) | 
`public inline void `[`setupUi`](#class_ui___main_window_1acf4a0872c4c77d8f43a2ec66ed849b58)`(QMainWindow * MainWindow)` | 
`public inline void `[`retranslateUi`](#class_ui___main_window_1a097dd160c3534a204904cb374412c618)`(QMainWindow * MainWindow)` | 

## Members

#### `public QAction * `[`_actionStartEasy`](#class_ui___main_window_1a7539880ad78d32024474bec5defe7d23) 

#### `public QAction * `[`_actionStartMedium`](#class_ui___main_window_1ab4b0e670eb6b2a9615c21747501cff60) 

#### `public QAction * `[`_actionStartHard`](#class_ui___main_window_1a3aa57e184f82ccafd511c900dbb60992) 

#### `public QWidget * `[`centralwidget`](#class_ui___main_window_1a39420100bfee3ba57f137af5a3b0f8e9) 

#### `public QHBoxLayout * `[`horizontalLayout`](#class_ui___main_window_1ae7104d878681f568e492c5bd0f653157) 

#### `public QVBoxLayout * `[`verticalLayout_3`](#class_ui___main_window_1a38b8a4b887f3b58e2a49e7905ae6f1f0) 

#### `public QLabel * `[`_enemyShoutbox`](#class_ui___main_window_1a9af431f477e11650b3ba2219499eba97) 

#### `public `[`CPlayerBattleFieldLabel`](#class_c_player_battle_field_label)` * `[`_playerDisplay`](#class_ui___main_window_1a2282dc67b790ad10cbe738a12156ede1) 

#### `public QVBoxLayout * `[`verticalLayout_2`](#class_ui___main_window_1a0c01bad60d9f422a1258e710635a2f65) 

#### `public `[`CComputerBattleField`](#class_c_computer_battle_field)` * `[`_enemyGround`](#class_ui___main_window_1a178e84d003302e6cd1cf5900a23090b5) 

#### `public `[`CPlayerBattleField`](#class_c_player_battle_field)` * `[`_playerGround`](#class_ui___main_window_1a230a850baf65cce5df64694b540ffb75) 

#### `public QVBoxLayout * `[`verticalLayout`](#class_ui___main_window_1a649287f742c9a33b8444116dccb1b72b) 

#### `public `[`CComputerBattleFieldLabel`](#class_c_computer_battle_field_label)` * `[`_enemyDisplay`](#class_ui___main_window_1a77fd407a3eb337f706ed0d52f31b969d) 

#### `public QLabel * `[`_playerShoutBox`](#class_ui___main_window_1abd249ea15b5429e5d6db40e2e797404e) 

#### `public QMenuBar * `[`menubar`](#class_ui___main_window_1a734b1d3bb71c1b8e1ea01b7fa4344fce) 

#### `public QMenu * `[`menunew_game`](#class_ui___main_window_1a05cb37149c85efe4b87d592d270400a6) 

#### `public QStatusBar * `[`statusbar`](#class_ui___main_window_1a07519bbb9a350befd6feb4e84ef299fd) 

#### `public QPushButton * `[`pbReset`](#class_ui___main_window_1a9dede260e66a4c0ca575cbcbf60b4671) 

#### `public `[`CButtonBox`](#class_c_button_box)` * `[`frmButtonBox`](#class_ui___main_window_1a57835849bf42e9feef30729898be6c80) 

#### `public `[`CPlayField`](#class_c_play_field)` * `[`frmPlayfield`](#class_ui___main_window_1a1a8db9b9715c71c0bfc66b2b7c3ba7db) 

#### `public `[`CDisplayLabel`](#class_c_display_label)` * `[`frmDisplay`](#class_ui___main_window_1a9addec087731e7c7f75d1fbf6f107761) 

#### `public QSpacerItem * `[`horizontalSpacer`](#class_ui___main_window_1ae189b5a48fa6e6f4b6775f1f832afe9c) 

#### `public QComboBox * `[`cbGameMode`](#class_ui___main_window_1a3df3e22231a2684265822cdd1b4ebfa9) 

#### `public QSpinBox * `[`sbNumFields`](#class_ui___main_window_1a16db84e1b81269e927eaa8ff18ad9d9f) 

#### `public `[`CDisplay`](#class_c_display)` * `[`display`](#class_ui___main_window_1ac0798d0d2e694fe503b9588eb963694a) 

#### `public `[`CPlayField`](#class_c_play_field)` * `[`playField`](#class_ui___main_window_1a7a0a2fa4a7f4873085cd0f7cba189ebf) 

#### `public QMenu * `[`menuGame`](#class_ui___main_window_1a83c095b7e1caa75f895adee845fd5a65) 

#### `public QMenu * `[`menuSize`](#class_ui___main_window_1a1ab861653515a2244919577b4595c3b5) 

#### `public QMenu * `[`menuBombs`](#class_ui___main_window_1a446acbaa21484c250f743a52411d9ff3) 

#### `public QWidget * `[`centralWidget`](#class_ui___main_window_1a6600dd3bdd3d55e535659e4a4096ea48) 

#### `public QLabel * `[`lb_lastResult`](#class_ui___main_window_1ac75c8544696921a3f1e27d5c4146bb0a) 

#### `public QLabel * `[`lb_operator`](#class_ui___main_window_1ab9662940cae3c1e1b81c0fbc176997da) 

#### `public QGridLayout * `[`gridLayout`](#class_ui___main_window_1ac4586abe48f0aabf940b0dc2df3772ed) 

#### `public QLabel * `[`lb_display`](#class_ui___main_window_1a2c69a69b27621de53cb1554e46d6f738) 

#### `public QSpacerItem * `[`verticalSpacer`](#class_ui___main_window_1a8384329c3663ff274e926a12024aab52) 

#### `public QLabel * `[`lb_ErrorDisplay`](#class_ui___main_window_1a0633a696ce28aa4a5fb4f3475c604e6e) 

#### `public QGridLayout * `[`gridLayout_2`](#class_ui___main_window_1a6b2a0c5f7e8ff2a87134908dd770d2d2) 

#### `public QPushButton * `[`pb_cmd_clear`](#class_ui___main_window_1af638eb704ad4cbd10013006c2bfc0096) 

#### `public QPushButton * `[`pb_cmd_clearE`](#class_ui___main_window_1aa371e98adef206acdee947bf57ccfe9f) 

#### `public QPushButton * `[`pb_cmd_back`](#class_ui___main_window_1a4435e6722c8f82434df45dfbf9f296d9) 

#### `public QPushButton * `[`pb_op_sqrt`](#class_ui___main_window_1a8ba43522f28ce36f9951bab67ff77cfb) 

#### `public QPushButton * `[`pb_op_sq`](#class_ui___main_window_1a81aaadee5c6ff7cb5a80b43d10e79632) 

#### `public QPushButton * `[`pb_op_percent`](#class_ui___main_window_1ada89083cbdae40ebd9faa2c0754123d7) 

#### `public QPushButton * `[`pb_op_plus`](#class_ui___main_window_1a7164d0c6418677020a77df64e68a399c) 

#### `public QPushButton * `[`pb_1`](#class_ui___main_window_1ab11497495df82c10050dac3fe6cad125) 

#### `public QPushButton * `[`pb_2`](#class_ui___main_window_1a2eeadd08c2414c02f065325ac283def1) 

#### `public QPushButton * `[`pb_3`](#class_ui___main_window_1a68c14ca6b4a1cd0a1d6322c722568284) 

#### `public QPushButton * `[`pb_op_min`](#class_ui___main_window_1af6c6029df0ed8a0da123b6ef32f3fd43) 

#### `public QPushButton * `[`pb_4`](#class_ui___main_window_1abef85cdb9c488524b2f145862eeee13f) 

#### `public QPushButton * `[`pb_5`](#class_ui___main_window_1ae360787215f6e5dec7cfe40a62d4e0df) 

#### `public QPushButton * `[`pb_6`](#class_ui___main_window_1a9445b5598c993dd17e5db7200008a66f) 

#### `public QPushButton * `[`pb_op_mul`](#class_ui___main_window_1a36a1278ef310e54aa1afabfe16b51a35) 

#### `public QPushButton * `[`pb_7`](#class_ui___main_window_1ab7f72cff98b570aaef6cc50ca25227ed) 

#### `public QPushButton * `[`pb_8`](#class_ui___main_window_1a27d521b9a2423842e4e81d79b7725841) 

#### `public QPushButton * `[`pb_9`](#class_ui___main_window_1a90e18bb5639c26308b8bb35d114cf63f) 

#### `public QPushButton * `[`pb_op_div`](#class_ui___main_window_1a21788d666028a4281aad11e588d2cfb5) 

#### `public QPushButton * `[`pb_pt`](#class_ui___main_window_1a4c2896c1def2a3284efb187567c8ded4) 

#### `public QPushButton * `[`pb_0`](#class_ui___main_window_1aa0fd148a57a5a15ac76a685a398d38dd) 

#### `public QPushButton * `[`pb_plus_minus`](#class_ui___main_window_1ac56efc679c953678227fadcbe1e12edc) 

#### `public QPushButton * `[`pb_cmd_enter`](#class_ui___main_window_1a08a848dd88636984ec2ac70c72118542) 

#### `public QStatusBar * `[`statusBar`](#class_ui___main_window_1afa919f3af6f2f526a70f1fa331f63724) 

#### `public QPushButton * `[`pb1`](#class_ui___main_window_1a23eb68fbebd4c24ef320279562b620d8) 

#### `public QPushButton * `[`pb3`](#class_ui___main_window_1a71e84c6fcd472252df0af26f4a24281c) 

#### `public QPushButton * `[`pb4`](#class_ui___main_window_1a4f2b5b986ff25f1dd3599d5a307b02fc) 

#### `public QPushButton * `[`pb2`](#class_ui___main_window_1a7873b3a0dcbf1d553dd38c9e7b488931) 

#### `public QPushButton * `[`pb6`](#class_ui___main_window_1ae686f88a178ef7af71103297af26a4ff) 

#### `public QPushButton * `[`pb9`](#class_ui___main_window_1a75325029b59062f6a8b0282cfeff5e20) 

#### `public QLabel * `[`lbOut`](#class_ui___main_window_1a67cbe8c516acc380833e21e828e63585) 

#### `public QPushButton * `[`pb7`](#class_ui___main_window_1a8e8634c634efc288fece44c3136263db) 

#### `public QPushButton * `[`pb5`](#class_ui___main_window_1a6a03f1ba6305323b05eaf49627096ccf) 

#### `public QPushButton * `[`pb8`](#class_ui___main_window_1a411fffdfb30284be90cf0a70e4ac15c0) 

#### `public QComboBox * `[`cbModeSelect`](#class_ui___main_window_1a2ae9a3cce827922e727fc1bda610b0ec) 

#### `public QLabel * `[`lbMode`](#class_ui___main_window_1a2561845101d70ef59264e630badc95b6) 

#### `public inline void `[`setupUi`](#class_ui___main_window_1acf4a0872c4c77d8f43a2ec66ed849b58)`(QMainWindow * MainWindow)` 

#### `public inline void `[`retranslateUi`](#class_ui___main_window_1a097dd160c3534a204904cb374412c618)`(QMainWindow * MainWindow)` 

# struct `CBattleFieldGridIterator` 

The [CBattleFieldGridIterator](#struct_c_battle_field_grid_iterator) class Wir bauen uns einen Iterator für einen 2 dimensionalen Vektor.

Ist es sinnvoll einen Container zu erfinden, und einen Iterator dafür zu bauen, wenn sich das mit STL Containern umsetzen ließe? - NEIN! Ist es einfacher einen Container zu erfinden, und einen Iterator dafür zu bauen, wenn sich das mit STL Containern umsetzen ließe? - Um Gottes Willen, NEIN! Machen wir es trotzdem? - FUCK YEAH! Warum? - Weil wir es können! 

- Wir implementieren alles in den Header. Das ist nicht schön, aber wir haben eine Template Klasse, und müssen den Compiler zwingen die Klasse kompiliert zu haben, wenn wir sie Brauchen. Das ist eine Möglichkeit, die andere Option findet sich im Container. 

**See also**: [CBattleFieldGrid](#class_c_battle_field_grid)

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`CBattleFieldGridIterator`](#struct_c_battle_field_grid_iterator_1a6bbd1d185a018c9e93b73e42ca93d573)`(TContainerType * vv,std::size_t outer,std::size_t inner)` | [CBattleFieldGridIterator](#struct_c_battle_field_grid_iterator) Im Konstruktor bekommt der Iterator einen Zeiger auf das Grid, und eine Startposition.
`public inline `[`reference`](#struct_c_battle_field_grid_iterator_1a154460fcdd6af04a4627777cedd95a5d)` `[`operator*`](#struct_c_battle_field_grid_iterator_1ae677efc4829f48290930d334b80abfa4)`()` | Ab hier Standard. Alle Iteratoren müssen die folgenden Operatoren implementieren. Die Zugriffsopteratoren (* und ->) müssen const und nicht-const vorhanden sein. Aufpassen beim Lesen, *this benutzt den ersten *-Operatore zum dereferenzieren des Wertes. (Also das, was der Iterator landläufig so macht.) Natürlich implementieren wir den Zugriff nur einmal und benutzen ihn dann.
`public inline `[`reference`](#struct_c_battle_field_grid_iterator_1a154460fcdd6af04a4627777cedd95a5d)` `[`operator*`](#struct_c_battle_field_grid_iterator_1aa0a6d48f822fd398e0974fc4ae5245e3)`() const` | 
`public inline `[`pointer`](#struct_c_battle_field_grid_iterator_1a8d0c325296d51b1928f788ce51f379a3)` `[`operator->`](#struct_c_battle_field_grid_iterator_1a53210d0b69c578ed67792b9a3ba4dc1a)`()` | 
`public inline `[`pointer`](#struct_c_battle_field_grid_iterator_1a8d0c325296d51b1928f788ce51f379a3)` `[`operator->`](#struct_c_battle_field_grid_iterator_1a35f20c631e00b7942f2d9daefd822f00)`() const` | 
`public inline `[`self_type`](#struct_c_battle_field_grid_iterator_1a0239772783c74f374ed0142cdfa05832)` & `[`operator++`](#struct_c_battle_field_grid_iterator_1a88e9ec713f06c7293806f0b062d0efc5)`()` | Inkrement und Dekrement jeweils als Postfix und als Prefix Auch hier wieder einmal implementieren und dann nutzen. Wir greifen auch auf den reference operator zurück
`public inline `[`self_type`](#struct_c_battle_field_grid_iterator_1a0239772783c74f374ed0142cdfa05832)` `[`operator++`](#struct_c_battle_field_grid_iterator_1a326acf9032408f76b85c42358cd58818)`(int)` | 
`public inline `[`self_type`](#struct_c_battle_field_grid_iterator_1a0239772783c74f374ed0142cdfa05832)` & `[`operator--`](#struct_c_battle_field_grid_iterator_1a21e22adcf76eee10dd2e5a5a3ba8ec43)`()` | 
`public inline `[`self_type`](#struct_c_battle_field_grid_iterator_1a0239772783c74f374ed0142cdfa05832)` `[`operator--`](#struct_c_battle_field_grid_iterator_1a49709b76112b7b8156f084387f2cdb3f)`(int)` | 
`public inline `[`difference_type`](#struct_c_battle_field_grid_iterator_1ab9694ba7c7faef5b8c54ed727804e406)` `[`operator-`](#struct_c_battle_field_grid_iterator_1aff85e6b4130bf6847d9715edfc4542c2)`(const `[`self_type`](#struct_c_battle_field_grid_iterator_1a0239772783c74f374ed0142cdfa05832)` & rhs) const` | Und weil wir es wissen wollten und einen Random Access Iterator gebaut haben (sozusagen die Königin Mutter der Iteratoren), müssen wir auch arithmetische Operatoren haben.
`public inline `[`self_type`](#struct_c_battle_field_grid_iterator_1a0239772783c74f374ed0142cdfa05832)` `[`operator+`](#struct_c_battle_field_grid_iterator_1affe6883e4e8fb055afbf6d9c921fdf2f)`(const `[`difference_type`](#struct_c_battle_field_grid_iterator_1ab9694ba7c7faef5b8c54ed727804e406)` rhs) const` | 
`public inline `[`self_type`](#struct_c_battle_field_grid_iterator_1a0239772783c74f374ed0142cdfa05832)` `[`operator-`](#struct_c_battle_field_grid_iterator_1a94a9e7a4798cfefb67b4a04a57705dbe)`(const `[`difference_type`](#struct_c_battle_field_grid_iterator_1ab9694ba7c7faef5b8c54ed727804e406)` rhs) const` | 
`public inline bool `[`operator==`](#struct_c_battle_field_grid_iterator_1a3b269ef178e25bd65f0602bb39e41362)`(const `[`self_type`](#struct_c_battle_field_grid_iterator_1a0239772783c74f374ed0142cdfa05832)` & other) const` | Und zu guter Letzt muss der Kram noch vergleichbar sein.
`public inline bool `[`operator!=`](#struct_c_battle_field_grid_iterator_1a4365c3556af5fc6a548cfc76b87f96dc)`(const `[`self_type`](#struct_c_battle_field_grid_iterator_1a0239772783c74f374ed0142cdfa05832)` & other) const` | 
`public inline bool `[`operator>`](#struct_c_battle_field_grid_iterator_1a1127ff379c7875b233915fb3457b85d6)`(const `[`self_type`](#struct_c_battle_field_grid_iterator_1a0239772783c74f374ed0142cdfa05832)` & rhs) const` | 
`public inline bool `[`operator<`](#struct_c_battle_field_grid_iterator_1a59434d15c7b077826a55f327aa663ab9)`(const `[`self_type`](#struct_c_battle_field_grid_iterator_1a0239772783c74f374ed0142cdfa05832)` & rhs) const` | 
`public inline bool `[`operator>=`](#struct_c_battle_field_grid_iterator_1ad9738921930d95445f35e6196621e79d)`(const `[`self_type`](#struct_c_battle_field_grid_iterator_1a0239772783c74f374ed0142cdfa05832)` & rhs) const` | 
`public inline bool `[`operator<=`](#struct_c_battle_field_grid_iterator_1affd00a0f8f924964b96e4d04ec882064)`(const `[`self_type`](#struct_c_battle_field_grid_iterator_1a0239772783c74f374ed0142cdfa05832)` & rhs) const` | 
`public inline size_t `[`x`](#struct_c_battle_field_grid_iterator_1acb8de91d4431c1c4f1318a76be1d4c8c)`() const` | x der Iterator soll auch seine Position verraten
`public inline size_t `[`y`](#struct_c_battle_field_grid_iterator_1a9d787e5c1bf06b6f6cb819cea93344e2)`() const` | y der Iterator soll auch seine Position verraten
`typedef `[`iterator_category`](#struct_c_battle_field_grid_iterator_1a5dc9b25c59de2d60bf877b16dbb9366a) | Diese definitionen sind notwendig, damit der Compiler das ganze Konstrukt als Iterator nutzen kann Wie bauen einen Random Access Iterator, man kann also in beide Richtungen iterieren und auch frei hin- und herspringem.
`typedef `[`difference_type`](#struct_c_battle_field_grid_iterator_1ab9694ba7c7faef5b8c54ed727804e406) | 
`typedef `[`value_type`](#struct_c_battle_field_grid_iterator_1ab82c8d5894be7aaa6df0850876e63bab) | 
`typedef `[`pointer`](#struct_c_battle_field_grid_iterator_1a8d0c325296d51b1928f788ce51f379a3) | 
`typedef `[`reference`](#struct_c_battle_field_grid_iterator_1a154460fcdd6af04a4627777cedd95a5d) | 
`typedef `[`self_type`](#struct_c_battle_field_grid_iterator_1a0239772783c74f374ed0142cdfa05832) | für die Bessere Lesbarkeit der self_type ist nicht notwendig.

## Members

#### `public inline  `[`CBattleFieldGridIterator`](#struct_c_battle_field_grid_iterator_1a6bbd1d185a018c9e93b73e42ca93d573)`(TContainerType * vv,std::size_t outer,std::size_t inner)` 

[CBattleFieldGridIterator](#struct_c_battle_field_grid_iterator) Im Konstruktor bekommt der Iterator einen Zeiger auf das Grid, und eine Startposition.

#### Parameters
* `vv` Zeiger auf den Container 

* `outer` y-Pos 

* `inner` x-Pos

#### `public inline `[`reference`](#struct_c_battle_field_grid_iterator_1a154460fcdd6af04a4627777cedd95a5d)` `[`operator*`](#struct_c_battle_field_grid_iterator_1ae677efc4829f48290930d334b80abfa4)`()` 

Ab hier Standard. Alle Iteratoren müssen die folgenden Operatoren implementieren. Die Zugriffsopteratoren (* und ->) müssen const und nicht-const vorhanden sein. Aufpassen beim Lesen, *this benutzt den ersten *-Operatore zum dereferenzieren des Wertes. (Also das, was der Iterator landläufig so macht.) Natürlich implementieren wir den Zugriff nur einmal und benutzen ihn dann.

#### `public inline `[`reference`](#struct_c_battle_field_grid_iterator_1a154460fcdd6af04a4627777cedd95a5d)` `[`operator*`](#struct_c_battle_field_grid_iterator_1aa0a6d48f822fd398e0974fc4ae5245e3)`() const` 

#### `public inline `[`pointer`](#struct_c_battle_field_grid_iterator_1a8d0c325296d51b1928f788ce51f379a3)` `[`operator->`](#struct_c_battle_field_grid_iterator_1a53210d0b69c578ed67792b9a3ba4dc1a)`()` 

#### `public inline `[`pointer`](#struct_c_battle_field_grid_iterator_1a8d0c325296d51b1928f788ce51f379a3)` `[`operator->`](#struct_c_battle_field_grid_iterator_1a35f20c631e00b7942f2d9daefd822f00)`() const` 

#### `public inline `[`self_type`](#struct_c_battle_field_grid_iterator_1a0239772783c74f374ed0142cdfa05832)` & `[`operator++`](#struct_c_battle_field_grid_iterator_1a88e9ec713f06c7293806f0b062d0efc5)`()` 

Inkrement und Dekrement jeweils als Postfix und als Prefix Auch hier wieder einmal implementieren und dann nutzen. Wir greifen auch auf den reference operator zurück

#### `public inline `[`self_type`](#struct_c_battle_field_grid_iterator_1a0239772783c74f374ed0142cdfa05832)` `[`operator++`](#struct_c_battle_field_grid_iterator_1a326acf9032408f76b85c42358cd58818)`(int)` 

#### `public inline `[`self_type`](#struct_c_battle_field_grid_iterator_1a0239772783c74f374ed0142cdfa05832)` & `[`operator--`](#struct_c_battle_field_grid_iterator_1a21e22adcf76eee10dd2e5a5a3ba8ec43)`()` 

#### `public inline `[`self_type`](#struct_c_battle_field_grid_iterator_1a0239772783c74f374ed0142cdfa05832)` `[`operator--`](#struct_c_battle_field_grid_iterator_1a49709b76112b7b8156f084387f2cdb3f)`(int)` 

#### `public inline `[`difference_type`](#struct_c_battle_field_grid_iterator_1ab9694ba7c7faef5b8c54ed727804e406)` `[`operator-`](#struct_c_battle_field_grid_iterator_1aff85e6b4130bf6847d9715edfc4542c2)`(const `[`self_type`](#struct_c_battle_field_grid_iterator_1a0239772783c74f374ed0142cdfa05832)` & rhs) const` 

Und weil wir es wissen wollten und einen Random Access Iterator gebaut haben (sozusagen die Königin Mutter der Iteratoren), müssen wir auch arithmetische Operatoren haben.

#### `public inline `[`self_type`](#struct_c_battle_field_grid_iterator_1a0239772783c74f374ed0142cdfa05832)` `[`operator+`](#struct_c_battle_field_grid_iterator_1affe6883e4e8fb055afbf6d9c921fdf2f)`(const `[`difference_type`](#struct_c_battle_field_grid_iterator_1ab9694ba7c7faef5b8c54ed727804e406)` rhs) const` 

#### `public inline `[`self_type`](#struct_c_battle_field_grid_iterator_1a0239772783c74f374ed0142cdfa05832)` `[`operator-`](#struct_c_battle_field_grid_iterator_1a94a9e7a4798cfefb67b4a04a57705dbe)`(const `[`difference_type`](#struct_c_battle_field_grid_iterator_1ab9694ba7c7faef5b8c54ed727804e406)` rhs) const` 

#### `public inline bool `[`operator==`](#struct_c_battle_field_grid_iterator_1a3b269ef178e25bd65f0602bb39e41362)`(const `[`self_type`](#struct_c_battle_field_grid_iterator_1a0239772783c74f374ed0142cdfa05832)` & other) const` 

Und zu guter Letzt muss der Kram noch vergleichbar sein.

#### `public inline bool `[`operator!=`](#struct_c_battle_field_grid_iterator_1a4365c3556af5fc6a548cfc76b87f96dc)`(const `[`self_type`](#struct_c_battle_field_grid_iterator_1a0239772783c74f374ed0142cdfa05832)` & other) const` 

#### `public inline bool `[`operator>`](#struct_c_battle_field_grid_iterator_1a1127ff379c7875b233915fb3457b85d6)`(const `[`self_type`](#struct_c_battle_field_grid_iterator_1a0239772783c74f374ed0142cdfa05832)` & rhs) const` 

#### `public inline bool `[`operator<`](#struct_c_battle_field_grid_iterator_1a59434d15c7b077826a55f327aa663ab9)`(const `[`self_type`](#struct_c_battle_field_grid_iterator_1a0239772783c74f374ed0142cdfa05832)` & rhs) const` 

#### `public inline bool `[`operator>=`](#struct_c_battle_field_grid_iterator_1ad9738921930d95445f35e6196621e79d)`(const `[`self_type`](#struct_c_battle_field_grid_iterator_1a0239772783c74f374ed0142cdfa05832)` & rhs) const` 

#### `public inline bool `[`operator<=`](#struct_c_battle_field_grid_iterator_1affd00a0f8f924964b96e4d04ec882064)`(const `[`self_type`](#struct_c_battle_field_grid_iterator_1a0239772783c74f374ed0142cdfa05832)` & rhs) const` 

#### `public inline size_t `[`x`](#struct_c_battle_field_grid_iterator_1acb8de91d4431c1c4f1318a76be1d4c8c)`() const` 

x der Iterator soll auch seine Position verraten

#### Returns
x-coordinate

#### `public inline size_t `[`y`](#struct_c_battle_field_grid_iterator_1a9d787e5c1bf06b6f6cb819cea93344e2)`() const` 

y der Iterator soll auch seine Position verraten

#### Returns
y-coordinate

#### `typedef `[`iterator_category`](#struct_c_battle_field_grid_iterator_1a5dc9b25c59de2d60bf877b16dbb9366a) 

Diese definitionen sind notwendig, damit der Compiler das ganze Konstrukt als Iterator nutzen kann Wie bauen einen Random Access Iterator, man kann also in beide Richtungen iterieren und auch frei hin- und herspringem.

#### `typedef `[`difference_type`](#struct_c_battle_field_grid_iterator_1ab9694ba7c7faef5b8c54ed727804e406) 

#### `typedef `[`value_type`](#struct_c_battle_field_grid_iterator_1ab82c8d5894be7aaa6df0850876e63bab) 

#### `typedef `[`pointer`](#struct_c_battle_field_grid_iterator_1a8d0c325296d51b1928f788ce51f379a3) 

#### `typedef `[`reference`](#struct_c_battle_field_grid_iterator_1a154460fcdd6af04a4627777cedd95a5d) 

#### `typedef `[`self_type`](#struct_c_battle_field_grid_iterator_1a0239772783c74f374ed0142cdfa05832) 

für die Bessere Lesbarkeit der self_type ist nicht notwendig.

# struct `PlayFieldCoords` 

```
struct PlayFieldCoords
  : public QPair< int, int >
```  

The [PlayFieldCoords](#struct_play_field_coords) struct Koordinaten auf dem Spielfeld, mit valid funktion.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`PlayFieldCoords`](#struct_play_field_coords_1a27e4e5256047295606b7f47f0361355f)`()` | 
`public  `[`PlayFieldCoords`](#struct_play_field_coords_1aa3ef613bde897ad3223f9905ffe0355f)`(const int i1,const int i2)` | 
`public bool `[`isValid`](#struct_play_field_coords_1abed672ee3fdc2773cd2fcde216e39363)`() const` | 
`public int `[`x`](#struct_play_field_coords_1a986942a739e09aeeef94113c5a5f45fa)`() const` | 
`public int `[`y`](#struct_play_field_coords_1a2d9219a9ccd747ef4a02c780990bce53)`() const` | 

## Members

#### `public  `[`PlayFieldCoords`](#struct_play_field_coords_1a27e4e5256047295606b7f47f0361355f)`()` 

#### `public  `[`PlayFieldCoords`](#struct_play_field_coords_1aa3ef613bde897ad3223f9905ffe0355f)`(const int i1,const int i2)` 

#### `public bool `[`isValid`](#struct_play_field_coords_1abed672ee3fdc2773cd2fcde216e39363)`() const` 

#### `public int `[`x`](#struct_play_field_coords_1a986942a739e09aeeef94113c5a5f45fa)`() const` 

#### `public int `[`y`](#struct_play_field_coords_1a2d9219a9ccd747ef4a02c780990bce53)`() const` 

# struct `TGridSize` 

The [TGridSize](#struct_t_grid_size) struct für die Größe bauen wir uns eine Struktur.

wir könnten QSize nehmen, aber wir wollen lieber size_t als Datentyp und noch die Zählfunktion drin haben.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public size_t `[`width`](#struct_t_grid_size_1a1e4aa79a8a7e74c01900f8af1e855ec0) | 
`public size_t `[`height`](#struct_t_grid_size_1aacb0f40b51844a1ca5550ff2f96682b8) | 
`public inline size_t `[`numFields`](#struct_t_grid_size_1a4a1e4a4e49aa852c09c44ab0fb835cef)`() const` | 

## Members

#### `public size_t `[`width`](#struct_t_grid_size_1a1e4aa79a8a7e74c01900f8af1e855ec0) 

#### `public size_t `[`height`](#struct_t_grid_size_1aacb0f40b51844a1ca5550ff2f96682b8) 

#### `public inline size_t `[`numFields`](#struct_t_grid_size_1a4a1e4a4e49aa852c09c44ab0fb835cef)`() const` 

Generated by [Moxygen](https://sourcey.com/moxygen)