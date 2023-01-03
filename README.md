# Zadanie do wykonania czesc 1 - przetwarzanie_obrazow
Napisać program do obsługi czarno-białych obrazów rastrowych (ze skalą szarości). Takie obrazy mogą być przedstawione w postaci dwuwymiarowej tablicy, której elementy są liczbami całkowitymi. Każda z liczb reprezentuje kolor jednego punktu (piksela) obrazu, przy czym przyjmuje się, że kolorowi czarnemu odpowiada wartość 0, a kolorowi białemu wartość maksymalna, zależna od liczby poziomów szarości\

Program ma obsługiwać obrazy zapisane w plikach w formacie PGM.

# Zadanie do wykonania czesc 2 - przetwarzanie_obrazow
Zmodyfikować program do przetwarzania obrazów z laboratorium 3 zgodnie z następującymi założeniami:

Wybrane elementy programu powinny tworzyć moduł z odpowiednim plikiem nagłówkowym.

Wprowadzić strukturę danych opisującą całościowo przechowywany w pamięci obraz. Wykorzystać możliwość dynamicznego ustalania rozmiaru tablic, aby dopasować rozmiar przechowywanych danych do rzeczywistych wymiarów obrazu.\

Zmodyfikować funkcje programu tak, aby wykorzystywały wprowadzoną strukturę.\

Zmodyfikować dokumentację programu tak, by odpowiadała wprowadzonym powyżej zmianom. Podobnie dokonywać modyfikacji dokumentacji programu po zrealizowaniu każdego z poniżej podanych punktów\

Uzupełnić funkcje o asercje sprawdzające zaproponowane warunki poprawności.\

Dodać do programu obsługę obrazów kolorowych w formacie ppm (P3). Funkcja wczytująca obraz powinna automatycznie rozpoznać typ pliku i dostosować wielkość alokowanej pamięci, a struktura obrazu – przechowywać informację z jakim obrazem mamy do czynienia.\

Zdefiniować funkcję konwersji do stopni szarości dla obrazów kolorowych: każdy punkt nowego obrazu jest średnią arytmetyczną wartości składowych kolorów. Przekonwertowany obraz powinien być zapisywany w formacie PGM (opcjonalnie: do wyboru użytkownika PGM lub PPM).

