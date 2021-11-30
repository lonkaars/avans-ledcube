# avans-ledcube

(in dutch again haha)

onze ledcube is iets anders dan de gemiddelde ledcube. onze leds zijn
aangesloten als een 8x8 matrix waarbij alle anodes in rijen, en alle cathodes
in kolommen zijn verbonden. hierdoor gebruikt onze ledcube maar acht
weerstanden inplaats van zestien, en geen transistoren of mosfets. ook worden
maar drie uitgangen van de arduino gebruikt voor de seriële ingang, seriële
klok, en de latch klok van het shiftregister.

## software

de software is als gevolg hierdoor ook anders ingericht. de atmega328p heeft
ingebouwde pwm timers, die je zou kunnen gebruiken om snel door de vier lagen
van de ledcube heen te schakelen. omdat deze timers los van je code draaien kun
je de ingebouwde `delay()` gewoon gebruiken om de animaties makkelijker te
implementeren, maar dit werkt alleen wanneer je transistoren gebruikt en ze
direct op pwm uitgangen aansluit.

daarom gebruikt onze software geen `delay()` of andere 'blokkerende' functies,
maar timers. dit zorgt ervoor dat de ingebouwde `loop()` functie van de arduino
vaak genoeg draait om het te laten lijken alsof alle led's van de ledcube
tegelijkertijd aan zijn.

de software is opgesplitst in losse bestanden om overzichtelijkheid te
behouden. alle documentatie bevindt zich in de header (.h) bestanden, is in het
engels, en is in doxygen formaat. hier is een beknopte beschrijving van de
bestanden:

```
software/
├── animation.h      --
├── animation.ino    helpfuncties voor animaties
├── consts.h         algemene constantes
├── effects.h        bevat ook opties voor de diavoorstelling van animaties
├── effects.ino      de animaties die weergeven worden
├── readme.md        dit bestand
├── scan.h           --
├── scan.ino         functies omtrent het schakelen van de rijen
├── shift.h          --
├── shift.ino        functies die het shiftregister besturen
├── software.h       --
├── software.ino     hoofdbestand/ingangspunt
├── util.h           --
└── util.ino         gereedschapsfuncties
```

de code voor de animaties is nog niet compleet af, animatie 1 en 3 doen het
inmiddels, maar 2 heeft nog wat problemen door de `fill_plane` functie. deze ga
ik opnieuw implementeren en woensdag testen.

ook het algoritme om lege scanrijen over te slaan is nog niet afgewerkt en
wordt dus ook op woensdag getest.
