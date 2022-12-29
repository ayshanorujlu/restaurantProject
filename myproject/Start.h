#pragma once
#include"Classes.h"
#include<conio.h>

#pragma region mySetColor
void mysetcolor(int fg, int bg) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, fg | (bg << 4));
}
#pragma endregion

void Start() {
	Kitchen kitchen;
	Meals meals(" ",1);
	Order order(" ",1,1);

	Ingredients tomato("tomato", 50, 0.9, 18);
	Ingredients lettuce("lettuce", 21, 0.2, 15);
	Ingredients sezarsauce("sezar-sauce", 20, 4.5, 44);
	Ingredients chicken("chicken", 9, 5, 177);
	Ingredients hollandcheese("holland-cheese", 10, 2.4, 3.71);
	Ingredients drybread("dry bread", 30, 0.3, 82);
	Ingredients meat("meat", 15, 16, 1.43);
	Ingredients burgerbread("burger-bread", 30, 1.2, 140);
	Ingredients pasta1("pasta", 50, 1.2, 131);
	Ingredients bolognesesauce("bolognese-sauce", 20, 5.2, 259);
	Ingredients pizzadough("pizza dough", 25, 2.6, 130);
	Ingredients sausage("sausage", 50, 7.8, 346);

	Ingredients tomatosezar(5);
	Ingredients lettucesezar(7);
	Ingredients sezarsauce1(1);
	Ingredients chickensezar(4);
	Ingredients hollandcheesesezar(4);
	Ingredients drybreadsezar(10);
	Ingredients tomatoburger(1);
	Ingredients meatburger(1);
	Ingredients lettuceburger(2);
	Ingredients hollandcheeseburger(1);
	Ingredients burgerbreadburger(1);
	Ingredients pasta2(1);
	Ingredients hollandcheesepasta(3);
	Ingredients bolognesesaucepasta(1);
	Ingredients tomatopizza(3);
	Ingredients pizzadough1(1);
	Ingredients sausagepizza(10);
	Ingredients hollandcheesepizza(4);

	SezarSalad sezar("Sezar Salad", 16.00);
	Burger burger("Chicken Burger", 15.00);
	BolognesePasta pasta("Bolognese Pasta", 12.00);
	PepperoniPizza pizza("Pepperoni Pizza", 12.00);

	kitchen.AddMeal(sezar);
	kitchen.AddMeal(burger);
	kitchen.AddMeal(pasta);
	kitchen.AddMeal(pizza);

	sezar.AddIngredient(lettuce);
	sezar.AddIngredient(sezarsauce);
	sezar.AddIngredient(tomato);
	sezar.AddIngredient(chicken);
	sezar.AddIngredient(hollandcheese);
	sezar.AddIngredient(drybread);

	burger.AddIngredient(meat);
	burger.AddIngredient(tomato);
	burger.AddIngredient(lettuce);
	burger.AddIngredient(hollandcheese);
	burger.AddIngredient(burgerbread);

	pasta.AddIngredient(pasta1);
	pasta.AddIngredient(hollandcheese);
	pasta.AddIngredient(bolognesesauce);

	pizza.AddIngredient(tomato);
	pizza.AddIngredient(pizzadough);
	pizza.AddIngredient(sausage);
	pizza.AddIngredient(hollandcheese);

	Stock stock;
	Ingredients tomatoStock("tomato", 50);
	Ingredients lettuceStock("lettuce", 21);
	Ingredients sezarsauceStock("sezar-sauce", 50);
	Ingredients chickenStock("chicken", 9);
	Ingredients hollandcheeseStock("holland-cheese", 10);
	Ingredients drybreadStock("dry bread", 30);
	Ingredients meatStock("meat", 15);
	Ingredients burgerbreadStock("burger-bread", 30);
	Ingredients pastaStock("pasta", 20);
	Ingredients bolognesesauceStock("bolognese-sauce", 12);
	Ingredients pizzadoughStock("pizza dough", 25);
	Ingredients sausageStock("sausage", 50);

	stock.AddProduct(tomatoStock);
	stock.AddProduct(lettuceStock);
	stock.AddProduct(sezarsauceStock);
	stock.AddProduct(chickenStock);
	stock.AddProduct(hollandcheeseStock);
	stock.AddProduct(drybreadStock);
	stock.AddProduct(meatStock);
	stock.AddProduct(burgerbreadStock);
	stock.AddProduct(pastaStock);
	stock.AddProduct(bolognesesauceStock);
	stock.AddProduct(pizzadoughStock);
	stock.AddProduct(sausageStock);

	//FileHelper::Save(stock);
	Stock obj = FileHelper::Read();

#pragma region START
#pragma region RestaurantName
	mysetcolor(13, 0);
	cout << " ______  ______  ____    __       ______  __  __  ____    ______      " << endl;
	cout << "/\\__  _\\/\\  _  \\/\\  _`\\ /\\ \\     /\\  _  \\/\\ \\/\\ \\/\\  _`\\ /\\  _  \\     " << endl;
	cout << "\\/_/\\ \\/\\ \\ \\L\\ \\ \\ \\L\\_\\ \\ \\    \\ \\ \\L\\ \\ \\ \\ \\ \\ \\ \\L\\ \\ \\ \\L\\ \\    " << endl;
	cout << "   \\ \\ \\ \\ \\  __ \\ \\ \\L_L\\ \\ \\  __\\ \\  __ \\ \\ \\ \\ \\ \\ ,  /\\ \\__ \\ \\   " << endl;
	cout << "    \\ \\ \\ \\ \\ \\/\\ \\ \\ \\/, \\ \\ \\L\\ \\\\ \\ \\/\\ \\ \\ \\_\\ \\ \\ \\\\ \\\\ \\ \\/\\ \\  " << endl;
	cout << "     \\ \\_\\ \\ \\_\\ \\_\\ \\____/\\ \\____/ \\ \\_\\ \\_\\ \\_____\\ \\_\\ \\_\\ \\_\\ \\_\\ " << endl;
	cout << "      \\/_/  \\/_/\\/_/\\/___/  \\/___/   \\/_/\\/_/\\/_____/\\/_/\\/ /\\/_/\\/_/ " << endl;
	cout << "                                                                      " << endl;
	cout << "                                                                      " << endl;

	cout << " ________  _______   ________  _________  ________  ___  ___  ________  ________  ________   _________   " << endl;
	cout << "|\\   __  \\|\\  ___ \\ |\\   ____\\|\\___   ___\\\\   __  \\|\\  \\|\\  \\|\\   __  \\|\\   __  \\|\\   ___  \\|\\___   ___\\ " << endl;
	cout << "\\ \\  \\|\\  \\ \\   __/|\\ \\  \\___|\\|___ \\  \\_\\ \\  \\|\\  \\ \\  \\\\\\  \\ \\  \\|\\  \\ \\  \\|\\  \\ \\  \\\\ \\  \\|___ \\  \\_| " << endl;
	cout << " \\ \\   _  _\\ \\  \\_|/_\\ \\_____  \\   \\ \\  \\ \\ \\   __  \\ \\  \\\\\\  \\ \\   _  _\\ \\   __  \\ \\  \\\\ \\  \\   \\ \\  \\  " << endl;
	cout << "  \\ \\  \\\\  \\\\ \\  \\_|\\ \\|____|\\  \\   \\ \\  \\ \\ \\  \\ \\  \\ \\  \\\\\\  \\ \\  \\\\  \\\\ \\  \\ \\  \\ \\  \\\\ \\  \\   \\ \\  \\ " << endl;
	cout << "   \\ \\__\\\\ _\\\\ \\_______\\____\\_\\  \\   \\ \\__\\ \\ \\__\\ \\__\\ \\_______\\ \\__\\\\ _\\\\ \\__\\ \\__\\ \\__\\\\ \\__\\   \\ \\__\\ " << endl;
	cout << "    \\|__|\\|__|\\|_______|\\_________\\   \\|__|  \\|__|\\|__|\\|_______|\\|__|\\|__|\\|__|\\|__|\\|__| \\|__|    \\|__|" << endl;
	cout << "                       \\|_________|                                                                      " << endl;
	cout << "                                                                                                         " << endl;
	cout << "                                                                                                          " << endl;
	mysetcolor(7, 0);
#pragma endregion

	while (true)
	{
		cout << "Admin-----[1]" << endl;
		cout << "User------[2]" << endl;
		cout << "Exit------[3]" << endl;
		cout << endl << endl;
		int choice = 0;
		cout << "Enter your choice :";
		cin >> choice;
		if (choice == 1)
		{
			cout << "LOGIN:" << endl;
			while (true)
			{
				cin.ignore();
				cin.clear();
				cout << "Enter username:";
				string username;
				getline(cin, username);

				cout << "Enter Password: ";
				string password;
				getline(cin, password);
				if (username == "ayshan.ly" && password == "12345") {
					cout << "------------WELCOME ADMIN---------" << endl;
					while (true)
					{
						cout << "Kitchen[1]" << endl;
						cout << "Stock--[2]" << endl;
						int choice = 0;
						cin >> choice;
						if (choice == 1)//Kitchen
						{
							while (true)
							{
								cout << "--------Kitchen--------" << endl;
								cout << "Show All Meals-------------[1]" << endl;
								cout << "Add meal-------------------[2]" << endl;
								cout << "Update meal----------------[3]" << endl;
								cout << "Enter your choice:" << endl;
								int select = 0;
								cin >> select;
								if (select == 1) {
									kitchen.ShowMeals();
								}
								else if (select == 2)
								{
									cin.ignore();
									cin.clear();
									string newname;
									cout << "Enter name : ";
									getline(cin, newname);
									double price;
									cout << "Enter price : ";
									cin >> price;
									Meals newmeal(newname, price);
									kitchen.AddMeal(newmeal);
								}
								else if (select == 3)
								{
									kitchen.ShowMeals();
									cout << "Enter meal id (which you want to update)  : ";
									int id = 0;
									cin >> id;
									cout << endl;
									cout << "Name ----- [1]" << endl;
									cout << "Price ---- [2]" << endl;
									cout << "What do you want to change?";
									int change = 0;
									cin >> change;
									if (change == 1) {
										cin.ignore();
										cin.clear();
										string newname;
										cout << "Enter new name : ";
										getline(cin, newname);
										kitchen.UpdateName(id, newname);
									}
									else if (change == 2) {
										int newprice;
										cin >> newprice;
										kitchen.UpdatePrice(id, newprice);
									}
								}
								else {
									cout << "INVALID ENTRY!" << endl;
								}
							}
						}
						else if (choice == 2) //Stock
						{
							cout << "-----STOCK-----" << endl;
							obj.Show();
						}
					}
				}
				else {
					cout << "INVALID ENTRY!!" << endl << "TRY AGAIN!!" << endl;
					break;
				}
			}
		}
		else if (choice == 2) {

			mysetcolor(4, 0);
			cout << "               -------------WELCOME TO OUR RESTAURANT-------------" << endl;

			cout << "                                     ,%;," << endl;
			cout << "                                     ,%%," << endl;
			cout << "                        ______________)(______________" << endl;
			cout << "                       /             (__)             \\" << endl;
			cout << "                      /________________________________\\" << endl;
			cout << "                      [________________________________]" << endl;
			cout << "                         \\ \\  / /           \\ \\  / /" << endl;
			cout << "                          \\ \\/ /             \\ \\/ /" << endl;
			cout << "                          _\\/ /_______________\\ \\/_" << endl;
			cout << "                         [_/o/_________________\\o\\_]" << endl;
			cout << "                          / /\\ \\              / /\\ \\" << endl;
			cout << "                         /_/  \\_\\            /_/  \\_\\" << endl;
			mysetcolor(7, 0);

			cout << "1) ";
			sezar.Show();
			cout << endl << "2) ";
			burger.Show();
			cout << endl << "3) ";
			pasta.Show();
			cout << endl << "4) ";
			pizza.Show();
			cout << "Please,order!" << endl;
			int choice = 0;
			cin >> choice;
			if (choice == 1)//sezar
			{
				int option = 0;
				cout << "Order---------------[1]" << endl;
				cout << "Show Ingredients----[2]" << endl;
				cout << "Enter your choice:" << endl;
				cin >> option;
				if (option == 1)//order
				{
					int count = 0;
					cout << "Enter count : ";
					cin >> count;
					auto myarr = new Ingredients[6]{ lettuce, sezarsauce, tomato, chicken, hollandcheese, drybread };
					bool isokay = true;
					for (size_t i = 0; i < 6; i++)
					{
						if (stock.ShowAvailability(myarr[i])) {
							isokay = true;
						}
						else {
							isokay = false;
							break;
						}
					}
					if (isokay) {
						order.SetName(sezar.GetName());
						order.SetCount(count);			
						order.SetPrice(count * sezar.GetPrice());
						

						cout << "Total Amount is : " << order.GetPrice() << endl;
					}
					else {
						auto myarr = new Ingredients[6]{ lettuce, sezarsauce, tomato, chicken, hollandcheese, drybread };
						for (size_t i = 0; i < 6; i++)
						{
							if (!obj.ShowAvailability(myarr[i])) {
								mysetcolor(4, 0);
								cout << "You should not buy this meal, because " << myarr[i].GetName() << " is out of stock" << endl;
								mysetcolor(7, 0);
							}
						}
						continue;
					}
				}

				else if (option == 2)
				{
					sezar.ShowIngredients();
					cout << "Total calory you will gain : " << sezar.CalculateCalories();
					cout << endl << endl;
				}

			}
			else if (choice == 2)//burger
			{
				int option = 0;
				cout << "Order---------------[1]" << endl;
				cout << "Show Ingredients----[2]" << endl;
				cout << "Enter your choice:" << endl;
				cin >> option;
				if (option == 1)//order
				{
					int count = 0;
					cout << "Enter count : ";
					cin >> count;
					auto myarr = new Ingredients[5]{ meat, lettuce, tomato, burgerbread, hollandcheese };

					bool isokay = true;
					for (size_t i = 0; i < 5; i++)
					{
						if (obj.ShowAvailability(myarr[i])) {
							isokay = true;
						}
						else {
							isokay = false;
							break;
						}
					}
					if (isokay) {
						try {
							order.SetName(burger.GetName());
						}
						catch (const Exception& ex) {
							ex.PrintMessage();
							return;
						}

						try {
							order.SetCount(count);
						}
						catch (const Exception& ex) {
							ex.PrintMessage();
							return;
						}

						try {
							order.SetPrice(count * burger.GetPrice());
						}
						catch (const Exception& ex) {
							ex.PrintMessage();
							return;
						}

						cout << "Total Amount is : " << order.GetPrice() << endl;
					}
					else {
						auto myarr = new Ingredients[5]{ meat, lettuce, tomato, burgerbread, hollandcheese };
						for (size_t i = 0; i < 5; i++)
						{
							if (!obj.ShowAvailability(myarr[i])) {
								mysetcolor(4, 0);
								cout << "You should not buy this meal, because " << myarr[i].GetName() << " is out of stock" << endl;
								mysetcolor(7, 0);
							}
						}
						continue;
					}
				}
				else if (option == 2)//showingredient
				{
					burger.ShowIngredients();
					cout << "Total calory you will gain : " << burger.CalculateCalories();
					cout << endl << endl;
				}
			}

			else if (choice == 3)//pasta
			{
				int option = 0;
				cout << "Order---------------[1]" << endl;
				cout << "Show Ingredients----[2]" << endl;
				cout << "Enter your choice:" << endl;
				cin >> option;
				if (option == 1)//order
				{
					int count = 0;
					cout << "Enter count : ";
					cin >> count;
					auto myarr = new Ingredients[3]{ bolognesesauce,pasta1, hollandcheese };

					bool isokay = true;
					for (size_t i = 0; i < 3; i++)
					{
						if (obj.ShowAvailability(myarr[i])) {
							isokay = true;
						}
						else {
							isokay = false;
							break;
						}
					}
					if (isokay) {
						try {
							order.SetName(pasta.GetName());
						}
						catch (const Exception& ex) {
							ex.PrintMessage();
							return;
						}

						try {
							order.SetCount(count);
						}
						catch (const Exception& ex) {
							ex.PrintMessage();
							return;
						}

						try {
							order.SetPrice(count * pasta.GetPrice());
						}
						catch (const Exception& ex) {
							ex.PrintMessage();
							return;
						}

						cout << "Total Amount is : " << order.GetPrice() << endl;
					}
					else {
						auto myarr = new Ingredients[3]{ bolognesesauce,pasta1, hollandcheese };
						for (size_t i = 0; i < 3; i++)
						{
							if (!obj.ShowAvailability(myarr[i])) {
								mysetcolor(4, 0);
								cout << "You should not buy this meal, because " << myarr[i].GetName() << " is out of stock" << endl;
								mysetcolor(7, 0);
							}
						}
						continue;
					}
				}
				else if (option == 2)//showingredient
				{
					pasta.ShowIngredients();
					cout << "Total calory you will gain : " << pasta.CalculateCalories();
					cout << endl << endl;
				}
			}
			else if (choice == 4)//pizza
			{
				int option = 0;
				cout << "Order---------------[1]" << endl;
				cout << "Show Ingredients----[2]" << endl;
				cout << "Enter your choice:" << endl;
				cin >> option;
				if (option == 1)//order
				{
					int count = 0;
					cout << "Enter count : ";
					cin >> count;
					auto myarr = new Ingredients[4]{ pizzadough,tomato, sausage,hollandcheese };

					bool isokay = true;
					for (size_t i = 0; i < 4; i++)
					{
						if (obj.ShowAvailability(myarr[i])) {
							isokay = true;
						}
						else {
							isokay = false;
							break;
						}
					}
					if (isokay) {
						try {
							order.SetName(pizza.GetName());
						}
						catch (const Exception& ex) {
							ex.PrintMessage();
							return;
						}

						try {
							order.SetCount(count);
						}
						catch (const Exception& ex) {
							ex.PrintMessage();
							return;
						}

						try {
							order.SetPrice(count * pizza.GetPrice());
						}
						catch (const Exception& ex) {
							ex.PrintMessage();
							return;
						}

						cout << "Total Amount is : " << order.GetPrice() << endl;
					}
					else {
						auto myarr = new Ingredients[4]{ pizzadough,tomato, sausage,hollandcheese };
						for (size_t i = 0; i < 4; i++)
						{
							if (!obj.ShowAvailability(myarr[i])) {
								mysetcolor(4, 0);
								cout << "You should not buy this meal, because " << myarr[i].GetName() << " is out of stock" << endl;
								mysetcolor(7, 0);
							}
						}
						continue;
					}
				}
				else if (option == 2)//showingredient
				{
					pizza.ShowIngredients();
					cout << "Total calory you will gain : " << pizza.CalculateCalories();
					cout << endl << endl;
				}
			}
		}

#pragma endregion
	}

#pragma endregion



}