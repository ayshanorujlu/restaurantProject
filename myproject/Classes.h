#pragma once
#include<iostream>
#include <assert.h> 
#include<string>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include <Windows.h>
#include<stdio.h>
#include<fstream>
using namespace std;

#pragma region Exception
class Exception {
protected:
	string text;
	string source;
	int line;
	string date;
public:
	Exception(const string& text, const string& source
		, const int& line, const string& date)
		:text(text), source(source), line(line), date(date)
	{
	}
#pragma region Setters
	void SetText(const string& text) {
		this->text = text;
	}
	void SetSource(const string& source) {
		this->source = source;
	}
	void SetLine(const int& line) {
		this->line = line;
	}
	void SetDate(const string& date) {
		this->date = date;
	}
#pragma endregion
#pragma region Getters
	string GetText()const {
		return text;
	}
	string GetSource()const {
		return source;
	}
	int GetLine()const {
		return line;
	}
	string GetDate()const {
		return date;
	}
#pragma endregion
	void PrintMessage()const {
		cout << "++++++++++ERROR INFO+++++++++" << endl;
		cout << "Error content : " << text << endl;
		cout << "Source : " << source << endl;
		cout << "Line number : " << line << endl;
		cout << "Date : " << date << endl;
	}
};
#pragma endregion

class InvalidArgumentException :public Exception {
public:
	InvalidArgumentException(const string& text, const  string& source, const int& lne, const string& date) :Exception(text, source, line, date) {

	}
};

#pragma region Stack
template<class T>
class Stack {
	T* data;
	size_t size = 0;
public:
	Stack() :data(NULL), size(NULL) {}
	void Push(const T& newdata) {
		auto newarray = new T[size + 1]{};
		for (size_t i = 0; i < size; i++)
		{
			newarray[i] = data[i];
		}
		newarray[size] = newdata;
		data = newarray;
		newarray = nullptr;
		++size;
	}
	T Pop() {
		assert(size > 0 && "Empty Stack");
		auto newarray = new T[size - 1]{};
		for (size_t i = 0; i < size - 1; i++)
		{
			newarray[i] = data[i];
		}
		T last = data[size - 1];
		if (size != 0) {
			delete[]data;
		}
		data = newarray;
		newarray = nullptr;
		--size;
		return last;
	}
	void DeleteByIndex(int& index) {
		assert(size > 0 && "Empty Stack");
		auto newarray = new T[size - 1]{};
		for (size_t i = 0; i < index; i++)
		{
			newarray[i] = data[i];
		}
		for (size_t i = index; i < size - 1; i++)
		{
			newarray[i] = data[i + 1];
		}
		if (size != 0) {
			delete[]data;
		}
		data = newarray;
		newarray = nullptr;
		--size;
	}
	T Peek()const {
		assert(size > 0 && "Empty Stack");
		return data[size - 1];
	}
	void Clear() {
		if (this->data == NULL || this->size == NULL) {
			return;
		}
		delete[]data;
		this->data = NULL;
		this->size = NULL;
	}
	void Show() const {
		for (size_t i = 0; i < size; i++)
		{
			cout << data[i] << endl;
		}
	}
	size_t GetSize()const {
		return size;
	}
	T& operator[](int index) {
		return data[index];
	}
	~Stack()
	{
		delete[]data;
	}
};
#pragma endregion

#pragma region OrderClass
class Order {
	string orderName;
	int orderCount;
	double orderPrice;
public:
	Order() = default;
	Order(string orderName, int orderCount, double orderPrice) {
		this->orderName = orderName;
		this->orderCount = orderCount;
		this->orderPrice = orderPrice;
	}
#pragma region Setter&Getter
	void SetName(const string& orderName) {
		if (!orderName.empty()) {
			this->orderName = orderName;
		}
		else {
			cout << "Name must not be empty" << endl;
		}
	}
	void SetCount(const int& orderCount) {
		if (orderCount > 0) {
			this->orderCount = orderCount;
		}
		else {
			 cout << "Count must not be less than 0." << endl;
		}
	}
	void SetPrice(const double& orderPrice) {
		if (orderPrice > 0) {
			this->orderPrice = orderPrice;
		}
		else {
			 cout << "Price must not be less than 0." << endl;
		}
	}
	string GetName() const {
		return orderName;
	}
	int GetCount()const {
		return orderCount;
	}
	double GetPrice() const {
		return orderPrice;
	}
#pragma endregion
};
#pragma endregion

