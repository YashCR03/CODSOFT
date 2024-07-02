#include <iostream>
#include <cmath>
using namespace std;

void displayMenu() {
    cout << "\nChoose an operation:" << endl;
    cout << "1. Addition (+)" << endl;
    cout << "2. Subtraction (-)" << endl;
    cout << "3. Multiplication (*)" << endl;
    cout << "4. Division (/)" << endl;
    cout << "5. Exponentiation (^)" << endl;
    cout << "6. Modulus (%)" << endl;
    cout << "7. Square Root (sqrt)" << endl;
    cout << "8. Sine (sin)" << endl;
    cout << "9. Cosine (cos)" << endl;
    cout << "10. Tangent (tan)" << endl;
    cout << "11. Logarithm (log)" << endl;
    cout << "12. Natural Logarithm (ln)" << endl;
    cout << "13. Exit" << endl;
}

double getNumber(const string& prompt) {
    double num;
    cout << prompt;
    cin >> num;
    return num;
}

int main() {
    bool keepGoing = true;

    while (keepGoing) {
        displayMenu();
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        double num1, num2, result;
        switch (choice) {
            case 1:
                num1 = getNumber("Enter the first number: ");
                num2 = getNumber("Enter the second number: ");
                result = num1 + num2;
                cout << "Result: " << result << endl;
                break;
            case 2:
                num1 = getNumber("Enter the first number: ");
                num2 = getNumber("Enter the second number: ");
                result = num1 - num2;
                cout << "Result: " << result << endl;
                break;
            case 3:
                num1 = getNumber("Enter the first number: ");
                num2 = getNumber("Enter the second number: ");
                result = num1 * num2;
                cout << "Result: " << result << endl;
                break;
            case 4:
                num1 = getNumber("Enter the first number: ");
                num2 = getNumber("Enter the second number: ");
                if (num2 != 0) {
                    result = num1 / num2;
                    cout << "Result: " << result << endl;
                } else {
                    cout << "Error: Division by zero!" << endl;
                }
                break;
            case 5:
                num1 = getNumber("Enter the base: ");
                num2 = getNumber("Enter the exponent: ");
                result = pow(num1, num2);
                cout << "Result: " << result << endl;
                break;
            case 6:
                num1 = getNumber("Enter the first number: ");
                num2 = getNumber("Enter the second number: ");
                if (static_cast<int>(num2) != 0) {
                    result = static_cast<int>(num1) % static_cast<int>(num2);
                    cout << "Result: " << result << endl;
                } else {
                    cout << "Error: Division by zero!" << endl;
                }
                break;
            case 7:
                num1 = getNumber("Enter the number: ");
                if (num1 >= 0) {
                    result = sqrt(num1);
                    cout << "Result: " << result << endl;
                } else {
                    cout << "Error: Cannot compute square root of a negative number!" << endl;
                }
                break;
            case 8:
                num1 = getNumber("Enter the angle in degrees: ");
                result = sin(num1 * M_PI / 180.0);  // Convert degrees to radians
                cout << "Result: " << result << endl;
                break;
            case 9:
                num1 = getNumber("Enter the angle in degrees: ");
                result = cos(num1 * M_PI / 180.0);  // Convert degrees to radians
                cout << "Result: " << result << endl;
                break;
            case 10:
                num1 = getNumber("Enter the angle in degrees: ");
                result = tan(num1 * M_PI / 180.0);  // Convert degrees to radians
                cout << "Result: " << result << endl;
                break;
            case 11:
                num1 = getNumber("Enter the number: ");
                if (num1 > 0) {
                    result = log10(num1);
                    cout << "Result: " << result << endl;
                } else {
                    cout << "Error: Logarithm undefined for non-positive numbers!" << endl;
                }
                break;
            case 12:
                num1 = getNumber("Enter the number: ");
                if (num1 > 0) {
                    result = log(num1);
                    cout << "Result: " << result << endl;
                } else {
                    cout << "Error: Natural logarithm undefined for non-positive numbers!" << endl;
                }
                break;
            case 13:
                keepGoing = false;
                break;
            default:
                cout << "Error: Invalid choice!" << endl;
                break;
        }

        if (choice != 13) {
            char continueChoice;
            cout << "Do you want to perform another calculation? (y/n): ";
            cin >> continueChoice;

            if (continueChoice != 'y' && continueChoice != 'Y') {
                keepGoing = false;
            }
        }
    }

    cout << "Thank you for using the calculator. Goodbye!" << endl;

    return 0;
}

