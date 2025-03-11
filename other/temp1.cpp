#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
#include<exception>
#include<cstring> 
using namespace std;

//********************** start of my_string ****************************

class my_string {
private:
	const int extra = 10;
	char* str;
	int length;
	int capacity;

	void reverse(int new_size) {
		if (new_size >= this->capacity) {
			char* new_str = new char[2 * new_size + 1];
			strncpy(new_str, str, length);
			new_str[length] = '\0';
			delete[] str;
			str = new_str;
			this->capacity = 2 * new_size;
		}
	}
public:
	// 构造，赋值，析构

	my_string() {
		this->length = 0;
		this->str = new char[extra + 1];
		str[0] = '\0';
		capacity = extra;
	}

	my_string(int len) {
		this->length = len;
		this->capacity = len + extra;
		this->str = new char[this->capacity + 1];
		this->str[length] = '\0';
	}

	my_string(const char* other) { // 深拷贝
		this->length = static_cast<int>(strlen(other));
		this->capacity = this->length + extra;
		this->str = new char[this->capacity + 1];
		strncpy(this->str, other, length);
		this->str[length] = '\0';
	}

	my_string(const my_string& ms) {
		this->length = ms.length;
		this->capacity = this->length + extra;
		this->str = new char[this->capacity + 1];
		strncpy(this->str, ms.str, ms.length);
		this->str[length] = '\0';
	}

	~my_string() {
		delete[] str;
	}

	//成员函数

	int size() const {
		return this->length;
	}

	int get_capacity() const {
		return this->capacity;
	}

	bool empty() {
		return this->length == 0;
	}

	void resize(int new_size) {
		char* new_str = new char[new_size + 1 + extra];
		if (new_size >= this->length)
		{
			strncpy(new_str, this->str, this->length);
			delete[] str;
			str = new_str;
			str[new_size] = '\0';
			this->length = new_size;
			this->capacity = new_size + extra;
		}
		else {
			this->clear();
			this->resize(new_size);
		}
	}

	void clear() {
		delete[] str;
		str = nullptr;
		length = 0;
		capacity = extra;
		str = new char[capacity + 1];
		str[0] = '\0';
	}

	void append(const my_string& ms) {
		if (this->length + ms.length + 1 >= this->capacity) {
			reverse(this->length + ms.length + 1);
		}
		strcat(this->str, ms.str);
		this->length = this->length + ms.length;
	}

	void push_back(const char& c) {
		if (this->length + 1 >= this->capacity) {
			reverse(this->length + 1);
		}
		str[length] = c;
		str[++length] = '\0';
	}

	my_string substr(int i, int j) const {
		if (i >= j || i < 0 || i > this->length || j < 0 || j > this->length) {
			my_string empty_string;
			return empty_string;
		}
		my_string tmpString;
		for (int cur = i; cur < j; cur++) {
			tmpString.push_back(this->str[cur]);
		}
		return tmpString;
	}

	const char* c_str() const {   //返回C风格字符串
		return this->str;
	}

	my_string operator+(const my_string& ms);
	my_string& operator=(const my_string& ms);
	bool operator!=(const my_string& ms) const;
	bool operator==(const my_string& ms) const;
	char operator[](int index);
	char operator[](int index) const;

	friend istream& operator>>(istream& is, my_string& ms);
	friend ostream& operator<<(ostream& os, my_string& ms);
};

//相关运算符重载

bool my_string::operator==(const my_string& ms) const {
	return strcmp(ms.str, this->str) == 0;
}

bool my_string::operator!=(const my_string& ms) const {
	return strcmp(ms.str, this->str) != 0;
}

char my_string::operator[](int index) {
	if (index >= length || index < 0) {
		throw out_of_range("index out of range!");
	}
	return str[index];
}

char my_string::operator[](int index) const {
	if (index >= length || index < 0) {
		throw out_of_range("index out of range!");
	}
	return str[index];
}

my_string& my_string::operator=(const my_string& ms) {
	if (&ms != this) {
		delete[] str;
		this->length = ms.length;
		this->capacity = this->length + extra;
		this->str = new char[this->capacity + 1];
		strcpy(this->str, ms.str);
	}
	return *this;
}

