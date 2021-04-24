#include <iostream>
#include "vector.h"
#include "iterator.h"
#include "constiter.h"
#include "exceptions.h"
#include <cmath>

using namespace std;

int main()
{
    Vector<double> test1{1.0, 2.0, 3.0};
    cout << "TEST 1 (init list)" << endl;
    cout << test1 << endl;

    Vector<double> test2 = Vector<double>({2.0, 3.0, 4.0});
    cout << "TEST 2 (move)" << endl;
    cout << test2 << endl;

    Vector<double> test3 = test1 + test2;
    cout << "TEST 3 (sum)" << endl;
    cout << test3 << endl;

    Vector<double> test4 = test1 - test2;
    cout << "TEST 4 (diff)" << endl;
    cout << test4 << endl;

    double test5 = test1 * test2;
    cout << "TEST 5 (scalar mul)" << endl;
    cout << test5 << endl;

    Vector<double> test6 = test1 * 4.0;
    cout << "TEST 6 (numeric mul)" << endl;
    cout << test6 << endl;

    Vector<double> test7 = test1 ^ test2;
    cout << "TEST 7 (vector mul)" << endl;
    cout << test7 << endl;

    test2[1] = 4;
    cout << "TEST 8 (change index)" << endl;
    cout << test2 << endl;

    Vector<double> test9 = -test6;
    cout << "TEST 9 (negative)" << endl;
    cout << test9 << endl;

    Vector<double> test10(test1);
    cout << "TEST 10 (copy constructor)" << endl;
    cout << test10 << endl;

    double test11 = test10.module<double>();
    cout << "TEST 11 (module)" << endl;
    cout << test11 << endl;

    Vector<double> test12 = Vector<double>();
    cout << "TEST 12 (default)" << endl;
    cout << test12 << endl;

    cout << "TEST 13 (equal)" << endl;
    cout << (test10 == test1) << endl;

    cout << "TEST 14 (not equal)" << endl;
    cout << (test2 == test1) << endl;

    Vector<double> test15 = Vector<double>(3);
    cout << "TEST 15 (vector of zeros)" << endl;
    cout << test15 << " " << test15.is_zero() << endl;

    Vector<double> test16 {1, 2, 3};
    cout << "TEST 16 (zero collinear)" << endl;
    cout << test16.is_collinear(test15) << endl;

    cout << "TEST 17 (collinear)" << endl;
    cout << test16.is_collinear(test1) << endl;

    cout << "TEST 18 (non-collinear)" << endl;
    cout << test16.is_collinear(test2) << endl;

    cout << "TEST 19 (zero orthogonal)" << endl;
    cout << test16.is_orthogonal(test15) << endl;

    cout << "TEST 20 (orthogonal)" << endl;
    Vector<double> test20 {-9, 0, 3};
    cout << test16.is_orthogonal(test20) << endl;

    cout << "TEST 21 (non-orthogonal)" << endl;
    cout << test16.is_orthogonal(test1) << endl;

    cout << "TEST 22 (angle 90)" << endl;
    cout << test16.angle<double>(test20) << endl;

    cout << "TEST 23 (angle 0)" << endl;
    cout << test16.angle<double>(test1) << endl;

    cout << "TEST 24 (angle)" << endl;
    cout << test16.angle<double>(test2) << endl;

    double elem = 1.0;
    Vector<double> test25 = Vector<double>(3, elem);
    cout << "TEST 25 (create vector of equal elements)" << endl;
    cout << test25 << endl;

    Vector<double> test26 = test25.get_ort();
    cout << "TEST 26 (get ort)" << endl;
    cout << test26 << endl;

    cout << endl << "EXCEPTIONS" << endl;
    cout << endl << "ETEST 1 (wrong dimensions)" << endl;
    try
    {
        Vector<double> test = {3, 4};
        test1 += test;
    } catch (DimensionsException &exc) {
        cout << exc.what() << endl;
    }

    cout << endl << "ETEST 2 (zero-sized vector)" << endl;
    try
    {
        Vector<double> test = Vector<double>();
        test *= 3.0;
    } catch (ZeroVectorException &exc) {
        cout << exc.what() << endl;
    }

    cout << endl << "ETEST 3 (cross product for non-3d)" << endl;
    try
    {
        Vector<double> test1 {2, 3};
        Vector<double> test2 {2, 3};
        Vector<double> test = test1 ^ test2;
    } catch (CrossProductException &exc) {
        cout << exc.what() << endl;
    }

    cout << endl << "ETEST 4 (invalid index)" << endl;
    try
    {
        Vector<double> test1 {2, 3};
        double num = test1[2];
        cout << num << endl;
    } catch (WrongIndexException &exc) {
        cout << exc.what() << endl;
    }

    cout << endl << "ETEST 5 (invalid alloc)" << endl;
    try
    {
        Vector<double> test1 = Vector<double>(10000000000000);
    } catch (MemoryException &exc) {
        cout << exc.what() << endl;
    }

    return 0;
}
