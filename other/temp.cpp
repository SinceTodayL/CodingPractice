/*****************************************************************//**
 * \file   assignment2_problem5.cpp
 * \brief  Big int plus big int.
 * 
 * \author Long Chengyou
 * \date   September 2024
 *********************************************************************/
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

const int kMaxNumLength = 100;

/// <summary>
/// for unruly big int, 10-based only.
/// </summary>
class BigInt
{
private:
	string num_;
public:		
	/// <summary>
	/// Displays the number.
	/// </summary>
	void DisplayNum();	
	/// <summary>
	/// Sets the number.
	/// </summary>
	/// <param name="num">The number.</param>
	/// <returns>Whether the parameter number is leagal.</returns>
	bool set_num_(string& num);		
	/// <summary>
	/// Gets the number.
	/// </summary>
	/// <returns>the num_</returns>
	string get_num_();	
	/// <summary>
	/// The addition of two BigInt.
	/// </summary>
	/// <param name="the_other">The other Bigint to be added together.</param>
	/// <returns>The sum.</returns>
	BigInt operator+(BigInt the_other);
};

/// <summary>
/// Input to an int variable.
/// </summary>
/// <param name="kMinNum">The minimum number accepted.</param>
/// <param name="kMaxNum">The maximum number accepted.</param>
/// <param name="hint">A hint for input.</param>
/// <returns>The inputted number.</returns>
int InputInt(const int kMinNum, const int kMaxNum, const char* hint = "");

int main()
{
	int num_a_length, num_b_length;//but actually I don't use them.
	string num_a, num_b;
	num_a_length = InputInt(1, kMaxNumLength, "Enter the length of the first number (number a):");
	cout << "Enter number a:" << endl;
	cin >> num_a;
	num_b_length = InputInt(1, kMaxNumLength, "Enter the length of the second number (number b):");
	cout << "Enter number b:" << endl;
	cin >> num_b;

	BigInt a, b;
	a.set_num_(num_a);
	b.set_num_(num_b);

	(a + b).DisplayNum();

	return 0;
}

void BigInt::DisplayNum()
{
	cout << num_;
}
bool BigInt::set_num_(string& num)
{
	for (int i = 0; i<int(num.length()); i++)
	{
		if (!isdigit(num[i])) return false;
	}
	num_ = num;
	return true;
}
string BigInt::get_num_()
{
	return num_;
}
BigInt BigInt::operator+(BigInt the_other)
{
	string num[2];
	num[0] = num_;
	num[1] = the_other.get_num_();
	reverse(num[0].begin(), num[0].end());
	reverse(num[1].begin(), num[1].end());//to align the lower digit.
	int max_length = max(num[0].length(), num[1].length());

	string answer = "";
	int carry = 0, digit_sum;
	for (int i = 0; i < max_length; i++)
	{
		digit_sum = 0;
		for (int j = 0; j < 2; j++)
		{
			if (int(num[j].length()) > i)//Whether a string has been used up.
			{
				digit_sum += (num[j][i] - '0');
			}
		}
		digit_sum += carry;
		
		carry = digit_sum / 10;
		digit_sum %= 10;

		answer = answer + char(digit_sum + '0');
	}

	if (carry != 0)
	{
		answer = answer + char(carry + '0');
	}
	reverse(answer.begin(), answer.end());

	BigInt result;
	result.set_num_(answer);
	
	return result;
}

int InputInt(const int kMinNum, const int kMaxNum, const char* hint)
{
	int input;
	while (true)
	{
		cout << hint << endl;
		cin >> input;
		if (cin.good() && kMinNum <= input && input <= kMaxNum)//Legal input, within acceptable range.
		{
			return input;
		}
		else if (cin.fail())//illegal input.
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Illegal input, please input again." << endl;
		}
		else
		{
			cout << "Input too small or too big, please input again." << endl;
		}
	}
}
