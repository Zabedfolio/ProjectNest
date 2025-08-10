
# Inventory Management System

The Inventory Management System is a console-based application developed in C++ as part of our 2nd semester course project.
It provides a simple yet effective way to manage products, stock levels, pricing, and sales records for small shops or businesses.

The system is designed for two primary user types:
	
    •	Admins can add new products, edit details, set different quantity–price options, update stock, delete products, and view sales reports. They can also track inventory levels in real time and review past transactions from stored sales files.
	•	Customers can register and log in to their accounts, browse available products, choose quantities, make purchases, and receive on-screen invoices. All purchases are recorded automatically in the sales file for tracking.

This project aims to simulate a basic real-world inventory management workflow while being simple enough for beginners to understand.
It focuses on menu-driven program design, file handling for data persistence, and dynamic storage using vectors.

We built this project as a team of four (3 Bits Dynamics) over the course of more than a month, making it our first fully completed C++ application.
It is well-suited for anyone learning programming fundamentals, file operations, and how to build structured applications in C++.


## Features

#### Project Introduction Screen
Upon launching the Inventory Management System, users are presented with the Project Introduction Screen, which serves as a formal welcome and acknowledgment of the development team. This screen features:
	
    •	The Team Name — 3 Bits Dynamics — prominently displayed to establish the project identity.
	•	A detailed list of Team Members, including their full names and unique identification numbers, crediting each contributor’s role.
	•	A prompt to press Enter to continue, ensuring users consciously proceed after reviewing the team information.
This introductory interface sets a professional tone for the application, providing transparency about the creators and fostering a sense of collaboration and accountability from the outset.

```cpp
========================================
|     3 Bits Dynamics                  |
========================================
|  Members:                            |
|  1. Mahir Jamal  - C231244           |
|  2. Zabed Mahmud - C233122           |
|  2. Sohag        - C241081           |
|  2. Dil Dihan.   - C241084           |
========================================
Press Enter to continue...
```


#### Main Menu Interface
The Main Menu Interface serves as the central navigation hub for the Inventory Management System. It presents users with clearly organized options that cater to both administrative staff and customers, ensuring easy access to all key functionalities:
	
    •	Admin Login: Secure entry point for administrators to manage products, monitor stock, and review sales reports. Access is protected by a password authentication system.
	•	Customer Login: Allows registered customers to sign in using their email and password, enabling them to browse products and make purchases.
	•	Customer Registration: Facilitates new user account creation with email and password, ensuring unique credentials and secure access.
	•	Reset Customer Password: Provides a mechanism for customers to recover access by resetting their password using their registered email.
	•	Exit: Option to safely terminate the application.

This interface incorporates robust input validation to handle incorrect or invalid entries gracefully, enhancing user experience and preventing unexpected program termination.

```cpp
=====================================
|              Main Menu             |
=====================================
1) Admin Login
2) Customer Login
3) Customer Registration
4) Reset Customer Password
5) Exit
=====================================
Select your preferred option: 
```

#### Admin Login and Authentication
The Admin Login feature restricts access to sensitive management functionalities, ensuring only authorized personnel can perform administrative tasks. Key characteristics include:

	•	Password-Protected Access: Admins must enter a valid password to gain access. Multiple predefined passwords corresponding to team members provide flexibility.
	•	Security Measures: Incorrect password entries prompt clear error messages and prevent access, protecting the system from unauthorized use.
	•	Successful Login Feedback: Upon correct authentication, admins receive confirmation, allowing them to proceed to the Admin Menu.
	•	User Experience: The system allows multiple attempts for entering the password, balancing security with usability.

This feature is essential for maintaining data integrity and operational security within the Inventory Management System.


