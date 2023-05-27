# Shipment-simulator

Początkowe klasy:
    -Shipment:
        -Letter
        -Package
    -Delivery_method:
        -Parcel_locker
        -Delivery_man
        -Mailbox
    -Container (shipments(map)):
        -City (name(string) and distance(float) from hq)
        -HQ (balance(float))

Shipment has price attribute, Letter has a set cost. Package has also weight attribute, on which the price depends.
Delivery method has a distance attribute, on which the price depends. Different subclasses have different price multipliers.