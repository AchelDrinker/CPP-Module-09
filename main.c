#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <string>
#include <stdexcept>

using namespace std;

// Data structure to store bitcoin prices by date
unordered_map<string, double> bitcoin_prices;

// Parse the CSV file containing bitcoin prices
void parse_csv_file(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("could not open file.");
    }

    string line;
    getline(file, line); // skip header
    while (getline(file, line)) {
        istringstream iss(line);
        string date_str;
        double price;
        if (getline(iss, date_str, ',') && iss >> price) {
            bitcoin_prices[date_str] = price;
        }
    }
}

// Validate and parse a line from the input file
pair<string, double> parse_input_line(string line) {
    istringstream iss(line);
    string date_str, value_str;
    double value;
    if (!(getline(iss, date_str, '|') && getline(iss, value_str))) {
        throw invalid_argument("bad input => " + line);
    }
    if (date_str.size() != 10 || value_str.empty()) {
        throw invalid_argument("bad input => " + line);
    }
    try {
        value = stod(value_str);
        if (value < 0 || value > 1000) {
            throw invalid_argument("not a positive number.");
        }
    } catch (invalid_argument& e) {
        throw invalid_argument("not a positive number.");
    }
    return make_pair(date_str, value);
}

int main(int argc, char** argv) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " input_file" << endl;
        return 1;
    }
    try {
        parse_csv_file("btc_price.csv");
        ifstream input_file(argv[1]);
        if (!input_file.is_open()) {
            throw runtime_error("could not open input file.");
        }
        string line;
        while (getline(input_file, line)) {
            try {
                auto [date_str, value] = parse_input_line(line);
                double exchange_rate = bitcoin_prices[date_str];
                cout << date_str << " => " << value << " = " << value * exchange_rate << endl;
            } catch (exception& e) {
                cout << e.what() << endl;
            }
        }
    } catch (exception& e) {
        cerr << e.what() << endl;
        return 1;
    }
    return 0;
}

