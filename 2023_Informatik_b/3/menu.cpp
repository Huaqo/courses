#include <iostream>
#include <string>
#include <vector>

// Enum für die verschiedenen Menüpunkte
enum MenuType {
    Vorspeise,
    Hauptgang,
    Dessert
};

// Struct für die Details eines Menüpunkts
struct MenuItem {
    MenuType type;
    std::string name;
    std::string description;
    double price;
};

void showMenu(const std::vector<MenuItem>& menu) {
    for (size_t i = 0; i < menu.size(); ++i) {
        std::string type;
        switch (menu[i].type) {
            case Vorspeise:
                type = "Vorspeise";
                break;
            case Hauptgang:
                type = "Hauptgang";
                break;
            case Dessert:
                type = "Dessert";
                break;
        }
        std::cout << type << ": " << menu[i].name << " - " << menu[i].description << " (€" << menu[i].price << ")\n";
    }
}

MenuItem searchMenuItem(const std::vector<MenuItem>& menu, const std::string& name) {
    for (size_t i = 0; i < menu.size(); ++i) {
        if (menu[i].name == name) {
            return menu[i];
        }
    }
    return MenuItem{static_cast<MenuType>(-1), "", "", -1.0};
}

int main() {
    // Erstellen des Restaurantmenüs
    std::vector<MenuItem> menu = {
        {Vorspeise, "Bruschetta", "Geröstetes Brot mit Tomaten, Knoblauch und Basilikum", 5.0},
        {Hauptgang, "Spaghetti Bolognese", "Spaghetti mit würziger Hackfleisch-Tomatensauce", 10.0},
        {Dessert, "Tiramisu", "Italienisches Dessert aus Löffelbiskuit, Mascarpone und Kaffee", 6.0}
    };

    std::cout << "Willkommen im Restaurant!\n";
    std::cout << "Möchten Sie das Menü anzeigen oder nach einem bestimmten Menüpunkt suchen?\n";
    std::cout << "1. Menü anzeigen\n";
    std::cout << "2. Nach Menüpunkt suchen\n";
    std::cout << "3. Beenden\n";

    int option;
    std::cin >> option;

    while (option != 3) {
        if (option == 1) {
            showMenu(menu);
        } else if (option == 2) {
            std::string name;
            std::cout << "Geben Sie den Namen des Menüpunkts ein, nach dem Sie suchen möchten: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            MenuItem item = searchMenuItem(menu, name);
            if (item.price != -1.0) {
                std::cout << item.name << " - " << item.description << " (€" << item.price << ")\n";
            } else {
                std::cout << "Menüpunkt nicht gefunden.\n";
            }
        } else {
            std::cout << "Ungültige Option.\n";
        }

        std::cout << "\nMöchten Sie das Menü anzeigen oder nach einem bestimmten Menüpunkt suchen?\n";
        std::cout << "1. Menü anzeigen\n";
        std::cout << "2. Nach Menüpunkt suchen\n";
        std::cout << "3. Beenden\n";
        std::cin >> option;
    }

    std::cout << "Vielen Dank für Ihren Besuch! Auf Wiedersehen!\n";
    return 0;
}