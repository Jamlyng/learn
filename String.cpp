#include "String.h"
String::String(const char* str) {
	for (size = 0; str[size]; ++size);
	this->str = new char[size + 1];
	for (size_t i = 0; i < size; ++i)
		this->str[i] = str[i];
	this->str[size] = '\0';
}
String::String(size_t size, char c) {
	this->size = size;
	this->str = new char[size + 1];
	for (size_t i = 0; i < size; ++i)
		this->str[i] = c;
	this->str[size] = '\0';
}
String::~String() {
	delete[] str;
}
size_t String::Length() {
	return size;
}
void String::Print(bool new_line) {
	for (size_t i = 0; i < size; ++i)
		std::cout << str[i];
	if (new_line)
		std::cout << std::endl;
	return;
}
void String::Append(String& other) {
	char* t = new char[other.Length() + size + 1];
	size_t i = 0;
	for (; i < size; ++i)
		t[i] = str[i];
	for (size_t j = 0; j < other.Length(); ++j, ++i)
		t[i] = other.Get(j);
	size = other.Length() + size;
	t[size] = '\0';
	delete[] str;
	str = t;
}
void String::Append(const char* other) {
	String s(other);
	this->Append(s);
}
char String::Get(size_t index) {
	return str[index];
}
void String::Reverse() {
	char temp = 'N';
	for (size_t i = 0; i < static_cast<size_t>(size/2); ++i) {
		temp = str[i];
		str[i] = str[size - i - 1];
		str[size - i - 1] = temp;
	}
}
void String::Replace(const char* from, const char* to, unsigned quantity) {
	if (!from)
		return;// обработка отсутствия изменений
	size_t size_from = 0;
	size_t size_to = 0;
	size_t size_indices = 100;
	size_t* indices = new size_t[size_indices];
	for (size_t TEMP = 0; TEMP < 100; ++TEMP)	indices[TEMP] = 0;
	size_t quantity_from = 0;
	for (; from[size_from]; ++size_from);
	for (; to[size_to]; ++size_to);
	int change_size = static_cast<size_t>(size_to - size_from);
	for (size_t i = 0, q = 0; ((i < size) && (!quantity || (q < quantity))); ++i) {
		if (str[i] == from[0]) { //Начало проверки вхождения
			size_t i_temp = i;
			bool crossing = true;
			for (size_t j = 0; ((j < size_from)&&(i_temp<size)); ++j,++i_temp) {
				if (str[i_temp] != from[j]) {
					crossing = false;
					break;
				}
			}
			if (crossing) { // Полное вхождение подстроки
				indices[quantity_from] = i;
				++quantity_from;
				if (size_indices == quantity_from) {//Если под индексы не хватает места
					size_t* temp = new size_t[size_indices + 100];
					for (size_t t = 0; t < size_indices; ++t)
						temp[t] = indices[t];
					delete[] indices;
					indices = temp;
					size_indices += 100;
				}
				++q;
			}
		}
	}
	size_t NewSize = size + (change_size * quantity_from);
	char* NewStr = new char[NewSize + 1];
	for (size_t i = 0,j = 0,k = 0; i < size; ++i) {
		if (i == indices[k]) {
			for (size_t h = 0; h < size_to; ++h, ++j)
				NewStr[j] = to[h];
			i += (size_from-1);
			++k;
			continue;
		}
		NewStr[j] = str[i];
		++j;
	}
	NewStr[NewSize] = '\0';
	delete[] str;
	str = NewStr;
	size = NewSize;
	delete[] indices;
}
unsigned String::Count(const char* item) {
	unsigned counter = 0;
	size_t size_item = 0;
	for (; item[size_item]; ++size_item);
	for (size_t i = 0; i < size; ++i) {
		if (str[i] == item[0]) {
			size_t i_temp = i;
			bool crossing = true;
			for (size_t j = 0; ((j < size_item) && (i_temp < size)); ++j, ++i_temp) {
				if (str[i_temp] != item[j]) {
					crossing = false;
					break;
				}
			}
			if (crossing)
				++counter;
		}
	}
	return counter;
}