#pragma region IngredientsClass
class Ingredients {
private:
	string ingredientName;
	int ingredientCount;
	double ingredientPrice;
	double ingredientCalory;
	Stack<Ingredients>ingredients;
public:
	Ingredients() = default;
	Ingredients(string ingredientName, int ingredientCount, double ingredientPrice, double ingredientCalory) {
		this->ingredientName = ingredientName;
		this->ingredientCount = ingredientCount;
		this->ingredientPrice = ingredientPrice;
		this->ingredientCalory = ingredientCalory;
	}
	Ingredients(string ingredientName, int ingredientCount) {
		this->ingredientName = ingredientName;
		this->ingredientCount = ingredientCount;
	}
	Ingredients(int ingredientCount) {
		this->ingredientCount = ingredientCount;
	}
#pragma region Setter&Getter
	void SetName(const string& ingredientName) {
		if (!ingredientName.empty()) {
			this->ingredientName = ingredientName;
		}
		else {
			cout << "Name must not be empty." << endl;
		}
	}
	void SetCount(const int& ingredientCount) {
		if (ingredientCount > 0) {
			this->ingredientCount = ingredientCount;
		}
		else {
			cout << "Count must not be less than 0." << endl;
		}
	}
	void SetPrice(const double& ingredientPrice) {
		if (ingredientPrice > 0) {
			this->ingredientPrice = ingredientPrice;
		}
		else {
			cout << "Price must not be less than 0" << endl;
		}
	}
	void SetCalory(const double& calory) {
		if (ingredientCalory > 0) {
			this->ingredientCalory = ingredientCalory;
		}
		else {
			cout << "Calory must not be less than 0" << endl;
		}
	}
	string GetName() const {
		return ingredientName;
	}
	int GetCount()const {
		return ingredientCount;
	}
	double GetPrice() const {
		return ingredientPrice;
	}
	double GetCalory()const {
		return ingredientCalory;
	}
#pragma endregion
	void AddIngredients(Ingredients& ingredient) {
		ingredients.Push(ingredient);
	}
	void Show() {
		cout << "Name of the ingredient:" << ingredientName << endl;
		cout << "Count of the ingredient:" << ingredientCount << endl;
		cout << "Price of the ingredient:" << ingredientPrice << endl;
		cout << "Calory of the ingredient:" << ingredientCalory << endl;
	}
	void ShowCalory() {
		cout << "Name of the ingredient:" << ingredientName << endl;
		cout << "Count of the ingredient:" << ingredientCount << endl;
		cout << "Calory of the ingredient:" << ingredientCalory << endl;
	}
	friend ostream& operator<<(ostream& out, const Ingredients& ingredients);
};
#pragma endregion 

#pragma region MealsClass
class Meals {
private:
	string mealName;
	double mealPrice;
	int mealCount;
public:
	Meals() = default;
	Meals(const string& mealName, const double& mealPrice) {
		this->mealName = mealName;
		this->mealPrice = mealPrice;
	}
	Meals(const string& mealName, const double& mealPrice, const int& mealCount) {
		this->mealName = mealName;
		this->mealPrice = mealPrice;
		this->mealCount = mealCount;
	}
#pragma region Setter&Getter
	void SetName(const string& mealName) {
		if (!mealName.empty()) {
			this->mealName = mealName;
		}
		else {
			cout << "Name must not be empty." << endl;
		}

	}
	void SetPrice(const double& mealPrice) {
		if (mealPrice > 0) {
			this->mealPrice = mealPrice;
		}
		else {
			cout << "Price must not be less than 0." << endl;
		}
	}
	void SetCount(const int& mealCount) {
		if (mealCount > 0) {
			this->mealCount = mealCount;
		}
		else {
			cout << "Count must not be less than 0." << endl;
		}
	}
	string GetName() const {
		return mealName;
	}
	double GetPrice() const {
		return mealPrice;
	}
	int GetCount()const {
		return mealCount;
	}
#pragma endregion
	void Show() {
		cout << "Name of the meal:" << mealName << endl;
		cout << "Price of the meal:" << mealPrice << endl;
	}
};
#pragma endregion 