#### Admin Menu
The Admin Menu provides a comprehensive interface for administrators to efficiently manage the inventory and sales operations. Key functionalities available include:

	•	Add Product: Input new products with details such as name, description, stock quantity, and multiple price options based on quantity.
	•	Delete Product: Remove an entire product from inventory or reduce its stock partially, with confirmation prompts to prevent accidental deletions.
	•	Update Product: Modify product information including name, description, stock, and price options, allowing flexible management of existing inventory.
	•	Stock Tracking: View a summary of current stock levels for all products, assisting in inventory monitoring and decision-making.
	•	View Sales Report: Access detailed sales history from stored files to analyze product performance and revenue.
	•	View All Products: Display a list of all products with comprehensive details, supporting easy review and auditing.
	•	Exit: Log out securely from the admin account, returning to the main menu.

The menu includes input validation and user-friendly prompts, ensuring smooth navigation and minimizing errors during inventory management.

```cpp
=================================
|          Admin Menu           |
=================================
 1) Add Product
 2) Delete Product
 3) Update Product
 4) Stock Tracking
 5) View Sales Report
 6) View All Products
 7) Exit
=================================
Select your preferred option:  
```

#### Customer Registration
The Customer Registration module allows new users to create personalized accounts within the system, enabling access to purchase products and track orders. Features include:

	•	Unique Email Validation: Ensures that each registered email is unique, preventing duplicate accounts.
	•	Password Creation with Validation: Users must create a password that is not already in use by another customer, enhancing account security.
	•	Data Persistence: New customer details are saved to a persistent file (customer.txt), ensuring registration is retained across sessions.
	•	Post-Registration Options: Upon successful registration, customers can immediately choose to log in or return to the main menu, providing a seamless user experience.
	•	Input Error Handling: The system gracefully handles invalid inputs and provides informative feedback to guide users through the registration process.

This feature is vital for onboarding new customers and maintaining secure, individualized access to the system.

#### Customer Login and Authentication
The Customer Login functionality enables registered users to securely access their accounts to browse and purchase products. Its key elements include:

	•	Email Verification: Validates that the entered email corresponds to a registered customer account.
	•	Password Authentication: Requires customers to enter the correct password with up to three attempts allowed, ensuring account security.
	•	Error Handling: Provides clear feedback on incorrect emails or passwords, with prompts to retry or register if necessary.
	•	Successful Login Feedback: Confirms successful authentication before granting access to the Customer Menu.
	•	Security Considerations: Limits password attempts to prevent unauthorized access, enhancing overall system safety.

This feature ensures that only legitimate customers can perform purchases and access their account-specific functionalities.

#### Customer Menu
The Customer Menu offers an intuitive interface for logged-in customers to interact with the inventory system, focusing on ease of browsing and purchasing. It includes:

	•	View Product List & Buy: Customers can browse the list of available products, view detailed information, and select items to purchase.
	•	Logout: Securely exit the customer session, returning to the main menu.

The menu incorporates input validation to ensure users make valid selections and provides clear prompts to enhance user experience. It guides customers through the purchasing process smoothly while maintaining session security.

```cpp
=====================================
|           Customer Menu            |
=====================================
1) View Product List & Buy
2) Logout
=====================================
Enter your choice:  
```

#### Product Browsing and Purchase
This feature allows customers to explore available products and complete purchases with detailed options:

	•	Product Listing: Displays all available products with current stock levels.
	•	Product Details: Shows comprehensive information including name, description, stock quantity, and all price options with quantity labels.
	•	Quantity and Price Selection: Customers select the desired product quantity and corresponding price option before purchasing.
	•	Stock Validation: Ensures requested purchase quantities do not exceed available stock, preventing overselling.
	•	Purchase Confirmation & Invoice: After a successful purchase, the system generates a clear invoice displaying product details, quantity, unit price, and total cost.
	•	Sales Recording: Purchases are logged into a sales report file (sales.txt) to maintain transaction history for administrative review.

This process ensures a smooth, transparent buying experience while maintaining accurate inventory and sales records.

```cpp
===================================
|        Available Products       |
===================================
1) Ghee (Stock: 27)

Select a product number to view details: 
```

#### Stock Tracking
Stock Tracking

