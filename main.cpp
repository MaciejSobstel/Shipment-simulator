#include <iostream>
#include "game.cpp"
using namespace std;

int main(){
    bool running = true;
    int gameoption;
    cout<<"1. New game"<<endl;
    cout<<"2. Load game"<<endl;
    cin>>gameoption;
    Game game;
    HQ hq(1000);
    City warszawa("Warszawa", 100);
    City krakow("Kraków", 250);
    City poznan("Poznań", 200);
    City wroclaw("Wrocław", 400);
    City gdansk("Gdańsk", 300);
    switch(gameoption)
    {
    case 1:
        game.add_city(warszawa);
        game.add_city(krakow);
        game.add_city(poznan);
        game.add_city(wroclaw);
        game.add_city(gdansk);
        game.genShipmentInCity();
        break;
    case 2:
        game.loadState();
        hq.loadState();
        break;
    default:
        break;
    }
    
    while(running){
        hq.returnDeliveryMethods();
        cout<<"---ROUND " + to_string(game.getRoundCount()) + "---"<<endl;
        cout<<"---CHOOSE WHAT YOU WANT TO DO THIS ROUND---"<<endl;
        cout<<endl;
        bool round_running = true;
        while(round_running){
            hq.print_balance();
            hq.print_shipments();
            hq.print_delivery_methods();
            game.print_cities();
            int option;
            cout<<"Choose option:"<<endl;
            cout<<"1. Buy parcel locker"<<endl;
            cout<<"2. Buy mailbox"<<endl;
            cout<<"3. Buy delivery man"<<endl;
            cout<<"4. Retrive package from city"<<endl;
            cout<<"5. Send package to city"<<endl;
            cout<<"6. End round"<<endl;
            cout<<"7. Save and exit"<<endl;
            cin>>option;
            string city_n;
            string ship_name;
            switch (option)
            {
            case 1:
                hq.buy_parcel_locker();
                break;
            case 2:
                hq.buy_mailbox();
                break;
            case 3:
                hq.buy_delivery_man();
                break;
            case 4:
                cout<<"Choose city:"<<endl;
                cout<<"1. Warszawa"<<endl;
                cout<<"2. Kraków"<<endl;
                cout<<"3. Poznań"<<endl;
                cout<<"4. Wrocław"<<endl;
                cout<<"5. Gdańsk"<<endl;
                int city_option;
                cin>>city_option;
                switch (city_option)
                {
                case 1:
                    city_n = "Warszawa";
                    break;
                case 2:
                    city_n = "Kraków";
                    break;
                case 3:
                    city_n = "Poznań";
                    break;
                case 4:
                    city_n = "Wrocław";
                    break;
                case 5:
                    city_n = "Gdańsk";
                    break;
                default:
                    cout<<"Incorrect option"<<endl;
                    break;
                }
                cout<<"Choose delivery method:"<<endl;
                cout<<"1. Parcel Locker"<<endl;
                cout<<"2. Mailbox"<<endl;
                cout<<"3. Delivery man"<<endl;
                int delivery_option;
                cin>>delivery_option;
                switch (delivery_option)
                {
                case 1:
                    if(hq.sendDeliveryMethod("Parcel_locker") == true)
                        game.retreivePackage(city_n, hq);
                    else
                        cout<<"You don't have this delivery method"<<endl;
                    break;
                case 2:
                    if(hq.sendDeliveryMethod("Mailbox") == true)
                        game.retreivePackage(city_n, hq);
                    else
                        cout<<"You don't have this delivery method"<<endl;
                    break;
                case 3:
                    if(hq.sendDeliveryMethod("Delivery_man") == true)
                        game.retreivePackage(city_n, hq);
                    else
                        cout<<"You don't have this delivery method"<<endl;
                    break;
                default:
                    cout<<"Incorrect option"<<endl;
                    break;
                }
                break;
            case 5:
                cout<<"Choose city:"<<endl;
                cout<<"1. Warszawa"<<endl;
                cout<<"2. Kraków"<<endl;
                cout<<"3. Poznań"<<endl;
                cout<<"4. Wrocław"<<endl;
                cout<<"5. Gdańsk"<<endl;
                int city_option_send;
                cin>>city_option_send;
                switch (city_option_send)
                {
                case 1:
                    city_n = "Warszawa";
                    break;
                case 2:
                    city_n = "Kraków";
                    break;
                case 3:
                    city_n = "Poznań";
                    break;
                case 4:
                    city_n = "Wrocław";
                    break;
                case 5:
                    city_n = "Gdańsk";
                    break;
                default:
                    cout<<"Incorrect option"<<endl;
                    break;
                }
                cout<<"Please type shipment name:"<<endl;
                cin>>ship_name;
                if(game.isShipmentInStorage(ship_name, hq) == true){
                    cout<<"Choose delivery method:"<<endl;
                    cout<<"1. Parcel Locker"<<endl;
                    cout<<"2. Mailbox"<<endl;
                    cout<<"3. Delivery man"<<endl;
                    int delivery_option_send;
                    cin>>delivery_option_send;
                    switch (delivery_option_send)
                    {
                    case 1:
                        if(hq.sendDeliveryMethod("Parcel_locker") == true){
                            game.sendPackage(city_n, "Parcel_locker", ship_name, hq);
                        }
                        else
                            cout<<"You don't have this delivery method"<<endl;
                        break;
                    case 2:
                        if(hq.sendDeliveryMethod("Mailbox") == true){
                            game.sendPackage(city_n, "Mailbox", ship_name, hq);
                        }
                        else 
                            cout<<"You don't have this delivery method"<<endl;
                        break;
                    case 3:
                        if(hq.sendDeliveryMethod("Delivery_man") == true){
                            game.sendPackage(city_n, "Delivery_man", ship_name, hq);
                        }
                        else
                            cout<<"You don't have this delivery method"<<endl;
                        break;
                    default:
                        cout<<"Incorrect option"<<endl;
                        break;
                    }
                }
                else 
                    cout<<"Shipment name incorrect"<<endl;
                break;
            case 6:
                round_running = false;
                break;
            case 7:
                game.saveState();
                hq.saveState();
                round_running = false;
                running = false;
                break;
            default:
                cout<<"Incorrect option"<<endl;
                break;
            }
        }
        game.countRoundUp();
        for(int i=0; i<game.getRoundCount();i++){
            game.genShipmentInCity();
        }
    }
}