#pragma region Menu
class SezarSalad :public Meals {
	Stack<Ingredients>ingredients;
public:
	SezarSalad(const string& mealname, const double& mealPrice) :Meals(mealname, mealPrice) {}
	void Show() {
		Meals::Show();
	}
	void AddIngredient(Ingredients& ingredient) {
		ingredients.Push(ingredient);
	}
	void ShowIngredients() {
		for (size_t i = 0; i < ingredients.GetSize(); i++)
		{
			ingredients[i].ShowCalory();
		}
	}
	double CalculateCalories() {
		double totalCalory = 0;
		for (size_t i = 0; i < ingredients.GetSize(); i++)
		{
			totalCalory += ingredients[i].GetCalory();
		}
		return totalCalory;
	}
	//lettuce,sezarsauce,tomato,chicken,cheese,dry bread 
};
class Burger :public Meals {
	Stack<Ingredients>ingredients;
public:
	Burger(const string& mealname, const double& mealPrice) :Meals(mealname, mealPrice) {}
	void Show() {
		Meals::Show();
	}
	void AddIngredient(Ingredients& ingredient) {
		ingredients.Push(ingredient);
	}
	void ShowIngredients() {
		for (size_t i = 0; i < ingredients.GetSize(); i++)
		{
			ingredients[i].Show();
		}
	}
	double CalculateCalories() {
		double totalCalory = 0;
		for (size_t i = 0; i < ingredients.GetSize(); i++)
		{
			totalCalory += ingredients[i].GetCalory();
		}
		return totalCalory;
	}
	//meat,tomato,lettuce,cheese,bread
};
class BolognesePasta :public Meals {
	Stack<Ingredients>ingredients;
public:
	BolognesePasta(const string& mealname, const double& mealPrice) :Meals(mealname, mealPrice) {}
	void Show() {
		Meals::Show();
	}
	void AddIngredient(Ingredients& ingredient) {
		ingredients.Push(ingredient);
	}
	void ShowIngredients() {
		for (size_t i = 0; i < ingredients.GetSize(); i++)
		{
			ingredients[i].Show();
		}
	}
	double CalculateCalories() {
		double totalCalory = 0;
		for (size_t i = 0; i < ingredients.GetSize(); i++)
		{
			totalCalory += ingredients[i].GetCalory();
		}
		return totalCalory;
	}
	//pasta,cheese,bolognesesauce
};
class PepperoniPizza :public Meals {
	Stack<Ingredients>ingredients;
public:
	PepperoniPizza(const string& mealname, const double& mealPrice) :Meals(mealname, mealPrice) {}
	void Show() {
		Meals::Show();
	}
	void AddIngredient(Ingredients& ingredient) {
		ingredients.Push(ingredient);
	}
	void ShowIngredients() {
		for (size_t i = 0; i < ingredients.GetSize(); i++)
		{
			ingredients[i].Show();
		}
	}
	double CalculateCalories() {
		double totalCalory = 0;
		for (size_t i = 0; i < ingredients.GetSize(); i++)
		{
			totalCalory += ingredients[i].GetCalory();
		}
		return totalCalory;
	}
	//tomato,pizza dough,sausage,cheese
};
#pragma endregion 

ostream& operator<<(ostream& out, const Ingredients& ingredients) {
	out << "Name of the ingredient:" << ingredients.GetName() << endl;
	out << "Count of the ingredient:" << ingredients.GetCount() << endl;
	return out;
}