my_string my_string::operator+(const my_string& ms) {
	my_string result;
	result.length = this->length + ms.length;
	result.capacity = result.length + extra;
	result.str = new char[result.capacity + 1];
	strcpy(result.str, this->str);
	strcat(result.str, ms.str);
	return result;
}

istream& operator>>(istream& is, my_string& ms) {
	char ch;
	ms.clear();
	while (is.peek() == ' ' || is.peek() == '\n') {
		is.get(ch);
	} //忽略前导空格
	while (is.get(ch) && ch != '\n' && ch != ' ') {
		ms.reverse(ms.length + 1);

		ms.str[ms.length] = ch;
		ms.length++;
	}
	ms.str[ms.length] = '\0';
	return is;
}

ostream& operator<<(ostream& os, my_string& ms) {
	for (int i = 0; i < ms.length; ++i) {
		os << ms.str[i];
	}
	return os;
}

//********************** end of my_string ****************************

void my_getline(istream& is, my_string& ms, char ch = '\n') {
	ms.clear();
	char tmp;
	while (is.get(tmp)) {
		if (tmp == ch)
			break;
		ms.push_back(tmp);
	}
	if (!is && ms.empty()) {
		is.setstate(ios::failbit);
	}
}

class data_structure {
protected:
	int _size;
public:
	data_structure() {
		_size = 0;
	}
	inline const int size() const {
		return _size;
	}
	inline const bool empty() const {
		return _size == 0;
	}
	//virtual void remove() = 0;
	virtual void clear() = 0;
};


//******************** start of my_vector *****************************

