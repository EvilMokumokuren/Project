// OOP - difficult 2 lesson.cpp Kolpakova Ekaterina
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <functional>
#include <string>
#include <fstream>


using namespace std;

/*
1.	Реализуйте шаблонную функцию Swap, которая принимает два указателя и обменивает местами значения, на которые указывают эти указатели.
*/
template <typename T>
void swap(T **Pointer_1,T ** Pointer_2)
{
	T* temp = *Pointer_1;
	*Pointer_1 = *Pointer_2;
	*Pointer_2 = temp;
}

void Task1()
{
	int a = 5;
	int b = 3;
	int *p1 = &a;
	int *p2 = &b;

	cout << "Pointer_1 = " << *p1 << endl <<"Pointer_2 = " << *p2 << endl;

	swap(p1, p2);

	cout << "Pointer_1 = " << *p1 << endl << "Pointer_2 = " << *p2 << endl;
}

/*
2.	Реализуйте шаблонную функцию SortPointers, которая принимает вектор указателей и сортирует указатели по значениям, на которые они указывают.
*/

struct PointerTask2 {
	int val = 0;
	PointerTask2(int a) : val(a) {};
};

struct SortPointers : std::binary_function <PointerTask2*, PointerTask2*, bool> {
	bool operator() (const PointerTask2* a, const PointerTask2* b) const {
		return !a || !b ? 0 : a->val < b->val;
	}
};


void Task2()
{
	PointerTask2 a(8), b(3), c(2), d(0);
	vector<PointerTask2*> v{ &a, &b, &c, &d };

	sort(v.begin(), v.end(), SortPointers());

	for (auto i : v)
		std::cout << i->val << " " << endl;
}

/*
Все таки для самостоятельной проработки это показалось мне сложноватым. Однако решение с сайта https://overcoder.net/q/1059580/c-%D0%BF%D1%80%D0%B5%D0%B4%D0%BE%D1%81%D1%82%D0%B0%D0%B2%D0%BB%D0%B5%D0%BD%D0%B8%D0%B5-%D1%88%D0%B0%D0%B1%D0%BB%D0%BE%D0%BD%D0%BD%D0%BE%D0%B9-%D1%84%D1%83%D0%BD%D0%BA%D1%86%D0%B8%D0%B8-%D1%81%D1%80%D0%B0%D0%B2%D0%BD%D0%B5%D0%BD%D0%B8%D1%8F-%D0%B4%D0%BB%D1%8F-std-sort
по какой-то причине не взлетело. Конкретно в моем случае отладка ругалась на неоднозначность less из строки  std::sort(v.begin(), v.end(), cmp_ptr<less>());
Не подскажите, почему?

Ps провозилась я часа 2 над этим заданием, поэтому решила разобрать реализацию отсюда: https://ru.stackoverflow.com/questions/515271/%D0%A1%D0%BE%D1%80%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%BA%D0%B0-%D0%B2%D0%B5%D0%BA%D1%82%D0%BE%D1%80%D0%B0-%D1%83%D0%BA%D0%B0%D0%B7%D0%B0%D1%82%D0%B5%D0%BB%D0%B5%D0%B9
*/

/*
3.	Подсчитайте количество гласных букв в книге “Война и мир”. Для подсчета используйте 4 способа:
○      count_if и find
○      count_if и цикл for
○      цикл for и find
○      2 цикла for
Замерьте время каждого способа подсчета и сделайте выводы.
Справка:
count_if - это алгоритмическая функция из STL, которая принимает 3 параметра: итератор на начало, итератор на конец и унарный предикат (функцию, принимающую один параметр и возвращающую тип bool).
find - это метод класса string, который возвращает позицию символа (строки), переданного в качестве параметра, в исходной строке. Если символ не найден, то метод возвращает string::npos.
*/

vector<string> CountVowels(const string& s)
{
	//вообще без понятия, как и что =) все-таки сложно за где-то 3 месяца с практически нуля вот в это все =с
}


void Task3()
{
	ifstream file("War and peace.txt");
	file.seekg(0, std::ios::end);
	size_t size = file.tellg();
	file.seekg(0);
	string s(size, ' ');
	file.read(&s[0], size);

	CountVowels(s);
}

int main()
{
	//Task1();
	//Task2();
	//Task3();
}