The Stock Tracking functionality provides administrators with an overview of current inventory levels across all products. Key aspects include:

	•	Comprehensive Stock Summary: Lists all products along with their respective total stock quantities, enabling quick assessment of inventory status.
	•	User-Friendly Display: Organized and clear presentation aids in monitoring stock levels efficiently.
	•	Decision Support: Helps identify low-stock or out-of-stock items, facilitating timely restocking and inventory management.
	•	Simple Navigation: Accessible via the Admin Menu with prompts to return easily after review.

This feature is essential for maintaining an up-to-date view of product availability and ensuring smooth inventory operations.

```cpp
===================================
|           Stock Tracking         |
===================================
Product: Ghee
Total Stock: 27
-----------------------------------

Press Enter to continue...
```

#### Sales Report Viewing
The Sales Report Viewing feature enables administrators to access detailed records of all completed sales transactions. Its main functions include:

	•	File-Based Sales Log: Reads sales data from a persistent file (sales.txt), ensuring all sales history is maintained across sessions.
	•	Comprehensive Transaction Display: Shows detailed invoices including product names, quantities sold, unit prices, and total amounts for each transaction.
	•	User-Friendly Interface: Presents sales data clearly with proper formatting and separators for easy reading and analysis.
	•	Exit Option: Allows administrators to exit the sales report view and return to the Admin Menu smoothly.
	•	Input Validation: Ensures users can only select valid options for exiting the report screen.

This feature supports informed decision-making by providing transparent and accessible sales performance data.

```cpp
Ghee 1 250g 350
Ghee 1 500 700
Ghee 1 250g 300
Ghee 1 250g 300
----------------------------
1) Exit
----------------------------
Select your preferred option: 
```

#### Add Product
The Add Product feature empowers administrators to expand the inventory by adding new products with detailed specifications. Key functionalities include:

	•	Product Details Input: Admins can enter the product name, detailed description, and total stock quantity.
	•	Multiple Pricing Options: Supports adding multiple price points based on quantity labels (e.g., 250g, 500g), allowing flexible pricing schemes.
	•	Input Validation: Ensures entered stock quantities and prices are valid non-negative numbers to maintain data integrity.
	•	Persistent Storage: Newly added products are saved to the products.txt file, making the data persistent across program executions.
	•	User Feedback: Confirms successful addition of products and provides prompts to continue management tasks.

This feature is crucial for keeping the inventory up-to-date with diverse product offerings.

```cpp
=== Add New Product ===
Enter product name: Ghee
Enter total stock quantity: 15
Enter number of quantity-price options: 1
Enter quantity label (e.g., 250g, 500g, 1L): 500g
Enter price for 500g: 700
Enter product description: Ghee

Product added successfully!
```

#### Update Product
The Update Product feature allows administrators to modify existing product information to keep the inventory accurate and relevant. Main capabilities include:

	•	Product Selection: Admins choose which product to update from the current inventory list.
	•	Field Updates: Ability to change product name, description, total stock quantity, and price options with multiple quantity-price pairs.
	•	Price Options Management: Admins can add new price options, update existing ones, or delete price options for more flexible pricing control.
	•	Input Validation: Ensures valid entries for quantities and prices to maintain data consistency.
	•	Data Persistence: Changes are saved to the products.txt file, ensuring updates are retained between sessions.
	•	User-Friendly Navigation: Menu-driven interface allows easy navigation between different update tasks and exit back to the Admin Menu.

This feature supports effective inventory management by allowing dynamic updates reflecting current product details and market changes.

```cpp
Updating Product: Ghee
1) Update Name
2) Update Description
3) Update Total Stock
4) Update Prices
5) Back to Admin Menu
Select option: 
```