template <class T> class my_vector : public data_structure {
private:
	const int extra = 10;
	T* start;
	int capacity;   //表示实际申请了多大空间

	void reverse(int new_size) {   // 在需要添加元素之前，一定要先用这个函数判别一下
		if (new_size >= this->capacity) {  //希望可以实现移动构造
			this->capacity = 2 * this->capacity + extra;
			T* new_mem = new T[this->capacity];
			T* begin_tmp = start;
			start = new_mem;
			for (int i = 0; i < _size; ++i) {
				if constexpr (std::is_move_constructible<T>::value) {
					// 如果 T 支持移动构造，使用 std::move
					*(start + i) = std::move(*(begin_tmp + i));
				}
				else {
					// 否则使用拷贝构造
					*(start + i) = *(begin_tmp + i);
				}
			}
			delete[] begin_tmp;
		}
	}

public:
	class my_iterator;

	const my_iterator begin() const {   // ROV
		return my_iterator(start);
	}

	my_iterator begin() {
		return my_iterator(start);
	}

	const my_iterator end() const {
		return my_iterator(start + _size);
	}

	my_iterator end() {
		return my_iterator(start + _size);
	}

	my_vector() {
		capacity = extra;
		_size = 0;
		T* new_mem = new T[extra];
		start = new_mem;
	}

	my_vector(int len) {
		capacity = len + extra;
		_size = len;
		T* new_mem = new T[extra + len];
		start = new_mem;
	}

	my_vector(int len, T element) {   // T必须正确重载了 = 
		capacity = len + extra;
		_size = len;
		T* new_mem = new T[extra + len];
		start = new_mem;
		for (int i = 0; i < len; ++i) {
			*(start + i) = element;
		}
	}

	my_vector(const my_vector& mv) {
		if (this != &mv) {
			capacity = mv.capacity;
			_size = mv._size;
			T* new_mem = new T[mv.capacity];
			start = new_mem;
			for (int i = 0; i < _size; ++i) {
				*(start + i) = *(mv.start + i);
			}
		}
	}

	~my_vector() {
		delete[] start;
	}

	void push_back(T element) {
		reverse(_size + 1);
		*(start + _size) = element;
		_size++;
	}

	T pop_back() {
		T tmp_element;
		if (!empty()) {
			tmp_element = *(start + _size - 1);
			_size--;
			return tmp_element;
		}
		throw std::out_of_range("my_vector is empty!");
	}

	void clear() {  //先不释放内存
		_size = 0;
	}

	my_vector& operator+(const my_vector& mv) {
		my_vector result(*this);
		for (int i = 0; i < mv.size(); ++i) {
			result.push_back(*(mv + i));
		}
		return result;
	}

	my_vector& operator=(const my_vector& mv) {
		this->clear();
		for (int i = 0; i < mv.size(); ++i) {
			this->push_back(mv[i]);
		}
		return *this;
	}

	T& operator[](int index) {
		if (index >= _size || index < 0) {
			throw std::out_of_range("index out of range!");
		}
		return *(my_vector::begin() + index);
	}

	const T& operator[](int index) const {
		if (index >= _size || index < 0) {
			throw std::out_of_range("index out of range!");
		}
		return *(my_vector::begin() + index);
	}

	class my_iterator {
	protected:
		T* ptr;
		friend class my_vector;

	public: // vector的遍历很简单，就直接加减指针即可
		my_iterator() {
			ptr = nullptr;
		}

		my_iterator(T* pointer) {
			this->ptr = pointer;
		}

		my_iterator(const my_iterator& mi) {
			this->ptr = mi.ptr;
		}

		T& operator*() const {     //这里可以不返回引用吗 不可以
			return *ptr;
		}

		my_iterator operator+(int index) {
			my_iterator result(this->ptr);
			result.ptr += index;
			return result;
		}

		const my_iterator operator+(int index) const {
			my_iterator result(this->ptr);
			result.ptr += index;
			return result;
		}

		my_iterator operator++() {  //前缀++
			ptr++;
			return *this;           // attention: 我没有限制迭代器范围，即使超过end也不会报错
		}

		my_iterator operator++(int) {  //后缀++
			my_iterator tmp = *this;
			ptr++;
			return tmp;
		}

		my_iterator operator--() {  //前缀--
			ptr--;
			return *this;
		}

		my_iterator operator--(int) {   //后缀--
			my_iterator tmp = *this;
			ptr--;
			return tmp;
		}

		my_iterator& operator=(const T* element) {
			ptr = element;
			return *this;
		}

		int operator-(const my_iterator& mi) {
			return static_cast<int>(this->ptr - mi.ptr);
		}

		bool operator ==(const my_iterator& mi) {
			return mi.ptr == this->ptr;
		}

		bool operator !=(const my_iterator& mi) {
			return mi.ptr != this->ptr;
		}

		bool operator >(const my_iterator& mi) {
			return this->ptr > mi.ptr;
		}

		bool operator <(const my_iterator& mi) {
			return this->ptr < mi.ptr;
		}
	};

};

//********************* end of my_vector ******************************

//************************ start of my_sort ***************************

class default_cmp {
public:
	template<typename T>
	bool operator()(const T& left, const T& right) {
		return left < right;
	}
};

template <class RandomIt, class Compare = default_cmp>   //Compare默认为default类
void my_sort(RandomIt start_it, RandomIt end_it, Compare cmp = Compare()) {
	int low = 0;
	int high = end_it - start_it - 1;
	qSort(start_it, low, high, cmp);
}

template <class RandomIt, class Compare>
int partition(RandomIt array, const int low, const int high, Compare cmp)
{
	int pivot = array[high];    // T类正确重载[]
	int i = low - 1;
	for (int j = low; j < high; j++) {
		if (cmp(array[j], pivot)) {
			i++;
			swap(array[j], array[i]);
		}
	}
	swap(array[high], array[i + 1]);

	return i + 1;
}

template <class RandomIt, class Compare>
void qSort(RandomIt array, int low, int high, Compare cmp) {
	if (low <= high)  //not (low==high)!! think about why?
	{
		int tmp = partition(array, low, high, cmp);
		qSort(array, low, tmp - 1, cmp);
		qSort(array, tmp + 1, high, cmp);
	}
}

//************************ end of my_sort ******************************

//********************* start of class node ****************************

