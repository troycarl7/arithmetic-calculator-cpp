#include <iostream>
#include <iomanip>
#include <algorithm>
#include <array>
#include <cmath>
#include <ctime>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

void multdiv(vector<string>& operators, vector<double>& trnumbers);
void addsub(vector<string>& operators, vector<double>& trnumbers);


int main() {
	string operation;

	cout << "Enter your operation: ";
	getline(cin, operation);

	size_t i = 0;
	vector<string> numbers;
	vector<string> operators;
	vector<double> trnumbers;


	while (i < operation.size()) {
		while (i < operation.size() && operation[i] == ' ') {
			i++;
		}
		if (i >= operation.size()) {
			break;
		}
		size_t spa = operation.find(' ', i);
		if (spa == string::npos) {
			spa = operation.size();
		}
		string op = operation.substr(i, spa - i);
		if (op == "*" || op == "/" || op == "+" || op == "-") {
			operators.push_back(op);
		}
		else {
			size_t j = 0;
			while (j < op.size()) {
				string glued;
				size_t position = op.find_first_of("*/+-", j);
				if (position == string::npos) {
					glued = op.substr(j);
					numbers.push_back(glued);
					break;
				}
				else if (position == 0) {

					operators.push_back(string(1, op[position]));

				}
				else if (position > 0) {
					string cha = op.substr(j, position - j);
					numbers.push_back(cha);
					string chara = op.substr(position, 1);
					operators.push_back(chara);
				}
				j = position + 1;
			}

		}
		i = spa + 1;
	}

	for (size_t w = 0; w < numbers.size(); ++w) {
		trnumbers.push_back(stod(numbers[w]));
	}

	multdiv(operators, trnumbers);
	addsub(operators, trnumbers);
	cout << endl;

	cout << "The final answer is: " << trnumbers[0] << endl;


	return 0;
}



void multdiv(vector<string>& operators, vector<double>& trnumbers) {
	size_t i = 0;
	while (i < operators.size()) {
		if (operators[i] == "*" || operators[i] == "/") {
			if (operators[i] == "*") {
				trnumbers[i] *= trnumbers[i + 1];
				trnumbers.erase(trnumbers.begin() + (i + 1));
				operators.erase(operators.begin() + i);
			}
			else {
				trnumbers[i] /= trnumbers[i + 1];
				trnumbers.erase(trnumbers.begin() + (i + 1));
				operators.erase(operators.begin() + i);
			}
		}
		else
			i++;

	}
}

void addsub(vector<string>& operators, vector<double>& trnumbers) {
	size_t i = 0;
	while (i < operators.size()) {
		if (operators[i] == "+" || operators[i] == "-") {
			if (operators[i] == "+") {
				trnumbers[i] += trnumbers[i + 1];
				trnumbers.erase(trnumbers.begin() + (i + 1));
				operators.erase(operators.begin() + i);
			}
			else {
				trnumbers[i] -= trnumbers[i + 1];
				trnumbers.erase(trnumbers.begin() + (i + 1));
				operators.erase(operators.begin() + i);
			}
		}
		else
			i++;
	}
}