#### Delete Product
The Delete Product functionality provides administrators with control to remove products from the inventory or reduce their stock quantities as needed. Features include:

	•	Product Selection: Displays a list of all products, allowing admins to choose which product to delete or modify.
	•	Full or Partial Deletion:
	•	Entire Product Deletion: Remove a product completely from the inventory after confirmation.
	•	Partial Quantity Deletion: Reduce the stock quantity of a product by a specified amount, useful for correcting inventory counts.
	•	Input Validation: Prevents invalid deletion requests, such as deleting more quantity than available or invalid choices.
	•	Persistent Updates: Saves changes immediately to the products.txt file to ensure inventory data is current.
	•	User Confirmation: Requests confirmation before permanently deleting products to avoid accidental removals.
	•	Clear Feedback: Informs the administrator about the success or cancellation of deletion operations.

This feature is vital for maintaining an accurate and clean product database.

```cpp
===================================
|         Delete Product           |
===================================
1) Ghee (Stock: 27)
2) Ghee (Stock: 15)

Select product number to delete or 0 to cancel: 
```

## Installation

Follow these steps to compile and run the Inventory Management System on your local machine:

Prerequisites
	•	C++ Compiler: Make sure you have a C++ compiler installed, such as g++ (part of GCC) or any IDE like Code::Blocks, Visual Studio, or CLion.
	•	Operating System: The program is cross-platform and can run on Windows, macOS, and Linux terminals or command prompts.

Steps to Compile and Run

Using Command Line / Terminal
	
	1.	Open your terminal or command prompt.
	2.	Navigate to the project directory where the source code file (main.cpp or your project file) is located, e.g.:

```bash
  cd path/to/your/project/folder
```
3.	Compile the code using g++:
    ```bash
    g++ -o InventoryManagementSystem main.cpp
    ```


	•	Replace main.cpp with your actual source filename(s) if different.

	•	This will create an executable file named InventoryManagementSystem (or InventoryManagementSystem.exe on Windows).

	4.	Run the executable:

	•	On macOS/Linux:
	```bash
    ./InventoryManagementSystem
    ```
		
•	On Windows:
    ```bash
    InventoryManagementSystem.exe
    ```
Using an IDE
	•	Open the project folder or source file in your preferred C++ IDE.
	•	Build/compile the project using the IDE’s build tools.
	•	Run the compiled program from within the IDE.

Data Files
	•	The program reads from and writes to products.txt and customer.txt for inventory and customer data.
	•	Make sure these files are in the same directory as the executable. If they don’t exist, the program will create them when you add products or register customers.

Notes
	
	•	The program runs in the terminal/console and uses keyboard input to navigate menus.
	•	Use number inputs to select options in menus.
	•	Screens clear automatically for better user experience (may not work perfectly on all terminals).
## Usage/Examples

Once you have compiled and run the program, follow these steps to navigate and use the Inventory Management System:

1. Welcome Screen
	
    •	The program begins with a Welcome Box displaying the project name (Inventory Management System), your team name (3 Bits Dynamics), and the team members.
	•	Press Enter to proceed.

2. Main Menu
	
    •	You will be presented with options:
   	1.	Admin Login – for managing products, viewing reports, and handling inventory.
	2.	Customer Login – for purchasing products and generating invoices.
	3.	Customer Registration – for new customers to create an account.
	4.	Exit – to close the program.
	•	Enter the corresponding number to select an option.

3. Admin Menu
	
    •	After successful login, admins can:
	
    •	View All Products
	
    •	Add New Product
	
    •	Update Existing Product
	
    •	Delete Product or Reduce Stock
	
    •	View Sales Report
	
    •	Logout

4. Customer Menu

	•	After logging in as a customer, you can:
	
    •	View Products
	
    •	Purchase Products (select quantity and generate invoice)
	
    •	View Purchase History
	
    •	Logout

5. Invoice Generation
	
    •	Upon completing a purchase, the system generates a detailed Invoice showing:
	
    •	Product name
	
    •	Quantity purchased
	
    •	Unit price
	
    •	Total cost
	
    •	The invoice is displayed in the console and stored for record-keeping.

6. Navigation Tips
	
    •	Numbers: Enter the menu option number to select an action.
	
    •	Back / Exit: Many menus include an option to return to the previous menu or logout.
	
    •	Validation: If you enter an invalid option, the program will prompt you to try again.

⸻


