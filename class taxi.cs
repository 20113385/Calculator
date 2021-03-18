class program
{
    static void Main(string[]args)
    {
        // membuat objek Taxi
        Taxi taxi = new Taxi();

        // pengesetan nilai properties
        taxi.DriverName = "jono";
        taxi.OnDuty = true;
        taxi.NumPassenger = 10;

        // pemanggilan methord
        taxi.TaxiInfo();
        taxi.PickUpPassenger();
        taxi.DropOffPassenger();

        Console.ReadKey();
    }
}