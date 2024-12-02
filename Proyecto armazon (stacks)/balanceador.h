#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct Product {
    string code;
    int quantity_available;
};

bool validate_product_request(const string& file_path) {

    // Open file_path
    ifstream file(file_path);
    if (!file.is_open()) {
        cerr << "Error opening file: " << file_path << endl;
        return false;
    }
    
    // Read first line (not needed)
    string line;
    getline(file, line);

    // Read second line (not needed)
    getline(file, line);

    // Read the rest of the lines and validate product codes and quantities
    vector<Product> products;
    while (getline(file, line)) {
        stringstream ss(line);
        string code, quantity_str;
        getline(ss, code, '\t');
        getline(ss, quantity_str, '\t');
        int quantity = stoi(quantity_str);

        // Open "articulos.txt"
        ifstream articles_file("articulos.txt");
        if (!articles_file.is_open()) {
            cerr << "Error opening file: articulos.txt" << endl;
            return false;
        }

        // Search for product in "articulos.txt" and validate quantity
        bool product_found = false;
        string article_line;
        while (getline(articles_file, article_line)) {
            stringstream article_ss(article_line);
            string article_code, quantity_available_str;
            getline(article_ss, article_code, '\t');
            getline(article_ss, quantity_available_str, '\t');
            int quantity_available = stoi(quantity_available_str);
            if (article_code == code) {
                product_found = true;
                if (quantity > quantity_available) {
                    cerr << "Error: Not enough quantity available for product " << code << endl;
                    return false;
                }
                break;
            }
        }

        // Close "articulos.txt"
        articles_file.close();

        // If product not found in "articulos.txt"
        if (!product_found) {
            cerr << "Error: Product " << code << " not found in articulos.txt" << endl;
            return false;
        }
    }

    // Close file_path
    file.close();

    // All products valid
    return true;
}