#pragma region KitchenClass
class Kitchen {
	Stack<Meals>meals;
public:
	Kitchen() = default;
	Kitchen(const string& meal) {
	}
	void AddMeal(Meals& meal) {
		meals.Push(meal);
	}
	void ShowMeals() {
		for (size_t i = 0; i < meals.GetSize(); i++)
		{
			meals[i].Show();
		}
	}
	int GetIdByMeal(const string& mealname) {
		for (size_t i = 0; i < meals.GetSize(); i++)
		{
			if (meals[i].GetName() == mealname) {
				return i;
			}
		}
	}
	Meals GetNameByMeal(const string& mealname) {
		for (size_t i = 0; i < meals.GetSize(); i++)
		{
			if (meals[i].GetName() == mealname) {
				return meals[i];
			}
		}
	}
	void DeleteMeal(const string& mealname) {
		int myID = GetIdByMeal(mealname);
		auto newArray = new Meals[100]{};
		for (size_t i = 0; i < myID; i++)
		{
			newArray[i] = meals[i];
		}
		for (size_t i = myID + 1; i < meals.GetSize(); i++)
		{
			newArray[i - 1] = meals[i];
		}
		//meals = newArray;
	}
	Meals* GetMealbyId(const int& id) {
		int temp = id - 1;
		for (size_t i = 0; i < meals.GetSize(); i++)
		{
			if (temp == i) {
				return &meals[i];
			}
		}
		return nullptr;
	}
	void UpdateName(const int& id, const string& name) {
		auto current = GetMealbyId(id);
		if (current != nullptr) {
			current->SetName(name);
			cout << "Meal Name is updated successfully!" << endl;
		}
		else {
			cout << "Invalid Meal Name! " << endl;
		}
	}
	void UpdatePrice(const int& id, const int& price) {
		auto current = GetMealbyId(id);
		if (current != NULL) {
			current->SetPrice(price);
			cout << "Meal Price is updated sucessfully!" << endl;
		}
		else {
			cout << "Invalid Entry!" << endl;
		}
	}
	void MealsPop() {
	}
	int GetMealsCount() {
		return meals.GetSize();
	}
};
#pragma endregion

#pragma region UserClass
class User {
	Stack<Kitchen>menu;
public:
	void AddMenu(Kitchen& kitchen) {
		menu.Push(kitchen);
	}
	void ShowMenu() {
		for (size_t i = 0; i < menu.GetSize(); i++)
		{
			menu[i].ShowMeals();
		}
	}
};
#pragma endregion

#pragma region StockClass
class Stock {
	int count = 0;
public:
	Stack<Ingredients>ingredients;
	void SetCount(const int& count) {
		if (count > 0) {
			this->count = count;
		}
		else {
			cout << "Count must not be less than 0." << endl;
		}
	}
	int GetCount()const {
		return count;
	}
	Stock() = default;
	void AddProduct(Ingredients& ing) {
		ingredients.Push(ing);
		SetCount(++count);
	}
	bool ShowAvailability(Ingredients& ing) {
		int size = ingredients.GetSize();
		for (size_t i = 0; i < size; i++)
		{
			if (ingredients[i].GetName() == ing.GetName()) {
				if (ingredients[i].GetCount() >= ing.GetCount()) {
					return true;
				}
			}
		}
		return false;
	}
	void Show() {
		cout << "ALL INGREDIENTS" << endl;
		for (size_t i = 0; i < ingredients.GetSize(); i++)
		{
			cout << ingredients[i] << endl;
		}
	}
};
#pragma endregion

#pragma region FileClass
class FileHelper {
public:
	static string filename;
	static void Save(Stock& stock) {
		remove("stock.txt");
		ofstream fout(filename, ios::app);
		if (fout.is_open()) {
			fout << stock.GetCount() << endl;
			for (size_t i = 0; i < stock.ingredients.GetSize(); i++)
			{
				fout << stock.ingredients[i].GetName() << " " << stock.ingredients[i].GetCount() << endl;
			}
			fout.close();
		}
	}
	static Stock Read() {
		Stock stock;
		ifstream fin(filename);
		int stocksize;
		fin >> stocksize;
		if (fin.is_open()) {
			for (size_t i = 0; i < stocksize; i++)
			{
				Ingredients ing;
				string name;
				double count;
				fin >> name;
				fin >> count;
				ing.SetName(name);
				ing.SetCount(count);
				stock.AddProduct(ing);
			}
			fin.close();
			return stock;
		}
	}
	friend ostream& operator<<(ostream& out, const Ingredients& ingredients);

};
string FileHelper::filename = "stock.txt";

#pragma endregion