template <class T> class node {
public:
	T data;
	node* f_ptr;
	node* b_ptr;

public:
	node() {
		f_ptr = nullptr;
		b_ptr = nullptr;
	}

	node(T dt) {
		data = dt;
		f_ptr = nullptr;
		b_ptr = nullptr;
	}

	node(T dt, node* fp) {
		data = dt; // 确保类T重载了"="
		f_ptr = fp;
		b_ptr = nullptr;
	}

	node(T dt, node* fp, node* bp) {
		data = dt;
		f_ptr = fp;
		b_ptr = bp;
	}

	node* get_f_ptr() {
		return this->f_ptr;
	}

	node* get_b_ptr() {
		return this->b_ptr;
	}

	node& operator=(node& nd) {
		if (&nd != this) { //实现深拷贝
			this->data = nd.data;
			this->f_ptr = nd.f_ptr;
			this->b_ptr = nd.b_ptr;
		}
	}
};

//********************** end of class node *****************************


//*********************** start of my_list **************************

template <class T> class my_list : public data_structure {
private:
	node<T>* begin;
	node<T>* end;

public:
	my_list() {
		begin = nullptr;
		end = nullptr;
		_size = 0;
	}

	my_list(const T& dt) {
		node<T>* newnode = new node<T>(dt);   //确保T类重载了=
		this->begin = newnode;
		this->end = newnode;
		newnode->f_ptr = nullptr;
		newnode->b_ptr = nullptr;
		_size++;
	}

	my_list(my_list&& ml) noexcept {
		begin = ml.begin;
		end = ml.end;
		_size = ml.size();
		ml.begin = nullptr;
		ml.end = nullptr;
	}

	my_list(const my_list& ml) { // 为什么参数里加一个const会无法调用size()函数？为什么加了const之后才能调用拷贝构造？
		if (&ml != this) {
			if (ml.size() == 0) {
				begin = nullptr;
				end = nullptr;
			}
			else {
				node<T>* other_cur = ml.get_begin();
				while (other_cur != nullptr) {
					node<T>* new_node = new node<T>(other_cur->data);
					this->push_back(new_node);
					other_cur = other_cur->f_ptr;
				}
				begin = ml.get_begin();
				end = ml.get_end();
			}
		}
	}

	~my_list() {   // attention
		node<T>* cur = begin;
		while (cur != nullptr) {
			node<T>* temp = cur->f_ptr;
			delete cur;
			cur = temp;
		}
	}

	my_list& operator=(const my_list& ml) {
		if (&ml != this) {
			this->clear();
			if (ml.size() == 0) {
				begin = nullptr;
				end = nullptr;
			}
			else {
				node<T>* other_cur = ml.get_begin();
				while (other_cur != nullptr) {
					node<T>* new_node = new node<T>;
					new_node->data = other_cur->data;
					this->push_back(new_node);
					other_cur = other_cur->f_ptr;
				}
			}
		}
		return *this;
	}

	node<T>* get_begin() const {
		return this->begin;
	}

	node<T>* get_end() const {
		return this->end;
	}

	void push_back(const T& dt) {
		node<T>* nd = new node<T>(dt);
		if (_size == 0) {
			begin = nd;
			end = nd;
			_size++;
			return;
		}
		nd->b_ptr = end;
		nd->f_ptr = nullptr;
		end->f_ptr = nd;
		end = nd;
		_size++;
	}

	void push_front(const T& dt) {
		node<T>* nd = new node<T>(dt);
		if (_size == 0) {
			begin = nd;
			end = nd;
			_size++;
			return;
		}
		nd->f_ptr = begin;
		nd->b_ptr = nullptr;
		begin->b_ptr = nd;
		begin = nd;
		_size++;
	}

	void pop_back() {
		if (empty())
			return;
		node<T>* tmp_ptr = end;
		end = end->b_ptr;
		if (end != nullptr)
			end->f_ptr = nullptr;
		_size--;
		if (empty())   // 这一步很重要，当删到头节点时，也要把begin指针置为nullptr！不然析构的时候会删除一块已经被delete的空间
			begin = nullptr;
		delete tmp_ptr;
	}

	void pop_front() {
		if (empty())
			return;
		node<T>* tmp_ptr = begin;
		begin = begin->f_ptr;
		if (begin != nullptr)
			begin->b_ptr = nullptr;
		_size--;
		if (empty())
			end = nullptr;
		delete tmp_ptr; // 这里如果node不是动态内存分配来的，会出问题
	}

	void clear() {
		node<T>* cur = begin;
		while (cur != nullptr) {
			node<T>* temp = cur;
			delete temp;
			cur = cur->f_ptr;
		}
		begin = nullptr;
		end = nullptr;
		_size = 0;
	}

	my_list get_intersection(const my_list<T>& ml) const {
		node<T>* self_cur = begin;
		node<T>* other_cur = ml.get_begin();
		my_list<T> intersection;
		while (self_cur != nullptr && other_cur != nullptr) {
			if (self_cur->data == other_cur->data &&
				!(intersection.size() > 0 && intersection.end->data == self_cur->data)) { //确保data类重载了==, >, <, >=, <=
				intersection.push_back(self_cur->data);
				self_cur = self_cur->f_ptr;
				other_cur = other_cur->f_ptr;
			}
			else if (self_cur->data > other_cur->data) {
				other_cur = other_cur->f_ptr;
			}
			else {
				self_cur = self_cur->f_ptr;
			}
		}
		return intersection;    // 这里为什么不能用move，使用移动拷贝
	}
};

