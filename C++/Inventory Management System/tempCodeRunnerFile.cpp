
#include <iostream>
#include<ctime>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <limits>
#include <iomanip>

using namespace std;

struct PriceOption {
    string quantityLabel;
    double price;
};

struct Product {
    string name;
    int totalStock;
    vector<PriceOption> prices;
    string description;
};

vector<Product> products;

struct Customer {
    string email;
    string password;
};

vector<Customer> customers;

// Cross-platform clear screen
void clearScreen() {
    // This sends ANSI escape codes to clear terminal screen
    cout << "\033[2J\033[1;1H";
}

// Cross-platform wait for key press (replaces getch())
void waitForKey() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // flush input buffer
    cin.get();
}

void saveProducts();
void loadCustomers();

// Cursor control replaced with a no-op or you can remove usage
// Since SetConsoleCursorPosition is Windows-only, we'll skip this.
void gotoXY(int x, int y) {
    // Optional: you could implement ANSI cursor movement if needed,
    // but your code doesn't seem to critically depend on it,
    // so leaving empty for now.
    (void)x; (void)y; // avoid unused warnings
}

//================ Team Display ====================
void ShowTeamName() {
    clearScreen();
    cout << "========================================\n";
    cout << "|     3 Bits Dynamics                  |\n";
    cout << "========================================\n";
    cout << "|  Members:                            |\n";
    cout << "|  1. Mahir Jamal  - C231244           |\n";
    cout << "|  2. Zabed Mahmud - C233122           |\n";
    cout << "|  2. Sohag        - C241081           |\n";
    cout << "|  2. Dil Dihan.   - C241084           |\n";
    cout << "========================================\n";
    waitForKey();             
}

//================ Admin Menu ====================
void adminMenu() {
    clearScreen();
    cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "=================================\n";
    cout << "|          Admin Menu           |\n";
    cout << "=================================\n";
    cout << " 1) Add Product\n";
    cout << " 2) Delete Product\n";
    cout << " 3) Update Product\n";
    cout << " 4) Stock Tracking\n";
    cout << " 5) View Sales Report\n";
    cout << " 6) View All Products\n";
    cout << " 7) Exit\n";
    cout << "=================================\n\n";
    cout << "Select your preferred option:  ";
}

