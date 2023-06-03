# Shipment-simulator
<h2> Podział zadań: </h2>
<ul>
    <li>Klasy Shipment, Delivery_method, Game - <b>Maciej Sobstel</b>
    <li>Klasa Conatiner, zapisywanie i odczyt z pliku - <b>Aleksander Gozdowski</b> (PewienInternauta)
    <li>plik main.py - <b>Artur Węgrzycki</b> (W3g0Rz)
</ul>
<h2>Klasy: </h2>
<ul>
    <li><b>Shipment</b> (atrybuty: destination, cost, expenses, name, delivery_type) :
        <ul>
        <li><b>Letter</b> (atrybuty takie jak w klasie Shipment z hard zakodowanymi atrybutami cost, expenses)
        <li><b>Package</b> (atrybuty takie jak w klasie Shipment, dodatkowo ma atrybut weight, który jest losową liczbą od 1 do 10 i na podstawie której obliczane są cost i expenses)
        </ul>
    <li><b>Container</b> (atrybuty: shipments, który jest mapą obiektów klasy Shipment z ich nazwą jako klucz):
        <ul>
        <li><b>City</b> (atrybuty takie jak w klasie Container, dodatkowo ma atrybuty distance i name)
        <li><b>HQ</b> (atrybuty takie jak w klasie Container, dodatkowo ma atrybuty balance, delivery_methods (tu znajdują się dostępne obiekty klasy Delivery_method), working_delivery_method (tu znajdują się obietky klasy Delivery_method, które nie są dostępne w tej turze), mailbox_num, delivery_man_num, parcel_locker_num)
        </ul>
    <li><b>Delivery_method</b> (atrybuty: base_price, expenses, name, delivery_type):
        <ul>
        <li><b>Parcel_locker</b> (atrybuty takie jak w klasie Delivery_method automatycznie przy wywołaniu konstrukora wszystkim atrybutom poza name zostaje przypisana wartość)
        <li><b>Delivery_man</b> (tak jak w Parcel_locker)
        <li><b>Mailbox</b> (tak jak w Parcel_locker)
        </ul>
    <li><b>Game</b> (atrybuty: round_count, package_num, letter_num, cities(mapa obiektów klasy City z ich nazwą jako klucz))
</ul>
<p>
Na początku gry gracz dostaje wybór zaczęcia gry od nowa lub wczytanie jej z pliku. Jeżeli gracz wybierze nową grę to dostaje na start 1000$. W grze istnieje 5 miast z różnymi nazwami i odległościami.
</p>
<p>
Gra działa turowo gracz w jednej turze może wykorzystać dostawcę tylko raz. Dostawca może zabrać wszystkie paczki z podanego miasta lub zawieźć jedną paczkę do jej celu. Jeżeli paczka zostanie dostarczona do złego miasta lub przez złą metodę dostawy to gracz nie dostaje wynagrodzenia za dostarczenie paczki oraz razem z ponoszeniem kosztów za wysyłkę zostaję nałożona na niego kara w wysokości 50$. Gracz podczas tury może także kupić nowych dostawców, którzy mają różne metody dostawy. Gracz może także manualnie zakończyć turę kiedy uzna, że nie może zrobić nic więcej w obecnej turze. Gracz może także wyjść i zapisać aktualny postęp. Paczki generują się pod koniec tury w losowym mieście i z losowymi parametrami. Ilośc generowanych paczek zależy od obecnego numeru rundy.
</p>