//*************************** end of my_list *************************


//********************** start of my_stack ****************************

class my_stack_overflow : public exception {
private:
	my_string message;

public:
	my_stack_overflow(const my_string& ms) {
		message = ms;
	}

	virtual const char* what() noexcept {
		return message.c_str();
	}
};

class my_stack_underflow : public exception {
private:
	my_string message;

public:
	my_stack_underflow(const my_string& ms) {
		message = ms;
	}

	virtual const char* what() noexcept {
		return message.c_str();
	}
};

template <class T> class my_stack : public data_structure {
private:
	static constexpr int max_size_of_stack = 1000; //存在爆栈的可能性
	T data[max_size_of_stack]; // T中需要对 = 进行重载
	int top_ptr, rear_ptr;

	bool check_full() {
		return _size == max_size_of_stack;  //如果顶指针和尾指针相等，说明栈满（当然也有可能是栈空，只是在代码中会避免这种情况出现）
	}

public:
	my_stack() {
		top_ptr = -1;
		rear_ptr = 0;
	}

	virtual ~my_stack() {

	}

	void push(const T& element) {
		top_ptr = (top_ptr + 1) % max_size_of_stack;
		if (check_full())
			throw my_stack_overflow("stack overflow");
		data[top_ptr] = element; // 尤其注意如果 T 类中有动态内存申请，一定注意对 = 的深拷贝
		_size++;
	}

	T& pop() {
		if (empty()) {
			throw my_stack_underflow("stack underflow");
		}
		int tmp_ptr = rear_ptr;
		rear_ptr = (rear_ptr + 1) % max_size_of_stack;
		_size--;
		return data[tmp_ptr];
	}

	const T& top() const {
		return data[top_ptr];
	}

	void clear() {
		rear_ptr = top_ptr;
		_size = 0;
	}
};

//依靠链表实现的栈
template <class T> class my_stack_by_list : public my_list<T> {
private:
public:
	using my_list<T>::pop_back;
	using my_list<T>::push_back;

	void push(const T& element) {
		push_back(element);
	}

	T pop() {    //这里如果返回对tmp_element的引用，会出现问题
		if (this->empty()) {
			throw my_stack_underflow("stack underflow");
		}
		T tmp_element = this->get_end()->data;
		pop_back();
		return tmp_element;
	}

	const T& top() const {
		return this->get_end()->data;
	}

	void clear() {
		my_list<T>::clear();
	}
};

//************************ end of my_stack *****************************

//*************************** end of my_list *************************

/*
	两种方式实现队列，一种数组方式，一种链表方式
*/

