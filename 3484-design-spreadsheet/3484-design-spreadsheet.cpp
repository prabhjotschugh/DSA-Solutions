#include <bits/stdc++.h>
using namespace std;

class Spreadsheet {
private:
    unordered_map<string, int> cellValues;

public:
    Spreadsheet(int rows) {
        // rows are fixed at initialization, but not directly used
    }

    void setCell(const string& cell, int value) {
        cellValues[cell] = value;
    }

    void resetCell(const string& cell) {
        cellValues[cell] = 0;
    }

    int getValue(string formula) {
        // remove '=' from the start
        formula = formula.substr(1);

        // split by '+'
        size_t pos = formula.find('+');
        string leftOperand = formula.substr(0, pos);
        string rightOperand = formula.substr(pos + 1);

        auto eval = [&](const string& op) {
            if (!op.empty() && isdigit(op[0]))
                return stoi(op);
            return cellValues.count(op) ? cellValues[op] : 0;
        };

        return eval(leftOperand) + eval(rightOperand);
    }
};
