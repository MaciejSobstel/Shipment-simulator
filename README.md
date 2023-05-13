# Shipment-simulator

Początkowe klasy:
    -Shipment:
        -Letter
        -Package
    -Delivery_method:
        -(Some delivery methods with different price multipliers)

Shipment has price attribute, Letter has a set cost. Package has also weight attribute, on which the price depends.
Delivery method has a distance attribute, on which the price depends. Different subclasses have different price multipliers.