class my_deque_overflow : public exception {
private:
	my_string message;
public:
	my_deque_overflow(const my_string& ms) {
		message = ms;
	}
	virtual const char* what() noexcept {
		return message.c_str();
	}
};
class my_deque_underflow : public exception {
private:
	my_string message;
public:
	my_deque_underflow(const my_string& ms) {
		message = ms;
	}
	virtual const char* what() noexcept {
		return message.c_str();
	}
};

//********************** start of my_deque **********************

//数组实现

template <class _Ty> class my_deque : public data_structure {
private:
	static constexpr int _max_size_of_deque = 1000;
	_Ty data[_max_size_of_deque];
	int _pfront, _prear;
	bool check_full() {
		return _size == _max_size_of_deque;
	}

public:
	my_deque() {
		_pfront = -1;
		_prear = 0;
		_size = 0;
	}

	my_deque(const _Ty& first) {
		_pfront = -1;
		data[++_pfront] = first;
		_prear = 0;
		_size++;
	}

	my_deque(const my_deque& md) {
		for (int ptr = md._prear, num = 1; num <= md.size();
			++num, ptr = (ptr + 1) % _max_size_of_deque) {
			this->data[++_pfront] = md.data[ptr];
			this->_size = md.size();
		}
	}

	virtual ~my_deque() {
	}

	void push_front(const _Ty& element) {   // 确保_Ty类正确重载了=
		if (check_full())
			throw my_deque_overflow("deque overflow");
		_pfront = (_pfront + 1) % _max_size_of_deque;
		data[_pfront] = element;
		_size++;
	}

	void push_back(const _Ty& element) {
		if (check_full())
			throw my_deque_overflow("deque overflow");
		_prear = (_prear + _max_size_of_deque - 1) % _max_size_of_deque;
		_size++;
		data[_prear] = element;
	}

	_Ty pop_front() {
		if (empty())
			throw my_deque_underflow("try to delete a empty deque");
		int tmp_ptr = (_pfront + _max_size_of_deque) % _max_size_of_deque;
		_pfront = (_pfront + _max_size_of_deque - 1) % _max_size_of_deque;
		_size--;
		return data[tmp_ptr];
	}

	_Ty pop_back() {
		if (empty())
			throw my_deque_underflow("try to delete a empty deque");
		int tmp_ptr = _prear;
		_prear = (_prear + 1) % _max_size_of_deque;
		_size--;
		return data[tmp_ptr];
	}

	_Ty top() {
		if (empty())
			throw my_deque_underflow("invalid top(), empty deque");
		return data[_pfront];
	}

	_Ty back() {
		if (empty())
			throw my_deque_underflow("invalid back(), empty deque");
		return data[_prear];
	}

	void clear() {
		_size = 0;
		_pfront = -1;
		_prear = 0;
	}
};

//链表实现
template<class _Ty> class my_deque_by_list : public my_list<_Ty> {
public:
	/*
	using my_list<_Ty> push_back;
	using my_list<_Ty> push_front;
	using my_list<_Ty> pop_front;
	using my_list<_Ty> pop_back;
	*/

	using data_structure::empty;

	my_deque_by_list(const _Ty& first) {
		my_list<_Ty>::push_back(first);
	}

	void push_back(const _Ty& element) {
		my_list<_Ty>::push_back(element);
	}

	void push_front(const _Ty& element) {
		my_list<_Ty>::push_front(element);
	}

	_Ty pop_front() {
		if (empty())
			throw my_deque_underflow("try to delete a empty deque");
		_Ty tmp_ele = this->get_begin()->data;
		my_list<_Ty>::pop_front();
		return tmp_ele;
	}

	_Ty pop_back()override {
		if (empty())
			throw my_deque_underflow("try to delete a empty deque");
		_Ty tmp_ele = this->get_end()->data;
		my_list<_Ty>::pop_back();
		return tmp_ele;
	}

	void clear() override {
		my_list<_Ty>::clear();
	}

	_Ty top() const {
		if (empty())
			throw my_deque_underflow("invalid top, empty deque");
		return this->get_begin()->data;
	}

	_Ty back() const {
		if (empty())
			throw my_deque_underflow("invalid back, empty deque");
		return this->get_end()->data;
	}
};

