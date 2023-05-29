# Shipment-simulator

Klasy:
    -Shipment(atrybuty: destination, cost, expenses, name, delivery_type):
        -Letter(atrybuty takie jak w klasie Shipment z hard zakodowanymi atrybutami cost, expenses)
        -Package(atrybuty takie jak w klasie Shipment, dodatkowo ma atrybut weight, który jest losową liczbą od 1 do 10 i na podstawie której obliczane są cost i expenses)
    -Delivery_method:
        -
    -Container(atrybuty: shipments, który jest mapą obiektów klasy Shipment z ich nazwą jako klucz):
        -City(atrybuty takie jak w klasie Container, dodatkowo ma atrybuty distance i name)
        -HQ(atrybuty takie jak w klasie Container, dodatkowo ma atrybuty balance, delivery_methods(tu znajdują się dostępne obiekty klasy Delivery_method), working_delivery_method(tu znajdują się obietky klasy Delivery_method, które nie są dostępne w tej turze), mailbox_num, delivery_man_num, parcel_locker_num)
    -Delivery_method(atrybuty: base_price, expenses, name, delivery_type):
        -Parcel_locker(atrybuty takie jak w klasie Delivery_method automatycznie przy wywołaniu konstrukora wszystkim atrybutom poza name zostaje przypisana wartość)
        -Delivery_man(tak jak w Parcel_locker)
        -Mailbox(tak jak w Parcel_locker)
    -Game(atrybuty: round_count, package_num, letter_num, cities(map of cities involved in a game))

Na początku gry gracz dostaje wybór zaczęcia gry od nowa lub wczytanie jej. JeZeli gracz wybierze nową grę to dostaje na start 1000$. W grze istnieje 5 miast z różnymi nazwami i odległościami.

Gra działa turowo gracz w jednej turze może wykorzystać dostawcę tylko raz. Dostawca może zabrać wszystkie paczki z podanego miasta lub zawieźć jedną paczkę do jej celu. Jeżeli paczka zostanie dostarczona do złego miasta lub przez złą metodę dostawy to gracz nie dostaje wynagrodzenia za dostarczenie paczki oraz razem z ponoszeniem kosztów za wysyłkę zostaję nałożona na niego kara w wysokości 50$. Gracz podczas tury może także kupić nowych dostawców, którzy mają różne metody dostawy. Gracz może także manualnie zakończyć turę kiedy uzna, że nie może zrobić nic więcej w obecnej turze. Gracz może także wyjść i zapisać aktualny postęp. Paczki generują się pod koniec tury w losowym mieście i z losowymi parametrami. Ilośc generowanych paczek zależy od obecnego numeru rundy.