//================ Update Products =====================
void updateProduct() {
    if (products.empty()) {
        cout << "No products available to update.\n";
        waitForKey();
        return;
    }
    clearScreen();
    cout << "Select product to update:\n";
    for (int i = 0; i < products.size(); ++i)
        cout << (i + 1) << ") " << products[i].name << "\n";
    cout << "Enter number: ";
    int choice;
    while (!(cin >> choice) || choice < 1 || choice > products.size()) {
        cout << "Invalid choice. Enter again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    Product& p = products[choice - 1];
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // flush newline

    while (true) {
        clearScreen();
        cout << "Updating Product: " << p.name << "\n";
        cout << "1) Update Name\n";
        cout << "2) Update Description\n";
        cout << "3) Update Total Stock\n";
        cout << "4) Update Prices\n";
        cout << "5) Back to Admin Menu\n";

        int option;
        cout << "Select option: ";
        while (!(cin >> option) || option < 1 || option > 5) {
            cout << "Invalid option. Enter again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (option == 1) {
            cout << "Enter new product name: ";
            getline(cin, p.name);
            cout << "Product name updated.\n";
        }
        else if (option == 2) {
            cout << "Enter new product description: ";
            getline(cin, p.description);
            cout << "Product description updated.\n";
        }
        else if (option == 3) {
            cout << "Enter new total stock quantity: ";
            int newStock;
            while (!(cin >> newStock) || newStock < 0) {
                cout << "Invalid input. Enter non-negative integer: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            p.totalStock = newStock;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Total stock updated.\n";
        }
        else if (option == 4) {
            while (true) {
                cout << "Current price options:\n";
                for (int i = 0; i < p.prices.size(); ++i) {
                    cout << i + 1 << ") " << p.prices[i].quantityLabel << " - " << p.prices[i].price << "\n";
                }
                cout << "1) Add new price option\n";
                cout << "2) Update existing price option\n";
                cout << "3) Delete price option\n";
                cout << "4) Back\n";

                int priceOption;
                cout << "Select option: ";
                while (!(cin >> priceOption) || priceOption < 1 || priceOption > 4) {
                    cout << "Invalid option. Enter again: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (priceOption == 1) {
                    PriceOption newPo;
                    cout << "Enter quantity label (e.g., 250g, 500g): ";
                    getline(cin, newPo.quantityLabel);
                    cout << "Enter price: ";
                    while (!(cin >> newPo.price) || newPo.price < 0) {
                        cout << "Invalid price! Enter again: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    p.prices.push_back(newPo);
                    cout << "New price option added.\n";
                }
                else if (priceOption == 2) {
                    cout << "Enter number of price option to update: ";
                    int updIndex;
                    while (!(cin >> updIndex) || updIndex < 1 || updIndex > p.prices.size()) {
                        cout << "Invalid option. Enter again: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Enter new quantity label: ";
                    getline(cin, p.prices[updIndex - 1].quantityLabel);
                    cout << "Enter new price: ";
                    while (!(cin >> p.prices[updIndex - 1].price) || p.prices[updIndex - 1].price < 0) {
                        cout << "Invalid price! Enter again: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Price option updated.\n";
                }
                else if (priceOption == 3) {
                    cout << "Enter number of price option to delete: ";
                    int delIndex;
                    while (!(cin >> delIndex) || delIndex < 1 || delIndex > p.prices.size()) {
                        cout << "Invalid option. Enter again: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    p.prices.erase(p.prices.begin() + delIndex - 1);
                    cout << "Price option deleted.\n";
                }
                else if (priceOption == 4) {
                    // Back to product update menu
                    break;
                }
                waitForKey();
            }
        }
        else if (option == 5) {
            // Save product changes before exiting
            saveProducts();
            break;
        }
        waitForKey();
    }
}

//================ Customer Check ====================
bool isEmailRegistered(const string& email) {
    for (const Customer& c : customers) {
        if (c.email == email)
            return true;
    }
    return false;
}

//============= Password check ====================
bool isPasswordRegistered(const string& password) {
    for (const Customer& c : customers) {
        if (c.password == password)
            return true;
    }
    return false;
}

//================ Admin Login ====================
bool adminLogin() {
    string password;
    cout << "Enter Admin Password: ";
    cin >> password;

    if (password == "C233122" || password == "C231244" || password == "C241081" || password == "C241084") {
        cout << "\nLogin Successful\n";
        return true;
    }
    else {
        cout << "\nIncorrect Password\n";
        waitForKey();
        return false;
    }
}

//================ Customer Login ====================
bool customerLogin(string& loggedInEmail) {
    string email;
    cout << "\n===== Customer Login =====\n";
    cout << "Enter Email: ";
    cin >> email;

    for (const Customer& c : customers) {
        if (c.email == email) {
            int attempts = 3;
            string password;

            while (attempts--) {
                cout << "Enter Password: ";
                cin >> password;

                if (password == c.password) {
                    cout << "\nLogin Successful!\n";
                    loggedInEmail = email;
                    waitForKey();
                    return true;
                }
                else {
                    cout << "\nIncorrect Password!\n";
                    if (attempts > 0)
                        cout << attempts << " attempt(s) left.\n";
                }
            }

            cout << "\nLogin failed. Returning to Main Menu...\n";
            waitForKey();
            return false;
        }
    }

    cout << "\nEmail not registered. Please register first.\n";
    waitForKey();
    return false;
}

//================ Reset Customer Password ====================
void resetCustomerPassword() {
    string email;
    cout << "\n=== Forgot Password ===\n";
    cout << "Enter your registered Email: ";
    cin >> email;

    for (Customer& c : customers) {
        if (c.email == email) {
            string newPassword;
            cout << "=============================\n";
            cout << "  Enter your new password: ";
            cin >> newPassword;
            cout << "=============================\n";
            c.password = newPassword;

            // Save all customers to file after password reset
            ofstream fout("customer.txt");
            if (fout.is_open()) {
                for (const Customer& cust : customers) {
                    fout << cust.email << " " << cust.password << "\n";
                }
                fout.close();
            }

            cout << "\nPassword reset successfully!\n";
            waitForKey();
            return;
        }
    }

    cout << "\nEmail not found. Please register first.\n";
    waitForKey();
}

void customerMenu(const std::string& email);

//========= Load Customer ==============
void loadCustomers() {
    ifstream fin("customer.txt");
    if (!fin) return;

    string email, password;
    customers.clear();

    while (fin >> email >> password) {
        customers.push_back({ email, password });
    }
    fin.close();
}

//================ Save Customer to File ====================
void saveCustomer(const Customer& c) {
    ofstream fout("customer.txt", ios::app);
    if (fout.is_open()) {
        fout << c.email << " " << c.password << "\n";
        fout.close();
    }
}

//================ Customer Registration ====================
void registerCustomer() {
    loadCustomers();  // Load current customers from file before registration

    string email, password;
    cout << "\n=== Customer Registration ===\n";
    cout << "Enter Email: ";
    cin >> email;

    if (isEmailRegistered(email)) {
        cout << "Email already registered. Try logging in.\n";
        waitForKey();
        return;
    }

    cout << "Create Password: ";
    cin >> password;

    if (isPasswordRegistered(password)) {
        cout << "Password already in use by another customer. Please choose a different password.\n";
        waitForKey();
        return;
    }

    Customer newCustomer = { email, password };
    customers.push_back(newCustomer);

    cout << "Current customers:\n";
    for (const auto& c : customers) {
        cout << c.email << "\n";
    }

    saveCustomer(newCustomer);  // Save new customer to file

    loadCustomers();  // Reload customers from file to keep vector updated

    cout << "=============================\n";
    cout << "\nRegistration Successful!\n";
    cout << "=============================\n";

    int nextStep;
    cout << "\n==============================\n";
    cout << " 1) Login Now\n";
    cout << " 2) Return to Main Menu\n";
    cout << "==============================\n";
    cout << "Select your preferred option:  ";
    cin >> nextStep;

    if (nextStep == 1) {
        string loggedInEmail;
        if (customerLogin(loggedInEmail)) {
            customerMenu(loggedInEmail);
        }
    }
    else if (nextStep == 2) {
        cout << "\nReturning to main menu...\n";
        waitForKey();
    }
    else {
        cout << "\nInvalid choice. Returning to main menu...\n";
        waitForKey();
    }
}

//================ Buy Product ====================
void buyProduct()
{
    if (products.empty())
    {
        cout << "\nNo products available to purchase.\n";
        waitForKey();
        return;
    }

    clearScreen();
    cout << "===================================\n";
    cout << "|        Available Products       |\n";
    cout << "===================================\n";

    for (int i = 0; i < products.size(); ++i)
    {
        cout << i + 1 << ") " << products[i].name << " (Stock: " << products[i].totalStock << ")\n";
    }

    cout << "\nSelect a product number to view details: ";
    int choice;
    cin >> choice;

    if (choice < 1 || choice > products.size())
    {
        cout << "\nInvalid product selection.\n";
        waitForKey();
        return;
    }

    Product& selected = products[choice - 1];

    clearScreen();
    cout << "===================================\n";
    cout << "|       Product Information       |\n";
    cout << "===================================\n";
    cout << " Name       : " << selected.name << "\n";
    cout << " Description: " << selected.description << "\n";
    cout << " Total Stock: " << selected.totalStock << "\n";
    cout << "-----------------------------------\n";
    cout << " Available Quantities and Prices:\n";
    

    for (int i = 0; i < selected.prices.size(); ++i)
    {
        cout << i + 1 << ") " << selected.prices[i].quantityLabel << " - TK " << selected.prices[i].price << "\n";
    }
    cout << "-----------------------------------\n";

    cout << "\nSelect quantity option number: ";
    int qtyOption;
    cin >> qtyOption;

    if (qtyOption < 1 || qtyOption > selected.prices.size())
    {
        cout << "\nInvalid option.\n";
        waitForKey();
        return;
    }

    cout << "Enter number of items to purchase: ";
    int quantity;
    cin >> quantity;

    if (quantity <= 0 || quantity > selected.totalStock)
    {
        cout << "\nInvalid quantity.\n";
        waitForKey();
        return;
    }

    selected.totalStock -= quantity;
    saveProducts();
    double totalPrice = selected.prices[qtyOption - 1].price * quantity;

    // === Show Invoice to Customer ===
    clearScreen();
    cout << "=============================================\n";
    cout << "|               PURCHASE INVOICE            |\n";
    cout << "=============================================\n";
        cout << "| Product Name   : " << selected.name << "\n";
    cout << "| Quantity       : " << quantity << " x " << selected.prices[qtyOption - 1].quantityLabel << "\n";
    cout << "| Price per unit : TK " << fixed << setprecision(2) << selected.prices[qtyOption - 1].price << "\n";
    cout << "---------------------------------------------\n";
    cout << "| Total Price    : TK " << totalPrice << "\n";
    cout << "=============================================\n";


    // Save sale info to sales.txt
    ofstream salesFile("sales.txt", ios::app);
    if (salesFile.is_open())
    {
        salesFile << selected.name << " " << quantity << " " << selected.prices[qtyOption - 1].quantityLabel << " " << totalPrice << "\n";
        salesFile.close();
    }

    cout << "\nPurchase completed successfully.\n";
    waitForKey();
}

//================ Stock Tracking ====================
void stockTracking()
{
    clearScreen();
    cout << "===================================\n";
    cout << "|           Stock Tracking         |\n";
    cout << "===================================\n";

    if (products.empty())
    {
        cout << "No products available.\n";
        waitForKey();
        return;
    }

    for (const auto& p : products)
    {
        cout << "Product: " << p.name << "\n";
        cout << "Total Stock: " << p.totalStock << "\n";
        cout << "-----------------------------------\n";
    }
    waitForKey();
}

//================ Save Sales Report ====================
void saveSaleToReport(const string& productName, int quantity, const string& quantityLabel, double totalPrice)
{
    ofstream reportFile("sales.txt", ios::app);
    if (!reportFile)
    {
        cout << "Error opening sales report file.\n";
        return;
    }

    double unitPrice = (quantity > 0) ? (totalPrice / quantity) : 0;

    reportFile << "============= INVOICE =============\n";
    reportFile << "Product   :  " << productName << "\n";
    reportFile << "Quantity  :  " << quantity << " x " << quantityLabel << "\n";
    reportFile << "Unit Price: Tk " << fixed << setprecision(2) << unitPrice << "\n";
    reportFile << "Total     : Tk " << fixed << setprecision(2) << totalPrice << "\n";
    reportFile << "-----------------------------------\n";

    reportFile.close();
}


//================ View Sales Report ====================
void viewSalesReport()
{
    clearScreen();
    ifstream reportFile("sales.txt");
    if (!reportFile.is_open())
    {
        cout << "No sales report found.\n";
        waitForKey();
        return;
    }

    string line;
    while (getline(reportFile, line))
    {
        cout << line << "\n";
    }

    reportFile.close();
    
    cout<<"----------------------------\n";
    cout<<"1) Exit\n";
    cout<<"----------------------------\n";
    cout<<"Select your preferred option: ";

    int choice;
    cin>>choice;
    while(choice!=0)
    {
        cout<<"Invalid option. Please enter 1 to exit.\n";
        cout<<"Select your preferred option: ";
        cin>>choice;
    }
}

//================ Add Product ====================
void addProduct()
{
    Product newProduct;

    cout << "\n=== Add New Product ===\n";

    cout << "Enter product name: ";
    getline(cin, newProduct.name);

    cout << "Enter total stock quantity: ";
    while (!(cin >> newProduct.totalStock) || newProduct.totalStock < 0)
    {
        cout << "Invalid input. Enter non-negative integer for stock: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter number of quantity-price options: ";
    int numPrices;
    while (!(cin >> numPrices) || numPrices <= 0)
    {
        cout << "Invalid input. Enter positive integer for number of options: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < numPrices; ++i)
    {
        PriceOption po;
        cout << "Enter quantity label (e.g., 250g, 500g, 1L): ";
        getline(cin, po.quantityLabel);

        cout << "Enter price for " << po.quantityLabel << ": ";
        while (!(cin >> po.price) || po.price < 0)
        {
            cout << "Invalid price! Enter again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        newProduct.prices.push_back(po);
    }

    cout << "Enter product description: ";
    getline(cin, newProduct.description);

    products.push_back(newProduct);

    saveProducts();

    cout << "\nProduct added successfully!\n";
    waitForKey();
}

//================== Save Products ====================
void saveProducts(){
    ofstream fout("products.txt");
    if(!fout.is_open()){
        cout<<"Error opening products.txt for saving!\n";
        return;
    }
    for(const auto& p: products){
        fout<<p.name<<"\n";
        fout<<p.totalStock<<"\n";
        fout<<p.prices.size()<<"\n";
        for(const auto& po: p.prices){
            fout<<po.quantityLabel<<" "<<po.price<<"\n";
        }
        fout<<p.description<<"\n";
    }
    fout.close();
}

//================ Delete Product ====================
void deleteProduct()
{
    if (products.empty())
    {
        cout << "\nNo products to delete.\n";
        waitForKey();
        return;
    }

    clearScreen();
    cout << "===================================\n";
    cout << "|         Delete Product           |\n";
    cout << "===================================\n";

    for (int i = 0; i < (int)products.size(); ++i)
    {
        cout << i + 1 << ") " << products[i].name << " (Stock: " << products[i].totalStock << ")\n";
    }

    cout << "\nSelect product number to delete or 0 to cancel: ";
    int choice;
    cin >> choice;

    if (choice == 0)
    {
        cout << "Deletion cancelled.\n";
        waitForKey();
        return;
    }

    if (choice < 1 || choice > products.size())
    {
        cout << "Invalid choice.\n";
        waitForKey();
        return;
    }

    Product& selectedProduct = products[choice - 1];

    cout << "\nYou selected: " << selectedProduct.name << " (Stock: " << selectedProduct.totalStock << ")\n";
    cout << "1) Delete entire product\n2) Delete partial quantity\n3) Cancel\n";

    int delChoice;
    cin >> delChoice;

    if (delChoice == 1)
    {
        cout << "Are you sure you want to delete entire product? (Y/N): ";
        char confirm;
        cin >> confirm;

        if (confirm == 'Y' || confirm == 'y')
        {
            products.erase(products.begin() + (choice - 1));
            saveProducts();
            cout << "Product deleted successfully.\n";
        }
        else
        {
            cout << "Deletion cancelled.\n";
        }
    }
    else if (delChoice == 2)
{
    cout << "Enter quantity to delete: ";
    int qtyToDelete;
    cin >> qtyToDelete;

    if (qtyToDelete <= 0 || qtyToDelete > selectedProduct.totalStock)
    {
        cout << "Invalid quantity.\n";
    }
    else
    {
        selectedProduct.totalStock -= qtyToDelete;
        saveProducts();  // <--- Add this to save updated stock
        cout << "Partial quantity deleted successfully.\n";
    }
}
    else
    {
        cout << "Deletion cancelled.\n";
    }
    waitForKey();
}

//================ Customer Menu ====================
void customerMenu(const string& loggedInEmail)
{
    int choice;

    while (true)
    {
        clearScreen();
        cout << "=====================================\n";
        cout << "|           Customer Menu            |\n";
        cout << "=====================================\n";
        cout << "1) View Product List & Buy\n";
        cout << "2) Logout\n";
        cout << "=====================================\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "⚠️ Invalid input! Please enter a valid number from the menu.\n";
            waitForKey();
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice)
        {
            case 1:
                buyProduct();
                break;
            case 2:
                cout << "Logging out...\n";
                waitForKey();
                return;
            default:
                cout << "⚠️ Invalid choice! Please enter a number from the menu.\n";
                waitForKey();
                break;
        }
    }
}

//=========== View all products for admin =====================
void viewAllProductsForAdmin(){
    while(true) {
        clearScreen();
        if(products.empty()){
            cout << "No products available.\n";
            waitForKey();
            return;
        }

        cout << "=========================================\n";
        cout << "|              All Products             |\n";
        cout << "=========================================\n";
        for(const auto& p : products){
            cout << "Name: " << p.name << "\n";
            cout << "Description: " << p.description << "\n";
            cout << "Stock: " << p.totalStock << "\n";
            cout << "Prices: \n";
            for (const auto& po: p.prices){
                cout << " -" << po.quantityLabel << ": Tk " << fixed << setprecision(2) << po.price << "\n";
            }
            cout << "--------------------------------------\n";
        }

        cout << "\n1) Exit\n";
        cout << "Select your option: ";

        int choice;
        cin >> choice;

        if(choice == 1){
            return;  // Exit the function to go back to admin menu
        } else {
            cout << "Invalid choice. Please try again.\n";
            waitForKey();
        }
    }
}

void loadCustomers();
//================ Main Login Menu ====================
void loginMenu()
{
    loadCustomers();
    int option;

    while (true)
    {
        clearScreen();
        cout << "=====================================\n";
        cout << "|              Main Menu             |\n";
        cout << "=====================================\n";
        cout << "1) Admin Login\n";
        cout << "2) Customer Login\n";
        cout << "3) Customer Registration\n";
        cout << "4) Reset Customer Password\n";
        cout << "5) Exit\n";
        cout << "=====================================\n";
        cout << "Select your preferred option: ";

        if (!(cin >> option))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "⚠️ Invalid input! Please enter a number from the menu.\n";
            waitForKey();
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (option)
        {
            case 1:
                if (adminLogin())
                {
                    int adminChoice;
                    while (true)
                    {
                        adminMenu();
                        if (!(cin >> adminChoice))
                        {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "⚠️ Invalid input! Please enter a valid number.\n";
                            waitForKey();
                            continue;
                        }
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        switch (adminChoice)
                        {
                            case 1: addProduct(); break;
                            case 2: deleteProduct(); break;
                            case 3: updateProduct(); break;
                            case 4: stockTracking(); break;
                            case 5: viewSalesReport(); break;
                            case 6: viewAllProductsForAdmin(); break;
                            case 7:
                                cout << "Logging out from Admin...\n";
                                waitForKey();
                                goto endAdmin;
                            default:
                                cout << "⚠️ Invalid choice! Please enter a number from the menu.\n";
                                waitForKey();
                                break;
                        }
                    }
                }
            endAdmin:
                break;

            case 2:
            {
                string loggedInEmail;
                if (customerLogin(loggedInEmail))
                {
                    customerMenu(loggedInEmail);
                }
                break;
            }

            case 3:
                registerCustomer();
                break;

            case 4:
                resetCustomerPassword();
                break;

            case 5:
                cout << "Exiting program...\n";
                return;

            default:
                cout << "⚠️ Invalid choice! Please enter a number from the menu.\n";
                waitForKey();
                break;
        }
    }
}

//=========== Load Products ==============
void loadProducts() {
    ifstream fin("products.txt");
    if (!fin) {
        // File doesn't exist or cannot be opened
        return;
    }

    products.clear();

    while (true) {
        Product p;
        if (!getline(fin, p.name) || p.name.empty()) break; // EOF or empty line

        fin >> p.totalStock;

        int numPrices;
        fin >> numPrices;
        fin.ignore(numeric_limits<streamsize>::max(), '\n'); // consume leftover newline

        p.prices.clear();
        for (int i = 0; i < numPrices; ++i) {
            string line;
            if (!getline(fin, line)) break;
            istringstream iss(line);
            PriceOption po;
            iss >> po.quantityLabel >> po.price;
            p.prices.push_back(po);
        }

        getline(fin, p.description);

        products.push_back(p);
    }

    fin.close();
}




int main() {
    ShowTeamName();


    loadProducts();
    loadCustomers();

    loginMenu();
    viewAllProductsForAdmin();
    updateProduct();

    return 0;
}