//********************** end of my_deque **************************






template<typename _Ty> class my_binary_tree;
template<typename _Ty, typename _Compare = my_less<_Ty>> class my_priority_queue;

class wrong_info :public exception {
private:
	my_string message;
public:
	wrong_info(const my_string& ms) {
		this->message = ms;
	}
	virtual const char* what() const noexcept {
		return message.c_str();
	}
};

template<typename _Ty> class tree_node {
private:
	_Ty data;
	tree_node<_Ty>* father_node;
	tree_node<_Ty>* left_son;
	tree_node<_Ty>* right_son;
	friend class my_binary_tree<_Ty>;
public:
	tree_node(const _Ty& dt) {
		this->data = dt;
		this->father_node = nullptr;
		this->left_son = nullptr;
		this->right_son = nullptr;
	}
	tree_node() {
		this->father_node = nullptr;
		this->left_son = nullptr;
		this->right_son = nullptr;
	}
	virtual ~tree_node() {
	}
	
	inline bool is_leaf_node() {
		return (left_son == nullptr && right_son == nullptr) ? true : false;
	}

};

template<typename _Ty> class my_binary_tree : public data_structure {
protected:
	tree_node<_Ty>* ancestor_node;
public:
	my_binary_tree() {
		ancestor_node = nullptr;
		_size = 0;
	}
	my_binary_tree(const _Ty& dt) {
		tree_node<_Ty>* newnode = new tree_node<_Ty>(dt);  // new
		_size = 1;
		this->ancestor_node = newnode;
	}
	virtual ~my_binary_tree() {
		int _;
		recur_delete(ancestor_node, _);
	}
	void clear() {
		int _;
		recur_delete(ancestor_node, _);
		_size = 0;
	}
	void recur_delete(tree_node<_Ty>* cur_node, int& node_number) {
		if (cur_node == nullptr)
			return;
		node_number++;
		recur_delete(cur_node->left_son, node_number);
		recur_delete(cur_node->right_son, node_number);
		delete cur_node;
	}

	//寻找最右边有值的节点
	tree_node<_Ty>* find_deepest_node() {
		if (this->ancestor_node == nullptr)
			throw wrong_info("no node in this binary_tree!");
		my_deque<tree_node<_Ty>> record;
		record.push_back(ancestor_node);
		tree_node<_Ty>* deepest = nullptr;
		while (!record.empty()) {
			deepest = record.top();
			record.pop_front();
			if (deepest->left_son)
				record.push_back(deepest->left_son);
			if (deepest->right_son)
				record.push_back(deepest->right_son);
		}
		return deepest;
	}

	virtual void find(const _Ty& dt, tree_node<_Ty>* cur_node, tree_node<_Ty>* find_node) {
		if (find_node != nullptr)
			return;
		if (cur_node->data == dt) {
			find_node = cur_node;
			return;
		}
		find(dt, cur_node->left_son, find_node);
		find(dt, cur_node->right_son, find_node);
	}

	virtual _Ty pop(const _Ty& dt, tree_node<_Ty>* cur_node) {
		tree_node<_Ty> find_node;
		find(dt, this->ancestor_node, find_node);
		if (find_node == nullptr) {
			throw wrong_info("do not find such node in pop()!");
		}

		_Ty return_value = find_node->data;
		tree_node<_Ty>* deepest = find_deepest_node();
		find_node->data = deepest->data;   //只把值复制过去，指针不变
		tree_node<_Ty>* fn = deepest->father_node;

		if (find_node == ancestor_node)
			this->ancestor_node = deepest;
		if (fn->left_son = deepest)	{
			fn->left_son = nullptr;
		}
		else {
			fn->right_son = nullptr;
		}
		delete deepest;
		_size--;
		return return_value;
	}

	//找到最深节点直接push
	virtual tree_node<_Ty>* push(const _Ty& dt) {
		tree_node<_Ty>* newnode = new tree_node<_Ty>(dt);

		my_deque<tree_node<_Ty>*> record;
		if (ancestor_node == nullptr) {
			ancestor_node = newnode;
			_size++;
			return;
		}
		else
			record.push_back(ancestor_node);

		while (!record.empty()) {
			tree_node<_Ty>* cur = record.top();
			record.pop_front();

			if (cur->left_son == nullptr) {
				cur->left_son = newnode;
				newnode->father_node = cur;
				return;
			}
			else {
				record.push_back(cur->left_son);
			}
			if (cur->right_son == nullptr) {
				cur->right_son = newnode;
				newnode->father_node = cur;
				return;
			}
			else {
				record.push_back(cur->right_son);
			}
		}
		return newnode;
	}

	virtual void swap_tree_node(tree_node<_Ty>* tnf, tree_node<_Ty>* tns) {
		if (tnf == nullptr || tns == nullptr)
			throw wrong_info("try to swap nullptr!");
		
		_Ty* newdt = new _Ty;
		*newdt = tns->data;
		tns->data = tnf->data;
		tnf->data = *newdt;    // _Ty类一定要正确重载 =
		delete newdt;
	}
};

