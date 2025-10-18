#include <iostream>
#include "SingleList.hpp"

int main() {
    using std::cout;
    using std::endl;

    cout << "===== TEST 1: Constructors =====\n";
    SingleList a;                         // default
    SingleList b(3, 5);                   // 3 elements of value 5
    SingleList c{1, 2, 3, 4, 5};          // initializer list

    cout << "List b: " << b << endl;
    cout << "List c: " << c << endl;

    cout << "\n===== TEST 2: Copy & Move =====\n";
    SingleList copyC = c;                 // copy ctor
    cout << "Copy of c: " << copyC << endl;

    SingleList moveB = std::move(b);      // move ctor
    cout << "After move, b (should be empty): " << b << endl;
    cout << "MoveB: " << moveB << endl;

    SingleList assign;
    assign = c;                           // copy assignment
    cout << "Assign = c: " << assign << endl;

    SingleList moveAssign;
    moveAssign = std::move(copyC);        // move assignment
    cout << "Move assign (copyC -> moveAssign): " << moveAssign << endl;

    cout << "\n===== TEST 3: + and += operators =====\n";
    SingleList left{1, 2};
    SingleList right{3, 4};
    SingleList combined = left + right;   // operator+
    cout << "left + right = " << combined << endl;

    left += SingleList{9, 9};
    cout << "left after += {9,9}: " << left << endl;

    cout << "\n===== TEST 4: Comparison operators =====\n";
    cout << "left == right: " << (left == right ? "true" : "false") << endl;
    cout << "c == assign: " << (c == assign ? "true" : "false") << endl;
    cout << "left != right: " << (left != right ? "true" : "false") << endl;

    cout << "\n===== TEST 5: Index operator [] =====\n";
    cout << "c[0] = " << c[0] << endl;
    cout << "c[2] = " << c[2] << endl;
    c[2] = 99;
    cout << "After modifying c[2] = 99 -> " << c << endl;

    cout << "\n===== TEST 6: Prefix/Postfix ++ and -- =====\n";
    SingleList incList{7, 8};
    cout << "Original incList: " << incList << endl;

    ++incList;
    cout << "After ++prefix: " << incList << endl;

    incList++;
    cout << "After postfix++: " << incList << endl;

    --incList;
    cout << "After --prefix: " << incList << endl;

    incList--;
    cout << "After postfix--: " << incList << endl;

    cout << "\n===== TEST 7: Push & Pop =====\n";
    SingleList ops;
    ops.push_back(10);
    ops.push_front(5);
    ops.push_back(15);
    cout << "After pushes: " << ops << endl;

    ops.pop_front();
    cout << "After pop_front: " << ops << endl;

    ops.pop_back();
    cout << "After pop_back: " << ops << endl;

    cout << "\n===== TEST 8: Stream input >> =====\n";
    SingleList inputList;
    std::cout << "Enter numbers for inputList (Ctrl+D to stop): ";
    std::cin >> inputList;
    std::cout << "You entered: " << inputList << std::endl;

    cout << "\n===== TEST 9: Edge cases =====\n";
    SingleList empty;
    cout << "Empty list: " << empty << " size = " << empty.size() << endl;

    SingleList single{42};
    cout << "Single element: " << single << " size = " << single.size() << endl;

    ++empty;
    cout << "After ++ on empty: " << empty << endl;
    --single;
    cout << "After -- on single: " << single << endl;

    cout << "\n===== TEST 10: Size() =====\n";
    cout << "c size = " << c.size() << endl;
    cout << "left size = " << left.size() << endl;

    cout << "\nAll tests completed successfully.\n";
    return 0;
}