template<typename _Ty> class my_less {
public:
	bool operator()(const _Ty& left_class, const _Ty& right_class) const{
		return left_class < right_class;
	}
};

template<typename _Ty, typename _Compare = my_less<_Ty>> 
class my_priority_queue : public my_binary_tree<_Ty> {
	using my_binary_tree<_Ty>::ancestor_node;
	using my_binary_tree<_Ty>::find_deepest_node;
	using my_binary_tree<_Ty>::_size;
public:
	_Compare _Compare;
	virtual tree_node<_Ty>* push(const _Ty& dt) {
		tree_node<_Ty>* cur = my_binary_tree<_Ty>::push(dt);
		while (cur != ancestor_node && _Compare(cur->father_node->data, cur->data)) {
			swap_tree_node(cur, cur->father_node);
			cur = cur->father_node;
		}
		return cur;
	}
	
	virtual void pop() {
		tree_node<_Ty>* deepest = find_deepest_node();
		swap_tree_node(ancestor_node, deepest);
		tree_node<_Ty>* father = deepest->father_node;
		if (father->left_son == deepest)
			father->left_son = nullptr;
		else
			father->right_son = nullptr;
		delete deepest;
		_size--;
		tree_node<_Ty>* cur = ancestor_node;
		
		while (1) {
			if (cur->left_son != nullptr && cur->right_son == nullptr) {
				if (_Compare(cur->left_son->data, cur->data) && _Compare(cur->right_son->data, cur->data)) {
					break;
				}
				else if (_Compare(cur->left_son->data, cur->data) && !_Compare(cur->right_son->data, cur->data)) {
					swap_tree_node(cur, cur->right_son);
					cur = cur->right_son;
				}
				else {
					swap_tree_node(cur, cur->left_son);
					cur = cur->left_son;
				}
			}
			else if (cur->left_son != nullptr && cur->right_son == nullptr) {
				if (_Compare(cur->left_son->data, cur->data)) {
					break;
				}
				else {
					swap_tree_node(cur, cur->left_son);
					cur = cur->left_son;
				}
			}
			else if (cur->left_son == nullptr && cur->right_son != nullptr) {
				if (_Compare(cur->right_son->data, cur->data)) {
					break;
				}
				else {
					swap_tree_node(cur, cur->right_son);
					cur = cur->right_son;
				}
			}
			else
				break;
		}
	}

	_Ty& top() {
		return ancestor_node->data;
	}
};

int main() {

	my_priority_queue<int> mpq;
	int test[10] = { 45,34,1,6,3,7,-1,3,7,7 };
	for (int i = 0; i < 10; ++i) {
		mpq.push(test[i]);
	}
	for (int i = 0; i < 10 ; ++i) {
		cout << mpq.top() << endl;
		mpq.pop();
		cout << mpq.size() << endl <<endl;
	}
	return 0;
}
